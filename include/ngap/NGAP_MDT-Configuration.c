/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_MDT-Configuration.h"

#include "NGAP_MDT-Configuration-NR.h"
#include "NGAP_MDT-Configuration-EUTRA.h"
#include "NGAP_ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_NGAP_MDT_Configuration_1[] = {
	{ ATF_POINTER, 3, offsetof(struct NGAP_MDT_Configuration, mdt_Config_NR),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_MDT_Configuration_NR,
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
		"mdt-Config-NR"
		},
	{ ATF_POINTER, 2, offsetof(struct NGAP_MDT_Configuration, mdt_Config_EUTRA),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_MDT_Configuration_EUTRA,
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
		"mdt-Config-EUTRA"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_MDT_Configuration, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_11180P197,
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
static const int asn_MAP_NGAP_MDT_Configuration_oms_1[] = { 0, 1, 2 };
static const ber_tlv_tag_t asn_DEF_NGAP_MDT_Configuration_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_MDT_Configuration_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* mdt-Config-NR */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* mdt-Config-EUTRA */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NGAP_MDT_Configuration_specs_1 = {
	sizeof(struct NGAP_MDT_Configuration),
	offsetof(struct NGAP_MDT_Configuration, _asn_ctx),
	asn_MAP_NGAP_MDT_Configuration_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_NGAP_MDT_Configuration_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_MDT_Configuration = {
	"MDT-Configuration",
	"MDT-Configuration",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_MDT_Configuration_tags_1,
	sizeof(asn_DEF_NGAP_MDT_Configuration_tags_1)
		/sizeof(asn_DEF_NGAP_MDT_Configuration_tags_1[0]), /* 1 */
	asn_DEF_NGAP_MDT_Configuration_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_MDT_Configuration_tags_1)
		/sizeof(asn_DEF_NGAP_MDT_Configuration_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_MDT_Configuration_1,
	3,	/* Elements count */
	&asn_SPC_NGAP_MDT_Configuration_specs_1	/* Additional specs */
};

