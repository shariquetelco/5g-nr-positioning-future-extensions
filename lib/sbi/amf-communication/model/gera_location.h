/*
 * gera_location.h
 *
 * Exactly one of cgi, sai or lai shall be present.
 */

#ifndef _gera_location_H_
#define _gera_location_H_

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

typedef struct gera_location_s gera_location_t;
typedef struct gera_location_s {
	char *location_number;
	struct cell_global_id_s *cgi;
	struct service_area_id_s *sai;
	struct location_area_id_s *lai;
	struct routing_area_id_s *rai;
	char *vlr_number;
	char *msc_number;
	bool is_age_of_location_information;
	int age_of_location_information;
	char *ue_location_timestamp;
	char *geographical_information;
	char *geodetic_information;
} gera_location_t;

gera_location_t *gera_location_create(char *location_number,
                                      cell_global_id_t *cgi,
                                      service_area_id_t *sai,
                                      location_area_id_t *lai,
                                      routing_area_id_t *rai, char *vlr_number,
                                      char *msc_number,
                                      bool is_age_of_location_information,
                                      int age_of_location_information,
                                      char *ue_location_timestamp,
                                      char *geographical_information,
                                      char *geodetic_information);
void gera_location_free(gera_location_t *gera_location);
gera_location_t *gera_location_parseFromJSON(cJSON *gera_locationJSON);
cJSON *gera_location_convertToJSON(gera_location_t *gera_location);
gera_location_t *gera_location_copy(gera_location_t *dst, gera_location_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _gera_location_H_ */
