/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_MDT-Configuration-EUTRA.h"

#include "NGAP_MDTPLMNList.h"
#include "NGAP_ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_NGAP_MDT_Configuration_EUTRA_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_MDT_Configuration_EUTRA, mdt_Activation),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_MDT_Activation,
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
		"mdt-Activation"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_MDT_Configuration_EUTRA, areaScopeOfMDT),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NGAP_AreaScopeOfMDT_EUTRA,
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
		"areaScopeOfMDT"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_MDT_Configuration_EUTRA, mDTMode),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_MDTModeEutra,
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
		"mDTMode"
		},
	{ ATF_POINTER, 2, offsetof(struct NGAP_MDT_Configuration_EUTRA, signallingBasedMDTPLMNList),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_MDTPLMNList,
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
		"signallingBasedMDTPLMNList"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_MDT_Configuration_EUTRA, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_11180P199,
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
static const int asn_MAP_NGAP_MDT_Configuration_EUTRA_oms_1[] = { 3, 4 };
static const ber_tlv_tag_t asn_DEF_NGAP_MDT_Configuration_EUTRA_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_MDT_Configuration_EUTRA_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* mdt-Activation */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* areaScopeOfMDT */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* mDTMode */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* signallingBasedMDTPLMNList */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NGAP_MDT_Configuration_EUTRA_specs_1 = {
	sizeof(struct NGAP_MDT_Configuration_EUTRA),
	offsetof(struct NGAP_MDT_Configuration_EUTRA, _asn_ctx),
	asn_MAP_NGAP_MDT_Configuration_EUTRA_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_NGAP_MDT_Configuration_EUTRA_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	5,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_MDT_Configuration_EUTRA = {
	"MDT-Configuration-EUTRA",
	"MDT-Configuration-EUTRA",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_MDT_Configuration_EUTRA_tags_1,
	sizeof(asn_DEF_NGAP_MDT_Configuration_EUTRA_tags_1)
		/sizeof(asn_DEF_NGAP_MDT_Configuration_EUTRA_tags_1[0]), /* 1 */
	asn_DEF_NGAP_MDT_Configuration_EUTRA_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_MDT_Configuration_EUTRA_tags_1)
		/sizeof(asn_DEF_NGAP_MDT_Configuration_EUTRA_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_MDT_Configuration_EUTRA_1,
	5,	/* Elements count */
	&asn_SPC_NGAP_MDT_Configuration_EUTRA_specs_1	/* Additional specs */
};

