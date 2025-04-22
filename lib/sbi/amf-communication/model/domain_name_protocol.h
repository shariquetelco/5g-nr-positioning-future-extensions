/*
 * domain_name_protocol.h
 *
 * Represents the type of Domain Name Protocol.   Possible values are: - DNS_QNAME: Identifies the DNS protocol and the question name in DNS query. - TLS_SNI: Identifies the Server Name Indication in TLS ClientHello message. - TLS_SAN: Identifies the Subject Alternative Name in TLS ServerCertificate message. - TSL_SCN: Identifies the Subject Common Name in TLS ServerCertificate message.
 */

#ifndef _domain_name_protocol_H_
#define _domain_name_protocol_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "domain_name_protocol_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct domain_name_protocol_s domain_name_protocol_t;
typedef struct domain_name_protocol_s {} domain_name_protocol_t;

domain_name_protocol_t *domain_name_protocol_create();
void domain_name_protocol_free(domain_name_protocol_t *domain_name_protocol);
domain_name_protocol_t *domain_name_protocol_parseFromJSON(
	cJSON *domain_name_protocolJSON);
cJSON *domain_name_protocol_convertToJSON(
	domain_name_protocol_t *domain_name_protocol);
domain_name_protocol_t *domain_name_protocol_copy(
	domain_name_protocol_t	*dst,
	domain_name_protocol_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _domain_name_protocol_H_ */
