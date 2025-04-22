/*
 * access_token_err.h
 *
 * Error returned in the access token response message
 */

#ifndef _access_token_err_H_
#define _access_token_err_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct access_token_err_s access_token_err_t;
typedef enum { access_token_err_ERROR_NULL = 0,
	       access_token_err_ERROR_invalid_request,
	       access_token_err_ERROR_invalid_client,
	       access_token_err_ERROR_invalid_grant,
	       access_token_err_ERROR_unauthorized_client,
	       access_token_err_ERROR_unsupported_grant_type,
	       access_token_err_ERROR_invalid_scope } access_token_err_error_e;

char *access_token_err_error_ToString(access_token_err_error_e error);

access_token_err_error_e access_token_err_error_FromString(char *error);
typedef struct access_token_err_s {
	access_token_err_error_e error;
	char *error_description;
	char *error_uri;
} access_token_err_t;

access_token_err_t *access_token_err_create(access_token_err_error_e	error,
                                            char			*error_description,
                                            char			*error_uri);
void access_token_err_free(access_token_err_t *access_token_err);
access_token_err_t *access_token_err_parseFromJSON(cJSON *access_token_errJSON);
cJSON *access_token_err_convertToJSON(access_token_err_t *access_token_err);
access_token_err_t *access_token_err_copy(access_token_err_t	*dst,
                                          access_token_err_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _access_token_err_H_ */
