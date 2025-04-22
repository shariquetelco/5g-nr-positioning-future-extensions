/*
 * problem_details.h
 *
 * Provides additional information in an error response.
 */

#ifndef _problem_details_H_
#define _problem_details_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "access_token_err.h"
#include "access_token_req.h"
#include "invalid_param.h"
#include "no_profile_match_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct problem_details_s problem_details_t;
typedef struct problem_details_s {
	char *type;
	char *title;
	bool is_status;
	int status;
	char *detail;
	char *instance;
	char *cause;
	list_t *invalid_params;
	char *supported_features;
	struct access_token_err_s *access_token_error;
	struct access_token_req_s *access_token_request;
	char *nrf_id;
	list_t *supported_api_versions;
	struct no_profile_match_info_s *no_profile_match_info;
} problem_details_t;

problem_details_t *problem_details_create(char *type, char *title,
                                          bool is_status, int status,
                                          char *detail, char *instance,
                                          char *cause, list_t *invalid_params,
                                          char *supported_features,
                                          access_token_err_t *access_token_error, access_token_req_t *access_token_request, char *nrf_id, list_t *supported_api_versions, no_profile_match_info_t *no_profile_match_info);
void problem_details_free(problem_details_t *problem_details);
problem_details_t *problem_details_parseFromJSON(cJSON *problem_detailsJSON);
cJSON *problem_details_convertToJSON(problem_details_t *problem_details);
problem_details_t *problem_details_copy(problem_details_t	*dst,
                                        problem_details_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _problem_details_H_ */
