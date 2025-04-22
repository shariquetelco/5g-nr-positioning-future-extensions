/*
 * td_traffic.h
 *
 * Represents traffic that matches or unmatches Traffic Descriptor of URSP rule.
 */

#ifndef _td_traffic_H_
#define _td_traffic_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "pdu_ses_traffic_req.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct td_traffic_s td_traffic_t;
typedef struct td_traffic_s {
	list_t *pdu_ses_traf_reqs;
	bool is_ul_vol;
	long ul_vol;
	bool is_dl_vol;
	long dl_vol;
	bool is_all_vol;
	long all_vol;
	bool is_ul_num_of_pkt;
	int ul_num_of_pkt;
	bool is_dl_num_of_pkt;
	int dl_num_of_pkt;
	bool is_all_num_of_pkt;
	int all_num_of_pkt;
} td_traffic_t;

td_traffic_t *td_traffic_create(list_t *pdu_ses_traf_reqs, bool is_ul_vol,
                                long ul_vol, bool is_dl_vol, long dl_vol,
                                bool is_all_vol, long all_vol,
                                bool is_ul_num_of_pkt, int ul_num_of_pkt,
                                bool is_dl_num_of_pkt, int dl_num_of_pkt,
                                bool is_all_num_of_pkt, int all_num_of_pkt);
void td_traffic_free(td_traffic_t *td_traffic);
td_traffic_t *td_traffic_parseFromJSON(cJSON *td_trafficJSON);
cJSON *td_traffic_convertToJSON(td_traffic_t *td_traffic);
td_traffic_t *td_traffic_copy(td_traffic_t *dst, td_traffic_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _td_traffic_H_ */
