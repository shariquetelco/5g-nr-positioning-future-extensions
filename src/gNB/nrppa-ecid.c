#include "nrppa-ecid.h"

/*
 * getRANUEMeasurementID - check if a RAN UE Measurement ID is already reserved for a given LMF UE Measurement ID
 *
 * @lmf_ue: pointer to the given LMF UE Measurement ID
 *
 * return: @lmf_ue on success, -1 otherwise
 *
 * NOTE: The LMF UE Measurement ID is unique. Therefore, it can be used as field access identifier.
 */
static NRPPa_UE_Measurement_ID_t
getRANUEMeasurementID(NRPPa_UE_Measurement_ID_t *lmf_ue)
{
	if(!lmf_ue || *lmf_ue < 1 || *lmf_ue > 256)
	{
		return -1;
	}

	/*Lock global RAN list*/
	if(sem_wait(&ran_list->lock) != 0)
	{
		perror("sem_wait");
		return -1;
	}

	/*If RAN UE ID currently not exist: Create entry*/
	if(ran_list->list[(*lmf_ue)-1] == 0)
	{
		ran_list->list[(*lmf_ue)-1] = 1;
		ran_list->cnt++;
	}

	/*Unlock global RAN list*/
	sem_post(&ran_list->lock);

	return *lmf_ue;
}

static bool
removeRANUEMeasurementID(NRPPa_UE_Measurement_ID_t *lmf_ue)
{
	if(!lmf_ue || *lmf_ue < 1 || *lmf_ue > 256)
	{
		return false;
	}

	/*Lock global RAN list*/
	if(sem_wait(&ran_list->lock) != 0)
	{
		perror("sem_wait");
		return false;
	}

	/*If RAN UE ID exist: Remove entry*/
	if(ran_list->list[(*lmf_ue)-1] != 0)
	{
		ran_list->list[(*lmf_ue)-1] = 0;
		ran_list->cnt--;
	}

	/*Unlock global RAN list*/
	sem_post(&ran_list->lock);

	return true;
}

/*
 * createECIDMeasurementResult - create an intialized E-CID Measurement Result data structure based on requested measurement quantities
 *
 * @mqlist: list of requested measurement quantities (via NRPPa E-CID Measurement Initiation Request message)
 * @num: no. of elements in @mqlist
 *
 * return: E-CID Measurement Result data structure on success, null pointer otherwise
 */
static NRPPa_E_CID_MeasurementResult_t*
createECIDMeasurementResult(NRPPa_MeasurementQuantitiesValue_t *mqlist, int cnt)
{
	/*Variables*/
	int i, j, k;
	NRPPa_E_CID_MeasurementResult_t *ecid = 0;

	/*Allocate memory for E-CID measurement result IE*/
	if((ecid = calloc(1, sizeof(NRPPa_E_CID_MeasurementResult_t))) == NULL || (ecid->servingCell_ID.pLMN_Identity.buf = calloc(3, sizeof(uint8_t))) == NULL || (ecid->servingCell_ID.nG_RANcell.choice.nR_CellID.buf = calloc(5, sizeof(uint8_t))) == NULL
		|| (ecid->servingCellTAC.buf = calloc(3, sizeof(uint8_t))) == NULL || (ecid->measuredResults = calloc(1, sizeof(NRPPa_MeasuredResults_t))) == NULL)
	{
		if(ecid)
		{
			if(ecid->servingCell_ID.pLMN_Identity.buf)
			{
				free(ecid->servingCell_ID.pLMN_Identity.buf);
			}

			if(ecid->servingCell_ID.nG_RANcell.choice.nR_CellID.buf)
			{
				free(ecid->servingCell_ID.nG_RANcell.choice.nR_CellID.buf);
			}

			if(ecid->servingCellTAC.buf)
			{
				free(ecid->servingCellTAC.buf);
			}
			free(ecid);
			ecid = 0;
		}
		return NULL;
	}

	/*
	 * Add gNB related information
	 *
	 * PLMN, NR Cell ID, TAC are taken from global gNB data structure: @gnb
	 */
	ecid->servingCell_ID.pLMN_Identity.size = 3;
	memcpy(ecid->servingCell_ID.pLMN_Identity.buf, gnb->plmn, 3);

	ecid->servingCell_ID.nG_RANcell.present = NRPPa_NG_RANCell_PR_nR_CellID;
	ecid->servingCell_ID.nG_RANcell.choice.nR_CellID.size = 5;
	ecid->servingCell_ID.nG_RANcell.choice.nR_CellID.bits_unused = 4;
	memcpy(ecid->servingCell_ID.nG_RANcell.choice.nR_CellID.buf, gnb->nr_cell_id, 5);

	ecid->servingCellTAC.size = 3;
	memcpy(ecid->servingCellTAC.buf, gnb->tac, 3);

	if((ecid->measuredResults->list.array = calloc(cnt, sizeof(NRPPa_MeasuredResultsValue_t*))) == NULL)
	{
		free(ecid->servingCell_ID.pLMN_Identity.buf);
		free(ecid->servingCell_ID.nG_RANcell.choice.nR_CellID.buf);
		free(ecid->servingCellTAC.buf);
		free(ecid->measuredResults);
		free(ecid);
		ecid = 0;
		return NULL;
	}
	ecid->measuredResults->list.size = cnt;

	for(i = 0; i < cnt; i++)
	{
		switch(mqlist[i])
		{
			/*SS-RSRP*/
			case NRPPa_MeasurementQuantitiesValue_sS_RSRP:

				/*Data buffer for reading from file*/
				ResultSS_RSRP_Item_t ss_rsrp[maxCellReport] = {0};

				/*Open target device file*/
				if(ecid_fd[NRPPa_MeasurementQuantitiesValue_sS_RSRP - NRPPa_MeasurementQuantitiesValue_sS_RSRP] < 0)
				{
					continue;
				}

				/*Get emulated SS-RSRP item list from the kernel driver*/
				if(read(ecid_fd[NRPPa_MeasurementQuantitiesValue_sS_RSRP - NRPPa_MeasurementQuantitiesValue_sS_RSRP], ss_rsrp, sizeof(ss_rsrp)) != sizeof(ss_rsrp))
				{
					perror("[gNB] read()");
					continue;
				}

				/*Allocate memory*/
				if((ecid->measuredResults->list.array[i] = calloc(1, sizeof(NRPPa_MeasuredResultsValue_t))) == NULL)
				{
					continue;
				}

				ecid->measuredResults->list.array[i]->present = NRPPa_MeasuredResultsValue_PR_choice_Extension;
				if((ecid->measuredResults->list.array[i]->choice.choice_Extension = calloc(1, sizeof(NRPPa_MeasuredResultsValue_ExtensionIE_t))) == NULL)
				{
					free(ecid->measuredResults->list.array[i]);
					ecid->measuredResults->list.array[i] = 0;
					continue;
				}

				ecid->measuredResults->list.array[i]->choice.choice_Extension->id = NRPPa_ProtocolIE_ID_id_ResultSS_RSRP;
				ecid->measuredResults->list.array[i]->choice.choice_Extension->criticality = NRPPa_Criticality_ignore;
				ecid->measuredResults->list.array[i]->choice.choice_Extension->value.present = NRPPa_MeasuredResultsValue_ExtensionIE__value_PR_ResultSS_RSRP;
				if((ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array = calloc(NRPPa_maxCellReport, sizeof(NRPPa_ResultSS_RSRP_Item_t*))) == NULL) /*here: always the maximum of items is generated*/
				{
					free(ecid->measuredResults->list.array[i]->choice.choice_Extension);
					free(ecid->measuredResults->list.array[i]);
					ecid->measuredResults->list.array[i] = 0;
					continue;
				}		
				ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.size = NRPPa_maxCellReport;

				/*Allocate memory for each list item and copy the obtained item data*/
				for(j = 0; j < NRPPa_maxCellReport; j++)
				{
					if((ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j] = calloc(1, sizeof(NRPPa_ResultSS_RSRP_Item_t))) == NULL)
					{
						j--;
						continue;
					}

					/*PCI, ARFCN, PLMN and NR Cell Identifier*/
					ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->nR_PCI = gnb->pci;
					ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->nR_ARFCN = gnb->arfcn;

					if((ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR = calloc(1, sizeof(NRPPa_CGI_NR_t))) == NULL ||
					   (ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->pLMN_Identity.buf = calloc(3, sizeof(uint8_t))) == NULL ||
					   (ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->nRcellIdentifier.buf = calloc(5, sizeof(uint8_t))) == NULL)
					{
						if(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR)
						{
							free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR);
						}
						if(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->pLMN_Identity.buf)
						{
							free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->pLMN_Identity.buf);
						}
						free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]);
						ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j] = 0;
						j--;
						continue;
					}

					ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->pLMN_Identity.size = 3;
					memcpy(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->pLMN_Identity.buf, gnb->plmn, 3);

					ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->nRcellIdentifier.size = 5;
					ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->nRcellIdentifier.bits_unused = 4;
					memcpy(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->nRcellIdentifier.buf, gnb->nr_cell_id, 5);

					/*Copy emulated data that was obtained from the kernel driver*/
					if((ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->valueSS_RSRP_Cell = calloc(1, sizeof(NRPPa_ValueRSRP_NR_t))) == NULL)
					{
						if(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR)
						{
							free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR);
						}
						if(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->pLMN_Identity.buf)
						{
							free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->pLMN_Identity.buf);
						}
						if(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->nRcellIdentifier.buf)
						{
							free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->nRcellIdentifier.buf);
						}
						free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]);
						ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j] = 0;
						j--;
						continue;
					}

					/*SS-RSRP Cell value*/
					ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->valueSS_RSRP_Cell[0] = ss_rsrp[j].valueSS_RSRP_Cell;

					if((ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->sS_RSRP_PerSSB = calloc(1, sizeof(NRPPa_ResultSS_RSRP_PerSSB_t))) == NULL ||
					   (ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->sS_RSRP_PerSSB->list.array = calloc(maxIndexesReport, sizeof(NRPPa_ResultSS_RSRP_PerSSB_Item_t*))) == NULL)
					{
						if(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR)
						{
							free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR);
						}
						if(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->pLMN_Identity.buf)
						{
							free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->pLMN_Identity.buf);
						}
						if(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->nRcellIdentifier.buf)
						{
							free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->cGI_NR->nRcellIdentifier.buf);
						}
						if(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->valueSS_RSRP_Cell)
						{
							free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->valueSS_RSRP_Cell);
						}
						if(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->sS_RSRP_PerSSB)
						{
							free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->sS_RSRP_PerSSB);
						}
						free(ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]);
						ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j] = 0;
						j--;
						continue;
					}
					ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->sS_RSRP_PerSSB->list.size = maxIndexesReport;

					for(k = 0; k < maxIndexesReport; k++)
					{
						if((ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->sS_RSRP_PerSSB->list.array[k] = calloc(1, sizeof(NRPPa_ResultSS_RSRP_PerSSB_Item_t))) == NULL)
						{
							k--;
							continue;
						}

						/*SS-RSRP SSB index*/
						ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->sS_RSRP_PerSSB->list.array[k]->sSB_Index = ss_rsrp[j].sS_RSRP_PerSSB[k].sSB_Index;

						/*SS-RSRP SSB index value*/
						ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->sS_RSRP_PerSSB->list.array[k]->valueSS_RSRP = ss_rsrp[j].sS_RSRP_PerSSB[k].valueSS_RSRP;

						/*Increase list counter*/
						ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.array[j]->sS_RSRP_PerSSB->list.count++;
					}

					/*Increase list counter*/
					ecid->measuredResults->list.array[i]->choice.choice_Extension->value.choice.ResultSS_RSRP.list.count++;
				}

				break;
	
			/*SS-RSRQ*/
			case NRPPa_MeasurementQuantitiesValue_sS_RSRQ:
				continue; //TODO: Implementation open!
				if(ecid_fd[NRPPa_MeasurementQuantitiesValue_sS_RSRQ - NRPPa_MeasurementQuantitiesValue_sS_RSRP] < 0)
				{
					continue;
				}
				break;

			/*CSI-RSRP*/
			case NRPPa_MeasurementQuantitiesValue_cSI_RSRP:
				continue; //TODO: Implementation open!
				if(ecid_fd[NRPPa_MeasurementQuantitiesValue_cSI_RSRP - NRPPa_MeasurementQuantitiesValue_sS_RSRP] < 0)
				{
					continue;
				}
	
				break;

			/*CSI-RSRQ*/
			case NRPPa_MeasurementQuantitiesValue_cSI_RSRQ:
				continue; //TODO: Implementation open!
				if(ecid_fd[NRPPa_MeasurementQuantitiesValue_cSI_RSRQ - NRPPa_MeasurementQuantitiesValue_sS_RSRP] < 0)
				{
					continue;
				}
				break;

			/*AoA NR*/
			case NRPPa_MeasurementQuantitiesValue_angleOfArrivalNR:
				continue; //TODO: Implementation open!
				if(ecid_fd[NRPPa_MeasurementQuantitiesValue_angleOfArrivalNR - NRPPa_MeasurementQuantitiesValue_sS_RSRP] < 0)
				{
					continue;
				}
				break;

			/*Timing Advance NR*/
			case NRPPa_MeasurementQuantitiesValue_timingAdvanceNR:
				continue; //TODO: Implementation open!
				if(ecid_fd[NRPPa_MeasurementQuantitiesValue_timingAdvanceNR - NRPPa_MeasurementQuantitiesValue_sS_RSRP] < 0)
				{
					continue;
				}
				break;

			/*UE TxRx Time Difference*/
			case NRPPa_MeasurementQuantitiesValue_uE_Rx_Tx_Time_Diff:
				continue; //TODO: Implementation open!
				if(ecid_fd[NRPPa_MeasurementQuantitiesValue_uE_Rx_Tx_Time_Diff - NRPPa_MeasurementQuantitiesValue_sS_RSRP] < 0)
				{
					continue;
				}
				break;

			default:
				continue;

		}

		/*Increase list counter*/
		ecid->measuredResults->list.count++;
	}

	/*Free memory if not entries were inserted*/
	if(!ecid->measuredResults->list.count)
	{
		free(ecid->servingCell_ID.pLMN_Identity.buf);
		free(ecid->servingCell_ID.nG_RANcell.choice.nR_CellID.buf);
		free(ecid->servingCellTAC.buf);
		free(ecid->measuredResults->list.array);
		free(ecid->measuredResults);
		free(ecid);
		ecid = 0;

		return NULL;
	}

	return ecid;
}

/*
 * E_CID_MeasurementReport - periodical NRPPa E-CID Measurement Report message generation
 * --------------------------------------------------------------------------------------------
 * 
 *
 * --------------------------------------------------------------------------------------------
 * compliant with: 3GPP TS 38.455, 8.2.3
 */
static void
E_CID_MeasurementReport(void *data)
{
	/*Variables*/
	nrppamsg_t *nrppa = 0;
	ngapmsg_t *ngap = 0;
	NRPPa_Cause_t cause = {0};
	NRPPa_E_CID_MeasurementResult_t *ecid = 0;
	NRPPa_UE_Measurement_ID_t lmf_ue = 0;
	ecid_report_param_t *param = 0;
	pthpool_data_t *tpinfo = 0;

	/*Check passed LMF UE Measurement ID*/
	if((tpinfo = (pthpool_data_t*) data) == NULL || (param = (ecid_report_param_t*) tpinfo->arg) == NULL || (lmf_ue = param->lmf_ue) <= 0 || lmf_ue > ECID_SESS_MAX)
	{
		goto err;
	}

	/*Get current timestamp*/
	clock_gettime(CLOCK_MONOTONIC, &param->next_period);
#ifndef RESEARCH
	printf("[gNB] -- Starting E-CID Measurement Report message sending for (%ld | %ld) --\n", param->lmf_ue, param->ran_ue);
#endif

	/*
	 * Loop: Sending NRPPa E-CID Measurement Report messaged to the target LMF
	 *
	 * NOTE: Precondition is that the time for creating the response message is smaller than the requested period!
	 */
	while(report_list[param->lmf_ue-1][param->ran_ue-1].isActive)
	{
		/*(1) Get measurement data from kernel*/
		if((ecid = createECIDMeasurementResult(param->mqlist, param->num)) == NULL)
		{
			goto err;
		}

		/*(2) Create NGAP encapsulated NRPPa message (also use LMF UE Measurement ID as NRPPa transaction ID)*/
		if((nrppa = NRPPa_ECID_Measurement_Report(lmf_ue, param->lmf_ue, param->ran_ue, &ecid, NULL)) == NULL)
		{
			if(ecid)
			{
				//TODO: Free memory by using ASN_STRUCT_FREE!
			}
			goto err;
		}

		if((ngap = createNGAPforNRPPaTransport(NGAP_ProcedureCode_id_UplinkUEAssociatedNRPPaTransport, nrppa->enc, nrppa->size, param->ngap_amf, param->ngap_ran, param->nfid)) == NULL)
		{
			free(nrppa->enc);
			free(nrppa);
			nrppa = 0;
			goto err;
		}
		free(nrppa);
		nrppa = 0;

		/*(3) Wait until period ends*/
		param->next_period.tv_nsec += param->period_ns;	/*(3.1) Increment absolute time step by one period*/
		while(param->next_period.tv_nsec >= 1000000000)
		{
			param->next_period.tv_sec++;
			param->next_period.tv_nsec -=1000000000;
		}

		clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &param->next_period, NULL); /*(3.2) Sleep until the end of the period is reached*/

		/*(4) Send created NGAP message to the target AMF*/
		if(sctpcli(amf->sockfd, &amf->con, false, ngap->enc, ngap->size, NULL) != 0)
		{
			freeNGAPMessage(ngap);
			ngap = 0;
			goto err;
		}
		freeNGAPMessage(ngap);
		ngap = 0;
	}
#ifndef RESEARCH
	printf("[gNB] -- Stopping sending of E-CID Measurement Report messages for (%ld | %ld) --\n", param->lmf_ue, param->ran_ue);
#endif

	/*Free RAN UE Measurement ID by marking as unused in global list*/
	removeRANUEMeasurementID(&lmf_ue);

	/*Free E-CID Measurement Report parameter set*/
	free(param->ngap_amf.buf);
	free(param);

	return;

err:
	/*Set cause for termination - if it hasn't been already set*/
	if(!cause.present)
	{
		cause.present = NRPPa_Cause_PR_misc;
		cause.choice.misc = NRPPa_CauseMisc_unspecified;
	}

	/*
	 * A fatal error is occured:
	 * (1) Send NRPPa E-CID Measurement Failure Indication message to LMF
	 * (2) Free RAN UE Measurement ID
	 * (3) Remove entry from global table
	 * (4) Termination of this thread
	 */
	if(!lmf_ue)
	{
		/*TODO: End job here. Normally, an Error Indication message should be generated*/
		return;
	}

	/*Creating response message (also use LMF UE Measurement ID as NRPPa transaction ID)*/
	if((nrppa = NRPPa_ECID_Measurement_Failure_Indication(lmf_ue, param->lmf_ue, param->ran_ue, &cause)) == NULL)
	{
		/*Ending without a response message*/
		goto next;
	}

	if((ngap = createNGAPforNRPPaTransport(NGAP_ProcedureCode_id_UplinkUEAssociatedNRPPaTransport, nrppa->enc, nrppa->size, param->ngap_amf, param->ngap_ran, param->nfid)) == NULL)
	{
		free(nrppa->enc);
		free(nrppa);
		nrppa = 0;

		/*Ending without a response message*/
		goto next;
	}
	free(nrppa);
	nrppa = 0;

	/*Sending ...*/
	sctpcli(amf->sockfd, &amf->con, false, ngap->enc, ngap->size, NULL); /*It doesn't matter if the message was sent ...*/
	freeNGAPMessage(ngap);
	ngap = 0;

next:
	/*Free RAN UE Measurement ID by marking as unused in global list*/
	removeRANUEMeasurementID(&lmf_ue);

	/*Free E-CID Measurement Report parameter*/
	free(param->ngap_amf.buf);
	free(param);

	return;
}

/*
 * E_CID_MeasurementInitiation - parse NRPPa E-CID Measurement Initiation Request message
 * and create a corresponding E-CID Measurement Initiation Request/Failure message.
 * --------------------------------------------------------------------------------------------
 * @nrppa: NRPPa PDU message structure
 * @ngap: corresponding NGAP message from which @nrppa was extracted.
 *
 * return: NRPPa PDU message structure that represents the ASN.1 PER encoded response message
 *		   (only if measurement periodicity = onDemand!), otherwise "empty" NRPPa message
 * --------------------------------------------------------------------------------------------
 * compliant with: 3GPP TS 38.455, 8.2.1
 */
nrppamsg_t*
E_CID_MeasurementInitiation(nrppamsg_t *nrppa, ngapmsg_t *ngap)
{
	/*Variables*/
	int i, j, k;
	nrppamsg_t *resp = 0;
	NRPPa_NRPPATransactionID_t transID = 0;
	NRPPa_UE_Measurement_ID_t lmf_ue = 0, ran_ue = 0, *pass = 0;
	NRPPa_ReportCharacteristics_t rtype = 0;
	NRPPa_MeasurementPeriodicity_t period = -1;
	NRPPa_MeasurementQuantitiesValue_t mqlist[NRPPa_maxNoMeas] = {0};
	NRPPa_OtherRATMeasurementQuantitiesValue_t orat[NRPPa_maxNoMeas] = {0};
	NRPPa_WLANMeasurementQuantitiesValue_t wlan[NRPPa_maxNoMeas] = {0};
	NRPPa_MeasurementPeriodicityNR_AoA_t aoa = 0;

	NRPPa_E_CID_MeasurementResult_t *ecid = 0;
	NRPPa_OtherRATMeasurementResult_t *orat_res = 0;
	NRPPa_WLANMeasurementResult_t *wlan_res = 0;

	NRPPa_Cause_t cause;

	uint8_t cnt[3] = {0}; /*[0] == Measurement Quantities, [1] == ORAT Measurement Quantities, [2] == WLAN Measurement Quantities*/
	bool isAoA = false;
	bool isORAT = false, isWLAN = false, isNRAoA = false;

	ecid_report_param_t *param = 0;

	explicit_bzero(&cause, sizeof(cause));

	/*Check open header fields*/
	if(nrppa->pdu->choice.initiatingMessage->procedureCode != NRPPa_ProcedureCode_id_e_CIDMeasurementInitiation || nrppa->pdu->choice.initiatingMessage->criticality != NRPPa_Criticality_reject)
	{
		return 0;
	}

	/*
	 * Store the sent NRPPa Transaction ID
	 *
	 * According to 3GPP TS 38.455, 9.2.4:
	 *
	 * (1) Messages belonging to the same procedure shall use the same NRPPa Transaction ID.
	 * (2) The NRPPa Transaction ID is determined by the initiating peer of a procedure.
	 * (3) The NRPPa Transaction ID shall uniquely identify a procedure among all ongoing parallel procedures
	 * 	   using the same procedure code, and initiated by the same protocol peer.
	 */
	transID = nrppa->pdu->choice.initiatingMessage->nrppatransactionID;

	/*
	 * Iterate through included container IEs (at least 3 IEs are expected)
	 */
	if(!nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array
	|| !nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.size
	|| !nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count
	|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count < 3
	|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count > nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.size)
	{
		return 0;
	}

	for(i = 0; i < nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count; i++)
	{
		/*Check if selected IE exists...*/
		if(!nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i])
		{
			return 0;
		}

		/*Check each included IE*/
		switch(i)
		{
			/*(1) LMF UE Measurement ID (M)*/
			case 0:
				if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id != NRPPa_ProtocolIE_ID_id_LMF_UE_Measurement_ID
				|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->criticality != NRPPa_Criticality_reject
				|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.present != NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_UE_Measurement_ID)
				{
					return 0;
				}

				lmf_ue = nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.UE_Measurement_ID;
				break;

			/*(2) Report Charcteristics*/
			case 1:
				if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id != NRPPa_ProtocolIE_ID_id_ReportCharacteristics
				|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->criticality != NRPPa_Criticality_reject
				|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.present != NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_ReportCharacteristics)
				{
					goto err; /*Beginning here with E-CID Measurement Initiation Failure message because NRPPa Transaction ID and LMF UE Measurement ID are known!*/
				}

				rtype = nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.ReportCharacteristics;
				break;

			/*(3) Measurement Periodicity (if periodic is requested), Measurement Quantities otherwise*/
			case 2:
				if(rtype == NRPPa_ReportCharacteristics_periodic)
				{
					if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id != NRPPa_ProtocolIE_ID_id_MeasurementPeriodicity
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->criticality != NRPPa_Criticality_reject
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.present != NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_MeasurementPeriodicity)
					{
						goto err;
					}

					period = nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementPeriodicity;
				}
				else
				{
mquant:
					if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id != NRPPa_ProtocolIE_ID_id_MeasurementQuantities
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->criticality != NRPPa_Criticality_reject
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.present != NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_MeasurementQuantities
					|| !nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementQuantities.list.array
					|| !nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementQuantities.list.size
					|| !nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementQuantities.list.count
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementQuantities.list.size < nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementQuantities.list.count
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementQuantities.list.size > NRPPa_maxNoMeas)
					{
						goto err;
					}

					/*Iterate through the Measurement Item List*/
					for(j = 0; j < nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementQuantities.list.count; j++)
					{
						if(!nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementQuantities.list.array[j])
						{
							goto err;
						}

						if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementQuantities.list.array[j]->id != NRPPa_ProtocolIE_ID_id_MeasurementQuantities_Item
						|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementQuantities.list.array[j]->criticality != NRPPa_Criticality_reject
						|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementQuantities.list.array[j]->value.present != NRPPa_MeasurementQuantities_ItemIEs__value_PR_MeasurementQuantities_Item)
						{
							goto err;
						}

						/*Store measurement quantity value*/
						mqlist[cnt[0]++] = nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementQuantities.list.array[j]->value.choice.MeasurementQuantities_Item.measurementQuantitiesValue;

						if(mqlist[cnt[0]-1] == NRPPa_MeasurementQuantitiesValue_angleOfArrivalNR)
						{
							isAoA = true;
						}
					}

				}
				break;

			/*(4) Measurement Quantities, otherwise: other RAT Measurement/WLAN Quantities/NR AoA periodicity*/
			case 3:
				if(rtype == NRPPa_ReportCharacteristics_periodic)
				{
					goto mquant;
				}

				else if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id == NRPPa_ProtocolIE_ID_id_OtherRATMeasurementQuantities)
				{
orat:
					if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->criticality != NRPPa_Criticality_ignore
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.present != NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_OtherRATMeasurementQuantities
					|| !nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.OtherRATMeasurementQuantities.list.array
					|| !nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.OtherRATMeasurementQuantities.list.size
					|| !nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.OtherRATMeasurementQuantities.list.count
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.OtherRATMeasurementQuantities.list.size < nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.OtherRATMeasurementQuantities.list.count
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.OtherRATMeasurementQuantities.list.size > NRPPa_maxNoMeas)
					{
						goto err;
					}

					/*Iterate through the ORAT Measurement Item List*/
					for(j = 0; j < nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.OtherRATMeasurementQuantities.list.count; j++)
					{
						if(!nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.OtherRATMeasurementQuantities.list.array[j])
						{
							goto err;
						}

						if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.OtherRATMeasurementQuantities.list.array[j]->id != NRPPa_ProtocolIE_ID_id_OtherRATMeasurementQuantities_Item
						|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.OtherRATMeasurementQuantities.list.array[j]->criticality != NRPPa_Criticality_reject
						|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.OtherRATMeasurementQuantities.list.array[j]->value.present != NRPPa_OtherRATMeasurementQuantities_ItemIEs__value_PR_OtherRATMeasurementQuantities_Item)
						{
							goto err;
						}

						/*Store ORAT measurement quantity value*/
						orat[cnt[1]++] = nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.OtherRATMeasurementQuantities.list.array[j]->value.choice.OtherRATMeasurementQuantities_Item.otherRATMeasurementQuantitiesValue;

						isORAT = true;
					}
				}

				else if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id == NRPPa_ProtocolIE_ID_id_WLANMeasurementQuantities)
				{
wlan:
					if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->criticality != NRPPa_Criticality_ignore
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.present != NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_WLANMeasurementQuantities
					|| !nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.WLANMeasurementQuantities.list.array
					|| !nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.WLANMeasurementQuantities.list.size
					|| !nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.WLANMeasurementQuantities.list.count
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.WLANMeasurementQuantities.list.size < nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.WLANMeasurementQuantities.list.count
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.WLANMeasurementQuantities.list.size > NRPPa_maxNoMeas)
					{
						goto err;
					}

					/*Iterate through the WLAN Measurement Item List*/
					for(j = 0; j < nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.WLANMeasurementQuantities.list.count; j++)
					{
						if(!nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.WLANMeasurementQuantities.list.array[j])
						{
							goto err;
						}

						if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.WLANMeasurementQuantities.list.array[j]->id != NRPPa_ProtocolIE_ID_id_WLANMeasurementQuantities_Item
						|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.WLANMeasurementQuantities.list.array[j]->criticality != NRPPa_Criticality_reject
						|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.WLANMeasurementQuantities.list.array[j]->value.present != NRPPa_WLANMeasurementQuantities_ItemIEs__value_PR_WLANMeasurementQuantities_Item)
						{
							goto err;
						}

						/*Store WLAN measurement quantity value*/
						wlan[cnt[2]++] = nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.WLANMeasurementQuantities.list.array[j]->value.choice.WLANMeasurementQuantities_Item.wLANMeasurementQuantitiesValue;

						isWLAN = true;
					}
				}

				else if(isAoA && nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id == NRPPa_ProtocolIE_ID_id_MeasurementPeriodicityNR_AoA)
				{
aoa:
					if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->criticality != NRPPa_Criticality_reject
					|| nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.present != NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_MeasurementPeriodicityNR_AoA)
					{
						goto err;
					}
					aoa = nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->value.choice.MeasurementPeriodicityNR_AoA;
					isNRAoA = true;
				}

				else
				{
					return 0;
				}

				break;

			/*(5) Other RAT Measurement Quantities/WLAN Measurement Quantities/NR AoA Periodicity*/
			case 4:
				if(isNRAoA)
				{
					/*Last possible IE is already reached. Return error...*/
					return 0;
				}

				if(rtype == NRPPa_ReportCharacteristics_periodic)
				{
					if(!isORAT && nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id == NRPPa_ProtocolIE_ID_id_OtherRATMeasurementQuantities)
					{
						goto orat;
					}
					else if(!isWLAN && nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id == NRPPa_ProtocolIE_ID_id_WLANMeasurementQuantities)
					{
						goto wlan;
					}
					else if(isAoA && nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id == NRPPa_ProtocolIE_ID_id_MeasurementPeriodicityNR_AoA)
					{
						goto aoa;
					}
					else
					{
						goto err;
					}
				}
				else if(!isWLAN && nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id == NRPPa_ProtocolIE_ID_id_WLANMeasurementQuantities)
				{
					goto wlan;
				}
				else if(isAoA && nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id == NRPPa_ProtocolIE_ID_id_MeasurementPeriodicityNR_AoA)
				{
					goto aoa;
				}
				else
				{
					goto err;
				}
				break;

			/*(6) WLAN Measurement Quantities/NR AoA Measurement Periodicity*/
			case 5:
				if(isNRAoA)
				{
					/*Last possible IE is already reached. Return error...*/
					goto err;
				}

				if(rtype == NRPPa_ReportCharacteristics_periodic)
				{
					if(!isWLAN && nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id == NRPPa_ProtocolIE_ID_id_WLANMeasurementQuantities)
					{
						goto wlan;
					}
					else if(isAoA && nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id == NRPPa_ProtocolIE_ID_id_MeasurementPeriodicityNR_AoA)
					{
						goto aoa;
					}
					else
					{
						goto err;
					}
				}
				else if(isAoA && nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id == NRPPa_ProtocolIE_ID_id_MeasurementPeriodicityNR_AoA)
				{
					goto aoa;
				}
				else
				{
					goto err;
				}
				break;

			/*NR AoA Periodicity*/
			case 6:
				if(isNRAoA)
				{
					/*Last possible IE is already reached. Return error...*/
					goto err;
				}

				if(isAoA && nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[i]->id == NRPPa_ProtocolIE_ID_id_MeasurementPeriodicityNR_AoA)
				{
					goto aoa;
				}
				else
				{
					goto err;
				}
				break;

			default:
				goto err;
		}
	}

#ifndef RESEARCH
	printf("[gNB-n2] NRPPa E-CID Measurement Request was successfully checked\n");
#endif

	/*(2) Get free RAN UE Measurement ID*/
	if((ran_ue = getRANUEMeasurementID(&lmf_ue)) < 0)
	{
		goto err;
	}

	/*
	 * Further handling depends on the requested report type:
	 *
	 * @NRPPa_ReportCharacteristics_onDemand: The requested E-CID measurement values has to be sent within the response message.
	 * @NRPPa_ReportCharacteristics_periodic: The requested E-CID measurement values has to be sent within a E-CID Measurement Report message periodically (separate POSIX thread).
	 */
	if(rtype == NRPPa_ReportCharacteristics_onDemand)
	{
		/*
 		 * Check if requested measurement values can be provided AND add them to the corresponding Measurement Result IE:
 		 *
 		 * (I)   E-CID Measurement Result
 		 * (II)  Other RAT Measurement Result
 		 * (III) WLAN Measurement Result
 		 *
 		 * NOTE: Currently, there are only selected E-CID Measurement values available! Therefore, only (I) is considered.
 		 *		Otherwise, a NRPPa E-CID Measurement Initiation Failure message is generated.
 		 */
 		 if((ecid = createECIDMeasurementResult(mqlist, cnt[0])) == NULL)
 		 {
 		 	cause.present = NRPPa_Cause_PR_radioNetwork;
			cause.choice.radioNetwork = NRPPa_CauseRadioNetwork_requested_item_not_supported;
 		 	goto err;
 		 }
#ifndef RESEARCH
		printf("[gNB-n2] NRPPa E-CID Measurement Initiation Response with %d items prepared\n", ecid->measuredResults->list.count);
#endif

		/*-- TODO: Add checking of other measurement quantities HERE: @orat_res + @wlan_res --*/

		/*Create NRPPa E-CID Measurement Initiation Response message*/
		if((resp = NRPPa_ECID_Measurement_Initiation_Response(transID, lmf_ue, ran_ue, &ecid, NULL, &orat_res, &wlan_res, NULL)) == NULL || !removeRANUEMeasurementID(&lmf_ue))
		{
			goto err;
		}

		/*Drop RAN UE Measurement ID because after sending the corresponding logical UE connection ends*/
		ran_ue = 0;

		if(!resp->enc || !resp->size)
		{
			if(resp->enc)
			{
				free(resp->enc);
				resp->enc = 0;
			}
			free(resp);
			resp = 0;
			goto err;
		}
	}

	else if(rtype == NRPPa_ReportCharacteristics_periodic)
	{
		/* (1) Create an E-CID Measurement Report parameter set*/

		/*Check if entry is already in use*/
		if(report_list[lmf_ue-1][ran_ue-1].isActive)
		{
			goto err;
		}

		/*Allocate memory*/
		if((param = calloc(1, sizeof(ecid_report_param_t))) == NULL || (param->ngap_amf.buf = calloc(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[0]->value.choice.AMF_UE_NGAP_ID.size, sizeof(uint8_t))) == NULL)
		{
			goto err;
		}

		/*Set time interval for sending NRPPa E-CID Measurement Report messages*/
		switch(period)
		{
			case NRPPa_MeasurementPeriodicity_ms120:
				param->period_ns = 120000000;
				break;
			case NRPPa_MeasurementPeriodicity_ms240:
				param->period_ns = 240000000;
				break;
			case NRPPa_MeasurementPeriodicity_ms480:
				param->period_ns = 480000000;
				break;
			case NRPPa_MeasurementPeriodicity_ms640:
				param->period_ns = 640000000;
				break;
			case NRPPa_MeasurementPeriodicity_ms1024:
				param->period_ns = 1024000000;
				break;
			case NRPPa_MeasurementPeriodicity_ms2048:
				param->period_ns = 2048000000;
				break;
			case NRPPa_MeasurementPeriodicity_ms5120:
				param->period_ns = 5120000000;
				break;
			default:
				//TODO: implementation open; currently: error response
				free(param->ngap_amf.buf);
				free(param);
				param = 0;
				goto err;
		}

		/*Initialize entry with further data*/
		param->lmf_ue = lmf_ue;
		param->ran_ue = ran_ue;
		param->ngap_amf.size = ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[0]->value.choice.AMF_UE_NGAP_ID.size;
		memcpy((void*)param->ngap_amf.buf, (void*) ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[0]->value.choice.AMF_UE_NGAP_ID.buf, ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[0]->value.choice.AMF_UE_NGAP_ID.size);
		param->ngap_ran = ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[1]->value.choice.RAN_UE_NGAP_ID;
		memcpy((void*)param->nfid, (void*) ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[2]->value.choice.RoutingID.buf, 16*sizeof(uint8_t));
		memcpy((void*)param->mqlist, (void*)mqlist, NRPPa_maxNoMeas*sizeof(NRPPa_MeasurementQuantitiesValue_t));
		param->num = cnt[0];

		/*(2) Create and send NRPPa E-CID Measurement Initiation Response message without measurement data*/
		if((resp = NRPPa_ECID_Measurement_Initiation_Response(transID, lmf_ue, ran_ue, NULL, NULL, NULL, NULL, NULL)) == NULL)
		{
			goto err;
		}

		if(!resp->enc || !resp->size)
		{
			if(resp->enc)
			{
				free(resp->enc);
				resp->enc = 0;
			}
			free(resp);
			resp = 0;
			goto err;
		}

		/*(3) Set Reporting to true*/
		sem_wait(&report_list[lmf_ue-1][ran_ue-1].lock);

		report_list[lmf_ue-1][ran_ue-1].isActive = true;

		sem_post(&report_list[lmf_ue-1][ran_ue-1].lock);

		/*(4) Starting NRPPa E-CID Measurement Report message generation via thread pool for long service time jobs*/
		if(!pthpool_add_job(tpool_long, E_CID_MeasurementReport, param))
		{
			printf("[gNB-n2] NRPPa E-CID Measurement Report message generation couldn't be added to the target thread pool\n");
			freeNRPPaMessage(resp);
			free(resp);
			resp = 0;
			goto err;
		}
	}
	else
	{
		goto err;
	}

	return resp;

err:
	/*
	 * If error cause was not initialized:
	 *
	 * Set NRPPa Cause to Miscellaneous Cause + Unspecified Failure reason (3GPP TS 38.455, 9.2.1)
	 */
	if(!cause.present)
	{
		cause.present = NRPPa_Cause_PR_misc;
		cause.choice.misc = NRPPa_CauseMisc_unspecified;
	}

	/*Free reserved RAN UE Measurement ID*/
	if(ran_ue > 0)
	{
		removeRANUEMeasurementID(&lmf_ue);
	}

	/*Remove report entry from global table*/
	if(param)
	{
		free(param->ngap_amf.buf);
		free(param);
		param = 0;
	}

	/*NRPPa E-CID Measurement Initiation Failure message*/
	if(resp)
	{
		free(resp);
		resp = 0;
	}
	resp = NRPPa_ECID_Measurement_Initiation_Failure(transID, lmf_ue, &cause, NULL);
	if(!resp || !resp->enc || !resp->size)
	{
		if(resp->enc)
		{
			free(resp->enc);
		}
		free(resp);
		return 0;
	}

	return resp;
}

/*
 * E_CID_MeasurementTermination - parse NRPPa E-CID Measurement Termination Command message
 * and stop sending of corresponding E-CID Measurement Report message.
 * --------------------------------------------------------------------------------------------
 * @nrppa: NRPPa PDU message structure (request)
 * --------------------------------------------------------------------------------------------
 * compliant with: 3GPP TS 38.455, 8.2.4
 */
int
E_CID_MeasurementTermination(nrppamsg_t *nrppa)
{
	NRPPa_UE_Measurement_ID_t lmf_ue = 0, ran_ue = 0;

	/*Check header fields*/
	if(nrppa->pdu->choice.initiatingMessage->procedureCode != NRPPa_ProcedureCode_id_e_CIDMeasurementTermination ||
	   nrppa->pdu->choice.initiatingMessage->criticality != NRPPa_Criticality_reject ||
	   nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.count != 2)
	{
		return -1;
	}

	/*(1) LMF UE Measurement ID*/
	if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[0]->id != NRPPa_ProtocolIE_ID_id_LMF_UE_Measurement_ID ||
	   nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[0]->criticality != NRPPa_Criticality_reject ||
	   nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[0]->value.present != NRPPa_E_CIDMeasurementTerminationCommand_IEs__value_PR_UE_Measurement_ID)
	{
		return -1;
	}

	lmf_ue = nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[0]->value.choice.UE_Measurement_ID;

	/*(2) RAN UE Measurement ID*/
	if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[1]->id != NRPPa_ProtocolIE_ID_id_RAN_UE_Measurement_ID ||
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[1]->criticality != NRPPa_Criticality_reject ||
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[1]->value.present != NRPPa_E_CIDMeasurementTerminationCommand_IEs__value_PR_UE_Measurement_ID_1)
	{
		return -1;
	}

	ran_ue = nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[1]->value.choice.UE_Measurement_ID_1;

	/*Look up in global E-CID Measurement Report table if it contains a pair of the received IDs*/
	if(report_list[lmf_ue-1][ran_ue-1].isActive)
	{
		sem_wait(&report_list[lmf_ue-1][ran_ue-1].lock);

		report_list[lmf_ue-1][ran_ue-1].isActive = false;

		sem_post(&report_list[lmf_ue-1][ran_ue-1].lock);
		return 0;
	}

	printf("[NRPPa] No E-CID Measurement Report Generation (%ld, %ld) found!\n", lmf_ue, ran_ue);
	return -1;
}
