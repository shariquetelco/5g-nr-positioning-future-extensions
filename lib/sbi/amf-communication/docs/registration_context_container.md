# registration_context_container_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**ue_context** | [**ue_context_t**](ue_context.md) \* |  | 
**local_time_zone** | **char \*** | String with format \&quot;time-numoffset\&quot; optionally appended by \&quot;daylightSavingTime\&quot;, where  - \&quot;time-numoffset\&quot; shall represent the time zone adjusted for daylight saving time and be    encoded as time-numoffset as defined in clause 5.6 of IETF RFC 3339;  - \&quot;daylightSavingTime\&quot; shall represent the adjustment that has been made and shall be    encoded as \&quot;+1\&quot; or \&quot;+2\&quot; for a +1 or +2 hours adjustment.   The example is for 8 hours behind UTC, +1 hour adjustment for Daylight Saving Time.  | [optional] 
**an_type** | **access_type_t \*** |  | 
**an_n2_ap_id** | **int** |  | 
**ran_node_id** | [**global_ran_node_id_t**](global_ran_node_id.md) \* |  | 
**initial_amf_name** | **char \*** | Fully Qualified Domain Name | 
**user_location** | [**user_location_t**](user_location.md) \* |  | 
**rrc_est_cause** | **char \*** |  | [optional] 
**ue_context_request** | **int** |  | [optional] [default to false]
**initial_amf_n2_ap_id** | **int** |  | [optional] 
**an_n2_ipv4_addr** | **char \*** | String identifying a IPv4 address formatted in the &#39;dotted decimal&#39; notation as defined in RFC 1166.  | [optional] 
**an_n2_ipv6_addr** | [**ipv6_addr_t**](ipv6_addr.md) \* |  | [optional] 
**allowed_nssai** | [**allowed_nssai_t**](allowed_nssai.md) \* |  | [optional] 
**configured_nssai** | [**list_t**](configured_snssai.md) \* |  | [optional] 
**rejected_nssai_in_plmn** | [**list_t**](snssai.md) \* |  | [optional] 
**rejected_nssai_in_ta** | [**list_t**](snssai.md) \* |  | [optional] 
**selected_plmn_id** | [**plmn_id_t**](plmn_id.md) \* |  | [optional] 
**iab_node_ind** | **int** |  | [optional] [default to false]
**mbsr_node_ind** | **int** |  | [optional] [default to false]
**ce_mode_b_ind** | [**ce_mode_b_ind_t**](ce_mode_b_ind.md) \* |  | [optional] 
**lte_m_ind** | [**lte_m_ind_t**](lte_m_ind.md) \* |  | [optional] 
**authenticated_ind** | **int** |  | [optional] [default to false]
**npn_access_info** | [**npn_access_info_t**](npn_access_info.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


