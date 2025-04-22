/*
 * storage_outcome.h
 *
 *
 */

#ifndef _storage_outcome_H_
#define _storage_outcome_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { storage_outcome_NULL = 0, storage_outcome_STORAGE_SUCCESSFUL,
	       storage_outcome_STORAGE_FAILED } storage_outcome_e;

char *storage_outcome_ToString(storage_outcome_e storage_outcome);

storage_outcome_e storage_outcome_FromString(char *storage_outcome);

#ifdef __cplusplus
}
#endif

#endif /* _storage_outcome_H_ */
