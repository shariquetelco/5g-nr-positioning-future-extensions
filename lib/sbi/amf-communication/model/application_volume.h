/*
 * application_volume.h
 *
 * Application data volume per Application Id.
 */

#ifndef _application_volume_H_
#define _application_volume_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct application_volume_s application_volume_t;
typedef struct application_volume_s {
	char *app_id;
	long app_volume;
} application_volume_t;

application_volume_t *application_volume_create(char *app_id, long app_volume);
void application_volume_free(application_volume_t *application_volume);
application_volume_t *application_volume_parseFromJSON(
	cJSON *application_volumeJSON);
cJSON *application_volume_convertToJSON(
	application_volume_t *application_volume);
application_volume_t *application_volume_copy(application_volume_t	*dst,
                                              application_volume_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _application_volume_H_ */
