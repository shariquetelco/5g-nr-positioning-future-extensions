/*
 * ciphering_set_report.h
 *
 * Represents a report of Ciphering Data Set storage.
 */

#ifndef _ciphering_set_report_H_
#define _ciphering_set_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "storage_outcome.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ciphering_set_report_s ciphering_set_report_t;
typedef struct ciphering_set_report_s {
	int ciphering_set_id;
	storage_outcome_e storage_outcome;
} ciphering_set_report_t;

ciphering_set_report_t *ciphering_set_report_create(
	int			ciphering_set_id,
	storage_outcome_e	storage_outcome);
void ciphering_set_report_free(ciphering_set_report_t *ciphering_set_report);
ciphering_set_report_t *ciphering_set_report_parseFromJSON(
	cJSON *ciphering_set_reportJSON);
cJSON *ciphering_set_report_convertToJSON(
	ciphering_set_report_t *ciphering_set_report);
ciphering_set_report_t *ciphering_set_report_copy(
	ciphering_set_report_t	*dst,
	ciphering_set_report_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ciphering_set_report_H_ */
