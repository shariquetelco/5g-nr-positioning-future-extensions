#include "pthpool.h"

/*
 * pthpool_job_create - allocate memory for a new job and initialize it
 *
 * @func: function pointer of the new job
 * @arg: main argument that has to be passed to @func when the latter is executed.
 *
 * return: pointer to the newly created job on success, null pointer otherwise
 */
static pthpool_job_t*
pthpool_job_create(thread_func_t func, void *arg)
{
	pthpool_job_t *job = 0;

	if(func == NULL || (job = calloc(1, sizeof(pthpool_job_t))) == NULL || (job->arg = calloc(1, sizeof(pthpool_data_t))) == NULL)
	{
		return NULL;
	}

	job->func = func;
	job->arg->arg = arg;

	return job;
}

/*
 * pthpool_job_destroy - free memory of an executed job
 *
 * @job: target job that has to be freed
 */
static void
pthpool_job_destroy(pthpool_job_t *job)
{
	if(job)
	{
		if(job->arg)
		{
			free(job->arg);
		}
		free(job);
	}
	return;
}

/*
 * pthpool_job_get - take a job from its corresponding thread pool
 *
 * @tpool: target thread pool from which the job is taken.
 *
 * return: pointer to the taken job on success, null pointer otherwise
 */
static pthpool_job_t*
pthpool_job_get(pthpool_t *tpool)
{
	pthpool_job_t *job = 0;

	/*Check, if passed parameter is valid*/
	if(!tpool || (job = tpool->first) == NULL)
	{
		return NULL;
	}

	/*Take a job (FIFO principle) from the pool and adjust its pointer*/
	if(!job->next)
	{
		tpool->first = NULL;
		tpool->last = NULL;
	}
	else
	{
		tpool->first = job->next;
	}

	return job;
}

/*
 * tpool_worker - thread function that executes the jobs from its thread pool
 *
 * @data: pointer to its corresponding thread pool
 */
static void*
tpool_worker(void *data)
{
	/*Variables*/
	pthpool_t *tpool = 0;
	pthpool_job_t *job = 0;

	/*Check passed parameter*/
	if((tpool = (pthpool_t*) data) == NULL)
	{
		pthread_exit(NULL);
	}

	/*Loop: Pop a job from the pool and execute it*/
	while(1)
	{
		/*Waiting for a job*/
		pthread_mutex_lock(&(tpool->lock));
		while (tpool->first == NULL && !tpool->stop)
		{
			pthread_cond_wait(&(tpool->isJob), &(tpool->lock));
		}

		/*Break here, if the thread pool has to be destroyed*/
		if (tpool->stop)
		{
			break;
		}

		/*Pop a job from the pool*/
		job = pthpool_job_get(tpool);
		tpool->process_cnt++;
		pthread_mutex_unlock(&(tpool->lock));

		/*Execute the taken job*/
		if (job != NULL)
		{
			/*Add target thread pool reference here to enable migration between different pools while execution time*/
			job->arg->pool = &tpool;
	
			job->func(job->arg);
			pthpool_job_destroy(job);
		}

		/*Check, if pool is empty now ...*/
		pthread_mutex_lock(&(tpool->lock));
		tpool->process_cnt--;

		if (!tpool->stop &&
			tpool->process_cnt == 0 &&
			tpool->first == NULL)
		{
			pthread_cond_signal(&(tpool->isIdle));
		}

		pthread_mutex_unlock(&(tpool->lock));
	}

	/*Signal POSIX thread termination*/
	tpool->thr_cnt--;
	pthread_cond_signal(&(tpool->isIdle));
	pthread_mutex_unlock(&(tpool->lock));

	pthread_exit(NULL);
}

/*
 * pthpool_migrate - migrate a POSIX thread from a source to a destination thread pool
 *
 * @src: thread pool to which the thread is currently assigned to.
 * @dest: target thread pool to which the thread has to be migrated.
 *
 * return: true on success, false otherwise
 *
 * NOTE: This function has only to be executed while a job is processed!
 */
bool
pthpool_migrate(pthpool_t **src, pthpool_t *dest)
{
	/*Check passed input parameter*/
	if(!src || !src[0] || src[0]->thr_cnt < 2 || !dest || *src == dest)
	{
		return false;
	}

	/*Enter critical section of source thread pool*/
	pthread_mutex_lock(&(src[0]->lock));

	src[0]->process_cnt--;
	src[0]->thr_cnt--;

	if(!src[0]->stop && src[0]->process_cnt == 0 && src[0]->first == NULL)
	{
		pthread_cond_signal(&(src[0]->isIdle));
	}

	/*Leave critical section*/
	pthread_mutex_unlock(&(src[0]->lock));

	/*Enter critical section of target thread pool*/
	pthread_mutex_lock(&(dest->lock));

	dest->process_cnt++;
	dest->thr_cnt++;

	/*Leave critical section*/
	pthread_mutex_unlock(&(dest->lock));

	/*Save new thread pool pointer*/
	*src = dest;

	return true;
}

/*
 * pthpool_inc_size - increase size of a certain POSIX thread pool
 *
 * @tpool: target thread pool that has to be increased.
 * @num: no. threads that has to be added to @tpool
 *
 * return: true on success, false otherwise
 */
bool
pthpool_inc_size(pthpool_t *tpool, size_t num)
{
	size_t i;
	pthread_t tid;

	if(!tpool || num < 0)
	{
		return false;
	}
	else if(!num)
	{
		return true;
	}

	/*Enter critical section*/
	pthread_mutex_lock(&(tpool->lock));

	/*Create new POSIX threads for the target thread pool*/
	for(i = 0; i < num; i++)
	{
		if(pthread_create(&tid, NULL, tpool_worker, tpool) != 0)
		{
			continue;
		}
		pthread_detach(tid);
		tpool->thr_cnt++;
	}

	/*Leave critical section*/
	pthread_mutex_unlock(&(tpool->lock));

	return true;
}

/*
 * pthpool_create - create a new POSIX thread pool
 *
 * @num: number of threads within the newly created thread pool
 *
 * return: pointer to the new thread pool on success, null pointer otherwise
 */
pthpool_t*
pthpool_create(size_t num)
{
	/*Variables*/
	pthpool_t *tpool = 0;
	pthread_t tid;
	size_t i;

	/*Set default size if value is negative*/
	if(num < 0)
	{
		num = PTHPOOL_SIZE;
	}

	/*Allocate memory for thread pool*/
	if((tpool = calloc(1, sizeof(*tpool))) == NULL)
	{
		return NULL;
	}

	/*Initialize thread pool*/
	pthread_mutex_init(&(tpool->lock), NULL);
	if(pthread_cond_init(&(tpool->isJob), NULL) != 0 ||
	   pthread_cond_init(&(tpool->isIdle), NULL) != 0)
	{
		pthread_mutex_destroy(&(tpool->lock));
		free(tpool);
		return NULL;
	}

	/*Create POSIX threads*/
	for (i = 0; i < num; i++)
	{
		if(pthread_create(&tid, NULL, tpool_worker, tpool) != 0)
		{
			continue;
		}
		pthread_detach(tid);
		tpool->thr_cnt++;
	}

	return tpool;
}

/*
 * pthpool_destroy - destroy a POSIX thread pool
 *
 * @tpool: target thread pool that has to be destroyed.
 */
void
pthpool_destroy(pthpool_t *tpool)
{
	/*Variables*/
	pthpool_job_t *job[2] = {0};

	/*Check passed parameter*/
	if(!tpool)
	{
		return;
	}

	/*Enter critical section*/
	pthread_mutex_lock(&(tpool->lock));

	/*Remove all jobs from the thread pool*/
	job[0] = tpool->first;
	while(job[0] != NULL)
	{
		job[1] = job[0]->next;
		pthpool_job_destroy(job[0]);
		job[0] = job[1];
	}

	/*Signaling to all threads that stopping now*/
	tpool->first = 0;
	tpool->stop = true;

	pthread_cond_broadcast(&(tpool->isJob));
	pthread_mutex_unlock(&(tpool->lock));
	pthpool_wait(tpool);

	/*Free memory*/
	pthread_mutex_destroy(&(tpool->lock));
	pthread_cond_destroy(&(tpool->isJob));
	pthread_cond_destroy(&(tpool->isIdle));
	free(tpool);

	return;
}

/*
 * pthpool_add_job - add a job to a target thread pool
 *
 * @tpool: target thread pool
 * @func: function pointer that is used when the corresponding job is executed.
 * @arg: main argument that is passed to @func when the latter is executed.
 *
 * return: true on success, false otherwise
 *
 * NOTE: If the thread pool does not have any threads, no jobs can be added.
 */
bool
pthpool_add_job(pthpool_t *tpool, thread_func_t func, void *arg)
{
	pthpool_job_t *job = 0;

	if(!tpool)
	{
		return false;
	}

	pthread_mutex_lock(&(tpool->lock));

	if(!tpool->thr_cnt || (job = pthpool_job_create(func, arg)) == NULL)
	{
		pthread_mutex_unlock(&(tpool->lock));
		return false;
	}

	/*Insert job into linked list (FIFO)*/
	if(tpool->first == NULL)
	{
		tpool->first = job;
		tpool->last = tpool->first;
	}
	else
	{
		tpool->last->next = job;
		tpool->last = job;
	}

	pthread_cond_broadcast(&(tpool->isJob));
	pthread_mutex_unlock(&(tpool->lock));

	return true;
}

/*
 * pthpool_wait - waiting for all jobs are done
 *
 * @tpool: target thread pool
 */
void
pthpool_wait(pthpool_t *tpool)
{
	if(!tpool)
	{
		return;
	}

	pthread_mutex_lock(&(tpool->lock));
	while(1)
	{
		if (tpool->thr_cnt && (tpool->first != NULL || (!tpool->stop && tpool->process_cnt != 0)))
		{
			pthread_cond_wait(&(tpool->isIdle), &(tpool->lock));
		}
		else
		{
			break;
		}
	}
	pthread_mutex_unlock(&(tpool->lock));
}
