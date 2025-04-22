/*
 * pc5_qos_flow_item.h
 *
 * Contains a PC5 QOS flow.
 */

#ifndef _pc5_qos_flow_item_H_
#define _pc5_qos_flow_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "pc5_flow_bit_rates.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pc5_qos_flow_item_s pc5_qos_flow_item_t;
typedef struct pc5_qos_flow_item_s {
	int pqi;
	struct pc5_flow_bit_rates_s *pc5_flow_bit_rates;
	bool is_range;
	int range;
} pc5_qos_flow_item_t;

pc5_qos_flow_item_t *pc5_qos_flow_item_create(int pqi,
                                              pc5_flow_bit_rates_t *pc5_flow_bit_rates, bool is_range, int range);
void pc5_qos_flow_item_free(pc5_qos_flow_item_t *pc5_qos_flow_item);
pc5_qos_flow_item_t *pc5_qos_flow_item_parseFromJSON(
	cJSON *pc5_qos_flow_itemJSON);
cJSON *pc5_qos_flow_item_convertToJSON(pc5_qos_flow_item_t *pc5_qos_flow_item);
pc5_qos_flow_item_t *pc5_qos_flow_item_copy(pc5_qos_flow_item_t *dst,
                                            pc5_qos_flow_item_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _pc5_qos_flow_item_H_ */
