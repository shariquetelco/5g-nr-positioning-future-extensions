/*
 * smf_change_info.h
 *
 * SMF change information for PDU session(s)
 */

#ifndef _smf_change_info_H_
#define _smf_change_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "smf_change_indication.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct smf_change_info_s smf_change_info_t;
typedef struct smf_change_info_s {
	list_t *pdu_session_id_list;
	smf_change_indication_e smf_change_ind;
} smf_change_info_t;

smf_change_info_t *smf_change_info_create(
	list_t			*pdu_session_id_list,
	smf_change_indication_e smf_change_ind);
void smf_change_info_free(smf_change_info_t *smf_change_info);
smf_change_info_t *smf_change_info_parseFromJSON(cJSON *smf_change_infoJSON);
cJSON *smf_change_info_convertToJSON(smf_change_info_t *smf_change_info);
smf_change_info_t *smf_change_info_copy(smf_change_info_t	*dst,
                                        smf_change_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _smf_change_info_H_ */
