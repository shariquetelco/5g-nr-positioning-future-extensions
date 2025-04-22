/*
 * tac_info.h
 *
 * contains tracking area information (tracking area codes).
 */

#ifndef _tac_info_H_
#define _tac_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tac_info_s tac_info_t;
typedef struct tac_info_s {
	list_t *tac_list;
} tac_info_t;

tac_info_t *tac_info_create(list_t *tac_list);
void tac_info_free(tac_info_t *tac_info);
tac_info_t *tac_info_parseFromJSON(cJSON *tac_infoJSON);
cJSON *tac_info_convertToJSON(tac_info_t *tac_info);
tac_info_t *tac_info_copy(tac_info_t *dst, tac_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _tac_info_H_ */
