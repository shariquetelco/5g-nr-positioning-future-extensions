/*
 * assigned_ebi_data.h
 *
 * Data within a successful response to an EBI assignment request
 */

#ifndef _assigned_ebi_data_H_
#define _assigned_ebi_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "arp.h"
#include "ebi_arp_mapping.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct assigned_ebi_data_s assigned_ebi_data_t;
typedef struct assigned_ebi_data_s {
	int pdu_session_id;
	list_t *assigned_ebi_list;
	list_t *failed_arp_list;
	list_t *released_ebi_list;
	list_t *modified_ebi_list;
} assigned_ebi_data_t;

assigned_ebi_data_t *assigned_ebi_data_create(int	pdu_session_id,
                                              list_t	*assigned_ebi_list,
                                              list_t	*failed_arp_list,
                                              list_t	*released_ebi_list,
                                              list_t	*modified_ebi_list);
void assigned_ebi_data_free(assigned_ebi_data_t *assigned_ebi_data);
assigned_ebi_data_t *assigned_ebi_data_parseFromJSON(
	cJSON *assigned_ebi_dataJSON);
cJSON *assigned_ebi_data_convertToJSON(assigned_ebi_data_t *assigned_ebi_data);
assigned_ebi_data_t *assigned_ebi_data_copy(assigned_ebi_data_t *dst,
                                            assigned_ebi_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _assigned_ebi_data_H_ */
