# ue_communication_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**comm_dur** | **int** | indicating a time in seconds. | [optional] 
**comm_dur_variance** | **float** | string with format &#39;float&#39; as defined in OpenAPI. | [optional] 
**perio_time** | **int** | indicating a time in seconds. | [optional] 
**perio_time_variance** | **float** | string with format &#39;float&#39; as defined in OpenAPI. | [optional] 
**ts** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**ts_variance** | **float** | string with format &#39;float&#39; as defined in OpenAPI. | [optional] 
**recurring_time** | [**scheduled_communication_time_1_t**](scheduled_communication_time_1.md) \* |  | [optional] 
**traf_char** | [**traffic_characterization_t**](traffic_characterization.md) \* |  | [optional] 
**ratio** | **int** | Unsigned integer indicating Sampling Ratio (see clauses 4.15.1 of 3GPP TS 23.502), expressed in percent.   | [optional] 
**perio_comm_ind** | **int** | This attribute indicates whether the UE communicates periodically or not. Set to \&quot;true\&quot; to indicate the UE communicates periodically, otherwise set to \&quot;false\&quot; or omitted.  | [optional] 
**confidence** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**ana_of_app_list** | [**app_list_for_ue_comm_t**](app_list_for_ue_comm.md) \* |  | [optional] 
**sess_inact_timer** | [**sess_inact_timer_for_ue_comm_t**](sess_inact_timer_for_ue_comm.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


