/*
 * presence_info.h
 *
 * If the additionalPraId IE is present, this IE shall state the presence information of the UE for the individual PRA identified by the additionalPraId IE;  If the additionalPraId IE is not present, this IE shall state the presence information of the UE for the PRA identified by the praId IE.
 */

#ifndef _presence_info_H_
#define _presence_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ecgi.h"
#include "global_ran_node_id.h"
#include "ncgi.h"
#include "presence_state.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct presence_info_s presence_info_t;
typedef struct presence_info_s {
	char *pra_id;
	char *additional_pra_id;
	struct presence_state_s *presence_state;
	list_t *tracking_area_list;
	list_t *ecgi_list;
	list_t *ncgi_list;
	list_t *global_ran_node_id_list;
	list_t *globale_nb_id_list;
} presence_info_t;

presence_info_t *presence_info_create(char *pra_id, char *additional_pra_id,
                                      presence_state_t *presence_state,
                                      list_t *tracking_area_list,
                                      list_t *ecgi_list, list_t *ncgi_list,
                                      list_t *global_ran_node_id_list,
                                      list_t *globale_nb_id_list);
void presence_info_free(presence_info_t *presence_info);
presence_info_t *presence_info_parseFromJSON(cJSON *presence_infoJSON);
cJSON *presence_info_convertToJSON(presence_info_t *presence_info);
presence_info_t *presence_info_copy(presence_info_t *dst, presence_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _presence_info_H_ */
