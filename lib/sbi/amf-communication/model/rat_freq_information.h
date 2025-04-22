/*
 * rat_freq_information.h
 *
 * Represents the RAT type and/or Frequency information.
 */

#ifndef _rat_freq_information_H_
#define _rat_freq_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "matching_direction.h"
#include "rat_type.h"
#include "threshold_level.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rat_freq_information_s rat_freq_information_t;
typedef struct rat_freq_information_s {
	bool is_all_freq;
	int all_freq;
	bool is_all_rat;
	int all_rat;
	bool is_freq;
	int freq;
	struct rat_type_s *rat_type;
	struct threshold_level_s *svc_exp_threshold;
	struct matching_direction_s *matching_dir;
} rat_freq_information_t;

rat_freq_information_t *rat_freq_information_create(bool is_all_freq,
                                                    int all_freq,
                                                    bool is_all_rat,
                                                    int all_rat, bool is_freq,
                                                    int freq,
                                                    rat_type_t *rat_type,
                                                    threshold_level_t *svc_exp_threshold, matching_direction_t *matching_dir);
void rat_freq_information_free(rat_freq_information_t *rat_freq_information);
rat_freq_information_t *rat_freq_information_parseFromJSON(
	cJSON *rat_freq_informationJSON);
cJSON *rat_freq_information_convertToJSON(
	rat_freq_information_t *rat_freq_information);
rat_freq_information_t *rat_freq_information_copy(
	rat_freq_information_t	*dst,
	rat_freq_information_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _rat_freq_information_H_ */
