/*
 * add_location_datas.h
 *
 *
 */

#ifndef _add_location_datas_H_
#define _add_location_datas_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "location_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct add_location_datas_s add_location_datas_t;
typedef struct add_location_datas_s {
	list_t *add_location_datas;
} add_location_datas_t;

add_location_datas_t *add_location_datas_create(list_t *add_location_datas);
void add_location_datas_free(add_location_datas_t *add_location_datas);
add_location_datas_t *add_location_datas_parseFromJSON(
	cJSON *add_location_datasJSON);
cJSON *add_location_datas_convertToJSON(
	add_location_datas_t *add_location_datas);
add_location_datas_t *add_location_datas_copy(add_location_datas_t	*dst,
                                              add_location_datas_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _add_location_datas_H_ */
