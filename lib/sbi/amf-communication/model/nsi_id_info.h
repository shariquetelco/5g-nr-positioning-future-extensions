/*
 * nsi_id_info.h
 *
 * Represents the S-NSSAI and the optionally associated Network Slice Instance(s).
 */

#ifndef _nsi_id_info_H_
#define _nsi_id_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nsi_id_info_s nsi_id_info_t;
typedef struct nsi_id_info_s {
	struct snssai_s *snssai;
	list_t *nsi_ids;
} nsi_id_info_t;

nsi_id_info_t *nsi_id_info_create(snssai_t *snssai, list_t *nsi_ids);
void nsi_id_info_free(nsi_id_info_t *nsi_id_info);
nsi_id_info_t *nsi_id_info_parseFromJSON(cJSON *nsi_id_infoJSON);
cJSON *nsi_id_info_convertToJSON(nsi_id_info_t *nsi_id_info);
nsi_id_info_t *nsi_id_info_copy(nsi_id_info_t *dst, nsi_id_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _nsi_id_info_H_ */
