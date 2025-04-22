/*
 * n2_information_transfer_req_data.h
 *
 * Data within a N2 Information Transfer request containing the N2 information requested to be transferred to 5G AN
 */

#ifndef _n2_information_transfer_req_data_H_
#define _n2_information_transfer_req_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "global_ran_node_id.h"
#include "n2_info_container.h"
#include "rat_selector.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n2_information_transfer_req_data_s
        n2_information_transfer_req_data_t;
typedef struct n2_information_transfer_req_data_s {
	list_t *tai_list;
	rat_selector_e rat_selector;
	list_t *global_ran_node_list;
	struct n2_info_container_s *n2_information;
	char *supported_features;
} n2_information_transfer_req_data_t;

n2_information_transfer_req_data_t *n2_information_transfer_req_data_create(
	list_t *tai_list, rat_selector_e rat_selector,
	list_t *global_ran_node_list, n2_info_container_t *n2_information,
	char *supported_features);
void n2_information_transfer_req_data_free(
	n2_information_transfer_req_data_t *n2_information_transfer_req_data);
n2_information_transfer_req_data_t *
n2_information_transfer_req_data_parseFromJSON(
	cJSON *n2_information_transfer_req_dataJSON);
cJSON *n2_information_transfer_req_data_convertToJSON(
	n2_information_transfer_req_data_t *n2_information_transfer_req_data);
n2_information_transfer_req_data_t *n2_information_transfer_req_data_copy(
	n2_information_transfer_req_data_t	*dst,
	n2_information_transfer_req_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _n2_information_transfer_req_data_H_ */
