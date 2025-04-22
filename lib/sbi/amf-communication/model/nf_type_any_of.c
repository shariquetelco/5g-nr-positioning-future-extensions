#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_type_any_of.h"

char *nf_type_any_of_ToString(nf_type_any_of_e nf_type_any_of) {
	const char *nf_type_any_ofArray[] =
	{ "NULL", "NRF", "UDM", "AMF", "SMF", "AUSF", "NEF", "PCF", "SMSF",
	  "NSSF", "UDR", "LMF", "GMLC", "5G_EIR", "SEPP", "UPF", "N3IWF",
	  "AF", "UDSF", "BSF", "CHF", "NWDAF", "PCSCF", "CBCF", "HSS",
	  "UCMF", "SOR_AF", "SPAF", "MME", "SCSAS", "SCEF", "SCP",
	  "NSSAAF", "ICSCF", "SCSCF", "DRA", "IMS_AS", "AANF", "5G_DDNMF",
	  "NSACF", "MFAF", "EASDF", "DCCF", "MB_SMF", "TSCTSF", "ADRF",
	  "GBA_BSF", "CEF", "MB_UPF", "NSWOF", "PKMF", "MNPF", "SMS_GMSC",
	  "SMS_IWMSC", "MBSF", "MBSTF", "PANF", "IP_SM_GW", "SMS_ROUTER",
	  "DCSF", "MRF", "MRFP", "MF", "SLPKMF", "RH" };
	size_t sizeofArray = sizeof(nf_type_any_ofArray) /
	                     sizeof(nf_type_any_ofArray[0]);
	if(nf_type_any_of < sizeofArray) {
		return (char *) nf_type_any_ofArray[nf_type_any_of];
	} else {
		return (char *) "Unknown";
	}
}

nf_type_any_of_e nf_type_any_of_FromString(char *nf_type_any_of) {
	int stringToReturn = 0;
	const char *nf_type_any_ofArray[] =
	{ "NULL", "NRF", "UDM", "AMF", "SMF", "AUSF", "NEF", "PCF", "SMSF",
	  "NSSF", "UDR", "LMF", "GMLC", "5G_EIR", "SEPP", "UPF", "N3IWF",
	  "AF", "UDSF", "BSF", "CHF", "NWDAF", "PCSCF", "CBCF", "HSS",
	  "UCMF", "SOR_AF", "SPAF", "MME", "SCSAS", "SCEF", "SCP",
	  "NSSAAF", "ICSCF", "SCSCF", "DRA", "IMS_AS", "AANF", "5G_DDNMF",
	  "NSACF", "MFAF", "EASDF", "DCCF", "MB_SMF", "TSCTSF", "ADRF",
	  "GBA_BSF", "CEF", "MB_UPF", "NSWOF", "PKMF", "MNPF", "SMS_GMSC",
	  "SMS_IWMSC", "MBSF", "MBSTF", "PANF", "IP_SM_GW", "SMS_ROUTER",
	  "DCSF", "MRF", "MRFP", "MF", "SLPKMF", "RH" };
	size_t sizeofArray = sizeof(nf_type_any_ofArray) /
	                     sizeof(nf_type_any_ofArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(nf_type_any_of,
		          nf_type_any_ofArray[stringToReturn]) == 0) {
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
