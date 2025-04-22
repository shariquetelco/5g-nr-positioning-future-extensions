#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "top_application.h"

top_application_t *top_application_create(char *app_id,
                                          flow_info_t *ip_traffic_filter,
                                          bool is_ratio, int ratio) {
	top_application_t *top_application_local_var =
		malloc(sizeof(top_application_t));

	top_application_local_var->app_id = app_id;
	top_application_local_var->ip_traffic_filter = ip_traffic_filter;
	top_application_local_var->is_ratio = is_ratio;
	top_application_local_var->ratio = ratio;

	return top_application_local_var;
}

void top_application_free(top_application_t *top_application) {
	lnode_t *node = NULL;

	if(NULL == top_application) {
		return;
	}
	if(top_application->app_id) {
		free(top_application->app_id);
		top_application->app_id = NULL;
	}
	if(top_application->ip_traffic_filter) {
		flow_info_free(top_application->ip_traffic_filter);
		top_application->ip_traffic_filter = NULL;
	}
	free(top_application);
}

cJSON *top_application_convertToJSON(top_application_t *top_application) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(top_application == NULL) {
		printf("top_application_convertToJSON() failed [TopApplication]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(top_application->app_id) {
		if(cJSON_AddStringToObject(item, "appId",
		                           top_application->app_id) == NULL)
		{
			printf("top_application_convertToJSON() failed [app_id]");
			goto end;
		}
	}

	if(top_application->ip_traffic_filter) {
		cJSON *ip_traffic_filter_local_JSON = flow_info_convertToJSON(
			top_application->ip_traffic_filter);
		if(ip_traffic_filter_local_JSON == NULL) {
			printf(
				"top_application_convertToJSON() failed [ip_traffic_filter]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ipTrafficFilter",
		                      ip_traffic_filter_local_JSON);
		if(item->child == NULL) {
			printf(
				"top_application_convertToJSON() failed [ip_traffic_filter]");
			goto end;
		}
	}

	if(top_application->is_ratio) {
		if(cJSON_AddNumberToObject(item, "ratio",
		                           top_application->ratio) == NULL)
		{
			printf("top_application_convertToJSON() failed [ratio]");
			goto end;
		}
	}

end:
	return item;
}

top_application_t *top_application_parseFromJSON(cJSON *top_applicationJSON) {
	top_application_t *top_application_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *app_id = NULL;
	cJSON *ip_traffic_filter = NULL;
	flow_info_t *ip_traffic_filter_local_nonprim = NULL;
	cJSON *ratio = NULL;
	app_id = cJSON_GetObjectItemCaseSensitive(top_applicationJSON, "appId");
	if(app_id) {
		if(!cJSON_IsString(app_id) &&
		   !cJSON_IsNull(app_id))
		{
			printf("top_application_parseFromJSON() failed [app_id]");
			goto end;
		}
	}

	ip_traffic_filter = cJSON_GetObjectItemCaseSensitive(
		top_applicationJSON, "ipTrafficFilter");
	if(ip_traffic_filter) {
		ip_traffic_filter_local_nonprim = flow_info_parseFromJSON(
			ip_traffic_filter);
		if(!ip_traffic_filter_local_nonprim) {
			printf(
				"flow_info_parseFromJSON failed [ip_traffic_filter]");
			goto end;
		}
	}

	ratio = cJSON_GetObjectItemCaseSensitive(top_applicationJSON, "ratio");
	if(ratio) {
		if(!cJSON_IsNumber(ratio)) {
			printf("top_application_parseFromJSON() failed [ratio]");
			goto end;
		}
	}

	top_application_local_var = top_application_create(
		app_id &&
		!cJSON_IsNull(app_id) ? strdup(app_id->valuestring) : NULL,
		ip_traffic_filter ? ip_traffic_filter_local_nonprim : NULL,
		ratio ? true : false,
		ratio ? ratio->valuedouble : 0
		);

	return top_application_local_var;
end:
	if(ip_traffic_filter_local_nonprim) {
		flow_info_free(ip_traffic_filter_local_nonprim);
		ip_traffic_filter_local_nonprim = NULL;
	}
	return NULL;
}

top_application_t *top_application_copy(top_application_t	*dst,
                                        top_application_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = top_application_convertToJSON(src);
	if(!item) {
		printf("top_application_convertToJSON() failed");
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

	top_application_free(dst);
	dst = top_application_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
