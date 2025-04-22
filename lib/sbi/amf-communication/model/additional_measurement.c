#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "additional_measurement.h"

additional_measurement_t *additional_measurement_create(
	network_area_info_t *unexp_loc, list_t *unexp_flow_teps,
	list_t *unexp_wakes, address_list_t *ddos_attack,
	address_list_t *wrg_dest, list_t *circums) {
	additional_measurement_t *additional_measurement_local_var = malloc(
		sizeof(additional_measurement_t));

	additional_measurement_local_var->unexp_loc = unexp_loc;
	additional_measurement_local_var->unexp_flow_teps = unexp_flow_teps;
	additional_measurement_local_var->unexp_wakes = unexp_wakes;
	additional_measurement_local_var->ddos_attack = ddos_attack;
	additional_measurement_local_var->wrg_dest = wrg_dest;
	additional_measurement_local_var->circums = circums;

	return additional_measurement_local_var;
}

void additional_measurement_free(
	additional_measurement_t *additional_measurement) {
	lnode_t *node = NULL;

	if(NULL == additional_measurement) {
		return;
	}
	if(additional_measurement->unexp_loc) {
		network_area_info_free(additional_measurement->unexp_loc);
		additional_measurement->unexp_loc = NULL;
	}
	if(additional_measurement->unexp_flow_teps) {
		list_for_each(additional_measurement->unexp_flow_teps, node) {
			ip_eth_flow_description_free(node->data);
		}
		list_free(additional_measurement->unexp_flow_teps);
		additional_measurement->unexp_flow_teps = NULL;
	}
	if(additional_measurement->unexp_wakes) {
		list_for_each(additional_measurement->unexp_wakes, node) {
			free(node->data);
		}
		list_free(additional_measurement->unexp_wakes);
		additional_measurement->unexp_wakes = NULL;
	}
	if(additional_measurement->ddos_attack) {
		address_list_free(additional_measurement->ddos_attack);
		additional_measurement->ddos_attack = NULL;
	}
	if(additional_measurement->wrg_dest) {
		address_list_free(additional_measurement->wrg_dest);
		additional_measurement->wrg_dest = NULL;
	}
	if(additional_measurement->circums) {
		list_for_each(additional_measurement->circums, node) {
			circumstance_description_free(node->data);
		}
		list_free(additional_measurement->circums);
		additional_measurement->circums = NULL;
	}
	free(additional_measurement);
}

cJSON *additional_measurement_convertToJSON(
	additional_measurement_t *additional_measurement) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(additional_measurement == NULL) {
		printf(
			"additional_measurement_convertToJSON() failed [AdditionalMeasurement]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(additional_measurement->unexp_loc) {
		cJSON *unexp_loc_local_JSON = network_area_info_convertToJSON(
			additional_measurement->unexp_loc);
		if(unexp_loc_local_JSON == NULL) {
			printf(
				"additional_measurement_convertToJSON() failed [unexp_loc]");
			goto end;
		}
		cJSON_AddItemToObject(item, "unexpLoc", unexp_loc_local_JSON);
		if(item->child == NULL) {
			printf(
				"additional_measurement_convertToJSON() failed [unexp_loc]");
			goto end;
		}
	}

	if(additional_measurement->unexp_flow_teps) {
		cJSON *unexp_flow_tepsList = cJSON_AddArrayToObject(item,
		                                                    "unexpFlowTeps");
		if(unexp_flow_tepsList == NULL) {
			printf(
				"additional_measurement_convertToJSON() failed [unexp_flow_teps]");
			goto end;
		}
		list_for_each(additional_measurement->unexp_flow_teps, node) {
			cJSON *itemLocal =
				ip_eth_flow_description_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"additional_measurement_convertToJSON() failed [unexp_flow_teps]");
				goto end;
			}
			cJSON_AddItemToArray(unexp_flow_tepsList, itemLocal);
		}
	}

	if(additional_measurement->unexp_wakes) {
		cJSON *unexp_wakesList = cJSON_AddArrayToObject(item,
		                                                "unexpWakes");
		if(unexp_wakesList == NULL) {
			printf(
				"additional_measurement_convertToJSON() failed [unexp_wakes]");
			goto end;
		}
		list_for_each(additional_measurement->unexp_wakes, node) {}
	}

	if(additional_measurement->ddos_attack) {
		cJSON *ddos_attack_local_JSON = address_list_convertToJSON(
			additional_measurement->ddos_attack);
		if(ddos_attack_local_JSON == NULL) {
			printf(
				"additional_measurement_convertToJSON() failed [ddos_attack]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ddosAttack",
		                      ddos_attack_local_JSON);
		if(item->child == NULL) {
			printf(
				"additional_measurement_convertToJSON() failed [ddos_attack]");
			goto end;
		}
	}

	if(additional_measurement->wrg_dest) {
		cJSON *wrg_dest_local_JSON = address_list_convertToJSON(
			additional_measurement->wrg_dest);
		if(wrg_dest_local_JSON == NULL) {
			printf(
				"additional_measurement_convertToJSON() failed [wrg_dest]");
			goto end;
		}
		cJSON_AddItemToObject(item, "wrgDest", wrg_dest_local_JSON);
		if(item->child == NULL) {
			printf(
				"additional_measurement_convertToJSON() failed [wrg_dest]");
			goto end;
		}
	}

	if(additional_measurement->circums) {
		cJSON *circumsList = cJSON_AddArrayToObject(item, "circums");
		if(circumsList == NULL) {
			printf(
				"additional_measurement_convertToJSON() failed [circums]");
			goto end;
		}
		list_for_each(additional_measurement->circums, node) {
			cJSON *itemLocal =
				circumstance_description_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"additional_measurement_convertToJSON() failed [circums]");
				goto end;
			}
			cJSON_AddItemToArray(circumsList, itemLocal);
		}
	}

end:
	return item;
}

additional_measurement_t *additional_measurement_parseFromJSON(
	cJSON *additional_measurementJSON) {
	additional_measurement_t *additional_measurement_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *unexp_loc = NULL;
	network_area_info_t *unexp_loc_local_nonprim = NULL;
	cJSON *unexp_flow_teps = NULL;
	list_t *unexp_flow_tepsList = NULL;
	cJSON *unexp_wakes = NULL;
	list_t *unexp_wakesList = NULL;
	cJSON *ddos_attack = NULL;
	address_list_t *ddos_attack_local_nonprim = NULL;
	cJSON *wrg_dest = NULL;
	address_list_t *wrg_dest_local_nonprim = NULL;
	cJSON *circums = NULL;
	list_t *circumsList = NULL;
	unexp_loc = cJSON_GetObjectItemCaseSensitive(additional_measurementJSON,
	                                             "unexpLoc");
	if(unexp_loc) {
		unexp_loc_local_nonprim = network_area_info_parseFromJSON(
			unexp_loc);
		if(!unexp_loc_local_nonprim) {
			printf(
				"network_area_info_parseFromJSON failed [unexp_loc]");
			goto end;
		}
	}

	unexp_flow_teps = cJSON_GetObjectItemCaseSensitive(
		additional_measurementJSON, "unexpFlowTeps");
	if(unexp_flow_teps) {
		cJSON *unexp_flow_teps_local = NULL;
		if(!cJSON_IsArray(unexp_flow_teps)) {
			printf(
				"additional_measurement_parseFromJSON() failed [unexp_flow_teps]");
			goto end;
		}

		unexp_flow_tepsList = list_create();

		cJSON_ArrayForEach(unexp_flow_teps_local, unexp_flow_teps) {
			if(!cJSON_IsObject(unexp_flow_teps_local)) {
				printf(
					"additional_measurement_parseFromJSON() failed [unexp_flow_teps]");
				goto end;
			}
			ip_eth_flow_description_t *unexp_flow_tepsItem =
				ip_eth_flow_description_parseFromJSON(
					unexp_flow_teps_local);
			if(!unexp_flow_tepsItem) {
				printf("No unexp_flow_tepsItem");
				goto end;
			}
			list_add(unexp_flow_tepsList, unexp_flow_tepsItem);
		}
	}

	unexp_wakes = cJSON_GetObjectItemCaseSensitive(
		additional_measurementJSON, "unexpWakes");
	if(unexp_wakes) {
		cJSON *unexp_wakes_local = NULL;
		if(!cJSON_IsArray(unexp_wakes)) {
			printf(
				"additional_measurement_parseFromJSON() failed [unexp_wakes]");
			goto end;
		}

		unexp_wakesList = list_create();

		cJSON_ArrayForEach(unexp_wakes_local, unexp_wakes) {
			double *localDouble = NULL;
			int *localInt = NULL;
		}
	}

	ddos_attack = cJSON_GetObjectItemCaseSensitive(
		additional_measurementJSON, "ddosAttack");
	if(ddos_attack) {
		ddos_attack_local_nonprim = address_list_parseFromJSON(
			ddos_attack);
		if(!ddos_attack_local_nonprim) {
			printf("address_list_parseFromJSON failed [ddos_attack]");
			goto end;
		}
	}

	wrg_dest = cJSON_GetObjectItemCaseSensitive(additional_measurementJSON,
	                                            "wrgDest");
	if(wrg_dest) {
		wrg_dest_local_nonprim = address_list_parseFromJSON(wrg_dest);
		if(!wrg_dest_local_nonprim) {
			printf("address_list_parseFromJSON failed [wrg_dest]");
			goto end;
		}
	}

	circums = cJSON_GetObjectItemCaseSensitive(additional_measurementJSON,
	                                           "circums");
	if(circums) {
		cJSON *circums_local = NULL;
		if(!cJSON_IsArray(circums)) {
			printf(
				"additional_measurement_parseFromJSON() failed [circums]");
			goto end;
		}

		circumsList = list_create();

		cJSON_ArrayForEach(circums_local, circums) {
			if(!cJSON_IsObject(circums_local)) {
				printf(
					"additional_measurement_parseFromJSON() failed [circums]");
				goto end;
			}
			circumstance_description_t *circumsItem =
				circumstance_description_parseFromJSON(
					circums_local);
			if(!circumsItem) {
				printf("No circumsItem");
				goto end;
			}
			list_add(circumsList, circumsItem);
		}
	}

	additional_measurement_local_var = additional_measurement_create(
		unexp_loc ? unexp_loc_local_nonprim : NULL,
		unexp_flow_teps ? unexp_flow_tepsList : NULL,
		unexp_wakes ? unexp_wakesList : NULL,
		ddos_attack ? ddos_attack_local_nonprim : NULL,
		wrg_dest ? wrg_dest_local_nonprim : NULL,
		circums ? circumsList : NULL
		);

	return additional_measurement_local_var;
end:
	if(unexp_loc_local_nonprim) {
		network_area_info_free(unexp_loc_local_nonprim);
		unexp_loc_local_nonprim = NULL;
	}
	if(unexp_flow_tepsList) {
		list_for_each(unexp_flow_tepsList, node) {
			ip_eth_flow_description_free(node->data);
		}
		list_free(unexp_flow_tepsList);
		unexp_flow_tepsList = NULL;
	}
	if(unexp_wakesList) {
		list_for_each(unexp_wakesList, node) {
			free(node->data);
		}
		list_free(unexp_wakesList);
		unexp_wakesList = NULL;
	}
	if(ddos_attack_local_nonprim) {
		address_list_free(ddos_attack_local_nonprim);
		ddos_attack_local_nonprim = NULL;
	}
	if(wrg_dest_local_nonprim) {
		address_list_free(wrg_dest_local_nonprim);
		wrg_dest_local_nonprim = NULL;
	}
	if(circumsList) {
		list_for_each(circumsList, node) {
			circumstance_description_free(node->data);
		}
		list_free(circumsList);
		circumsList = NULL;
	}
	return NULL;
}

additional_measurement_t *additional_measurement_copy(
	additional_measurement_t *dst, additional_measurement_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = additional_measurement_convertToJSON(src);
	if(!item) {
		printf("additional_measurement_convertToJSON() failed");
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

	additional_measurement_free(dst);
	dst = additional_measurement_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
