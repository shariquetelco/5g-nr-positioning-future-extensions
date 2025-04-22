/*
 * user_location.h
 *
 * At least one of eutraLocation, nrLocation and n3gaLocation shall be present. Several of them may be present.
 */

#ifndef _user_location_H_
#define _user_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "eutra_location.h"
#include "gera_location.h"
#include "n3ga_location.h"
#include "nr_location.h"
#include "utra_location.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct user_location_s user_location_t;
typedef struct user_location_s {
	struct eutra_location_s *eutra_location;
	struct nr_location_s *nr_location;
	struct n3ga_location_s *n3ga_location;
	struct utra_location_s *utra_location;
	struct gera_location_s *gera_location;
} user_location_t;

user_location_t *user_location_create(eutra_location_t	*eutra_location,
                                      nr_location_t	*nr_location,
                                      n3ga_location_t	*n3ga_location,
                                      utra_location_t	*utra_location,
                                      gera_location_t	*gera_location);
void user_location_free(user_location_t *user_location);
user_location_t *user_location_parseFromJSON(cJSON *user_locationJSON);
cJSON *user_location_convertToJSON(user_location_t *user_location);
user_location_t *user_location_copy(user_location_t *dst, user_location_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _user_location_H_ */
