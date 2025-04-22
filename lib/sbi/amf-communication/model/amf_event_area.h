/*
 * amf_event_area.h
 *
 * Represents an area to be monitored by an AMF event
 */

#ifndef _amf_event_area_H_
#define _amf_event_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ladn_info.h"
#include "presence_info.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct amf_event_area_s amf_event_area_t;
typedef struct amf_event_area_s {
	struct presence_info_s *presence_info;
	struct ladn_info_s *ladn_info;
	struct snssai_s *s_nssai;
	char *nsi_id;
} amf_event_area_t;

amf_event_area_t *amf_event_area_create(presence_info_t *presence_info,
                                        ladn_info_t *ladn_info,
                                        snssai_t *s_nssai, char *nsi_id);
void amf_event_area_free(amf_event_area_t *amf_event_area);
amf_event_area_t *amf_event_area_parseFromJSON(cJSON *amf_event_areaJSON);
cJSON *amf_event_area_convertToJSON(amf_event_area_t *amf_event_area);
amf_event_area_t *amf_event_area_copy(amf_event_area_t	*dst,
                                      amf_event_area_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _amf_event_area_H_ */
