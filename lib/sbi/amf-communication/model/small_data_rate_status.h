/*
 * small_data_rate_status.h
 *
 * It indicates theSmall Data Rate Control Status
 */

#ifndef _small_data_rate_status_H_
#define _small_data_rate_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct small_data_rate_status_s small_data_rate_status_t;
typedef struct small_data_rate_status_s {
	bool is_remain_packets_ul;
	int remain_packets_ul;
	bool is_remain_packets_dl;
	int remain_packets_dl;
	char *validity_time;
	bool is_remain_ex_reports_ul;
	int remain_ex_reports_ul;
	bool is_remain_ex_reports_dl;
	int remain_ex_reports_dl;
} small_data_rate_status_t;

small_data_rate_status_t *small_data_rate_status_create(
	bool is_remain_packets_ul, int remain_packets_ul,
	bool is_remain_packets_dl, int remain_packets_dl, char *validity_time,
	bool is_remain_ex_reports_ul, int remain_ex_reports_ul,
	bool is_remain_ex_reports_dl, int remain_ex_reports_dl);
void small_data_rate_status_free(
	small_data_rate_status_t *small_data_rate_status);
small_data_rate_status_t *small_data_rate_status_parseFromJSON(
	cJSON *small_data_rate_statusJSON);
cJSON *small_data_rate_status_convertToJSON(
	small_data_rate_status_t *small_data_rate_status);
small_data_rate_status_t *small_data_rate_status_copy(
	small_data_rate_status_t *dst, small_data_rate_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _small_data_rate_status_H_ */
