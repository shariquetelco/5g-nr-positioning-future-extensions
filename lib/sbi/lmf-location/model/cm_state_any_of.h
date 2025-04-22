/*
 * cm_state_any_of.h
 *
 *
 */

#ifndef _cm_state_any_of_H_
#define _cm_state_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { cm_state_any_of_NULL = 0, cm_state_any_of_IDLE,
	       cm_state_any_of_CONNECTED } cm_state_any_of_e;

char *cm_state_any_of_ToString(cm_state_any_of_e cm_state_any_of);

cm_state_any_of_e cm_state_any_of_FromString(char *cm_state_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _cm_state_any_of_H_ */
