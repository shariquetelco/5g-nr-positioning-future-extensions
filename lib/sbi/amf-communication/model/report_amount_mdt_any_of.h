/*
 * report_amount_mdt_any_of.h
 *
 *
 */

#ifndef _report_amount_mdt_any_of_H_
#define _report_amount_mdt_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { report_amount_mdt_any_of_NULL = 0, report_amount_mdt_any_of__1,
	       report_amount_mdt_any_of__2, report_amount_mdt_any_of__4,
	       report_amount_mdt_any_of__8, report_amount_mdt_any_of__16,
	       report_amount_mdt_any_of__32, report_amount_mdt_any_of__64,
	       report_amount_mdt_any_of_infinity } report_amount_mdt_any_of_e;

char *report_amount_mdt_any_of_ToString(
	report_amount_mdt_any_of_e report_amount_mdt_any_of);

report_amount_mdt_any_of_e report_amount_mdt_any_of_FromString(
	char *report_amount_mdt_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _report_amount_mdt_any_of_H_ */
