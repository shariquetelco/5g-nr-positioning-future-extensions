#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "analytics_metadata_indication.h"

analytics_metadata_indication_t *analytics_metadata_indication_create(
	time_window_t *data_window, list_t *data_stat_props,
	output_strategy_t *strategy, list_t *aggr_nwdaf_ids) {
	analytics_metadata_indication_t *analytics_metadata_indication_local_var
	        = malloc(sizeof(analytics_metadata_indication_t));

	analytics_metadata_indication_local_var->data_window = data_window;
	analytics_metadata_indication_local_var->data_stat_props =
		data_stat_props;
	analytics_metadata_indication_local_var->strategy = strategy;
	analytics_metadata_indication_local_var->aggr_nwdaf_ids =
		aggr_nwdaf_ids;

	return analytics_metadata_indication_local_var;
}

void analytics_metadata_indication_free(
	analytics_metadata_indication_t *analytics_metadata_indication) {
	lnode_t *node = NULL;

	if(NULL == analytics_metadata_indication) {
		return;
	}
	if(analytics_metadata_indication->data_window) {
		time_window_free(analytics_metadata_indication->data_window);
		analytics_metadata_indication->data_window = NULL;
	}
	if(analytics_metadata_indication->data_stat_props) {
		list_for_each(analytics_metadata_indication->data_stat_props,
		              node) {
			dataset_statistical_property_free(node->data);
		}
		list_free(analytics_metadata_indication->data_stat_props);
		analytics_metadata_indication->data_stat_props = NULL;
	}
	if(analytics_metadata_indication->strategy) {
		output_strategy_free(analytics_metadata_indication->strategy);
		analytics_metadata_indication->strategy = NULL;
	}
	if(analytics_metadata_indication->aggr_nwdaf_ids) {
		list_for_each(analytics_metadata_indication->aggr_nwdaf_ids,
		              node) {
			free(node->data);
		}
		list_free(analytics_metadata_indication->aggr_nwdaf_ids);
		analytics_metadata_indication->aggr_nwdaf_ids = NULL;
	}
	free(analytics_metadata_indication);
}

cJSON *analytics_metadata_indication_convertToJSON(
	analytics_metadata_indication_t *analytics_metadata_indication) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(analytics_metadata_indication == NULL) {
		printf(
			"analytics_metadata_indication_convertToJSON() failed [AnalyticsMetadataIndication]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(analytics_metadata_indication->data_window) {
		cJSON *data_window_local_JSON = time_window_convertToJSON(
			analytics_metadata_indication->data_window);
		if(data_window_local_JSON == NULL) {
			printf(
				"analytics_metadata_indication_convertToJSON() failed [data_window]");
			goto end;
		}
		cJSON_AddItemToObject(item, "dataWindow",
		                      data_window_local_JSON);
		if(item->child == NULL) {
			printf(
				"analytics_metadata_indication_convertToJSON() failed [data_window]");
			goto end;
		}
	}

	if(analytics_metadata_indication->data_stat_props) {
		cJSON *data_stat_propsList = cJSON_AddArrayToObject(item,
		                                                    "dataStatProps");
		if(data_stat_propsList == NULL) {
			printf(
				"analytics_metadata_indication_convertToJSON() failed [data_stat_props]");
			goto end;
		}
		list_for_each(analytics_metadata_indication->data_stat_props,
		              node) {
			cJSON *itemLocal =
				dataset_statistical_property_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"analytics_metadata_indication_convertToJSON() failed [data_stat_props]");
				goto end;
			}
			cJSON_AddItemToArray(data_stat_propsList, itemLocal);
		}
	}

	if(analytics_metadata_indication->strategy) {
		cJSON *strategy_local_JSON = output_strategy_convertToJSON(
			analytics_metadata_indication->strategy);
		if(strategy_local_JSON == NULL) {
			printf(
				"analytics_metadata_indication_convertToJSON() failed [strategy]");
			goto end;
		}
		cJSON_AddItemToObject(item, "strategy", strategy_local_JSON);
		if(item->child == NULL) {
			printf(
				"analytics_metadata_indication_convertToJSON() failed [strategy]");
			goto end;
		}
	}

	if(analytics_metadata_indication->aggr_nwdaf_ids) {
		cJSON *aggr_nwdaf_idsList = cJSON_AddArrayToObject(item,
		                                                   "aggrNwdafIds");
		if(aggr_nwdaf_idsList == NULL) {
			printf(
				"analytics_metadata_indication_convertToJSON() failed [aggr_nwdaf_ids]");
			goto end;
		}
		list_for_each(analytics_metadata_indication->aggr_nwdaf_ids,
		              node) {
			if(cJSON_AddStringToObject(aggr_nwdaf_idsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"analytics_metadata_indication_convertToJSON() failed [aggr_nwdaf_ids]");
				goto end;
			}
		}
	}

end:
	return item;
}

analytics_metadata_indication_t *analytics_metadata_indication_parseFromJSON(
	cJSON *analytics_metadata_indicationJSON) {
	analytics_metadata_indication_t *analytics_metadata_indication_local_var
	        = NULL;
	lnode_t *node = NULL;
	cJSON *data_window = NULL;
	time_window_t *data_window_local_nonprim = NULL;
	cJSON *data_stat_props = NULL;
	list_t *data_stat_propsList = NULL;
	cJSON *strategy = NULL;
	output_strategy_t *strategy_local_nonprim = NULL;
	cJSON *aggr_nwdaf_ids = NULL;
	list_t *aggr_nwdaf_idsList = NULL;
	data_window = cJSON_GetObjectItemCaseSensitive(
		analytics_metadata_indicationJSON, "dataWindow");
	if(data_window) {
		data_window_local_nonprim = time_window_parseFromJSON(
			data_window);
		if(!data_window_local_nonprim) {
			printf("time_window_parseFromJSON failed [data_window]");
			goto end;
		}
	}

	data_stat_props = cJSON_GetObjectItemCaseSensitive(
		analytics_metadata_indicationJSON, "dataStatProps");
	if(data_stat_props) {
		cJSON *data_stat_props_local = NULL;
		if(!cJSON_IsArray(data_stat_props)) {
			printf(
				"analytics_metadata_indication_parseFromJSON() failed [data_stat_props]");
			goto end;
		}

		data_stat_propsList = list_create();

		cJSON_ArrayForEach(data_stat_props_local, data_stat_props) {
			if(!cJSON_IsObject(data_stat_props_local)) {
				printf(
					"analytics_metadata_indication_parseFromJSON() failed [data_stat_props]");
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

	strategy = cJSON_GetObjectItemCaseSensitive(
		analytics_metadata_indicationJSON, "strategy");
	if(strategy) {
		strategy_local_nonprim =
			output_strategy_parseFromJSON(strategy);
		if(!strategy_local_nonprim) {
			printf("output_strategy_parseFromJSON failed [strategy]");
			goto end;
		}
	}

	aggr_nwdaf_ids = cJSON_GetObjectItemCaseSensitive(
		analytics_metadata_indicationJSON, "aggrNwdafIds");
	if(aggr_nwdaf_ids) {
		cJSON *aggr_nwdaf_ids_local = NULL;
		if(!cJSON_IsArray(aggr_nwdaf_ids)) {
			printf(
				"analytics_metadata_indication_parseFromJSON() failed [aggr_nwdaf_ids]");
			goto end;
		}

		aggr_nwdaf_idsList = list_create();

		cJSON_ArrayForEach(aggr_nwdaf_ids_local, aggr_nwdaf_ids) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(aggr_nwdaf_ids_local)) {
				printf(
					"analytics_metadata_indication_parseFromJSON() failed [aggr_nwdaf_ids]");
				goto end;
			}
			list_add(aggr_nwdaf_idsList,
			         strdup(aggr_nwdaf_ids_local->valuestring));
		}
	}

	analytics_metadata_indication_local_var =
		analytics_metadata_indication_create(
			data_window ? data_window_local_nonprim : NULL,
			data_stat_props ? data_stat_propsList : NULL,
			strategy ? strategy_local_nonprim : NULL,
			aggr_nwdaf_ids ? aggr_nwdaf_idsList : NULL
			);

	return analytics_metadata_indication_local_var;
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
	if(aggr_nwdaf_idsList) {
		list_for_each(aggr_nwdaf_idsList, node) {
			free(node->data);
		}
		list_free(aggr_nwdaf_idsList);
		aggr_nwdaf_idsList = NULL;
	}
	return NULL;
}

analytics_metadata_indication_t *analytics_metadata_indication_copy(
	analytics_metadata_indication_t *dst,
	analytics_metadata_indication_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = analytics_metadata_indication_convertToJSON(src);
	if(!item) {
		printf("analytics_metadata_indication_convertToJSON() failed");
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

	analytics_metadata_indication_free(dst);
	dst = analytics_metadata_indication_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
