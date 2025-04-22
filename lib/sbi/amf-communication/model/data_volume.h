/*
 * data_volume.h
 *
 * Data Volume including UL/DL.
 */

#ifndef _data_volume_H_
#define _data_volume_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_volume_s data_volume_t;
typedef struct data_volume_s {
	bool is_uplink_volume;
	long uplink_volume;
	bool is_downlink_volume;
	long downlink_volume;
} data_volume_t;

data_volume_t *data_volume_create(bool is_uplink_volume, long uplink_volume,
                                  bool is_downlink_volume,
                                  long downlink_volume);
void data_volume_free(data_volume_t *data_volume);
data_volume_t *data_volume_parseFromJSON(cJSON *data_volumeJSON);
cJSON *data_volume_convertToJSON(data_volume_t *data_volume);
data_volume_t *data_volume_copy(data_volume_t *dst, data_volume_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _data_volume_H_ */
