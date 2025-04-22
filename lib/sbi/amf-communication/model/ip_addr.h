/*
 * ip_addr.h
 *
 * Contains an IP adresse.
 */

#ifndef _ip_addr_H_
#define _ip_addr_H_

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

typedef struct ip_addr_s ip_addr_t;
typedef struct ip_addr_s {
	char *ipv4_addr;
	struct ipv6_addr_s *ipv6_addr;
	struct ipv6_prefix_s *ipv6_prefix;
} ip_addr_t;

ip_addr_t *ip_addr_create(char *ipv4_addr, ipv6_addr_t *ipv6_addr,
                          ipv6_prefix_t *ipv6_prefix);
void ip_addr_free(ip_addr_t *ip_addr);
ip_addr_t *ip_addr_parseFromJSON(cJSON *ip_addrJSON);
cJSON *ip_addr_convertToJSON(ip_addr_t *ip_addr);
ip_addr_t *ip_addr_copy(ip_addr_t *dst, ip_addr_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ip_addr_H_ */
