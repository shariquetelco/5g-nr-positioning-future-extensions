/*
 * arp.h
 *
 * Contains Allocation and Retention Priority information.
 */

#ifndef _arp_H_
#define _arp_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "preemption_capability.h"
#include "preemption_vulnerability.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct arp_s arp_t;
typedef struct arp_s {
	bool is_priority_level_null;
	int priority_level;
	struct preemption_capability_s *preempt_cap;
	struct preemption_vulnerability_s *preempt_vuln;
} arp_t;

arp_t *arp_create(bool is_priority_level_null, int priority_level,
                  preemption_capability_t *preempt_cap,
                  preemption_vulnerability_t *preempt_vuln);
void arp_free(arp_t *arp);
arp_t *arp_parseFromJSON(cJSON *arpJSON);
cJSON *arp_convertToJSON(arp_t *arp);
arp_t *arp_copy(arp_t *dst, arp_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _arp_H_ */
