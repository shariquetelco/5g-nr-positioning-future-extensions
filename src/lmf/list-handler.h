#ifndef _LIST_HANDLER_H_
#define _LIST_HANDLER_H_

#include "lmfd.h"

/*
 * handler functions for global UE context list
 */
void initUEctxList(ue_ctx_list_t **list);
ue_ctx_t* getUEctx(ue_ctx_list_t *list, char *supi);
bool addUEctx(ue_ctx_list_t *list, ue_ctx_t *entry);
bool deleteUEctx(ue_ctx_list_t *list, ue_ctx_t *entry);
void freeUEctxList(ue_ctx_list_t *list);

/*
 * handler functions for global NRPPa transaction / LMF UE Measurement ID list
 */
void initNRPPaList(nrppa_transact_t **list, int num);
uint16_t reserveListID(nrppa_transact_t *list);
void freeListID(nrppa_transact_t *list, uint16_t id);
void freeNRPPaList(nrppa_transact_t **list);

#endif
