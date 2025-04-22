/*
 * analytics_metadata_any_of.h
 *
 *
 */

#ifndef _analytics_metadata_any_of_H_
#define _analytics_metadata_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { analytics_metadata_any_of_NULL = 0,
	       analytics_metadata_any_of_NUM_OF_SAMPLES,
	       analytics_metadata_any_of_DATA_WINDOW,
	       analytics_metadata_any_of_DATA_STAT_PROPS,
	       analytics_metadata_any_of_STRATEGY,
	       analytics_metadata_any_of_ACCURACY } analytics_metadata_any_of_e;

char *analytics_metadata_any_of_ToString(
	analytics_metadata_any_of_e analytics_metadata_any_of);

analytics_metadata_any_of_e analytics_metadata_any_of_FromString(
	char *analytics_metadata_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _analytics_metadata_any_of_H_ */
