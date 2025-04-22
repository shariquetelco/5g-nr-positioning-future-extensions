/*
 * ciphering_data_set.h
 *
 * Represents a Ciphering Data Set.
 */

#ifndef _ciphering_data_set_H_
#define _ciphering_data_set_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ciphering_data_set_s ciphering_data_set_t;
typedef struct ciphering_data_set_s {
	int ciphering_set_id;
	char *ciphering_key;
	char *c0;
	char *lte_pos_sib_types;
	char *nr_pos_sib_types;
	char *validity_start_time;
	int validity_duration;
	char *tai_list;
} ciphering_data_set_t;

ciphering_data_set_t *ciphering_data_set_create(int ciphering_set_id,
                                                char *ciphering_key, char *c0,
                                                char *lte_pos_sib_types,
                                                char *nr_pos_sib_types,
                                                char *validity_start_time,
                                                int validity_duration,
                                                char *tai_list);
void ciphering_data_set_free(ciphering_data_set_t *ciphering_data_set);
ciphering_data_set_t *ciphering_data_set_parseFromJSON(
	cJSON *ciphering_data_setJSON);
cJSON *ciphering_data_set_convertToJSON(
	ciphering_data_set_t *ciphering_data_set);
ciphering_data_set_t *ciphering_data_set_copy(ciphering_data_set_t	*dst,
                                              ciphering_data_set_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ciphering_data_set_H_ */
