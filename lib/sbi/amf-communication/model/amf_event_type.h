/*
 * amf_event_type.h
 *
 * Describes the supported event types of Namf_EventExposure Service
 */

#ifndef _amf_event_type_H_
#define _amf_event_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "amf_event_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct amf_event_type_s amf_event_type_t;
typedef struct amf_event_type_s {} amf_event_type_t;

amf_event_type_t *amf_event_type_create();
void amf_event_type_free(amf_event_type_t *amf_event_type);
amf_event_type_t *amf_event_type_parseFromJSON(cJSON *amf_event_typeJSON);
cJSON *amf_event_type_convertToJSON(amf_event_type_t *amf_event_type);
amf_event_type_t *amf_event_type_copy(amf_event_type_t	*dst,
                                      amf_event_type_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _amf_event_type_H_ */
