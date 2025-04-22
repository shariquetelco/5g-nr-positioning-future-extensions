/*
 * analytics_metadata.h
 *
 * Represents the types of analytics metadata information that can be requested.   Possible values are: - NUM_OF_SAMPLES: Number of data samples used for the generation of the output analytics. - DATA_WINDOW: Data time window of the data samples. - DATA_STAT_PROPS: Dataset statistical properties of the data used to generate the   analytics. - STRATEGY: Output strategy used for the reporting of the analytics. - ACCURACY: Level of accuracy reached for the analytics.
 */

#ifndef _analytics_metadata_H_
#define _analytics_metadata_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "analytics_metadata_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct analytics_metadata_s analytics_metadata_t;
typedef struct analytics_metadata_s {} analytics_metadata_t;

analytics_metadata_t *analytics_metadata_create();
void analytics_metadata_free(analytics_metadata_t *analytics_metadata);
analytics_metadata_t *analytics_metadata_parseFromJSON(
	cJSON *analytics_metadataJSON);
cJSON *analytics_metadata_convertToJSON(
	analytics_metadata_t *analytics_metadata);
analytics_metadata_t *analytics_metadata_copy(analytics_metadata_t	*dst,
                                              analytics_metadata_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _analytics_metadata_H_ */
