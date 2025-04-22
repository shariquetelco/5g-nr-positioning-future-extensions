#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "qos_requirement.h"

qos_requirement_t *qos_requirement_create(bool is__5qi, int _5qi, char *gfbr_ul,
                                          char *gfbr_dl,
                                          qos_resource_type_t *res_type,
                                          bool is_pdb, int pdb, char *per,
                                          velocity_estimate_t *device_speed,
                                          device_type_t *device_type) {
	qos_requirement_t *qos_requirement_local_var =
		malloc(sizeof(qos_requirement_t));

	qos_requirement_local_var->is__5qi = is__5qi;
	qos_requirement_local_var->_5qi = _5qi;
	qos_requirement_local_var->gfbr_ul = gfbr_ul;
	qos_requirement_local_var->gfbr_dl = gfbr_dl;
	qos_requirement_local_var->res_type = res_type;
	qos_requirement_local_var->is_pdb = is_pdb;
	qos_requirement_local_var->pdb = pdb;
	qos_requirement_local_var->per = per;
	qos_requirement_local_var->device_speed = device_speed;
	qos_requirement_local_var->device_type = device_type;

	return qos_requirement_local_var;
}

void qos_requirement_free(qos_requirement_t *qos_requirement) {
	lnode_t *node = NULL;

	if(NULL == qos_requirement) {
		return;
	}
	if(qos_requirement->gfbr_ul) {
		free(qos_requirement->gfbr_ul);
		qos_requirement->gfbr_ul = NULL;
	}
	if(qos_requirement->gfbr_dl) {
		free(qos_requirement->gfbr_dl);
		qos_requirement->gfbr_dl = NULL;
	}
	if(qos_requirement->res_type) {
		qos_resource_type_free(qos_requirement->res_type);
		qos_requirement->res_type = NULL;
	}
	if(qos_requirement->per) {
		free(qos_requirement->per);
		qos_requirement->per = NULL;
	}
	if(qos_requirement->device_speed) {
		velocity_estimate_free(qos_requirement->device_speed);
		qos_requirement->device_speed = NULL;
	}
	if(qos_requirement->device_type) {
		device_type_free(qos_requirement->device_type);
		qos_requirement->device_type = NULL;
	}
	free(qos_requirement);
}

cJSON *qos_requirement_convertToJSON(qos_requirement_t *qos_requirement) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(qos_requirement == NULL) {
		printf("qos_requirement_convertToJSON() failed [QosRequirement]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(qos_requirement->is__5qi) {
		if(cJSON_AddNumberToObject(item, "5qi",
		                           qos_requirement->_5qi) == NULL)
		{
			printf("qos_requirement_convertToJSON() failed [_5qi]");
			goto end;
		}
	}

	if(qos_requirement->gfbr_ul) {
		if(cJSON_AddStringToObject(item, "gfbrUl",
		                           qos_requirement->gfbr_ul) == NULL)
		{
			printf(
				"qos_requirement_convertToJSON() failed [gfbr_ul]");
			goto end;
		}
	}

	if(qos_requirement->gfbr_dl) {
		if(cJSON_AddStringToObject(item, "gfbrDl",
		                           qos_requirement->gfbr_dl) == NULL)
		{
			printf(
				"qos_requirement_convertToJSON() failed [gfbr_dl]");
			goto end;
		}
	}

	if(qos_requirement->res_type) {
		cJSON *res_type_local_JSON = qos_resource_type_convertToJSON(
			qos_requirement->res_type);
		if(res_type_local_JSON == NULL) {
			printf(
				"qos_requirement_convertToJSON() failed [res_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "resType", res_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"qos_requirement_convertToJSON() failed [res_type]");
			goto end;
		}
	}

	if(qos_requirement->is_pdb) {
		if(cJSON_AddNumberToObject(item, "pdb",
		                           qos_requirement->pdb) == NULL)
		{
			printf("qos_requirement_convertToJSON() failed [pdb]");
			goto end;
		}
	}

	if(qos_requirement->per) {
		if(cJSON_AddStringToObject(item, "per",
		                           qos_requirement->per) == NULL)
		{
			printf("qos_requirement_convertToJSON() failed [per]");
			goto end;
		}
	}

	if(qos_requirement->device_speed) {
		cJSON *device_speed_local_JSON =
			velocity_estimate_convertToJSON(
				qos_requirement->device_speed);
		if(device_speed_local_JSON == NULL) {
			printf(
				"qos_requirement_convertToJSON() failed [device_speed]");
			goto end;
		}
		cJSON_AddItemToObject(item, "deviceSpeed",
		                      device_speed_local_JSON);
		if(item->child == NULL) {
			printf(
				"qos_requirement_convertToJSON() failed [device_speed]");
			goto end;
		}
	}

	if(qos_requirement->device_type) {
		cJSON *device_type_local_JSON = device_type_convertToJSON(
			qos_requirement->device_type);
		if(device_type_local_JSON == NULL) {
			printf(
				"qos_requirement_convertToJSON() failed [device_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "deviceType",
		                      device_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"qos_requirement_convertToJSON() failed [device_type]");
			goto end;
		}
	}

end:
	return item;
}

qos_requirement_t *qos_requirement_parseFromJSON(cJSON *qos_requirementJSON) {
	qos_requirement_t *qos_requirement_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *_5qi = NULL;
	cJSON *gfbr_ul = NULL;
	cJSON *gfbr_dl = NULL;
	cJSON *res_type = NULL;
	qos_resource_type_t *res_type_local_nonprim = NULL;
	cJSON *pdb = NULL;
	cJSON *per = NULL;
	cJSON *device_speed = NULL;
	velocity_estimate_t *device_speed_local_nonprim = NULL;
	cJSON *device_type = NULL;
	device_type_t *device_type_local_nonprim = NULL;
	_5qi = cJSON_GetObjectItemCaseSensitive(qos_requirementJSON, "5qi");
	if(_5qi) {
		if(!cJSON_IsNumber(_5qi)) {
			printf("qos_requirement_parseFromJSON() failed [_5qi]");
			goto end;
		}
	}

	gfbr_ul =
		cJSON_GetObjectItemCaseSensitive(qos_requirementJSON, "gfbrUl");
	if(gfbr_ul) {
		if(!cJSON_IsString(gfbr_ul) &&
		   !cJSON_IsNull(gfbr_ul))
		{
			printf(
				"qos_requirement_parseFromJSON() failed [gfbr_ul]");
			goto end;
		}
	}

	gfbr_dl =
		cJSON_GetObjectItemCaseSensitive(qos_requirementJSON, "gfbrDl");
	if(gfbr_dl) {
		if(!cJSON_IsString(gfbr_dl) &&
		   !cJSON_IsNull(gfbr_dl))
		{
			printf(
				"qos_requirement_parseFromJSON() failed [gfbr_dl]");
			goto end;
		}
	}

	res_type = cJSON_GetObjectItemCaseSensitive(qos_requirementJSON,
	                                            "resType");
	if(res_type) {
		res_type_local_nonprim = qos_resource_type_parseFromJSON(
			res_type);
		if(!res_type_local_nonprim) {
			printf(
				"qos_resource_type_parseFromJSON failed [res_type]");
			goto end;
		}
	}

	pdb = cJSON_GetObjectItemCaseSensitive(qos_requirementJSON, "pdb");
	if(pdb) {
		if(!cJSON_IsNumber(pdb)) {
			printf("qos_requirement_parseFromJSON() failed [pdb]");
			goto end;
		}
	}

	per = cJSON_GetObjectItemCaseSensitive(qos_requirementJSON, "per");
	if(per) {
		if(!cJSON_IsString(per) &&
		   !cJSON_IsNull(per))
		{
			printf("qos_requirement_parseFromJSON() failed [per]");
			goto end;
		}
	}

	device_speed = cJSON_GetObjectItemCaseSensitive(qos_requirementJSON,
	                                                "deviceSpeed");
	if(device_speed) {
		device_speed_local_nonprim = velocity_estimate_parseFromJSON(
			device_speed);
		if(!device_speed_local_nonprim) {
			printf(
				"velocity_estimate_parseFromJSON failed [device_speed]");
			goto end;
		}
	}

	device_type = cJSON_GetObjectItemCaseSensitive(qos_requirementJSON,
	                                               "deviceType");
	if(device_type) {
		device_type_local_nonprim = device_type_parseFromJSON(
			device_type);
		if(!device_type_local_nonprim) {
			printf("device_type_parseFromJSON failed [device_type]");
			goto end;
		}
	}

	qos_requirement_local_var = qos_requirement_create(
		_5qi ? true : false,
		_5qi ? _5qi->valuedouble : 0,
		gfbr_ul &&
		!cJSON_IsNull(gfbr_ul) ? strdup(gfbr_ul->valuestring) : NULL,
		gfbr_dl &&
		!cJSON_IsNull(gfbr_dl) ? strdup(gfbr_dl->valuestring) : NULL,
		res_type ? res_type_local_nonprim : NULL,
		pdb ? true : false,
		pdb ? pdb->valuedouble : 0,
		per &&
		!cJSON_IsNull(per) ? strdup(per->valuestring) : NULL,
		device_speed ? device_speed_local_nonprim : NULL,
		device_type ? device_type_local_nonprim : NULL
		);

	return qos_requirement_local_var;
end:
	if(res_type_local_nonprim) {
		qos_resource_type_free(res_type_local_nonprim);
		res_type_local_nonprim = NULL;
	}
	if(device_speed_local_nonprim) {
		velocity_estimate_free(device_speed_local_nonprim);
		device_speed_local_nonprim = NULL;
	}
	if(device_type_local_nonprim) {
		device_type_free(device_type_local_nonprim);
		device_type_local_nonprim = NULL;
	}
	return NULL;
}

qos_requirement_t *qos_requirement_copy(qos_requirement_t	*dst,
                                        qos_requirement_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = qos_requirement_convertToJSON(src);
	if(!item) {
		printf("qos_requirement_convertToJSON() failed");
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

	qos_requirement_free(dst);
	dst = qos_requirement_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
