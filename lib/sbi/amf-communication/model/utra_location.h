/*
 * utra_location.h
 *
 * Exactly one of cgi, sai or lai shall be present.
 */

#ifndef _utra_location_H_
#define _utra_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "cell_global_id.h"
#include "location_area_id.h"
#include "routing_area_id.h"
#include "service_area_id.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct utra_location_s utra_location_t;
typedef struct utra_location_s {
	struct cell_global_id_s *cgi;
	struct service_area_id_s *sai;
	struct location_area_id_s *lai;
	struct routing_area_id_s *rai;
	bool is_age_of_location_information;
	int age_of_location_information;
	char *ue_location_timestamp;
	char *geographical_information;
	char *geodetic_information;
} utra_location_t;

utra_location_t *utra_location_create(cell_global_id_t		*cgi,
                                      service_area_id_t		*sai,
                                      location_area_id_t	*lai,
                                      routing_area_id_t		*rai,
                                      bool			is_age_of_location_information,
                                      int			age_of_location_information,
                                      char			*ue_location_timestamp,
                                      char			*geographical_information,
                                      char			*geodetic_information);
void utra_location_free(utra_location_t *utra_location);
utra_location_t *utra_location_parseFromJSON(cJSON *utra_locationJSON);
cJSON *utra_location_convertToJSON(utra_location_t *utra_location);
utra_location_t *utra_location_copy(utra_location_t *dst, utra_location_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _utra_location_H_ */
