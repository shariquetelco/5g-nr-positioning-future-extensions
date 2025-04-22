/*
 * reporting_ind.h
 *
 * Indicates whether the UE is allowed to generate and send the event report inside or outside the event report allowed(expected) area
 */

#ifndef _reporting_ind_H_
#define _reporting_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "reporting_ind_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct reporting_ind_s reporting_ind_t;
typedef struct reporting_ind_s {
	reporting_ind_any_of_e ind;	//NK: Solution for anyOf! :-)
} reporting_ind_t;

reporting_ind_t *reporting_ind_create();
void reporting_ind_free(reporting_ind_t *reporting_ind);
reporting_ind_t *reporting_ind_parseFromJSON(cJSON *reporting_indJSON);
cJSON *reporting_ind_convertToJSON(reporting_ind_t *reporting_ind);
reporting_ind_t *reporting_ind_copy(reporting_ind_t *dst, reporting_ind_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _reporting_ind_H_ */
