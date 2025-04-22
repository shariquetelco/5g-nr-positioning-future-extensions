/*
 * assign_ebi_data.h
 *
 * Data within an EBI assignment request
 */

#ifndef _assign_ebi_data_H_
#define _assign_ebi_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "arp.h"
#include "ebi_arp_mapping.h"
#include "guami.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct assign_ebi_data_s assign_ebi_data_t;
typedef struct assign_ebi_data_s {
	int pdu_session_id;
	list_t *arp_list;
	list_t *released_ebi_list;
	struct guami_s *old_guami;
	list_t *modified_ebi_list;
} assign_ebi_data_t;

assign_ebi_data_t *assign_ebi_data_create(int pdu_session_id, list_t *arp_list,
                                          list_t *released_ebi_list,
                                          guami_t *old_guami,
                                          list_t *modified_ebi_list);
void assign_ebi_data_free(assign_ebi_data_t *assign_ebi_data);
assign_ebi_data_t *assign_ebi_data_parseFromJSON(cJSON *assign_ebi_dataJSON);
cJSON *assign_ebi_data_convertToJSON(assign_ebi_data_t *assign_ebi_data);
assign_ebi_data_t *assign_ebi_data_copy(assign_ebi_data_t	*dst,
                                        assign_ebi_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _assign_ebi_data_H_ */
