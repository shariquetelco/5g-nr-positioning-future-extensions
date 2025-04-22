/*
 * service_area_id.h
 *
 * Contains a Service Area Identifier as defined in 3GPP TS 23.003, clause 12.5.
 */

#ifndef _service_area_id_H_
#define _service_area_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct service_area_id_s service_area_id_t;
typedef struct service_area_id_s {
	struct plmn_id_s *plmn_id;
	char *lac;
	char *sac;
} service_area_id_t;

service_area_id_t *service_area_id_create(plmn_id_t *plmn_id, char *lac,
                                          char *sac);
void service_area_id_free(service_area_id_t *service_area_id);
service_area_id_t *service_area_id_parseFromJSON(cJSON *service_area_idJSON);
cJSON *service_area_id_convertToJSON(service_area_id_t *service_area_id);
service_area_id_t *service_area_id_copy(service_area_id_t	*dst,
                                        service_area_id_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _service_area_id_H_ */
