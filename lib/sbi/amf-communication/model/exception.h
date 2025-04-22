/*
 * exception.h
 *
 * Represents the Exception information.
 */

#ifndef _exception_H_
#define _exception_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "exception_id.h"
#include "exception_trend.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct exception_s exception_t;
typedef struct exception_s {
	struct exception_id_s *excep_id;
	bool is_excep_level;
	int excep_level;
	struct exception_trend_s *excep_trend;
} exception_t;

exception_t *exception_create(exception_id_t *excep_id, bool is_excep_level,
                              int excep_level, exception_trend_t *excep_trend);
void exception_free(exception_t *exception);
exception_t *exception_parseFromJSON(cJSON *exceptionJSON);
cJSON *exception_convertToJSON(exception_t *exception);
exception_t *exception_copy(exception_t *dst, exception_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _exception_H_ */
