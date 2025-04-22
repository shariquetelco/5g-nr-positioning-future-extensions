# event_notification_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**event** | [**nwdaf_event_t**](nwdaf_event.md) \* |  | 
**start** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**expiry** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**time_stamp_gen** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**fail_notify_code** | [**nwdaf_failure_code_t**](nwdaf_failure_code.md) \* |  | [optional] 
**rv_wait_time** | **int** | indicating a time in seconds. | [optional] 
**ana_meta_info** | [**analytics_metadata_info_t**](analytics_metadata_info.md) \* |  | [optional] 
**nf_load_level_infos** | [**list_t**](nf_load_level_information.md) \* |  | [optional] 
**nsi_load_level_infos** | [**list_t**](nsi_load_level_info.md) \* |  | [optional] 
**pfd_determ_infos** | [**list_t**](pfd_determination_info.md) \* |  | [optional] 
**slice_load_level_info** | [**slice_load_level_information_t**](slice_load_level_information.md) \* |  | [optional] 
**svc_exps** | [**list_t**](service_experience_info.md) \* |  | [optional] 
**qos_sustain_infos** | [**list_t**](qos_sustainability_info.md) \* |  | [optional] 
**ue_comms** | [**list_t**](ue_communication.md) \* |  | [optional] 
**ue_mobs** | [**list_t**](ue_mobility.md) \* |  | [optional] 
**user_data_cong_infos** | [**list_t**](user_data_congestion_info.md) \* |  | [optional] 
**abnor_behavrs** | [**list_t**](abnormal_behaviour.md) \* |  | [optional] 
**nw_perfs** | [**list_t**](network_perf_info.md) \* |  | [optional] 
**dn_perf_infos** | [**list_t**](dn_perf_info.md) \* |  | [optional] 
**disper_infos** | [**list_t**](dispersion_info.md) \* |  | [optional] 
**red_trans_infos** | [**list_t**](redundant_transmission_exp_info.md) \* |  | [optional] 
**wlan_infos** | [**list_t**](wlan_performance_info.md) \* |  | [optional] 
**smcc_exps** | [**list_t**](smcce_info.md) \* |  | [optional] 
**pdu_ses_traf_infos** | [**list_t**](pdu_ses_traffic_info.md) \* |  | [optional] 
**data_vl_trns_tm_infos** | [**list_t**](e2e_data_vol_trans_time_info.md) \* |  | [optional] 
**accu_info** | [**accuracy_info_t**](accuracy_info.md) \* |  | [optional] 
**cancel_accu_ind** | **int** | Indicates cancelled subscription of the analytics accuracy information. Set to \&quot;true\&quot; indicates the NWDAF cancelled subscription of analytics accuracy information as the NWDAF does not support the accuracy checking capability. Otherwise set to \&quot;false\&quot;. Default value is \&quot;false\&quot; if omitted.  | [optional] 
**pause_ind** | **int** | Pause analytics consumption indication. Set to \&quot;true\&quot; to indicate the consumer to stop the consumption of the analytics. Default value is \&quot;false\&quot; if omitted.  | [optional] 
**resume_ind** | **int** | Resume analytics consumption indication. Set to \&quot;true\&quot; to indicate the consumer to resume the consumption of the analytics. Default value is \&quot;false\&quot; if omitted.  | [optional] 
**mov_behav_infos** | [**list_t**](mov_behav_info.md) \* |  | [optional] 
**loc_acc_infos** | [**list_t**](loc_accuracy_info.md) \* |  | [optional] 
**rel_prox_infos** | [**list_t**](rel_prox_info.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


