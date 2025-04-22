/*
 * pfd_determination_info.h
 *
 * Represents the PFD Determination information for a known application identifier.
 */

#ifndef _pfd_determination_info_H_
#define _pfd_determination_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "snssai.h"
#include "suggested_pfd_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pfd_determination_info_s pfd_determination_info_t;
typedef struct pfd_determination_info_s {
	char *app_id;
	struct snssai_s *snssai;
	char *dnn;
	list_t *sugg_pfd_info_list;
} pfd_determination_info_t;

pfd_determination_info_t *pfd_determination_info_create(char		*app_id,
                                                        snssai_t	*snssai,
                                                        char		*dnn,
                                                        list_t		*sugg_pfd_info_list);
void pfd_determination_info_free(
	pfd_determination_info_t *pfd_determination_info);
pfd_determination_info_t *pfd_determination_info_parseFromJSON(
	cJSON *pfd_determination_infoJSON);
cJSON *pfd_determination_info_convertToJSON(
	pfd_determination_info_t *pfd_determination_info);
pfd_determination_info_t *pfd_determination_info_copy(
	pfd_determination_info_t *dst, pfd_determination_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _pfd_determination_info_H_ */
