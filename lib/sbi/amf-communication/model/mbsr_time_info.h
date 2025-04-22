/*
 * mbsr_time_info.h
 *
 *
 */

#ifndef _mbsr_time_info_H_
#define _mbsr_time_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "recur_time.h"
#include "valid_time_period.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mbsr_time_info_s mbsr_time_info_t;
typedef struct mbsr_time_info_s {
	list_t *mbsr_time_window;
	list_t *mbsr_recur_time;
} mbsr_time_info_t;

mbsr_time_info_t *mbsr_time_info_create(list_t	*mbsr_time_window,
                                        list_t	*mbsr_recur_time);
void mbsr_time_info_free(mbsr_time_info_t *mbsr_time_info);
mbsr_time_info_t *mbsr_time_info_parseFromJSON(cJSON *mbsr_time_infoJSON);
cJSON *mbsr_time_info_convertToJSON(mbsr_time_info_t *mbsr_time_info);
mbsr_time_info_t *mbsr_time_info_copy(mbsr_time_info_t	*dst,
                                      mbsr_time_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _mbsr_time_info_H_ */
