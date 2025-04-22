# accuracy_req_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**accu_time_win** | [**time_window_t**](time_window.md) \* |  | [optional] 
**accu_period** | **int** | indicating a time in seconds. | [optional] 
**accu_dev_thr** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**min_num** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**updated_ana_flg** | **int** | Indicates the updated Analytics flag. Set to \&quot;true\&quot; indicates that the NWDAF can provide the updated analytics if the analytics can be generated within the analytics accuracy information time window, which is specified by \&quot;accuTimeWin\&quot; attribute. Otherwise set to “false”. Default value is “false” if omitted.  | [optional] 
**correction_interval** | **int** | indicating a time in seconds. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


