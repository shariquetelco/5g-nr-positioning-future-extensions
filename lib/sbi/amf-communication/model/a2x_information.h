/*
 * a2x_information.h
 *
 * A2X related N2 information
 */

#ifndef _a2x_information_H_
#define _a2x_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_content.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct a2x_information_s a2x_information_t;
typedef struct a2x_information_s {
	struct n2_info_content_s *n2_pc5_pol;
} a2x_information_t;

a2x_information_t *a2x_information_create(n2_info_content_t *n2_pc5_pol);
void a2x_information_free(a2x_information_t *a2x_information);
a2x_information_t *a2x_information_parseFromJSON(cJSON *a2x_informationJSON);
cJSON *a2x_information_convertToJSON(a2x_information_t *a2x_information);
a2x_information_t *a2x_information_copy(a2x_information_t	*dst,
                                        a2x_information_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _a2x_information_H_ */
