/*
 * traffic_information.h
 *
 * Traffic information including UL/DL data rate and/or Traffic volume.
 */

#ifndef _traffic_information_H_
#define _traffic_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct traffic_information_s traffic_information_t;
typedef struct traffic_information_s {
	char *uplink_rate;
	char *downlink_rate;
	bool is_uplink_volume;
	long uplink_volume;
	bool is_downlink_volume;
	long downlink_volume;
	bool is_total_volume;
	long total_volume;
} traffic_information_t;

traffic_information_t *traffic_information_create(char	*uplink_rate,
                                                  char	*downlink_rate,
                                                  bool	is_uplink_volume,
                                                  long	uplink_volume,
                                                  bool	is_downlink_volume,
                                                  long	downlink_volume,
                                                  bool	is_total_volume,
                                                  long	total_volume);
void traffic_information_free(traffic_information_t *traffic_information);
traffic_information_t *traffic_information_parseFromJSON(
	cJSON *traffic_informationJSON);
cJSON *traffic_information_convertToJSON(
	traffic_information_t *traffic_information);
traffic_information_t *traffic_information_copy(traffic_information_t	*dst,
                                                traffic_information_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _traffic_information_H_ */
