/*
 * alert_limit.h
 *
 * Alert Limit.
 */

#ifndef _alert_limit_H_
#define _alert_limit_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct alert_limit_s alert_limit_t;
typedef struct alert_limit_s {
	int horizontal_protection_level;
	bool is_vertical_protection_level;
	int vertical_protection_level;
} alert_limit_t;

alert_limit_t *alert_limit_create(int	horizontal_protection_level,
                                  bool	is_vertical_protection_level,
                                  int	vertical_protection_level);
void alert_limit_free(alert_limit_t *alert_limit);
alert_limit_t *alert_limit_parseFromJSON(cJSON *alert_limitJSON);
cJSON *alert_limit_convertToJSON(alert_limit_t *alert_limit);
alert_limit_t *alert_limit_copy(alert_limit_t *dst, alert_limit_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _alert_limit_H_ */
