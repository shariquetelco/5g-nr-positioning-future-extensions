/*
 * report_interval_nr_mdt_any_of.h
 *
 *
 */

#ifndef _report_interval_nr_mdt_any_of_H_
#define _report_interval_nr_mdt_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { report_interval_nr_mdt_any_of_NULL = 0,
	       report_interval_nr_mdt_any_of__120,
	       report_interval_nr_mdt_any_of__240,
	       report_interval_nr_mdt_any_of__480,
	       report_interval_nr_mdt_any_of__640,
	       report_interval_nr_mdt_any_of__1024,
	       report_interval_nr_mdt_any_of__2048,
	       report_interval_nr_mdt_any_of__5120,
	       report_interval_nr_mdt_any_of__10240,
	       report_interval_nr_mdt_any_of__20480,
	       report_interval_nr_mdt_any_of__40960,
	       report_interval_nr_mdt_any_of__60000,
	       report_interval_nr_mdt_any_of__360000,
	       report_interval_nr_mdt_any_of__720000,
	       report_interval_nr_mdt_any_of__1800000,
	       report_interval_nr_mdt_any_of__3600000 }
report_interval_nr_mdt_any_of_e;

char *report_interval_nr_mdt_any_of_ToString(
	report_interval_nr_mdt_any_of_e report_interval_nr_mdt_any_of);

report_interval_nr_mdt_any_of_e report_interval_nr_mdt_any_of_FromString(
	char *report_interval_nr_mdt_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _report_interval_nr_mdt_any_of_H_ */
