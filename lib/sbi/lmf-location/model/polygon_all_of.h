/*
 * polygon_all_of.h
 *
 *
 */

#ifndef _polygon_all_of_H_
#define _polygon_all_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geographical_coordinates.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct polygon_all_of_s polygon_all_of_t;
typedef struct polygon_all_of_s {
	list_t *point_list;
} polygon_all_of_t;

polygon_all_of_t *polygon_all_of_create(list_t *point_list);
void polygon_all_of_free(polygon_all_of_t *polygon_all_of);
polygon_all_of_t *polygon_all_of_parseFromJSON(cJSON *polygon_all_ofJSON);
cJSON *polygon_all_of_convertToJSON(polygon_all_of_t *polygon_all_of);
polygon_all_of_t *polygon_all_of_copy(polygon_all_of_t	*dst,
                                      polygon_all_of_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _polygon_all_of_H_ */
