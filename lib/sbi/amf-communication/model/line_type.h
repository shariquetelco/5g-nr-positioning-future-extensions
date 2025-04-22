/*
 * line_type.h
 *
 * Possible values are: - DSL: Identifies a DSL line - PON: Identifies a PON line
 */

#ifndef _line_type_H_
#define _line_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "line_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct line_type_s line_type_t;
typedef struct line_type_s {} line_type_t;

line_type_t *line_type_create();
void line_type_free(line_type_t *line_type);
line_type_t *line_type_parseFromJSON(cJSON *line_typeJSON);
cJSON *line_type_convertToJSON(line_type_t *line_type);
line_type_t *line_type_copy(line_type_t *dst, line_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _line_type_H_ */
