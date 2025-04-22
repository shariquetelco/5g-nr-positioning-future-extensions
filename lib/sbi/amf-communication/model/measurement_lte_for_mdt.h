/*
 * measurement_lte_for_mdt.h
 *
 * The enumeration MeasurementLteForMdt defines Measurements used for MDT in LTE in the trace. See 3GPP TS 32.422 for further description of the values. It shall comply with the provisions defined in table 5.6.3.5-1.
 */

#ifndef _measurement_lte_for_mdt_H_
#define _measurement_lte_for_mdt_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "measurement_lte_for_mdt_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct measurement_lte_for_mdt_s measurement_lte_for_mdt_t;
typedef struct measurement_lte_for_mdt_s {} measurement_lte_for_mdt_t;

measurement_lte_for_mdt_t *measurement_lte_for_mdt_create();
void measurement_lte_for_mdt_free(
	measurement_lte_for_mdt_t *measurement_lte_for_mdt);
measurement_lte_for_mdt_t *measurement_lte_for_mdt_parseFromJSON(
	cJSON *measurement_lte_for_mdtJSON);
cJSON *measurement_lte_for_mdt_convertToJSON(
	measurement_lte_for_mdt_t *measurement_lte_for_mdt);
measurement_lte_for_mdt_t *measurement_lte_for_mdt_copy(
	measurement_lte_for_mdt_t *dst, measurement_lte_for_mdt_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _measurement_lte_for_mdt_H_ */
