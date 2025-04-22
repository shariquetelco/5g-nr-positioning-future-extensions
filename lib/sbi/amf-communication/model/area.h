/*
 * area.h
 *
 * Provides area information.
 */

#ifndef _area_H_
#define _area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct area_s area_t;
typedef struct area_s {
	list_t *tacs;
	char *area_code;
} area_t;

area_t *area_create(list_t *tacs, char *area_code);
void area_free(area_t *area);
area_t *area_parseFromJSON(cJSON *areaJSON);
cJSON *area_convertToJSON(area_t *area);
area_t *area_copy(area_t *dst, area_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _area_H_ */
