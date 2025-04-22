/*
 * ue_context_transfer_status.h
 *
 *
 */

#ifndef _ue_context_transfer_status_H_
#define _ue_context_transfer_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ue_context_transfer_status_NULL = 0,
	       ue_context_transfer_status_TRANSFERRED,
	       ue_context_transfer_status_NOT_TRANSFERRED }
ue_context_transfer_status_e;

char *ue_context_transfer_status_ToString(
	ue_context_transfer_status_e ue_context_transfer_status);

ue_context_transfer_status_e ue_context_transfer_status_FromString(
	char *ue_context_transfer_status);

#ifdef __cplusplus
}
#endif

#endif /* _ue_context_transfer_status_H_ */
