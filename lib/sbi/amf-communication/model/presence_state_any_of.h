/*
 * presence_state_any_of.h
 *
 *
 */

#ifndef _presence_state_any_of_H_
#define _presence_state_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { presence_state_any_of_NULL = 0, presence_state_any_of_IN_AREA,
	       presence_state_any_of_OUT_OF_AREA, presence_state_any_of_UNKNOWN,
	       presence_state_any_of_INACTIVE } presence_state_any_of_e;

char *presence_state_any_of_ToString(
	presence_state_any_of_e presence_state_any_of);

presence_state_any_of_e presence_state_any_of_FromString(
	char *presence_state_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _presence_state_any_of_H_ */
