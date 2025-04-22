/*
 * n2_ran_information.h
 *
 * Represents the RAN related N2 information data part
 */

#ifndef _n2_ran_information_H_
#define _n2_ran_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_content.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n2_ran_information_s n2_ran_information_t;
typedef struct n2_ran_information_s {
	struct n2_info_content_s *n2_info_content;
} n2_ran_information_t;

n2_ran_information_t *n2_ran_information_create(
	n2_info_content_t *n2_info_content);
void n2_ran_information_free(n2_ran_information_t *n2_ran_information);
n2_ran_information_t *n2_ran_information_parseFromJSON(
	cJSON *n2_ran_informationJSON);
cJSON *n2_ran_information_convertToJSON(
	n2_ran_information_t *n2_ran_information);
n2_ran_information_t *n2_ran_information_copy(n2_ran_information_t	*dst,
                                              n2_ran_information_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _n2_ran_information_H_ */
