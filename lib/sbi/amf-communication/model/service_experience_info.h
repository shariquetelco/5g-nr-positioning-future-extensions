/*
 * service_experience_info.h
 *
 * Represents service experience information.
 */

#ifndef _service_experience_info_H_
#define _service_experience_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "addr_fqdn.h"
#include "location_info.h"
#include "network_area_info.h"
#include "pdu_session_info_1.h"
#include "rat_freq_information.h"
#include "service_experience_type.h"
#include "snssai.h"
#include "svc_experience.h"
#include "upf_information.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct service_experience_info_s service_experience_info_t;
typedef struct service_experience_info_s {
	struct svc_experience_s *svc_exprc;
	bool is_svc_exprc_variance;
	float svc_exprc_variance;
	list_t *supis;
	struct snssai_s *snssai;
	char *app_id;
	struct service_experience_type_s *srv_expc_type;
	list_t *ue_locs;
	struct upf_information_s *upf_info;
	char *dnai;
	struct addr_fqdn_s *app_server_inst;
	bool is_confidence;
	int confidence;
	char *dnn;
	struct network_area_info_s *network_area;
	char *nsi_id;
	bool is_ratio;
	int ratio;
	struct rat_freq_information_s *rat_freq;
	struct pdu_session_info_1_s *pdu_ses_info;
} service_experience_info_t;

service_experience_info_t *service_experience_info_create(
	svc_experience_t *svc_exprc, bool is_svc_exprc_variance,
	float svc_exprc_variance, list_t *supis, snssai_t *snssai, char *app_id,
	service_experience_type_t *srv_expc_type, list_t *ue_locs,
	upf_information_t *upf_info, char *dnai, addr_fqdn_t *app_server_inst,
	bool is_confidence, int confidence, char *dnn,
	network_area_info_t *network_area, char *nsi_id, bool is_ratio,
	int ratio, rat_freq_information_t *rat_freq,
	pdu_session_info_1_t *pdu_ses_info);
void service_experience_info_free(
	service_experience_info_t *service_experience_info);
service_experience_info_t *service_experience_info_parseFromJSON(
	cJSON *service_experience_infoJSON);
cJSON *service_experience_info_convertToJSON(
	service_experience_info_t *service_experience_info);
service_experience_info_t *service_experience_info_copy(
	service_experience_info_t *dst, service_experience_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _service_experience_info_H_ */
