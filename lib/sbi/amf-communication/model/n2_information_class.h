/*
 * n2_information_class.h
 *
 *
 */

#ifndef _n2_information_class_H_
#define _n2_information_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { n2_information_class_NULL = 0, n2_information_class_SM,
	       n2_information_class_NRPPa, n2_information_class_PWS,
	       n2_information_class_PWS_BCAL, n2_information_class_PWS_RF,
	       n2_information_class_RAN, n2_information_class_V2X,
	       n2_information_class_PROSE, n2_information_class_TSS,
	       n2_information_class_RSPP,
	       n2_information_class_A2X } n2_information_class_e;

char *n2_information_class_ToString(
	n2_information_class_e n2_information_class);

n2_information_class_e n2_information_class_FromString(
	char *n2_information_class);

#ifdef __cplusplus
}
#endif

#endif /* _n2_information_class_H_ */
