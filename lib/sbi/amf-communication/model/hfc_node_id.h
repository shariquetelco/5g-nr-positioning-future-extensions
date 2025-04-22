/*
 * hfc_node_id.h
 *
 * REpresents the HFC Node Identifer received over NGAP.
 */

#ifndef _hfc_node_id_H_
#define _hfc_node_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hfc_node_id_s hfc_node_id_t;
typedef struct hfc_node_id_s {
	char *hfc_nid;
} hfc_node_id_t;

hfc_node_id_t *hfc_node_id_create(char *hfc_nid);
void hfc_node_id_free(hfc_node_id_t *hfc_node_id);
hfc_node_id_t *hfc_node_id_parseFromJSON(cJSON *hfc_node_idJSON);
cJSON *hfc_node_id_convertToJSON(hfc_node_id_t *hfc_node_id);
hfc_node_id_t *hfc_node_id_copy(hfc_node_id_t *dst, hfc_node_id_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _hfc_node_id_H_ */
