/*
 * transfer_reason.h
 *
 *
 */

#ifndef _transfer_reason_H_
#define _transfer_reason_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { transfer_reason_NULL = 0, transfer_reason_INIT_REG,
	       transfer_reason_MOBI_REG,
	       transfer_reason_MOBI_REG_UE_VALIDATED } transfer_reason_e;

char *transfer_reason_ToString(transfer_reason_e transfer_reason);

transfer_reason_e transfer_reason_FromString(char *transfer_reason);

#ifdef __cplusplus
}
#endif

#endif /* _transfer_reason_H_ */
