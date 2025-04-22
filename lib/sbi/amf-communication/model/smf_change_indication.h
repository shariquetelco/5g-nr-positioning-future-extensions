/*
 * smf_change_indication.h
 *
 *
 */

#ifndef _smf_change_indication_H_
#define _smf_change_indication_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { smf_change_indication_NULL = 0, smf_change_indication_CHANGED,
	       smf_change_indication_REMOVED } smf_change_indication_e;

char *smf_change_indication_ToString(
	smf_change_indication_e smf_change_indication);

smf_change_indication_e smf_change_indication_FromString(
	char *smf_change_indication);

#ifdef __cplusplus
}
#endif

#endif /* _smf_change_indication_H_ */
