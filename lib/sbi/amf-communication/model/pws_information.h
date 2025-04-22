/*
 * pws_information.h
 *
 * Represents a PWS related information data part
 */

#ifndef _pws_information_H_
#define _pws_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "global_ran_node_id.h"
#include "n2_info_content.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pws_information_s pws_information_t;
typedef struct pws_information_s {
	int message_identifier;
	int serial_number;
	struct n2_info_content_s *pws_container;
	list_t *bc_empty_area_list;
	bool is_send_ran_response;
	int send_ran_response;
	char *omc_id;
	char *nf_id;
} pws_information_t;

pws_information_t *pws_information_create(int message_identifier,
                                          int serial_number,
                                          n2_info_content_t *pws_container,
                                          list_t *bc_empty_area_list,
                                          bool is_send_ran_response,
                                          int send_ran_response, char *omc_id,
                                          char *nf_id);
void pws_information_free(pws_information_t *pws_information);
pws_information_t *pws_information_parseFromJSON(cJSON *pws_informationJSON);
cJSON *pws_information_convertToJSON(pws_information_t *pws_information);
pws_information_t *pws_information_copy(pws_information_t	*dst,
                                        pws_information_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _pws_information_H_ */
