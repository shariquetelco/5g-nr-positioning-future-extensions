/*
 * mov_behav_req.h
 *
 * Represents the Movement Behaviour analytics requirements.
 */

#ifndef _mov_behav_req_H_
#define _mov_behav_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "loc_info_granularity.h"
#include "threshold_level.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mov_behav_req_s mov_behav_req_t;
typedef struct mov_behav_req_s {
	struct loc_info_granularity_s *location_gran_req;
	struct threshold_level_s *report_thresholds;
} mov_behav_req_t;

mov_behav_req_t *mov_behav_req_create(
	loc_info_granularity_t	*location_gran_req,
	threshold_level_t	*report_thresholds);
void mov_behav_req_free(mov_behav_req_t *mov_behav_req);
mov_behav_req_t *mov_behav_req_parseFromJSON(cJSON *mov_behav_reqJSON);
cJSON *mov_behav_req_convertToJSON(mov_behav_req_t *mov_behav_req);
mov_behav_req_t *mov_behav_req_copy(mov_behav_req_t *dst, mov_behav_req_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _mov_behav_req_H_ */
