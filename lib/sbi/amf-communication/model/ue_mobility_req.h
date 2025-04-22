/*
 * ue_mobility_req.h
 *
 * UE mobility analytics requirement.
 */

#ifndef _ue_mobility_req_H_
#define _ue_mobility_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "matching_direction.h"
#include "ue_mobility_order_criterion.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_mobility_req_s ue_mobility_req_t;
typedef struct ue_mobility_req_s {
	struct ue_mobility_order_criterion_s *order_criterion;
	struct matching_direction_s *order_direction;
	bool is_ue_loc_order_ind;
	int ue_loc_order_ind;
	list_t *dist_thresholds;
} ue_mobility_req_t;

ue_mobility_req_t *ue_mobility_req_create(
	ue_mobility_order_criterion_t *order_criterion,
	matching_direction_t *order_direction, bool is_ue_loc_order_ind,
	int ue_loc_order_ind, list_t *dist_thresholds);
void ue_mobility_req_free(ue_mobility_req_t *ue_mobility_req);
ue_mobility_req_t *ue_mobility_req_parseFromJSON(cJSON *ue_mobility_reqJSON);
cJSON *ue_mobility_req_convertToJSON(ue_mobility_req_t *ue_mobility_req);
ue_mobility_req_t *ue_mobility_req_copy(ue_mobility_req_t	*dst,
                                        ue_mobility_req_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_mobility_req_H_ */
