/*
 * reporting_area.h
 *
 * Indicates an area for event reporting.
 */

#ifndef _reporting_area_H_
#define _reporting_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ecgi.h"
#include "ncgi.h"
#include "reporting_area_type.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct reporting_area_s reporting_area_t;
typedef struct reporting_area_s {
	reporting_area_type_e area_type;
	struct tai_s *tai;
	struct ecgi_s *ecgi;
	struct ncgi_s *ncgi;
} reporting_area_t;

reporting_area_t *reporting_area_create(reporting_area_type_e area_type,
                                        tai_t *tai, ecgi_t *ecgi, ncgi_t *ncgi);
void reporting_area_free(reporting_area_t *reporting_area);
reporting_area_t *reporting_area_parseFromJSON(cJSON *reporting_areaJSON);
cJSON *reporting_area_convertToJSON(reporting_area_t *reporting_area);
reporting_area_t *reporting_area_copy(reporting_area_t	*dst,
                                      reporting_area_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _reporting_area_H_ */
