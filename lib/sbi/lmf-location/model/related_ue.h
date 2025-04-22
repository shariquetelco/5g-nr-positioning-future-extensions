/*
 * related_ue.h
 *
 * Related UE Information
 */

#ifndef _related_ue_H_
#define _related_ue_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "related_ue_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct related_ue_s related_ue_t;
typedef struct related_ue_s {
	char *applicationlayer_id;
	related_ue_type_e related_ue_type;
} related_ue_t;

related_ue_t *related_ue_create(char			*applicationlayer_id,
                                related_ue_type_e	related_ue_type);
void related_ue_free(related_ue_t *related_ue);
related_ue_t *related_ue_parseFromJSON(cJSON *related_ueJSON);
cJSON *related_ue_convertToJSON(related_ue_t *related_ue);
related_ue_t *related_ue_copy(related_ue_t *dst, related_ue_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _related_ue_H_ */
