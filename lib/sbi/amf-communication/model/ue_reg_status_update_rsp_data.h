/*
 * ue_reg_status_update_rsp_data.h
 *
 * Data within a UE registration status update response to provide the status of UE context transfer status update at a source AMF
 */

#ifndef _ue_reg_status_update_rsp_data_H_
#define _ue_reg_status_update_rsp_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_reg_status_update_rsp_data_s ue_reg_status_update_rsp_data_t;
typedef struct ue_reg_status_update_rsp_data_s {
	int reg_status_transfer_complete;
} ue_reg_status_update_rsp_data_t;

ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data_create(
	int reg_status_transfer_complete);
void ue_reg_status_update_rsp_data_free(
	ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data);
ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data_parseFromJSON(
	cJSON *ue_reg_status_update_rsp_dataJSON);
cJSON *ue_reg_status_update_rsp_data_convertToJSON(
	ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data);
ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data_copy(
	ue_reg_status_update_rsp_data_t *dst,
	ue_reg_status_update_rsp_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_reg_status_update_rsp_data_H_ */
