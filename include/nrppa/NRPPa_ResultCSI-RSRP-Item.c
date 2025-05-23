/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NRPPa_ResultCSI-RSRP-Item.h"

#include "NRPPa_CGI-NR.h"
#include "NRPPa_ResultCSI-RSRP-PerCSI-RS.h"
#include "NRPPa_ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_NRPPa_ResultCSI_RSRP_Item_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_ResultCSI_RSRP_Item, nR_PCI),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_NR_PCI,
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
		"nR-PCI"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_ResultCSI_RSRP_Item, nR_ARFCN),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_NR_ARFCN,
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
		"nR-ARFCN"
		},
	{ ATF_POINTER, 4, offsetof(struct NRPPa_ResultCSI_RSRP_Item, cGI_NR),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_CGI_NR,
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
		"cGI-NR"
		},
	{ ATF_POINTER, 3, offsetof(struct NRPPa_ResultCSI_RSRP_Item, valueCSI_RSRP_Cell),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_ValueRSRP_NR,
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
		"valueCSI-RSRP-Cell"
		},
	{ ATF_POINTER, 2, offsetof(struct NRPPa_ResultCSI_RSRP_Item, cSI_RSRP_PerCSI_RS),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_ResultCSI_RSRP_PerCSI_RS,
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
		"cSI-RSRP-PerCSI-RS"
		},
	{ ATF_POINTER, 1, offsetof(struct NRPPa_ResultCSI_RSRP_Item, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_ProtocolExtensionContainer_4443P92,
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
static const int asn_MAP_NRPPa_ResultCSI_RSRP_Item_oms_1[] = { 2, 3, 4, 5 };
static const ber_tlv_tag_t asn_DEF_NRPPa_ResultCSI_RSRP_Item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NRPPa_ResultCSI_RSRP_Item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* nR-PCI */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* nR-ARFCN */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* cGI-NR */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* valueCSI-RSRP-Cell */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* cSI-RSRP-PerCSI-RS */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NRPPa_ResultCSI_RSRP_Item_specs_1 = {
	sizeof(struct NRPPa_ResultCSI_RSRP_Item),
	offsetof(struct NRPPa_ResultCSI_RSRP_Item, _asn_ctx),
	asn_MAP_NRPPa_ResultCSI_RSRP_Item_tag2el_1,
	6,	/* Count of tags in the map */
	asn_MAP_NRPPa_ResultCSI_RSRP_Item_oms_1,	/* Optional members */
	4, 0,	/* Root/Additions */
	6,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NRPPa_ResultCSI_RSRP_Item = {
	"ResultCSI-RSRP-Item",
	"ResultCSI-RSRP-Item",
	&asn_OP_SEQUENCE,
	asn_DEF_NRPPa_ResultCSI_RSRP_Item_tags_1,
	sizeof(asn_DEF_NRPPa_ResultCSI_RSRP_Item_tags_1)
		/sizeof(asn_DEF_NRPPa_ResultCSI_RSRP_Item_tags_1[0]), /* 1 */
	asn_DEF_NRPPa_ResultCSI_RSRP_Item_tags_1,	/* Same as above */
	sizeof(asn_DEF_NRPPa_ResultCSI_RSRP_Item_tags_1)
		/sizeof(asn_DEF_NRPPa_ResultCSI_RSRP_Item_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NRPPa_ResultCSI_RSRP_Item_1,
	6,	/* Elements count */
	&asn_SPC_NRPPa_ResultCSI_RSRP_Item_specs_1	/* Additional specs */
};

