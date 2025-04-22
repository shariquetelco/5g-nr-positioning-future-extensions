/*
 * geographical_coordinates.h
 *
 * Geographical coordinates.
 */

#ifndef _geographical_coordinates_H_
#define _geographical_coordinates_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct geographical_coordinates_s geographical_coordinates_t;
typedef struct geographical_coordinates_s {
	double lon;
	double lat;
} geographical_coordinates_t;

geographical_coordinates_t *geographical_coordinates_create(double	lon,
                                                            double	lat);
void geographical_coordinates_free(
	geographical_coordinates_t *geographical_coordinates);
geographical_coordinates_t *geographical_coordinates_parseFromJSON(
	cJSON *geographical_coordinatesJSON);
cJSON *geographical_coordinates_convertToJSON(
	geographical_coordinates_t *geographical_coordinates);
geographical_coordinates_t *geographical_coordinates_copy(
	geographical_coordinates_t *dst, geographical_coordinates_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _geographical_coordinates_H_ */
