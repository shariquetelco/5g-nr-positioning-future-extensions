/*
 * event_reporting_requirement.h
 *
 * Represents the type of reporting that the subscription requires.
 */

#ifndef _event_reporting_requirement_H_
#define _event_reporting_requirement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "accuracy.h"
#include "analytics_metadata.h"
#include "analytics_metadata_indication.h"
#include "time_window.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct event_reporting_requirement_s event_reporting_requirement_t;
typedef struct event_reporting_requirement_s {
	struct accuracy_s *accuracy;
	list_t *acc_per_subset;
	char *start_ts;
	char *end_ts;
	bool is_offset_period;
	int offset_period;
	bool is_samp_ratio;
	int samp_ratio;
	bool is_max_object_nbr;
	int max_object_nbr;
	bool is_max_supi_nbr;
	int max_supi_nbr;
	char *time_ana_needed;
	list_t *ana_meta;
	struct analytics_metadata_indication_s *ana_meta_ind;
	struct time_window_s *hist_ana_time_period;
} event_reporting_requirement_t;

event_reporting_requirement_t *event_reporting_requirement_create(
	accuracy_t *accuracy, list_t *acc_per_subset, char *start_ts,
	char *end_ts, bool is_offset_period, int offset_period,
	bool is_samp_ratio, int samp_ratio, bool is_max_object_nbr,
	int max_object_nbr, bool is_max_supi_nbr, int max_supi_nbr,
	char *time_ana_needed, list_t *ana_meta,
	analytics_metadata_indication_t *ana_meta_ind,
	time_window_t *hist_ana_time_period);
void event_reporting_requirement_free(
	event_reporting_requirement_t *event_reporting_requirement);
event_reporting_requirement_t *event_reporting_requirement_parseFromJSON(
	cJSON *event_reporting_requirementJSON);
cJSON *event_reporting_requirement_convertToJSON(
	event_reporting_requirement_t *event_reporting_requirement);
event_reporting_requirement_t *event_reporting_requirement_copy(
	event_reporting_requirement_t *dst, event_reporting_requirement_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _event_reporting_requirement_H_ */
