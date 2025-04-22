# amf_event_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | [**amf_event_type_t**](amf_event_type.md) \* |  | 
**immediate_flag** | **int** |  | [optional] [default to false]
**area_list** | [**list_t**](amf_event_area.md) \* |  | [optional] 
**location_filter_list** | [**list_t**](location_filter.md) \* |  | [optional] 
**ref_id** | **int** | Integer where the allowed values correspond to the value range of an unsigned 64-bit integer.  | [optional] 
**traffic_descriptor_list** | [**list_t**](traffic_descriptor.md) \* |  | [optional] 
**report_ue_reachable** | **int** |  | [optional] [default to false]
**reachability_filter** | [**reachability_filter_t**](reachability_filter.md) \* |  | [optional] 
**udm_detect_ind** | **int** |  | [optional] [default to false]
**max_reports** | **int** |  | [optional] 
**presence_info_list** | **list_t*** | A map(list of key-value pairs) where praId serves as key. | [optional] 
**max_response_time** | **int** | indicating a time in seconds. | [optional] 
**target_area** | [**target_area_t**](target_area.md) \* |  | [optional] 
**snssai_filter** | [**list_t**](ext_snssai.md) \* |  | [optional] 
**ue_in_area_filter** | [**ue_in_area_filter_t**](ue_in_area_filter.md) \* |  | [optional] 
**min_interval** | **int** | indicating a time in seconds. | [optional] 
**next_report** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**idle_status_ind** | **int** |  | [optional] [default to false]
**dispersion_area** | [**dispersion_area_t**](dispersion_area.md) \* |  | [optional] 
**next_periodic_report_time** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**adjust_ao_ion_ra** | **int** |  | [optional] [default to false]
**ran_timing_synchro_status_change** | **int** |  | [optional] [default to false]
**notify_for_supi_list** | **list_t \*** |  | [optional] 
**notify_for_group_list** | **list_t \*** |  | [optional] 
**notify_for_snssai_dnn_list** | [**list_t**](snssai_dnn_item.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


