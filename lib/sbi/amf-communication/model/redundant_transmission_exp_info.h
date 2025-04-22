/*
 * redundant_transmission_exp_info.h
 *
 * The redundant transmission experience related information. When subscribed event is \&quot;RED_TRANS_EXP\&quot;, the \&quot;redTransInfos\&quot; attribute shall be included.
 */

#ifndef _redundant_transmission_exp_info_H_
#define _redundant_transmission_exp_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "network_area_info.h"
#include "redundant_transmission_exp_per_ts.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct redundant_transmission_exp_info_s
        redundant_transmission_exp_info_t;
typedef struct redundant_transmission_exp_info_s {
	struct network_area_info_s *spatial_valid_con;
	char *dnn;
	list_t *red_trans_exps;
} redundant_transmission_exp_info_t;

redundant_transmission_exp_info_t *redundant_transmission_exp_info_create(
	network_area_info_t *spatial_valid_con, char *dnn,
	list_t *red_trans_exps);
void redundant_transmission_exp_info_free(
	redundant_transmission_exp_info_t *redundant_transmission_exp_info);
redundant_transmission_exp_info_t *redundant_transmission_exp_info_parseFromJSON(
	cJSON *redundant_transmission_exp_infoJSON);
cJSON *redundant_transmission_exp_info_convertToJSON(
	redundant_transmission_exp_info_t *redundant_transmission_exp_info);
redundant_transmission_exp_info_t *redundant_transmission_exp_info_copy(
	redundant_transmission_exp_info_t	*dst,
	redundant_transmission_exp_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _redundant_transmission_exp_info_H_ */
