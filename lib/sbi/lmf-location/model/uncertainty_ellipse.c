#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "uncertainty_ellipse.h"

uncertainty_ellipse_t *uncertainty_ellipse_create(float semi_major,
                                                  float semi_minor,
                                                  int	orientation_major) {
	uncertainty_ellipse_t *uncertainty_ellipse_local_var =
		malloc(sizeof(uncertainty_ellipse_t));

	uncertainty_ellipse_local_var->semi_major = semi_major;
	uncertainty_ellipse_local_var->semi_minor = semi_minor;
	uncertainty_ellipse_local_var->orientation_major = orientation_major;

	return uncertainty_ellipse_local_var;
}

void uncertainty_ellipse_free(uncertainty_ellipse_t *uncertainty_ellipse) {
	lnode_t *node = NULL;

	if(NULL == uncertainty_ellipse) {
		return;
	}
	free(uncertainty_ellipse);
}

cJSON *uncertainty_ellipse_convertToJSON(
	uncertainty_ellipse_t *uncertainty_ellipse) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(uncertainty_ellipse == NULL) {
		printf(
			"uncertainty_ellipse_convertToJSON() failed [UncertaintyEllipse]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "semiMajor",
	                           uncertainty_ellipse->semi_major) == NULL)
	{
		printf("uncertainty_ellipse_convertToJSON() failed [semi_major]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "semiMinor",
	                           uncertainty_ellipse->semi_minor) == NULL)
	{
		printf("uncertainty_ellipse_convertToJSON() failed [semi_minor]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "orientationMajor",
	                           uncertainty_ellipse->orientation_major) ==
	   NULL)
	{
		printf(
			"uncertainty_ellipse_convertToJSON() failed [orientation_major]");
		goto end;
	}

end:
	return item;
}

uncertainty_ellipse_t *uncertainty_ellipse_parseFromJSON(
	cJSON *uncertainty_ellipseJSON) {
	uncertainty_ellipse_t *uncertainty_ellipse_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *semi_major = NULL;
	cJSON *semi_minor = NULL;
	cJSON *orientation_major = NULL;
	semi_major = cJSON_GetObjectItemCaseSensitive(uncertainty_ellipseJSON,
	                                              "semiMajor");
	if(!semi_major) {
		printf("uncertainty_ellipse_parseFromJSON() failed [semi_major]");
		goto end;
	}
	if(!cJSON_IsNumber(semi_major)) {
		printf("uncertainty_ellipse_parseFromJSON() failed [semi_major]");
		goto end;
	}

	semi_minor = cJSON_GetObjectItemCaseSensitive(uncertainty_ellipseJSON,
	                                              "semiMinor");
	if(!semi_minor) {
		printf("uncertainty_ellipse_parseFromJSON() failed [semi_minor]");
		goto end;
	}
	if(!cJSON_IsNumber(semi_minor)) {
		printf("uncertainty_ellipse_parseFromJSON() failed [semi_minor]");
		goto end;
	}

	orientation_major = cJSON_GetObjectItemCaseSensitive(
		uncertainty_ellipseJSON, "orientationMajor");
	if(!orientation_major) {
		printf(
			"uncertainty_ellipse_parseFromJSON() failed [orientation_major]");
		goto end;
	}
	if(!cJSON_IsNumber(orientation_major)) {
		printf(
			"uncertainty_ellipse_parseFromJSON() failed [orientation_major]");
		goto end;
	}

	uncertainty_ellipse_local_var = uncertainty_ellipse_create(

		semi_major->valuedouble,

		semi_minor->valuedouble,

		orientation_major->valuedouble
		);

	return uncertainty_ellipse_local_var;
end:
	return NULL;
}

uncertainty_ellipse_t *uncertainty_ellipse_copy(uncertainty_ellipse_t	*dst,
                                                uncertainty_ellipse_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = uncertainty_ellipse_convertToJSON(src);
	if(!item) {
		printf("uncertainty_ellipse_convertToJSON() failed");
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

	uncertainty_ellipse_free(dst);
	dst = uncertainty_ellipse_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
