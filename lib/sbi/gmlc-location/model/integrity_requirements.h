/*
 * integrity_requirements.h
 *
 * integrity requirements.
 */

#ifndef _integrity_requirements_H_
#define _integrity_requirements_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "alert_limit.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct integrity_requirements_s integrity_requirements_t;
typedef struct integrity_requirements_s {
	bool is_time_to_alert;
	int time_to_alert;
	bool is_target_integrity_risk;
	int target_integrity_risk;
	struct alert_limit_s *alert_limit;
} integrity_requirements_t;

integrity_requirements_t *integrity_requirements_create(bool is_time_to_alert,
                                                        int time_to_alert,
                                                        bool is_target_integrity_risk, int target_integrity_risk, alert_limit_t *alert_limit);
void integrity_requirements_free(
	integrity_requirements_t *integrity_requirements);
integrity_requirements_t *integrity_requirements_parseFromJSON(
	cJSON *integrity_requirementsJSON);
cJSON *integrity_requirements_convertToJSON(
	integrity_requirements_t *integrity_requirements);
integrity_requirements_t *integrity_requirements_copy(
	integrity_requirements_t *dst, integrity_requirements_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _integrity_requirements_H_ */
