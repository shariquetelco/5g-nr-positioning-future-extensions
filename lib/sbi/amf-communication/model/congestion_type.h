/*
 * congestion_type.h
 *
 * Indicates the congestion analytics type.   Possible values are: - USER_PLANE: The congestion analytics type is User Plane. - CONTROL_PLANE: The congestion analytics type is Control Plane. - USER_AND_CONTROL_PLANE: The congestion analytics type is User Plane and Control Plane.
 */

#ifndef _congestion_type_H_
#define _congestion_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "congestion_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct congestion_type_s congestion_type_t;
typedef struct congestion_type_s {} congestion_type_t;

congestion_type_t *congestion_type_create();
void congestion_type_free(congestion_type_t *congestion_type);
congestion_type_t *congestion_type_parseFromJSON(cJSON *congestion_typeJSON);
cJSON *congestion_type_convertToJSON(congestion_type_t *congestion_type);
congestion_type_t *congestion_type_copy(congestion_type_t	*dst,
                                        congestion_type_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _congestion_type_H_ */
