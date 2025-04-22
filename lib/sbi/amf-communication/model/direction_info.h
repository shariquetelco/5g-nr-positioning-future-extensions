/*
 * direction_info.h
 *
 * Represents the UE direction information.
 */

#ifndef _direction_info_H_
#define _direction_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "direction.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct direction_info_s direction_info_t;
typedef struct direction_info_s {
	char *supi;
	char *gpsi;
	bool is_num_of_ue;
	int num_of_ue;
	bool is_avr_speed;
	float avr_speed;
	bool is_ratio;
	int ratio;
	struct direction_s *direction;
} direction_info_t;

direction_info_t *direction_info_create(char *supi, char *gpsi,
                                        bool is_num_of_ue, int num_of_ue,
                                        bool is_avr_speed, float avr_speed,
                                        bool is_ratio, int ratio,
                                        direction_t *direction);
void direction_info_free(direction_info_t *direction_info);
direction_info_t *direction_info_parseFromJSON(cJSON *direction_infoJSON);
cJSON *direction_info_convertToJSON(direction_info_t *direction_info);
direction_info_t *direction_info_copy(direction_info_t	*dst,
                                      direction_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _direction_info_H_ */
