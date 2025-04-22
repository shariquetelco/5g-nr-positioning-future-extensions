/*
 * uncertainty_ellipse.h
 *
 * Ellipse with uncertainty.
 */

#ifndef _uncertainty_ellipse_H_
#define _uncertainty_ellipse_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct uncertainty_ellipse_s uncertainty_ellipse_t;
typedef struct uncertainty_ellipse_s {
	float semi_major;
	float semi_minor;
	int orientation_major;
} uncertainty_ellipse_t;

uncertainty_ellipse_t *uncertainty_ellipse_create(float semi_major,
                                                  float semi_minor,
                                                  int	orientation_major);
void uncertainty_ellipse_free(uncertainty_ellipse_t *uncertainty_ellipse);
uncertainty_ellipse_t *uncertainty_ellipse_parseFromJSON(
	cJSON *uncertainty_ellipseJSON);
cJSON *uncertainty_ellipse_convertToJSON(
	uncertainty_ellipse_t *uncertainty_ellipse);
uncertainty_ellipse_t *uncertainty_ellipse_copy(uncertainty_ellipse_t	*dst,
                                                uncertainty_ellipse_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _uncertainty_ellipse_H_ */
