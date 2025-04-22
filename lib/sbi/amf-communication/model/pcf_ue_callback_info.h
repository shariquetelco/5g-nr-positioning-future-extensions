/*
 * pcf_ue_callback_info.h
 *
 * Contains the PCF for the UE information necessary for the PCF for the PDU session to send  SM Policy Association Establishment and Termination events.
 */

#ifndef _pcf_ue_callback_info_H_
#define _pcf_ue_callback_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pcf_ue_callback_info_s pcf_ue_callback_info_t;
typedef struct pcf_ue_callback_info_s {
	char *callback_uri;
	char *binding_info;
} pcf_ue_callback_info_t;

pcf_ue_callback_info_t *pcf_ue_callback_info_create(char	*callback_uri,
                                                    char	*binding_info);
void pcf_ue_callback_info_free(pcf_ue_callback_info_t *pcf_ue_callback_info);
pcf_ue_callback_info_t *pcf_ue_callback_info_parseFromJSON(
	cJSON *pcf_ue_callback_infoJSON);
cJSON *pcf_ue_callback_info_convertToJSON(
	pcf_ue_callback_info_t *pcf_ue_callback_info);
pcf_ue_callback_info_t *pcf_ue_callback_info_copy(
	pcf_ue_callback_info_t	*dst,
	pcf_ue_callback_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _pcf_ue_callback_info_H_ */
