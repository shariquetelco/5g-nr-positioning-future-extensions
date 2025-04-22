/*
 * up_loc_rep_addr_af_rm.h
 *
 * Represents the user plane addressing information.
 */

#ifndef _up_loc_rep_addr_af_rm_H_
#define _up_loc_rep_addr_af_rm_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ipv6_addr.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct up_loc_rep_addr_af_rm_s up_loc_rep_addr_af_rm_t;
typedef struct up_loc_rep_addr_af_rm_s {
	list_t *ipv4_addrs;
	list_t *ipv6_addrs;
	char *fqdn;
} up_loc_rep_addr_af_rm_t;

up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm_create(list_t	*ipv4_addrs,
                                                      list_t	*ipv6_addrs,
                                                      char	*fqdn);
void up_loc_rep_addr_af_rm_free(up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm);
up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm_parseFromJSON(
	cJSON *up_loc_rep_addr_af_rmJSON);
cJSON *up_loc_rep_addr_af_rm_convertToJSON(
	up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm);
up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm_copy(
	up_loc_rep_addr_af_rm_t *dst, up_loc_rep_addr_af_rm_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _up_loc_rep_addr_af_rm_H_ */
