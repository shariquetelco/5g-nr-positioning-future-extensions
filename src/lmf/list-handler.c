#include "list-handler.h"
#include "sbi-client.h"

/*
 * initUEctxList - initialize the global UE context list
 *
 * @list: pointer to the pointer of the global UE context list
 */
void
initUEctxList(ue_ctx_list_t **list)
{
	pthread_mutexattr_t attr;

	/*Check if list reference was passed*/
	if(!list)
	{
		return;
	}

	/*Initialize POSIX thread mutex attributes*/
#ifdef DEBUG
	if(pthread_mutexattr_init(&attr) != 0)
	{
		perror("pthread_mutexattr_init()");
		return;
	}

	if(pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT) != 0)
	{
		pthread_mutexattr_destroy(&attr);
		perror("pthread_mutexattr_setprotocol()");
		return;
	}
#endif
	/*Allocate memory*/
	if((*list = calloc(1, sizeof(ue_ctx_list_t))) == NULL)
	{
		return;
	}

	/*Initialize POSIX thread mutex*/
	if(pthread_mutex_init(&(list[0]->lock), NULL) != 0)
	{
		free(*list);
		*list = 0;
	}

	pthread_mutexattr_destroy(&attr);

	return;
}

/*
 * getUEctx - get UE context by a given SUPI from list
 */
ue_ctx_t*
getUEctx(ue_ctx_list_t *list, char *supi)
{
	ue_ctx_t *ctx = 0;

	if(!list || !supi)
	{
		return NULL;
	}

	/*Enter critical section*/
	if(pthread_mutex_lock(&list->lock) != 0)
	{
		return NULL;
	}

	for(ctx = list->first; ctx != NULL; ctx = ctx->next)
	{
		/*Return UE context if found ...*/
		if(strcmp(ctx->supi, supi) == 0)
		{
			/*Leave critical section*/
			pthread_mutex_unlock(&list->lock);
			return ctx;
		}
	}

#ifndef RESEARCH
	printf("No entry found for %s (%ld) under %d elements:\n", supi, strlen(supi), list->cnt);
	for(ctx = list->first; ctx != NULL; ctx = ctx->next)
	{
		printf("compare %s (%ld, list) with %s (%ld, passed)\n", ctx->supi, strlen(ctx->supi), supi, strlen(supi));
	}
#endif

	/*Leave critical section*/
	pthread_mutex_unlock(&list->lock);

	return NULL;
}

/*
 * addUEctx - add UE context to global UE context list
 *
 * @list: reference of global UE context list
 * @entry: UE context that shall be added to @list.
 *
 * return: true on success, false otherwise
 *
 * NOTE: @entry has to be initialized with 
 */
bool
addUEctx(ue_ctx_list_t *list, ue_ctx_t *entry)
{
	if(!list || !entry || !entry->supi || !entry->lcsid || !entry->amfid)
	{
		return false;
	}

again:
	/*Enter critical section*/
	if(pthread_mutex_lock(&list->lock) != 0)
	{
		goto again;
	}

	/*Change UE context list pointer references*/
	if(!list->cnt)
	{
		list->first = entry;
	}
	else
	{
		list->last->next = entry;
	}
	list->last = entry;
	entry->next = 0;

	/*Increase list counter*/
	list->cnt++;

	/*Leave critical section*/
	pthread_mutex_unlock(&list->lock);

	return true;
}

/*
 * deleteUEctx - remove an UE context from global list
 *
 * @list: global UE context list
 * @entry: selected context that has to be removed.
 *
 * return: true on success, false otherwise
 *
 * NOTE: @entry will be completely freed on success.
 */
bool
deleteUEctx(ue_ctx_list_t *list, ue_ctx_t *entry)
{
	ue_ctx_t *ctx = 0, *prev = 0;

	if(!list || !list->cnt || !entry)
	{
		return false;
	}

	/*Enter critical section*/
	if(pthread_mutex_lock(&list->lock) != 0)
	{
		return false;
	}

	/*Looking for the target entry*/
	if(list->cnt == 1)
	{
		if(list->first == entry)
		{
			list->first = 0;
			list->last = 0;
			list->cnt = 0;
			goto end;
		}
		else
		{
			pthread_mutex_unlock(&list->lock);
			return false;
		}
	}

	/*Looking for the target entry when the global list contains at least two elements...*/
	for(ctx = list->first, prev = 0; ctx != NULL; prev = ctx, ctx = ctx->next)
	{
		if(ctx == entry)
		{
			/*Adjust linked list references*/
			if(!prev)
			{
				list->first = ctx->next; //enough because list contains at least a second entry
			}
			else
			{
				/*End of list reached*/
				if(list->last == ctx)
				{
					list->last = prev;
					prev->next = 0;
				}

				/*Somewhere in the mid of the list...*/
				else
				{
					prev->next = ctx->next;
				}
			}

			list->cnt--;
			goto end;
		}
	}

	/*Leave critical section*/
	pthread_mutex_unlock(&list->lock);

	return false;

end:
	/*Leave critical section*/
	pthread_mutex_unlock(&list->lock);

retry:
	/*Enter critical section*/
	ctx = entry;
	if(pthread_mutex_lock(&ctx->lock) != 0)
	{
		goto retry;
	}

	/*Mark LMF UE Measurement ID as unused - if used*/
	if(lmf_ue_meas_list && ctx->lmf_ue)
	{
		freeListID(lmf_ue_meas_list, ctx->lmf_ue - 1);
	}

	/*Free memory*/
	if(ctx->n2subid)
	{
		namf_comm_n1n2msgunsubscribe(ctx);
		free(ctx->n2subid);
		ctx->n2subid = 0;
	}

	if(ctx->n2_clb_uri)
	{
		free(ctx->n2_clb_uri);
		ctx->n2_clb_uri = 0;
	}

	if(ctx->supi)
	{
		free(ctx->supi);
		ctx->supi = 0;
	}

	if(ctx->lcsid)
	{
		free(ctx->lcsid);
		ctx->lcsid = 0;
	}

	if(ctx->amfid)
	{
		free(ctx->amfid);
		ctx->amfid = 0;
	}

	pthread_mutex_destroy(&ctx->lock);

	free(ctx);

	return true;
}

/*
 * freeUEctxList - free UE context list entries and free list
 *
 * @list: pointer to the global UE context list
 */
void
freeUEctxList(ue_ctx_list_t *list)
{
	ue_ctx_t *ctx = 0;

	/*Check if list reference was passed*/
	if(!list)
	{
		return;
	}

	/*Free list if it is empty*/
	if(!list->cnt)
	{
		free(list);
		return;
	}


	/*Enter critical section*/
	if(pthread_mutex_lock(&list->lock) != 0)
	{
		return;
	}

	/*Free each list entry*/
	for(ctx = list->first; ctx != NULL; ctx = list->first)
	{

		/*Enter critical section*/
		if(pthread_mutex_lock(&ctx->lock) != 0)
		{
			return;
		}

		/*Mark LMF UE Measurement ID as unused - if used*/
		if(lmf_ue_meas_list && ctx->lmf_ue)
		{
			freeListID(lmf_ue_meas_list, ctx->lmf_ue - 1);
		}

		/*Free memory of entry members*/
		if(ctx->n2subid)
		{
			namf_comm_n1n2msgunsubscribe(ctx);
			free(ctx->n2subid);
		}

		if(ctx->n2_clb_uri)
		{
			free(ctx->n2_clb_uri);
		}
		
		if(ctx->supi)
		{
			free(ctx->supi);
		}

		if(ctx->lcsid)
		{
			free(ctx->lcsid);
		}

		pthread_mutex_destroy(&ctx->lock);

		/*Adjust list data*/
		list->first = ctx->next;
		list->cnt--;
		free(ctx);
	}

	pthread_barrier_destroy(&list->barrier);
	pthread_mutex_destroy(&list->lock);

	/*Free memory*/
	free(list);
	return;
}

/********************************************************************
 * NRPPA TRANSACTION / LMF UE MEASUREMENT ID LIST HANDLER FUNCTIONS
 ********************************************************************/

/*
 * initNRPPaList - initialize global ID list
 */
void
initNRPPaList(nrppa_transact_t **list, int num)
{
	pthread_mutexattr_t attr;

	if(!list || num <= 0)
	{
		return;
	}

	/*Initialize POSIX thread mutex attributes*/
#ifdef DEBUG
        if(pthread_mutexattr_init(&attr) != 0)
	{
		perror("pthread_mutexattr_init()");
		return;
	}

	if(pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT) != 0)
	{
		pthread_mutexattr_destroy(&attr);
		perror("pthread_mutexattr_setprotocol()");
		return;
	}
#endif
	/*Allocate memory*/
	if((*list = calloc(1, sizeof(nrppa_transact_t))) == NULL || (list[0]->list = calloc(num, sizeof(uint8_t))) == NULL)
	{
		if(*list)
		{
			free(*list);
			*list = 0;
		}
		return;
	}

	/*Initialize POSIX semaphore*/
	if(pthread_mutex_init(&list[0]->lock, NULL) != 0)
	{
		free(list[0]->list);
		free(*list);
		*list = 0;
		return;
	}

	list[0]->num = num;

	pthread_mutexattr_destroy(&attr);

	return;
}

/*
 * reserveListID - get an unused ID from list and mark it as used
 */
uint16_t
reserveListID(nrppa_transact_t *list)
{
	uint16_t idx;

	/*Enter critical section*/
	if(pthread_mutex_lock(&list->lock) != 0)
	{
		return list->num;
	}

	/*If all IDs are used...*/
	if(list->cnt == list->num)
	{
		goto end;
	}

	for(idx = 0; idx < list->num; idx++)
	{
		if(!list->list[idx])
		{
			list->list[idx] = 1;
			list->cnt++;

			/*Leave critical section*/
			pthread_mutex_unlock(&list->lock);

			return idx;
		}
	}

end:
	/*Leave critical section*/
	pthread_mutex_unlock(&list->lock);

	return list->num;
}

/*
 * freeListID - free an used ID
 */
void
freeListID(nrppa_transact_t *list, uint16_t id)
{
	/*Enter critical section*/
	if(pthread_mutex_lock(&list->lock) != 0)
	{
		return;
	}

	if(list->list[id])
	{
		list->list[id] = 0;
		list->cnt--;
	}

	/*Leave critical section*/
	pthread_mutex_unlock(&list->lock);

	return;
}

/*
 * freeNRPPaList - free global ID list
 */
void
freeNRPPaList(nrppa_transact_t **list)
{
	/*Enter critical section*/
	if(pthread_mutex_lock(&list[0]->lock) != 0)
	{
		return;
	}

	pthread_mutex_destroy(&list[0]->lock);
	free(list[0]->list);
	free(*list);
	*list = 0;

	return;
}
