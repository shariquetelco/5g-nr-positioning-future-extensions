#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point_altitude_uncertainty_all_of.h"

point_altitude_uncertainty_all_of_t *point_altitude_uncertainty_all_of_create(
	geographical_coordinates_t *point, double altitude,
	uncertainty_ellipse_t *uncertainty_ellipse, float uncertainty_altitude,
	int confidence, bool is_v_confidence, int v_confidence) {
	point_altitude_uncertainty_all_of_t *
	        point_altitude_uncertainty_all_of_local_var =
		malloc(sizeof(point_altitude_uncertainty_all_of_t));

	point_altitude_uncertainty_all_of_local_var->point = point;
	point_altitude_uncertainty_all_of_local_var->altitude = altitude;
	point_altitude_uncertainty_all_of_local_var->uncertainty_ellipse =
		uncertainty_ellipse;
	point_altitude_uncertainty_all_of_local_var->uncertainty_altitude =
		uncertainty_altitude;
	point_altitude_uncertainty_all_of_local_var->confidence = confidence;
	point_altitude_uncertainty_all_of_local_var->is_v_confidence =
		is_v_confidence;
	point_altitude_uncertainty_all_of_local_var->v_confidence =
		v_confidence;

	return point_altitude_uncertainty_all_of_local_var;
}

void point_altitude_uncertainty_all_of_free(
	point_altitude_uncertainty_all_of_t *point_altitude_uncertainty_all_of)
{
	lnode_t *node = NULL;

	if(NULL == point_altitude_uncertainty_all_of) {
		return;
	}
	if(point_altitude_uncertainty_all_of->point) {
		geographical_coordinates_free(
			point_altitude_uncertainty_all_of->point);
		point_altitude_uncertainty_all_of->point = NULL;
	}
	if(point_altitude_uncertainty_all_of->uncertainty_ellipse) {
		uncertainty_ellipse_free(
			point_altitude_uncertainty_all_of->uncertainty_ellipse);
		point_altitude_uncertainty_all_of->uncertainty_ellipse = NULL;
	}
	free(point_altitude_uncertainty_all_of);
}

cJSON *point_altitude_uncertainty_all_of_convertToJSON(
	point_altitude_uncertainty_all_of_t *point_altitude_uncertainty_all_of)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(point_altitude_uncertainty_all_of == NULL) {
		printf(
			"point_altitude_uncertainty_all_of_convertToJSON() failed [PointAltitudeUncertainty_allOf]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!point_altitude_uncertainty_all_of->point) {
		printf(
			"point_altitude_uncertainty_all_of_convertToJSON() failed [point]");
		return NULL;
	}
	cJSON *point_local_JSON = geographical_coordinates_convertToJSON(
		point_altitude_uncertainty_all_of->point);
	if(point_local_JSON == NULL) {
		printf(
			"point_altitude_uncertainty_all_of_convertToJSON() failed [point]");
		goto end;
	}
	cJSON_AddItemToObject(item, "point", point_local_JSON);
	if(item->child == NULL) {
		printf(
			"point_altitude_uncertainty_all_of_convertToJSON() failed [point]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "altitude",
	                           point_altitude_uncertainty_all_of->altitude)
	   == NULL)
	{
		printf(
			"point_altitude_uncertainty_all_of_convertToJSON() failed [altitude]");
		goto end;
	}

	if(!point_altitude_uncertainty_all_of->uncertainty_ellipse) {
		printf(
			"point_altitude_uncertainty_all_of_convertToJSON() failed [uncertainty_ellipse]");
		return NULL;
	}
	cJSON *uncertainty_ellipse_local_JSON =
		uncertainty_ellipse_convertToJSON(
			point_altitude_uncertainty_all_of->uncertainty_ellipse);
	if(uncertainty_ellipse_local_JSON == NULL) {
		printf(
			"point_altitude_uncertainty_all_of_convertToJSON() failed [uncertainty_ellipse]");
		goto end;
	}
	cJSON_AddItemToObject(item, "uncertaintyEllipse",
	                      uncertainty_ellipse_local_JSON);
	if(item->child == NULL) {
		printf(
			"point_altitude_uncertainty_all_of_convertToJSON() failed [uncertainty_ellipse]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "uncertaintyAltitude",
	                           point_altitude_uncertainty_all_of->
	                           uncertainty_altitude) == NULL)
	{
		printf(
			"point_altitude_uncertainty_all_of_convertToJSON() failed [uncertainty_altitude]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "confidence",
	                           point_altitude_uncertainty_all_of->confidence)
	   == NULL)
	{
		printf(
			"point_altitude_uncertainty_all_of_convertToJSON() failed [confidence]");
		goto end;
	}

	if(point_altitude_uncertainty_all_of->is_v_confidence) {
		if(cJSON_AddNumberToObject(item, "vConfidence",
		                           point_altitude_uncertainty_all_of->
		                           v_confidence) == NULL)
		{
			printf(
				"point_altitude_uncertainty_all_of_convertToJSON() failed [v_confidence]");
			goto end;
		}
	}

end:
	return item;
}

point_altitude_uncertainty_all_of_t *
point_altitude_uncertainty_all_of_parseFromJSON(
	cJSON *point_altitude_uncertainty_all_ofJSON) {
	point_altitude_uncertainty_all_of_t *
	        point_altitude_uncertainty_all_of_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *point = NULL;
	geographical_coordinates_t *point_local_nonprim = NULL;
	cJSON *altitude = NULL;
	cJSON *uncertainty_ellipse = NULL;
	uncertainty_ellipse_t *uncertainty_ellipse_local_nonprim = NULL;
	cJSON *uncertainty_altitude = NULL;
	cJSON *confidence = NULL;
	cJSON *v_confidence = NULL;
	point = cJSON_GetObjectItemCaseSensitive(
		point_altitude_uncertainty_all_ofJSON, "point");
	if(!point) {
		printf(
			"point_altitude_uncertainty_all_of_parseFromJSON() failed [point]");
		goto end;
	}
	point_local_nonprim = geographical_coordinates_parseFromJSON(point);
	if(!point_local_nonprim) {
		printf("geographical_coordinates_parseFromJSON failed [point]");
		goto end;
	}

	altitude = cJSON_GetObjectItemCaseSensitive(
		point_altitude_uncertainty_all_ofJSON, "altitude");
	if(!altitude) {
		printf(
			"point_altitude_uncertainty_all_of_parseFromJSON() failed [altitude]");
		goto end;
	}
	if(!cJSON_IsNumber(altitude)) {
		printf(
			"point_altitude_uncertainty_all_of_parseFromJSON() failed [altitude]");
		goto end;
	}

	uncertainty_ellipse = cJSON_GetObjectItemCaseSensitive(
		point_altitude_uncertainty_all_ofJSON, "uncertaintyEllipse");
	if(!uncertainty_ellipse) {
		printf(
			"point_altitude_uncertainty_all_of_parseFromJSON() failed [uncertainty_ellipse]");
		goto end;
	}
	uncertainty_ellipse_local_nonprim = uncertainty_ellipse_parseFromJSON(
		uncertainty_ellipse);
	if(!uncertainty_ellipse_local_nonprim) {
		printf(
			"uncertainty_ellipse_parseFromJSON failed [uncertainty_ellipse]");
		goto end;
	}

	uncertainty_altitude = cJSON_GetObjectItemCaseSensitive(
		point_altitude_uncertainty_all_ofJSON, "uncertaintyAltitude");
	if(!uncertainty_altitude) {
		printf(
			"point_altitude_uncertainty_all_of_parseFromJSON() failed [uncertainty_altitude]");
		goto end;
	}
	if(!cJSON_IsNumber(uncertainty_altitude)) {
		printf(
			"point_altitude_uncertainty_all_of_parseFromJSON() failed [uncertainty_altitude]");
		goto end;
	}

	confidence = cJSON_GetObjectItemCaseSensitive(
		point_altitude_uncertainty_all_ofJSON, "confidence");
	if(!confidence) {
		printf(
			"point_altitude_uncertainty_all_of_parseFromJSON() failed [confidence]");
		goto end;
	}
	if(!cJSON_IsNumber(confidence)) {
		printf(
			"point_altitude_uncertainty_all_of_parseFromJSON() failed [confidence]");
		goto end;
	}

	v_confidence = cJSON_GetObjectItemCaseSensitive(
		point_altitude_uncertainty_all_ofJSON, "vConfidence");
	if(v_confidence) {
		if(!cJSON_IsNumber(v_confidence)) {
			printf(
				"point_altitude_uncertainty_all_of_parseFromJSON() failed [v_confidence]");
			goto end;
		}
	}

	point_altitude_uncertainty_all_of_local_var =
		point_altitude_uncertainty_all_of_create(
			point_local_nonprim,

			altitude->valuedouble,
			uncertainty_ellipse_local_nonprim,

			uncertainty_altitude->valuedouble,

			confidence->valuedouble,
			v_confidence ? true : false,
			v_confidence ? v_confidence->valuedouble : 0
			);

	return point_altitude_uncertainty_all_of_local_var;
end:
	if(point_local_nonprim) {
		geographical_coordinates_free(point_local_nonprim);
		point_local_nonprim = NULL;
	}
	if(uncertainty_ellipse_local_nonprim) {
		uncertainty_ellipse_free(uncertainty_ellipse_local_nonprim);
		uncertainty_ellipse_local_nonprim = NULL;
	}
	return NULL;
}

point_altitude_uncertainty_all_of_t *point_altitude_uncertainty_all_of_copy(
	point_altitude_uncertainty_all_of_t	*dst,
	point_altitude_uncertainty_all_of_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = point_altitude_uncertainty_all_of_convertToJSON(src);
	if(!item) {
		printf(
			"point_altitude_uncertainty_all_of_convertToJSON() failed");
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

	point_altitude_uncertainty_all_of_free(dst);
	dst = point_altitude_uncertainty_all_of_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
