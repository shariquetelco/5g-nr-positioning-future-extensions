/*
 * satellite_backhaul_category.h
 *
 * Indicates the satellite backhaul used.
 */

#ifndef _satellite_backhaul_category_H_
#define _satellite_backhaul_category_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "satellite_backhaul_category_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct satellite_backhaul_category_s satellite_backhaul_category_t;
typedef struct satellite_backhaul_category_s {} satellite_backhaul_category_t;

satellite_backhaul_category_t *satellite_backhaul_category_create();
void satellite_backhaul_category_free(
	satellite_backhaul_category_t *satellite_backhaul_category);
satellite_backhaul_category_t *satellite_backhaul_category_parseFromJSON(
	cJSON *satellite_backhaul_categoryJSON);
cJSON *satellite_backhaul_category_convertToJSON(
	satellite_backhaul_category_t *satellite_backhaul_category);
satellite_backhaul_category_t *satellite_backhaul_category_copy(
	satellite_backhaul_category_t *dst, satellite_backhaul_category_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _satellite_backhaul_category_H_ */
