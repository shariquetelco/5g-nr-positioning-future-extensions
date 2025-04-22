/*
 * bw_requirement.h
 *
 * Represents bandwidth requirements.
 */

#ifndef _bw_requirement_H_
#define _bw_requirement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct bw_requirement_s bw_requirement_t;
typedef struct bw_requirement_s {
	char *app_id;
	char *mar_bw_dl;
	char *mar_bw_ul;
	char *mir_bw_dl;
	char *mir_bw_ul;
} bw_requirement_t;

bw_requirement_t *bw_requirement_create(char *app_id, char *mar_bw_dl,
                                        char *mar_bw_ul, char *mir_bw_dl,
                                        char *mir_bw_ul);
void bw_requirement_free(bw_requirement_t *bw_requirement);
bw_requirement_t *bw_requirement_parseFromJSON(cJSON *bw_requirementJSON);
cJSON *bw_requirement_convertToJSON(bw_requirement_t *bw_requirement);
bw_requirement_t *bw_requirement_copy(bw_requirement_t	*dst,
                                      bw_requirement_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _bw_requirement_H_ */
