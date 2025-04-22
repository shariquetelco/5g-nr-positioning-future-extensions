/*
 * slice_replacement_mapping.h
 *
 * Represents the mapping between a replaced S-NSSAI in serving PLMN to its alternative S-NSSAI
 */

#ifndef _slice_replacement_mapping_H_
#define _slice_replacement_mapping_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct slice_replacement_mapping_s slice_replacement_mapping_t;
typedef struct slice_replacement_mapping_s {
	struct snssai_s *replaced_snssai;
	struct snssai_s *alt_snssai;
} slice_replacement_mapping_t;

slice_replacement_mapping_t *slice_replacement_mapping_create(
	snssai_t *replaced_snssai, snssai_t *alt_snssai);
void slice_replacement_mapping_free(
	slice_replacement_mapping_t *slice_replacement_mapping);
slice_replacement_mapping_t *slice_replacement_mapping_parseFromJSON(
	cJSON *slice_replacement_mappingJSON);
cJSON *slice_replacement_mapping_convertToJSON(
	slice_replacement_mapping_t *slice_replacement_mapping);
slice_replacement_mapping_t *slice_replacement_mapping_copy(
	slice_replacement_mapping_t *dst, slice_replacement_mapping_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _slice_replacement_mapping_H_ */
