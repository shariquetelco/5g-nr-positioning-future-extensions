/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NRPPa_TimeWindowInformation-Measurement-Item.h"

#include "NRPPa_ProtocolExtensionContainer.h"
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_NRPPa_timeWindowType_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_NRPPa_timeWindowType_value2enum_3[] = {
	{ 0,	6,	"single" },
	{ 1,	8,	"periodic" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NRPPa_timeWindowType_enum2value_3[] = {
	1,	/* periodic(1) */
	0	/* single(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_NRPPa_timeWindowType_specs_3 = {
	asn_MAP_NRPPa_timeWindowType_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_NRPPa_timeWindowType_enum2value_3,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	3,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NRPPa_timeWindowType_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_NRPPa_timeWindowType_3 = {
	"timeWindowType",
	"timeWindowType",
	&asn_OP_NativeEnumerated,
	asn_DEF_NRPPa_timeWindowType_tags_3,
	sizeof(asn_DEF_NRPPa_timeWindowType_tags_3)
		/sizeof(asn_DEF_NRPPa_timeWindowType_tags_3[0]) - 1, /* 1 */
	asn_DEF_NRPPa_timeWindowType_tags_3,	/* Same as above */
	sizeof(asn_DEF_NRPPa_timeWindowType_tags_3)
		/sizeof(asn_DEF_NRPPa_timeWindowType_tags_3[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NRPPa_timeWindowType_constr_3,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NRPPa_timeWindowType_specs_3	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_NRPPa_TimeWindowInformation_Measurement_Item_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_TimeWindowInformation_Measurement_Item, timeWindowDurationMeasurement),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NRPPa_TimeWindowDurationMeasurement,
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
		"timeWindowDurationMeasurement"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_TimeWindowInformation_Measurement_Item, timeWindowType),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_timeWindowType_3,
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
		"timeWindowType"
		},
	{ ATF_POINTER, 2, offsetof(struct NRPPa_TimeWindowInformation_Measurement_Item, timeWindowPeriodicityMeasurement),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_TimeWindowPeriodicityMeasurement,
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
		"timeWindowPeriodicityMeasurement"
		},
	{ ATF_POINTER, 1, offsetof(struct NRPPa_TimeWindowInformation_Measurement_Item, iE_Extension),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_ProtocolExtensionContainer_4443P136,
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
		"iE-Extension"
		},
};
static const int asn_MAP_NRPPa_TimeWindowInformation_Measurement_Item_oms_1[] = { 2, 3 };
static const ber_tlv_tag_t asn_DEF_NRPPa_TimeWindowInformation_Measurement_Item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NRPPa_TimeWindowInformation_Measurement_Item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* timeWindowDurationMeasurement */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* timeWindowType */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* timeWindowPeriodicityMeasurement */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* iE-Extension */
};
asn_SEQUENCE_specifics_t asn_SPC_NRPPa_TimeWindowInformation_Measurement_Item_specs_1 = {
	sizeof(struct NRPPa_TimeWindowInformation_Measurement_Item),
	offsetof(struct NRPPa_TimeWindowInformation_Measurement_Item, _asn_ctx),
	asn_MAP_NRPPa_TimeWindowInformation_Measurement_Item_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_NRPPa_TimeWindowInformation_Measurement_Item_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	4,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NRPPa_TimeWindowInformation_Measurement_Item = {
	"TimeWindowInformation-Measurement-Item",
	"TimeWindowInformation-Measurement-Item",
	&asn_OP_SEQUENCE,
	asn_DEF_NRPPa_TimeWindowInformation_Measurement_Item_tags_1,
	sizeof(asn_DEF_NRPPa_TimeWindowInformation_Measurement_Item_tags_1)
		/sizeof(asn_DEF_NRPPa_TimeWindowInformation_Measurement_Item_tags_1[0]), /* 1 */
	asn_DEF_NRPPa_TimeWindowInformation_Measurement_Item_tags_1,	/* Same as above */
	sizeof(asn_DEF_NRPPa_TimeWindowInformation_Measurement_Item_tags_1)
		/sizeof(asn_DEF_NRPPa_TimeWindowInformation_Measurement_Item_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NRPPa_TimeWindowInformation_Measurement_Item_1,
	4,	/* Elements count */
	&asn_SPC_NRPPa_TimeWindowInformation_Measurement_Item_specs_1	/* Additional specs */
};

