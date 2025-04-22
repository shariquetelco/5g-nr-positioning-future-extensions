/*
 * n1_message_class.h
 *
 *
 */

#ifndef _n1_message_class_H_
#define _n1_message_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { n1_message_class_NULL = 0, n1_message_class_5GMM,
	       n1_message_class_SM, n1_message_class_LPP, n1_message_class_SMS,
	       n1_message_class_UPDP, n1_message_class_LCS,
	       n1_message_class_UPP_CM } n1_message_class_e;

char *n1_message_class_ToString(n1_message_class_e n1_message_class);

n1_message_class_e n1_message_class_FromString(char *n1_message_class);

#ifdef __cplusplus
}
#endif

#endif /* _n1_message_class_H_ */
