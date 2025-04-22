/*
 * amf_status_info.h
 *
 * AMF Status Information
 */

#ifndef _amf_status_info_H_
#define _amf_status_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "guami.h"
#include "status_change.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct amf_status_info_s amf_status_info_t;
typedef struct amf_status_info_s {
	list_t *guami_list;
	status_change_e status_change;
	char *target_amf_removal;
	char *target_amf_failure;
} amf_status_info_t;

amf_status_info_t *amf_status_info_create(list_t		*guami_list,
                                          status_change_e	status_change,
                                          char			*target_amf_removal,
                                          char			*target_amf_failure);
void amf_status_info_free(amf_status_info_t *amf_status_info);
amf_status_info_t *amf_status_info_parseFromJSON(cJSON *amf_status_infoJSON);
cJSON *amf_status_info_convertToJSON(amf_status_info_t *amf_status_info);
amf_status_info_t *amf_status_info_copy(amf_status_info_t	*dst,
                                        amf_status_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _amf_status_info_H_ */
