/*
 * sd_range.h
 *
 * A range of SDs (Slice Differentiators)
 */

#ifndef _sd_range_H_
#define _sd_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sd_range_s sd_range_t;
typedef struct sd_range_s {
	char *start;
	char *end;
} sd_range_t;

sd_range_t *sd_range_create(char *start, char *end);
void sd_range_free(sd_range_t *sd_range);
sd_range_t *sd_range_parseFromJSON(cJSON *sd_rangeJSON);
cJSON *sd_range_convertToJSON(sd_range_t *sd_range);
sd_range_t *sd_range_copy(sd_range_t *dst, sd_range_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _sd_range_H_ */
