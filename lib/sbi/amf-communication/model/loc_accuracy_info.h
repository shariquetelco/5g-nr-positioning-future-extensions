/*
 * loc_accuracy_info.h
 *
 * Contains location accuracy analytics.
 */

#ifndef _loc_accuracy_info_H_
#define _loc_accuracy_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "loc_accuracy_per_method.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct loc_accuracy_info_s loc_accuracy_info_t;
typedef struct loc_accuracy_info_s {
	list_t *loc_acc_per_meths;
	bool is_in_out_ue_pct;
	int in_out_ue_pct;
	bool is_in_out_ind;
	int in_out_ind;
	bool is_confidence;
	int confidence;
} loc_accuracy_info_t;

loc_accuracy_info_t *loc_accuracy_info_create(list_t	*loc_acc_per_meths,
                                              bool	is_in_out_ue_pct,
                                              int	in_out_ue_pct,
                                              bool	is_in_out_ind,
                                              int	in_out_ind,
                                              bool	is_confidence,
                                              int	confidence);
void loc_accuracy_info_free(loc_accuracy_info_t *loc_accuracy_info);
loc_accuracy_info_t *loc_accuracy_info_parseFromJSON(
	cJSON *loc_accuracy_infoJSON);
cJSON *loc_accuracy_info_convertToJSON(loc_accuracy_info_t *loc_accuracy_info);
loc_accuracy_info_t *loc_accuracy_info_copy(loc_accuracy_info_t *dst,
                                            loc_accuracy_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _loc_accuracy_info_H_ */
