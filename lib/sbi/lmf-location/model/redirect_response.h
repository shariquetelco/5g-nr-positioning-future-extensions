/*
 * redirect_response.h
 *
 * The response shall include a Location header field containing a different URI  (pointing to a different URI of an other service instance), or the same URI if a request  is redirected to the same target resource via a different SCP.
 */

#ifndef _redirect_response_H_
#define _redirect_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct redirect_response_s redirect_response_t;
typedef struct redirect_response_s {
	char *cause;
	char *target_scp;
	char *target_sepp;
} redirect_response_t;

redirect_response_t *redirect_response_create(char *cause, char *target_scp,
                                              char *target_sepp);
void redirect_response_free(redirect_response_t *redirect_response);
redirect_response_t *redirect_response_parseFromJSON(
	cJSON *redirect_responseJSON);
cJSON *redirect_response_convertToJSON(redirect_response_t *redirect_response);
redirect_response_t *redirect_response_copy(redirect_response_t *dst,
                                            redirect_response_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _redirect_response_H_ */
