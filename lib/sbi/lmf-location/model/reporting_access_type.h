/*
 * reporting_access_type.h
 *
 *
 */

#ifndef _reporting_access_type_H_
#define _reporting_access_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { reporting_access_type_NULL = 0, reporting_access_type_NR,
	       reporting_access_type_EUTRA_CONNECTED_TO_5GC,
	       reporting_access_type_NON_3GPP_CONNECTED_TO_5GC,
	       reporting_access_type_NR_LEO, reporting_access_type_NR_MEO,
	       reporting_access_type_NR_GEO, reporting_access_type_NR_OTHER_SAT,
	       reporting_access_type_EUTRA_CONNECTED_TO_EPC }
reporting_access_type_e;

char *reporting_access_type_ToString(
	reporting_access_type_e reporting_access_type);

reporting_access_type_e reporting_access_type_FromString(
	char *reporting_access_type);

#ifdef __cplusplus
}
#endif

#endif /* _reporting_access_type_H_ */
