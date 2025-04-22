/*
 * qos_resource_type.h
 *
 * The enumeration QosResourceType indicates whether a QoS Flow is non-GBR, delay critical GBR, or non-delay critical GBR (see clauses 5.7.3.4 and 5.7.3.5 of 3GPP TS 23.501). It shall comply with the provisions defined in table 5.5.3.6-1.
 */

#ifndef _qos_resource_type_H_
#define _qos_resource_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "qos_resource_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct qos_resource_type_s qos_resource_type_t;
typedef struct qos_resource_type_s {} qos_resource_type_t;

qos_resource_type_t *qos_resource_type_create();
void qos_resource_type_free(qos_resource_type_t *qos_resource_type);
qos_resource_type_t *qos_resource_type_parseFromJSON(
	cJSON *qos_resource_typeJSON);
cJSON *qos_resource_type_convertToJSON(qos_resource_type_t *qos_resource_type);
qos_resource_type_t *qos_resource_type_copy(qos_resource_type_t *dst,
                                            qos_resource_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _qos_resource_type_H_ */
