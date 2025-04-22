/*
 * ec_restriction_data_wb.h
 *
 * Enhanced Coverage Restriction Data for WB-N1 mode
 */

#ifndef _ec_restriction_data_wb_H_
#define _ec_restriction_data_wb_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ec_restriction_data_wb_s ec_restriction_data_wb_t;
typedef struct ec_restriction_data_wb_s {
	bool is_ec_mode_a_restricted;
	int ec_mode_a_restricted;
	int ec_mode_b_restricted;
} ec_restriction_data_wb_t;

ec_restriction_data_wb_t *ec_restriction_data_wb_create(
	bool is_ec_mode_a_restricted, int ec_mode_a_restricted,
	int ec_mode_b_restricted);
void ec_restriction_data_wb_free(
	ec_restriction_data_wb_t *ec_restriction_data_wb);
ec_restriction_data_wb_t *ec_restriction_data_wb_parseFromJSON(
	cJSON *ec_restriction_data_wbJSON);
cJSON *ec_restriction_data_wb_convertToJSON(
	ec_restriction_data_wb_t *ec_restriction_data_wb);
ec_restriction_data_wb_t *ec_restriction_data_wb_copy(
	ec_restriction_data_wb_t *dst, ec_restriction_data_wb_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ec_restriction_data_wb_H_ */
