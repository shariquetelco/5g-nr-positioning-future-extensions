/*
 * pws_response_data.h
 *
 * Data related PWS included in a N2 Information Transfer response
 */

#ifndef _pws_response_data_H_
#define _pws_response_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pws_response_data_s pws_response_data_t;
typedef enum { pws_response_data_N2PWSSUBMISSIND_NULL = 0,
	       pws_response_data_N2PWSSUBMISSIND__true }
pws_response_data_n2_pws_sub_miss_ind_e;

char *pws_response_data_n2_pws_sub_miss_ind_ToString(
	pws_response_data_n2_pws_sub_miss_ind_e n2_pws_sub_miss_ind);

pws_response_data_n2_pws_sub_miss_ind_e
pws_response_data_n2_pws_sub_miss_ind_FromString(char *n2_pws_sub_miss_ind);
typedef struct pws_response_data_s {
	int ngap_message_type;
	int serial_number;
	int message_identifier;
	list_t *unknown_tai_list;
	pws_response_data_n2_pws_sub_miss_ind_e n2_pws_sub_miss_ind;
} pws_response_data_t;

pws_response_data_t *pws_response_data_create(
	int					ngap_message_type,
	int					serial_number,
	int					message_identifier,
	list_t					*unknown_tai_list,
	pws_response_data_n2_pws_sub_miss_ind_e n2_pws_sub_miss_ind);
void pws_response_data_free(pws_response_data_t *pws_response_data);
pws_response_data_t *pws_response_data_parseFromJSON(
	cJSON *pws_response_dataJSON);
cJSON *pws_response_data_convertToJSON(pws_response_data_t *pws_response_data);
pws_response_data_t *pws_response_data_copy(pws_response_data_t *dst,
                                            pws_response_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _pws_response_data_H_ */
