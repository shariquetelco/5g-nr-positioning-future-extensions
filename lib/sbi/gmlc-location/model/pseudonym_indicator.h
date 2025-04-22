/*
 * pseudonym_indicator.h
 *
 *
 */

#ifndef _pseudonym_indicator_H_
#define _pseudonym_indicator_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { pseudonym_indicator_NULL = 0,
	       pseudonym_indicator_PSEUDONYM_REQUESTED,
	       pseudonym_indicator_PSEUDONYM_NOT_REQUESTED }
pseudonym_indicator_e;

char *pseudonym_indicator_ToString(pseudonym_indicator_e pseudonym_indicator);

pseudonym_indicator_e pseudonym_indicator_FromString(char *pseudonym_indicator);

#ifdef __cplusplus
}
#endif

#endif /* _pseudonym_indicator_H_ */
