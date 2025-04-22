/*
 * eutra_location.h
 *
 * Contains the E-UTRA user location.
 */

#ifndef _eutra_location_H_
#define _eutra_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ecgi.h"
#include "global_ran_node_id.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct eutra_location_s eutra_location_t;
typedef struct eutra_location_s {
	struct tai_s *tai;
	bool is_ignore_tai;
	int ignore_tai;
	struct ecgi_s *ecgi;
	bool is_ignore_ecgi;
	int ignore_ecgi;
	bool is_age_of_location_information;
	int age_of_location_information;
	char *ue_location_timestamp;
	char *geographical_information;
	char *geodetic_information;
	struct global_ran_node_id_s *global_ngenb_id;
	struct global_ran_node_id_s *global_enb_id;
} eutra_location_t;

eutra_location_t *eutra_location_create(tai_t *tai, bool is_ignore_tai,
                                        int ignore_tai, ecgi_t *ecgi,
                                        bool is_ignore_ecgi, int ignore_ecgi,
                                        bool is_age_of_location_information,
                                        int age_of_location_information,
                                        char *ue_location_timestamp,
                                        char *geographical_information,
                                        char *geodetic_information,
                                        global_ran_node_id_t *global_ngenb_id,
                                        global_ran_node_id_t *global_enb_id);
void eutra_location_free(eutra_location_t *eutra_location);
eutra_location_t *eutra_location_parseFromJSON(cJSON *eutra_locationJSON);
cJSON *eutra_location_convertToJSON(eutra_location_t *eutra_location);
eutra_location_t *eutra_location_copy(eutra_location_t	*dst,
                                      eutra_location_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _eutra_location_H_ */
