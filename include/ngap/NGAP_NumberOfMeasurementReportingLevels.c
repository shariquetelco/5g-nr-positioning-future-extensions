/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_NumberOfMeasurementReportingLevels.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_NGAP_NumberOfMeasurementReportingLevels_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  3,  3,  0,  4 }	/* (0..4,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_NGAP_NumberOfMeasurementReportingLevels_value2enum_1[] = {
	{ 0,	2,	"n2" },
	{ 1,	2,	"n3" },
	{ 2,	2,	"n4" },
	{ 3,	2,	"n5" },
	{ 4,	3,	"n10" },
	{ 5,	2,	"n0" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NGAP_NumberOfMeasurementReportingLevels_enum2value_1[] = {
	5,	/* n0(5) */
	4,	/* n10(4) */
	0,	/* n2(0) */
	1,	/* n3(1) */
	2,	/* n4(2) */
	3	/* n5(3) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_NGAP_NumberOfMeasurementReportingLevels_specs_1 = {
	asn_MAP_NGAP_NumberOfMeasurementReportingLevels_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_NGAP_NumberOfMeasurementReportingLevels_enum2value_1,	/* N => "tag"; sorted by N */
	6,	/* Number of elements in the maps */
	6,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NGAP_NumberOfMeasurementReportingLevels_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_NGAP_NumberOfMeasurementReportingLevels = {
	"NumberOfMeasurementReportingLevels",
	"NumberOfMeasurementReportingLevels",
	&asn_OP_NativeEnumerated,
	asn_DEF_NGAP_NumberOfMeasurementReportingLevels_tags_1,
	sizeof(asn_DEF_NGAP_NumberOfMeasurementReportingLevels_tags_1)
		/sizeof(asn_DEF_NGAP_NumberOfMeasurementReportingLevels_tags_1[0]), /* 1 */
	asn_DEF_NGAP_NumberOfMeasurementReportingLevels_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_NumberOfMeasurementReportingLevels_tags_1)
		/sizeof(asn_DEF_NGAP_NumberOfMeasurementReportingLevels_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NGAP_NumberOfMeasurementReportingLevels_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NGAP_NumberOfMeasurementReportingLevels_specs_1	/* Additional specs */
};

