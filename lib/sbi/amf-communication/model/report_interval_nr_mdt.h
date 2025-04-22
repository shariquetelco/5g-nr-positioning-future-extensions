/*
 * report_interval_nr_mdt.h
 *
 * The enumeration ReportIntervalNrMdt defines Report Interval in NR for MDT in the trace. See 3GPP TS 32.422 for further description of the values. It shall comply with the provisions defined in table 5.6.3.17-1.
 */

#ifndef _report_interval_nr_mdt_H_
#define _report_interval_nr_mdt_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "report_interval_nr_mdt_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct report_interval_nr_mdt_s report_interval_nr_mdt_t;
typedef struct report_interval_nr_mdt_s {} report_interval_nr_mdt_t;

report_interval_nr_mdt_t *report_interval_nr_mdt_create();
void report_interval_nr_mdt_free(
	report_interval_nr_mdt_t *report_interval_nr_mdt);
report_interval_nr_mdt_t *report_interval_nr_mdt_parseFromJSON(
	cJSON *report_interval_nr_mdtJSON);
cJSON *report_interval_nr_mdt_convertToJSON(
	report_interval_nr_mdt_t *report_interval_nr_mdt);
report_interval_nr_mdt_t *report_interval_nr_mdt_copy(
	report_interval_nr_mdt_t *dst, report_interval_nr_mdt_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _report_interval_nr_mdt_H_ */
