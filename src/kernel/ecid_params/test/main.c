#include "ecid-params.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

int
main()
{
	/*Variables*/
	int fd, i, j;
	ResultSS_RSRP_Item_t ss_rsrp[maxCellReport] = {0};
	ResultSS_RSRQ_Item_t ss_rsrq[maxCellReport] = {0};
        ResultCSI_RSRP_Item_t csi_rsrp[maxCellReport] = {0};
        ResultCSI_RSRQ_Item_t csi_rsrq[maxCellReport] = {0};
        UL_AoA_t ul_aoa = {0};
        NR_TADV_t tadv = 0;
        UE_Rx_Tx_Time_Diff_t txrx = 0;

#ifdef DEBUG
	/*Open target device file*/
	if((fd = open("/dev/5g/ss_rsrp", O_RDONLY)) < 0)
	{
		perror("open");
		return 1;
	}

	/*
	 * Read random data from target device
	 *
	 * 1) SS-RSRP
	 * 2) SS-RSRQ
	 * 3) CSI-RSRP
	 * 4) CSI-RSRQ
	 * 5) NR UL AoA
	 * 6) NR Tadv
	 * 7) UE TxRx difference
	 */
	if(read(fd, ss_rsrp, sizeof(ss_rsrp)) != sizeof(ss_rsrp))
	{
		perror("read");
		close(fd);
		return 1;
	}

	/*Debug output of received values*/
	for(i = 0; i < maxCellReport; i++)
	{
		printf("Sample[%d]: SS-RSRP Cell value %ld\n", i+1, ss_rsrp[i].valueSS_RSRP_Cell);

		for(j = 0; j < maxIndexesReport; j++)
		{
			printf("Sample[%d].SSB[%d]: SS-RSRP SSB Idx %ld, SSB RSRP value %ld\n", i+1, j+1, ss_rsrp[i].sS_RSRP_PerSSB[j].sSB_Index, ss_rsrp[i].sS_RSRP_PerSSB[j].valueSS_RSRP);
		}
	}

	close(fd);

	/*Open target device file: SS-RSRQ*/
        if((fd = open("/dev/5g/ss_rsrq", O_RDONLY)) < 0)
        {
                perror("open");
                return 1;
        }

	if(read(fd, ss_rsrq, sizeof(ss_rsrq)) != sizeof(ss_rsrq))
        {
                perror("read SS-RSRQ");
                close(fd);
                return 1;
        }

        /*Debug output of received values*/
        for(i = 0; i < maxCellReport; i++)
        {
                printf("Sample[%d]: SS-RSRQ Cell value %ld\n", i+1, ss_rsrq[i].valueSS_RSRQ_Cell);

                for(j = 0; j < maxIndexesReport; j++)
                {
                        printf("Sample[%d].SSB[%d]: SS-RSRQ SSB Idx %ld, SSB RSRQ value %ld\n", i+1, j+1, ss_rsrq[i].sS_RSRQ_PerSSB[j].sSB_Index, ss_rsrq[i].sS_RSRQ_PerSSB[j].valueSS_RSRQ);
                }
        }

        close(fd);

	/*Open target device file: CSI RSRP*/
        if((fd = open("/dev/5g/csi_rsrp", O_RDONLY)) < 0)
        {
                perror("open");
                return 1;
        }

	if(read(fd, csi_rsrp, sizeof(csi_rsrp)) != sizeof(csi_rsrp))
        {
                perror("read CSI-RSRP");
                close(fd);
                return 1;
        }

        /*Debug output of received values*/
        for(i = 0; i < maxCellReport; i++)
        {
                printf("Sample[%d]: CSI-RSRP Cell value %ld\n", i+1, csi_rsrp[i].valueCSI_RSRP_Cell);

                for(j = 0; j < maxIndexesReport; j++)
                {
                        printf("Sample[%d].RS[%d]: CSI-RSRP RS Idx %ld, RS RSRP value %ld\n", i+1, j+1, csi_rsrp[i].cSI_RSRP_PerCSI_RS[j].cSI_RS_Index, csi_rsrp[i].cSI_RSRP_PerCSI_RS[j].valueCSI_RSRP);
                }
        }

        close(fd);
#endif

	/*Open target device file: CSI RSRQ*/
        if((fd = open("/dev/5g/csi_rsrq", O_RDONLY)) < 0)
        {
                perror("open");
                return 1;
        }

        if(read(fd, csi_rsrq, sizeof(csi_rsrq)) != sizeof(csi_rsrq))
        {
                perror("read CSI-RSRQ");
                close(fd);
                return 1;
        }

        /*Debug output of received values*/
        for(i = 0; i < maxCellReport; i++)
        {
                printf("Sample[%d]: CSI-RSRQ Cell value %ld\n", i+1, csi_rsrq[i].valueCSI_RSRQ_Cell);

                for(j = 0; j < maxIndexesReport; j++)
                {
                        printf("Sample[%d].RS[%d]: CSI-RSRQ RS Idx %ld, RS RSRQ value %ld\n", i+1, j+1, csi_rsrq[i].cSI_RSRQ_PerCSI_RS[j].cSI_RS_Index, csi_rsrq[i].cSI_RSRQ_PerCSI_RS[j].valueCSI_RSRQ);
                }
        }

        close(fd);

	/*Open target device file: NR UL AoA*/
        if((fd = open("/dev/5g/ul_aoa_nr", O_RDONLY)) < 0)
        {
                perror("open");
                return 1;
        }

	if(read(fd, &ul_aoa, sizeof(ul_aoa)) != sizeof(ul_aoa))
        {
                perror("read UL AoA NR");
                close(fd);
                return 1;
        }
	printf("UL AoA: Azimuth %ld, Zenith %ld, Alpha %ld, Beta %ld, Gamma %ld\n", ul_aoa.azimuthAoA, ul_aoa.zenithAoA, ul_aoa.lCS_to_GCS_Translation.alpha, ul_aoa.lCS_to_GCS_Translation.beta, ul_aoa.lCS_to_GCS_Translation.gamma);

	close(fd);

	/*Open target device file: NR Tadv*/
        if((fd = open("/dev/5g/tadv_nr", O_RDONLY)) < 0)
        {
                perror("open");
                return 1;
        }

        if(read(fd, &tadv, sizeof(tadv)) != sizeof(tadv))
        {
                perror("read NR Tadv");
                close(fd);
                return 1;
        }
        printf("Tadv NR: %ld\n", tadv);

        close(fd);

	/*Open target device file: UE TX RX difference*/
        if((fd = open("/dev/5g/ue_txrx_diff", O_RDONLY)) < 0)
        {
                perror("open");
                return 1;
        }

        if(read(fd, &txrx, sizeof(txrx)) != sizeof(txrx))
        {
                perror("read UE Tx Rx difference");
                close(fd);
                return 1;
        }
        printf("UE TX RX Time difference: %ld\n", txrx);

        close(fd);

	return 0;
}
