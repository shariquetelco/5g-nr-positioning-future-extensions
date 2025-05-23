/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-PDU-Descriptions"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NRPPa_UnsuccessfulOutcome.h"

static const long asn_VAL_1_NRPPa_id_e_CIDMeasurementInitiation = 2;
static const long asn_VAL_1_NRPPa_reject = 0;
static const long asn_VAL_2_NRPPa_id_oTDOAInformationExchange = 6;
static const long asn_VAL_2_NRPPa_reject = 0;
static const long asn_VAL_3_NRPPa_id_positioningInformationExchange = 9;
static const long asn_VAL_3_NRPPa_reject = 0;
static const long asn_VAL_4_NRPPa_id_Measurement = 11;
static const long asn_VAL_4_NRPPa_reject = 0;
static const long asn_VAL_5_NRPPa_id_tRPInformationExchange = 16;
static const long asn_VAL_5_NRPPa_reject = 0;
static const long asn_VAL_6_NRPPa_id_positioningActivation = 17;
static const long asn_VAL_6_NRPPa_reject = 0;
static const long asn_VAL_7_NRPPa_id_pRSConfigurationExchange = 19;
static const long asn_VAL_7_NRPPa_reject = 0;
static const long asn_VAL_8_NRPPa_id_measurementPreconfiguration = 20;
static const long asn_VAL_8_NRPPa_reject = 0;
static const long asn_VAL_9_NRPPa_id_e_CIDMeasurementFailureIndication = 3;
static const long asn_VAL_9_NRPPa_ignore = 1;
static const long asn_VAL_10_NRPPa_id_e_CIDMeasurementReport = 4;
static const long asn_VAL_10_NRPPa_ignore = 1;
static const long asn_VAL_11_NRPPa_id_e_CIDMeasurementTermination = 5;
static const long asn_VAL_11_NRPPa_reject = 0;
static const long asn_VAL_12_NRPPa_id_errorIndication = 0;
static const long asn_VAL_12_NRPPa_ignore = 1;
static const long asn_VAL_13_NRPPa_id_privateMessage = 1;
static const long asn_VAL_13_NRPPa_ignore = 1;
static const long asn_VAL_14_NRPPa_id_assistanceInformationControl = 7;
static const long asn_VAL_14_NRPPa_reject = 0;
static const long asn_VAL_15_NRPPa_id_assistanceInformationFeedback = 8;
static const long asn_VAL_15_NRPPa_reject = 0;
static const long asn_VAL_16_NRPPa_id_positioningInformationUpdate = 10;
static const long asn_VAL_16_NRPPa_ignore = 1;
static const long asn_VAL_17_NRPPa_id_MeasurementReport = 12;
static const long asn_VAL_17_NRPPa_ignore = 1;
static const long asn_VAL_18_NRPPa_id_MeasurementUpdate = 13;
static const long asn_VAL_18_NRPPa_ignore = 1;
static const long asn_VAL_19_NRPPa_id_MeasurementAbort = 14;
static const long asn_VAL_19_NRPPa_ignore = 1;
static const long asn_VAL_20_NRPPa_id_MeasurementFailureIndication = 15;
static const long asn_VAL_20_NRPPa_ignore = 1;
static const long asn_VAL_21_NRPPa_id_positioningDeactivation = 18;
static const long asn_VAL_21_NRPPa_ignore = 1;
static const long asn_VAL_22_NRPPa_id_measurementActivation = 21;
static const long asn_VAL_22_NRPPa_ignore = 1;
static const long asn_VAL_23_NRPPa_id_sRSInformationReservationNotification = 22;
static const long asn_VAL_23_NRPPa_reject = 0;
static const asn_ioc_cell_t asn_IOS_NRPPa_NRPPA_ELEMENTARY_PROCEDURES_1_rows[] = {
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_E_CIDMeasurementInitiationRequest },
	{ "&SuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_E_CIDMeasurementInitiationResponse },
	{ "&UnsuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_E_CIDMeasurementInitiationFailure },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_1_NRPPa_id_e_CIDMeasurementInitiation },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_1_NRPPa_reject },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_OTDOAInformationRequest },
	{ "&SuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_OTDOAInformationResponse },
	{ "&UnsuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_OTDOAInformationFailure },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_2_NRPPa_id_oTDOAInformationExchange },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_2_NRPPa_reject },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_PositioningInformationRequest },
	{ "&SuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_PositioningInformationResponse },
	{ "&UnsuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_PositioningInformationFailure },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_3_NRPPa_id_positioningInformationExchange },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_3_NRPPa_reject },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_MeasurementRequest },
	{ "&SuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_MeasurementResponse },
	{ "&UnsuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_MeasurementFailure },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_4_NRPPa_id_Measurement },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_4_NRPPa_reject },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_TRPInformationRequest },
	{ "&SuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_TRPInformationResponse },
	{ "&UnsuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_TRPInformationFailure },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_5_NRPPa_id_tRPInformationExchange },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_5_NRPPa_reject },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_PositioningActivationRequest },
	{ "&SuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_PositioningActivationResponse },
	{ "&UnsuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_PositioningActivationFailure },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_6_NRPPa_id_positioningActivation },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_6_NRPPa_reject },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_PRSConfigurationRequest },
	{ "&SuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_PRSConfigurationResponse },
	{ "&UnsuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_PRSConfigurationFailure },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_7_NRPPa_id_pRSConfigurationExchange },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_7_NRPPa_reject },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_MeasurementPreconfigurationRequired },
	{ "&SuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_MeasurementPreconfigurationConfirm },
	{ "&UnsuccessfulOutcome", aioc__type, &asn_DEF_NRPPa_MeasurementPreconfigurationRefuse },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_8_NRPPa_id_measurementPreconfiguration },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_8_NRPPa_reject },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_E_CIDMeasurementFailureIndication },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_9_NRPPa_id_e_CIDMeasurementFailureIndication },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_9_NRPPa_ignore },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_E_CIDMeasurementReport },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_10_NRPPa_id_e_CIDMeasurementReport },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_10_NRPPa_ignore },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_E_CIDMeasurementTerminationCommand },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_11_NRPPa_id_e_CIDMeasurementTermination },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_11_NRPPa_reject },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_ErrorIndication },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_12_NRPPa_id_errorIndication },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_12_NRPPa_ignore },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_PrivateMessage },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_13_NRPPa_id_privateMessage },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_13_NRPPa_ignore },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_AssistanceInformationControl },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_14_NRPPa_id_assistanceInformationControl },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_14_NRPPa_reject },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_AssistanceInformationFeedback },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_15_NRPPa_id_assistanceInformationFeedback },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_15_NRPPa_reject },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_PositioningInformationUpdate },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_16_NRPPa_id_positioningInformationUpdate },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_16_NRPPa_ignore },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_MeasurementReport },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_17_NRPPa_id_MeasurementReport },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_17_NRPPa_ignore },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_MeasurementUpdate },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_18_NRPPa_id_MeasurementUpdate },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_18_NRPPa_ignore },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_MeasurementAbort },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_19_NRPPa_id_MeasurementAbort },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_19_NRPPa_ignore },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_MeasurementFailureIndication },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_20_NRPPa_id_MeasurementFailureIndication },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_20_NRPPa_ignore },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_PositioningDeactivation },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_21_NRPPa_id_positioningDeactivation },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_21_NRPPa_ignore },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_MeasurementActivation },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_22_NRPPa_id_measurementActivation },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_22_NRPPa_ignore },
	{ "&InitiatingMessage", aioc__type, &asn_DEF_NRPPa_SRSInformationReservationNotification },
	{ "&SuccessfulOutcome",  },
	{ "&UnsuccessfulOutcome",  },
	{ "&procedureCode", aioc__value, &asn_DEF_NRPPa_ProcedureCode, &asn_VAL_23_NRPPa_id_sRSInformationReservationNotification },
	{ "&criticality", aioc__value, &asn_DEF_NRPPa_Criticality, &asn_VAL_23_NRPPa_reject }
};
static const asn_ioc_set_t asn_IOS_NRPPa_NRPPA_ELEMENTARY_PROCEDURES_1[] = {
	{ 23, 5, asn_IOS_NRPPa_NRPPA_ELEMENTARY_PROCEDURES_1_rows }
};
static int
memb_NRPPa_procedureCode_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0L && value <= 255L)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_type_selector_result_t
select_UnsuccessfulOutcome_NRPPa_criticality_type(const asn_TYPE_descriptor_t *parent_type, const void *parent_sptr) {
	asn_type_selector_result_t result = {0, 0};
	const asn_ioc_set_t *itable = asn_IOS_NRPPa_NRPPA_ELEMENTARY_PROCEDURES_1;
	size_t constraining_column = 3; /* &procedureCode */
	size_t for_column = 4; /* &criticality */
	size_t row, presence_index = 0;
	const long *constraining_value = (const long *)((const char *)parent_sptr + offsetof(struct NRPPa_UnsuccessfulOutcome, procedureCode));
	
	for(row=0; row < itable->rows_count; row++) {
	    const asn_ioc_cell_t *constraining_cell = &itable->rows[row * itable->columns_count + constraining_column];
	    const asn_ioc_cell_t *type_cell = &itable->rows[row * itable->columns_count + for_column];
	
	    if(type_cell->cell_kind == aioc__undefined)
	        continue;
	
	    presence_index++;
	    if(constraining_cell->type_descriptor->op->compare_struct(constraining_cell->type_descriptor, constraining_value, constraining_cell->value_sptr) == 0) {
	        result.type_descriptor = type_cell->type_descriptor;
	        result.presence_index = presence_index;
	        break;
	    }
	}
	
	return result;
}

static int
memb_NRPPa_criticality_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		/* Nothing is here. See below */
	}
	
	return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
}

static asn_type_selector_result_t
select_UnsuccessfulOutcome_NRPPa_value_type(const asn_TYPE_descriptor_t *parent_type, const void *parent_sptr) {
	asn_type_selector_result_t result = {0, 0};
	const asn_ioc_set_t *itable = asn_IOS_NRPPa_NRPPA_ELEMENTARY_PROCEDURES_1;
	size_t constraining_column = 3; /* &procedureCode */
	size_t for_column = 2; /* &UnsuccessfulOutcome */
	size_t row, presence_index = 0;
	const long *constraining_value = (const long *)((const char *)parent_sptr + offsetof(struct NRPPa_UnsuccessfulOutcome, procedureCode));
	
	for(row=0; row < itable->rows_count; row++) {
	    const asn_ioc_cell_t *constraining_cell = &itable->rows[row * itable->columns_count + constraining_column];
	    const asn_ioc_cell_t *type_cell = &itable->rows[row * itable->columns_count + for_column];
	
	    if(type_cell->cell_kind == aioc__undefined)
	        continue;
	
	    presence_index++;
	    if(constraining_cell->type_descriptor->op->compare_struct(constraining_cell->type_descriptor, constraining_value, constraining_cell->value_sptr) == 0) {
	        result.type_descriptor = type_cell->type_descriptor;
	        result.presence_index = presence_index;
	        break;
	    }
	}
	
	return result;
}

static int
memb_NRPPa_value_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		/* Nothing is here. See below */
	}
	
	return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
}

#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_NRPPa_procedureCode_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0,  255 }	/* (0..255) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_NRPPa_criticality_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  2 }	/* (0..2) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_NRPPa_value_constr_5 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static asn_TYPE_member_t asn_MBR_NRPPa_value_5[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_UnsuccessfulOutcome__value, choice.E_CIDMeasurementInitiationFailure),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_NRPPa_E_CIDMeasurementInitiationFailure,
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
		"E-CIDMeasurementInitiationFailure"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_UnsuccessfulOutcome__value, choice.OTDOAInformationFailure),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_NRPPa_OTDOAInformationFailure,
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
		"OTDOAInformationFailure"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_UnsuccessfulOutcome__value, choice.PositioningInformationFailure),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_NRPPa_PositioningInformationFailure,
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
		"PositioningInformationFailure"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_UnsuccessfulOutcome__value, choice.MeasurementFailure),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_NRPPa_MeasurementFailure,
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
		"MeasurementFailure"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_UnsuccessfulOutcome__value, choice.TRPInformationFailure),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_NRPPa_TRPInformationFailure,
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
		"TRPInformationFailure"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_UnsuccessfulOutcome__value, choice.PositioningActivationFailure),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_NRPPa_PositioningActivationFailure,
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
		"PositioningActivationFailure"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_UnsuccessfulOutcome__value, choice.PRSConfigurationFailure),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_NRPPa_PRSConfigurationFailure,
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
		"PRSConfigurationFailure"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_UnsuccessfulOutcome__value, choice.MeasurementPreconfigurationRefuse),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_NRPPa_MeasurementPreconfigurationRefuse,
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
		"MeasurementPreconfigurationRefuse"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_NRPPa_value_tag2el_5[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 0, 0, 7 }, /* E-CIDMeasurementInitiationFailure */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, -1, 6 }, /* OTDOAInformationFailure */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, -2, 5 }, /* PositioningInformationFailure */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 3, -3, 4 }, /* MeasurementFailure */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 4, -4, 3 }, /* TRPInformationFailure */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 5, -5, 2 }, /* PositioningActivationFailure */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 6, -6, 1 }, /* PRSConfigurationFailure */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 7, -7, 0 } /* MeasurementPreconfigurationRefuse */
};
static asn_CHOICE_specifics_t asn_SPC_NRPPa_value_specs_5 = {
	sizeof(struct NRPPa_UnsuccessfulOutcome__value),
	offsetof(struct NRPPa_UnsuccessfulOutcome__value, _asn_ctx),
	offsetof(struct NRPPa_UnsuccessfulOutcome__value, present),
	sizeof(((struct NRPPa_UnsuccessfulOutcome__value *)0)->present),
	asn_MAP_NRPPa_value_tag2el_5,
	8,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_NRPPa_value_5 = {
	"value",
	"value",
	&asn_OP_OPEN_TYPE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		OPEN_TYPE_constraint
	},
	asn_MBR_NRPPa_value_5,
	8,	/* Elements count */
	&asn_SPC_NRPPa_value_specs_5	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_NRPPa_UnsuccessfulOutcome_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_UnsuccessfulOutcome, procedureCode),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_ProcedureCode,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_NRPPa_procedureCode_constr_2,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_NRPPa_procedureCode_constraint_1
		},
		0, 0, /* No default value */
		"procedureCode"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_UnsuccessfulOutcome, criticality),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_Criticality,
		select_UnsuccessfulOutcome_NRPPa_criticality_type,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_NRPPa_criticality_constr_3,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_NRPPa_criticality_constraint_1
		},
		0, 0, /* No default value */
		"criticality"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NRPPa_UnsuccessfulOutcome, nrppatransactionID),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRPPa_NRPPATransactionID,
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
		"nrppatransactionID"
		},
	{ ATF_OPEN_TYPE | ATF_NOFLAGS, 0, offsetof(struct NRPPa_UnsuccessfulOutcome, value),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NRPPa_value_5,
		select_UnsuccessfulOutcome_NRPPa_value_type,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_NRPPa_value_constr_5,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_NRPPa_value_constraint_1
		},
		0, 0, /* No default value */
		"value"
		},
};
static const ber_tlv_tag_t asn_DEF_NRPPa_UnsuccessfulOutcome_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NRPPa_UnsuccessfulOutcome_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* procedureCode */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* criticality */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* nrppatransactionID */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* value */
};
asn_SEQUENCE_specifics_t asn_SPC_NRPPa_UnsuccessfulOutcome_specs_1 = {
	sizeof(struct NRPPa_UnsuccessfulOutcome),
	offsetof(struct NRPPa_UnsuccessfulOutcome, _asn_ctx),
	asn_MAP_NRPPa_UnsuccessfulOutcome_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NRPPa_UnsuccessfulOutcome = {
	"UnsuccessfulOutcome",
	"UnsuccessfulOutcome",
	&asn_OP_SEQUENCE,
	asn_DEF_NRPPa_UnsuccessfulOutcome_tags_1,
	sizeof(asn_DEF_NRPPa_UnsuccessfulOutcome_tags_1)
		/sizeof(asn_DEF_NRPPa_UnsuccessfulOutcome_tags_1[0]), /* 1 */
	asn_DEF_NRPPa_UnsuccessfulOutcome_tags_1,	/* Same as above */
	sizeof(asn_DEF_NRPPa_UnsuccessfulOutcome_tags_1)
		/sizeof(asn_DEF_NRPPa_UnsuccessfulOutcome_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NRPPa_UnsuccessfulOutcome_1,
	4,	/* Elements count */
	&asn_SPC_NRPPa_UnsuccessfulOutcome_specs_1	/* Additional specs */
};

