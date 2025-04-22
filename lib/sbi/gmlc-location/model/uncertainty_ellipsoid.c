#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "uncertainty_ellipsoid.h"

uncertainty_ellipsoid_t *uncertainty_ellipsoid_create(float	semi_major,
                                                      float	semi_minor,
                                                      float	vertical,
                                                      int	orientation_major)
{
	uncertainty_ellipsoid_t *uncertainty_ellipsoid_local_var = malloc(
		sizeof(uncertainty_ellipsoid_t));

	uncertainty_ellipsoid_local_var->semi_major = semi_major;
	uncertainty_ellipsoid_local_var->semi_minor = semi_minor;
	uncertainty_ellipsoid_local_var->vertical = vertical;
	uncertainty_ellipsoid_local_var->orientation_major = orientation_major;

	return uncertainty_ellipsoid_local_var;
}

void uncertainty_ellipsoid_free(uncertainty_ellipsoid_t *uncertainty_ellipsoid)
{
	lnode_t *node = NULL;

	if(NULL == uncertainty_ellipsoid) {
		return;
	}
	free(uncertainty_ellipsoid);
}

cJSON *uncertainty_ellipsoid_convertToJSON(
	uncertainty_ellipsoid_t *uncertainty_ellipsoid) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(uncertainty_ellipsoid == NULL) {
		printf(
			"uncertainty_ellipsoid_convertToJSON() failed [UncertaintyEllipsoid]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "semiMajor",
	                           uncertainty_ellipsoid->semi_major) == NULL)
	{
		printf(
			"uncertainty_ellipsoid_convertToJSON() failed [semi_major]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "semiMinor",
	                           uncertainty_ellipsoid->semi_minor) == NULL)
	{
		printf(
			"uncertainty_ellipsoid_convertToJSON() failed [semi_minor]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "vertical",
	                           uncertainty_ellipsoid->vertical) == NULL)
	{
		printf("uncertainty_ellipsoid_convertToJSON() failed [vertical]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "orientationMajor",
	                           uncertainty_ellipsoid->orientation_major) ==
	   NULL)
	{
		printf(
			"uncertainty_ellipsoid_convertToJSON() failed [orientation_major]");
		goto end;
	}

end:
	return item;
}

uncertainty_ellipsoid_t *uncertainty_ellipsoid_parseFromJSON(
	cJSON *uncertainty_ellipsoidJSON) {
	uncertainty_ellipsoid_t *uncertainty_ellipsoid_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *semi_major = NULL;
	cJSON *semi_minor = NULL;
	cJSON *vertical = NULL;
	cJSON *orientation_major = NULL;
	semi_major = cJSON_GetObjectItemCaseSensitive(uncertainty_ellipsoidJSON,
	                                              "semiMajor");
	if(!semi_major) {
		printf(
			"uncertainty_ellipsoid_parseFromJSON() failed [semi_major]");
		goto end;
	}
	if(!cJSON_IsNumber(semi_major)) {
		printf(
			"uncertainty_ellipsoid_parseFromJSON() failed [semi_major]");
		goto end;
	}

	semi_minor = cJSON_GetObjectItemCaseSensitive(uncertainty_ellipsoidJSON,
	                                              "semiMinor");
	if(!semi_minor) {
		printf(
			"uncertainty_ellipsoid_parseFromJSON() failed [semi_minor]");
		goto end;
	}
	if(!cJSON_IsNumber(semi_minor)) {
		printf(
			"uncertainty_ellipsoid_parseFromJSON() failed [semi_minor]");
		goto end;
	}

	vertical = cJSON_GetObjectItemCaseSensitive(uncertainty_ellipsoidJSON,
	                                            "vertical");
	if(!vertical) {
		printf("uncertainty_ellipsoid_parseFromJSON() failed [vertical]");
		goto end;
	}
	if(!cJSON_IsNumber(vertical)) {
		printf("uncertainty_ellipsoid_parseFromJSON() failed [vertical]");
		goto end;
	}

	orientation_major = cJSON_GetObjectItemCaseSensitive(
		uncertainty_ellipsoidJSON, "orientationMajor");
	if(!orientation_major) {
		printf(
			"uncertainty_ellipsoid_parseFromJSON() failed [orientation_major]");
		goto end;
	}
	if(!cJSON_IsNumber(orientation_major)) {
		printf(
			"uncertainty_ellipsoid_parseFromJSON() failed [orientation_major]");
		goto end;
	}

	uncertainty_ellipsoid_local_var = uncertainty_ellipsoid_create(

		semi_major->valuedouble,

		semi_minor->valuedouble,

		vertical->valuedouble,

		orientation_major->valuedouble
		);

	return uncertainty_ellipsoid_local_var;
end:
	return NULL;
}

uncertainty_ellipsoid_t *uncertainty_ellipsoid_copy(
	uncertainty_ellipsoid_t *dst, uncertainty_ellipsoid_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = uncertainty_ellipsoid_convertToJSON(src);
	if(!item) {
		printf("uncertainty_ellipsoid_convertToJSON() failed");
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

	uncertainty_ellipsoid_free(dst);
	dst = uncertainty_ellipsoid_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
