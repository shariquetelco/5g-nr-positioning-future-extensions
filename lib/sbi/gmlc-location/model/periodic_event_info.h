/*
 * periodic_event_info.h
 *
 * Indicates the information of periodic event reporting.
 */

#ifndef _periodic_event_info_H_
#define _periodic_event_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct periodic_event_info_s periodic_event_info_t;
typedef enum { periodic_event_info_REPORTINGINFINITEIND_NULL = 0,
	       periodic_event_info_REPORTINGINFINITEIND__true }
periodic_event_info_reporting_infinite_ind_e;

char *periodic_event_info_reporting_infinite_ind_ToString(
	periodic_event_info_reporting_infinite_ind_e reporting_infinite_ind);

periodic_event_info_reporting_infinite_ind_e
periodic_event_info_reporting_infinite_ind_FromString(
	char *reporting_infinite_ind);
typedef struct periodic_event_info_s {
	int reporting_amount;
	int reporting_interval;
	periodic_event_info_reporting_infinite_ind_e reporting_infinite_ind;
	bool is_reporting_interval_ms;
	int reporting_interval_ms;
} periodic_event_info_t;

periodic_event_info_t *periodic_event_info_create(int reporting_amount,
                                                  int reporting_interval,
                                                  periodic_event_info_reporting_infinite_ind_e reporting_infinite_ind, bool is_reporting_interval_ms, int reporting_interval_ms);
void periodic_event_info_free(periodic_event_info_t *periodic_event_info);
periodic_event_info_t *periodic_event_info_parseFromJSON(
	cJSON *periodic_event_infoJSON);
cJSON *periodic_event_info_convertToJSON(
	periodic_event_info_t *periodic_event_info);
periodic_event_info_t *periodic_event_info_copy(periodic_event_info_t	*dst,
                                                periodic_event_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _periodic_event_info_H_ */
