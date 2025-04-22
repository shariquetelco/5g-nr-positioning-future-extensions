/*
 * lcs_qos_class.h
 *
 *
 */

#ifndef _lcs_qos_class_H_
#define _lcs_qos_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { lcs_qos_class_NULL = 0, lcs_qos_class_BEST_EFFORT,
	       lcs_qos_class_ASSURED,
	       lcs_qos_class_MULTIPLE_QOS } lcs_qos_class_e;

char *lcs_qos_class_ToString(lcs_qos_class_e lcs_qos_class);

lcs_qos_class_e lcs_qos_class_FromString(char *lcs_qos_class);

#ifdef __cplusplus
}
#endif

#endif /* _lcs_qos_class_H_ */
