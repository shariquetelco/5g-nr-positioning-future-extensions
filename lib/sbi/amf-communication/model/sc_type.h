/*
 * sc_type.h
 *
 *
 */

#ifndef _sc_type_H_
#define _sc_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { sc_type_NULL = 0, sc_type_NATIVE, sc_type_MAPPED } sc_type_e;

char *sc_type_ToString(sc_type_e sc_type);

sc_type_e sc_type_FromString(char *sc_type);

#ifdef __cplusplus
}
#endif

#endif /* _sc_type_H_ */
