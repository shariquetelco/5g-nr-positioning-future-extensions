/*
 * battery_indication.h
 *
 * Parameters \&quot;replaceableInd\&quot; and \&quot;rechargeableInd\&quot; are only included if the value of Parameter \&quot;batteryInd\&quot; is true.
 */

#ifndef _battery_indication_H_
#define _battery_indication_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct battery_indication_s battery_indication_t;
typedef struct battery_indication_s {
	bool is_battery_ind;
	int battery_ind;
	bool is_replaceable_ind;
	int replaceable_ind;
	bool is_rechargeable_ind;
	int rechargeable_ind;
} battery_indication_t;

battery_indication_t *battery_indication_create(bool	is_battery_ind,
                                                int	battery_ind,
                                                bool	is_replaceable_ind,
                                                int	replaceable_ind,
                                                bool	is_rechargeable_ind,
                                                int	rechargeable_ind);
void battery_indication_free(battery_indication_t *battery_indication);
battery_indication_t *battery_indication_parseFromJSON(
	cJSON *battery_indicationJSON);
cJSON *battery_indication_convertToJSON(
	battery_indication_t *battery_indication);
battery_indication_t *battery_indication_copy(battery_indication_t	*dst,
                                              battery_indication_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _battery_indication_H_ */
