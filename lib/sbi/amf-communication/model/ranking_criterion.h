/*
 * ranking_criterion.h
 *
 * Indicates the usage ranking criterion between the high, medium and low usage UE.
 */

#ifndef _ranking_criterion_H_
#define _ranking_criterion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ranking_criterion_s ranking_criterion_t;
typedef struct ranking_criterion_s {
	int high_base;
	int low_base;
} ranking_criterion_t;

ranking_criterion_t *ranking_criterion_create(int high_base, int low_base);
void ranking_criterion_free(ranking_criterion_t *ranking_criterion);
ranking_criterion_t *ranking_criterion_parseFromJSON(
	cJSON *ranking_criterionJSON);
cJSON *ranking_criterion_convertToJSON(ranking_criterion_t *ranking_criterion);
ranking_criterion_t *ranking_criterion_copy(ranking_criterion_t *dst,
                                            ranking_criterion_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ranking_criterion_H_ */
