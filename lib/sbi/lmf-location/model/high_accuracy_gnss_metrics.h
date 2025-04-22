/*
 * high_accuracy_gnss_metrics.h
 *
 * High Accuracy GNSS Positioning Metrics.
 */

#ifndef _high_accuracy_gnss_metrics_H_
#define _high_accuracy_gnss_metrics_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "fix_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct high_accuracy_gnss_metrics_s high_accuracy_gnss_metrics_t;
typedef struct high_accuracy_gnss_metrics_s {
	bool is_nr_of_used_satellites;
	int nr_of_used_satellites;
	bool is_hdopi;
	int hdopi;
	bool is_pdopi;
	int pdopi;
	bool is_age;
	int age;
	fix_type_e fix_type;
} high_accuracy_gnss_metrics_t;

high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_create(
	bool is_nr_of_used_satellites, int nr_of_used_satellites, bool is_hdopi,
	int hdopi, bool is_pdopi, int pdopi, bool is_age, int age,
	fix_type_e fix_type);
void high_accuracy_gnss_metrics_free(
	high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);
high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_parseFromJSON(
	cJSON *high_accuracy_gnss_metricsJSON);
cJSON *high_accuracy_gnss_metrics_convertToJSON(
	high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);
high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_copy(
	high_accuracy_gnss_metrics_t *dst, high_accuracy_gnss_metrics_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _high_accuracy_gnss_metrics_H_ */
