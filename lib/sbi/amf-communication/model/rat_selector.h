/*
 * rat_selector.h
 *
 *
 */

#ifndef _rat_selector_H_
#define _rat_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { rat_selector_NULL = 0, rat_selector_E_UTRA,
	       rat_selector_NR } rat_selector_e;

char *rat_selector_ToString(rat_selector_e rat_selector);

rat_selector_e rat_selector_FromString(char *rat_selector);

#ifdef __cplusplus
}
#endif

#endif /* _rat_selector_H_ */
