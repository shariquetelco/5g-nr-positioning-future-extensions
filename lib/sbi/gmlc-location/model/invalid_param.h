/*
 * invalid_param.h
 *
 * It contains an invalid parameter and a related description.
 */

#ifndef _invalid_param_H_
#define _invalid_param_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct invalid_param_s invalid_param_t;
typedef struct invalid_param_s {
	char *param;
	char *reason;
} invalid_param_t;

invalid_param_t *invalid_param_create(char *param, char *reason);
void invalid_param_free(invalid_param_t *invalid_param);
invalid_param_t *invalid_param_parseFromJSON(cJSON *invalid_paramJSON);
cJSON *invalid_param_convertToJSON(invalid_param_t *invalid_param);
invalid_param_t *invalid_param_copy(invalid_param_t *dst, invalid_param_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _invalid_param_H_ */
