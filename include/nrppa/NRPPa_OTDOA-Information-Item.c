/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NRPPa_OTDOA-Information-Item.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_NRPPa_OTDOA_Information_Item_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  5,  5,  0,  19 }	/* (0..19,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_NRPPa_OTDOA_Information_Item_value2enum_1[] = {
	{ 0,	3,	"pci" },
	{ 1,	3,	"cGI" },
	{ 2,	3,	"tac" },
	{ 3,	6,	"earfcn" },
	{ 4,	12,	"prsBandwidth" },
	{ 5,	14,	"prsConfigIndex" },
	{ 6,	8,	"cpLength" },
	{ 7,	10,	"noDlFrames" },
	{ 8,	14,	"noAntennaPorts" },
	{ 9,	11,	"sFNInitTime" },
	{ 10,	25,	"nG-RANAccessPointPosition" },
	{ 11,	22,	"prsmutingconfiguration" },
	{ 12,	5,	"prsid" },
	{ 13,	4,	"tpid" },
	{ 14,	6,	"tpType" },
	{ 15,	11,	"crsCPlength" },
	{ 16,	11,	"dlBandwidth" },
	{ 17,	32,	"multipleprsConfigurationsperCell" },
	{ 18,	16,	"prsOccasionGroup" },
	{ 19,	32,	"prsFrequencyHoppingConfiguration" },
	{ 20,	9,	"tddConfig" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NRPPa_OTDOA_Information_Item_enum2value_1[] = {
	1,	/* cGI(1) */
	6,	/* cpLength(6) */
	15,	/* crsCPlength(15) */
	16,	/* dlBandwidth(16) */
	3,	/* earfcn(3) */
	17,	/* multipleprsConfigurationsperCell(17) */
	10,	/* nG-RANAccessPointPosition(10) */
	8,	/* noAntennaPorts(8) */
	7,	/* noDlFrames(7) */
	0,	/* pci(0) */
	4,	/* prsBandwidth(4) */
	5,	/* prsConfigIndex(5) */
	19,	/* prsFrequencyHoppingConfiguration(19) */
	18,	/* prsOccasionGroup(18) */
	12,	/* prsid(12) */
	11,	/* prsmutingconfiguration(11) */
	9,	/* sFNInitTime(9) */
	2,	/* tac(2) */
	20,	/* tddConfig(20) */
	14,	/* tpType(14) */
	13	/* tpid(13) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_NRPPa_OTDOA_Information_Item_specs_1 = {
	asn_MAP_NRPPa_OTDOA_Information_Item_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_NRPPa_OTDOA_Information_Item_enum2value_1,	/* N => "tag"; sorted by N */
	21,	/* Number of elements in the maps */
	21,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NRPPa_OTDOA_Information_Item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_NRPPa_OTDOA_Information_Item = {
	"OTDOA-Information-Item",
	"OTDOA-Information-Item",
	&asn_OP_NativeEnumerated,
	asn_DEF_NRPPa_OTDOA_Information_Item_tags_1,
	sizeof(asn_DEF_NRPPa_OTDOA_Information_Item_tags_1)
		/sizeof(asn_DEF_NRPPa_OTDOA_Information_Item_tags_1[0]), /* 1 */
	asn_DEF_NRPPa_OTDOA_Information_Item_tags_1,	/* Same as above */
	sizeof(asn_DEF_NRPPa_OTDOA_Information_Item_tags_1)
		/sizeof(asn_DEF_NRPPa_OTDOA_Information_Item_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NRPPa_OTDOA_Information_Item_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NRPPa_OTDOA_Information_Item_specs_1	/* Additional specs */
};

