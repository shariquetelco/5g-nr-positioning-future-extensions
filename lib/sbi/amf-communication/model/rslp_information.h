/*
 * rslp_information.h
 *
 * Represents Ranging/SL positioning related N2 information.
 */

#ifndef _rslp_information_H_
#define _rslp_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_content.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rslp_information_s rslp_information_t;
typedef struct rslp_information_s {
	struct n2_info_content_s *n2_pc5_rslp_pol;
} rslp_information_t;

rslp_information_t *rslp_information_create(n2_info_content_t *n2_pc5_rslp_pol);
void rslp_information_free(rslp_information_t *rslp_information);
rslp_information_t *rslp_information_parseFromJSON(cJSON *rslp_informationJSON);
cJSON *rslp_information_convertToJSON(rslp_information_t *rslp_information);
rslp_information_t *rslp_information_copy(rslp_information_t	*dst,
                                          rslp_information_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _rslp_information_H_ */
