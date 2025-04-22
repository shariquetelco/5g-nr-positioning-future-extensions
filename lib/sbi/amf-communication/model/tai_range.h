/*
 * tai_range.h
 *
 * Range of TAIs (Tracking Area Identities)
 */

#ifndef _tai_range_H_
#define _tai_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id.h"
#include "tac_range.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tai_range_s tai_range_t;
typedef struct tai_range_s {
	struct plmn_id_s *plmn_id;
	list_t *tac_range_list;
	char *nid;
} tai_range_t;

tai_range_t *tai_range_create(plmn_id_t *plmn_id, list_t *tac_range_list,
                              char *nid);
void tai_range_free(tai_range_t *tai_range);
tai_range_t *tai_range_parseFromJSON(cJSON *tai_rangeJSON);
cJSON *tai_range_convertToJSON(tai_range_t *tai_range);
tai_range_t *tai_range_copy(tai_range_t *dst, tai_range_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _tai_range_H_ */
