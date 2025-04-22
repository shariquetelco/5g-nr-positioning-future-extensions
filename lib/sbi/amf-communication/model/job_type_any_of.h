/*
 * job_type_any_of.h
 *
 *
 */

#ifndef _job_type_any_of_H_
#define _job_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { job_type_any_of_NULL = 0, job_type_any_of_IMMEDIATE_MDT_ONLY,
	       job_type_any_of_LOGGED_MDT_ONLY, job_type_any_of_TRACE_ONLY,
	       job_type_any_of_IMMEDIATE_MDT_AND_TRACE,
	       job_type_any_of_RLF_REPORTS_ONLY,
	       job_type_any_of_RCEF_REPORTS_ONLY,
	       job_type_any_of_LOGGED_MBSFN_MDT } job_type_any_of_e;

char *job_type_any_of_ToString(job_type_any_of_e job_type_any_of);

job_type_any_of_e job_type_any_of_FromString(char *job_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _job_type_any_of_H_ */
