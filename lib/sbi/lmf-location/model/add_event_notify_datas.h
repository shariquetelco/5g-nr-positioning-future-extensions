/*
 * add_event_notify_datas.h
 *
 *
 */

#ifndef _add_event_notify_datas_H_
#define _add_event_notify_datas_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "event_notify_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct add_event_notify_datas_s add_event_notify_datas_t;
typedef struct add_event_notify_datas_s {
	list_t *add_event_notify_datas;
} add_event_notify_datas_t;

add_event_notify_datas_t *add_event_notify_datas_create(
	list_t *add_event_notify_datas);
void add_event_notify_datas_free(
	add_event_notify_datas_t *add_event_notify_datas);
add_event_notify_datas_t *add_event_notify_datas_parseFromJSON(
	cJSON *add_event_notify_datasJSON);
cJSON *add_event_notify_datas_convertToJSON(
	add_event_notify_datas_t *add_event_notify_datas);
add_event_notify_datas_t *add_event_notify_datas_copy(
	add_event_notify_datas_t *dst, add_event_notify_datas_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _add_event_notify_datas_H_ */
