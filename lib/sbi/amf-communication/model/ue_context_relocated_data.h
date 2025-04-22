/*
 * ue_context_relocated_data.h
 *
 * Data within a Relocate UE Context response
 */

#ifndef _ue_context_relocated_data_H_
#define _ue_context_relocated_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_context.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_context_relocated_data_s ue_context_relocated_data_t;
typedef struct ue_context_relocated_data_s {
	struct ue_context_s *ue_context;
} ue_context_relocated_data_t;

ue_context_relocated_data_t *ue_context_relocated_data_create(
	ue_context_t *ue_context);
void ue_context_relocated_data_free(
	ue_context_relocated_data_t *ue_context_relocated_data);
ue_context_relocated_data_t *ue_context_relocated_data_parseFromJSON(
	cJSON *ue_context_relocated_dataJSON);
cJSON *ue_context_relocated_data_convertToJSON(
	ue_context_relocated_data_t *ue_context_relocated_data);
ue_context_relocated_data_t *ue_context_relocated_data_copy(
	ue_context_relocated_data_t *dst, ue_context_relocated_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_context_relocated_data_H_ */
