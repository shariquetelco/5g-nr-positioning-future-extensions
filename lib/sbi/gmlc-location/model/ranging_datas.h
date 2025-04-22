/*
 * ranging_datas.h
 *
 * Ranging Data List
 */

#ifndef _ranging_datas_H_
#define _ranging_datas_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ranging_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ranging_datas_s ranging_datas_t;
typedef struct ranging_datas_s {
	list_t *ranging_datas;
} ranging_datas_t;

ranging_datas_t *ranging_datas_create(list_t *ranging_datas);
void ranging_datas_free(ranging_datas_t *ranging_datas);
ranging_datas_t *ranging_datas_parseFromJSON(cJSON *ranging_datasJSON);
cJSON *ranging_datas_convertToJSON(ranging_datas_t *ranging_datas);
ranging_datas_t *ranging_datas_copy(ranging_datas_t *dst, ranging_datas_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ranging_datas_H_ */
