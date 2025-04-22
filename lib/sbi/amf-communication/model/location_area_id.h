/*
 * location_area_id.h
 *
 * Contains a Location area identification as defined in 3GPP TS 23.003, clause 4.1.
 */

#ifndef _location_area_id_H_
#define _location_area_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct location_area_id_s location_area_id_t;
typedef struct location_area_id_s {
	struct plmn_id_s *plmn_id;
	char *lac;
} location_area_id_t;

location_area_id_t *location_area_id_create(plmn_id_t *plmn_id, char *lac);
void location_area_id_free(location_area_id_t *location_area_id);
location_area_id_t *location_area_id_parseFromJSON(cJSON *location_area_idJSON);
cJSON *location_area_id_convertToJSON(location_area_id_t *location_area_id);
location_area_id_t *location_area_id_copy(location_area_id_t	*dst,
                                          location_area_id_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _location_area_id_H_ */
