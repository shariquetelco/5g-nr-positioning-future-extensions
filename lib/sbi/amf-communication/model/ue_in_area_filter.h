/*
 * ue_in_area_filter.h
 *
 * Additional filters for UE in Area Report event
 */

#ifndef _ue_in_area_filter_H_
#define _ue_in_area_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_in_area_filter_s ue_in_area_filter_t;
typedef struct ue_in_area_filter_s {
	struct ue_type_s *ue_type;
	bool is_aerial_srv_dnn_ind;
	int aerial_srv_dnn_ind;
	bool is_ue_id_omit_ind;
	int ue_id_omit_ind;
} ue_in_area_filter_t;

ue_in_area_filter_t *ue_in_area_filter_create(ue_type_t *ue_type,
                                              bool	is_aerial_srv_dnn_ind,
                                              int	aerial_srv_dnn_ind,
                                              bool	is_ue_id_omit_ind,
                                              int	ue_id_omit_ind);
void ue_in_area_filter_free(ue_in_area_filter_t *ue_in_area_filter);
ue_in_area_filter_t *ue_in_area_filter_parseFromJSON(
	cJSON *ue_in_area_filterJSON);
cJSON *ue_in_area_filter_convertToJSON(ue_in_area_filter_t *ue_in_area_filter);
ue_in_area_filter_t *ue_in_area_filter_copy(ue_in_area_filter_t *dst,
                                            ue_in_area_filter_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_in_area_filter_H_ */
