/*
 * nsi_load_level_info.h
 *
 * Represents the network slice and optionally the associated network slice instance and the load level information.
 */

#ifndef _nsi_load_level_info_H_
#define _nsi_load_level_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "network_area_info.h"
#include "number_average.h"
#include "resource_usage.h"
#include "snssai.h"
#include "time_window.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nsi_load_level_info_s nsi_load_level_info_t;
typedef struct nsi_load_level_info_s {
	int load_level_information;
	struct snssai_s *snssai;
	char *nsi_id;
	struct resource_usage_s *res_usage;
	bool is_num_of_exceed_load_level_thr;
	int num_of_exceed_load_level_thr;
	bool is_exceed_load_level_thr_ind;
	int exceed_load_level_thr_ind;
	struct network_area_info_s *network_area;
	struct time_window_s *time_period;
	list_t *res_usg_thr_cross_time_period;
	struct number_average_s *num_of_ues;
	struct number_average_s *num_of_pdu_sess;
	bool is_confidence;
	int confidence;
} nsi_load_level_info_t;

nsi_load_level_info_t *nsi_load_level_info_create(int load_level_information,
                                                  snssai_t *snssai,
                                                  char *nsi_id,
                                                  resource_usage_t *res_usage,
                                                  bool is_num_of_exceed_load_level_thr, int num_of_exceed_load_level_thr, bool is_exceed_load_level_thr_ind, int exceed_load_level_thr_ind, network_area_info_t *network_area, time_window_t *time_period, list_t *res_usg_thr_cross_time_period, number_average_t *num_of_ues, number_average_t *num_of_pdu_sess, bool is_confidence, int confidence);
void nsi_load_level_info_free(nsi_load_level_info_t *nsi_load_level_info);
nsi_load_level_info_t *nsi_load_level_info_parseFromJSON(
	cJSON *nsi_load_level_infoJSON);
cJSON *nsi_load_level_info_convertToJSON(
	nsi_load_level_info_t *nsi_load_level_info);
nsi_load_level_info_t *nsi_load_level_info_copy(nsi_load_level_info_t	*dst,
                                                nsi_load_level_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _nsi_load_level_info_H_ */
