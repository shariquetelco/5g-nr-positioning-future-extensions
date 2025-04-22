/*
 * cell_global_id.h
 *
 * Contains a Cell Global Identification as defined in 3GPP TS 23.003, clause 4.3.1.
 */

#ifndef _cell_global_id_H_
#define _cell_global_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cell_global_id_s cell_global_id_t;
typedef struct cell_global_id_s {
	struct plmn_id_s *plmn_id;
	char *lac;
	char *cell_id;
} cell_global_id_t;

cell_global_id_t *cell_global_id_create(plmn_id_t *plmn_id, char *lac,
                                        char *cell_id);
void cell_global_id_free(cell_global_id_t *cell_global_id);
cell_global_id_t *cell_global_id_parseFromJSON(cJSON *cell_global_idJSON);
cJSON *cell_global_id_convertToJSON(cell_global_id_t *cell_global_id);
cell_global_id_t *cell_global_id_copy(cell_global_id_t	*dst,
                                      cell_global_id_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _cell_global_id_H_ */
