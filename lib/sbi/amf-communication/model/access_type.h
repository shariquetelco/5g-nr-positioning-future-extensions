/*
 * access_type.h
 *
 * Indicates whether the access is  via 3GPP or via non-3GPP.
 */

#ifndef _access_type_H_
#define _access_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { access_type_NULL = 0, access_type_3GPP_ACCESS,
	       access_type_NON_3GPP_ACCESS } access_type_e;

char *access_type_ToString(access_type_e access_type);

access_type_e access_type_FromString(char *access_type);

#ifdef __cplusplus
}
#endif

#endif /* _access_type_H_ */
