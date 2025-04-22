/*
 * domain_name_protocol_any_of.h
 *
 *
 */

#ifndef _domain_name_protocol_any_of_H_
#define _domain_name_protocol_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { domain_name_protocol_any_of_NULL = 0,
	       domain_name_protocol_any_of_DNS_QNAME,
	       domain_name_protocol_any_of_TLS_SNI,
	       domain_name_protocol_any_of_TLS_SAN,
	       domain_name_protocol_any_of_TSL_SCN }
domain_name_protocol_any_of_e;

char *domain_name_protocol_any_of_ToString(
	domain_name_protocol_any_of_e domain_name_protocol_any_of);

domain_name_protocol_any_of_e domain_name_protocol_any_of_FromString(
	char *domain_name_protocol_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _domain_name_protocol_any_of_H_ */
