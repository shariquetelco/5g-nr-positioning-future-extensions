#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "civic_address.h"

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
                                      char *method, char *provided_by) {
	civic_address_t *civic_address_local_var = malloc(
		sizeof(civic_address_t));

	civic_address_local_var->country = country;
	civic_address_local_var->a1 = a1;
	civic_address_local_var->a2 = a2;
	civic_address_local_var->a3 = a3;
	civic_address_local_var->a4 = a4;
	civic_address_local_var->a5 = a5;
	civic_address_local_var->a6 = a6;
	civic_address_local_var->prd = prd;
	civic_address_local_var->pod = pod;
	civic_address_local_var->sts = sts;
	civic_address_local_var->hno = hno;
	civic_address_local_var->hns = hns;
	civic_address_local_var->lmk = lmk;
	civic_address_local_var->loc = loc;
	civic_address_local_var->nam = nam;
	civic_address_local_var->pc = pc;
	civic_address_local_var->bld = bld;
	civic_address_local_var->unit = unit;
	civic_address_local_var->flr = flr;
	civic_address_local_var->room = room;
	civic_address_local_var->plc = plc;
	civic_address_local_var->pcn = pcn;
	civic_address_local_var->pobox = pobox;
	civic_address_local_var->addcode = addcode;
	civic_address_local_var->seat = seat;
	civic_address_local_var->rd = rd;
	civic_address_local_var->rdsec = rdsec;
	civic_address_local_var->rdbr = rdbr;
	civic_address_local_var->rdsubbr = rdsubbr;
	civic_address_local_var->prm = prm;
	civic_address_local_var->pom = pom;
	civic_address_local_var->usage_rules = usage_rules;
	civic_address_local_var->method = method;
	civic_address_local_var->provided_by = provided_by;

	return civic_address_local_var;
}

void civic_address_free(civic_address_t *civic_address) {
	lnode_t *node = NULL;

	if(NULL == civic_address) {
		return;
	}
	if(civic_address->country) {
		free(civic_address->country);
		civic_address->country = NULL;
	}
	if(civic_address->a1) {
		free(civic_address->a1);
		civic_address->a1 = NULL;
	}
	if(civic_address->a2) {
		free(civic_address->a2);
		civic_address->a2 = NULL;
	}
	if(civic_address->a3) {
		free(civic_address->a3);
		civic_address->a3 = NULL;
	}
	if(civic_address->a4) {
		free(civic_address->a4);
		civic_address->a4 = NULL;
	}
	if(civic_address->a5) {
		free(civic_address->a5);
		civic_address->a5 = NULL;
	}
	if(civic_address->a6) {
		free(civic_address->a6);
		civic_address->a6 = NULL;
	}
	if(civic_address->prd) {
		free(civic_address->prd);
		civic_address->prd = NULL;
	}
	if(civic_address->pod) {
		free(civic_address->pod);
		civic_address->pod = NULL;
	}
	if(civic_address->sts) {
		free(civic_address->sts);
		civic_address->sts = NULL;
	}
	if(civic_address->hno) {
		free(civic_address->hno);
		civic_address->hno = NULL;
	}
	if(civic_address->hns) {
		free(civic_address->hns);
		civic_address->hns = NULL;
	}
	if(civic_address->lmk) {
		free(civic_address->lmk);
		civic_address->lmk = NULL;
	}
	if(civic_address->loc) {
		free(civic_address->loc);
		civic_address->loc = NULL;
	}
	if(civic_address->nam) {
		free(civic_address->nam);
		civic_address->nam = NULL;
	}
	if(civic_address->pc) {
		free(civic_address->pc);
		civic_address->pc = NULL;
	}
	if(civic_address->bld) {
		free(civic_address->bld);
		civic_address->bld = NULL;
	}
	if(civic_address->unit) {
		free(civic_address->unit);
		civic_address->unit = NULL;
	}
	if(civic_address->flr) {
		free(civic_address->flr);
		civic_address->flr = NULL;
	}
	if(civic_address->room) {
		free(civic_address->room);
		civic_address->room = NULL;
	}
	if(civic_address->plc) {
		free(civic_address->plc);
		civic_address->plc = NULL;
	}
	if(civic_address->pcn) {
		free(civic_address->pcn);
		civic_address->pcn = NULL;
	}
	if(civic_address->pobox) {
		free(civic_address->pobox);
		civic_address->pobox = NULL;
	}
	if(civic_address->addcode) {
		free(civic_address->addcode);
		civic_address->addcode = NULL;
	}
	if(civic_address->seat) {
		free(civic_address->seat);
		civic_address->seat = NULL;
	}
	if(civic_address->rd) {
		free(civic_address->rd);
		civic_address->rd = NULL;
	}
	if(civic_address->rdsec) {
		free(civic_address->rdsec);
		civic_address->rdsec = NULL;
	}
	if(civic_address->rdbr) {
		free(civic_address->rdbr);
		civic_address->rdbr = NULL;
	}
	if(civic_address->rdsubbr) {
		free(civic_address->rdsubbr);
		civic_address->rdsubbr = NULL;
	}
	if(civic_address->prm) {
		free(civic_address->prm);
		civic_address->prm = NULL;
	}
	if(civic_address->pom) {
		free(civic_address->pom);
		civic_address->pom = NULL;
	}
	if(civic_address->usage_rules) {
		free(civic_address->usage_rules);
		civic_address->usage_rules = NULL;
	}
	if(civic_address->method) {
		free(civic_address->method);
		civic_address->method = NULL;
	}
	if(civic_address->provided_by) {
		free(civic_address->provided_by);
		civic_address->provided_by = NULL;
	}
	free(civic_address);
}

cJSON *civic_address_convertToJSON(civic_address_t *civic_address) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(civic_address == NULL) {
		printf("civic_address_convertToJSON() failed [CivicAddress]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(civic_address->country) {
		if(cJSON_AddStringToObject(item, "country",
		                           civic_address->country) == NULL)
		{
			printf("civic_address_convertToJSON() failed [country]");
			goto end;
		}
	}

	if(civic_address->a1) {
		if(cJSON_AddStringToObject(item, "A1",
		                           civic_address->a1) == NULL)
		{
			printf("civic_address_convertToJSON() failed [a1]");
			goto end;
		}
	}

	if(civic_address->a2) {
		if(cJSON_AddStringToObject(item, "A2",
		                           civic_address->a2) == NULL)
		{
			printf("civic_address_convertToJSON() failed [a2]");
			goto end;
		}
	}

	if(civic_address->a3) {
		if(cJSON_AddStringToObject(item, "A3",
		                           civic_address->a3) == NULL)
		{
			printf("civic_address_convertToJSON() failed [a3]");
			goto end;
		}
	}

	if(civic_address->a4) {
		if(cJSON_AddStringToObject(item, "A4",
		                           civic_address->a4) == NULL)
		{
			printf("civic_address_convertToJSON() failed [a4]");
			goto end;
		}
	}

	if(civic_address->a5) {
		if(cJSON_AddStringToObject(item, "A5",
		                           civic_address->a5) == NULL)
		{
			printf("civic_address_convertToJSON() failed [a5]");
			goto end;
		}
	}

	if(civic_address->a6) {
		if(cJSON_AddStringToObject(item, "A6",
		                           civic_address->a6) == NULL)
		{
			printf("civic_address_convertToJSON() failed [a6]");
			goto end;
		}
	}

	if(civic_address->prd) {
		if(cJSON_AddStringToObject(item, "PRD",
		                           civic_address->prd) == NULL)
		{
			printf("civic_address_convertToJSON() failed [prd]");
			goto end;
		}
	}

	if(civic_address->pod) {
		if(cJSON_AddStringToObject(item, "POD",
		                           civic_address->pod) == NULL)
		{
			printf("civic_address_convertToJSON() failed [pod]");
			goto end;
		}
	}

	if(civic_address->sts) {
		if(cJSON_AddStringToObject(item, "STS",
		                           civic_address->sts) == NULL)
		{
			printf("civic_address_convertToJSON() failed [sts]");
			goto end;
		}
	}

	if(civic_address->hno) {
		if(cJSON_AddStringToObject(item, "HNO",
		                           civic_address->hno) == NULL)
		{
			printf("civic_address_convertToJSON() failed [hno]");
			goto end;
		}
	}

	if(civic_address->hns) {
		if(cJSON_AddStringToObject(item, "HNS",
		                           civic_address->hns) == NULL)
		{
			printf("civic_address_convertToJSON() failed [hns]");
			goto end;
		}
	}

	if(civic_address->lmk) {
		if(cJSON_AddStringToObject(item, "LMK",
		                           civic_address->lmk) == NULL)
		{
			printf("civic_address_convertToJSON() failed [lmk]");
			goto end;
		}
	}

	if(civic_address->loc) {
		if(cJSON_AddStringToObject(item, "LOC",
		                           civic_address->loc) == NULL)
		{
			printf("civic_address_convertToJSON() failed [loc]");
			goto end;
		}
	}

	if(civic_address->nam) {
		if(cJSON_AddStringToObject(item, "NAM",
		                           civic_address->nam) == NULL)
		{
			printf("civic_address_convertToJSON() failed [nam]");
			goto end;
		}
	}

	if(civic_address->pc) {
		if(cJSON_AddStringToObject(item, "PC",
		                           civic_address->pc) == NULL)
		{
			printf("civic_address_convertToJSON() failed [pc]");
			goto end;
		}
	}

	if(civic_address->bld) {
		if(cJSON_AddStringToObject(item, "BLD",
		                           civic_address->bld) == NULL)
		{
			printf("civic_address_convertToJSON() failed [bld]");
			goto end;
		}
	}

	if(civic_address->unit) {
		if(cJSON_AddStringToObject(item, "UNIT",
		                           civic_address->unit) == NULL)
		{
			printf("civic_address_convertToJSON() failed [unit]");
			goto end;
		}
	}

	if(civic_address->flr) {
		if(cJSON_AddStringToObject(item, "FLR",
		                           civic_address->flr) == NULL)
		{
			printf("civic_address_convertToJSON() failed [flr]");
			goto end;
		}
	}

	if(civic_address->room) {
		if(cJSON_AddStringToObject(item, "ROOM",
		                           civic_address->room) == NULL)
		{
			printf("civic_address_convertToJSON() failed [room]");
			goto end;
		}
	}

	if(civic_address->plc) {
		if(cJSON_AddStringToObject(item, "PLC",
		                           civic_address->plc) == NULL)
		{
			printf("civic_address_convertToJSON() failed [plc]");
			goto end;
		}
	}

	if(civic_address->pcn) {
		if(cJSON_AddStringToObject(item, "PCN",
		                           civic_address->pcn) == NULL)
		{
			printf("civic_address_convertToJSON() failed [pcn]");
			goto end;
		}
	}

	if(civic_address->pobox) {
		if(cJSON_AddStringToObject(item, "POBOX",
		                           civic_address->pobox) == NULL)
		{
			printf("civic_address_convertToJSON() failed [pobox]");
			goto end;
		}
	}

	if(civic_address->addcode) {
		if(cJSON_AddStringToObject(item, "ADDCODE",
		                           civic_address->addcode) == NULL)
		{
			printf("civic_address_convertToJSON() failed [addcode]");
			goto end;
		}
	}

	if(civic_address->seat) {
		if(cJSON_AddStringToObject(item, "SEAT",
		                           civic_address->seat) == NULL)
		{
			printf("civic_address_convertToJSON() failed [seat]");
			goto end;
		}
	}

	if(civic_address->rd) {
		if(cJSON_AddStringToObject(item, "RD",
		                           civic_address->rd) == NULL)
		{
			printf("civic_address_convertToJSON() failed [rd]");
			goto end;
		}
	}

	if(civic_address->rdsec) {
		if(cJSON_AddStringToObject(item, "RDSEC",
		                           civic_address->rdsec) == NULL)
		{
			printf("civic_address_convertToJSON() failed [rdsec]");
			goto end;
		}
	}

	if(civic_address->rdbr) {
		if(cJSON_AddStringToObject(item, "RDBR",
		                           civic_address->rdbr) == NULL)
		{
			printf("civic_address_convertToJSON() failed [rdbr]");
			goto end;
		}
	}

	if(civic_address->rdsubbr) {
		if(cJSON_AddStringToObject(item, "RDSUBBR",
		                           civic_address->rdsubbr) == NULL)
		{
			printf("civic_address_convertToJSON() failed [rdsubbr]");
			goto end;
		}
	}

	if(civic_address->prm) {
		if(cJSON_AddStringToObject(item, "PRM",
		                           civic_address->prm) == NULL)
		{
			printf("civic_address_convertToJSON() failed [prm]");
			goto end;
		}
	}

	if(civic_address->pom) {
		if(cJSON_AddStringToObject(item, "POM",
		                           civic_address->pom) == NULL)
		{
			printf("civic_address_convertToJSON() failed [pom]");
			goto end;
		}
	}

	if(civic_address->usage_rules) {
		if(cJSON_AddStringToObject(item, "usageRules",
		                           civic_address->usage_rules) == NULL)
		{
			printf(
				"civic_address_convertToJSON() failed [usage_rules]");
			goto end;
		}
	}

	if(civic_address->method) {
		if(cJSON_AddStringToObject(item, "method",
		                           civic_address->method) == NULL)
		{
			printf("civic_address_convertToJSON() failed [method]");
			goto end;
		}
	}

	if(civic_address->provided_by) {
		if(cJSON_AddStringToObject(item, "providedBy",
		                           civic_address->provided_by) == NULL)
		{
			printf(
				"civic_address_convertToJSON() failed [provided_by]");
			goto end;
		}
	}

end:
	return item;
}

civic_address_t *civic_address_parseFromJSON(cJSON *civic_addressJSON) {
	civic_address_t *civic_address_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *country = NULL;
	cJSON *a1 = NULL;
	cJSON *a2 = NULL;
	cJSON *a3 = NULL;
	cJSON *a4 = NULL;
	cJSON *a5 = NULL;
	cJSON *a6 = NULL;
	cJSON *prd = NULL;
	cJSON *pod = NULL;
	cJSON *sts = NULL;
	cJSON *hno = NULL;
	cJSON *hns = NULL;
	cJSON *lmk = NULL;
	cJSON *loc = NULL;
	cJSON *nam = NULL;
	cJSON *pc = NULL;
	cJSON *bld = NULL;
	cJSON *unit = NULL;
	cJSON *flr = NULL;
	cJSON *room = NULL;
	cJSON *plc = NULL;
	cJSON *pcn = NULL;
	cJSON *pobox = NULL;
	cJSON *addcode = NULL;
	cJSON *seat = NULL;
	cJSON *rd = NULL;
	cJSON *rdsec = NULL;
	cJSON *rdbr = NULL;
	cJSON *rdsubbr = NULL;
	cJSON *prm = NULL;
	cJSON *pom = NULL;
	cJSON *usage_rules = NULL;
	cJSON *method = NULL;
	cJSON *provided_by = NULL;
	country =
		cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "country");
	if(country) {
		if(!cJSON_IsString(country) &&
		   !cJSON_IsNull(country))
		{
			printf("civic_address_parseFromJSON() failed [country]");
			goto end;
		}
	}

	a1 = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "A1");
	if(a1) {
		if(!cJSON_IsString(a1) &&
		   !cJSON_IsNull(a1))
		{
			printf("civic_address_parseFromJSON() failed [a1]");
			goto end;
		}
	}

	a2 = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "A2");
	if(a2) {
		if(!cJSON_IsString(a2) &&
		   !cJSON_IsNull(a2))
		{
			printf("civic_address_parseFromJSON() failed [a2]");
			goto end;
		}
	}

	a3 = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "A3");
	if(a3) {
		if(!cJSON_IsString(a3) &&
		   !cJSON_IsNull(a3))
		{
			printf("civic_address_parseFromJSON() failed [a3]");
			goto end;
		}
	}

	a4 = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "A4");
	if(a4) {
		if(!cJSON_IsString(a4) &&
		   !cJSON_IsNull(a4))
		{
			printf("civic_address_parseFromJSON() failed [a4]");
			goto end;
		}
	}

	a5 = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "A5");
	if(a5) {
		if(!cJSON_IsString(a5) &&
		   !cJSON_IsNull(a5))
		{
			printf("civic_address_parseFromJSON() failed [a5]");
			goto end;
		}
	}

	a6 = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "A6");
	if(a6) {
		if(!cJSON_IsString(a6) &&
		   !cJSON_IsNull(a6))
		{
			printf("civic_address_parseFromJSON() failed [a6]");
			goto end;
		}
	}

	prd = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "PRD");
	if(prd) {
		if(!cJSON_IsString(prd) &&
		   !cJSON_IsNull(prd))
		{
			printf("civic_address_parseFromJSON() failed [prd]");
			goto end;
		}
	}

	pod = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "POD");
	if(pod) {
		if(!cJSON_IsString(pod) &&
		   !cJSON_IsNull(pod))
		{
			printf("civic_address_parseFromJSON() failed [pod]");
			goto end;
		}
	}

	sts = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "STS");
	if(sts) {
		if(!cJSON_IsString(sts) &&
		   !cJSON_IsNull(sts))
		{
			printf("civic_address_parseFromJSON() failed [sts]");
			goto end;
		}
	}

	hno = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "HNO");
	if(hno) {
		if(!cJSON_IsString(hno) &&
		   !cJSON_IsNull(hno))
		{
			printf("civic_address_parseFromJSON() failed [hno]");
			goto end;
		}
	}

	hns = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "HNS");
	if(hns) {
		if(!cJSON_IsString(hns) &&
		   !cJSON_IsNull(hns))
		{
			printf("civic_address_parseFromJSON() failed [hns]");
			goto end;
		}
	}

	lmk = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "LMK");
	if(lmk) {
		if(!cJSON_IsString(lmk) &&
		   !cJSON_IsNull(lmk))
		{
			printf("civic_address_parseFromJSON() failed [lmk]");
			goto end;
		}
	}

	loc = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "LOC");
	if(loc) {
		if(!cJSON_IsString(loc) &&
		   !cJSON_IsNull(loc))
		{
			printf("civic_address_parseFromJSON() failed [loc]");
			goto end;
		}
	}

	nam = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "NAM");
	if(nam) {
		if(!cJSON_IsString(nam) &&
		   !cJSON_IsNull(nam))
		{
			printf("civic_address_parseFromJSON() failed [nam]");
			goto end;
		}
	}

	pc = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "PC");
	if(pc) {
		if(!cJSON_IsString(pc) &&
		   !cJSON_IsNull(pc))
		{
			printf("civic_address_parseFromJSON() failed [pc]");
			goto end;
		}
	}

	bld = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "BLD");
	if(bld) {
		if(!cJSON_IsString(bld) &&
		   !cJSON_IsNull(bld))
		{
			printf("civic_address_parseFromJSON() failed [bld]");
			goto end;
		}
	}

	unit = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "UNIT");
	if(unit) {
		if(!cJSON_IsString(unit) &&
		   !cJSON_IsNull(unit))
		{
			printf("civic_address_parseFromJSON() failed [unit]");
			goto end;
		}
	}

	flr = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "FLR");
	if(flr) {
		if(!cJSON_IsString(flr) &&
		   !cJSON_IsNull(flr))
		{
			printf("civic_address_parseFromJSON() failed [flr]");
			goto end;
		}
	}

	room = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "ROOM");
	if(room) {
		if(!cJSON_IsString(room) &&
		   !cJSON_IsNull(room))
		{
			printf("civic_address_parseFromJSON() failed [room]");
			goto end;
		}
	}

	plc = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "PLC");
	if(plc) {
		if(!cJSON_IsString(plc) &&
		   !cJSON_IsNull(plc))
		{
			printf("civic_address_parseFromJSON() failed [plc]");
			goto end;
		}
	}

	pcn = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "PCN");
	if(pcn) {
		if(!cJSON_IsString(pcn) &&
		   !cJSON_IsNull(pcn))
		{
			printf("civic_address_parseFromJSON() failed [pcn]");
			goto end;
		}
	}

	pobox = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "POBOX");
	if(pobox) {
		if(!cJSON_IsString(pobox) &&
		   !cJSON_IsNull(pobox))
		{
			printf("civic_address_parseFromJSON() failed [pobox]");
			goto end;
		}
	}

	addcode =
		cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "ADDCODE");
	if(addcode) {
		if(!cJSON_IsString(addcode) &&
		   !cJSON_IsNull(addcode))
		{
			printf("civic_address_parseFromJSON() failed [addcode]");
			goto end;
		}
	}

	seat = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "SEAT");
	if(seat) {
		if(!cJSON_IsString(seat) &&
		   !cJSON_IsNull(seat))
		{
			printf("civic_address_parseFromJSON() failed [seat]");
			goto end;
		}
	}

	rd = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "RD");
	if(rd) {
		if(!cJSON_IsString(rd) &&
		   !cJSON_IsNull(rd))
		{
			printf("civic_address_parseFromJSON() failed [rd]");
			goto end;
		}
	}

	rdsec = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "RDSEC");
	if(rdsec) {
		if(!cJSON_IsString(rdsec) &&
		   !cJSON_IsNull(rdsec))
		{
			printf("civic_address_parseFromJSON() failed [rdsec]");
			goto end;
		}
	}

	rdbr = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "RDBR");
	if(rdbr) {
		if(!cJSON_IsString(rdbr) &&
		   !cJSON_IsNull(rdbr))
		{
			printf("civic_address_parseFromJSON() failed [rdbr]");
			goto end;
		}
	}

	rdsubbr =
		cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "RDSUBBR");
	if(rdsubbr) {
		if(!cJSON_IsString(rdsubbr) &&
		   !cJSON_IsNull(rdsubbr))
		{
			printf("civic_address_parseFromJSON() failed [rdsubbr]");
			goto end;
		}
	}

	prm = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "PRM");
	if(prm) {
		if(!cJSON_IsString(prm) &&
		   !cJSON_IsNull(prm))
		{
			printf("civic_address_parseFromJSON() failed [prm]");
			goto end;
		}
	}

	pom = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "POM");
	if(pom) {
		if(!cJSON_IsString(pom) &&
		   !cJSON_IsNull(pom))
		{
			printf("civic_address_parseFromJSON() failed [pom]");
			goto end;
		}
	}

	usage_rules = cJSON_GetObjectItemCaseSensitive(civic_addressJSON,
	                                               "usageRules");
	if(usage_rules) {
		if(!cJSON_IsString(usage_rules) &&
		   !cJSON_IsNull(usage_rules))
		{
			printf(
				"civic_address_parseFromJSON() failed [usage_rules]");
			goto end;
		}
	}

	method = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "method");
	if(method) {
		if(!cJSON_IsString(method) &&
		   !cJSON_IsNull(method))
		{
			printf("civic_address_parseFromJSON() failed [method]");
			goto end;
		}
	}

	provided_by = cJSON_GetObjectItemCaseSensitive(civic_addressJSON,
	                                               "providedBy");
	if(provided_by) {
		if(!cJSON_IsString(provided_by) &&
		   !cJSON_IsNull(provided_by))
		{
			printf(
				"civic_address_parseFromJSON() failed [provided_by]");
			goto end;
		}
	}

	civic_address_local_var = civic_address_create(
		country &&
		!cJSON_IsNull(country) ? strdup(country->valuestring) : NULL,
		a1 &&
		!cJSON_IsNull(a1) ? strdup(a1->valuestring) : NULL,
		a2 &&
		!cJSON_IsNull(a2) ? strdup(a2->valuestring) : NULL,
		a3 &&
		!cJSON_IsNull(a3) ? strdup(a3->valuestring) : NULL,
		a4 &&
		!cJSON_IsNull(a4) ? strdup(a4->valuestring) : NULL,
		a5 &&
		!cJSON_IsNull(a5) ? strdup(a5->valuestring) : NULL,
		a6 &&
		!cJSON_IsNull(a6) ? strdup(a6->valuestring) : NULL,
		prd &&
		!cJSON_IsNull(prd) ? strdup(prd->valuestring) : NULL,
		pod &&
		!cJSON_IsNull(pod) ? strdup(pod->valuestring) : NULL,
		sts &&
		!cJSON_IsNull(sts) ? strdup(sts->valuestring) : NULL,
		hno &&
		!cJSON_IsNull(hno) ? strdup(hno->valuestring) : NULL,
		hns &&
		!cJSON_IsNull(hns) ? strdup(hns->valuestring) : NULL,
		lmk &&
		!cJSON_IsNull(lmk) ? strdup(lmk->valuestring) : NULL,
		loc &&
		!cJSON_IsNull(loc) ? strdup(loc->valuestring) : NULL,
		nam &&
		!cJSON_IsNull(nam) ? strdup(nam->valuestring) : NULL,
		pc &&
		!cJSON_IsNull(pc) ? strdup(pc->valuestring) : NULL,
		bld &&
		!cJSON_IsNull(bld) ? strdup(bld->valuestring) : NULL,
		unit &&
		!cJSON_IsNull(unit) ? strdup(unit->valuestring) : NULL,
		flr &&
		!cJSON_IsNull(flr) ? strdup(flr->valuestring) : NULL,
		room &&
		!cJSON_IsNull(room) ? strdup(room->valuestring) : NULL,
		plc &&
		!cJSON_IsNull(plc) ? strdup(plc->valuestring) : NULL,
		pcn &&
		!cJSON_IsNull(pcn) ? strdup(pcn->valuestring) : NULL,
		pobox &&
		!cJSON_IsNull(pobox) ? strdup(pobox->valuestring) : NULL,
		addcode &&
		!cJSON_IsNull(addcode) ? strdup(addcode->valuestring) : NULL,
		seat &&
		!cJSON_IsNull(seat) ? strdup(seat->valuestring) : NULL,
		rd &&
		!cJSON_IsNull(rd) ? strdup(rd->valuestring) : NULL,
		rdsec &&
		!cJSON_IsNull(rdsec) ? strdup(rdsec->valuestring) : NULL,
		rdbr &&
		!cJSON_IsNull(rdbr) ? strdup(rdbr->valuestring) : NULL,
		rdsubbr &&
		!cJSON_IsNull(rdsubbr) ? strdup(rdsubbr->valuestring) : NULL,
		prm &&
		!cJSON_IsNull(prm) ? strdup(prm->valuestring) : NULL,
		pom &&
		!cJSON_IsNull(pom) ? strdup(pom->valuestring) : NULL,
		usage_rules &&
		!cJSON_IsNull(usage_rules) ? strdup(
			usage_rules->valuestring) : NULL,
		method &&
		!cJSON_IsNull(method) ? strdup(method->valuestring) : NULL,
		provided_by &&
		!cJSON_IsNull(provided_by) ? strdup(
			provided_by->valuestring) : NULL
		);

	return civic_address_local_var;
end:
	return NULL;
}

civic_address_t *civic_address_copy(civic_address_t	*dst,
                                    civic_address_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = civic_address_convertToJSON(src);
	if(!item) {
		printf("civic_address_convertToJSON() failed");
		return NULL;
	}

	content = cJSON_Print(item);
	cJSON_Delete(item);

	if(!content) {
		printf("cJSON_Print() failed");
		return NULL;
	}

	item = cJSON_Parse(content);
	free(content);
	if(!item) {
		printf("cJSON_Parse() failed");
		return NULL;
	}

	civic_address_free(dst);
	dst = civic_address_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
