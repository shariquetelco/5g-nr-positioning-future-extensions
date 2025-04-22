# mm_context_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**access_type** | **access_type_t \*** |  | 
**nas_security_mode** | [**nas_security_mode_t**](nas_security_mode.md) \* |  | [optional] 
**eps_nas_security_mode** | [**eps_nas_security_mode_t**](eps_nas_security_mode.md) \* |  | [optional] 
**nas_downlink_count** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**nas_uplink_count** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**ue_security_capability** | **char \*** | string with format &#39;bytes&#39; as defined in OpenAPI | [optional] 
**s1_ue_network_capability** | **char \*** | string with format &#39;bytes&#39; as defined in OpenAPI | [optional] 
**allowed_nssai** | [**list_t**](snssai.md) \* |  | [optional] 
**nssai_mapping_list** | [**list_t**](nssai_mapping.md) \* |  | [optional] 
**allowed_home_nssai** | [**list_t**](snssai.md) \* |  | [optional] 
**partially_allowed_nssai** | [**list_t**](partially_allowed_snssai.md) \* |  | [optional] 
**replaced_snssai_mapping_list** | [**list_t**](slice_replacement_mapping.md) \* |  | [optional] 
**ns_instance_list** | **list_t \*** |  | [optional] 
**expected_u_ebehavior** | [**expected_ue_behavior_t**](expected_ue_behavior.md) \* |  | [optional] 
**ue_differentiation_info** | [**ue_differentiation_info_t**](ue_differentiation_info.md) \* |  | [optional] 
**plmn_assi_ue_radio_cap_id** | **char \*** | string with format &#39;bytes&#39; as defined in OpenAPI | [optional] 
**man_assi_ue_radio_cap_id** | **char \*** | string with format &#39;bytes&#39; as defined in OpenAPI | [optional] 
**ucmf_dic_entry_id** | **char \*** |  | [optional] 
**n3_iwf_id** | [**global_ran_node_id_t**](global_ran_node_id.md) \* |  | [optional] 
**wagf_id** | [**global_ran_node_id_t**](global_ran_node_id.md) \* |  | [optional] 
**tngf_id** | [**global_ran_node_id_t**](global_ran_node_id.md) \* |  | [optional] 
**an_n2_ap_id** | **int** |  | [optional] 
**nssaa_status_list** | [**list_t**](nssaa_status.md) \* |  | [optional] 
**pending_nssai_mapping_list** | [**list_t**](nssai_mapping.md) \* |  | [optional] 
**uuaa_mm_status** | **uuaa_mm_status_t \*** |  | [optional] 
**dereg_inact_timer_list** | **list_t*** | The S-NSSAI shall be used as the key of the map. | [optional] 
**vo_support_match_ind** | **int** |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


