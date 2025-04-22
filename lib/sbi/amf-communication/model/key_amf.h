/*
 * key_amf.h
 *
 * Represents the Kamf or K&#39;amf
 */

#ifndef _key_amf_H_
#define _key_amf_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "key_amf_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct key_amf_s key_amf_t;
typedef struct key_amf_s {
	key_amf_type_e key_type;
	char *key_val;
} key_amf_t;

key_amf_t *key_amf_create(key_amf_type_e key_type, char *key_val);
void key_amf_free(key_amf_t *key_amf);
key_amf_t *key_amf_parseFromJSON(cJSON *key_amfJSON);
cJSON *key_amf_convertToJSON(key_amf_t *key_amf);
key_amf_t *key_amf_copy(key_amf_t *dst, key_amf_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _key_amf_H_ */
