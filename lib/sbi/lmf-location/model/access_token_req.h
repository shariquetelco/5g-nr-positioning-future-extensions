/*
 * access_token_req.h
 *
 * Contains information related to the access token request
 */

#ifndef _access_token_req_H_
#define _access_token_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nf_type.h"
#include "plmn_id.h"
#include "plmn_id_nid.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct access_token_req_s access_token_req_t;
typedef enum { access_token_req_GRANTTYPE_NULL = 0,
	       access_token_req_GRANTTYPE_client_credentials }
access_token_req_grant_type_e;

char *access_token_req_grant_type_ToString(
	access_token_req_grant_type_e grant_type);

access_token_req_grant_type_e access_token_req_grant_type_FromString(
	char *grant_type);
typedef struct access_token_req_s {
	access_token_req_grant_type_e grant_type;
	char *nf_instance_id;
	struct nf_type_s *nf_type;
	struct nf_type_s *target_nf_type;
	char *scope;
	char *target_nf_instance_id;
	struct plmn_id_s *requester_plmn;
	list_t *requester_plmn_list;
	list_t *requester_snssai_list;
	char *requester_fqdn;
	list_t *requester_snpn_list;
	struct plmn_id_s *target_plmn;
	struct plmn_id_nid_s *target_snpn;
	list_t *target_snssai_list;
	list_t *target_nsi_list;
	char *target_nf_set_id;
	char *target_nf_service_set_id;
	char *hnrf_access_token_uri;
	char *source_nf_instance_id;
} access_token_req_t;

access_token_req_t *access_token_req_create(
	access_token_req_grant_type_e grant_type, char *nf_instance_id,
	nf_type_t *nf_type, nf_type_t *target_nf_type, char *scope,
	char *target_nf_instance_id, plmn_id_t *requester_plmn,
	list_t *requester_plmn_list, list_t *requester_snssai_list,
	char *requester_fqdn, list_t *requester_snpn_list,
	plmn_id_t *target_plmn, plmn_id_nid_t *target_snpn,
	list_t *target_snssai_list, list_t *target_nsi_list,
	char *target_nf_set_id, char *target_nf_service_set_id,
	char *hnrf_access_token_uri, char *source_nf_instance_id);
void access_token_req_free(access_token_req_t *access_token_req);
access_token_req_t *access_token_req_parseFromJSON(cJSON *access_token_reqJSON);
cJSON *access_token_req_convertToJSON(access_token_req_t *access_token_req);
access_token_req_t *access_token_req_copy(access_token_req_t	*dst,
                                          access_token_req_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _access_token_req_H_ */
