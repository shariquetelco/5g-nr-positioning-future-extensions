/*
 * eth_flow_description.h
 *
 * Identifies an Ethernet flow.
 */

#ifndef _eth_flow_description_H_
#define _eth_flow_description_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "flow_direction.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct eth_flow_description_s eth_flow_description_t;
typedef struct eth_flow_description_s {
	char *dest_mac_addr;
	char *eth_type;
	char *f_desc;
	struct flow_direction_s *f_dir;
	char *source_mac_addr;
	list_t *vlan_tags;
	char *src_mac_addr_end;
	char *dest_mac_addr_end;
} eth_flow_description_t;

eth_flow_description_t *eth_flow_description_create(
	char			*dest_mac_addr,
	char			*eth_type,
	char			*f_desc,
	flow_direction_t	*f_dir,
	char			*source_mac_addr,
	list_t			*vlan_tags,
	char			*src_mac_addr_end,
	char			*dest_mac_addr_end);
void eth_flow_description_free(eth_flow_description_t *eth_flow_description);
eth_flow_description_t *eth_flow_description_parseFromJSON(
	cJSON *eth_flow_descriptionJSON);
cJSON *eth_flow_description_convertToJSON(
	eth_flow_description_t *eth_flow_description);
eth_flow_description_t *eth_flow_description_copy(
	eth_flow_description_t	*dst,
	eth_flow_description_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _eth_flow_description_H_ */
