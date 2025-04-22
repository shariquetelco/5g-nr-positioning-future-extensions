/*
 * smcce_ue_list.h
 *
 * Represents the List of UEs classified based on experience level of Session Management congestion control.
 */

#ifndef _smcce_ue_list_H_
#define _smcce_ue_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct smcce_ue_list_s smcce_ue_list_t;
typedef struct smcce_ue_list_s {
	list_t *high_level;
	list_t *medium_level;
	list_t *low_level;
} smcce_ue_list_t;

smcce_ue_list_t *smcce_ue_list_create(list_t *high_level, list_t *medium_level,
                                      list_t *low_level);
void smcce_ue_list_free(smcce_ue_list_t *smcce_ue_list);
smcce_ue_list_t *smcce_ue_list_parseFromJSON(cJSON *smcce_ue_listJSON);
cJSON *smcce_ue_list_convertToJSON(smcce_ue_list_t *smcce_ue_list);
smcce_ue_list_t *smcce_ue_list_copy(smcce_ue_list_t *dst, smcce_ue_list_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _smcce_ue_list_H_ */
