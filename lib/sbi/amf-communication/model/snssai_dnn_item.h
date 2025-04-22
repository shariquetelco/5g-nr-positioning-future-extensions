/*
 * snssai_dnn_item.h
 *
 * Combination of S-NSSAIs and DNNs
 */

#ifndef _snssai_dnn_item_H_
#define _snssai_dnn_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ext_snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct snssai_dnn_item_s snssai_dnn_item_t;
typedef struct snssai_dnn_item_s {
	list_t *snssai_list;
	list_t *dnn_list;
} snssai_dnn_item_t;

snssai_dnn_item_t *snssai_dnn_item_create(list_t	*snssai_list,
                                          list_t	*dnn_list);
void snssai_dnn_item_free(snssai_dnn_item_t *snssai_dnn_item);
snssai_dnn_item_t *snssai_dnn_item_parseFromJSON(cJSON *snssai_dnn_itemJSON);
cJSON *snssai_dnn_item_convertToJSON(snssai_dnn_item_t *snssai_dnn_item);
snssai_dnn_item_t *snssai_dnn_item_copy(snssai_dnn_item_t	*dst,
                                        snssai_dnn_item_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _snssai_dnn_item_H_ */
