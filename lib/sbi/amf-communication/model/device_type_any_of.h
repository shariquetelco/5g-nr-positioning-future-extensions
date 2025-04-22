/*
 * device_type_any_of.h
 *
 *
 */

#ifndef _device_type_any_of_H_
#define _device_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { device_type_any_of_NULL = 0, device_type_any_of_MOBILE_PHONE,
	       device_type_any_of_SMART_PHONE, device_type_any_of_TABLET,
	       device_type_any_of_DONGLE, device_type_any_of_MODEM,
	       device_type_any_of_WLAN_ROUTER, device_type_any_of_IOT_DEVICE,
	       device_type_any_of_WEARABLE,
	       device_type_any_of_MOBILE_TEST_PLATFORM,
	       device_type_any_of_UNDEFINED } device_type_any_of_e;

char *device_type_any_of_ToString(device_type_any_of_e device_type_any_of);

device_type_any_of_e device_type_any_of_FromString(char *device_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _device_type_any_of_H_ */
