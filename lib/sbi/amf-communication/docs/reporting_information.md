# reporting_information_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**imm_rep** | **int** |  | [optional] 
**notif_method** | [**notification_method_1_t**](notification_method_1.md) \* |  | [optional] 
**max_report_nbr** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**mon_dur** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**rep_period** | **int** | indicating a time in seconds. | [optional] 
**samp_ratio** | **int** | Unsigned integer indicating Sampling Ratio (see clauses 4.15.1 of 3GPP TS 23.502), expressed in percent.   | [optional] 
**partition_criteria** | [**list_t**](partitioning_criteria.md) \* | Criteria for partitioning the UEs before applying the sampling ratio. | [optional] 
**grp_rep_time** | **int** | indicating a time in seconds. | [optional] 
**notif_flag** | [**notification_flag_t**](notification_flag.md) \* |  | [optional] 
**notif_flag_instruct** | [**muting_exception_instructions_t**](muting_exception_instructions.md) \* |  | [optional] 
**muting_setting** | [**muting_notifications_settings_t**](muting_notifications_settings.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


