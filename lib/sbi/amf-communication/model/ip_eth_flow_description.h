/*
 * ip_eth_flow_description.h
 *
 * Contains the description of an Uplink and/or Downlink Ethernet flow.
 */

#ifndef _ip_eth_flow_description_H_
#define _ip_eth_flow_description_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "eth_flow_description.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ip_eth_flow_description_s ip_eth_flow_description_t;
typedef struct ip_eth_flow_description_s {
	char *ip_traffic_filter;
	struct eth_flow_description_s *eth_traffic_filter;
} ip_eth_flow_description_t;

ip_eth_flow_description_t *ip_eth_flow_description_create(
	char *ip_traffic_filter, eth_flow_description_t *eth_traffic_filter);
void ip_eth_flow_description_free(
	ip_eth_flow_description_t *ip_eth_flow_description);
ip_eth_flow_description_t *ip_eth_flow_description_parseFromJSON(
	cJSON *ip_eth_flow_descriptionJSON);
cJSON *ip_eth_flow_description_convertToJSON(
	ip_eth_flow_description_t *ip_eth_flow_description);
ip_eth_flow_description_t *ip_eth_flow_description_copy(
	ip_eth_flow_description_t *dst, ip_eth_flow_description_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ip_eth_flow_description_H_ */
