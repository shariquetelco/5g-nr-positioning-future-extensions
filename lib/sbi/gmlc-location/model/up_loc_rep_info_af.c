#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_loc_rep_info_af.h"

char *up_loc_rep_af_indup_loc_rep_info_af_ToString(
	up_loc_rep_info_af_up_loc_rep_af_ind_e up_loc_rep_af_ind) {
	const char *up_loc_rep_af_indArray[] = { "NULL", "true" };
	size_t sizeofArray = sizeof(up_loc_rep_af_indArray) /
	                     sizeof(up_loc_rep_af_indArray[0]);
	if(up_loc_rep_af_ind < sizeofArray) {
		return (char *) up_loc_rep_af_indArray[up_loc_rep_af_ind];
	} else {
		return (char *) "Unknown";
	}
}

up_loc_rep_info_af_up_loc_rep_af_ind_e
up_loc_rep_af_indup_loc_rep_info_af_FromString(char *up_loc_rep_af_ind) {
	int stringToReturn = 0;
	const char *up_loc_rep_af_indArray[] = { "NULL", "true" };
	size_t sizeofArray = sizeof(up_loc_rep_af_indArray) /
	                     sizeof(up_loc_rep_af_indArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(up_loc_rep_af_ind,
		          up_loc_rep_af_indArray[stringToReturn]) == 0)
		{
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
up_loc_rep_info_af_t *up_loc_rep_info_af_create(
	up_loc_rep_info_af_up_loc_rep_af_ind_e	up_loc_rep_af_ind,
	bool					is_up_loc_rep_addr_af_null,
	up_loc_rep_addr_af_rm_t			*up_loc_rep_addr_af,
	up_cum_evt_rpt_criteria_t		*up_cum_evt_rpt_criteria) {
	up_loc_rep_info_af_t *up_loc_rep_info_af_local_var =
		malloc(sizeof(up_loc_rep_info_af_t));

	up_loc_rep_info_af_local_var->up_loc_rep_af_ind = up_loc_rep_af_ind;
	up_loc_rep_info_af_local_var->is_up_loc_rep_addr_af_null =
		is_up_loc_rep_addr_af_null;
	up_loc_rep_info_af_local_var->up_loc_rep_addr_af = up_loc_rep_addr_af;
	up_loc_rep_info_af_local_var->up_cum_evt_rpt_criteria =
		up_cum_evt_rpt_criteria;

	return up_loc_rep_info_af_local_var;
}

void up_loc_rep_info_af_free(up_loc_rep_info_af_t *up_loc_rep_info_af) {
	lnode_t *node = NULL;

	if(NULL == up_loc_rep_info_af) {
		return;
	}
	if(up_loc_rep_info_af->up_loc_rep_addr_af) {
		up_loc_rep_addr_af_rm_free(
			up_loc_rep_info_af->up_loc_rep_addr_af);
		up_loc_rep_info_af->up_loc_rep_addr_af = NULL;
	}
	if(up_loc_rep_info_af->up_cum_evt_rpt_criteria) {
		up_cum_evt_rpt_criteria_free(
			up_loc_rep_info_af->up_cum_evt_rpt_criteria);
		up_loc_rep_info_af->up_cum_evt_rpt_criteria = NULL;
	}
	free(up_loc_rep_info_af);
}

cJSON *up_loc_rep_info_af_convertToJSON(
	up_loc_rep_info_af_t *up_loc_rep_info_af) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(up_loc_rep_info_af == NULL) {
		printf(
			"up_loc_rep_info_af_convertToJSON() failed [UpLocRepInfoAf]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(up_loc_rep_info_af->up_loc_rep_af_ind !=
	   up_loc_rep_info_af_UPLOCREPAFIND_NULL)
	{
		if(cJSON_AddStringToObject(item, "upLocRepAfInd",
		                           up_loc_rep_af_indup_loc_rep_info_af_ToString(
						   up_loc_rep_info_af
						   ->
						   up_loc_rep_af_ind)) == NULL)
		{
			printf(
				"up_loc_rep_info_af_convertToJSON() failed [up_loc_rep_af_ind]");
			goto end;
		}
	}

	if(up_loc_rep_info_af->up_loc_rep_addr_af) {
		cJSON *up_loc_rep_addr_af_local_JSON =
			up_loc_rep_addr_af_rm_convertToJSON(
				up_loc_rep_info_af->up_loc_rep_addr_af);
		if(up_loc_rep_addr_af_local_JSON == NULL) {
			printf(
				"up_loc_rep_info_af_convertToJSON() failed [up_loc_rep_addr_af]");
			goto end;
		}
		cJSON_AddItemToObject(item, "upLocRepAddrAf",
		                      up_loc_rep_addr_af_local_JSON);
		if(item->child == NULL) {
			printf(
				"up_loc_rep_info_af_convertToJSON() failed [up_loc_rep_addr_af]");
			goto end;
		}
	} else if(up_loc_rep_info_af->is_up_loc_rep_addr_af_null) {
		if(cJSON_AddNullToObject(item, "upLocRepAddrAf") == NULL) {
			printf(
				"up_loc_rep_info_af_convertToJSON() failed [up_loc_rep_addr_af]");
			goto end;
		}
	}

	if(up_loc_rep_info_af->up_cum_evt_rpt_criteria) {
		cJSON *up_cum_evt_rpt_criteria_local_JSON =
			up_cum_evt_rpt_criteria_convertToJSON(
				up_loc_rep_info_af->up_cum_evt_rpt_criteria);
		if(up_cum_evt_rpt_criteria_local_JSON == NULL) {
			printf(
				"up_loc_rep_info_af_convertToJSON() failed [up_cum_evt_rpt_criteria]");
			goto end;
		}
		cJSON_AddItemToObject(item, "upCumEvtRptCriteria",
		                      up_cum_evt_rpt_criteria_local_JSON);
		if(item->child == NULL) {
			printf(
				"up_loc_rep_info_af_convertToJSON() failed [up_cum_evt_rpt_criteria]");
			goto end;
		}
	}

end:
	return item;
}

up_loc_rep_info_af_t *up_loc_rep_info_af_parseFromJSON(
	cJSON *up_loc_rep_info_afJSON) {
	up_loc_rep_info_af_t *up_loc_rep_info_af_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *up_loc_rep_af_ind = NULL;
	up_loc_rep_info_af_up_loc_rep_af_ind_e up_loc_rep_af_indVariable = 0;
	cJSON *up_loc_rep_addr_af = NULL;
	up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_local_nonprim = NULL;
	cJSON *up_cum_evt_rpt_criteria = NULL;
	up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_nonprim = NULL;
	up_loc_rep_af_ind = cJSON_GetObjectItemCaseSensitive(
		up_loc_rep_info_afJSON, "upLocRepAfInd");
	if(up_loc_rep_af_ind) {
		if(!cJSON_IsString(up_loc_rep_af_ind)) {
			printf(
				"up_loc_rep_info_af_parseFromJSON() failed [up_loc_rep_af_ind]");
			goto end;
		}
		up_loc_rep_af_indVariable =
			up_loc_rep_af_indup_loc_rep_info_af_FromString(
				up_loc_rep_af_ind->valuestring);
	}

	up_loc_rep_addr_af = cJSON_GetObjectItemCaseSensitive(
		up_loc_rep_info_afJSON, "upLocRepAddrAf");
	if(up_loc_rep_addr_af) {
		if(!cJSON_IsNull(up_loc_rep_addr_af)) {
			up_loc_rep_addr_af_local_nonprim =
				up_loc_rep_addr_af_rm_parseFromJSON(
					up_loc_rep_addr_af);
			if(!up_loc_rep_addr_af_local_nonprim) {
				printf(
					"up_loc_rep_addr_af_rm_parseFromJSON failed [up_loc_rep_addr_af]");
				goto end;
			}
		}
	}

	up_cum_evt_rpt_criteria = cJSON_GetObjectItemCaseSensitive(
		up_loc_rep_info_afJSON, "upCumEvtRptCriteria");
	if(up_cum_evt_rpt_criteria) {
		up_cum_evt_rpt_criteria_local_nonprim =
			up_cum_evt_rpt_criteria_parseFromJSON(
				up_cum_evt_rpt_criteria);
		if(!up_cum_evt_rpt_criteria_local_nonprim) {
			printf(
				"up_cum_evt_rpt_criteria_parseFromJSON failed [up_cum_evt_rpt_criteria]");
			goto end;
		}
	}

	up_loc_rep_info_af_local_var = up_loc_rep_info_af_create(
		up_loc_rep_af_ind ? up_loc_rep_af_indVariable : 0,
		up_loc_rep_addr_af &&
		cJSON_IsNull(
			up_loc_rep_addr_af) ? true : false,
		up_loc_rep_addr_af ? up_loc_rep_addr_af_local_nonprim : NULL,
		up_cum_evt_rpt_criteria ? up_cum_evt_rpt_criteria_local_nonprim : NULL
		);

	return up_loc_rep_info_af_local_var;
end:
	if(up_loc_rep_addr_af_local_nonprim) {
		up_loc_rep_addr_af_rm_free(up_loc_rep_addr_af_local_nonprim);
		up_loc_rep_addr_af_local_nonprim = NULL;
	}
	if(up_cum_evt_rpt_criteria_local_nonprim) {
		up_cum_evt_rpt_criteria_free(
			up_cum_evt_rpt_criteria_local_nonprim);
		up_cum_evt_rpt_criteria_local_nonprim = NULL;
	}
	return NULL;
}

up_loc_rep_info_af_t *up_loc_rep_info_af_copy(up_loc_rep_info_af_t	*dst,
                                              up_loc_rep_info_af_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = up_loc_rep_info_af_convertToJSON(src);
	if(!item) {
		printf("up_loc_rep_info_af_convertToJSON() failed");
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

	up_loc_rep_info_af_free(dst);
	dst = up_loc_rep_info_af_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
