/*
 * ladn_info.h
 *
 * LADN Information
 */

#ifndef _ladn_info_H_
#define _ladn_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "presence_state.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ladn_info_s ladn_info_t;
typedef struct ladn_info_s {
	char *ladn;
	struct presence_state_s *presence;
} ladn_info_t;

ladn_info_t *ladn_info_create(char *ladn, presence_state_t *presence);
void ladn_info_free(ladn_info_t *ladn_info);
ladn_info_t *ladn_info_parseFromJSON(cJSON *ladn_infoJSON);
cJSON *ladn_info_convertToJSON(ladn_info_t *ladn_info);
ladn_info_t *ladn_info_copy(ladn_info_t *dst, ladn_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ladn_info_H_ */
