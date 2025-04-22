/*
 * resource_usage_requirement.h
 *
 * resource usage requirement.
 */

#ifndef _resource_usage_requirement_H_
#define _resource_usage_requirement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "traffic_direction.h"
#include "value_expression.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct resource_usage_requirement_s resource_usage_requirement_t;
typedef struct resource_usage_requirement_s {
	struct traffic_direction_s *tfc_dirc;
	struct value_expression_s *val_exp;
} resource_usage_requirement_t;

resource_usage_requirement_t *resource_usage_requirement_create(
	traffic_direction_t *tfc_dirc, value_expression_t *val_exp);
void resource_usage_requirement_free(
	resource_usage_requirement_t *resource_usage_requirement);
resource_usage_requirement_t *resource_usage_requirement_parseFromJSON(
	cJSON *resource_usage_requirementJSON);
cJSON *resource_usage_requirement_convertToJSON(
	resource_usage_requirement_t *resource_usage_requirement);
resource_usage_requirement_t *resource_usage_requirement_copy(
	resource_usage_requirement_t *dst, resource_usage_requirement_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _resource_usage_requirement_H_ */
