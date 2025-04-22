/*
 * stationary_indication.h
 *
 * Possible values are: - STATIONARY: Identifies the UE is stationary - MOBILE: Identifies the UE is mobile
 */

#ifndef _stationary_indication_H_
#define _stationary_indication_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "stationary_indication_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct stationary_indication_s stationary_indication_t;
typedef struct stationary_indication_s {} stationary_indication_t;

stationary_indication_t *stationary_indication_create();
void stationary_indication_free(stationary_indication_t *stationary_indication);
stationary_indication_t *stationary_indication_parseFromJSON(
	cJSON *stationary_indicationJSON);
cJSON *stationary_indication_convertToJSON(
	stationary_indication_t *stationary_indication);
stationary_indication_t *stationary_indication_copy(
	stationary_indication_t *dst, stationary_indication_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _stationary_indication_H_ */
