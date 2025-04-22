#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dispersion_collection.h"

dispersion_collection_t *dispersion_collection_create(user_location_t *ue_loc,
                                                      snssai_t *snssai,
                                                      list_t *supis,
                                                      list_t *gpsis,
                                                      list_t *app_volumes,
                                                      bool is_disper_amount,
                                                      int disper_amount,
                                                      dispersion_class_t *disper_class, bool is_usage_rank, int usage_rank, bool is_percentile_rank, int percentile_rank, bool is_ue_ratio, int ue_ratio, bool is_confidence,
                                                      int confidence) {
	dispersion_collection_t *dispersion_collection_local_var = malloc(
		sizeof(dispersion_collection_t));

	dispersion_collection_local_var->ue_loc = ue_loc;
	dispersion_collection_local_var->snssai = snssai;
	dispersion_collection_local_var->supis = supis;
	dispersion_collection_local_var->gpsis = gpsis;
	dispersion_collection_local_var->app_volumes = app_volumes;
	dispersion_collection_local_var->is_disper_amount = is_disper_amount;
	dispersion_collection_local_var->disper_amount = disper_amount;
	dispersion_collection_local_var->disper_class = disper_class;
	dispersion_collection_local_var->is_usage_rank = is_usage_rank;
	dispersion_collection_local_var->usage_rank = usage_rank;
	dispersion_collection_local_var->is_percentile_rank =
		is_percentile_rank;
	dispersion_collection_local_var->percentile_rank = percentile_rank;
	dispersion_collection_local_var->is_ue_ratio = is_ue_ratio;
	dispersion_collection_local_var->ue_ratio = ue_ratio;
	dispersion_collection_local_var->is_confidence = is_confidence;
	dispersion_collection_local_var->confidence = confidence;

	return dispersion_collection_local_var;
}

void dispersion_collection_free(dispersion_collection_t *dispersion_collection)
{
	lnode_t *node = NULL;

	if(NULL == dispersion_collection) {
		return;
	}
	if(dispersion_collection->ue_loc) {
		user_location_free(dispersion_collection->ue_loc);
		dispersion_collection->ue_loc = NULL;
	}
	if(dispersion_collection->snssai) {
		snssai_free(dispersion_collection->snssai);
		dispersion_collection->snssai = NULL;
	}
	if(dispersion_collection->supis) {
		list_for_each(dispersion_collection->supis, node) {
			free(node->data);
		}
		list_free(dispersion_collection->supis);
		dispersion_collection->supis = NULL;
	}
	if(dispersion_collection->gpsis) {
		list_for_each(dispersion_collection->gpsis, node) {
			free(node->data);
		}
		list_free(dispersion_collection->gpsis);
		dispersion_collection->gpsis = NULL;
	}
	if(dispersion_collection->app_volumes) {
		list_for_each(dispersion_collection->app_volumes, node) {
			application_volume_free(node->data);
		}
		list_free(dispersion_collection->app_volumes);
		dispersion_collection->app_volumes = NULL;
	}
	if(dispersion_collection->disper_class) {
		dispersion_class_free(dispersion_collection->disper_class);
		dispersion_collection->disper_class = NULL;
	}
	free(dispersion_collection);
}

cJSON *dispersion_collection_convertToJSON(
	dispersion_collection_t *dispersion_collection) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(dispersion_collection == NULL) {
		printf(
			"dispersion_collection_convertToJSON() failed [DispersionCollection]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(dispersion_collection->ue_loc) {
		cJSON *ue_loc_local_JSON = user_location_convertToJSON(
			dispersion_collection->ue_loc);
		if(ue_loc_local_JSON == NULL) {
			printf(
				"dispersion_collection_convertToJSON() failed [ue_loc]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueLoc", ue_loc_local_JSON);
		if(item->child == NULL) {
			printf(
				"dispersion_collection_convertToJSON() failed [ue_loc]");
			goto end;
		}
	}

	if(dispersion_collection->snssai) {
		cJSON *snssai_local_JSON = snssai_convertToJSON(
			dispersion_collection->snssai);
		if(snssai_local_JSON == NULL) {
			printf(
				"dispersion_collection_convertToJSON() failed [snssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"dispersion_collection_convertToJSON() failed [snssai]");
			goto end;
		}
	}

	if(dispersion_collection->supis) {
		cJSON *supisList = cJSON_AddArrayToObject(item, "supis");
		if(supisList == NULL) {
			printf(
				"dispersion_collection_convertToJSON() failed [supis]");
			goto end;
		}
		list_for_each(dispersion_collection->supis, node) {
			if(cJSON_AddStringToObject(supisList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"dispersion_collection_convertToJSON() failed [supis]");
				goto end;
			}
		}
	}

	if(dispersion_collection->gpsis) {
		cJSON *gpsisList = cJSON_AddArrayToObject(item, "gpsis");
		if(gpsisList == NULL) {
			printf(
				"dispersion_collection_convertToJSON() failed [gpsis]");
			goto end;
		}
		list_for_each(dispersion_collection->gpsis, node) {
			if(cJSON_AddStringToObject(gpsisList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"dispersion_collection_convertToJSON() failed [gpsis]");
				goto end;
			}
		}
	}

	if(dispersion_collection->app_volumes) {
		cJSON *app_volumesList = cJSON_AddArrayToObject(item,
		                                                "appVolumes");
		if(app_volumesList == NULL) {
			printf(
				"dispersion_collection_convertToJSON() failed [app_volumes]");
			goto end;
		}
		list_for_each(dispersion_collection->app_volumes, node) {
			cJSON *itemLocal = application_volume_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"dispersion_collection_convertToJSON() failed [app_volumes]");
				goto end;
			}
			cJSON_AddItemToArray(app_volumesList, itemLocal);
		}
	}

	if(dispersion_collection->is_disper_amount) {
		if(cJSON_AddNumberToObject(item, "disperAmount",
		                           dispersion_collection->disper_amount)
		   == NULL)
		{
			printf(
				"dispersion_collection_convertToJSON() failed [disper_amount]");
			goto end;
		}
	}

	if(dispersion_collection->disper_class) {
		cJSON *disper_class_local_JSON = dispersion_class_convertToJSON(
			dispersion_collection->disper_class);
		if(disper_class_local_JSON == NULL) {
			printf(
				"dispersion_collection_convertToJSON() failed [disper_class]");
			goto end;
		}
		cJSON_AddItemToObject(item, "disperClass",
		                      disper_class_local_JSON);
		if(item->child == NULL) {
			printf(
				"dispersion_collection_convertToJSON() failed [disper_class]");
			goto end;
		}
	}

	if(dispersion_collection->is_usage_rank) {
		if(cJSON_AddNumberToObject(item, "usageRank",
		                           dispersion_collection->usage_rank) ==
		   NULL)
		{
			printf(
				"dispersion_collection_convertToJSON() failed [usage_rank]");
			goto end;
		}
	}

	if(dispersion_collection->is_percentile_rank) {
		if(cJSON_AddNumberToObject(item, "percentileRank",
		                           dispersion_collection->
		                           percentile_rank) == NULL)
		{
			printf(
				"dispersion_collection_convertToJSON() failed [percentile_rank]");
			goto end;
		}
	}

	if(dispersion_collection->is_ue_ratio) {
		if(cJSON_AddNumberToObject(item, "ueRatio",
		                           dispersion_collection->ue_ratio) ==
		   NULL)
		{
			printf(
				"dispersion_collection_convertToJSON() failed [ue_ratio]");
			goto end;
		}
	}

	if(dispersion_collection->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           dispersion_collection->confidence) ==
		   NULL)
		{
			printf(
				"dispersion_collection_convertToJSON() failed [confidence]");
			goto end;
		}
	}

end:
	return item;
}

dispersion_collection_t *dispersion_collection_parseFromJSON(
	cJSON *dispersion_collectionJSON) {
	dispersion_collection_t *dispersion_collection_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ue_loc = NULL;
	user_location_t *ue_loc_local_nonprim = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *supis = NULL;
	list_t *supisList = NULL;
	cJSON *gpsis = NULL;
	list_t *gpsisList = NULL;
	cJSON *app_volumes = NULL;
	list_t *app_volumesList = NULL;
	cJSON *disper_amount = NULL;
	cJSON *disper_class = NULL;
	dispersion_class_t *disper_class_local_nonprim = NULL;
	cJSON *usage_rank = NULL;
	cJSON *percentile_rank = NULL;
	cJSON *ue_ratio = NULL;
	cJSON *confidence = NULL;
	ue_loc = cJSON_GetObjectItemCaseSensitive(dispersion_collectionJSON,
	                                          "ueLoc");
	if(ue_loc) {
		ue_loc_local_nonprim = user_location_parseFromJSON(ue_loc);
		if(!ue_loc_local_nonprim) {
			printf("user_location_parseFromJSON failed [ue_loc]");
			goto end;
		}
	}

	snssai = cJSON_GetObjectItemCaseSensitive(dispersion_collectionJSON,
	                                          "snssai");
	if(snssai) {
		snssai_local_nonprim = snssai_parseFromJSON(snssai);
		if(!snssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [snssai]");
			goto end;
		}
	}

	supis = cJSON_GetObjectItemCaseSensitive(dispersion_collectionJSON,
	                                         "supis");
	if(supis) {
		cJSON *supis_local = NULL;
		if(!cJSON_IsArray(supis)) {
			printf(
				"dispersion_collection_parseFromJSON() failed [supis]");
			goto end;
		}

		supisList = list_create();

		cJSON_ArrayForEach(supis_local, supis) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(supis_local)) {
				printf(
					"dispersion_collection_parseFromJSON() failed [supis]");
				goto end;
			}
			list_add(supisList, strdup(supis_local->valuestring));
		}
	}

	gpsis = cJSON_GetObjectItemCaseSensitive(dispersion_collectionJSON,
	                                         "gpsis");
	if(gpsis) {
		cJSON *gpsis_local = NULL;
		if(!cJSON_IsArray(gpsis)) {
			printf(
				"dispersion_collection_parseFromJSON() failed [gpsis]");
			goto end;
		}

		gpsisList = list_create();

		cJSON_ArrayForEach(gpsis_local, gpsis) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(gpsis_local)) {
				printf(
					"dispersion_collection_parseFromJSON() failed [gpsis]");
				goto end;
			}
			list_add(gpsisList, strdup(gpsis_local->valuestring));
		}
	}

	app_volumes = cJSON_GetObjectItemCaseSensitive(
		dispersion_collectionJSON, "appVolumes");
	if(app_volumes) {
		cJSON *app_volumes_local = NULL;
		if(!cJSON_IsArray(app_volumes)) {
			printf(
				"dispersion_collection_parseFromJSON() failed [app_volumes]");
			goto end;
		}

		app_volumesList = list_create();

		cJSON_ArrayForEach(app_volumes_local, app_volumes) {
			if(!cJSON_IsObject(app_volumes_local)) {
				printf(
					"dispersion_collection_parseFromJSON() failed [app_volumes]");
				goto end;
			}
			application_volume_t *app_volumesItem =
				application_volume_parseFromJSON(
					app_volumes_local);
			if(!app_volumesItem) {
				printf("No app_volumesItem");
				goto end;
			}
			list_add(app_volumesList, app_volumesItem);
		}
	}

	disper_amount = cJSON_GetObjectItemCaseSensitive(
		dispersion_collectionJSON, "disperAmount");
	if(disper_amount) {
		if(!cJSON_IsNumber(disper_amount)) {
			printf(
				"dispersion_collection_parseFromJSON() failed [disper_amount]");
			goto end;
		}
	}

	disper_class = cJSON_GetObjectItemCaseSensitive(
		dispersion_collectionJSON, "disperClass");
	if(disper_class) {
		disper_class_local_nonprim = dispersion_class_parseFromJSON(
			disper_class);
		if(!disper_class_local_nonprim) {
			printf(
				"dispersion_class_parseFromJSON failed [disper_class]");
			goto end;
		}
	}

	usage_rank = cJSON_GetObjectItemCaseSensitive(dispersion_collectionJSON,
	                                              "usageRank");
	if(usage_rank) {
		if(!cJSON_IsNumber(usage_rank)) {
			printf(
				"dispersion_collection_parseFromJSON() failed [usage_rank]");
			goto end;
		}
	}

	percentile_rank = cJSON_GetObjectItemCaseSensitive(
		dispersion_collectionJSON, "percentileRank");
	if(percentile_rank) {
		if(!cJSON_IsNumber(percentile_rank)) {
			printf(
				"dispersion_collection_parseFromJSON() failed [percentile_rank]");
			goto end;
		}
	}

	ue_ratio = cJSON_GetObjectItemCaseSensitive(dispersion_collectionJSON,
	                                            "ueRatio");
	if(ue_ratio) {
		if(!cJSON_IsNumber(ue_ratio)) {
			printf(
				"dispersion_collection_parseFromJSON() failed [ue_ratio]");
			goto end;
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(dispersion_collectionJSON,
	                                              "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"dispersion_collection_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	dispersion_collection_local_var = dispersion_collection_create(
		ue_loc ? ue_loc_local_nonprim : NULL,
		snssai ? snssai_local_nonprim : NULL,
		supis ? supisList : NULL,
		gpsis ? gpsisList : NULL,
		app_volumes ? app_volumesList : NULL,
		disper_amount ? true : false,
		disper_amount ? disper_amount->valuedouble : 0,
		disper_class ? disper_class_local_nonprim : NULL,
		usage_rank ? true : false,
		usage_rank ? usage_rank->valuedouble : 0,
		percentile_rank ? true : false,
		percentile_rank ? percentile_rank->valuedouble : 0,
		ue_ratio ? true : false,
		ue_ratio ? ue_ratio->valuedouble : 0,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0
		);

	return dispersion_collection_local_var;
end:
	if(ue_loc_local_nonprim) {
		user_location_free(ue_loc_local_nonprim);
		ue_loc_local_nonprim = NULL;
	}
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(supisList) {
		list_for_each(supisList, node) {
			free(node->data);
		}
		list_free(supisList);
		supisList = NULL;
	}
	if(gpsisList) {
		list_for_each(gpsisList, node) {
			free(node->data);
		}
		list_free(gpsisList);
		gpsisList = NULL;
	}
	if(app_volumesList) {
		list_for_each(app_volumesList, node) {
			application_volume_free(node->data);
		}
		list_free(app_volumesList);
		app_volumesList = NULL;
	}
	if(disper_class_local_nonprim) {
		dispersion_class_free(disper_class_local_nonprim);
		disper_class_local_nonprim = NULL;
	}
	return NULL;
}

dispersion_collection_t *dispersion_collection_copy(
	dispersion_collection_t *dst, dispersion_collection_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = dispersion_collection_convertToJSON(src);
	if(!item) {
		printf("dispersion_collection_convertToJSON() failed");
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

	dispersion_collection_free(dst);
	dst = dispersion_collection_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
