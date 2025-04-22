/*
 * mbsr_location_info.h
 *
 *
 */

#ifndef _mbsr_location_info_H_
#define _mbsr_location_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mbsr_location_info_s mbsr_location_info_t;
typedef struct mbsr_location_info_s {
	list_t *mbsr_location;
	list_t *mbsr_location_areas;
} mbsr_location_info_t;

mbsr_location_info_t *mbsr_location_info_create(list_t	*mbsr_location,
                                                list_t	*mbsr_location_areas);
void mbsr_location_info_free(mbsr_location_info_t *mbsr_location_info);
mbsr_location_info_t *mbsr_location_info_parseFromJSON(
	cJSON *mbsr_location_infoJSON);
cJSON *mbsr_location_info_convertToJSON(
	mbsr_location_info_t *mbsr_location_info);
mbsr_location_info_t *mbsr_location_info_copy(mbsr_location_info_t	*dst,
                                              mbsr_location_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _mbsr_location_info_H_ */
