/*
 * n2_information_transfer_result.h
 *
 *
 */

#ifndef _n2_information_transfer_result_H_
#define _n2_information_transfer_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { n2_information_transfer_result_NULL = 0,
	       n2_information_transfer_result_N2_INFO_TRANSFER_INITIATED }
n2_information_transfer_result_e;

char *n2_information_transfer_result_ToString(
	n2_information_transfer_result_e n2_information_transfer_result);

n2_information_transfer_result_e n2_information_transfer_result_FromString(
	char *n2_information_transfer_result);

#ifdef __cplusplus
}
#endif

#endif /* _n2_information_transfer_result_H_ */
