/*
 * ambr.h
 *
 * Contains the maximum aggregated uplink and downlink bit rates.
 */

#ifndef _ambr_H_
#define _ambr_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ambr_s ambr_t;
typedef struct ambr_s {
	char *uplink;
	char *downlink;
} ambr_t;

ambr_t *ambr_create(char *uplink, char *downlink);
void ambr_free(ambr_t *ambr);
ambr_t *ambr_parseFromJSON(cJSON *ambrJSON);
cJSON *ambr_convertToJSON(ambr_t *ambr);
ambr_t *ambr_copy(ambr_t *dst, ambr_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ambr_H_ */
