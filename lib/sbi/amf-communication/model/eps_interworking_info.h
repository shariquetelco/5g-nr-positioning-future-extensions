/*
 * eps_interworking_info.h
 *
 * This information element contains the associations between APN/DNN and PGW-C+SMF selected by the AMF for EPS interworking.
 */

#ifndef _eps_interworking_info_H_
#define _eps_interworking_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "eps_iwk_pgw.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct eps_interworking_info_s eps_interworking_info_t;
typedef struct eps_interworking_info_s {
	list_t *eps_iwk_pgws;
	char *registration_time;
} eps_interworking_info_t;

eps_interworking_info_t *eps_interworking_info_create(list_t	*eps_iwk_pgws,
                                                      char	*registration_time);
void eps_interworking_info_free(eps_interworking_info_t *eps_interworking_info);
eps_interworking_info_t *eps_interworking_info_parseFromJSON(
	cJSON *eps_interworking_infoJSON);
cJSON *eps_interworking_info_convertToJSON(
	eps_interworking_info_t *eps_interworking_info);
eps_interworking_info_t *eps_interworking_info_copy(
	eps_interworking_info_t *dst, eps_interworking_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _eps_interworking_info_H_ */
