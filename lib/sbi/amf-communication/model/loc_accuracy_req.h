/*
 * loc_accuracy_req.h
 *
 * Contains location accuracy analytics requirements.
 */

#ifndef _loc_accuracy_req_H_
#define _loc_accuracy_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "matching_direction.h"
#include "positioning_method.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct loc_accuracy_req_s loc_accuracy_req_t;
typedef struct loc_accuracy_req_s {
	bool is_acc_thres;
	int acc_thres;
	struct matching_direction_s *acc_thres_match_dir;
	bool is_in_out_thres;
	int in_out_thres;
	struct matching_direction_s *in_out_thres_match_dir;
	struct positioning_method_s *pos_method;
} loc_accuracy_req_t;

loc_accuracy_req_t *loc_accuracy_req_create(bool is_acc_thres, int acc_thres,
                                            matching_direction_t *acc_thres_match_dir, bool is_in_out_thres, int in_out_thres, matching_direction_t *in_out_thres_match_dir, positioning_method_t *pos_method);
void loc_accuracy_req_free(loc_accuracy_req_t *loc_accuracy_req);
loc_accuracy_req_t *loc_accuracy_req_parseFromJSON(cJSON *loc_accuracy_reqJSON);
cJSON *loc_accuracy_req_convertToJSON(loc_accuracy_req_t *loc_accuracy_req);
loc_accuracy_req_t *loc_accuracy_req_copy(loc_accuracy_req_t	*dst,
                                          loc_accuracy_req_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _loc_accuracy_req_H_ */
