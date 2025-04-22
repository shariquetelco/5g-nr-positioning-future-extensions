/*
 * measurement_lte_for_mdt_any_of.h
 *
 *
 */

#ifndef _measurement_lte_for_mdt_any_of_H_
#define _measurement_lte_for_mdt_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { measurement_lte_for_mdt_any_of_NULL = 0,
	       measurement_lte_for_mdt_any_of_M1,
	       measurement_lte_for_mdt_any_of_M2,
	       measurement_lte_for_mdt_any_of_M3,
	       measurement_lte_for_mdt_any_of_M4_DL,
	       measurement_lte_for_mdt_any_of_M4_UL,
	       measurement_lte_for_mdt_any_of_M5_DL,
	       measurement_lte_for_mdt_any_of_M5_UL,
	       measurement_lte_for_mdt_any_of_M6_DL,
	       measurement_lte_for_mdt_any_of_M6_UL,
	       measurement_lte_for_mdt_any_of_M7_DL,
	       measurement_lte_for_mdt_any_of_M7_UL,
	       measurement_lte_for_mdt_any_of_M8,
	       measurement_lte_for_mdt_any_of_M9 }
measurement_lte_for_mdt_any_of_e;

char *measurement_lte_for_mdt_any_of_ToString(
	measurement_lte_for_mdt_any_of_e measurement_lte_for_mdt_any_of);

measurement_lte_for_mdt_any_of_e measurement_lte_for_mdt_any_of_FromString(
	char *measurement_lte_for_mdt_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _measurement_lte_for_mdt_any_of_H_ */
