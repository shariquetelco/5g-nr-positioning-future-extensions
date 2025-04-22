/*
 * restriction_type_any_of.h
 *
 *
 */

#ifndef _restriction_type_any_of_H_
#define _restriction_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { restriction_type_any_of_NULL = 0,
	       restriction_type_any_of_ALLOWED_AREAS,
	       restriction_type_any_of_NOT_ALLOWED_AREAS }
restriction_type_any_of_e;

char *restriction_type_any_of_ToString(
	restriction_type_any_of_e restriction_type_any_of);

restriction_type_any_of_e restriction_type_any_of_FromString(
	char *restriction_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _restriction_type_any_of_H_ */
