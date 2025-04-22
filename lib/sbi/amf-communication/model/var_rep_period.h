/*
 * var_rep_period.h
 *
 * Indicates the Variable reporting periodicity for event reporting
 */

#ifndef _var_rep_period_H_
#define _var_rep_period_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct var_rep_period_s var_rep_period_t;
typedef struct var_rep_period_s {
	int rep_period;
	uint8_t perc_value_nf_load;
} var_rep_period_t;

var_rep_period_t *var_rep_period_create(int rep_period, uint8_t perc_value_nf_load);
void var_rep_period_free(var_rep_period_t *var_rep_period);
var_rep_period_t *var_rep_period_parseFromJSON(cJSON *var_rep_periodJSON);
cJSON *var_rep_period_convertToJSON(var_rep_period_t *var_rep_period);
var_rep_period_t *var_rep_period_copy(var_rep_period_t	*dst,
                                      var_rep_period_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _var_rep_period_H_ */
