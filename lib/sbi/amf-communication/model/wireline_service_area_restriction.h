/*
 * wireline_service_area_restriction.h
 *
 * The \&quot;restrictionType\&quot; attribute and the \&quot;areas\&quot; attribute shall be either both present or absent.  The empty array of areas is used when service is allowed/restricted nowhere.
 */

#ifndef _wireline_service_area_restriction_H_
#define _wireline_service_area_restriction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "restriction_type.h"
#include "wireline_area.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct wireline_service_area_restriction_s
        wireline_service_area_restriction_t;
typedef struct wireline_service_area_restriction_s {
	struct restriction_type_s *restriction_type;
	list_t *areas;
} wireline_service_area_restriction_t;

wireline_service_area_restriction_t *wireline_service_area_restriction_create(
	restriction_type_t *restriction_type, list_t *areas);
void wireline_service_area_restriction_free(
	wireline_service_area_restriction_t *wireline_service_area_restriction);
wireline_service_area_restriction_t *
wireline_service_area_restriction_parseFromJSON(
	cJSON *wireline_service_area_restrictionJSON);
cJSON *wireline_service_area_restriction_convertToJSON(
	wireline_service_area_restriction_t *wireline_service_area_restriction);
wireline_service_area_restriction_t *wireline_service_area_restriction_copy(
	wireline_service_area_restriction_t	*dst,
	wireline_service_area_restriction_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _wireline_service_area_restriction_H_ */
