/*
 * qos_requirement.h
 *
 * Represents the QoS requirements.
 */

#ifndef _qos_requirement_H_
#define _qos_requirement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "device_type.h"
#include "qos_resource_type.h"
#include "velocity_estimate.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct qos_requirement_s qos_requirement_t;
typedef struct qos_requirement_s {
	bool is__5qi;
	int _5qi;
	char *gfbr_ul;
	char *gfbr_dl;
	struct qos_resource_type_s *res_type;
	bool is_pdb;
	int pdb;
	char *per;
	struct velocity_estimate_s *device_speed;
	struct device_type_s *device_type;
} qos_requirement_t;

qos_requirement_t *qos_requirement_create(bool is__5qi, int _5qi, char *gfbr_ul,
                                          char *gfbr_dl,
                                          qos_resource_type_t *res_type,
                                          bool is_pdb, int pdb, char *per,
                                          velocity_estimate_t *device_speed,
                                          device_type_t *device_type);
void qos_requirement_free(qos_requirement_t *qos_requirement);
qos_requirement_t *qos_requirement_parseFromJSON(cJSON *qos_requirementJSON);
cJSON *qos_requirement_convertToJSON(qos_requirement_t *qos_requirement);
qos_requirement_t *qos_requirement_copy(qos_requirement_t	*dst,
                                        qos_requirement_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _qos_requirement_H_ */
