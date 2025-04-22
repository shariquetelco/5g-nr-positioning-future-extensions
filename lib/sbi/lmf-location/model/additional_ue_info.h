/*
 * additional_ue_info.h
 *
 * MBSR UE Information
 */

#ifndef _additional_ue_info_H_
#define _additional_ue_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ecgi.h"
#include "ncgi.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct additional_ue_info_s additional_ue_info_t;
typedef struct additional_ue_info_s {
	struct ncgi_s *ncgi;
	struct ecgi_s *ecgi;
} additional_ue_info_t;

additional_ue_info_t *additional_ue_info_create(ncgi_t *ncgi, ecgi_t *ecgi);
void additional_ue_info_free(additional_ue_info_t *additional_ue_info);
additional_ue_info_t *additional_ue_info_parseFromJSON(
	cJSON *additional_ue_infoJSON);
cJSON *additional_ue_info_convertToJSON(
	additional_ue_info_t *additional_ue_info);
additional_ue_info_t *additional_ue_info_copy(additional_ue_info_t	*dst,
                                              additional_ue_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _additional_ue_info_H_ */
