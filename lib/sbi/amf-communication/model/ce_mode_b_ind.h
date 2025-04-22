/*
 * ce_mode_b_ind.h
 *
 * CE-mode-B Support Indicator.
 */

#ifndef _ce_mode_b_ind_H_
#define _ce_mode_b_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ce_mode_b_ind_s ce_mode_b_ind_t;
typedef struct ce_mode_b_ind_s {
	int ce_mode_b_support_ind;
} ce_mode_b_ind_t;

ce_mode_b_ind_t *ce_mode_b_ind_create(int ce_mode_b_support_ind);
void ce_mode_b_ind_free(ce_mode_b_ind_t *ce_mode_b_ind);
ce_mode_b_ind_t *ce_mode_b_ind_parseFromJSON(cJSON *ce_mode_b_indJSON);
cJSON *ce_mode_b_ind_convertToJSON(ce_mode_b_ind_t *ce_mode_b_ind);
ce_mode_b_ind_t *ce_mode_b_ind_copy(ce_mode_b_ind_t *dst, ce_mode_b_ind_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ce_mode_b_ind_H_ */
