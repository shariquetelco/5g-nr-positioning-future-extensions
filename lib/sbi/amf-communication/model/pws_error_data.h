/*
 * pws_error_data.h
 *
 * Data related to PWS error included in a N2 Information Transfer failure response
 */

#ifndef _pws_error_data_H_
#define _pws_error_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pws_error_data_s pws_error_data_t;
typedef struct pws_error_data_s {
	int namf_cause;
} pws_error_data_t;

pws_error_data_t *pws_error_data_create(int namf_cause);
void pws_error_data_free(pws_error_data_t *pws_error_data);
pws_error_data_t *pws_error_data_parseFromJSON(cJSON *pws_error_dataJSON);
cJSON *pws_error_data_convertToJSON(pws_error_data_t *pws_error_data);
pws_error_data_t *pws_error_data_copy(pws_error_data_t	*dst,
                                      pws_error_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _pws_error_data_H_ */
