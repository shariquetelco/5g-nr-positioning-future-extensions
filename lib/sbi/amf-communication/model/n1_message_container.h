/*
 * n1_message_container.h
 *
 * N1 Message container
 */

#ifndef _n1_message_container_H_
#define _n1_message_container_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n1_message_class.h"
#include "ref_to_binary_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n1_message_container_s n1_message_container_t;
typedef struct n1_message_container_s {
	n1_message_class_e n1_message_class;
	struct ref_to_binary_data_s *n1_message_content;
	char *nf_id;
	char *service_instance_id;
} n1_message_container_t;

n1_message_container_t *n1_message_container_create(
	n1_message_class_e n1_message_class,
	ref_to_binary_data_t *n1_message_content, char *nf_id,
	char *service_instance_id);
void n1_message_container_free(n1_message_container_t *n1_message_container);
n1_message_container_t *n1_message_container_parseFromJSON(
	cJSON *n1_message_containerJSON);
cJSON *n1_message_container_convertToJSON(
	n1_message_container_t *n1_message_container);
n1_message_container_t *n1_message_container_copy(
	n1_message_container_t	*dst,
	n1_message_container_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _n1_message_container_H_ */
