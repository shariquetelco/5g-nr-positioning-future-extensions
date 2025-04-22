#ifndef _SBI_CLIENT_H_
#define _SBI_CLIENT_H_

#include "amfd.h"
#include <nrppa/nrppa_create.h>
#include <api/N1N2IndividualSubscriptionDocumentAPI.h>
#include <api/N1N2MessageCollectionCollectionAPI.h>
#include <api/DetermineLocationAPI.h>
#include <model/n2_information_notification.h>

/*
 * Macros
 *
 * @SBI_LMF_BASE_URI: SBI base URI to access the target LMF
 * @TLS_*_CERTDIR: Directory of the TLS certificate of the target NF 
 * @TLS_*_CERT: Certificate file of the target NF
 */
#define SBI_LMF_BASE_URI "https://lmfd.5gc:54321"

#define TLS_LMF_CERTDIR "/etc/init5g/tls/"
#define TLS_LMF_CERT "/etc/init5g/tls/lmf.crt"

/*
 * Namf_Communication_N2InfoNotify service - send UE specific N2 data to the target LMF
 *
 * @msg: ASN.1 PER encoded NRPPA PDU
 * @uri: callback URI that is used by the AMF for N2 message notification
 * @nfid: NF ID of this LMF
 * @lcsid: LCS Correlation ID
 * @sub_id: corresponding subscription ID
 *
 * return: 0 on success, -1 otherwise
 *
 * NOTE: The passed encoded NRPPa PDU has to be wrapped by the corresponding NGAP IE by using createNGAPforNRPPaTransportSBI() (e.g. see /src/lmf/sbi-client.c).
 */
int namf_comm_n2InfoNotify(nrppamsg_t *msg, const char *uri, char *nfid, char *lcsid, char *sub_id);

/*
 * Nlmf_Location_DetermineLocation service - request the position of a target UE from the LMF
 *
 *
 */
int nlmf_loc_determineLocation(const char *supi, const char *lcsid, const char *nfid);

#endif
