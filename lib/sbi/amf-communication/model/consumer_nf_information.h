/*
 * consumer_nf_information.h
 *
 * Represents the analytics consumer NF Information.
 */

#ifndef _consumer_nf_information_H_
#define _consumer_nf_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct consumer_nf_information_s consumer_nf_information_t;
typedef struct consumer_nf_information_s {
	char *nf_id;
	char *nf_set_id;
	list_t *tai_list;
} consumer_nf_information_t;

consumer_nf_information_t *consumer_nf_information_create(char		*nf_id,
                                                          char		*nf_set_id,
                                                          list_t	*tai_list);
void consumer_nf_information_free(
	consumer_nf_information_t *consumer_nf_information);
consumer_nf_information_t *consumer_nf_information_parseFromJSON(
	cJSON *consumer_nf_informationJSON);
cJSON *consumer_nf_information_convertToJSON(
	consumer_nf_information_t *consumer_nf_information);
consumer_nf_information_t *consumer_nf_information_copy(
	consumer_nf_information_t *dst, consumer_nf_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _consumer_nf_information_H_ */
