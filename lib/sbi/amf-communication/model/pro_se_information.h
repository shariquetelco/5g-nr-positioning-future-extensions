/*
 * pro_se_information.h
 *
 * Represents 5G ProSe related N2 information.
 */

#ifndef _pro_se_information_H_
#define _pro_se_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_content.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pro_se_information_s pro_se_information_t;
typedef struct pro_se_information_s {
	struct n2_info_content_s *n2_pc5_pro_se_pol;
} pro_se_information_t;

pro_se_information_t *pro_se_information_create(
	n2_info_content_t *n2_pc5_pro_se_pol);
void pro_se_information_free(pro_se_information_t *pro_se_information);
pro_se_information_t *pro_se_information_parseFromJSON(
	cJSON *pro_se_informationJSON);
cJSON *pro_se_information_convertToJSON(
	pro_se_information_t *pro_se_information);
pro_se_information_t *pro_se_information_copy(pro_se_information_t	*dst,
                                              pro_se_information_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _pro_se_information_H_ */
