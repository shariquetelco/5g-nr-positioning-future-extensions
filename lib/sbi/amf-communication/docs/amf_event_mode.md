# amf_event_mode_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**trigger** | [**amf_event_trigger_t**](amf_event_trigger.md) \* |  | 
**max_reports** | **int** |  | [optional] 
**expiry** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**rep_period** | **int** | indicating a time in seconds. | [optional] 
**samp_ratio** | **int** | Unsigned integer indicating Sampling Ratio (see clauses 4.15.1 of 3GPP TS 23.502), expressed in percent.   | [optional] 
**partitioning_criteria** | [**list_t**](partitioning_criteria.md) \* |  | [optional] 
**notif_flag** | [**notification_flag_t**](notification_flag.md) \* |  | [optional] 
**muting_exc_instructions** | [**amf_event_mode_muting_exc_instructions_t**](amf_event_mode_muting_exc_instructions.md) \* |  | [optional] 
**muting_not_settings** | [**muting_notifications_settings_t**](muting_notifications_settings.md) \* |  | [optional] [readonly] 
**var_rep_period_info** | [**list_t**](var_rep_period.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


