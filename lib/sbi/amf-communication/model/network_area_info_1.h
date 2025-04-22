/*
 * network_area_info_1.h
 *
 * Describes a network area information in which the NF service consumer requests the number of UEs.
 */

#ifndef _network_area_info_1_H_
#define _network_area_info_1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ecgi.h"
#include "global_ran_node_id.h"
#include "ncgi.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct network_area_info_1_s network_area_info_1_t;
typedef struct network_area_info_1_s {
	list_t *ecgis;
	list_t *ncgis;
	list_t *g_ran_node_ids;
	list_t *tais;
} network_area_info_1_t;

network_area_info_1_t *network_area_info_1_create(list_t *ecgis, list_t *ncgis,
                                                  list_t *g_ran_node_ids,
                                                  list_t *tais);
void network_area_info_1_free(network_area_info_1_t *network_area_info_1);
network_area_info_1_t *network_area_info_1_parseFromJSON(
	cJSON *network_area_info_1JSON);
cJSON *network_area_info_1_convertToJSON(
	network_area_info_1_t *network_area_info_1);
network_area_info_1_t *network_area_info_1_copy(network_area_info_1_t	*dst,
                                                network_area_info_1_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _network_area_info_1_H_ */
