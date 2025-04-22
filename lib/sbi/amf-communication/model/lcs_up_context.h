/*
 * lcs_up_context.h
 *
 * Represents the LCS UP related parameters
 */

#ifndef _lcs_up_context_H_
#define _lcs_up_context_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "up_connection_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct lcs_up_context_s lcs_up_context_t;
typedef struct lcs_up_context_s {
	struct up_connection_status_s *up_connection_status;
	char *serving_lmf_identification;
} lcs_up_context_t;

lcs_up_context_t *lcs_up_context_create(
	up_connection_status_t	*up_connection_status,
	char			*serving_lmf_identification);
void lcs_up_context_free(lcs_up_context_t *lcs_up_context);
lcs_up_context_t *lcs_up_context_parseFromJSON(cJSON *lcs_up_contextJSON);
cJSON *lcs_up_context_convertToJSON(lcs_up_context_t *lcs_up_context);
lcs_up_context_t *lcs_up_context_copy(lcs_up_context_t	*dst,
                                      lcs_up_context_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _lcs_up_context_H_ */
