/*
 * suggested_pfd_info.h
 *
 * Represents the suggested PFD information for the application identifier.
 */

#ifndef _suggested_pfd_info_H_
#define _suggested_pfd_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "domain_name_protocol.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct suggested_pfd_info_s suggested_pfd_info_t;
typedef struct suggested_pfd_info_s {
	char *pfd_id;
	list_t *ip3_tuple_list;
	list_t *urls;
	list_t *domain_names;
	struct domain_name_protocol_s *dn_protocol;
	bool is_pfd_confidence;
	int pfd_confidence;
} suggested_pfd_info_t;

suggested_pfd_info_t *suggested_pfd_info_create(char *pfd_id,
                                                list_t *ip3_tuple_list,
                                                list_t *urls,
                                                list_t *domain_names,
                                                domain_name_protocol_t *dn_protocol, bool is_pfd_confidence, int pfd_confidence);
void suggested_pfd_info_free(suggested_pfd_info_t *suggested_pfd_info);
suggested_pfd_info_t *suggested_pfd_info_parseFromJSON(
	cJSON *suggested_pfd_infoJSON);
cJSON *suggested_pfd_info_convertToJSON(
	suggested_pfd_info_t *suggested_pfd_info);
suggested_pfd_info_t *suggested_pfd_info_copy(suggested_pfd_info_t	*dst,
                                              suggested_pfd_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _suggested_pfd_info_H_ */
