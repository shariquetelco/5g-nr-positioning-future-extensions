/*
 * nf_type_any_of.h
 *
 *
 */

#ifndef _nf_type_any_of_H_
#define _nf_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { nf_type_any_of_NULL = 0, nf_type_any_of_NRF, nf_type_any_of_UDM,
	       nf_type_any_of_AMF, nf_type_any_of_SMF, nf_type_any_of_AUSF,
	       nf_type_any_of_NEF, nf_type_any_of_PCF, nf_type_any_of_SMSF,
	       nf_type_any_of_NSSF, nf_type_any_of_UDR, nf_type_any_of_LMF,
	       nf_type_any_of_GMLC, nf_type_any_of_5G_EIR, nf_type_any_of_SEPP,
	       nf_type_any_of_UPF, nf_type_any_of_N3IWF, nf_type_any_of_AF,
	       nf_type_any_of_UDSF, nf_type_any_of_BSF, nf_type_any_of_CHF,
	       nf_type_any_of_NWDAF, nf_type_any_of_PCSCF, nf_type_any_of_CBCF,
	       nf_type_any_of_HSS, nf_type_any_of_UCMF, nf_type_any_of_SOR_AF,
	       nf_type_any_of_SPAF, nf_type_any_of_MME, nf_type_any_of_SCSAS,
	       nf_type_any_of_SCEF, nf_type_any_of_SCP, nf_type_any_of_NSSAAF,
	       nf_type_any_of_ICSCF, nf_type_any_of_SCSCF, nf_type_any_of_DRA,
	       nf_type_any_of_IMS_AS, nf_type_any_of_AANF,
	       nf_type_any_of__5G_DDNMF,
	       nf_type_any_of_NSACF, nf_type_any_of_MFAF, nf_type_any_of_EASDF,
	       nf_type_any_of_DCCF, nf_type_any_of_MB_SMF,
	       nf_type_any_of_TSCTSF,
	       nf_type_any_of_ADRF, nf_type_any_of_GBA_BSF, nf_type_any_of_CEF,
	       nf_type_any_of_MB_UPF, nf_type_any_of_NSWOF, nf_type_any_of_PKMF,
	       nf_type_any_of_MNPF, nf_type_any_of_SMS_GMSC,
	       nf_type_any_of_SMS_IWMSC,
	       nf_type_any_of_MBSF, nf_type_any_of_MBSTF, nf_type_any_of_PANF,
	       nf_type_any_of_IP_SM_GW, nf_type_any_of_SMS_ROUTER,
	       nf_type_any_of_DCSF,
	       nf_type_any_of_MRF, nf_type_any_of_MRFP, nf_type_any_of_MF,
	       nf_type_any_of_SLPKMF, nf_type_any_of_RH } nf_type_any_of_e;

char *nf_type_any_of_ToString(nf_type_any_of_e nf_type_any_of);

nf_type_any_of_e nf_type_any_of_FromString(char *nf_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _nf_type_any_of_H_ */
