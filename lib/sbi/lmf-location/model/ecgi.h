/*
 * ecgi.h
 *
 * Contains the ECGI (E-UTRAN Cell Global Identity), as described in 3GPP 23.003
 */

#ifndef _ecgi_H_
#define _ecgi_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ecgi_s ecgi_t;
typedef struct ecgi_s {
	struct plmn_id_s *plmn_id;
	char *eutra_cell_id;
	char *nid;
} ecgi_t;

ecgi_t *ecgi_create(plmn_id_t *plmn_id, char *eutra_cell_id, char *nid);
void ecgi_free(ecgi_t *ecgi);
ecgi_t *ecgi_parseFromJSON(cJSON *ecgiJSON);
cJSON *ecgi_convertToJSON(ecgi_t *ecgi);
ecgi_t *ecgi_copy(ecgi_t *dst, ecgi_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ecgi_H_ */
