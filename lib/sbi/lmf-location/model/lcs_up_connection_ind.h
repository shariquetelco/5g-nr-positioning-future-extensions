/*
 * lcs_up_connection_ind.h
 *
 *
 */

#ifndef _lcs_up_connection_ind_H_
#define _lcs_up_connection_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { lcs_up_connection_ind_NULL = 0,
	       lcs_up_connection_ind_TERMINATION,
	       lcs_up_connection_ind_SETUP } lcs_up_connection_ind_e;

char *lcs_up_connection_ind_ToString(
	lcs_up_connection_ind_e lcs_up_connection_ind);

lcs_up_connection_ind_e lcs_up_connection_ind_FromString(
	char *lcs_up_connection_ind);

#ifdef __cplusplus
}
#endif

#endif /* _lcs_up_connection_ind_H_ */
