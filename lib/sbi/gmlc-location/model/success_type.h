/*
 * success_type.h
 *
 *
 */

#ifndef _success_type_H_
#define _success_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { success_type_NULL = 0, success_type_SUCCESS_COMPLETELY,
	       success_type_SUCCESS_PARTIALLY } success_type_e;

char *success_type_ToString(success_type_e success_type);

success_type_e success_type_FromString(char *success_type);

#ifdef __cplusplus
}
#endif

#endif /* _success_type_H_ */
