/*
 * small_data_rate_status_info.h
 *
 * Represents the small data rate status
 */

#ifndef _small_data_rate_status_info_H_
#define _small_data_rate_status_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "small_data_rate_status.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct small_data_rate_status_info_s small_data_rate_status_info_t;
typedef struct small_data_rate_status_info_s {
	struct snssai_s *snssai;
	char *dnn;
	struct small_data_rate_status_s *small_data_rate_status;
} small_data_rate_status_info_t;

small_data_rate_status_info_t *small_data_rate_status_info_create(
	snssai_t *snssai, char *dnn,
	small_data_rate_status_t *small_data_rate_status);
void small_data_rate_status_info_free(
	small_data_rate_status_info_t *small_data_rate_status_info);
small_data_rate_status_info_t *small_data_rate_status_info_parseFromJSON(
	cJSON *small_data_rate_status_infoJSON);
cJSON *small_data_rate_status_info_convertToJSON(
	small_data_rate_status_info_t *small_data_rate_status_info);
small_data_rate_status_info_t *small_data_rate_status_info_copy(
	small_data_rate_status_info_t *dst, small_data_rate_status_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _small_data_rate_status_info_H_ */
