/*
 * key_amf_type.h
 *
 *
 */

#ifndef _key_amf_type_H_
#define _key_amf_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { key_amf_type_NULL = 0, key_amf_type_KAMF,
	       key_amf_type_KPRIMEAMF } key_amf_type_e;

char *key_amf_type_ToString(key_amf_type_e key_amf_type);

key_amf_type_e key_amf_type_FromString(char *key_amf_type);

#ifdef __cplusplus
}
#endif

#endif /* _key_amf_type_H_ */
