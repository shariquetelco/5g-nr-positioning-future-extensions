#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "abnormal_behaviour.h"

abnormal_behaviour_t *abnormal_behaviour_create(list_t *supis,
                                                exception_t *excep, char *dnn,
                                                snssai_t *snssai, bool is_ratio,
                                                int ratio, bool is_confidence,
                                                int confidence,
                                                additional_measurement_t *addt_meas_info)
{
	abnormal_behaviour_t *abnormal_behaviour_local_var =
		malloc(sizeof(abnormal_behaviour_t));

	abnormal_behaviour_local_var->supis = supis;
	abnormal_behaviour_local_var->excep = excep;
	abnormal_behaviour_local_var->dnn = dnn;
	abnormal_behaviour_local_var->snssai = snssai;
	abnormal_behaviour_local_var->is_ratio = is_ratio;
	abnormal_behaviour_local_var->ratio = ratio;
	abnormal_behaviour_local_var->is_confidence = is_confidence;
	abnormal_behaviour_local_var->confidence = confidence;
	abnormal_behaviour_local_var->addt_meas_info = addt_meas_info;

	return abnormal_behaviour_local_var;
}

void abnormal_behaviour_free(abnormal_behaviour_t *abnormal_behaviour) {
	lnode_t *node = NULL;

	if(NULL == abnormal_behaviour) {
		return;
	}
	if(abnormal_behaviour->supis) {
		list_for_each(abnormal_behaviour->supis, node) {
			free(node->data);
		}
		list_free(abnormal_behaviour->supis);
		abnormal_behaviour->supis = NULL;
	}
	if(abnormal_behaviour->excep) {
		exception_free(abnormal_behaviour->excep);
		abnormal_behaviour->excep = NULL;
	}
	if(abnormal_behaviour->dnn) {
		free(abnormal_behaviour->dnn);
		abnormal_behaviour->dnn = NULL;
	}
	if(abnormal_behaviour->snssai) {
		snssai_free(abnormal_behaviour->snssai);
		abnormal_behaviour->snssai = NULL;
	}
	if(abnormal_behaviour->addt_meas_info) {
		additional_measurement_free(abnormal_behaviour->addt_meas_info);
		abnormal_behaviour->addt_meas_info = NULL;
	}
	free(abnormal_behaviour);
}

cJSON *abnormal_behaviour_convertToJSON(
	abnormal_behaviour_t *abnormal_behaviour) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(abnormal_behaviour == NULL) {
		printf(
			"abnormal_behaviour_convertToJSON() failed [AbnormalBehaviour]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(abnormal_behaviour->supis) {
		cJSON *supisList = cJSON_AddArrayToObject(item, "supis");
		if(supisList == NULL) {
			printf(
				"abnormal_behaviour_convertToJSON() failed [supis]");
			goto end;
		}
		list_for_each(abnormal_behaviour->supis, node) {
			if(cJSON_AddStringToObject(supisList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"abnormal_behaviour_convertToJSON() failed [supis]");
				goto end;
			}
		}
	}

	if(!abnormal_behaviour->excep) {
		printf("abnormal_behaviour_convertToJSON() failed [excep]");
		return NULL;
	}
	cJSON *excep_local_JSON = exception_convertToJSON(
		abnormal_behaviour->excep);
	if(excep_local_JSON == NULL) {
		printf("abnormal_behaviour_convertToJSON() failed [excep]");
		goto end;
	}
	cJSON_AddItemToObject(item, "excep", excep_local_JSON);
	if(item->child == NULL) {
		printf("abnormal_behaviour_convertToJSON() failed [excep]");
		goto end;
	}

	if(abnormal_behaviour->dnn) {
		if(cJSON_AddStringToObject(item, "dnn",
		                           abnormal_behaviour->dnn) == NULL)
		{
			printf("abnormal_behaviour_convertToJSON() failed [dnn]");
			goto end;
		}
	}

	if(abnormal_behaviour->snssai) {
		cJSON *snssai_local_JSON = snssai_convertToJSON(
			abnormal_behaviour->snssai);
		if(snssai_local_JSON == NULL) {
			printf(
				"abnormal_behaviour_convertToJSON() failed [snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"abnormal_behaviour_convertToJSON() failed [snssai]");
			goto end;
		}
	}

	if(abnormal_behaviour->is_ratio) {
		if(cJSON_AddNumberToObject(item, "ratio",
		                           abnormal_behaviour->ratio) == NULL)
		{
			printf(
				"abnormal_behaviour_convertToJSON() failed [ratio]");
			goto end;
		}
	}

	if(abnormal_behaviour->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           abnormal_behaviour->confidence) ==
		   NULL)
		{
			printf(
				"abnormal_behaviour_convertToJSON() failed [confidence]");
			goto end;
		}
	}

	if(abnormal_behaviour->addt_meas_info) {
		cJSON *addt_meas_info_local_JSON =
			additional_measurement_convertToJSON(
				abnormal_behaviour->addt_meas_info);
		if(addt_meas_info_local_JSON == NULL) {
			printf(
				"abnormal_behaviour_convertToJSON() failed [addt_meas_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "addtMeasInfo",
		                      addt_meas_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"abnormal_behaviour_convertToJSON() failed [addt_meas_info]");
			goto end;
		}
	}

end:
	return item;
}

abnormal_behaviour_t *abnormal_behaviour_parseFromJSON(
	cJSON *abnormal_behaviourJSON) {
	abnormal_behaviour_t *abnormal_behaviour_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *supis = NULL;
	list_t *supisList = NULL;
	cJSON *excep = NULL;
	exception_t *excep_local_nonprim = NULL;
	cJSON *dnn = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *ratio = NULL;
	cJSON *confidence = NULL;
	cJSON *addt_meas_info = NULL;
	additional_measurement_t *addt_meas_info_local_nonprim = NULL;
	supis =
		cJSON_GetObjectItemCaseSensitive(abnormal_behaviourJSON,
		                                 "supis");
	if(supis) {
		cJSON *supis_local = NULL;
		if(!cJSON_IsArray(supis)) {
			printf(
				"abnormal_behaviour_parseFromJSON() failed [supis]");
			goto end;
		}

		supisList = list_create();

		cJSON_ArrayForEach(supis_local, supis) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(supis_local)) {
				printf(
					"abnormal_behaviour_parseFromJSON() failed [supis]");
				goto end;
			}
			list_add(supisList, strdup(supis_local->valuestring));
		}
	}

	excep =
		cJSON_GetObjectItemCaseSensitive(abnormal_behaviourJSON,
		                                 "excep");
	if(!excep) {
		printf("abnormal_behaviour_parseFromJSON() failed [excep]");
		goto end;
	}
	excep_local_nonprim = exception_parseFromJSON(excep);
	if(!excep_local_nonprim) {
		printf("exception_parseFromJSON failed [excep]");
		goto end;
	}

	dnn = cJSON_GetObjectItemCaseSensitive(abnormal_behaviourJSON, "dnn");
	if(dnn) {
		if(!cJSON_IsString(dnn) &&
		   !cJSON_IsNull(dnn))
		{
			printf("abnormal_behaviour_parseFromJSON() failed [dnn]");
			goto end;
		}
	}

	snssai = cJSON_GetObjectItemCaseSensitive(abnormal_behaviourJSON,
	                                          "snssai");
	if(snssai) {
		snssai_local_nonprim = snssai_parseFromJSON(snssai);
		if(!snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [snssai]");
			goto end;
		}
	}

	ratio =
		cJSON_GetObjectItemCaseSensitive(abnormal_behaviourJSON,
		                                 "ratio");
	if(ratio) {
		if(!cJSON_IsNumber(ratio)) {
			printf(
				"abnormal_behaviour_parseFromJSON() failed [ratio]");
			goto end;
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(abnormal_behaviourJSON,
	                                              "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"abnormal_behaviour_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	addt_meas_info = cJSON_GetObjectItemCaseSensitive(
		abnormal_behaviourJSON, "addtMeasInfo");
	if(addt_meas_info) {
		addt_meas_info_local_nonprim =
			additional_measurement_parseFromJSON(addt_meas_info);
		if(!addt_meas_info_local_nonprim) {
			printf(
				"additional_measurement_parseFromJSON failed [addt_meas_info]");
			goto end;
		}
	}

	abnormal_behaviour_local_var = abnormal_behaviour_create(
		supis ? supisList : NULL,
		excep_local_nonprim,
		dnn &&
		!cJSON_IsNull(dnn) ? strdup(dnn->valuestring) : NULL,
		snssai ? snssai_local_nonprim : NULL,
		ratio ? true : false,
		ratio ? ratio->valuedouble : 0,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0,
		addt_meas_info ? addt_meas_info_local_nonprim : NULL
		);

	return abnormal_behaviour_local_var;
end:
	if(supisList) {
		list_for_each(supisList, node) {
			free(node->data);
		}
		list_free(supisList);
		supisList = NULL;
	}
	if(excep_local_nonprim) {
		exception_free(excep_local_nonprim);
		excep_local_nonprim = NULL;
	}
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(addt_meas_info_local_nonprim) {
		additional_measurement_free(addt_meas_info_local_nonprim);
		addt_meas_info_local_nonprim = NULL;
	}
	return NULL;
}

abnormal_behaviour_t *abnormal_behaviour_copy(abnormal_behaviour_t	*dst,
                                              abnormal_behaviour_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = abnormal_behaviour_convertToJSON(src);
	if(!item) {
		printf("abnormal_behaviour_convertToJSON() failed");
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

	abnormal_behaviour_free(dst);
	dst = abnormal_behaviour_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
