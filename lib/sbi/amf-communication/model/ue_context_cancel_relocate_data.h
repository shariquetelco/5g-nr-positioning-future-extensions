/*
 * ue_context_cancel_relocate_data.h
 *
 * Data structure used for cancellation of UE Context Relocation
 */

#ifndef _ue_context_cancel_relocate_data_H_
#define _ue_context_cancel_relocate_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ref_to_binary_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_context_cancel_relocate_data_s
        ue_context_cancel_relocate_data_t;
typedef struct ue_context_cancel_relocate_data_s {
	char *supi;
	struct ref_to_binary_data_s *relocation_cancel_request;
} ue_context_cancel_relocate_data_t;

ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data_create(
	char *supi, ref_to_binary_data_t *relocation_cancel_request);
void ue_context_cancel_relocate_data_free(
	ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data);
ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data_parseFromJSON(
	cJSON *ue_context_cancel_relocate_dataJSON);
cJSON *ue_context_cancel_relocate_data_convertToJSON(
	ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data);
ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data_copy(
	ue_context_cancel_relocate_data_t	*dst,
	ue_context_cancel_relocate_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_context_cancel_relocate_data_H_ */
