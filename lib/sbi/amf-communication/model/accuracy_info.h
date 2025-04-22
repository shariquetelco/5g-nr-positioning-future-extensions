/*
 * accuracy_info.h
 *
 * The analytics accuracy information.
 */

#ifndef _accuracy_info_H_
#define _accuracy_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "analytics_accuracy_indication.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct accuracy_info_s accuracy_info_t;
typedef struct accuracy_info_s {
	bool is_accuracy_val;
	int accuracy_val;
	bool is_accu_sample_nbr;
	int accu_sample_nbr;
	struct analytics_accuracy_indication_s *ana_accu_ind;
} accuracy_info_t;

accuracy_info_t *accuracy_info_create(bool is_accuracy_val, int accuracy_val,
                                      bool is_accu_sample_nbr,
                                      int accu_sample_nbr,
                                      analytics_accuracy_indication_t *ana_accu_ind);
void accuracy_info_free(accuracy_info_t *accuracy_info);
accuracy_info_t *accuracy_info_parseFromJSON(cJSON *accuracy_infoJSON);
cJSON *accuracy_info_convertToJSON(accuracy_info_t *accuracy_info);
accuracy_info_t *accuracy_info_copy(accuracy_info_t *dst, accuracy_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _accuracy_info_H_ */
