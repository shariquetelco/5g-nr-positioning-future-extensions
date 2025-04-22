/*
 * snssai_extension.h
 *
 * Extensions to the Snssai data type, sdRanges and wildcardSd shall not be present simultaneously
 */

#ifndef _snssai_extension_H_
#define _snssai_extension_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "sd_range.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct snssai_extension_s snssai_extension_t;
typedef enum { snssai_extension_WILDCARDSD_NULL = 0,
	       snssai_extension_WILDCARDSD__true }
snssai_extension_wildcard_sd_e;

char *snssai_extension_wildcard_sd_ToString(
	snssai_extension_wildcard_sd_e wildcard_sd);

snssai_extension_wildcard_sd_e snssai_extension_wildcard_sd_FromString(
	char *wildcard_sd);
typedef struct snssai_extension_s {
	list_t *sd_ranges;
	snssai_extension_wildcard_sd_e wildcard_sd;
} snssai_extension_t;

snssai_extension_t *snssai_extension_create(
	list_t				*sd_ranges,
	snssai_extension_wildcard_sd_e	wildcard_sd);
void snssai_extension_free(snssai_extension_t *snssai_extension);
snssai_extension_t *snssai_extension_parseFromJSON(cJSON *snssai_extensionJSON);
cJSON *snssai_extension_convertToJSON(snssai_extension_t *snssai_extension);
snssai_extension_t *snssai_extension_copy(snssai_extension_t	*dst,
                                          snssai_extension_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _snssai_extension_H_ */
