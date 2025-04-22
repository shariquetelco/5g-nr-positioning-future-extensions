/*
 * conditional_cag_info.h
 *
 *
 */

#ifndef _conditional_cag_info_H_
#define _conditional_cag_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "valid_time_period.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct conditional_cag_info_s conditional_cag_info_t;
typedef struct conditional_cag_info_s {
	list_t *allowed_cag_list;
	bool is_cag_only_indicator;
	int cag_only_indicator;
	struct valid_time_period_s *valid_time_period;
} conditional_cag_info_t;

conditional_cag_info_t *conditional_cag_info_create(
	list_t			*allowed_cag_list,
	bool			is_cag_only_indicator,
	int			cag_only_indicator,
	valid_time_period_t	*valid_time_period);
void conditional_cag_info_free(conditional_cag_info_t *conditional_cag_info);
conditional_cag_info_t *conditional_cag_info_parseFromJSON(
	cJSON *conditional_cag_infoJSON);
cJSON *conditional_cag_info_convertToJSON(
	conditional_cag_info_t *conditional_cag_info);
conditional_cag_info_t *conditional_cag_info_copy(
	conditional_cag_info_t	*dst,
	conditional_cag_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _conditional_cag_info_H_ */
