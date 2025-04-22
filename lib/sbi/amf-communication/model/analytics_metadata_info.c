#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "analytics_metadata_info.h"

analytics_metadata_info_t *analytics_metadata_info_create(bool is_num_samples,
                                                          int num_samples,
                                                          time_window_t *data_window, list_t *data_stat_props, output_strategy_t *strategy,
                                                          accuracy_t *accuracy)
{
	analytics_metadata_info_t *analytics_metadata_info_local_var = malloc(
		sizeof(analytics_metadata_info_t));

	analytics_metadata_info_local_var->is_num_samples = is_num_samples;
	analytics_metadata_info_local_var->num_samples = num_samples;
	analytics_metadata_info_local_var->data_window = data_window;
	analytics_metadata_info_local_var->data_stat_props = data_stat_props;
	analytics_metadata_info_local_var->strategy = strategy;
	analytics_metadata_info_local_var->accuracy = accuracy;

	return analytics_metadata_info_local_var;
}

void analytics_metadata_info_free(
	analytics_metadata_info_t *analytics_metadata_info) {
	lnode_t *node = NULL;

	if(NULL == analytics_metadata_info) {
		return;
	}
	if(analytics_metadata_info->data_window) {
		time_window_free(analytics_metadata_info->data_window);
		analytics_metadata_info->data_window = NULL;
	}
	if(analytics_metadata_info->data_stat_props) {
		list_for_each(analytics_metadata_info->data_stat_props, node) {
			dataset_statistical_property_free(node->data);
		}
		list_free(analytics_metadata_info->data_stat_props);
		analytics_metadata_info->data_stat_props = NULL;
	}
	if(analytics_metadata_info->strategy) {
		output_strategy_free(analytics_metadata_info->strategy);
		analytics_metadata_info->strategy = NULL;
	}
	if(analytics_metadata_info->accuracy) {
		accuracy_free(analytics_metadata_info->accuracy);
		analytics_metadata_info->accuracy = NULL;
	}
	free(analytics_metadata_info);
}

cJSON *analytics_metadata_info_convertToJSON(
	analytics_metadata_info_t *analytics_metadata_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(analytics_metadata_info == NULL) {
		printf(
			"analytics_metadata_info_convertToJSON() failed [AnalyticsMetadataInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(analytics_metadata_info->is_num_samples) {
		if(cJSON_AddNumberToObject(item, "numSamples",
		                           analytics_metadata_info->num_samples)
		   == NULL)
		{
			printf(
				"analytics_metadata_info_convertToJSON() failed [num_samples]");
			goto end;
		}
	}

	if(analytics_metadata_info->data_window) {
		cJSON *data_window_local_JSON = time_window_convertToJSON(
			analytics_metadata_info->data_window);
		if(data_window_local_JSON == NULL) {
			printf(
				"analytics_metadata_info_convertToJSON() failed [data_window]");
			goto end;
		}
		cJSON_AddItemToObject(item, "dataWindow",
		                      data_window_local_JSON);
		if(item->child == NULL) {
			printf(
				"analytics_metadata_info_convertToJSON() failed [data_window]");
			goto end;
		}
	}

	if(analytics_metadata_info->data_stat_props) {
		cJSON *data_stat_propsList = cJSON_AddArrayToObject(item,
		                                                    "dataStatProps");
		if(data_stat_propsList == NULL) {
			printf(
				"analytics_metadata_info_convertToJSON() failed [data_stat_props]");
			goto end;
		}
		list_for_each(analytics_metadata_info->data_stat_props, node) {
			cJSON *itemLocal =
				dataset_statistical_property_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"analytics_metadata_info_convertToJSON() failed [data_stat_props]");
				goto end;
			}
			cJSON_AddItemToArray(data_stat_propsList, itemLocal);
		}
	}

	if(analytics_metadata_info->strategy) {
		cJSON *strategy_local_JSON = output_strategy_convertToJSON(
			analytics_metadata_info->strategy);
		if(strategy_local_JSON == NULL) {
			printf(
				"analytics_metadata_info_convertToJSON() failed [strategy]");
			goto end;
		}
		cJSON_AddItemToObject(item, "strategy", strategy_local_JSON);
		if(item->child == NULL) {
			printf(
				"analytics_metadata_info_convertToJSON() failed [strategy]");
			goto end;
		}
	}

	if(analytics_metadata_info->accuracy) {
		cJSON *accuracy_local_JSON = accuracy_convertToJSON(
			analytics_metadata_info->accuracy);
		if(accuracy_local_JSON == NULL) {
			printf(
				"analytics_metadata_info_convertToJSON() failed [accuracy]");
			goto end;
		}
		cJSON_AddItemToObject(item, "accuracy", accuracy_local_JSON);
		if(item->child == NULL) {
			printf(
				"analytics_metadata_info_convertToJSON() failed [accuracy]");
			goto end;
		}
	}

end:
	return item;
}

analytics_metadata_info_t *analytics_metadata_info_parseFromJSON(
	cJSON *analytics_metadata_infoJSON) {
	analytics_metadata_info_t *analytics_metadata_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *num_samples = NULL;
	cJSON *data_window = NULL;
	time_window_t *data_window_local_nonprim = NULL;
	cJSON *data_stat_props = NULL;
	list_t *data_stat_propsList = NULL;
	cJSON *strategy = NULL;
	output_strategy_t *strategy_local_nonprim = NULL;
	cJSON *accuracy = NULL;
	accuracy_t *accuracy_local_nonprim = NULL;
	num_samples = cJSON_GetObjectItemCaseSensitive(
		analytics_metadata_infoJSON, "numSamples");
	if(num_samples) {
		if(!cJSON_IsNumber(num_samples)) {
			printf(
				"analytics_metadata_info_parseFromJSON() failed [num_samples]");
			goto end;
		}
	}

	data_window = cJSON_GetObjectItemCaseSensitive(
		analytics_metadata_infoJSON, "dataWindow");
	if(data_window) {
		data_window_local_nonprim = time_window_parseFromJSON(
			data_window);
		if(!data_window_local_nonprim) {
			printf("time_window_parseFromJSON failed [data_window]");
			goto end;
		}
	}

	data_stat_props = cJSON_GetObjectItemCaseSensitive(
		analytics_metadata_infoJSON, "dataStatProps");
	if(data_stat_props) {
		cJSON *data_stat_props_local = NULL;
		if(!cJSON_IsArray(data_stat_props)) {
			printf(
				"analytics_metadata_info_parseFromJSON() failed [data_stat_props]");
			goto end;
		}

		data_stat_propsList = list_create();

		cJSON_ArrayForEach(data_stat_props_local, data_stat_props) {
			if(!cJSON_IsObject(data_stat_props_local)) {
				printf(
					"analytics_metadata_info_parseFromJSON() failed [data_stat_props]");
				goto end;
			}
			dataset_statistical_property_t *data_stat_propsItem =
				dataset_statistical_property_parseFromJSON(
					data_stat_props_local);
			if(!data_stat_propsItem) {
				printf("No data_stat_propsItem");
				goto end;
			}
			list_add(data_stat_propsList, data_stat_propsItem);
		}
	}

	strategy = cJSON_GetObjectItemCaseSensitive(analytics_metadata_infoJSON,
	                                            "strategy");
	if(strategy) {
		strategy_local_nonprim =
			output_strategy_parseFromJSON(strategy);
		if(!strategy_local_nonprim) {
			printf("output_strategy_parseFromJSON failed [strategy]");
			goto end;
		}
	}

	accuracy = cJSON_GetObjectItemCaseSensitive(analytics_metadata_infoJSON,
	                                            "accuracy");
	if(accuracy) {
		accuracy_local_nonprim = accuracy_parseFromJSON(accuracy);
		if(!accuracy_local_nonprim) {
			printf("accuracy_parseFromJSON failed [accuracy]");
			goto end;
		}
	}

	analytics_metadata_info_local_var = analytics_metadata_info_create(
		num_samples ? true : false,
		num_samples ? num_samples->valuedouble : 0,
		data_window ? data_window_local_nonprim : NULL,
		data_stat_props ? data_stat_propsList : NULL,
		strategy ? strategy_local_nonprim : NULL,
		accuracy ? accuracy_local_nonprim : NULL
		);

	return analytics_metadata_info_local_var;
end:
	if(data_window_local_nonprim) {
		time_window_free(data_window_local_nonprim);
		data_window_local_nonprim = NULL;
	}
	if(data_stat_propsList) {
		list_for_each(data_stat_propsList, node) {
			dataset_statistical_property_free(node->data);
		}
		list_free(data_stat_propsList);
		data_stat_propsList = NULL;
	}
	if(strategy_local_nonprim) {
		output_strategy_free(strategy_local_nonprim);
		strategy_local_nonprim = NULL;
	}
	if(accuracy_local_nonprim) {
		accuracy_free(accuracy_local_nonprim);
		accuracy_local_nonprim = NULL;
	}
	return NULL;
}

analytics_metadata_info_t *analytics_metadata_info_copy(
	analytics_metadata_info_t *dst, analytics_metadata_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = analytics_metadata_info_convertToJSON(src);
	if(!item) {
		printf("analytics_metadata_info_convertToJSON() failed");
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

	analytics_metadata_info_free(dst);
	dst = analytics_metadata_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
