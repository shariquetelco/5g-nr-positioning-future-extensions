/*
 * positioning_method_mdt.h
 *
 * The enumeration LoggingDurationMdt defines Logging Duration for MDT in the trace. See 3GPP TS 32.422 for further description of the values. It shall comply with the provisions defined in table 5.6.3.13-1.
 */

#ifndef _positioning_method_mdt_H_
#define _positioning_method_mdt_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "positioning_method_mdt_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct positioning_method_mdt_s positioning_method_mdt_t;
typedef struct positioning_method_mdt_s {} positioning_method_mdt_t;

positioning_method_mdt_t *positioning_method_mdt_create();
void positioning_method_mdt_free(
	positioning_method_mdt_t *positioning_method_mdt);
positioning_method_mdt_t *positioning_method_mdt_parseFromJSON(
	cJSON *positioning_method_mdtJSON);
cJSON *positioning_method_mdt_convertToJSON(
	positioning_method_mdt_t *positioning_method_mdt);
positioning_method_mdt_t *positioning_method_mdt_copy(
	positioning_method_mdt_t *dst, positioning_method_mdt_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _positioning_method_mdt_H_ */
