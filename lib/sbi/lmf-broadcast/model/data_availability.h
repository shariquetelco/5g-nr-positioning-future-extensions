/*
 * data_availability.h
 *
 *
 */

#ifndef _data_availability_H_
#define _data_availability_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { data_availability_NULL = 0,
	       data_availability_CIPHERING_KEY_DATA_AVAILABLE,
	       data_availability_CIPHERING_KEY_DATA_NOT_AVAILABLE }
data_availability_e;

char *data_availability_ToString(data_availability_e data_availability);

data_availability_e data_availability_FromString(char *data_availability);

#ifdef __cplusplus
}
#endif

#endif /* _data_availability_H_ */
