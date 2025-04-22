/*
 * circumstance_description.h
 *
 * Contains the description of a circumstance.
 */

#ifndef _circumstance_description_H_
#define _circumstance_description_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "network_area_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct circumstance_description_s circumstance_description_t;
typedef struct circumstance_description_s {
	bool is_freq;
	float freq;
	char *tm;
	struct network_area_info_s *loc_area;
	bool is_vol;
	long vol;
} circumstance_description_t;

circumstance_description_t *circumstance_description_create(bool is_freq,
                                                            float freq,
                                                            char *tm,
                                                            network_area_info_t *loc_area, bool is_vol, long vol);
void circumstance_description_free(
	circumstance_description_t *circumstance_description);
circumstance_description_t *circumstance_description_parseFromJSON(
	cJSON *circumstance_descriptionJSON);
cJSON *circumstance_description_convertToJSON(
	circumstance_description_t *circumstance_description);
circumstance_description_t *circumstance_description_copy(
	circumstance_description_t *dst, circumstance_description_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _circumstance_description_H_ */
