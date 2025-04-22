/*
 * ngap-handler - AMF handler functions for different NGAP PDU message types
 */

#ifndef _NGAP_HANDLER_H_
#define _NGAP_HANDLER_H_

#include "amfd.h"

/*
 * NGAP handler function for different NGAP initiating message types
 */
int handleUplinkUEAssociatedNRPPaTransport(ngapmsg_t *msg);
int handleUplinkNonUEAssociatedNRPPaTransport(ngapmsg_t *msg);

#endif
