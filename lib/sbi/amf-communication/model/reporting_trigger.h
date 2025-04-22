/*
 * reporting_trigger.h
 *
 * The enumeration ReportingTrigger defines Reporting Triggers for MDT in the trace. See 3GPP TS 32.42] for further  description of the values. It shall comply with the provisions defined in table 5.6.3.8-1.
 */

#ifndef _reporting_trigger_H_
#define _reporting_trigger_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "reporting_trigger_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct reporting_trigger_s reporting_trigger_t;
typedef struct reporting_trigger_s {} reporting_trigger_t;

reporting_trigger_t *reporting_trigger_create();
void reporting_trigger_free(reporting_trigger_t *reporting_trigger);
reporting_trigger_t *reporting_trigger_parseFromJSON(
	cJSON *reporting_triggerJSON);
cJSON *reporting_trigger_convertToJSON(reporting_trigger_t *reporting_trigger);
reporting_trigger_t *reporting_trigger_copy(reporting_trigger_t *dst,
                                            reporting_trigger_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _reporting_trigger_H_ */
