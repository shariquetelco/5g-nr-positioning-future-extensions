/*
 * privacy_check_id_mapping_resp_data.h
 *
 * Privacy Check Id Mapping Response Data
 */

#ifndef _privacy_check_id_mapping_resp_data_H_
#define _privacy_check_id_mapping_resp_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct privacy_check_id_mapping_resp_data_s
        privacy_check_id_mapping_resp_data_t;
typedef struct privacy_check_id_mapping_resp_data_s {
	char *app_layer_id;
	char *gpsi;
} privacy_check_id_mapping_resp_data_t;

privacy_check_id_mapping_resp_data_t *privacy_check_id_mapping_resp_data_create(
	char *app_layer_id, char *gpsi);
void privacy_check_id_mapping_resp_data_free(
	privacy_check_id_mapping_resp_data_t *privacy_check_id_mapping_resp_data);
privacy_check_id_mapping_resp_data_t *
privacy_check_id_mapping_resp_data_parseFromJSON(
	cJSON *privacy_check_id_mapping_resp_dataJSON);
cJSON *privacy_check_id_mapping_resp_data_convertToJSON(
	privacy_check_id_mapping_resp_data_t *privacy_check_id_mapping_resp_data);
privacy_check_id_mapping_resp_data_t *privacy_check_id_mapping_resp_data_copy(
	privacy_check_id_mapping_resp_data_t	*dst,
	privacy_check_id_mapping_resp_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _privacy_check_id_mapping_resp_data_H_ */
