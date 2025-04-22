/*
 * nr_location.h
 *
 * Contains the NR user location.
 */

#ifndef _nr_location_H_
#define _nr_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "global_ran_node_id.h"
#include "ncgi.h"
#include "ntn_tai_info.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nr_location_s nr_location_t;
typedef struct nr_location_s {
	struct tai_s *tai;
	struct ncgi_s *ncgi;
	bool is_ignore_ncgi;
	int ignore_ncgi;
	bool is_age_of_location_information;
	int age_of_location_information;
	char *ue_location_timestamp;
	char *geographical_information;
	char *geodetic_information;
	struct global_ran_node_id_s *global_gnb_id;
	struct ntn_tai_info_s *ntn_tai_info;
} nr_location_t;

nr_location_t *nr_location_create(tai_t *tai, ncgi_t *ncgi, bool is_ignore_ncgi,
                                  int ignore_ncgi,
                                  bool is_age_of_location_information,
                                  int age_of_location_information,
                                  char *ue_location_timestamp,
                                  char *geographical_information,
                                  char *geodetic_information,
                                  global_ran_node_id_t *global_gnb_id,
                                  ntn_tai_info_t *ntn_tai_info);
void nr_location_free(nr_location_t *nr_location);
nr_location_t *nr_location_parseFromJSON(cJSON *nr_locationJSON);
cJSON *nr_location_convertToJSON(nr_location_t *nr_location);
nr_location_t *nr_location_copy(nr_location_t *dst, nr_location_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _nr_location_H_ */
