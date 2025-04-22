/*
 * candidate_for_replacement.h
 *
 * Represents a list of candidate DNNs for replacement for an S-NSSAI.
 */

#ifndef _candidate_for_replacement_H_
#define _candidate_for_replacement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct candidate_for_replacement_s candidate_for_replacement_t;
typedef struct candidate_for_replacement_s {
	struct snssai_s *snssai;
	bool is_dnns_null;
	list_t *dnns;
} candidate_for_replacement_t;

candidate_for_replacement_t *candidate_for_replacement_create(snssai_t	*snssai,
                                                              bool	is_dnns_null,
                                                              list_t	*dnns);
void candidate_for_replacement_free(
	candidate_for_replacement_t *candidate_for_replacement);
candidate_for_replacement_t *candidate_for_replacement_parseFromJSON(
	cJSON *candidate_for_replacementJSON);
cJSON *candidate_for_replacement_convertToJSON(
	candidate_for_replacement_t *candidate_for_replacement);
candidate_for_replacement_t *candidate_for_replacement_copy(
	candidate_for_replacement_t *dst, candidate_for_replacement_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _candidate_for_replacement_H_ */
