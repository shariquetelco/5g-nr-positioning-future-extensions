/*
 * core_network_type_any_of.h
 *
 *
 */

#ifndef _core_network_type_any_of_H_
#define _core_network_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { core_network_type_any_of_NULL = 0, core_network_type_any_of__5GC,
	       core_network_type_any_of_EPC } core_network_type_any_of_e;

char *core_network_type_any_of_ToString(
	core_network_type_any_of_e core_network_type_any_of);

core_network_type_any_of_e core_network_type_any_of_FromString(
	char *core_network_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _core_network_type_any_of_H_ */
