/*
 * dn_perf.h
 *
 * Represents DN performance for the application.
 */

#ifndef _dn_perf_H_
#define _dn_perf_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "addr_fqdn.h"
#include "network_area_info.h"
#include "perf_data.h"
#include "time_window.h"
#include "upf_information.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dn_perf_s dn_perf_t;
typedef struct dn_perf_s {
	struct addr_fqdn_s *app_server_ins_addr;
	struct upf_information_s *upf_info;
	char *dnai;
	struct perf_data_s *perf_data;
	struct network_area_info_s *spatial_valid_con;
	struct time_window_s *temporal_valid_con;
} dn_perf_t;

dn_perf_t *dn_perf_create(addr_fqdn_t *app_server_ins_addr,
                          upf_information_t *upf_info, char *dnai,
                          perf_data_t *perf_data,
                          network_area_info_t *spatial_valid_con,
                          time_window_t *temporal_valid_con);
void dn_perf_free(dn_perf_t *dn_perf);
dn_perf_t *dn_perf_parseFromJSON(cJSON *dn_perfJSON);
cJSON *dn_perf_convertToJSON(dn_perf_t *dn_perf);
dn_perf_t *dn_perf_copy(dn_perf_t *dst, dn_perf_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _dn_perf_H_ */
