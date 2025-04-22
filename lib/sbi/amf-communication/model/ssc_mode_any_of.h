/*
 * ssc_mode_any_of.h
 *
 *
 */

#ifndef _ssc_mode_any_of_H_
#define _ssc_mode_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ssc_mode_any_of_NULL = 0, ssc_mode_any_of_SSC_MODE_1,
	       ssc_mode_any_of_SSC_MODE_2,
	       ssc_mode_any_of_SSC_MODE_3 } ssc_mode_any_of_e;

char *ssc_mode_any_of_ToString(ssc_mode_any_of_e ssc_mode_any_of);

ssc_mode_any_of_e ssc_mode_any_of_FromString(char *ssc_mode_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _ssc_mode_any_of_H_ */
