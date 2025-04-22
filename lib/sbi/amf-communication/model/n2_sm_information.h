/*
 * n2_sm_information.h
 *
 * Represents the session management SMF related N2 information data part
 */

#ifndef _n2_sm_information_H_
#define _n2_sm_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_content.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n2_sm_information_s n2_sm_information_t;
typedef struct n2_sm_information_s {
	int pdu_session_id;
	struct n2_info_content_s *n2_info_content;
	struct snssai_s *s_nssai;
	struct snssai_s *home_plmn_snssai;
	struct snssai_s *iwk_snssai;
	bool is_subject_to_ho;
	int subject_to_ho;
} n2_sm_information_t;

n2_sm_information_t *n2_sm_information_create(int pdu_session_id,
                                              n2_info_content_t *n2_info_content, snssai_t *s_nssai, snssai_t *home_plmn_snssai, snssai_t *iwk_snssai, bool is_subject_to_ho, int subject_to_ho);
void n2_sm_information_free(n2_sm_information_t *n2_sm_information);
n2_sm_information_t *n2_sm_information_parseFromJSON(
	cJSON *n2_sm_informationJSON);
cJSON *n2_sm_information_convertToJSON(n2_sm_information_t *n2_sm_information);
n2_sm_information_t *n2_sm_information_copy(n2_sm_information_t *dst,
                                            n2_sm_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _n2_sm_information_H_ */
