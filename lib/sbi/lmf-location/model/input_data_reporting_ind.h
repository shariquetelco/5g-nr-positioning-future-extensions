/*
 * input_data_reporting_ind.h
 *
 *
 */

#ifndef _input_data_reporting_ind_H_
#define _input_data_reporting_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct input_data_reporting_ind_s input_data_reporting_ind_t;
typedef struct input_data_reporting_ind_s {} input_data_reporting_ind_t;

input_data_reporting_ind_t *input_data_reporting_ind_create();
void input_data_reporting_ind_free(
	input_data_reporting_ind_t *input_data_reporting_ind);
input_data_reporting_ind_t *input_data_reporting_ind_parseFromJSON(
	cJSON *input_data_reporting_indJSON);
cJSON *input_data_reporting_ind_convertToJSON(
	input_data_reporting_ind_t *input_data_reporting_ind);
input_data_reporting_ind_t *input_data_reporting_ind_copy(
	input_data_reporting_ind_t *dst, input_data_reporting_ind_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _input_data_reporting_ind_H_ */
