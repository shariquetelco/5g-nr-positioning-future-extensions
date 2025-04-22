/*
 * area_scope.h
 *
 * Contain the area based on Cells or Tracking Areas.
 */

#ifndef _area_scope_H_
#define _area_scope_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "cag_info_1.h"
#include "nid_info.h"
#include "tac_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct area_scope_s area_scope_t;
typedef struct area_scope_s {
	list_t *eutra_cell_id_list;
	list_t *nr_cell_id_list;
	list_t *tac_list;
	list_t *tac_info_per_plmn;
	list_t *cag_info_per_plmn;
	list_t *nid_info_per_plmn;
} area_scope_t;

area_scope_t *area_scope_create(list_t *eutra_cell_id_list,
                                list_t *nr_cell_id_list, list_t *tac_list,
                                list_t *tac_info_per_plmn,
                                list_t *cag_info_per_plmn,
                                list_t *nid_info_per_plmn);
void area_scope_free(area_scope_t *area_scope);
area_scope_t *area_scope_parseFromJSON(cJSON *area_scopeJSON);
cJSON *area_scope_convertToJSON(area_scope_t *area_scope);
area_scope_t *area_scope_copy(area_scope_t *dst, area_scope_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _area_scope_H_ */
