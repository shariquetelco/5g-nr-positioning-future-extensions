/*
 * slice_mbr.h
 *
 * MBR related to slice
 */

#ifndef _slice_mbr_H_
#define _slice_mbr_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct slice_mbr_s slice_mbr_t;
typedef struct slice_mbr_s {
	char *uplink;
	char *downlink;
} slice_mbr_t;

slice_mbr_t *slice_mbr_create(char *uplink, char *downlink);
void slice_mbr_free(slice_mbr_t *slice_mbr);
slice_mbr_t *slice_mbr_parseFromJSON(cJSON *slice_mbrJSON);
cJSON *slice_mbr_convertToJSON(slice_mbr_t *slice_mbr);
slice_mbr_t *slice_mbr_copy(slice_mbr_t *dst, slice_mbr_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _slice_mbr_H_ */
