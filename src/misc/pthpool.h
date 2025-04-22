/*
 * POSIX thread pool - reuse and limit the number of parallel executed POSIX threads within an application
 *
 * created on: 08/03/2024, NK
 * last modified: 08/04/2024, NK
 */
#ifndef _PTHPOOL_H_
#define _PTHPOOL_H_

#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

/*
 * Macros
 *
 * @PTHPOOL_SIZE: Default number of threads within a thread pool
 */
#define PTHPOOL_SIZE 4

/*
 * (Forward) declarations
 */
typedef void (*thread_func_t)(void *arg);
struct pthpool_data;

/*
 * pthpool_job - thread item that has to be executed
 */
struct pthpool_job
{
	thread_func_t func;
	struct pthpool_data *arg;
	struct pthpool_job *next;
};

typedef struct pthpool_job pthpool_job_t;

/*
 * pthpool - representation of a POSIX thread pool (linked list)
 *
 * @first: reference to the first list item
 * @last: reference to the last list item
 * @lock: semaphore to enable mutual exclusion
 * @isJob: condition variable to indicate that there are jobs in the list that can be processed
 * @isIdle: condition variable to indicate that there are currently no jobs in the list
 * @process_cnt: identifier to track number of processed thread at time ti
 * @thr_cnt: number of threads within the thread pool
 * @stop: variable to signal threads that the pool will destroyed in future
 */
struct pthpool
{
	pthpool_job_t *first;
	pthpool_job_t *last;
	pthread_mutex_t lock;
	pthread_cond_t isJob;
	pthread_cond_t isIdle;
	size_t process_cnt;
	size_t thr_cnt;
	bool stop;
};

typedef struct pthpool pthpool_t;

/*
 * pthpool_data - generic data structure that is passed to each job function
 *
 * @pool: pointer to the target thread pool reference (needed for thread migration)
 * @arg: pointer to main argument that is used by the job itself
 */
struct pthpool_data
{
	pthpool_t **pool;
	void *arg;
};

typedef struct pthpool_data pthpool_data_t;

/*
 * POSIX thread helper functions
 *
 * @pthpool_create: Creation of a new thread pool
 * @pthpool_destroy: Deletion of an existing thread pool
 * @pthpool_add_job: Adding a new POSIX thread to a certain thread pool
 * @pthpool_migrate: Migrate a thread to a new thread pool
 * @pthpool_inc_size: Adding new POSIX threads to a thread pool
 * @pthpool_wait: Waiting until all jobs are processed
 */
pthpool_t* pthpool_create(size_t num);
void pthpool_destroy(pthpool_t *tpool);
bool pthpool_add_job(pthpool_t *tpool, thread_func_t func, void *arg);
bool pthpool_migrate(pthpool_t **src, pthpool_t *dest);
bool pthpool_inc_size(pthpool_t *tpool, size_t num);
void pthpool_wait(pthpool_t *tpool);

#endif
