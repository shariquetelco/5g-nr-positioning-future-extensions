/*
 * loc_update_subs.h
 *
 * UE location information subscription
 */

#ifndef _loc_update_subs_H_
#define _loc_update_subs_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct loc_update_subs_s loc_update_subs_t;
typedef struct loc_update_subs_s {
	char *nf_instance_id;
	char *notif_uri;
	char *gpsi;
	char *supi;
} loc_update_subs_t;

loc_update_subs_t *loc_update_subs_create(char *nf_instance_id, char *notif_uri,
                                          char *gpsi, char *supi);
void loc_update_subs_free(loc_update_subs_t *loc_update_subs);
loc_update_subs_t *loc_update_subs_parseFromJSON(cJSON *loc_update_subsJSON);
cJSON *loc_update_subs_convertToJSON(loc_update_subs_t *loc_update_subs);
loc_update_subs_t *loc_update_subs_copy(loc_update_subs_t	*dst,
                                        loc_update_subs_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _loc_update_subs_H_ */
