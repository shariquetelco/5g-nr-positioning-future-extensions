/*
 * report_amount_mdt.h
 *
 * The enumeration ReportAmountMdt defines Report Amount for MDT in the trace. See 3GPP TS 32.422 for further description of the values. It shall comply with the provisions defined in table 5.6.3.10-1.
 */

#ifndef _report_amount_mdt_H_
#define _report_amount_mdt_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "report_amount_mdt_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct report_amount_mdt_s report_amount_mdt_t;
typedef struct report_amount_mdt_s {} report_amount_mdt_t;

report_amount_mdt_t *report_amount_mdt_create();
void report_amount_mdt_free(report_amount_mdt_t *report_amount_mdt);
report_amount_mdt_t *report_amount_mdt_parseFromJSON(
	cJSON *report_amount_mdtJSON);
cJSON *report_amount_mdt_convertToJSON(report_amount_mdt_t *report_amount_mdt);
report_amount_mdt_t *report_amount_mdt_copy(report_amount_mdt_t *dst,
                                            report_amount_mdt_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _report_amount_mdt_H_ */
