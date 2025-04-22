/*
 * ue_privacy_requirements.h
 *
 * UE privacy requirements from (H)GMLC to the serving AMF or VGMLC(in the roaming case) for the target UE
 */

#ifndef _ue_privacy_requirements_H_
#define _ue_privacy_requirements_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "lcs_service_auth.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_privacy_requirements_s ue_privacy_requirements_t;
typedef struct ue_privacy_requirements_s {
	struct lcs_service_auth_s *lcs_service_auth_info;
	bool is_code_word_check;
	int code_word_check;
} ue_privacy_requirements_t;

ue_privacy_requirements_t *ue_privacy_requirements_create(
	lcs_service_auth_t *lcs_service_auth_info, bool is_code_word_check,
	int code_word_check);
void ue_privacy_requirements_free(
	ue_privacy_requirements_t *ue_privacy_requirements);
ue_privacy_requirements_t *ue_privacy_requirements_parseFromJSON(
	cJSON *ue_privacy_requirementsJSON);
cJSON *ue_privacy_requirements_convertToJSON(
	ue_privacy_requirements_t *ue_privacy_requirements);
ue_privacy_requirements_t *ue_privacy_requirements_copy(
	ue_privacy_requirements_t *dst, ue_privacy_requirements_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_privacy_requirements_H_ */
