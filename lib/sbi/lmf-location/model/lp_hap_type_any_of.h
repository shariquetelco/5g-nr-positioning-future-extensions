/*
 * lp_hap_type_any_of.h
 *
 *
 */

#ifndef _lp_hap_type_any_of_H_
#define _lp_hap_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { lp_hap_type_any_of_NULL = 0,
	       lp_hap_type_any_of_LOW_POW_HIGH_ACCU_POS } lp_hap_type_any_of_e;

char *lp_hap_type_any_of_ToString(lp_hap_type_any_of_e lp_hap_type_any_of);

lp_hap_type_any_of_e lp_hap_type_any_of_FromString(char *lp_hap_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _lp_hap_type_any_of_H_ */
