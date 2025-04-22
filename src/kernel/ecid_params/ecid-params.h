#ifndef _ECID_PARAMS_H_
#define _ECID_PARAMS_H_

#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/random.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/device/class.h>
#include <asm/uaccess.h>

#define CDEV_CLASS_MAIN "nr_ecid"

/**
 * NRPPa specific stuff (taken from ASN.1 specification in 3GPP TS 38.455)
 *
 * NOTE: Used data structures were modified. Pointer were removed ("direct struct")
 * 	 and OCTET/BIT STRING where replaced by uint8_t arrays of known size.
 *	 Members of a struct that does not contain measurement data were removed.
 */
#define maxIndexesReport (64)
#define maxCellReport (9)

/*(1) NRPPa_ResultSS-RSRP-Item */
typedef long	 ValueRSRP_NR_t;
typedef long	 SSB_Index_t;
typedef long	 ValueRSRQ_NR_t;

typedef struct ResultSS_RSRP_PerSSB_Item {
	SSB_Index_t	 sSB_Index; /*range: 0 - 63*/
	ValueRSRP_NR_t	 valueSS_RSRP; /*range: 0 - 127*/
} ResultSS_RSRP_PerSSB_Item_t;

typedef struct ResultSS_RSRP_Item
{
	ValueRSRP_NR_t	valueSS_RSRP_Cell; /*range: 0 - 127*/
	struct ResultSS_RSRP_PerSSB_Item	sS_RSRP_PerSSB[maxIndexesReport];
	uint8_t num;
} ResultSS_RSRP_Item_t;

/*(2) NRPPa_ResultSS-RSRQ-Item */
typedef struct ResultSS_RSRQ_PerSSB_Item {
	SSB_Index_t	 sSB_Index; /*range: 0 - 63*/
	ValueRSRQ_NR_t	 valueSS_RSRQ; /*range: 0 - 127*/
} ResultSS_RSRQ_PerSSB_Item_t;

typedef struct NRPPa_ResultSS_RSRQ_Item {
	ValueRSRQ_NR_t valueSS_RSRQ_Cell;	/*range: 0 - 127*/
	struct ResultSS_RSRQ_PerSSB_Item sS_RSRQ_PerSSB[maxIndexesReport];	/* OPTIONAL */
	uint8_t num;
} ResultSS_RSRQ_Item_t;

/*(3) NRPPa_ResultCSI-RSRP-Item*/
typedef struct ResultCSI_RSRP_PerCSI_RS_Item {
	long	 cSI_RS_Index; /*range: 0 - 95*/
	ValueRSRP_NR_t	 valueCSI_RSRP; /*range: 0 - 127*/
} ResultCSI_RSRP_PerCSI_RS_Item_t;

typedef struct ResultCSI_RSRP_Item {
	ValueRSRP_NR_t valueCSI_RSRP_Cell;	/* range: 0 - 127 */
	struct ResultCSI_RSRP_PerCSI_RS_Item cSI_RSRP_PerCSI_RS[maxIndexesReport];	/* OPTIONAL */
	uint8_t num;
} ResultCSI_RSRP_Item_t;

/*(4) NRPPa_ResultCSI-RSRQ-Item */
typedef struct ResultCSI_RSRQ_PerCSI_RS_Item {
	long	 cSI_RS_Index; /*range: 0 - 95*/
	ValueRSRQ_NR_t	 valueCSI_RSRQ; /*range: 0 - 127*/
} ResultCSI_RSRQ_PerCSI_RS_Item_t;

typedef struct NRPPa_ResultCSI_RSRQ_Item {
	ValueRSRQ_NR_t valueCSI_RSRQ_Cell; /*range: 0 - 127*/
	struct ResultCSI_RSRQ_PerCSI_RS_Item cSI_RSRQ_PerCSI_RS[maxIndexesReport];	/* OPTIONAL */
	uint8_t num;
} ResultCSI_RSRQ_Item_t;

/*(5) NRPPa_UL-AoA */
typedef struct LCS_to_GCS_Translation { /*each member's range: 0 - 3599*/
	long	alpha;
	long	beta;
	long	gamma;
} LCS_to_GCS_Translation_t;

typedef struct UL_AoA
{
	long	azimuthAoA;	/*range: 0 - 3599*/
	long	zenithAoA;	/*range: 0 - 1799*/
	struct LCS_to_GCS_Translation	lCS_to_GCS_Translation;	/* OPTIONAL */
} UL_AoA_t;

/*(6) NRPPa_NR-TADV*/
typedef long     NR_TADV_t; /*range: 0 - 7690*/

/*(7) NRPPa_UE-Rx-Tx-Time-Diff*/
typedef long	 UE_Rx_Tx_Time_Diff_t; /*range: 0 - 61565*/

/**
 * Character device file names for each E-CID measurement value
 *
 * location in VFS: /dev/5g
 */
#define CDEV_NAME_SS_RSRP "ss_rsrp"
#define CDEV_NAME_SS_RSRQ "ss_rsrq"
#define CDEV_NAME_CSI_RSRP "csi_rsrp"
#define CDEV_NAME_CSI_RSRQ "csi_rsrq"
#define CDEV_NAME_AOA_NR "ul_aoa_nr"
#define CDEV_NAME_TADV_NR "tadv_nr"
#define CDEV_NAME_UE_TXRX "ue_txrx_diff"

#define INIT_DEVFILE(cl, num, idx, name)\
{\
	if(device_create(cl, NULL, MKDEV(MAJOR(num), MINOR(num)+idx), NULL, "5g/%s", name) == NULL) \
	{\
		goto cls; \
	}\
}

/*
 * RANDOM_VALUE_GEN - generate a random value in a specific range
 *
 * @item: variable (no pointer!) for which the random value is generated.
 * @mod: modulo value, e.g. is a range of 0 - 127 selected, @mod has to be 128.
 */
#define RANDOM_VALUE_GEN(item, mod)\
{\
	get_random_bytes(&item, sizeof(item));\
	if(item < 0) \
	{ \
		item = -item; \
	} \
\
	item %= mod; \
}

#endif
