/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NRPPa_RequestedDLPRSResourceSet-Item.h"

#include "NRPPa_RequestedDLPRSResource-List.h"
#include "NRPPa_StartTimeAndDuration.h"
#include "NRPPa_ProtocolExtensionContainer.h"
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static int
memb_NRPPa_pRSbandwidth_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1L && value <= 63L)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_NRPPa_combSize_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  3 }	/* (0..3,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_NRPPa_resourceSetPeriodicity_constr_9 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  5,  5,  0,  19 }	/* (0..19,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_NRPPa_resourceRepetitionFactor_constr_34 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  3,  3,  0,  6 }	/* (0..6,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_NRPPa_resourceNumberofSymbols_constr_43 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  3 }	/* (0..3,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_NRPPa_pRSbandwidth_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 6,  6,  1,  63 }	/* (1..63) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_NRPPa_combSize_value2enum_3[] = {
	{ 0,	2,	"n2" },
	{ 1,	2,	"n4" },
	{ 2,	2,	"n6" },
	{ 3,	3,	"n12" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NRPPa_combSize_enum2value_3[] = {
	3,	/* n12(3) */
	0,	/* n2(0) */
	1,	/* n4(1) */
	2	/* n6(2) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_NRPPa_combSize_specs_3 = {
	asn_MAP_NRPPa_combSize_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_NRPPa_combSize_enum2value_3,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	5,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NRPPa_combSize_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_NRPPa_combSize_3 = {
	"combSize",
	"combSize",
	&asn_OP_NativeEnumerated,
	asn_DEF_NRPPa_combSize_tags_3,
	sizeof(asn_DEF_NRPPa_combSize_tags_3)
		/sizeof(asn_DEF_NRPPa_combSize_tags_3[0]) - 1, /* 1 */
	asn_DEF_NRPPa_combSize_tags_3,	/* Same as above */
	sizeof(asn_DEF_NRPPa_combSize_tags_3)
		/sizeof(asn_DEF_NRPPa_combSize_tags_3[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NRPPa_combSize_constr_3,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NRPPa_combSize_specs_3	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_NRPPa_resourceSetPeriodicity_value2enum_9[] = {
	{ 0,	2,	"n4" },
	{ 1,	2,	"n5" },
	{ 2,	2,	"n8" },
	{ 3,	3,	"n10" },
	{ 4,	3,	"n16" },
	{ 5,	3,	"n20" },
	{ 6,	3,	"n32" },
	{ 7,	3,	"n40" },
	{ 8,	3,	"n64" },
	{ 9,	3,	"n80" },
	{ 10,	4,	"n160" },
	{ 11,	4,	"n320" },
	{ 12,	4,	"n640" },
	{ 13,	5,	"n1280" },
	{ 14,	5,	"n2560" },
	{ 15,	5,	"n5120" },
	{ 16,	6,	"n10240" },
	{ 17,	6,	"n20480" },
	{ 18,	6,	"n40960" },
	{ 19,	6,	"n81920" },
	{ 20,	4,	"n128" },
	{ 21,	4,	"n256" },
	{ 22,	4,	"n512" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NRPPa_resourceSetPeriodicity_enum2value_9[] = {
	3,	/* n10(3) */
	16,	/* n10240(16) */
	20,	/* n128(20) */
	13,	/* n1280(13) */
	4,	/* n16(4) */
	10,	/* n160(10) */
	5,	/* n20(5) */
	17,	/* n20480(17) */
	21,	/* n256(21) */
	14,	/* n2560(14) */
	6,	/* n32(6) */
	11,	/* n320(11) */
	0,	/* n4(0) */
	7,	/* n40(7) */
	18,	/* n40960(18) */
	1,	/* n5(1) */
	22,	/* n512(22) */
	15,	/* n5120(15) */
	8,	/* n64(8) */
	12,	/* n640(12) */
	2,	/* n8(2) */
	9,	/* n80(9) */
	19	/* n81920(19) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_NRPPa_resourceSetPeriodicity_specs_9 = {
	asn_MAP_NRPPa_resourceSetPeriodicity_value2enum_9,	/* "tag" => N; sorted by tag */
	asn_MAP_NRPPa_resourceSetPeriodicity_enum2value_9,	/* N => "tag"; sorted by N */
	23,	/* Number of elements in the maps */
	21,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NRPPa_resourceSetPeriodicity_tags_9[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_NRPPa_resourceSetPeriodicity_9 = {
	"resourceSetPeriodicity",
	"resourceSetPeriodicity",
	&asn_OP_NativeEnumerated,
	asn_DEF_NRPPa_resourceSetPeriodicity_tags_9,
	sizeof(asn_DEF_NRPPa_resourceSetPeriodicity_tags_9)
		/sizeof(asn_DEF_NRPPa_resourceSetPeriodicity_tags_9[0]) - 1, /* 1 */
	asn_DEF_NRPPa_resourceSetPeriodicity_tags_9,	/* Same as above */
	sizeof(asn_DEF_NRPPa_resourceSetPeriodicity_tags_9)
		/sizeof(asn_DEF_NRPPa_resourceSetPeriodicity_tags_9[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NRPPa_resourceSetPeriodicity_constr_9,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NRPPa_resourceSetPeriodicity_specs_9	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_NRPPa_resourceRepetitionFactor_value2enum_34[] = {
	{ 0,	3,	"rf1" },
	{ 1,	3,	"rf2" },
	{ 2,	3,	"rf4" },
	{ 3,	3,	"rf6" },
	{ 4,	3,	"rf8" },
	{ 5,	4,	"rf16" },
	{ 6,	4,	"rf32" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NRPPa_resourceRepetitionFactor_enum2value_34[] = {
	0,	/* rf1(0) */
	5,	/* rf16(5) */
	1,	/* rf2(1) */
	6,	/* rf32(6) */
	2,	/* rf4(2) */
	3,	/* rf6(3) */
	4	/* rf8(4) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_NRPPa_resourceRepetitionFactor_specs_34 = {
	asn_MAP_NRPPa_resourceRepetitionFactor_value2enum_34,	/* "tag" => N; sorted by tag */
	asn_MAP_NRPPa_resourceRepetitionFactor_enum2value_34,	/* N => "tag"; sorted by N */
	7,	/* Number of elements in the maps */
	8,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NRPPa_resourceRepetitionFactor_tags_34[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_NRPPa_resourceRepetitionFactor_34 = {
	"resourceRepetitionFactor",
	"resourceRepetitionFactor",
	&asn_OP_NativeEnumerated,
	asn_DEF_NRPPa_resourceRepetitionFactor_tags_34,
	sizeof(asn_DEF_NRPPa_resourceRepetitionFactor_tags_34)
		/sizeof(asn_DEF_NRPPa_resourceRepetitionFactor_tags_34[0]) - 1, /* 1 */
	asn_DEF_NRPPa_resourceRepetitionFactor_tags_34,	/* Same as above */
	sizeof(asn_DEF_NRPPa_resourceRepetitionFactor_tags_34)
		/sizeof(asn_DEF_NRPPa_resourceRepetitionFactor_tags_34[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NRPPa_resourceRepetitionFactor_constr_34,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NRPPa_resourceRepetitionFactor_specs_34	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_NRPPa_resourceNumberofSymbols_value2enum_43[] = {
	{ 0,	2,	"n2" },
	{ 1,	2,	"n4" },
	{ 2,	2,	"n6" },
	{ 3,	3,	"n12" },
	{ 4,	2,	"n1" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NRPPa_resourceNumberofSymbols_enum2value_43[] = {
	4,	/* n1(4) */
	3,	/* n12(3) */
	0,	/* n2(0) */
	1,	/* n4(1) */
	2	/* n6(2) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_NRPPa_resourceNumberofSymbols_specs_43 = {
	asn_MAP_NRPPa_resourceNumberofSymbols_value2enum_43,	/* "tag" => N; sorted by tag */
	asn_MAP_NRPPa_resourceNumberofSymbols_enum2value_43,	/* N => "tag"; sorted by N */
	5,	/* Number of elements in the maps */
	5,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NRPPa_resourceNumberofSymbols_tags_43[] = {
	(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_NRPPa_resourceNumberofSymbols_43 = {
	"resourceNumberofSymbols",
	"resourceNumberofSymbols",
	&asn_OP_NativeEnumerated,
	asn_DEF_NRPPa_resourceNumberofSymbols_tags_43,
	sizeof(asn_DEF_NRPPa_resourceNumberofSymbols_tags_43)
		/sizeof(asn_DEF_NRPPa_resourceNumberofSymbols_tags_43[0]) - 1, /* 1 */
	asn_DEF_NRPPa_resourceNumberofSymbols_tags_43,	/* Same as above */
	sizeof(asn_DEF_NRPPa_resourceNumberofSymbols_tags_43)
		/sizeof(asn_DEF_NRPPa_resourceNumberofSymbols_tags_43[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NRPPa_resourceNumberofSymbols_constr_43,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NRPPa_resourceNumberofSymbols_specs_43	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_NRPPa_RequestedDLPRSResourceSet_Item_1[] = {
	{ ATF_POINTER, 8, offsetof(struct NRPPa_RequestedDLPRSResourceSet_Item, pRSbandwidth),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_NRPPa_pRSbandwidth_constr_2,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_NRPPa_pRSbandwidth_constraint_1
		},
		0, 0, /* No default value */
		"pRSbandwidth"
		},
	{ ATF_POINTER, 7, offsetof(struct NRPPa_RequestedDLPRSResourceSet_Item, combSize),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_combSize_3,
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
		"combSize"
		},
	{ ATF_POINTER, 6, offsetof(struct NRPPa_RequestedDLPRSResourceSet_Item, resourceSetPeriodicity),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_resourceSetPeriodicity_9,
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
		"resourceSetPeriodicity"
		},
	{ ATF_POINTER, 5, offsetof(struct NRPPa_RequestedDLPRSResourceSet_Item, resourceRepetitionFactor),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_resourceRepetitionFactor_34,
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
		"resourceRepetitionFactor"
		},
	{ ATF_POINTER, 4, offsetof(struct NRPPa_RequestedDLPRSResourceSet_Item, resourceNumberofSymbols),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_resourceNumberofSymbols_43,
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
		"resourceNumberofSymbols"
		},
	{ ATF_POINTER, 3, offsetof(struct NRPPa_RequestedDLPRSResourceSet_Item, requestedDLPRSResource_List),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_RequestedDLPRSResource_List,
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
		"requestedDLPRSResource-List"
		},
	{ ATF_POINTER, 2, offsetof(struct NRPPa_RequestedDLPRSResourceSet_Item, resourceSetStartTimeAndDuration),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_StartTimeAndDuration,
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
		"resourceSetStartTimeAndDuration"
		},
	{ ATF_POINTER, 1, offsetof(struct NRPPa_RequestedDLPRSResourceSet_Item, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_ProtocolExtensionContainer_4443P76,
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
static const int asn_MAP_NRPPa_RequestedDLPRSResourceSet_Item_oms_1[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
static const ber_tlv_tag_t asn_DEF_NRPPa_RequestedDLPRSResourceSet_Item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NRPPa_RequestedDLPRSResourceSet_Item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pRSbandwidth */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* combSize */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* resourceSetPeriodicity */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* resourceRepetitionFactor */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* resourceNumberofSymbols */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* requestedDLPRSResource-List */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* resourceSetStartTimeAndDuration */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NRPPa_RequestedDLPRSResourceSet_Item_specs_1 = {
	sizeof(struct NRPPa_RequestedDLPRSResourceSet_Item),
	offsetof(struct NRPPa_RequestedDLPRSResourceSet_Item, _asn_ctx),
	asn_MAP_NRPPa_RequestedDLPRSResourceSet_Item_tag2el_1,
	8,	/* Count of tags in the map */
	asn_MAP_NRPPa_RequestedDLPRSResourceSet_Item_oms_1,	/* Optional members */
	8, 0,	/* Root/Additions */
	8,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NRPPa_RequestedDLPRSResourceSet_Item = {
	"RequestedDLPRSResourceSet-Item",
	"RequestedDLPRSResourceSet-Item",
	&asn_OP_SEQUENCE,
	asn_DEF_NRPPa_RequestedDLPRSResourceSet_Item_tags_1,
	sizeof(asn_DEF_NRPPa_RequestedDLPRSResourceSet_Item_tags_1)
		/sizeof(asn_DEF_NRPPa_RequestedDLPRSResourceSet_Item_tags_1[0]), /* 1 */
	asn_DEF_NRPPa_RequestedDLPRSResourceSet_Item_tags_1,	/* Same as above */
	sizeof(asn_DEF_NRPPa_RequestedDLPRSResourceSet_Item_tags_1)
		/sizeof(asn_DEF_NRPPa_RequestedDLPRSResourceSet_Item_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NRPPa_RequestedDLPRSResourceSet_Item_1,
	8,	/* Elements count */
	&asn_SPC_NRPPa_RequestedDLPRSResourceSet_Item_specs_1	/* Additional specs */
};

