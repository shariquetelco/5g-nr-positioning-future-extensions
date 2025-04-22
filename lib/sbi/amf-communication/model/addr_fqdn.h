/*
 * addr_fqdn.h
 *
 * IP address and/or FQDN.
 */

#ifndef _addr_fqdn_H_
#define _addr_fqdn_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ip_addr.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct addr_fqdn_s addr_fqdn_t;
typedef struct addr_fqdn_s {
	struct ip_addr_s *ip_addr;
	char *fqdn;
} addr_fqdn_t;

addr_fqdn_t *addr_fqdn_create(ip_addr_t *ip_addr, char *fqdn);
void addr_fqdn_free(addr_fqdn_t *addr_fqdn);
addr_fqdn_t *addr_fqdn_parseFromJSON(cJSON *addr_fqdnJSON);
cJSON *addr_fqdn_convertToJSON(addr_fqdn_t *addr_fqdn);
addr_fqdn_t *addr_fqdn_copy(addr_fqdn_t *dst, addr_fqdn_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _addr_fqdn_H_ */
