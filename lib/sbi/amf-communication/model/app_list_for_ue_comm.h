/*
 * app_list_for_ue_comm.h
 *
 * Represents the analytics of the application list used by UE.
 */

#ifndef _app_list_for_ue_comm_H_
#define _app_list_for_ue_comm_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "network_area_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct app_list_for_ue_comm_s app_list_for_ue_comm_t;
typedef struct app_list_for_ue_comm_s {
	char *app_id;
	char *start_time;
	bool is_app_dur;
	int app_dur;
	bool is_occur_ratio;
	int occur_ratio;
	struct network_area_info_s *spatial_validity;
} app_list_for_ue_comm_t;

app_list_for_ue_comm_t *app_list_for_ue_comm_create(char		*app_id,
                                                    char		*start_time,
                                                    bool		is_app_dur,
                                                    int			app_dur,
                                                    bool		is_occur_ratio,
                                                    int			occur_ratio,
                                                    network_area_info_t *spatial_validity);
void app_list_for_ue_comm_free(app_list_for_ue_comm_t *app_list_for_ue_comm);
app_list_for_ue_comm_t *app_list_for_ue_comm_parseFromJSON(
	cJSON *app_list_for_ue_commJSON);
cJSON *app_list_for_ue_comm_convertToJSON(
	app_list_for_ue_comm_t *app_list_for_ue_comm);
app_list_for_ue_comm_t *app_list_for_ue_comm_copy(
	app_list_for_ue_comm_t	*dst,
	app_list_for_ue_comm_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _app_list_for_ue_comm_H_ */
