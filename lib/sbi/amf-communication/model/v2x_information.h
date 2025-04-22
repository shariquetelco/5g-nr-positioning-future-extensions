/*
 * v2x_information.h
 *
 * V2X related N2 information
 */

#ifndef _v2x_information_H_
#define _v2x_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_content.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct v2x_information_s v2x_information_t;
typedef struct v2x_information_s {
	struct n2_info_content_s *n2_pc5_pol;
} v2x_information_t;

v2x_information_t *v2x_information_create(n2_info_content_t *n2_pc5_pol);
void v2x_information_free(v2x_information_t *v2x_information);
v2x_information_t *v2x_information_parseFromJSON(cJSON *v2x_informationJSON);
cJSON *v2x_information_convertToJSON(v2x_information_t *v2x_information);
v2x_information_t *v2x_information_copy(v2x_information_t	*dst,
                                        v2x_information_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _v2x_information_H_ */
