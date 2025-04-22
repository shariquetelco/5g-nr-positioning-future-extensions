#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ec_restriction_data_wb.h"

ec_restriction_data_wb_t *ec_restriction_data_wb_create(
	bool is_ec_mode_a_restricted, int ec_mode_a_restricted,
	int ec_mode_b_restricted) {
	ec_restriction_data_wb_t *ec_restriction_data_wb_local_var = malloc(
		sizeof(ec_restriction_data_wb_t));

	ec_restriction_data_wb_local_var->is_ec_mode_a_restricted =
		is_ec_mode_a_restricted;
	ec_restriction_data_wb_local_var->ec_mode_a_restricted =
		ec_mode_a_restricted;
	ec_restriction_data_wb_local_var->ec_mode_b_restricted =
		ec_mode_b_restricted;

	return ec_restriction_data_wb_local_var;
}

void ec_restriction_data_wb_free(
	ec_restriction_data_wb_t *ec_restriction_data_wb) {
	lnode_t *node = NULL;

	if(NULL == ec_restriction_data_wb) {
		return;
	}
	free(ec_restriction_data_wb);
}

cJSON *ec_restriction_data_wb_convertToJSON(
	ec_restriction_data_wb_t *ec_restriction_data_wb) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ec_restriction_data_wb == NULL) {
		printf(
			"ec_restriction_data_wb_convertToJSON() failed [EcRestrictionDataWb]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ec_restriction_data_wb->is_ec_mode_a_restricted) {
		if(cJSON_AddBoolToObject(item, "ecModeARestricted",
		                         ec_restriction_data_wb->
		                         ec_mode_a_restricted) == NULL)
		{
			printf(
				"ec_restriction_data_wb_convertToJSON() failed [ec_mode_a_restricted]");
			goto end;
		}
	}

	if(cJSON_AddBoolToObject(item, "ecModeBRestricted",
	                         ec_restriction_data_wb->ec_mode_b_restricted)
	   == NULL)
	{
		printf(
			"ec_restriction_data_wb_convertToJSON() failed [ec_mode_b_restricted]");
		goto end;
	}

end:
	return item;
}

ec_restriction_data_wb_t *ec_restriction_data_wb_parseFromJSON(
	cJSON *ec_restriction_data_wbJSON) {
	ec_restriction_data_wb_t *ec_restriction_data_wb_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ec_mode_a_restricted = NULL;
	cJSON *ec_mode_b_restricted = NULL;
	ec_mode_a_restricted = cJSON_GetObjectItemCaseSensitive(
		ec_restriction_data_wbJSON, "ecModeARestricted");
	if(ec_mode_a_restricted) {
		if(!cJSON_IsBool(ec_mode_a_restricted)) {
			printf(
				"ec_restriction_data_wb_parseFromJSON() failed [ec_mode_a_restricted]");
			goto end;
		}
	}

	ec_mode_b_restricted = cJSON_GetObjectItemCaseSensitive(
		ec_restriction_data_wbJSON, "ecModeBRestricted");
	if(!ec_mode_b_restricted) {
		printf(
			"ec_restriction_data_wb_parseFromJSON() failed [ec_mode_b_restricted]");
		goto end;
	}
	if(!cJSON_IsBool(ec_mode_b_restricted)) {
		printf(
			"ec_restriction_data_wb_parseFromJSON() failed [ec_mode_b_restricted]");
		goto end;
	}

	ec_restriction_data_wb_local_var = ec_restriction_data_wb_create(
		ec_mode_a_restricted ? true : false,
		ec_mode_a_restricted ? ec_mode_a_restricted->valueint : 0,

		ec_mode_b_restricted->valueint
		);

	return ec_restriction_data_wb_local_var;
end:
	return NULL;
}

ec_restriction_data_wb_t *ec_restriction_data_wb_copy(
	ec_restriction_data_wb_t *dst, ec_restriction_data_wb_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ec_restriction_data_wb_convertToJSON(src);
	if(!item) {
		printf("ec_restriction_data_wb_convertToJSON() failed");
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

	ec_restriction_data_wb_free(dst);
	dst = ec_restriction_data_wb_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
