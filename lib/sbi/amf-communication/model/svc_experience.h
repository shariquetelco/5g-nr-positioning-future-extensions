/*
 * svc_experience.h
 *
 * Contains a mean opinion score with the customized range.
 */

#ifndef _svc_experience_H_
#define _svc_experience_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct svc_experience_s svc_experience_t;
typedef struct svc_experience_s {
	bool is_mos;
	float mos;
	bool is_upper_range;
	float upper_range;
	bool is_lower_range;
	float lower_range;
} svc_experience_t;

svc_experience_t *svc_experience_create(bool is_mos, float mos,
                                        bool is_upper_range, float upper_range,
                                        bool is_lower_range, float lower_range);
void svc_experience_free(svc_experience_t *svc_experience);
svc_experience_t *svc_experience_parseFromJSON(cJSON *svc_experienceJSON);
cJSON *svc_experience_convertToJSON(svc_experience_t *svc_experience);
svc_experience_t *svc_experience_copy(svc_experience_t	*dst,
                                      svc_experience_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _svc_experience_H_ */
