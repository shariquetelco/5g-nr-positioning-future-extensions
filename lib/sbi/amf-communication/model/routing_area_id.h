/*
 * routing_area_id.h
 *
 * Contains a Routing Area Identification as defined in 3GPP TS 23.003, clause 4.2.
 */

#ifndef _routing_area_id_H_
#define _routing_area_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct routing_area_id_s routing_area_id_t;
typedef struct routing_area_id_s {
	struct plmn_id_s *plmn_id;
	char *lac;
	char *rac;
} routing_area_id_t;

routing_area_id_t *routing_area_id_create(plmn_id_t *plmn_id, char *lac,
                                          char *rac);
void routing_area_id_free(routing_area_id_t *routing_area_id);
routing_area_id_t *routing_area_id_parseFromJSON(cJSON *routing_area_idJSON);
cJSON *routing_area_id_convertToJSON(routing_area_id_t *routing_area_id);
routing_area_id_t *routing_area_id_copy(routing_area_id_t	*dst,
                                        routing_area_id_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _routing_area_id_H_ */
