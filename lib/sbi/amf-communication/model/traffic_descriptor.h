/*
 * traffic_descriptor.h
 *
 * Represents the Traffic Descriptor
 */

#ifndef _traffic_descriptor_H_
#define _traffic_descriptor_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ddd_traffic_descriptor.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct traffic_descriptor_s traffic_descriptor_t;
typedef struct traffic_descriptor_s {
	char *dnn;
	struct snssai_s *s_nssai;
	list_t *ddd_traffic_descriptor_list;
} traffic_descriptor_t;

traffic_descriptor_t *traffic_descriptor_create(char *dnn, snssai_t *s_nssai,
                                                list_t *ddd_traffic_descriptor_list);
void traffic_descriptor_free(traffic_descriptor_t *traffic_descriptor);
traffic_descriptor_t *traffic_descriptor_parseFromJSON(
	cJSON *traffic_descriptorJSON);
cJSON *traffic_descriptor_convertToJSON(
	traffic_descriptor_t *traffic_descriptor);
traffic_descriptor_t *traffic_descriptor_copy(traffic_descriptor_t	*dst,
                                              traffic_descriptor_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _traffic_descriptor_H_ */
