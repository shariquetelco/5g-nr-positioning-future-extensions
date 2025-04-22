/*
 * reporting_ind_any_of.h
 *
 *
 */

#ifndef _reporting_ind_any_of_H_
#define _reporting_ind_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { reporting_ind_any_of_NULL = 0,
	       reporting_ind_any_of_INSIDE_REPORTING,
	       reporting_ind_any_of_OUTSIDE_REPORTING } reporting_ind_any_of_e;

char *reporting_ind_any_of_ToString(
	reporting_ind_any_of_e reporting_ind_any_of);

reporting_ind_any_of_e reporting_ind_any_of_FromString(
	char *reporting_ind_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _reporting_ind_any_of_H_ */
