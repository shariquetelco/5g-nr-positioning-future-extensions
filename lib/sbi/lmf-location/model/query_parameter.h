/*
 * query_parameter.h
 *
 * Contains the name and value of a query parameter
 */

#ifndef _query_parameter_H_
#define _query_parameter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct query_parameter_s query_parameter_t;
typedef struct query_parameter_s {
	char *name;
	char *value;
} query_parameter_t;

query_parameter_t *query_parameter_create(char *name, char *value);
void query_parameter_free(query_parameter_t *query_parameter);
query_parameter_t *query_parameter_parseFromJSON(cJSON *query_parameterJSON);
cJSON *query_parameter_convertToJSON(query_parameter_t *query_parameter);
query_parameter_t *query_parameter_copy(query_parameter_t	*dst,
                                        query_parameter_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _query_parameter_H_ */
