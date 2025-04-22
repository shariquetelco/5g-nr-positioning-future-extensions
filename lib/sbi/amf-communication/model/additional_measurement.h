/*
 * additional_measurement.h
 *
 * Represents additional measurement information.
 */

#ifndef _additional_measurement_H_
#define _additional_measurement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "address_list.h"
#include "circumstance_description.h"
#include "ip_eth_flow_description.h"
#include "network_area_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct additional_measurement_s additional_measurement_t;
typedef struct additional_measurement_s {
	struct network_area_info_s *unexp_loc;
	list_t *unexp_flow_teps;
	list_t *unexp_wakes;
	struct address_list_s *ddos_attack;
	struct address_list_s *wrg_dest;
	list_t *circums;
} additional_measurement_t;

additional_measurement_t *additional_measurement_create(
	network_area_info_t *unexp_loc, list_t *unexp_flow_teps,
	list_t *unexp_wakes, address_list_t *ddos_attack,
	address_list_t *wrg_dest, list_t *circums);
void additional_measurement_free(
	additional_measurement_t *additional_measurement);
additional_measurement_t *additional_measurement_parseFromJSON(
	cJSON *additional_measurementJSON);
cJSON *additional_measurement_convertToJSON(
	additional_measurement_t *additional_measurement);
additional_measurement_t *additional_measurement_copy(
	additional_measurement_t *dst, additional_measurement_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _additional_measurement_H_ */
