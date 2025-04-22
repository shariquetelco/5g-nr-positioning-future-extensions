/*
 * line_type_any_of.h
 *
 *
 */

#ifndef _line_type_any_of_H_
#define _line_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { line_type_any_of_NULL = 0, line_type_any_of_DSL,
	       line_type_any_of_PON } line_type_any_of_e;

char *line_type_any_of_ToString(line_type_any_of_e line_type_any_of);

line_type_any_of_e line_type_any_of_FromString(char *line_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _line_type_any_of_H_ */
