/*
 * uncertainty_ellipsoid.h
 *
 * Ellipsoid with uncertainty
 */

#ifndef _uncertainty_ellipsoid_H_
#define _uncertainty_ellipsoid_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct uncertainty_ellipsoid_s uncertainty_ellipsoid_t;
typedef struct uncertainty_ellipsoid_s {
	float semi_major;
	float semi_minor;
	float vertical;
	int orientation_major;
} uncertainty_ellipsoid_t;

uncertainty_ellipsoid_t *uncertainty_ellipsoid_create(float	semi_major,
                                                      float	semi_minor,
                                                      float	vertical,
                                                      int	orientation_major);
void uncertainty_ellipsoid_free(uncertainty_ellipsoid_t *uncertainty_ellipsoid);
uncertainty_ellipsoid_t *uncertainty_ellipsoid_parseFromJSON(
	cJSON *uncertainty_ellipsoidJSON);
cJSON *uncertainty_ellipsoid_convertToJSON(
	uncertainty_ellipsoid_t *uncertainty_ellipsoid);
uncertainty_ellipsoid_t *uncertainty_ellipsoid_copy(
	uncertainty_ellipsoid_t *dst, uncertainty_ellipsoid_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _uncertainty_ellipsoid_H_ */
