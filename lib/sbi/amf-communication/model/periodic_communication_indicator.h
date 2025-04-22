/*
 * periodic_communication_indicator.h
 *
 *
 */

#ifndef _periodic_communication_indicator_H_
#define _periodic_communication_indicator_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { periodic_communication_indicator_NULL = 0,
	       periodic_communication_indicator_PIORIODICALLY,
	       periodic_communication_indicator_ON_DEMAND }
periodic_communication_indicator_e;

char *periodic_communication_indicator_ToString(
	periodic_communication_indicator_e periodic_communication_indicator);

periodic_communication_indicator_e periodic_communication_indicator_FromString(
	char *periodic_communication_indicator);

#ifdef __cplusplus
}
#endif

#endif /* _periodic_communication_indicator_H_ */
