/*
 * pc5_flow_bit_rates.h
 *
 * it shall represent the PC5 Flow Bit Rates
 */

#ifndef _pc5_flow_bit_rates_H_
#define _pc5_flow_bit_rates_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pc5_flow_bit_rates_s pc5_flow_bit_rates_t;
typedef struct pc5_flow_bit_rates_s {
	char *gua_fbr;
	char *max_fbr;
} pc5_flow_bit_rates_t;

pc5_flow_bit_rates_t *pc5_flow_bit_rates_create(char *gua_fbr, char *max_fbr);
void pc5_flow_bit_rates_free(pc5_flow_bit_rates_t *pc5_flow_bit_rates);
pc5_flow_bit_rates_t *pc5_flow_bit_rates_parseFromJSON(
	cJSON *pc5_flow_bit_ratesJSON);
cJSON *pc5_flow_bit_rates_convertToJSON(
	pc5_flow_bit_rates_t *pc5_flow_bit_rates);
pc5_flow_bit_rates_t *pc5_flow_bit_rates_copy(pc5_flow_bit_rates_t	*dst,
                                              pc5_flow_bit_rates_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _pc5_flow_bit_rates_H_ */
