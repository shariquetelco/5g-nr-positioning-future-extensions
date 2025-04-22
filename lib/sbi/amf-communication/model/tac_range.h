/*
 * tac_range.h
 *
 * Range of TACs (Tracking Area Codes)
 */

#ifndef _tac_range_H_
#define _tac_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tac_range_s tac_range_t;
typedef struct tac_range_s {
	char *start;
	char *end;
	char *pattern;
} tac_range_t;

tac_range_t *tac_range_create(char *start, char *end, char *pattern);
void tac_range_free(tac_range_t *tac_range);
tac_range_t *tac_range_parseFromJSON(cJSON *tac_rangeJSON);
cJSON *tac_range_convertToJSON(tac_range_t *tac_range);
tac_range_t *tac_range_copy(tac_range_t *dst, tac_range_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _tac_range_H_ */
