/*
 * analytics_metadata_indication.h
 *
 * Contains analytics metadata information requested to be used during analytics generation.
 */

#ifndef _analytics_metadata_indication_H_
#define _analytics_metadata_indication_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "dataset_statistical_property.h"
#include "output_strategy.h"
#include "time_window.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct analytics_metadata_indication_s analytics_metadata_indication_t;
typedef struct analytics_metadata_indication_s {
	struct time_window_s *data_window;
	list_t *data_stat_props;
	struct output_strategy_s *strategy;
	list_t *aggr_nwdaf_ids;
} analytics_metadata_indication_t;

analytics_metadata_indication_t *analytics_metadata_indication_create(
	time_window_t *data_window, list_t *data_stat_props,
	output_strategy_t *strategy, list_t *aggr_nwdaf_ids);
void analytics_metadata_indication_free(
	analytics_metadata_indication_t *analytics_metadata_indication);
analytics_metadata_indication_t *analytics_metadata_indication_parseFromJSON(
	cJSON *analytics_metadata_indicationJSON);
cJSON *analytics_metadata_indication_convertToJSON(
	analytics_metadata_indication_t *analytics_metadata_indication);
analytics_metadata_indication_t *analytics_metadata_indication_copy(
	analytics_metadata_indication_t *dst,
	analytics_metadata_indication_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _analytics_metadata_indication_H_ */
