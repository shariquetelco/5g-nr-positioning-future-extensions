#include "amfd.h"

int
addEntry(rlist_t *list, rentry_t *entry)
{
	if(!list || !entry)
	{
		return -1;
	}

	/*Enter critical section*/
	if(pthread_mutex_lock(&list->lock) != 0)
	{
		return -1;
	}

	if(!list->cnt)
	{
		list->root = entry;
		list->last = entry;
	}
	else
	{
		list->last->next = entry;
		list->last = entry;
	}

	list->cnt++;

again:
	/*Leave critical section*/
	if(pthread_mutex_unlock(&list->lock) != 0)
	{
		goto again;
	}

	return 0;
}

void
deleteEntry(rlist_t *list, rentry_t *entry)
{
	int i;
	rentry_t *tmp = 0, *tmp2 = 0; /*current and previous element pointer*/

	if(!list || !entry || !list->cnt)
	{
		return;
	}

	/*Enter critical section*/
	if(pthread_mutex_lock(&list->lock) != 0)
	{
		return;
	}

	/*Special case I: list only contains 1 element*/
	if(list->cnt == 1)
	{
		if(list->root == entry)
		{
			list->root = 0;
			list->last = 0;
			list->cnt = 0;

			/*Free memory*/
			if(entry->imsi)
			{
				free(entry->imsi);
			}
			
			if(entry->lcs_id)
			{
				free(entry->lcs_id);
			}
			if(entry->nfid.buf)
			{
				free(entry->nfid.buf);
			}
			if(entry->ngap_amf_id.buf)
			{
				free(entry->ngap_amf_id.buf);
			}

			free(entry);
		}

		/*Leave critical section*/
		pthread_mutex_unlock(&list->lock);

		return;
	}
	
	/*Otherwise: iteration through entire list*/
	for(i = 0, tmp = list->root; i < list->cnt; i++, tmp2 = tmp, tmp = tmp2->next)
	{
		/*Compare heap addresses*/
		if(tmp == entry)
		{
			/*If last element in list*/
			if(tmp->next == NULL)
			{
				list->last = tmp2;
				tmp2->next = 0;
			}
			else
			{
				tmp2->next = tmp->next;
			}
			
			/*Decrease list counter*/
			list->cnt--;
			
			/*Free memory*/
			if(entry->imsi)
			{
				free(entry->imsi);
			}
			
			if(entry->lcs_id)
			{
				free(entry->lcs_id);
			}
			if(entry->nfid.buf)
			{
				free(entry->nfid.buf);
			}
			if(entry->ngap_amf_id.buf)
			{
				free(entry->ngap_amf_id.buf);
			}

			/*-- gNB entry of LCS session is cleared within the caller --*/

			free(entry);
			
			break;
		}
	}

	/*Leave critical section*/
	pthread_mutex_unlock(&list->lock);
}


/*
 * getEntry - find a suitable entry in global LCS list by using key
 *
 * @list: pointer to global LCS list
 * @key: attribute that is used for comparison (IMSI or LCS Correlation ID)
 *
 * return: pointer to found entry on success, NULL pointer otherwise
 */
rentry_t*
getEntry(rlist_t *list, void *key)
{
	int i;
	rentry_t *tmp = 0;

	if(!list || !key)
	{
		return NULL;
	}

	/*Enter critical section*/
	if(pthread_mutex_lock(&list->lock) != 0)
	{
		return NULL;
	}

	for(i = 0, tmp = list->root; i < list->cnt; i++, tmp = tmp->next)
	{
		/*Check if attribute is inialized*/
		if(!tmp->imsi || !tmp->lcs_id)
		{
			continue;
		}
		
		if(strcmp(tmp->imsi, (char*)key) == 0 || strcmp(tmp->lcs_id, (char*)key) == 0)
		{
			/*Leave critical section*/
			pthread_mutex_unlock(&list->lock);

			return tmp;
		}
	}

	/*Leave critical section*/
	pthread_mutex_unlock(&list->lock);

	return NULL;
}

/*
 * getEntryFull - find a suitable entry in global LCS list by using NGAP UE specific IDs and the target NF ID (Routing ID)
 *
 * @list: pointer to global LCS list
 * @ngap_amf_id: AMF UE NGAP ID
 * @ngap_ran_ue: RAN UE NGAP ID
 * @nfid: Routing identifer that corresponds to the target NF ID
 *
 * return: pointer to found entry on success, NULL pointer otherwise
 *
 * NOTE: returned entry is already locked. Free it with sem_post!
 */
rentry_t*
getEntryFull(rlist_t *list, NGAP_AMF_UE_NGAP_ID_t *ngap_amf_id, NGAP_RAN_UE_NGAP_ID_t *ngap_ran_id, NGAP_RoutingID_t *nfid)
{
	int i;
	rentry_t *tmp = 0;
	size_t n = 0;

	if(!list || !ngap_amf_id || !ngap_amf_id->buf || ngap_amf_id->size > 5 || !ngap_ran_id || !nfid || !nfid->buf || nfid->size > 16 || !nfid->size)
	{
		return NULL;
	}

	/*Enter critical section*/
	if(pthread_mutex_lock(&list->lock) != 0)
	{
		return NULL;
	}

	for(i = 0, tmp = list->root; i < list->cnt; i++, tmp = tmp->next)
	{
		/*Check if attributes are inialized*/
		if(!tmp->isComplete)
		{
			continue;
		}

		/*(1) AMF UE NGAP ID*/
		(ngap_amf_id->size >= tmp->ngap_amf_id.size) ? (n = tmp->ngap_amf_id.size) : (n = ngap_amf_id->size);
		if(memcmp(tmp->ngap_amf_id.buf + tmp->ngap_amf_id.size - n, ngap_amf_id->buf, n) != 0)
		{
			continue;
		}

		/*(2) RAN UE NGAP ID*/
		if(tmp->ngap_ran_id != *ngap_ran_id)
		{
			continue;
		}

		/*(3) Routing ID*/
		(nfid->size >= tmp->nfid.size) ? (n = tmp->nfid.size) : (n = nfid->size);
		if(memcmp(nfid->buf, tmp->nfid.buf, n) == 0)
		{
			/*Leave critical section*/
			pthread_mutex_unlock(&list->lock);

			/*Enter critical section for found entry*/
			pthread_mutex_lock(&tmp->lock);

			return tmp;
		}
	}

	/*Leave critical section*/
	pthread_mutex_unlock(&list->lock);

	return NULL;
}

/*
 * addGNBToUEctx - add a gNB to a certain number of UE context entries that are not associated with a serving gNB
 *
 * @list: global UE context list
 * @gnb: target gNB that has to be associated with.
 * @num: number of UE context entries with which @gnb has to be associated.
 *
 * NOTE: This is only realized here for simplicity. In general, the assignment of UE <-> gNB is realized by a complex registration process.. ;-)
 * NOTE: This function may be invoked if @list->sem is locked by the caller! Otherwise, undefined behaviour is expected...
 */
void
addGNBToUEctx(rlist_t *list, gnb_t *gnb, int num)
{
	int i, j;
	rentry_t *tmp = 0;

	if(!list || !gnb || !num)
	{
		return;
	}

	if(num > list->cnt)
	{
		num = list->cnt;
	}

	for(i = 0, j = num, tmp = list->root; i < list->cnt && j > 0; i++, tmp = tmp->next)
	{
		if(tmp)
		{
			if(!tmp->gnb)
			{
				tmp->gnb = gnb;
				if(tmp->sub_n2[n2_information_class_NRPPa-1])
				{
					printf("[AMF-n2] UE context %s is now complete\n", tmp->imsi);
					tmp->isComplete = true;
				}
#ifndef RESEARCH
				printf("[AMF-n2] Added gNB reference to UE context %d: (%s)\n", i+1, tmp->imsi);
#endif
				j--;
			}
		}
	}

	gnb->num = num - j;
	printf("[AMF-n2] Added gNB reference to %d UE context entries\n", gnb->num);

	return;
}

void
deleteGNBFromList(rlist_t *list, gnb_t *gnb)
{
	int i, j, as = 0;
	rentry_t *tmp = 0;

	if(!list || !gnb)
	{
		return;
	}

	/*Enter critical section*/
	if(pthread_mutex_lock(&list->lock) != 0)
	{
		return;
	}

	for(as = gnb->num, i = 0, j = gnb->num, tmp = list->root; i < list->cnt && gnb->num > 0; i++, tmp = tmp->next)
	{
		if(tmp && tmp->gnb == gnb)
		{
			tmp->gnb = 0;
			tmp->isComplete = false;

#ifndef RESEARCH
			printf("[AMF-n2] Removed gNB reference from UE context %d: (%s)\n", i+1, tmp->imsi);
#endif
			gnb->num--;
		}
	}

	if(!gnb->num)
	{
		printf("[AMF-n2] gNB (%s) was successfully removed from its associated UE contexts (%d)\n", gnb->name, as);
	}

	/*Leave critical section*/
	pthread_mutex_unlock(&list->lock);

	return;
}

void
freeList(rlist_t *list)
{
	int i, j;
	rentry_t *tmp = 0;

	if(!list)
	{
		return;
	}

again:
	/*Enter critical section*/
	if(pthread_mutex_lock(&list->lock) != 0)
	{
		goto again;
	}

	for(i = 0, tmp = list->root; i < list->cnt; i++, tmp = list->root)
	{
		if(!tmp)
		{
			return;
		}

		/*Last element*/
		if(i < list->cnt - 1)
		{
			list->root = tmp->next;
		}

		/*Free memory*/
		if(tmp)
		{
			if(tmp->lcs_id)
			{
				free(tmp->lcs_id);
			}

			if(tmp->imsi)
			{
				free(tmp->imsi);
			}

			for(j = 0; j < AMF_SUB_N1_MAX; j++)
			{
				if(tmp->sub_n1[j])
				{
					ue_n1_n2_info_subscription_create_data_free(tmp->sub_n1[j]);
				}
			}

			for(j = 0; j < AMF_SUB_N2_MAX; j++)
			{
				if(tmp->sub_n2[j])
				{
					ue_n1_n2_info_subscription_create_data_free(tmp->sub_n2[j]);
				}
			}

			if(tmp->nfid.size > 0 && tmp->nfid.buf)
			{
				free(tmp->nfid.buf);
			}

			if(tmp->ngap_amf_id.size > 0 && tmp->ngap_amf_id.buf)
			{
				free(tmp->ngap_amf_id.buf);
			}

			/*NOTE: gNB data is free while freeing global gNB list*/
		}

		/*Decrease list counter*/
		list->cnt--;
	}
}
