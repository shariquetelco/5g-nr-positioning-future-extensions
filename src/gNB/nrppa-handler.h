/*
 * nrppa-handler - gNB handler function for different NRPPa PDU message types
 */

#ifndef _NRPPA_HANDLER_H_
#define _NRPPA_HANDLER_H_

#include "gNB.h"

/*
 * Generic NRPPa handler function for different NRPPa message types
 *
 * NOTE: If the passed NRPPa message triggers multiple responses (e.g. Measurement report),
 *		 this handler function creates a new POSIX thread to handle these messages!
 */
nrppamsg_t* handleNRPPaMessage(nrppamsg_t *, ngapmsg_t *);

#endif
