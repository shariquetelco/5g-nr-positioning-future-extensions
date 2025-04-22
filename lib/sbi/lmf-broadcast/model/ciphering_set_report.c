#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ciphering_set_report.h"

ciphering_set_report_t *ciphering_set_report_create(
	int			ciphering_set_id,
	storage_outcome_e	storage_outcome)
{
	ciphering_set_report_t *ciphering_set_report_local_var =
		malloc(sizeof(ciphering_set_report_t));

	ciphering_set_report_local_var->ciphering_set_id = ciphering_set_id;
	ciphering_set_report_local_var->storage_outcome = storage_outcome;

	return ciphering_set_report_local_var;
}

void ciphering_set_report_free(ciphering_set_report_t *ciphering_set_report) {
	lnode_t *node = NULL;

	if(NULL == ciphering_set_report) {
		return;
	}
	free(ciphering_set_report);
}

cJSON *ciphering_set_report_convertToJSON(
	ciphering_set_report_t *ciphering_set_report) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ciphering_set_report == NULL) {
		printf(
			"ciphering_set_report_convertToJSON() failed [CipheringSetReport]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "cipheringSetID",
	                           ciphering_set_report->ciphering_set_id) ==
	   NULL)
	{
		printf(
			"ciphering_set_report_convertToJSON() failed [ciphering_set_id]");
		goto end;
	}

	if(ciphering_set_report->storage_outcome == storage_outcome_NULL) {
		printf(
			"ciphering_set_report_convertToJSON() failed [storage_outcome]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "storageOutcome",
	                           storage_outcome_ToString(ciphering_set_report
	                                                    ->storage_outcome))
	   ==
	   NULL)
	{
		printf(
			"ciphering_set_report_convertToJSON() failed [storage_outcome]");
		goto end;
	}

end:
	return item;
}

ciphering_set_report_t *ciphering_set_report_parseFromJSON(
	cJSON *ciphering_set_reportJSON) {
	ciphering_set_report_t *ciphering_set_report_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ciphering_set_id = NULL;
	cJSON *storage_outcome = NULL;
	storage_outcome_e storage_outcomeVariable = 0;
	ciphering_set_id = cJSON_GetObjectItemCaseSensitive(
		ciphering_set_reportJSON, "cipheringSetID");
	if(!ciphering_set_id) {
		printf(
			"ciphering_set_report_parseFromJSON() failed [ciphering_set_id]");
		goto end;
	}
	if(!cJSON_IsNumber(ciphering_set_id)) {
		printf(
			"ciphering_set_report_parseFromJSON() failed [ciphering_set_id]");
		goto end;
	}

	storage_outcome = cJSON_GetObjectItemCaseSensitive(
		ciphering_set_reportJSON, "storageOutcome");
	if(!storage_outcome) {
		printf(
			"ciphering_set_report_parseFromJSON() failed [storage_outcome]");
		goto end;
	}
	if(!cJSON_IsString(storage_outcome)) {
		printf(
			"ciphering_set_report_parseFromJSON() failed [storage_outcome]");
		goto end;
	}
	storage_outcomeVariable = storage_outcome_FromString(
		storage_outcome->valuestring);

	ciphering_set_report_local_var = ciphering_set_report_create(

		ciphering_set_id->valuedouble,
		storage_outcomeVariable
		);

	return ciphering_set_report_local_var;
end:
	return NULL;
}

ciphering_set_report_t *ciphering_set_report_copy(
	ciphering_set_report_t	*dst,
	ciphering_set_report_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = ciphering_set_report_convertToJSON(src);
	if(!item) {
		printf("ciphering_set_report_convertToJSON() failed");
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

	ciphering_set_report_free(dst);
	dst = ciphering_set_report_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
