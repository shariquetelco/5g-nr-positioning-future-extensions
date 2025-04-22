/*
 * civic_address.h
 *
 * Indicates a Civic address.
 */

#ifndef _civic_address_H_
#define _civic_address_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct civic_address_s civic_address_t;
typedef struct civic_address_s {
	char *country;
	char *a1;
	char *a2;
	char *a3;
	char *a4;
	char *a5;
	char *a6;
	char *prd;
	char *pod;
	char *sts;
	char *hno;
	char *hns;
	char *lmk;
	char *loc;
	char *nam;
	char *pc;
	char *bld;
	char *unit;
	char *flr;
	char *room;
	char *plc;
	char *pcn;
	char *pobox;
	char *addcode;
	char *seat;
	char *rd;
	char *rdsec;
	char *rdbr;
	char *rdsubbr;
	char *prm;
	char *pom;
	char *usage_rules;
	char *method;
	char *provided_by;
} civic_address_t;

civic_address_t *civic_address_create(char *country, char *a1, char *a2,
                                      char *a3, char *a4, char *a5, char *a6,
                                      char *prd, char *pod, char *sts,
                                      char *hno, char *hns, char *lmk,
                                      char *loc, char *nam, char *pc, char *bld,
                                      char *unit, char *flr, char *room,
                                      char *plc, char *pcn, char *pobox,
                                      char *addcode, char *seat, char *rd,
                                      char *rdsec, char *rdbr, char *rdsubbr,
                                      char *prm, char *pom, char *usage_rules,
                                      char *method, char *provided_by);
void civic_address_free(civic_address_t *civic_address);
civic_address_t *civic_address_parseFromJSON(cJSON *civic_addressJSON);
cJSON *civic_address_convertToJSON(civic_address_t *civic_address);
civic_address_t *civic_address_copy(civic_address_t *dst, civic_address_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _civic_address_H_ */
