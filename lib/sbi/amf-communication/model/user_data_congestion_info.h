/*
 * user_data_congestion_info.h
 *
 * Represents the user data congestion information.
 */

#ifndef _user_data_congestion_info_H_
#define _user_data_congestion_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "congestion_info.h"
#include "network_area_info.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct user_data_congestion_info_s user_data_congestion_info_t;
typedef struct user_data_congestion_info_s {
	struct network_area_info_s *network_area;
	struct congestion_info_s *congestion_info;
	struct snssai_s *snssai;
} user_data_congestion_info_t;

user_data_congestion_info_t *user_data_congestion_info_create(
	network_area_info_t *network_area, congestion_info_t *congestion_info,
	snssai_t *snssai);
void user_data_congestion_info_free(
	user_data_congestion_info_t *user_data_congestion_info);
user_data_congestion_info_t *user_data_congestion_info_parseFromJSON(
	cJSON *user_data_congestion_infoJSON);
cJSON *user_data_congestion_info_convertToJSON(
	user_data_congestion_info_t *user_data_congestion_info);
user_data_congestion_info_t *user_data_congestion_info_copy(
	user_data_congestion_info_t *dst, user_data_congestion_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _user_data_congestion_info_H_ */
