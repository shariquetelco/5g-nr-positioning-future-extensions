/*
 * clock_quality.h
 *
 * Contains Clock Quality.
 */

#ifndef _clock_quality_H_
#define _clock_quality_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct clock_quality_s clock_quality_t;
typedef struct clock_quality_s {
	bool is_traceability_to_gnss;
	int traceability_to_gnss;
	bool is_traceability_to_utc;
	int traceability_to_utc;
	bool is_frequency_stability;
	int frequency_stability;
	char *clock_accuracy_index;
	bool is_clock_accuracy_value;
	int clock_accuracy_value;
} clock_quality_t;

clock_quality_t *clock_quality_create(bool	is_traceability_to_gnss,
                                      int	traceability_to_gnss,
                                      bool	is_traceability_to_utc,
                                      int	traceability_to_utc,
                                      bool	is_frequency_stability,
                                      int	frequency_stability,
                                      char	*clock_accuracy_index,
                                      bool	is_clock_accuracy_value,
                                      int	clock_accuracy_value);
void clock_quality_free(clock_quality_t *clock_quality);
clock_quality_t *clock_quality_parseFromJSON(cJSON *clock_qualityJSON);
cJSON *clock_quality_convertToJSON(clock_quality_t *clock_quality);
clock_quality_t *clock_quality_copy(clock_quality_t *dst, clock_quality_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _clock_quality_H_ */
