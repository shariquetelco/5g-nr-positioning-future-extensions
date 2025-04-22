/*
 * muting_notifications_settings.h
 *
 * Indicates the Event producer NF settings to the Event consumer NF
 */

#ifndef _muting_notifications_settings_H_
#define _muting_notifications_settings_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct muting_notifications_settings_s muting_notifications_settings_t;
typedef struct muting_notifications_settings_s {
	bool is_max_no_of_notif;
	int max_no_of_notif;
	bool is_duration_buffered_notif;
	int duration_buffered_notif;
} muting_notifications_settings_t;

muting_notifications_settings_t *muting_notifications_settings_create(
	bool is_max_no_of_notif, int max_no_of_notif,
	bool is_duration_buffered_notif, int duration_buffered_notif);
void muting_notifications_settings_free(
	muting_notifications_settings_t *muting_notifications_settings);
muting_notifications_settings_t *muting_notifications_settings_parseFromJSON(
	cJSON *muting_notifications_settingsJSON);
cJSON *muting_notifications_settings_convertToJSON(
	muting_notifications_settings_t *muting_notifications_settings);
muting_notifications_settings_t *muting_notifications_settings_copy(
	muting_notifications_settings_t *dst,
	muting_notifications_settings_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _muting_notifications_settings_H_ */
