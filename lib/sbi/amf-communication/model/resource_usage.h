/*
 * resource_usage.h
 *
 * The current usage of the virtual resources assigned to the NF instances belonging to a particular network slice instance.
 */

#ifndef _resource_usage_H_
#define _resource_usage_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct resource_usage_s resource_usage_t;
typedef struct resource_usage_s {
	bool is_cpu_usage;
	int cpu_usage;
	bool is_memory_usage;
	int memory_usage;
	bool is_storage_usage;
	int storage_usage;
} resource_usage_t;

resource_usage_t *resource_usage_create(bool is_cpu_usage, int cpu_usage,
                                        bool is_memory_usage, int memory_usage,
                                        bool is_storage_usage,
                                        int storage_usage);
void resource_usage_free(resource_usage_t *resource_usage);
resource_usage_t *resource_usage_parseFromJSON(cJSON *resource_usageJSON);
cJSON *resource_usage_convertToJSON(resource_usage_t *resource_usage);
resource_usage_t *resource_usage_copy(resource_usage_t	*dst,
                                      resource_usage_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _resource_usage_H_ */
