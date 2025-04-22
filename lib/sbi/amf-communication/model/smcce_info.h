/*
 * smcce_info.h
 *
 * Represents the Session Management congestion control experience information.
 */

#ifndef _smcce_info_H_
#define _smcce_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "smcce_ue_list.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct smcce_info_s smcce_info_t;
typedef struct smcce_info_s {
	char *dnn;
	struct snssai_s *snssai;
	struct smcce_ue_list_s *smcce_ue_list;
} smcce_info_t;

smcce_info_t *smcce_info_create(char *dnn, snssai_t *snssai,
                                smcce_ue_list_t *smcce_ue_list);
void smcce_info_free(smcce_info_t *smcce_info);
smcce_info_t *smcce_info_parseFromJSON(cJSON *smcce_infoJSON);
cJSON *smcce_info_convertToJSON(smcce_info_t *smcce_info);
smcce_info_t *smcce_info_copy(smcce_info_t *dst, smcce_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _smcce_info_H_ */
