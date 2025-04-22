#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pc5_qos_flow_item.h"

pc5_qos_flow_item_t *pc5_qos_flow_item_create(int pqi,
                                              pc5_flow_bit_rates_t *pc5_flow_bit_rates, bool is_range,
                                              int range) {
	pc5_qos_flow_item_t *pc5_qos_flow_item_local_var =
		malloc(sizeof(pc5_qos_flow_item_t));

	pc5_qos_flow_item_local_var->pqi = pqi;
	pc5_qos_flow_item_local_var->pc5_flow_bit_rates = pc5_flow_bit_rates;
	pc5_qos_flow_item_local_var->is_range = is_range;
	pc5_qos_flow_item_local_var->range = range;

	return pc5_qos_flow_item_local_var;
}

void pc5_qos_flow_item_free(pc5_qos_flow_item_t *pc5_qos_flow_item) {
	lnode_t *node = NULL;

	if(NULL == pc5_qos_flow_item) {
		return;
	}
	if(pc5_qos_flow_item->pc5_flow_bit_rates) {
		pc5_flow_bit_rates_free(pc5_qos_flow_item->pc5_flow_bit_rates);
		pc5_qos_flow_item->pc5_flow_bit_rates = NULL;
	}
	free(pc5_qos_flow_item);
}

cJSON *pc5_qos_flow_item_convertToJSON(pc5_qos_flow_item_t *pc5_qos_flow_item) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pc5_qos_flow_item == NULL) {
		printf(
			"pc5_qos_flow_item_convertToJSON() failed [Pc5QosFlowItem]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "pqi",
	                           pc5_qos_flow_item->pqi) == NULL)
	{
		printf("pc5_qos_flow_item_convertToJSON() failed [pqi]");
		goto end;
	}

	if(pc5_qos_flow_item->pc5_flow_bit_rates) {
		cJSON *pc5_flow_bit_rates_local_JSON =
			pc5_flow_bit_rates_convertToJSON(
				pc5_qos_flow_item->pc5_flow_bit_rates);
		if(pc5_flow_bit_rates_local_JSON == NULL) {
			printf(
				"pc5_qos_flow_item_convertToJSON() failed [pc5_flow_bit_rates]");
			goto end;
		}
		cJSON_AddItemToObject(item, "pc5FlowBitRates",
		                      pc5_flow_bit_rates_local_JSON);
		if(item->child == NULL) {
			printf(
				"pc5_qos_flow_item_convertToJSON() failed [pc5_flow_bit_rates]");
			goto end;
		}
	}

	if(pc5_qos_flow_item->is_range) {
		if(cJSON_AddNumberToObject(item, "range",
		                           pc5_qos_flow_item->range) == NULL)
		{
			printf(
				"pc5_qos_flow_item_convertToJSON() failed [range]");
			goto end;
		}
	}

end:
	return item;
}

pc5_qos_flow_item_t *pc5_qos_flow_item_parseFromJSON(
	cJSON *pc5_qos_flow_itemJSON) {
	pc5_qos_flow_item_t *pc5_qos_flow_item_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *pqi = NULL;
	cJSON *pc5_flow_bit_rates = NULL;
	pc5_flow_bit_rates_t *pc5_flow_bit_rates_local_nonprim = NULL;
	cJSON *range = NULL;
	pqi = cJSON_GetObjectItemCaseSensitive(pc5_qos_flow_itemJSON, "pqi");
	if(!pqi) {
		printf("pc5_qos_flow_item_parseFromJSON() failed [pqi]");
		goto end;
	}
	if(!cJSON_IsNumber(pqi)) {
		printf("pc5_qos_flow_item_parseFromJSON() failed [pqi]");
		goto end;
	}

	pc5_flow_bit_rates = cJSON_GetObjectItemCaseSensitive(
		pc5_qos_flow_itemJSON, "pc5FlowBitRates");
	if(pc5_flow_bit_rates) {
		pc5_flow_bit_rates_local_nonprim =
			pc5_flow_bit_rates_parseFromJSON(pc5_flow_bit_rates);
		if(!pc5_flow_bit_rates_local_nonprim) {
			printf(
				"pc5_flow_bit_rates_parseFromJSON failed [pc5_flow_bit_rates]");
			goto end;
		}
	}

	range =
		cJSON_GetObjectItemCaseSensitive(pc5_qos_flow_itemJSON,
		                                 "range");
	if(range) {
		if(!cJSON_IsNumber(range)) {
			printf(
				"pc5_qos_flow_item_parseFromJSON() failed [range]");
			goto end;
		}
	}

	pc5_qos_flow_item_local_var = pc5_qos_flow_item_create(

		pqi->valuedouble,
		pc5_flow_bit_rates ? pc5_flow_bit_rates_local_nonprim : NULL,
		range ? true : false,
		range ? range->valuedouble : 0
		);

	return pc5_qos_flow_item_local_var;
end:
	if(pc5_flow_bit_rates_local_nonprim) {
		pc5_flow_bit_rates_free(pc5_flow_bit_rates_local_nonprim);
		pc5_flow_bit_rates_local_nonprim = NULL;
	}
	return NULL;
}

pc5_qos_flow_item_t *pc5_qos_flow_item_copy(pc5_qos_flow_item_t *dst,
                                            pc5_qos_flow_item_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = pc5_qos_flow_item_convertToJSON(src);
	if(!item) {
		printf("pc5_qos_flow_item_convertToJSON() failed");
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

	pc5_qos_flow_item_free(dst);
	dst = pc5_qos_flow_item_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
