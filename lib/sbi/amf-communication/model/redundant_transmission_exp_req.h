/*
 * redundant_transmission_exp_req.h
 *
 * Represents other redundant transmission experience analytics requirements.
 */

#ifndef _redundant_transmission_exp_req_H_
#define _redundant_transmission_exp_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "matching_direction.h"
#include "red_trans_exp_ordering_criterion.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct redundant_transmission_exp_req_s redundant_transmission_exp_req_t;
typedef struct redundant_transmission_exp_req_s {
	struct red_trans_exp_ordering_criterion_s *red_t_order_criter;
	struct matching_direction_s *order;
} redundant_transmission_exp_req_t;

redundant_transmission_exp_req_t *redundant_transmission_exp_req_create(
	red_trans_exp_ordering_criterion_t	*red_t_order_criter,
	matching_direction_t			*order);
void redundant_transmission_exp_req_free(
	redundant_transmission_exp_req_t *redundant_transmission_exp_req);
redundant_transmission_exp_req_t *redundant_transmission_exp_req_parseFromJSON(
	cJSON *redundant_transmission_exp_reqJSON);
cJSON *redundant_transmission_exp_req_convertToJSON(
	redundant_transmission_exp_req_t *redundant_transmission_exp_req);
redundant_transmission_exp_req_t *redundant_transmission_exp_req_copy(
	redundant_transmission_exp_req_t	*dst,
	redundant_transmission_exp_req_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _redundant_transmission_exp_req_H_ */
