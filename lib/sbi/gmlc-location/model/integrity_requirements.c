#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "integrity_requirements.h"

integrity_requirements_t *integrity_requirements_create(bool is_time_to_alert,
                                                        int time_to_alert,
                                                        bool is_target_integrity_risk, int target_integrity_risk,
                                                        alert_limit_t *alert_limit)
{
	integrity_requirements_t *integrity_requirements_local_var = malloc(
		sizeof(integrity_requirements_t));

	integrity_requirements_local_var->is_time_to_alert = is_time_to_alert;
	integrity_requirements_local_var->time_to_alert = time_to_alert;
	integrity_requirements_local_var->is_target_integrity_risk =
		is_target_integrity_risk;
	integrity_requirements_local_var->target_integrity_risk =
		target_integrity_risk;
	integrity_requirements_local_var->alert_limit = alert_limit;

	return integrity_requirements_local_var;
}

void integrity_requirements_free(
	integrity_requirements_t *integrity_requirements) {
	lnode_t *node = NULL;

	if(NULL == integrity_requirements) {
		return;
	}
	if(integrity_requirements->alert_limit) {
		alert_limit_free(integrity_requirements->alert_limit);
		integrity_requirements->alert_limit = NULL;
	}
	free(integrity_requirements);
}

cJSON *integrity_requirements_convertToJSON(
	integrity_requirements_t *integrity_requirements) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(integrity_requirements == NULL) {
		printf(
			"integrity_requirements_convertToJSON() failed [IntegrityRequirements]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(integrity_requirements->is_time_to_alert) {
		if(cJSON_AddNumberToObject(item, "timeToAlert",
		                           integrity_requirements->time_to_alert)
		   == NULL)
		{
			printf(
				"integrity_requirements_convertToJSON() failed [time_to_alert]");
			goto end;
		}
	}

	if(integrity_requirements->is_target_integrity_risk) {
		if(cJSON_AddNumberToObject(item, "targetIntegrityRisk",
		                           integrity_requirements->
		                           target_integrity_risk) == NULL)
		{
			printf(
				"integrity_requirements_convertToJSON() failed [target_integrity_risk]");
			goto end;
		}
	}

	if(integrity_requirements->alert_limit) {
		cJSON *alert_limit_local_JSON = alert_limit_convertToJSON(
			integrity_requirements->alert_limit);
		if(alert_limit_local_JSON == NULL) {
			printf(
				"integrity_requirements_convertToJSON() failed [alert_limit]");
			goto end;
		}
		cJSON_AddItemToObject(item, "alertLimit",
		                      alert_limit_local_JSON);
		if(item->child == NULL) {
			printf(
				"integrity_requirements_convertToJSON() failed [alert_limit]");
			goto end;
		}
	}

end:
	return item;
}

integrity_requirements_t *integrity_requirements_parseFromJSON(
	cJSON *integrity_requirementsJSON) {
	integrity_requirements_t *integrity_requirements_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *time_to_alert = NULL;
	cJSON *target_integrity_risk = NULL;
	cJSON *alert_limit = NULL;
	alert_limit_t *alert_limit_local_nonprim = NULL;
	time_to_alert = cJSON_GetObjectItemCaseSensitive(
		integrity_requirementsJSON, "timeToAlert");
	if(time_to_alert) {
		if(!cJSON_IsNumber(time_to_alert)) {
			printf(
				"integrity_requirements_parseFromJSON() failed [time_to_alert]");
			goto end;
		}
	}

	target_integrity_risk = cJSON_GetObjectItemCaseSensitive(
		integrity_requirementsJSON, "targetIntegrityRisk");
	if(target_integrity_risk) {
		if(!cJSON_IsNumber(target_integrity_risk)) {
			printf(
				"integrity_requirements_parseFromJSON() failed [target_integrity_risk]");
			goto end;
		}
	}

	alert_limit = cJSON_GetObjectItemCaseSensitive(
		integrity_requirementsJSON, "alertLimit");
	if(alert_limit) {
		alert_limit_local_nonprim = alert_limit_parseFromJSON(
			alert_limit);
		if(!alert_limit_local_nonprim) {
			printf("alert_limit_parseFromJSON failed [alert_limit]");
			goto end;
		}
	}

	integrity_requirements_local_var = integrity_requirements_create(
		time_to_alert ? true : false,
		time_to_alert ? time_to_alert->valuedouble : 0,
		target_integrity_risk ? true : false,
		target_integrity_risk ? target_integrity_risk->valuedouble : 0,
		alert_limit ? alert_limit_local_nonprim : NULL
		);

	return integrity_requirements_local_var;
end:
	if(alert_limit_local_nonprim) {
		alert_limit_free(alert_limit_local_nonprim);
		alert_limit_local_nonprim = NULL;
	}
	return NULL;
}

integrity_requirements_t *integrity_requirements_copy(
	integrity_requirements_t *dst, integrity_requirements_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = integrity_requirements_convertToJSON(src);
	if(!item) {
		printf("integrity_requirements_convertToJSON() failed");
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

	integrity_requirements_free(dst);
	dst = integrity_requirements_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
