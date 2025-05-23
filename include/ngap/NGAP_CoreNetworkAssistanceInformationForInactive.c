/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_CoreNetworkAssistanceInformationForInactive.h"

#include "NGAP_ExpectedUEBehaviour.h"
#include "NGAP_ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_NGAP_CoreNetworkAssistanceInformationForInactive_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_CoreNetworkAssistanceInformationForInactive, uEIdentityIndexValue),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NGAP_UEIdentityIndexValue,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"uEIdentityIndexValue"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_CoreNetworkAssistanceInformationForInactive, uESpecificDRX),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_PagingDRX,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"uESpecificDRX"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_CoreNetworkAssistanceInformationForInactive, periodicRegistrationUpdateTimer),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_PeriodicRegistrationUpdateTimer,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"periodicRegistrationUpdateTimer"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_CoreNetworkAssistanceInformationForInactive, mICOModeIndication),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_MICOModeIndication,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"mICOModeIndication"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_CoreNetworkAssistanceInformationForInactive, tAIListForInactive),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_TAIListForInactive,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"tAIListForInactive"
		},
	{ ATF_POINTER, 2, offsetof(struct NGAP_CoreNetworkAssistanceInformationForInactive, expectedUEBehaviour),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ExpectedUEBehaviour,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"expectedUEBehaviour"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_CoreNetworkAssistanceInformationForInactive, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_11180P57,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_NGAP_CoreNetworkAssistanceInformationForInactive_oms_1[] = { 1, 3, 5, 6 };
static const ber_tlv_tag_t asn_DEF_NGAP_CoreNetworkAssistanceInformationForInactive_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_CoreNetworkAssistanceInformationForInactive_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* uEIdentityIndexValue */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* uESpecificDRX */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* periodicRegistrationUpdateTimer */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* mICOModeIndication */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* tAIListForInactive */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* expectedUEBehaviour */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NGAP_CoreNetworkAssistanceInformationForInactive_specs_1 = {
	sizeof(struct NGAP_CoreNetworkAssistanceInformationForInactive),
	offsetof(struct NGAP_CoreNetworkAssistanceInformationForInactive, _asn_ctx),
	asn_MAP_NGAP_CoreNetworkAssistanceInformationForInactive_tag2el_1,
	7,	/* Count of tags in the map */
	asn_MAP_NGAP_CoreNetworkAssistanceInformationForInactive_oms_1,	/* Optional members */
	4, 0,	/* Root/Additions */
	7,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_CoreNetworkAssistanceInformationForInactive = {
	"CoreNetworkAssistanceInformationForInactive",
	"CoreNetworkAssistanceInformationForInactive",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_CoreNetworkAssistanceInformationForInactive_tags_1,
	sizeof(asn_DEF_NGAP_CoreNetworkAssistanceInformationForInactive_tags_1)
		/sizeof(asn_DEF_NGAP_CoreNetworkAssistanceInformationForInactive_tags_1[0]), /* 1 */
	asn_DEF_NGAP_CoreNetworkAssistanceInformationForInactive_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_CoreNetworkAssistanceInformationForInactive_tags_1)
		/sizeof(asn_DEF_NGAP_CoreNetworkAssistanceInformationForInactive_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_CoreNetworkAssistanceInformationForInactive_1,
	7,	/* Elements count */
	&asn_SPC_NGAP_CoreNetworkAssistanceInformationForInactive_specs_1	/* Additional specs */
};

