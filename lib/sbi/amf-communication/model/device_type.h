/*
 * device_type.h
 *
 * Represents the device type.   Possible values are:     - MOBILE_PHONE: Mobile Phone.   - SMART_PHONE: Smartphone.   - TABLET: Tablet.   - DONGLE: Dongle.   - MODEM: Modem.   - WLAN_ROUTER: WLAN Router.   - IOT_DEVICE: IoT Device.   - WEARABLE: Wearable.   - MOBILE_TEST_PLATFORM: Mobile Test Platform.   - UNDEFINED: Undefined.
 */

#ifndef _device_type_H_
#define _device_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "device_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct device_type_s device_type_t;
typedef struct device_type_s {} device_type_t;

device_type_t *device_type_create();
void device_type_free(device_type_t *device_type);
device_type_t *device_type_parseFromJSON(cJSON *device_typeJSON);
cJSON *device_type_convertToJSON(device_type_t *device_type);
device_type_t *device_type_copy(device_type_t *dst, device_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _device_type_H_ */
