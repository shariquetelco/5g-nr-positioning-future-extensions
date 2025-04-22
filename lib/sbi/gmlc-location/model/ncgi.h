/*
 * ncgi.h
 *
 * Contains the NCGI (NR Cell Global Identity), as described in 3GPP 23.003
 */

#ifndef _ncgi_H_
#define _ncgi_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ncgi_s ncgi_t;
typedef struct ncgi_s {
	struct plmn_id_s *plmn_id;
	char *nr_cell_id;
	char *nid;
} ncgi_t;

ncgi_t *ncgi_create(plmn_id_t *plmn_id, char *nr_cell_id, char *nid);
void ncgi_free(ncgi_t *ncgi);
ncgi_t *ncgi_parseFromJSON(cJSON *ncgiJSON);
cJSON *ncgi_convertToJSON(ncgi_t *ncgi);
ncgi_t *ncgi_copy(ncgi_t *dst, ncgi_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ncgi_H_ */
