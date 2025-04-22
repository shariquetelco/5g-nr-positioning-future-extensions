/*
 * up_config.h
 *
 * UP Config
 */

#ifndef _up_config_H_
#define _up_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "lcs_up_connection_ind.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct up_config_s up_config_t;
typedef struct up_config_s {
	char *up_notify_call_back_uri;
	char *notif_correlation_id;
	char *supi;
	char *gpsi;
	bool is_amf_reallocation_ind;
	int amf_reallocation_ind;
	lcs_up_connection_ind_e lcs_up_connection_ind;
	char *target_lmfid;
} up_config_t;

up_config_t *up_config_create(char *up_notify_call_back_uri,
                              char *notif_correlation_id, char *supi,
                              char *gpsi, bool is_amf_reallocation_ind,
                              int amf_reallocation_ind,
                              lcs_up_connection_ind_e lcs_up_connection_ind,
                              char *target_lmfid);
void up_config_free(up_config_t *up_config);
up_config_t *up_config_parseFromJSON(cJSON *up_configJSON);
cJSON *up_config_convertToJSON(up_config_t *up_config);
up_config_t *up_config_copy(up_config_t *dst, up_config_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _up_config_H_ */
