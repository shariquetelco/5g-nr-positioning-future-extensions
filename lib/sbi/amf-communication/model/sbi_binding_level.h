/*
 * sbi_binding_level.h
 *
 *
 */

#ifndef _sbi_binding_level_H_
#define _sbi_binding_level_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { sbi_binding_level_NULL = 0,
	       sbi_binding_level_NF_INSTANCE_BINDING,
	       sbi_binding_level_NF_SET_BINDING,
	       sbi_binding_level_NF_SERVICE_SET_BINDING,
	       sbi_binding_level_NF_SERVICE_INSTANCE_BINDING }
sbi_binding_level_e;

char *sbi_binding_level_ToString(sbi_binding_level_e sbi_binding_level);

sbi_binding_level_e sbi_binding_level_FromString(char *sbi_binding_level);

#ifdef __cplusplus
}
#endif

#endif /* _sbi_binding_level_H_ */
