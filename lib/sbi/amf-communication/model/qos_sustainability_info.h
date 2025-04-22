/*
 * qos_sustainability_info.h
 *
 * Represents the QoS Sustainability information.
 */

#ifndef _qos_sustainability_info_H_
#define _qos_sustainability_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "network_area_info.h"
#include "retainability_threshold.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct qos_sustainability_info_s qos_sustainability_info_t;
typedef struct qos_sustainability_info_s {
	struct network_area_info_s *area_info;
	char *fine_area_infos;
	char *end_ts;
	struct retainability_threshold_s *qos_flow_ret_thd;
	char *ran_ue_throu_thd;
	struct snssai_s *snssai;
	bool is_confidence;
	int confidence;
} qos_sustainability_info_t;

qos_sustainability_info_t *qos_sustainability_info_create(
	network_area_info_t *area_info, char *fine_area_infos, char *end_ts,
	retainability_threshold_t *qos_flow_ret_thd, char *ran_ue_throu_thd,
	snssai_t *snssai, bool is_confidence, int confidence);
void qos_sustainability_info_free(
	qos_sustainability_info_t *qos_sustainability_info);
qos_sustainability_info_t *qos_sustainability_info_parseFromJSON(
	cJSON *qos_sustainability_infoJSON);
cJSON *qos_sustainability_info_convertToJSON(
	qos_sustainability_info_t *qos_sustainability_info);
qos_sustainability_info_t *qos_sustainability_info_copy(
	qos_sustainability_info_t *dst, qos_sustainability_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _qos_sustainability_info_H_ */
