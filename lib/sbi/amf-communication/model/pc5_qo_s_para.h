/*
 * pc5_qo_s_para.h
 *
 * Contains policy data on the PC5 QoS parameters.
 */

#ifndef _pc5_qo_s_para_H_
#define _pc5_qo_s_para_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "pc5_qos_flow_item.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pc5_qo_s_para_s pc5_qo_s_para_t;
typedef struct pc5_qo_s_para_s {
	list_t *pc5_qos_flow_list;
	char *pc5_link_ambr;
} pc5_qo_s_para_t;

pc5_qo_s_para_t *pc5_qo_s_para_create(list_t	*pc5_qos_flow_list,
                                      char	*pc5_link_ambr);
void pc5_qo_s_para_free(pc5_qo_s_para_t *pc5_qo_s_para);
pc5_qo_s_para_t *pc5_qo_s_para_parseFromJSON(cJSON *pc5_qo_s_paraJSON);
cJSON *pc5_qo_s_para_convertToJSON(pc5_qo_s_para_t *pc5_qo_s_para);
pc5_qo_s_para_t *pc5_qo_s_para_copy(pc5_qo_s_para_t *dst, pc5_qo_s_para_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _pc5_qo_s_para_H_ */
