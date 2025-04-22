# mov_behav_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**ts_start** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | 
**ts_duration** | **int** | indicating a time in seconds. | 
**num_of_ue** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**ratio** | **int** | Unsigned integer indicating Sampling Ratio (see clauses 4.15.1 of 3GPP TS 23.502), expressed in percent.   | [optional] 
**avr_speed** | **float** | string with format &#39;float&#39; as defined in OpenAPI. | [optional] 
**speed_thresd_infos** | [**list_t**](speed_threshold_info.md) \* |  | [optional] 
**direction_ue_infos** | [**list_t**](direction_info.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


