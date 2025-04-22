/*
 * smf_selection_data.h
 *
 * Represents the SMF Selection information that may be replaced by the PCF.
 */

#ifndef _smf_selection_data_H_
#define _smf_selection_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "candidate_for_replacement.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct smf_selection_data_s smf_selection_data_t;
typedef struct smf_selection_data_s {
	bool is_unsupp_dnn;
	int unsupp_dnn;
	bool is_candidates_null;
	list_t *candidates;
	struct snssai_s *snssai;
	struct snssai_s *mapping_snssai;
	char *dnn;
} smf_selection_data_t;

smf_selection_data_t *smf_selection_data_create(bool		is_unsupp_dnn,
                                                int		unsupp_dnn,
                                                bool		is_candidates_null,
                                                list_t		*candidates,
                                                snssai_t	*snssai,
                                                snssai_t	*mapping_snssai,
                                                char		*dnn);
void smf_selection_data_free(smf_selection_data_t *smf_selection_data);
smf_selection_data_t *smf_selection_data_parseFromJSON(
	cJSON *smf_selection_dataJSON);
cJSON *smf_selection_data_convertToJSON(
	smf_selection_data_t *smf_selection_data);
smf_selection_data_t *smf_selection_data_copy(smf_selection_data_t	*dst,
                                              smf_selection_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _smf_selection_data_H_ */
