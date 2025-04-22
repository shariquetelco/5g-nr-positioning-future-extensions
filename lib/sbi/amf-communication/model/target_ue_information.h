/*
 * target_ue_information.h
 *
 * Identifies the target UE information.
 */

#ifndef _target_ue_information_H_
#define _target_ue_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct target_ue_information_s target_ue_information_t;
typedef struct target_ue_information_s {
	bool is_any_ue;
	int any_ue;
	list_t *supis;
	list_t *gpsis;
	list_t *int_group_ids;
} target_ue_information_t;

target_ue_information_t *target_ue_information_create(bool is_any_ue,
                                                      int any_ue, list_t *supis,
                                                      list_t *gpsis,
                                                      list_t *int_group_ids);
void target_ue_information_free(target_ue_information_t *target_ue_information);
target_ue_information_t *target_ue_information_parseFromJSON(
	cJSON *target_ue_informationJSON);
cJSON *target_ue_information_convertToJSON(
	target_ue_information_t *target_ue_information);
target_ue_information_t *target_ue_information_copy(
	target_ue_information_t *dst, target_ue_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _target_ue_information_H_ */
