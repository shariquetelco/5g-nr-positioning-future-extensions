/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NRPPa_PRSTransmissionOffIndication.h"

#include "NRPPa_PRSTransmissionOffPerResourceSet.h"
#include "NRPPa_PRSTransmissionOffPerResource.h"
#include "NRPPa_ProtocolIE-Single-Container.h"
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_NRPPa_PRSTransmissionOffIndication_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
asn_TYPE_member_t asn_MBR_NRPPa_PRSTransmissionOffIndication_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_PRSTransmissionOffIndication, choice.pRSTransmissionOffPerTRP),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
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
		"pRSTransmissionOffPerTRP"
		},
	{ ATF_POINTER, 0, offsetof(struct NRPPa_PRSTransmissionOffIndication, choice.pRSTransmissionOffPerResourceSet),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_PRSTransmissionOffPerResourceSet,
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
		"pRSTransmissionOffPerResourceSet"
		},
	{ ATF_POINTER, 0, offsetof(struct NRPPa_PRSTransmissionOffIndication, choice.pRSTransmissionOffPerResource),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_PRSTransmissionOffPerResource,
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
		"pRSTransmissionOffPerResource"
		},
	{ ATF_POINTER, 0, offsetof(struct NRPPa_PRSTransmissionOffIndication, choice.choice_Extension),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_ProtocolIE_Single_Container_4422P23,
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
		"choice-Extension"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_NRPPa_PRSTransmissionOffIndication_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pRSTransmissionOffPerTRP */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* pRSTransmissionOffPerResourceSet */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* pRSTransmissionOffPerResource */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* choice-Extension */
};
asn_CHOICE_specifics_t asn_SPC_NRPPa_PRSTransmissionOffIndication_specs_1 = {
	sizeof(struct NRPPa_PRSTransmissionOffIndication),
	offsetof(struct NRPPa_PRSTransmissionOffIndication, _asn_ctx),
	offsetof(struct NRPPa_PRSTransmissionOffIndication, present),
	sizeof(((struct NRPPa_PRSTransmissionOffIndication *)0)->present),
	asn_MAP_NRPPa_PRSTransmissionOffIndication_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_NRPPa_PRSTransmissionOffIndication = {
	"PRSTransmissionOffIndication",
	"PRSTransmissionOffIndication",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NRPPa_PRSTransmissionOffIndication_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		CHOICE_constraint
	},
	asn_MBR_NRPPa_PRSTransmissionOffIndication_1,
	4,	/* Elements count */
	&asn_SPC_NRPPa_PRSTransmissionOffIndication_specs_1	/* Additional specs */
};

