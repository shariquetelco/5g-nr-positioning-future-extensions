/*
 * ue_comm_req.h
 *
 * UE communication analytics requirement.
 */

#ifndef _ue_comm_req_H_
#define _ue_comm_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "matching_direction.h"
#include "ue_comm_order_criterion.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_comm_req_s ue_comm_req_t;
typedef struct ue_comm_req_s {
	struct ue_comm_order_criterion_s *order_criterion;
	struct matching_direction_s *order_direction;
} ue_comm_req_t;

ue_comm_req_t *ue_comm_req_create(
	ue_comm_order_criterion_t	*order_criterion,
	matching_direction_t		*order_direction);
void ue_comm_req_free(ue_comm_req_t *ue_comm_req);
ue_comm_req_t *ue_comm_req_parseFromJSON(cJSON *ue_comm_reqJSON);
cJSON *ue_comm_req_convertToJSON(ue_comm_req_t *ue_comm_req);
ue_comm_req_t *ue_comm_req_copy(ue_comm_req_t *dst, ue_comm_req_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_comm_req_H_ */
