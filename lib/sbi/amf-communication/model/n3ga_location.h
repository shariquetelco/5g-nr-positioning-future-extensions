/*
 * n3ga_location.h
 *
 * Contains the Non-3GPP access user location.
 */

#ifndef _n3ga_location_H_
#define _n3ga_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "hfc_node_id.h"
#include "ipv6_addr.h"
#include "line_type.h"
#include "tai.h"
#include "tnap_id.h"
#include "transport_protocol.h"
#include "twap_id.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n3ga_location_s n3ga_location_t;
typedef struct n3ga_location_s {
	struct tai_s *n3gpp_tai;
	char *n3_iwf_id;
	char *ue_ipv4_addr;
	struct ipv6_addr_s *ue_ipv6_addr;
	bool is_port_number;
	int port_number;
	struct transport_protocol_s *protocol;
	struct tnap_id_s *tnap_id;
	struct twap_id_s *twap_id;
	struct hfc_node_id_s *hfc_node_id;
	char *gli;
	struct line_type_s *w5gban_line_type;
	char *gci;
} n3ga_location_t;

n3ga_location_t *n3ga_location_create(tai_t *n3gpp_tai, char *n3_iwf_id,
                                      char *ue_ipv4_addr,
                                      ipv6_addr_t *ue_ipv6_addr,
                                      bool is_port_number, int port_number,
                                      transport_protocol_t *protocol,
                                      tnap_id_t *tnap_id, twap_id_t *twap_id,
                                      hfc_node_id_t *hfc_node_id, char *gli,
                                      line_type_t *w5gban_line_type, char *gci);
void n3ga_location_free(n3ga_location_t *n3ga_location);
n3ga_location_t *n3ga_location_parseFromJSON(cJSON *n3ga_locationJSON);
cJSON *n3ga_location_convertToJSON(n3ga_location_t *n3ga_location);
n3ga_location_t *n3ga_location_copy(n3ga_location_t *dst, n3ga_location_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _n3ga_location_H_ */
