/*
 * core_network_type.h
 *
 * It contains the Core Network type 5GC or EPC.
 */

#ifndef _core_network_type_H_
#define _core_network_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "core_network_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct core_network_type_s core_network_type_t;
typedef struct core_network_type_s {} core_network_type_t;

core_network_type_t *core_network_type_create();
void core_network_type_free(core_network_type_t *core_network_type);
core_network_type_t *core_network_type_parseFromJSON(
	cJSON *core_network_typeJSON);
cJSON *core_network_type_convertToJSON(core_network_type_t *core_network_type);
core_network_type_t *core_network_type_copy(core_network_type_t *dst,
                                            core_network_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _core_network_type_H_ */
