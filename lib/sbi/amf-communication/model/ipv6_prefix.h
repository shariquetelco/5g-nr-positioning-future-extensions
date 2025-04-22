/*
 * ipv6_prefix.h
 *
 * String identifying an IPv6 address prefix formatted according to clause 4 of RFC 5952. IPv6Prefix data type may contain an individual /128 IPv6 address.
 */

#ifndef _ipv6_prefix_H_
#define _ipv6_prefix_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ipv6_prefix_s ipv6_prefix_t;
typedef struct ipv6_prefix_s {} ipv6_prefix_t;

ipv6_prefix_t *ipv6_prefix_create();
void ipv6_prefix_free(ipv6_prefix_t *ipv6_prefix);
ipv6_prefix_t *ipv6_prefix_parseFromJSON(cJSON *ipv6_prefixJSON);
cJSON *ipv6_prefix_convertToJSON(ipv6_prefix_t *ipv6_prefix);
ipv6_prefix_t *ipv6_prefix_copy(ipv6_prefix_t *dst, ipv6_prefix_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ipv6_prefix_H_ */
