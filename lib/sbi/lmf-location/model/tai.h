/*
 * tai.h
 *
 * Contains the tracking area identity as described in 3GPP 23.003
 */

#ifndef _tai_H_
#define _tai_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tai_s tai_t;
typedef struct tai_s {
	struct plmn_id_s *plmn_id;
	char *tac;
	char *nid;
} tai_t;

tai_t *tai_create(plmn_id_t *plmn_id, char *tac, char *nid);
void tai_free(tai_t *tai);
tai_t *tai_parseFromJSON(cJSON *taiJSON);
cJSON *tai_convertToJSON(tai_t *tai);
tai_t *tai_copy(tai_t *dst, tai_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _tai_H_ */
