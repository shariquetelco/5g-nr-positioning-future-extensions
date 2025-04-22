#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "device_type_any_of.h"

char *device_type_any_of_ToString(device_type_any_of_e device_type_any_of) {
	const char *device_type_any_ofArray[] =
	{ "NULL", "MOBILE_PHONE", "SMART_PHONE", "TABLET", "DONGLE", "MODEM",
	  "WLAN_ROUTER", "IOT_DEVICE", "WEARABLE", "MOBILE_TEST_PLATFORM",
	  "UNDEFINED" };
	size_t sizeofArray = sizeof(device_type_any_ofArray) /
	                     sizeof(device_type_any_ofArray[0]);
	if(device_type_any_of < sizeofArray) {
		return (char *) device_type_any_ofArray[device_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

device_type_any_of_e device_type_any_of_FromString(char *device_type_any_of) {
	int stringToReturn = 0;
	const char *device_type_any_ofArray[] =
	{ "NULL", "MOBILE_PHONE", "SMART_PHONE", "TABLET", "DONGLE", "MODEM",
	  "WLAN_ROUTER", "IOT_DEVICE", "WEARABLE", "MOBILE_TEST_PLATFORM",
	  "UNDEFINED" };
	size_t sizeofArray = sizeof(device_type_any_ofArray) /
	                     sizeof(device_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(device_type_any_of,
		          device_type_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
