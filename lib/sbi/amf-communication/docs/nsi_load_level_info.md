# nsi_load_level_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**load_level_information** | **int** | Load level information of the network slice and the optionally associated network slice instance.  | 
**snssai** | [**snssai_t**](snssai.md) \* |  | 
**nsi_id** | **char \*** | Contains the Identifier of the selected Network Slice instance | [optional] 
**res_usage** | [**resource_usage_t**](resource_usage.md) \* |  | [optional] 
**num_of_exceed_load_level_thr** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**exceed_load_level_thr_ind** | **int** | Indicates whether the Load Level Threshold is met or exceeded by the statistics value. Set to \&quot;true\&quot; if the Load Level Threshold is met or exceeded, otherwise set to \&quot;false\&quot;. Shall be present if one of the element in the \&quot;listOfAnaSubsets\&quot; attribute was set to EXCEED_LOAD_LEVEL_THR_IND.  | [optional] 
**network_area** | [**network_area_info_t**](network_area_info.md) \* |  | [optional] 
**time_period** | [**time_window_t**](time_window.md) \* |  | [optional] 
**res_usg_thr_cross_time_period** | [**list_t**](time_window.md) \* | Each element indicates the time elapsed between times each threshold is met or exceeded or crossed. The start time and end time are the exact time stamps of the resource usage threshold is reached or exceeded. May be present if the \&quot;listOfAnaSubsets\&quot; attribute is provided and the maximum number of instances shall not exceed the value provided in the \&quot;numOfExceedLoadLevelThr\&quot; attribute.  | [optional] 
**num_of_ues** | [**number_average_t**](number_average.md) \* |  | [optional] 
**num_of_pdu_sess** | [**number_average_t**](number_average.md) \* |  | [optional] 
**confidence** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


