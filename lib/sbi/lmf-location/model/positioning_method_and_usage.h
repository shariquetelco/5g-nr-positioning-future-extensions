/*
 * positioning_method_and_usage.h
 *
 * Indicates the usage of a positioning method.
 */

#ifndef _positioning_method_and_usage_H_
#define _positioning_method_and_usage_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "positioning_method.h"
#include "positioning_mode.h"
#include "usage.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct positioning_method_and_usage_s positioning_method_and_usage_t;
typedef struct positioning_method_and_usage_s {
	positioning_method_e method;
	positioning_mode_e mode;
	usage_e usage;
	bool is_method_code;
	int method_code;
} positioning_method_and_usage_t;

positioning_method_and_usage_t *positioning_method_and_usage_create(
	positioning_method_e method, positioning_mode_e mode, usage_e usage,
	bool is_method_code, int method_code);
void positioning_method_and_usage_free(
	positioning_method_and_usage_t *positioning_method_and_usage);
positioning_method_and_usage_t *positioning_method_and_usage_parseFromJSON(
	cJSON *positioning_method_and_usageJSON);
cJSON *positioning_method_and_usage_convertToJSON(
	positioning_method_and_usage_t *positioning_method_and_usage);
positioning_method_and_usage_t *positioning_method_and_usage_copy(
	positioning_method_and_usage_t	*dst,
	positioning_method_and_usage_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _positioning_method_and_usage_H_ */
