/**
 * E-CID Measurement random value generator
 * ----------------------------------------------------------------------------
 * This kernel module creates different character device files from which
 * an application can read random measurement values, e.g. SS-RSRP or SS-RSRQ.
 * ----------------------------------------------------------------------------
 * created on: 07/07/2024, NK
 * last modified: 07/22/2024, NK
 */

#include "ecid-params.h"

static dev_t num_dev;
static struct cdev *drv;
static struct class *drv_cl;
static char *devname[] = {CDEV_NAME_SS_RSRP, CDEV_NAME_SS_RSRQ, CDEV_NAME_CSI_RSRP, CDEV_NAME_CSI_RSRQ, CDEV_NAME_AOA_NR, CDEV_NAME_TADV_NR, CDEV_NAME_UE_TXRX};

/**
 * ecid_open - callback function when open(2) is called.
 */
int
ecid_open(struct inode *in, struct file *f)
{
	/*Only allow device file to be opened for reading*/
	if((f->f_flags & O_ACCMODE) == O_WRONLY || (f->f_flags & O_ACCMODE) == O_RDWR)
	{
		return -EINVAL;
	}

	return 0;
}

/**
 * ecid_close - callback function when close(2) is called.
 */
int
ecid_close(struct inode *in, struct file *f)
{
	return 0;
}

/**
 * ecid_read - callback function when reading from device file
 */
ssize_t
ecid_read(struct file* f, char __user *usr, size_t count, loff_t *off)
{
	/*Variables*/
	ResultSS_RSRP_Item_t *ss_rsrp = 0;
	ResultSS_RSRQ_Item_t *ss_rsrq = 0;
	ResultCSI_RSRP_Item_t *csi_rsrp = 0;
	ResultCSI_RSRQ_Item_t *csi_rsrq = 0;
	UL_AoA_t ul_aoa = {0};
	NR_TADV_t tadv = 0;
	UE_Rx_Tx_Time_Diff_t txrx = 0;
	size_t num = 0;
	int i, j;
	bool isHeap = false;
	char *ptr = 0;
	unsigned long not_cpy = 0, cpy = 0;

#ifdef DEBUG
	printk(KERN_INFO "[ecid_params] Reading from device file %s with minor number %d", devname[iminor(f->f_inode)], iminor(f->f_inode));
#endif

	/*If no byte were requested, return 0 byte :-)*/
	if(!count)
	{
		return 0;
	}

	/*
	 * Initialize target data structure(s)
	 *
	 * 1) Check Minor number -> type of requested data
	 * 2) Generate random bytes for target struct members via get_random_bytes() (see: drivers/char/random.c).
	 * 3) Write initialized data structure to userspace via copy_to_user()
	 * 4) return number of written bytes.
	 */

	switch(iminor(f->f_inode))
	{
		/*SS-RSRP*/
		case 0:
			/*
			 * Check requested number of elements:
			 *
			 * (1) If @count is not a multiple of the target data structure: error EINVAL
			 * (2) If @count / sizeof(data_structure) is zero: return 0.
			 * (3) If @count is larger than the 3GPP defined limit of items: Set to the maximum number of allowed items.
			 */
			if(count % sizeof(ResultSS_RSRP_Item_t) != 0)
			{
				return -EINVAL;
			}

			num = count / sizeof(ResultSS_RSRP_Item_t);
			if(!num)
			{
				return 0;
			}
			else if(num > maxCellReport)
			{
				num = maxCellReport;
			}

			/*Allocate memory on heap*/
			if((ss_rsrp = kcalloc(num, sizeof(ResultSS_RSRP_Item_t), GFP_USER)) == NULL)
			{
				return -ENOMEM;
			}
			isHeap = true;

			/*
			 * Generate random item data
			 *
			 * (1) SS-RSRP Cell value (0 - 127)
			 * (2) SS-RSRP per SSB resource (SSB Index, SS-RSRP value per SSB)
			 */
			for(i = 0; i < num; i++)
			{
				RANDOM_VALUE_GEN(ss_rsrp[i].valueSS_RSRP_Cell, 128)
#ifdef DEBUG
				printk(KERN_INFO "Sample[%d]: SS-RSRP Cell value %ld\n", i+1, ss_rsrp[i].valueSS_RSRP_Cell);
#endif
				for(j = 0; j < maxIndexesReport; j++)
				{
					RANDOM_VALUE_GEN(ss_rsrp[i].sS_RSRP_PerSSB[j].sSB_Index, 64)
					RANDOM_VALUE_GEN(ss_rsrp[i].sS_RSRP_PerSSB[j].valueSS_RSRP, 128)
#ifdef DEBUG
					printk(KERN_INFO "Sample[%d].SSB[%d]: SS-RSRP SSB Idx %ld, SSB RSRP value %ld\n", i+1, j+1, ss_rsrp[i].sS_RSRP_PerSSB[j].sSB_Index, ss_rsrp[i].sS_RSRP_PerSSB[j].valueSS_RSRP);
#endif
				}

				ss_rsrp[i].num = maxIndexesReport;
			}

			/*Set pointer to target buffer*/
			cpy = num * sizeof(ResultSS_RSRP_Item_t);
			ptr = (char*) ss_rsrp;
			break;

		/*SS-RSRQ*/
		case 1:
			/*
			 * Check requested number of elements:
			 *
			 * (1) If @count is not a multiple of the target data structure: error EINVAL
			 * (2) If @count / sizeof(data_structure) is zero: return 0.
			 * (3) If @count is larger than the 3GPP defined limit of items: Set to the maximum number of allowed items.
			 */
			if(count % sizeof(ResultSS_RSRQ_Item_t) != 0)
			{
				return -EINVAL;
			}

			num = count / sizeof(ResultSS_RSRQ_Item_t);
			if(!num)
			{
				return 0;
			}
			else if(num > maxCellReport)
			{
				num = maxCellReport;
			}

			/*Allocate memory on heap*/
			if((ss_rsrq = kcalloc(num, sizeof(ResultSS_RSRQ_Item_t), GFP_USER)) == NULL)
			{
				return -ENOMEM;
			}
			isHeap = true;

			/*
			 * Generate random item data
			 *
			 * (1) SS-RSRQ Cell value (0 - 127)
			 * (2) SS-RSRQ per SSB resource (SSB Index, SS-RSRQ value per SSB)
			 */
			for(i = 0; i < num; i++)
			{
				RANDOM_VALUE_GEN(ss_rsrq[i].valueSS_RSRQ_Cell, 128)
#ifdef DEBUG
				printk(KERN_INFO "Sample[%d]: SS-RSRQ Cell value %ld\n", i+1, ss_rsrq[i].valueSS_RSRQ_Cell);
#endif
				for(j = 0; j < maxIndexesReport; j++)
				{
					RANDOM_VALUE_GEN(ss_rsrq[i].sS_RSRQ_PerSSB[j].sSB_Index, 64)
					RANDOM_VALUE_GEN(ss_rsrq[i].sS_RSRQ_PerSSB[j].valueSS_RSRQ, 128)
#ifdef DEBUG
					printk(KERN_INFO "Sample[%d].SSB[%d]: SS-RSRQ SSB Idx %ld, SSB RSRQ value %ld\n", i+1, j+1, ss_rsrq[i].sS_RSRQ_PerSSB[j].sSB_Index, ss_rsrq[i].sS_RSRQ_PerSSB[j].valueSS_RSRQ);
#endif
				}

				ss_rsrq[i].num = maxIndexesReport;
			}

			/*Set pointer to target buffer*/
			cpy = num * sizeof(ResultSS_RSRQ_Item_t);
			ptr = (char*) ss_rsrq;
			break;

		/*CSI-RSRP*/
		case 2:
			/*
			 * Check requested number of elements:
			 *
			 * (1) If @count is not a multiple of the target data structure: error EINVAL
			 * (2) If @count / sizeof(data_structure) is zero: return 0.
			 * (3) If @count is larger than the 3GPP defined limit of items: Set to the maximum number of allowed items.
			 */
			if(count % sizeof(ResultCSI_RSRP_Item_t) != 0)
			{
				return -EINVAL;
			}

			num = count / sizeof(ResultCSI_RSRP_Item_t);
			if(!num)
			{
				return 0;
			}
			else if(num > maxCellReport)
			{
				num = maxCellReport;
			}

			/*Allocate memory on heap*/
			if((csi_rsrp = kcalloc(num, sizeof(ResultCSI_RSRP_Item_t), GFP_USER)) == NULL)
			{
				return -ENOMEM;
			}
			isHeap = true;

			/*
			 * Generate random item data
			 *
			 * (1) CSI-RSRP Cell value (0 - 127)
			 * (2) CSI-RSRP per CSI-RS resource (RS Index, CSI-RSRP value per RS)
			 */
			for(i = 0; i < num; i++)
			{
				RANDOM_VALUE_GEN(csi_rsrp[i].valueCSI_RSRP_Cell, 128)
#ifdef DEBUG
				printk(KERN_INFO "Sample[%d]: CSI-RSRP Cell value %ld\n", i+1, csi_rsrp[i].valueCSI_RSRP_Cell);
#endif
				for(j = 0; j < maxIndexesReport; j++)
				{
					RANDOM_VALUE_GEN(csi_rsrp[i].cSI_RSRP_PerCSI_RS[j].cSI_RS_Index, 96)
					RANDOM_VALUE_GEN(csi_rsrp[i].cSI_RSRP_PerCSI_RS[j].valueCSI_RSRP, 128)
#ifdef DEBUG
					printk(KERN_INFO "Sample[%d].RS[%d]: CSI-RSRP RS Idx %ld, RS RSRP value %ld\n", i+1, j+1, csi_rsrp[i].cSI_RSRP_PerCSI_RS[j].cSI_RS_Index, csi_rsrp[i].cSI_RSRP_PerCSI_RS[j].valueCSI_RSRP);
#endif
				}

				csi_rsrp[i].num = maxIndexesReport;
			}

			/*Set pointer to target buffer*/
			cpy = num * sizeof(ResultCSI_RSRP_Item_t);
			ptr = (char*) csi_rsrp;
			break;

		/*CSI-RSRQ*/
		case 3:
			/*
			 * Check requested number of elements:
			 *
			 * (1) If @count is not a multiple of the target data structure: error EINVAL
			 * (2) If @count / sizeof(data_structure) is zero: return 0.
			 * (3) If @count is larger than the 3GPP defined limit of items: Set to the maximum number of allowed items.
			 */
			if(count % sizeof(ResultCSI_RSRQ_Item_t) != 0)
			{
				return -EINVAL;
			}

			num = count / sizeof(ResultCSI_RSRQ_Item_t);
			if(!num)
			{
				return 0;
			}
			else if(num > maxCellReport)
			{
				num = maxCellReport;
			}

			/*Allocate memory on heap*/
			if((csi_rsrq = kcalloc(num, sizeof(ResultCSI_RSRQ_Item_t), GFP_USER)) == NULL)
			{
				return -ENOMEM;
			}
			isHeap = true;

			/*
			 * Generate random item data
			 *
			 * (1) CSI-RSRP Cell value (0 - 127)
			 * (2) CSI-RSRP per CSI-RS resource (RS Index, CSI-RSRP value per RS)
			 */
			for(i = 0; i < num; i++)
			{
				RANDOM_VALUE_GEN(csi_rsrq[i].valueCSI_RSRQ_Cell, 128)
#ifdef DEBUG
				printk(KERN_INFO "Sample[%d]: CSI-RSRQ Cell value %ld\n", i+1, csi_rsrq[i].valueCSI_RSRQ_Cell);
#endif
				for(j = 0; j < maxIndexesReport; j++)
				{
					RANDOM_VALUE_GEN(csi_rsrq[i].cSI_RSRQ_PerCSI_RS[j].cSI_RS_Index, 96)
					RANDOM_VALUE_GEN(csi_rsrq[i].cSI_RSRQ_PerCSI_RS[j].valueCSI_RSRQ, 128)
#ifdef DEBUG
					printk(KERN_INFO "Sample[%d].RS[%d]: CSI-RSRQ RS Idx %ld, RS RSRP value %ld\n", i+1, j+1, csi_rsrq[i].cSI_RSRQ_PerCSI_RS[j].cSI_RS_Index, csi_rsrq[i].cSI_RSRQ_PerCSI_RS[j].valueCSI_RSRQ);
#endif
				}

				csi_rsrq[i].num = maxIndexesReport;
			}

			/*Set pointer to target buffer*/
			cpy = num * sizeof(ResultCSI_RSRQ_Item_t);
			ptr = (char*) csi_rsrq;
			break;

		/*NR UL AoA*/
		case 4:
			if(count != sizeof(UL_AoA_t))
			{
				return -EINVAL;
			}

			/*
			 * Generate random item data
			 */
			RANDOM_VALUE_GEN(ul_aoa.azimuthAoA, 3600);
			RANDOM_VALUE_GEN(ul_aoa.zenithAoA, 1800);
			RANDOM_VALUE_GEN(ul_aoa.lCS_to_GCS_Translation.alpha, 3600);
			RANDOM_VALUE_GEN(ul_aoa.lCS_to_GCS_Translation.beta, 3600);
			RANDOM_VALUE_GEN(ul_aoa.lCS_to_GCS_Translation.gamma, 3600);
#ifdef DEBUG
			printk(KERN_INFO "UL AoA: Azimuth %ld, Zenith %ld, Alpha %ld, Beta %ld, Gamma %ld\n", ul_aoa.azimuthAoA, ul_aoa.zenithAoA, ul_aoa.lCS_to_GCS_Translation.alpha, ul_aoa.lCS_to_GCS_Translation.beta, ul_aoa.lCS_to_GCS_Translation.gamma);
#endif
			/*Set pointer to target buffer*/
			cpy = sizeof(UL_AoA_t);
			ptr = (char*) &ul_aoa;
			break;

		/*NR Tadv*/
		case 5:
			if(count != sizeof(NR_TADV_t))
			{
				return -EINVAL;
			}

			/*Generate random data*/
			RANDOM_VALUE_GEN(tadv, 7691)
#ifdef DEBUG
			printk(KERN_INFO "Tadv NR: %ld\n", tadv);
#endif
			/*Set pointer to target buffer*/
			cpy = sizeof(NR_TADV_t);
			ptr = (char*) &tadv;

			break;

		/*UE TxRx time difference*/
		case 6:
			if(count != sizeof(UE_Rx_Tx_Time_Diff_t))
			{
				return -EINVAL;
			}

			/*Generate random data*/
			RANDOM_VALUE_GEN(txrx, 61566)
#ifdef DEBUG
			printk(KERN_INFO "UE Tx Rx: %ld\n", txrx);
#endif
			/*Set pointer to target buffer*/
			cpy = sizeof(UE_Rx_Tx_Time_Diff_t);
			ptr = (char*) &txrx;
			break;

		default:
			return 0;
	}

	/*Copy generated data to target user space application*/
	not_cpy = copy_to_user(usr, ptr, cpy);

	/*If not all data were copy: Loop until request is completely satisfied*/
	while(not_cpy)
	{
		not_cpy = copy_to_user(usr + cpy + not_cpy, ptr + cpy + not_cpy, not_cpy);
	}

	/*Free allocated memory*/
	if(isHeap)
	{
		kfree(ptr);
	}

	return cpy;
}

/**
 * Set driver entry points for IO operations from user space
 */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = ecid_open,
    .read = ecid_read,
    .release = ecid_close
};

/**
 * ecid_init - entry point of kernel module
 */
static int __init
ecid_init(void)
{
	int i, j;

	/*Reserve Major and Minor numbers for the device driver*/
	if(alloc_chrdev_region(&num_dev, 0, 7, "5g_ecid_params") < 0)
	{
		return -1;
	}

	/*Allocate memory for device driver object (cdev)*/
	if((drv = cdev_alloc()) == NULL)
	{
		goto dev_num;
	}

	/*Initialize driver object*/
	drv->owner = THIS_MODULE;
	drv->ops = &fops;

	/*Notify kernel that a new char device was created*/
	if(cdev_add(drv, num_dev, 7) < 0)
	{
		goto cdev;
	}

	/*Create a corresponding class in sysfs*/
	if((drv_cl = class_create(CDEV_CLASS_MAIN)) == NULL)
	{
		goto cdev;
	}

	/*Create character device files*/
	for(i = 0; i < 7; i++)
	{
		INIT_DEVFILE(drv_cl, num_dev, i, devname[i])
	}

	return 0;

cls:
	for(j = 0; j < i; j++)
	{
		device_destroy(drv_cl, MKDEV(num_dev, j));
	}
	class_destroy(drv_cl);

cdev:
	cdev_del(drv);

dev_num:
	unregister_chrdev_region(num_dev, 7);

	return -EIO;
}

/**
 * ecid_exit - callback function that is executed when this module
 * is removed from the kernel, e.g. by using rmmod(1).
 */
static void __exit
ecid_exit(void)
{
	int i;

	for(i = 0; i < 7; i++)
	{
		device_destroy(drv_cl, MKDEV(MAJOR(num_dev), MINOR(num_dev+i)));
	}

	cdev_del(drv);
	class_destroy(drv_cl);
	unregister_chrdev_region(num_dev, 7);

	return;
}

/**
 * Set up the kernel module entry points
 */
module_init(ecid_init);
module_exit(ecid_exit);

/**
 * Meta information
 */
MODULE_AUTHOR("Nico Kalis");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("5G NRPPa E-CID Measurement value generator");
