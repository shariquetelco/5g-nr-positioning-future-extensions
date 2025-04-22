/*
 * analytics_metadata_info.h
 *
 * Contains analytics metadata information required for analytics aggregation.
 */

#ifndef _analytics_metadata_info_H_
#define _analytics_metadata_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "accuracy.h"
#include "dataset_statistical_property.h"
#include "output_strategy.h"
#include "time_window.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct analytics_metadata_info_s analytics_metadata_info_t;
typedef struct analytics_metadata_info_s {
	bool is_num_samples;
	int num_samples;
	struct time_window_s *data_window;
	list_t *data_stat_props;
	struct output_strategy_s *strategy;
	struct accuracy_s *accuracy;
} analytics_metadata_info_t;

analytics_metadata_info_t *analytics_metadata_info_create(bool is_num_samples,
                                                          int num_samples,
                                                          time_window_t *data_window, list_t *data_stat_props, output_strategy_t *strategy, accuracy_t *accuracy);
void analytics_metadata_info_free(
	analytics_metadata_info_t *analytics_metadata_info);
analytics_metadata_info_t *analytics_metadata_info_parseFromJSON(
	cJSON *analytics_metadata_infoJSON);
cJSON *analytics_metadata_info_convertToJSON(
	analytics_metadata_info_t *analytics_metadata_info);
analytics_metadata_info_t *analytics_metadata_info_copy(
	analytics_metadata_info_t *dst, analytics_metadata_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _analytics_metadata_info_H_ */
