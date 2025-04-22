/*
 * abnormal_behaviour.h
 *
 * Represents the abnormal behaviour information.
 */

#ifndef _abnormal_behaviour_H_
#define _abnormal_behaviour_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "additional_measurement.h"
#include "exception.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct abnormal_behaviour_s abnormal_behaviour_t;
typedef struct abnormal_behaviour_s {
	list_t *supis;
	struct exception_s *excep;
	char *dnn;
	struct snssai_s *snssai;
	bool is_ratio;
	int ratio;
	bool is_confidence;
	int confidence;
	struct additional_measurement_s *addt_meas_info;
} abnormal_behaviour_t;

abnormal_behaviour_t *abnormal_behaviour_create(list_t *supis,
                                                exception_t *excep, char *dnn,
                                                snssai_t *snssai, bool is_ratio,
                                                int ratio, bool is_confidence,
                                                int confidence,
                                                additional_measurement_t *addt_meas_info);
void abnormal_behaviour_free(abnormal_behaviour_t *abnormal_behaviour);
abnormal_behaviour_t *abnormal_behaviour_parseFromJSON(
	cJSON *abnormal_behaviourJSON);
cJSON *abnormal_behaviour_convertToJSON(
	abnormal_behaviour_t *abnormal_behaviour);
abnormal_behaviour_t *abnormal_behaviour_copy(abnormal_behaviour_t	*dst,
                                              abnormal_behaviour_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _abnormal_behaviour_H_ */
