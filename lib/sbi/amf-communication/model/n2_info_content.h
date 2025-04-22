/*
 * n2_info_content.h
 *
 * Represents a transparent N2 information content to be relayed by AMF
 */

#ifndef _n2_info_content_H_
#define _n2_info_content_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ngap_ie_type.h"
#include "ref_to_binary_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n2_info_content_s n2_info_content_t;
typedef struct n2_info_content_s {
	bool is_ngap_message_type;
	int ngap_message_type;
	ngap_ie_type_e ngap_ie_type;
	struct ref_to_binary_data_s *ngap_data;
} n2_info_content_t;

n2_info_content_t *n2_info_content_create(
	bool			is_ngap_message_type,
	int			ngap_message_type,
	ngap_ie_type_e		ngap_ie_type,
	ref_to_binary_data_t	*ngap_data);
void n2_info_content_free(n2_info_content_t *n2_info_content);
n2_info_content_t *n2_info_content_parseFromJSON(cJSON *n2_info_contentJSON);
cJSON *n2_info_content_convertToJSON(n2_info_content_t *n2_info_content);
n2_info_content_t *n2_info_content_copy(n2_info_content_t	*dst,
                                        n2_info_content_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _n2_info_content_H_ */
