/*
 * ddd_traffic_descriptor.h
 *
 * Contains a Traffic Descriptor.
 */

#ifndef _ddd_traffic_descriptor_H_
#define _ddd_traffic_descriptor_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ipv6_addr.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ddd_traffic_descriptor_s ddd_traffic_descriptor_t;
typedef struct ddd_traffic_descriptor_s {
	char *ipv4_addr;
	struct ipv6_addr_s *ipv6_addr;
	bool is_port_number;
	int port_number;
	char *mac_addr;
} ddd_traffic_descriptor_t;

ddd_traffic_descriptor_t *ddd_traffic_descriptor_create(
	char		*ipv4_addr,
	ipv6_addr_t	*ipv6_addr,
	bool		is_port_number,
	int		port_number,
	char		*mac_addr);
void ddd_traffic_descriptor_free(
	ddd_traffic_descriptor_t *ddd_traffic_descriptor);
ddd_traffic_descriptor_t *ddd_traffic_descriptor_parseFromJSON(
	cJSON *ddd_traffic_descriptorJSON);
cJSON *ddd_traffic_descriptor_convertToJSON(
	ddd_traffic_descriptor_t *ddd_traffic_descriptor);
ddd_traffic_descriptor_t *ddd_traffic_descriptor_copy(
	ddd_traffic_descriptor_t *dst, ddd_traffic_descriptor_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ddd_traffic_descriptor_H_ */
