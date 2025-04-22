/*
 * cancel_loc_data.h
 *
 * Contains the input parameters in CancelLocation service operation
 */

#ifndef _cancel_loc_data_H_
#define _cancel_loc_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cancel_loc_data_s cancel_loc_data_t;
typedef struct cancel_loc_data_s {
	char *gpsi;
	char *supi;
	char *ext_group_id;
	char *int_group_id;
	char *hgmlc_call_back_uri;
	char *ldr_reference;
	char *lmf_identification;
	char *amf_id;
} cancel_loc_data_t;

cancel_loc_data_t *cancel_loc_data_create(char *gpsi, char *supi,
                                          char *ext_group_id,
                                          char *int_group_id,
                                          char *hgmlc_call_back_uri,
                                          char *ldr_reference,
                                          char *lmf_identification,
                                          char *amf_id);
void cancel_loc_data_free(cancel_loc_data_t *cancel_loc_data);
cancel_loc_data_t *cancel_loc_data_parseFromJSON(cJSON *cancel_loc_dataJSON);
cJSON *cancel_loc_data_convertToJSON(cancel_loc_data_t *cancel_loc_data);
cancel_loc_data_t *cancel_loc_data_copy(cancel_loc_data_t	*dst,
                                        cancel_loc_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _cancel_loc_data_H_ */
