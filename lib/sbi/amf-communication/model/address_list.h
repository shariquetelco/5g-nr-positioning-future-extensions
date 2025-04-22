/*
 * address_list.h
 *
 * Represents a list of IPv4 and/or IPv6 addresses.
 */

#ifndef _address_list_H_
#define _address_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ipv6_addr.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct address_list_s address_list_t;
typedef struct address_list_s {
	list_t *ipv4_addrs;
	list_t *ipv6_addrs;
} address_list_t;

address_list_t *address_list_create(list_t *ipv4_addrs, list_t *ipv6_addrs);
void address_list_free(address_list_t *address_list);
address_list_t *address_list_parseFromJSON(cJSON *address_listJSON);
cJSON *address_list_convertToJSON(address_list_t *address_list);
address_list_t *address_list_copy(address_list_t *dst, address_list_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _address_list_H_ */
