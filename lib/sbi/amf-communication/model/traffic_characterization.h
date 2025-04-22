/*
 * traffic_characterization.h
 *
 * Identifies the detailed traffic characterization.
 */

#ifndef _traffic_characterization_H_
#define _traffic_characterization_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ip_eth_flow_description.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct traffic_characterization_s traffic_characterization_t;
typedef struct traffic_characterization_s {
	char *dnn;
	struct snssai_s *snssai;
	char *app_id;
	list_t *f_descs;
	bool is_ul_vol;
	long ul_vol;
	bool is_ul_vol_variance;
	float ul_vol_variance;
	bool is_dl_vol;
	long dl_vol;
	bool is_dl_vol_variance;
	float dl_vol_variance;
} traffic_characterization_t;

traffic_characterization_t *traffic_characterization_create(char *dnn,
                                                            snssai_t *snssai,
                                                            char *app_id,
                                                            list_t *f_descs,
                                                            bool is_ul_vol,
                                                            long ul_vol,
                                                            bool is_ul_vol_variance, float ul_vol_variance, bool is_dl_vol, long dl_vol, bool is_dl_vol_variance, float dl_vol_variance);
void traffic_characterization_free(
	traffic_characterization_t *traffic_characterization);
traffic_characterization_t *traffic_characterization_parseFromJSON(
	cJSON *traffic_characterizationJSON);
cJSON *traffic_characterization_convertToJSON(
	traffic_characterization_t *traffic_characterization);
traffic_characterization_t *traffic_characterization_copy(
	traffic_characterization_t *dst, traffic_characterization_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _traffic_characterization_H_ */
