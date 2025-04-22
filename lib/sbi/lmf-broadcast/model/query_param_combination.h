/*
 * query_param_combination.h
 *
 * Contains a list of Query Parameters
 */

#ifndef _query_param_combination_H_
#define _query_param_combination_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "query_parameter.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct query_param_combination_s query_param_combination_t;
typedef struct query_param_combination_s {
	list_t *query_params;
} query_param_combination_t;

query_param_combination_t *query_param_combination_create(list_t *query_params);
void query_param_combination_free(
	query_param_combination_t *query_param_combination);
query_param_combination_t *query_param_combination_parseFromJSON(
	cJSON *query_param_combinationJSON);
cJSON *query_param_combination_convertToJSON(
	query_param_combination_t *query_param_combination);
query_param_combination_t *query_param_combination_copy(
	query_param_combination_t *dst, query_param_combination_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _query_param_combination_H_ */
