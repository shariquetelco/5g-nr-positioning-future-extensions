/*
 * mbsr_info.h
 *
 * MBSR Information
 */

#ifndef _mbsr_info_H_
#define _mbsr_info_H_

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

typedef struct mbsr_info_s mbsr_info_t;
typedef struct mbsr_info_s {
	struct ncgi_s *ncgi;
	struct ecgi_s *ecgi;
} mbsr_info_t;

mbsr_info_t *mbsr_info_create(ncgi_t *ncgi, ecgi_t *ecgi);
void mbsr_info_free(mbsr_info_t *mbsr_info);
mbsr_info_t *mbsr_info_parseFromJSON(cJSON *mbsr_infoJSON);
cJSON *mbsr_info_convertToJSON(mbsr_info_t *mbsr_info);
mbsr_info_t *mbsr_info_copy(mbsr_info_t *dst, mbsr_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _mbsr_info_H_ */
