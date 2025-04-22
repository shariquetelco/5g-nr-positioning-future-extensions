/*
 * ngap-handler - gNB handler functions for different NGAP PDU message types
 */

#ifndef _NGAP_HANDLER_H_
#define _NGAP_HANDLER_H_

#include "gNB.h"

/*
 * NGAP handler function for different NGAP initiating message types
 */
int handleDownlinkUEAssociatedNRPPaTransport(ngapmsg_t *msg);
int handleDownlinkNonUEAssociatedNRPPaTransport(ngapmsg_t *msg);

#endif
