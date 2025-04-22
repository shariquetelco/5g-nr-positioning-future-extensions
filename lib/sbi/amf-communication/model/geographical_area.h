/*
 * geographical_area.h
 *
 * Contains geographical area information (e.g.a civic address or shapes).
 */

#ifndef _geographical_area_H_
#define _geographical_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "civic_address.h"
#include "geographic_area.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct geographical_area_s geographical_area_t;
typedef struct geographical_area_s {
	struct civic_address_s *civic_address;
	struct geographic_area_s *shapes;
} geographical_area_t;

geographical_area_t *geographical_area_create(civic_address_t	*civic_address,
                                              geographic_area_t *shapes);
void geographical_area_free(geographical_area_t *geographical_area);
geographical_area_t *geographical_area_parseFromJSON(
	cJSON *geographical_areaJSON);
cJSON *geographical_area_convertToJSON(geographical_area_t *geographical_area);
geographical_area_t *geographical_area_copy(geographical_area_t *dst,
                                            geographical_area_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _geographical_area_H_ */
