/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_ExcessPacketDelayThresholdValue.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_NGAP_ExcessPacketDelayThresholdValue_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  5,  5,  0,  18 }	/* (0..18,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_NGAP_ExcessPacketDelayThresholdValue_value2enum_1[] = {
	{ 0,	8,	"ms0dot25" },
	{ 1,	7,	"ms0dot5" },
	{ 2,	3,	"ms1" },
	{ 3,	3,	"ms2" },
	{ 4,	3,	"ms4" },
	{ 5,	3,	"ms5" },
	{ 6,	4,	"ms10" },
	{ 7,	4,	"ms20" },
	{ 8,	4,	"ms30" },
	{ 9,	4,	"ms40" },
	{ 10,	4,	"ms50" },
	{ 11,	4,	"ms60" },
	{ 12,	4,	"ms70" },
	{ 13,	4,	"ms80" },
	{ 14,	4,	"ms90" },
	{ 15,	5,	"ms100" },
	{ 16,	5,	"ms150" },
	{ 17,	5,	"ms300" },
	{ 18,	5,	"ms500" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NGAP_ExcessPacketDelayThresholdValue_enum2value_1[] = {
	0,	/* ms0dot25(0) */
	1,	/* ms0dot5(1) */
	2,	/* ms1(2) */
	6,	/* ms10(6) */
	15,	/* ms100(15) */
	16,	/* ms150(16) */
	3,	/* ms2(3) */
	7,	/* ms20(7) */
	8,	/* ms30(8) */
	17,	/* ms300(17) */
	4,	/* ms4(4) */
	9,	/* ms40(9) */
	5,	/* ms5(5) */
	10,	/* ms50(10) */
	18,	/* ms500(18) */
	11,	/* ms60(11) */
	12,	/* ms70(12) */
	13,	/* ms80(13) */
	14	/* ms90(14) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_NGAP_ExcessPacketDelayThresholdValue_specs_1 = {
	asn_MAP_NGAP_ExcessPacketDelayThresholdValue_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_NGAP_ExcessPacketDelayThresholdValue_enum2value_1,	/* N => "tag"; sorted by N */
	19,	/* Number of elements in the maps */
	20,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NGAP_ExcessPacketDelayThresholdValue_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_NGAP_ExcessPacketDelayThresholdValue = {
	"ExcessPacketDelayThresholdValue",
	"ExcessPacketDelayThresholdValue",
	&asn_OP_NativeEnumerated,
	asn_DEF_NGAP_ExcessPacketDelayThresholdValue_tags_1,
	sizeof(asn_DEF_NGAP_ExcessPacketDelayThresholdValue_tags_1)
		/sizeof(asn_DEF_NGAP_ExcessPacketDelayThresholdValue_tags_1[0]), /* 1 */
	asn_DEF_NGAP_ExcessPacketDelayThresholdValue_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_ExcessPacketDelayThresholdValue_tags_1)
		/sizeof(asn_DEF_NGAP_ExcessPacketDelayThresholdValue_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NGAP_ExcessPacketDelayThresholdValue_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NGAP_ExcessPacketDelayThresholdValue_specs_1	/* Additional specs */
};

