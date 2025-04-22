/*
 * ssc_mode.h
 *
 * represents the service and session continuity mode It shall comply with the provisions defined in table 5.4.3.6-1.
 */

#ifndef _ssc_mode_H_
#define _ssc_mode_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ssc_mode_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ssc_mode_s ssc_mode_t;
typedef struct ssc_mode_s {} ssc_mode_t;

ssc_mode_t *ssc_mode_create();
void ssc_mode_free(ssc_mode_t *ssc_mode);
ssc_mode_t *ssc_mode_parseFromJSON(cJSON *ssc_modeJSON);
cJSON *ssc_mode_convertToJSON(ssc_mode_t *ssc_mode);
ssc_mode_t *ssc_mode_copy(ssc_mode_t *dst, ssc_mode_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ssc_mode_H_ */
