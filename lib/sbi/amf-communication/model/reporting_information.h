/*
 * reporting_information.h
 *
 * Represents the type of reporting that the subscription requires.
 */

#ifndef _reporting_information_H_
#define _reporting_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "muting_exception_instructions.h"
#include "muting_notifications_settings.h"
#include "notification_flag.h"
#include "notification_method_1.h"
#include "partitioning_criteria.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct reporting_information_s reporting_information_t;
typedef struct reporting_information_s {
	bool is_imm_rep;
	int imm_rep;
	struct notification_method_1_s *notif_method;
	bool is_max_report_nbr;
	int max_report_nbr;
	char *mon_dur;
	bool is_rep_period;
	int rep_period;
	bool is_samp_ratio;
	int samp_ratio;
	list_t *partition_criteria;
	bool is_grp_rep_time;
	int grp_rep_time;
	struct notification_flag_s *notif_flag;
	struct muting_exception_instructions_s *notif_flag_instruct;
	struct muting_notifications_settings_s *muting_setting;
} reporting_information_t;

reporting_information_t *reporting_information_create(bool is_imm_rep,
                                                      int imm_rep,
                                                      notification_method_1_t *notif_method, bool is_max_report_nbr, int max_report_nbr, char *mon_dur, bool is_rep_period, int rep_period, bool is_samp_ratio, int samp_ratio, list_t *partition_criteria, bool is_grp_rep_time, int grp_rep_time, notification_flag_t *notif_flag, muting_exception_instructions_t *notif_flag_instruct, muting_notifications_settings_t *muting_setting);
void reporting_information_free(reporting_information_t *reporting_information);
reporting_information_t *reporting_information_parseFromJSON(
	cJSON *reporting_informationJSON);
cJSON *reporting_information_convertToJSON(
	reporting_information_t *reporting_information);
reporting_information_t *reporting_information_copy(
	reporting_information_t *dst, reporting_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _reporting_information_H_ */
