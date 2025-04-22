/*
 * congestion_info.h
 *
 * Represents the congestion information.
 */

#ifndef _congestion_info_H_
#define _congestion_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "congestion_type.h"
#include "threshold_level.h"
#include "time_window.h"
#include "top_application.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct congestion_info_s congestion_info_t;
typedef struct congestion_info_s {
	struct congestion_type_s *cong_type;
	struct time_window_s *time_intev;
	struct threshold_level_s *nsi;
	bool is_confidence;
	int confidence;
	list_t *top_app_list_ul;
	list_t *top_app_list_dl;
} congestion_info_t;

congestion_info_t *congestion_info_create(congestion_type_t *cong_type,
                                          time_window_t *time_intev,
                                          threshold_level_t *nsi,
                                          bool is_confidence, int confidence,
                                          list_t *top_app_list_ul,
                                          list_t *top_app_list_dl);
void congestion_info_free(congestion_info_t *congestion_info);
congestion_info_t *congestion_info_parseFromJSON(cJSON *congestion_infoJSON);
cJSON *congestion_info_convertToJSON(congestion_info_t *congestion_info);
congestion_info_t *congestion_info_copy(congestion_info_t	*dst,
                                        congestion_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _congestion_info_H_ */
