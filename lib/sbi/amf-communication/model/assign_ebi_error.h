/*
 * assign_ebi_error.h
 *
 * Data within a failure response to the EBI assignment request
 */

#ifndef _assign_ebi_error_H_
#define _assign_ebi_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "assign_ebi_failed.h"
#include "problem_details.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct assign_ebi_error_s assign_ebi_error_t;
typedef struct assign_ebi_error_s {
	struct problem_details_s *error;
	struct assign_ebi_failed_s *failure_details;
} assign_ebi_error_t;

assign_ebi_error_t *assign_ebi_error_create(problem_details_t	*error,
                                            assign_ebi_failed_t *failure_details);
void assign_ebi_error_free(assign_ebi_error_t *assign_ebi_error);
assign_ebi_error_t *assign_ebi_error_parseFromJSON(cJSON *assign_ebi_errorJSON);
cJSON *assign_ebi_error_convertToJSON(assign_ebi_error_t *assign_ebi_error);
assign_ebi_error_t *assign_ebi_error_copy(assign_ebi_error_t	*dst,
                                          assign_ebi_error_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _assign_ebi_error_H_ */
