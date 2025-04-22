#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "td_traffic.h"

td_traffic_t *td_traffic_create(list_t *pdu_ses_traf_reqs, bool is_ul_vol,
                                long ul_vol, bool is_dl_vol, long dl_vol,
                                bool is_all_vol, long all_vol,
                                bool is_ul_num_of_pkt, int ul_num_of_pkt,
                                bool is_dl_num_of_pkt, int dl_num_of_pkt,
                                bool is_all_num_of_pkt, int all_num_of_pkt) {
	td_traffic_t *td_traffic_local_var = malloc(sizeof(td_traffic_t));

	td_traffic_local_var->pdu_ses_traf_reqs = pdu_ses_traf_reqs;
	td_traffic_local_var->is_ul_vol = is_ul_vol;
	td_traffic_local_var->ul_vol = ul_vol;
	td_traffic_local_var->is_dl_vol = is_dl_vol;
	td_traffic_local_var->dl_vol = dl_vol;
	td_traffic_local_var->is_all_vol = is_all_vol;
	td_traffic_local_var->all_vol = all_vol;
	td_traffic_local_var->is_ul_num_of_pkt = is_ul_num_of_pkt;
	td_traffic_local_var->ul_num_of_pkt = ul_num_of_pkt;
	td_traffic_local_var->is_dl_num_of_pkt = is_dl_num_of_pkt;
	td_traffic_local_var->dl_num_of_pkt = dl_num_of_pkt;
	td_traffic_local_var->is_all_num_of_pkt = is_all_num_of_pkt;
	td_traffic_local_var->all_num_of_pkt = all_num_of_pkt;

	return td_traffic_local_var;
}

void td_traffic_free(td_traffic_t *td_traffic) {
	lnode_t *node = NULL;

	if(NULL == td_traffic) {
		return;
	}
	if(td_traffic->pdu_ses_traf_reqs) {
		list_for_each(td_traffic->pdu_ses_traf_reqs, node) {
			pdu_ses_traffic_req_free(node->data);
		}
		list_free(td_traffic->pdu_ses_traf_reqs);
		td_traffic->pdu_ses_traf_reqs = NULL;
	}
	free(td_traffic);
}

cJSON *td_traffic_convertToJSON(td_traffic_t *td_traffic) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(td_traffic == NULL) {
		printf("td_traffic_convertToJSON() failed [TdTraffic]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(td_traffic->pdu_ses_traf_reqs) {
		cJSON *pdu_ses_traf_reqsList = cJSON_AddArrayToObject(item,
		                                                      "pduSesTrafReqs");
		if(pdu_ses_traf_reqsList == NULL) {
			printf(
				"td_traffic_convertToJSON() failed [pdu_ses_traf_reqs]");
			goto end;
		}
		list_for_each(td_traffic->pdu_ses_traf_reqs, node) {
			cJSON *itemLocal = pdu_ses_traffic_req_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"td_traffic_convertToJSON() failed [pdu_ses_traf_reqs]");
				goto end;
			}
			cJSON_AddItemToArray(pdu_ses_traf_reqsList, itemLocal);
		}
	}

	if(td_traffic->is_ul_vol) {
		if(cJSON_AddNumberToObject(item, "ulVol",
		                           td_traffic->ul_vol) == NULL)
		{
			printf("td_traffic_convertToJSON() failed [ul_vol]");
			goto end;
		}
	}

	if(td_traffic->is_dl_vol) {
		if(cJSON_AddNumberToObject(item, "dlVol",
		                           td_traffic->dl_vol) == NULL)
		{
			printf("td_traffic_convertToJSON() failed [dl_vol]");
			goto end;
		}
	}

	if(td_traffic->is_all_vol) {
		if(cJSON_AddNumberToObject(item, "allVol",
		                           td_traffic->all_vol) == NULL)
		{
			printf("td_traffic_convertToJSON() failed [all_vol]");
			goto end;
		}
	}

	if(td_traffic->is_ul_num_of_pkt) {
		if(cJSON_AddNumberToObject(item, "ulNumOfPkt",
		                           td_traffic->ul_num_of_pkt) == NULL)
		{
			printf(
				"td_traffic_convertToJSON() failed [ul_num_of_pkt]");
			goto end;
		}
	}

	if(td_traffic->is_dl_num_of_pkt) {
		if(cJSON_AddNumberToObject(item, "dlNumOfPkt",
		                           td_traffic->dl_num_of_pkt) == NULL)
		{
			printf(
				"td_traffic_convertToJSON() failed [dl_num_of_pkt]");
			goto end;
		}
	}

	if(td_traffic->is_all_num_of_pkt) {
		if(cJSON_AddNumberToObject(item, "allNumOfPkt",
		                           td_traffic->all_num_of_pkt) == NULL)
		{
			printf(
				"td_traffic_convertToJSON() failed [all_num_of_pkt]");
			goto end;
		}
	}

end:
	return item;
}

td_traffic_t *td_traffic_parseFromJSON(cJSON *td_trafficJSON) {
	td_traffic_t *td_traffic_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *pdu_ses_traf_reqs = NULL;
	list_t *pdu_ses_traf_reqsList = NULL;
	cJSON *ul_vol = NULL;
	cJSON *dl_vol = NULL;
	cJSON *all_vol = NULL;
	cJSON *ul_num_of_pkt = NULL;
	cJSON *dl_num_of_pkt = NULL;
	cJSON *all_num_of_pkt = NULL;
	pdu_ses_traf_reqs = cJSON_GetObjectItemCaseSensitive(td_trafficJSON,
	                                                     "pduSesTrafReqs");
	if(pdu_ses_traf_reqs) {
		cJSON *pdu_ses_traf_reqs_local = NULL;
		if(!cJSON_IsArray(pdu_ses_traf_reqs)) {
			printf(
				"td_traffic_parseFromJSON() failed [pdu_ses_traf_reqs]");
			goto end;
		}

		pdu_ses_traf_reqsList = list_create();

		cJSON_ArrayForEach(pdu_ses_traf_reqs_local, pdu_ses_traf_reqs) {
			if(!cJSON_IsObject(pdu_ses_traf_reqs_local)) {
				printf(
					"td_traffic_parseFromJSON() failed [pdu_ses_traf_reqs]");
				goto end;
			}
			pdu_ses_traffic_req_t *pdu_ses_traf_reqsItem =
				pdu_ses_traffic_req_parseFromJSON(
					pdu_ses_traf_reqs_local);
			if(!pdu_ses_traf_reqsItem) {
				printf("No pdu_ses_traf_reqsItem");
				goto end;
			}
			list_add(pdu_ses_traf_reqsList, pdu_ses_traf_reqsItem);
		}
	}

	ul_vol = cJSON_GetObjectItemCaseSensitive(td_trafficJSON, "ulVol");
	if(ul_vol) {
		if(!cJSON_IsNumber(ul_vol)) {
			printf("td_traffic_parseFromJSON() failed [ul_vol]");
			goto end;
		}
	}

	dl_vol = cJSON_GetObjectItemCaseSensitive(td_trafficJSON, "dlVol");
	if(dl_vol) {
		if(!cJSON_IsNumber(dl_vol)) {
			printf("td_traffic_parseFromJSON() failed [dl_vol]");
			goto end;
		}
	}

	all_vol = cJSON_GetObjectItemCaseSensitive(td_trafficJSON, "allVol");
	if(all_vol) {
		if(!cJSON_IsNumber(all_vol)) {
			printf("td_traffic_parseFromJSON() failed [all_vol]");
			goto end;
		}
	}

	ul_num_of_pkt = cJSON_GetObjectItemCaseSensitive(td_trafficJSON,
	                                                 "ulNumOfPkt");
	if(ul_num_of_pkt) {
		if(!cJSON_IsNumber(ul_num_of_pkt)) {
			printf(
				"td_traffic_parseFromJSON() failed [ul_num_of_pkt]");
			goto end;
		}
	}

	dl_num_of_pkt = cJSON_GetObjectItemCaseSensitive(td_trafficJSON,
	                                                 "dlNumOfPkt");
	if(dl_num_of_pkt) {
		if(!cJSON_IsNumber(dl_num_of_pkt)) {
			printf(
				"td_traffic_parseFromJSON() failed [dl_num_of_pkt]");
			goto end;
		}
	}

	all_num_of_pkt = cJSON_GetObjectItemCaseSensitive(td_trafficJSON,
	                                                  "allNumOfPkt");
	if(all_num_of_pkt) {
		if(!cJSON_IsNumber(all_num_of_pkt)) {
			printf(
				"td_traffic_parseFromJSON() failed [all_num_of_pkt]");
			goto end;
		}
	}

	td_traffic_local_var = td_traffic_create(
		pdu_ses_traf_reqs ? pdu_ses_traf_reqsList : NULL,
		ul_vol ? true : false,
		ul_vol ? ul_vol->valuedouble : 0,
		dl_vol ? true : false,
		dl_vol ? dl_vol->valuedouble : 0,
		all_vol ? true : false,
		all_vol ? all_vol->valuedouble : 0,
		ul_num_of_pkt ? true : false,
		ul_num_of_pkt ? ul_num_of_pkt->valuedouble : 0,
		dl_num_of_pkt ? true : false,
		dl_num_of_pkt ? dl_num_of_pkt->valuedouble : 0,
		all_num_of_pkt ? true : false,
		all_num_of_pkt ? all_num_of_pkt->valuedouble : 0
		);

	return td_traffic_local_var;
end:
	if(pdu_ses_traf_reqsList) {
		list_for_each(pdu_ses_traf_reqsList, node) {
			pdu_ses_traffic_req_free(node->data);
		}
		list_free(pdu_ses_traf_reqsList);
		pdu_ses_traf_reqsList = NULL;
	}
	return NULL;
}

td_traffic_t *td_traffic_copy(td_traffic_t *dst, td_traffic_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = td_traffic_convertToJSON(src);
	if(!item) {
		printf("td_traffic_convertToJSON() failed");
		return NULL;
	}

	content = cJSON_Print(item);
	cJSON_Delete(item);

	if(!content) {
		printf("cJSON_Print() failed");
		return NULL;
	}

	item = cJSON_Parse(content);
	free(content);
	if(!item) {
		printf("cJSON_Parse() failed");
		return NULL;
	}

	td_traffic_free(dst);
	dst = td_traffic_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
