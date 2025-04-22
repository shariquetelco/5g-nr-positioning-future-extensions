/*
 * gnss_id.h
 *
 *
 */

#ifndef _gnss_id_H_
#define _gnss_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { gnss_id_NULL = 0, gnss_id_GPS, gnss_id_GALILEO, gnss_id_SBAS,
	       gnss_id_MODERNIZED_GPS, gnss_id_QZSS, gnss_id_GLONASS,
	       gnss_id_BDS,
	       gnss_id_NAVIC } gnss_id_e;

char *gnss_id_ToString(gnss_id_e gnss_id);

gnss_id_e gnss_id_FromString(char *gnss_id);

#ifdef __cplusplus
}
#endif

#endif /* _gnss_id_H_ */
