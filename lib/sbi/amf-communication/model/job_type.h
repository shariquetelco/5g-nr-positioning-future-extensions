/*
 * job_type.h
 *
 * The enumeration JobType defines Job Type in the trace. See 3GPP TS 32.422 for further  description of the values. It shall comply with the provisions defined in table 5.6.3.3-1.
 */

#ifndef _job_type_H_
#define _job_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "job_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct job_type_s job_type_t;
typedef struct job_type_s {} job_type_t;

job_type_t *job_type_create();
void job_type_free(job_type_t *job_type);
job_type_t *job_type_parseFromJSON(cJSON *job_typeJSON);
cJSON *job_type_convertToJSON(job_type_t *job_type);
job_type_t *job_type_copy(job_type_t *dst, job_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _job_type_H_ */
