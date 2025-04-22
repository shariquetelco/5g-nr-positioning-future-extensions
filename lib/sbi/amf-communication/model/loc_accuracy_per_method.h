/*
 * loc_accuracy_per_method.h
 *
 * Contains location accuracy analytics per positioning method.
 */

#ifndef _loc_accuracy_per_method_H_
#define _loc_accuracy_per_method_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "positioning_method.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct loc_accuracy_per_method_s loc_accuracy_per_method_t;
typedef struct loc_accuracy_per_method_s {
	struct positioning_method_s *pos_method;
	int loc_acc;
	bool is_los_nlos_pct;
	int los_nlos_pct;
	bool is_los_nlos_ind;
	int los_nlos_ind;
} loc_accuracy_per_method_t;

loc_accuracy_per_method_t *loc_accuracy_per_method_create(
	positioning_method_t *pos_method, int loc_acc, bool is_los_nlos_pct,
	int los_nlos_pct, bool is_los_nlos_ind, int los_nlos_ind);
void loc_accuracy_per_method_free(
	loc_accuracy_per_method_t *loc_accuracy_per_method);
loc_accuracy_per_method_t *loc_accuracy_per_method_parseFromJSON(
	cJSON *loc_accuracy_per_methodJSON);
cJSON *loc_accuracy_per_method_convertToJSON(
	loc_accuracy_per_method_t *loc_accuracy_per_method);
loc_accuracy_per_method_t *loc_accuracy_per_method_copy(
	loc_accuracy_per_method_t *dst, loc_accuracy_per_method_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _loc_accuracy_per_method_H_ */
