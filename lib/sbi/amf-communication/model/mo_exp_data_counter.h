/*
 * mo_exp_data_counter.h
 *
 * Contain the MO Exception Data Counter.
 */

#ifndef _mo_exp_data_counter_H_
#define _mo_exp_data_counter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mo_exp_data_counter_s mo_exp_data_counter_t;
typedef struct mo_exp_data_counter_s {
	int counter;
	char *time_stamp;
} mo_exp_data_counter_t;

mo_exp_data_counter_t *mo_exp_data_counter_create(int	counter,
                                                  char	*time_stamp);
void mo_exp_data_counter_free(mo_exp_data_counter_t *mo_exp_data_counter);
mo_exp_data_counter_t *mo_exp_data_counter_parseFromJSON(
	cJSON *mo_exp_data_counterJSON);
cJSON *mo_exp_data_counter_convertToJSON(
	mo_exp_data_counter_t *mo_exp_data_counter);
mo_exp_data_counter_t *mo_exp_data_counter_copy(mo_exp_data_counter_t	*dst,
                                                mo_exp_data_counter_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _mo_exp_data_counter_H_ */
