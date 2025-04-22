/*
 * geo_distribution_info.h
 *
 * Represents the geographical distribution of the UEs.
 */

#ifndef _geo_distribution_info_H_
#define _geo_distribution_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "user_location.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct geo_distribution_info_s geo_distribution_info_t;
typedef struct geo_distribution_info_s {
	struct user_location_s *loc;
	list_t *supis;
	list_t *gpsis;
} geo_distribution_info_t;

geo_distribution_info_t *geo_distribution_info_create(user_location_t	*loc,
                                                      list_t		*supis,
                                                      list_t		*gpsis);
void geo_distribution_info_free(geo_distribution_info_t *geo_distribution_info);
geo_distribution_info_t *geo_distribution_info_parseFromJSON(
	cJSON *geo_distribution_infoJSON);
cJSON *geo_distribution_info_convertToJSON(
	geo_distribution_info_t *geo_distribution_info);
geo_distribution_info_t *geo_distribution_info_copy(
	geo_distribution_info_t *dst, geo_distribution_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _geo_distribution_info_H_ */
