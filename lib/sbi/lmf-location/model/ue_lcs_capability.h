/*
 * ue_lcs_capability.h
 *
 * Indicates the LCS capability supported by the UE..
 */

#ifndef _ue_lcs_capability_H_
#define _ue_lcs_capability_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_lcs_capability_s ue_lcs_capability_t;
typedef struct ue_lcs_capability_s {
	bool is_lpp_support;
	int lpp_support;
	bool is_ciot_optimisation;
	int ciot_optimisation;
} ue_lcs_capability_t;

ue_lcs_capability_t *ue_lcs_capability_create(bool	is_lpp_support,
                                              int	lpp_support,
                                              bool	is_ciot_optimisation,
                                              int	ciot_optimisation);
void ue_lcs_capability_free(ue_lcs_capability_t *ue_lcs_capability);
ue_lcs_capability_t *ue_lcs_capability_parseFromJSON(
	cJSON *ue_lcs_capabilityJSON);
cJSON *ue_lcs_capability_convertToJSON(ue_lcs_capability_t *ue_lcs_capability);
ue_lcs_capability_t *ue_lcs_capability_copy(ue_lcs_capability_t *dst,
                                            ue_lcs_capability_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_lcs_capability_H_ */
