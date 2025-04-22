/*
 * assign_ebi_failed.h
 *
 * Represents failed assignment of EBI(s)
 */

#ifndef _assign_ebi_failed_H_
#define _assign_ebi_failed_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "arp.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct assign_ebi_failed_s assign_ebi_failed_t;
typedef struct assign_ebi_failed_s {
	int pdu_session_id;
	list_t *failed_arp_list;
} assign_ebi_failed_t;

assign_ebi_failed_t *assign_ebi_failed_create(int	pdu_session_id,
                                              list_t	*failed_arp_list);
void assign_ebi_failed_free(assign_ebi_failed_t *assign_ebi_failed);
assign_ebi_failed_t *assign_ebi_failed_parseFromJSON(
	cJSON *assign_ebi_failedJSON);
cJSON *assign_ebi_failed_convertToJSON(assign_ebi_failed_t *assign_ebi_failed);
assign_ebi_failed_t *assign_ebi_failed_copy(assign_ebi_failed_t *dst,
                                            assign_ebi_failed_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _assign_ebi_failed_H_ */
