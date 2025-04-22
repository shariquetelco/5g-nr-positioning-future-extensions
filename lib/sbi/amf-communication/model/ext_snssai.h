/*
 * ext_snssai.h
 *
 * The sdRanges and wildcardSd attributes shall be exclusive from each other. If one of these attributes is present,  the sd attribute shall also be present and it shall contain one Slice Differentiator value within the range of SD  (if the sdRanges attribute is present) or with any value (if the wildcardSd attribute is present).
 */

#ifndef _ext_snssai_H_
#define _ext_snssai_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "sd_range.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ext_snssai_s ext_snssai_t;
typedef enum { ext_snssai_WILDCARDSD_NULL = 0,
	       ext_snssai_WILDCARDSD__true } ext_snssai_wildcard_sd_e;

char *ext_snssai_wildcard_sd_ToString(ext_snssai_wildcard_sd_e wildcard_sd);

ext_snssai_wildcard_sd_e ext_snssai_wildcard_sd_FromString(char *wildcard_sd);
typedef struct ext_snssai_s {
	int sst;
	char *sd;
	list_t *sd_ranges;
	ext_snssai_wildcard_sd_e wildcard_sd;
} ext_snssai_t;

ext_snssai_t *ext_snssai_create(int sst, char *sd, list_t *sd_ranges,
                                ext_snssai_wildcard_sd_e wildcard_sd);
void ext_snssai_free(ext_snssai_t *ext_snssai);
ext_snssai_t *ext_snssai_parseFromJSON(cJSON *ext_snssaiJSON);
cJSON *ext_snssai_convertToJSON(ext_snssai_t *ext_snssai);
ext_snssai_t *ext_snssai_copy(ext_snssai_t *dst, ext_snssai_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ext_snssai_H_ */
