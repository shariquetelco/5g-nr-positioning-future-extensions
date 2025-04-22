/*
 * area_of_validity.h
 *
 * Area of validity information for N2 information transfer
 */

#ifndef _area_of_validity_H_
#define _area_of_validity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "tai.h"
#include "tai_range.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct area_of_validity_s area_of_validity_t;
typedef struct area_of_validity_s {
	list_t *tai_list;
	list_t *tai_range_list;
} area_of_validity_t;

area_of_validity_t *area_of_validity_create(list_t	*tai_list,
                                            list_t	*tai_range_list);
void area_of_validity_free(area_of_validity_t *area_of_validity);
area_of_validity_t *area_of_validity_parseFromJSON(cJSON *area_of_validityJSON);
cJSON *area_of_validity_convertToJSON(area_of_validity_t *area_of_validity);
area_of_validity_t *area_of_validity_copy(area_of_validity_t	*dst,
                                          area_of_validity_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _area_of_validity_H_ */
