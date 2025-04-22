/*
 * ip_address.h
 *
 *
 */

#ifndef _ip_address_H_
#define _ip_address_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ipv6_addr.h"
#include "ipv6_prefix.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ip_address_s ip_address_t;
typedef struct ip_address_s {
	char *ipv4_addr;
	struct ipv6_addr_s *ipv6_addr;
	struct ipv6_prefix_s *ipv6_prefix;
} ip_address_t;

ip_address_t *ip_address_create(char *ipv4_addr, ipv6_addr_t *ipv6_addr,
                                ipv6_prefix_t *ipv6_prefix);
void ip_address_free(ip_address_t *ip_address);
ip_address_t *ip_address_parseFromJSON(cJSON *ip_addressJSON);
cJSON *ip_address_convertToJSON(ip_address_t *ip_address);
ip_address_t *ip_address_copy(ip_address_t *dst, ip_address_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ip_address_H_ */
