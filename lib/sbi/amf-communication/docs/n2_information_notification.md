# n2_information_notification_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**n2_notify_subscription_id** | **char \*** |  | 
**n2_info_container** | [**n2_info_container_t**](n2_info_container.md) \* |  | [optional] 
**to_release_session_list** | **list_t \*** |  | [optional] 
**lcs_correlation_id** | **char \*** | LCS Correlation ID. | [optional] 
**notify_reason** | **n2_info_notify_reason_t \*** |  | [optional] 
**smf_change_info_list** | [**list_t**](smf_change_info.md) \* |  | [optional] 
**ran_node_id** | [**global_ran_node_id_t**](global_ran_node_id.md) \* |  | [optional] 
**initial_amf_name** | **char \*** | Fully Qualified Domain Name | [optional] 
**an_n2_ipv4_addr** | **char \*** | String identifying a IPv4 address formatted in the &#39;dotted decimal&#39; notation as defined in RFC 1166.  | [optional] 
**an_n2_ipv6_addr** | [**ipv6_addr_t**](ipv6_addr.md) \* |  | [optional] 
**guami** | [**guami_t**](guami.md) \* |  | [optional] 
**notify_source_ng_ran** | **int** |  | [optional] [default to false]
**notif_correlation_id** | **char \*** |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


