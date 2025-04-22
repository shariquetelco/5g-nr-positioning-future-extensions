/*
 * wireline_area.h
 *
 * One and only one of the \&quot;globLineIds\&quot;, \&quot;hfcNIds\&quot;, \&quot;areaCodeB\&quot;,d \&quot;areaCodeC\&quot; and  combGciAndHfcNIds attributes        shall be included in a WirelineArea data structure
 */

#ifndef _wireline_area_H_
#define _wireline_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "comb_gci_and_hfc_n_ids.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct wireline_area_s wireline_area_t;
typedef struct wireline_area_s {
	list_t *global_line_ids;
	list_t *hfc_n_ids;
	char *area_code_b;
	char *area_code_c;
	list_t *comb_gci_and_hfc_n_ids;
} wireline_area_t;

wireline_area_t *wireline_area_create(list_t *global_line_ids,
                                      list_t *hfc_n_ids, char *area_code_b,
                                      char *area_code_c,
                                      list_t *comb_gci_and_hfc_n_ids);
void wireline_area_free(wireline_area_t *wireline_area);
wireline_area_t *wireline_area_parseFromJSON(cJSON *wireline_areaJSON);
cJSON *wireline_area_convertToJSON(wireline_area_t *wireline_area);
wireline_area_t *wireline_area_copy(wireline_area_t *dst, wireline_area_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _wireline_area_H_ */
