/*
 * up_loc_rep_info_af.h
 *
 * Information for the location reporting over user plane
 */

#ifndef _up_loc_rep_info_af_H_
#define _up_loc_rep_info_af_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "up_cum_evt_rpt_criteria.h"
#include "up_loc_rep_addr_af_rm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct up_loc_rep_info_af_s up_loc_rep_info_af_t;
typedef enum { up_loc_rep_info_af_UPLOCREPAFIND_NULL = 0,
	       up_loc_rep_info_af_UPLOCREPAFIND__true }
up_loc_rep_info_af_up_loc_rep_af_ind_e;

char *up_loc_rep_info_af_up_loc_rep_af_ind_ToString(
	up_loc_rep_info_af_up_loc_rep_af_ind_e up_loc_rep_af_ind);

up_loc_rep_info_af_up_loc_rep_af_ind_e
up_loc_rep_info_af_up_loc_rep_af_ind_FromString(char *up_loc_rep_af_ind);
typedef struct up_loc_rep_info_af_s {
	up_loc_rep_info_af_up_loc_rep_af_ind_e up_loc_rep_af_ind;
	bool is_up_loc_rep_addr_af_null;
	struct up_loc_rep_addr_af_rm_s *up_loc_rep_addr_af;
	struct up_cum_evt_rpt_criteria_s *up_cum_evt_rpt_criteria;
} up_loc_rep_info_af_t;

up_loc_rep_info_af_t *up_loc_rep_info_af_create(
	up_loc_rep_info_af_up_loc_rep_af_ind_e	up_loc_rep_af_ind,
	bool					is_up_loc_rep_addr_af_null,
	up_loc_rep_addr_af_rm_t			*up_loc_rep_addr_af,
	up_cum_evt_rpt_criteria_t		*up_cum_evt_rpt_criteria);
void up_loc_rep_info_af_free(up_loc_rep_info_af_t *up_loc_rep_info_af);
up_loc_rep_info_af_t *up_loc_rep_info_af_parseFromJSON(
	cJSON *up_loc_rep_info_afJSON);
cJSON *up_loc_rep_info_af_convertToJSON(
	up_loc_rep_info_af_t *up_loc_rep_info_af);
up_loc_rep_info_af_t *up_loc_rep_info_af_copy(up_loc_rep_info_af_t	*dst,
                                              up_loc_rep_info_af_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _up_loc_rep_info_af_H_ */
