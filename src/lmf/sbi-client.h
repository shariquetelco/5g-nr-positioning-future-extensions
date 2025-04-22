#ifndef _SBI_CLIENT_H_
#define _SBI_CLIENT_H_

#include "lmfd.h"

/*
 * Macros
 *
 * @SBI_NAMF_COMM_*: SBI URI to access the corresponding AMF service
 * @TLS_*_CERTDIR: Directory of the TLS certificate of the target NF 
 * @TLS_*_CERT: Certificate file of the target NF
 */
#define SBI_NAMF_COMM_N2 "https://amfd.5gc:54321/namf-comm/v1/ue-contexts/imsi-001010003201001/n1-n2-messages"
#define SBI_NAMF_COMM_SUB "https://amfd.5gc:54321/namf-comm/v1/ue-contexts/imsi-001010003201001/n1-n2-messages/subscriptions"

#define TLS_AMF_CERTDIR "/etc/init5g/tls/"
#define TLS_AMF_CERT "/etc/init5g/tls/amf.crt"

/*
 * Namf_Communication_N1N2MessageSubscribe service - subscribe for UE specific N2 data
 *
 * @uri: callback URI that is used by the AMF for N2 message transfer
 * @nfid: NF ID of this LMF
 * @ctx: Target UE context for which is subscribed.
 *
 * return: 0 on success, -1 otherwise
 *
 * NOTE: According to 3GPP TS 29.501, 4.6.2.2.1: Subscriptions can be implicit. Therefore, to send a subscription message is not mandatory!
 */
int namf_comm_n1n2msgsubscribe(char *uri, char *nfid, ue_ctx_t *ctx);

/*
 * Namf_Communication_N1N2MessageUnsubscribe service - unsubscribe for UE specific N2 data
 *
 * @ctx: Target UE context which is unsubscribed.
 *
 * return: 0 on success, -1 otherwise
 *
 */
int namf_comm_n1n2msgunsubscribe(ue_ctx_t *ctx);

/*
 * Namf_Communication_N1N2MessageTransfer service - send UE specific N1 and N2 data (here: only NRPPa PDUs)
 *
 * @msg: ASN.1 PER encoded NRPPa PDU and its size [B]
 * @nfid: NF ID of this LMF
 * @lcsid: LCS Correlation Identifier
 *
 * NOTE: Precondition: The LMF has already subscribed to the AMF using the Namf_Communication_N1N2MessageSubscribe service to get the corresponding N2 response data.
 */
int namf_comm_n1n2msgtransfer(nrppamsg_t *msg, char *nfid, char *lcsid, char *ctx);

#endif
