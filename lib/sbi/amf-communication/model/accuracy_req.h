/*
 * accuracy_req.h
 *
 * Represents the analytics accuracy requirement information.
 */

#ifndef _accuracy_req_H_
#define _accuracy_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "time_window.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct accuracy_req_s accuracy_req_t;
typedef struct accuracy_req_s {
	struct time_window_s *accu_time_win;
	bool is_accu_period;
	int accu_period;
	bool is_accu_dev_thr;
	int accu_dev_thr;
	bool is_min_num;
	int min_num;
	bool is_updated_ana_flg;
	int updated_ana_flg;
	bool is_correction_interval;
	int correction_interval;
} accuracy_req_t;

accuracy_req_t *accuracy_req_create(time_window_t *accu_time_win,
                                    bool is_accu_period, int accu_period,
                                    bool is_accu_dev_thr, int accu_dev_thr,
                                    bool is_min_num, int min_num,
                                    bool is_updated_ana_flg,
                                    int updated_ana_flg,
                                    bool is_correction_interval,
                                    int correction_interval);
void accuracy_req_free(accuracy_req_t *accuracy_req);
accuracy_req_t *accuracy_req_parseFromJSON(cJSON *accuracy_reqJSON);
cJSON *accuracy_req_convertToJSON(accuracy_req_t *accuracy_req);
accuracy_req_t *accuracy_req_copy(accuracy_req_t *dst, accuracy_req_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _accuracy_req_H_ */
