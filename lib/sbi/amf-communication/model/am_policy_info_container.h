/*
 * am_policy_info_container.h
 *
 * AM Policy Information Container
 */

#ifndef _am_policy_info_container_H_
#define _am_policy_info_container_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "slice_usage_control_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct am_policy_info_container_s am_policy_info_container_t;
typedef struct am_policy_info_container_s {
	list_t *slice_usg_ctrl_info_sets;
} am_policy_info_container_t;

am_policy_info_container_t *am_policy_info_container_create(
	list_t *slice_usg_ctrl_info_sets);
void am_policy_info_container_free(
	am_policy_info_container_t *am_policy_info_container);
am_policy_info_container_t *am_policy_info_container_parseFromJSON(
	cJSON *am_policy_info_containerJSON);
cJSON *am_policy_info_container_convertToJSON(
	am_policy_info_container_t *am_policy_info_container);
am_policy_info_container_t *am_policy_info_container_copy(
	am_policy_info_container_t *dst, am_policy_info_container_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _am_policy_info_container_H_ */
