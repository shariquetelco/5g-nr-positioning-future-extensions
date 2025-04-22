/*
 * measurement_period_lte_mdt.h
 *
 * The enumeration MeasurementPeriodLteMdt defines Measurement period LTE for MDT in the trace.  See 3GPP TS 32.422 for further description of the values. It shall comply with the provisions defined in table 5.6.3.16-1.
 */

#ifndef _measurement_period_lte_mdt_H_
#define _measurement_period_lte_mdt_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "collection_period_rmm_lte_mdt_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct measurement_period_lte_mdt_s measurement_period_lte_mdt_t;
typedef struct measurement_period_lte_mdt_s {} measurement_period_lte_mdt_t;

measurement_period_lte_mdt_t *measurement_period_lte_mdt_create();
void measurement_period_lte_mdt_free(
	measurement_period_lte_mdt_t *measurement_period_lte_mdt);
measurement_period_lte_mdt_t *measurement_period_lte_mdt_parseFromJSON(
	cJSON *measurement_period_lte_mdtJSON);
cJSON *measurement_period_lte_mdt_convertToJSON(
	measurement_period_lte_mdt_t *measurement_period_lte_mdt);
measurement_period_lte_mdt_t *measurement_period_lte_mdt_copy(
	measurement_period_lte_mdt_t *dst, measurement_period_lte_mdt_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _measurement_period_lte_mdt_H_ */
