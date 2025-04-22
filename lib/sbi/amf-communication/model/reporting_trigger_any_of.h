/*
 * reporting_trigger_any_of.h
 *
 *
 */

#ifndef _reporting_trigger_any_of_H_
#define _reporting_trigger_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { reporting_trigger_any_of_NULL = 0,
	       reporting_trigger_any_of_PERIODICAL,
	       reporting_trigger_any_of_EVENT_A2,
	       reporting_trigger_any_of_EVENT_A2_PERIODIC,
	       reporting_trigger_any_of_ALL_RRM_EVENT_TRIGGERS }
reporting_trigger_any_of_e;

char *reporting_trigger_any_of_ToString(
	reporting_trigger_any_of_e reporting_trigger_any_of);

reporting_trigger_any_of_e reporting_trigger_any_of_FromString(
	char *reporting_trigger_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _reporting_trigger_any_of_H_ */
