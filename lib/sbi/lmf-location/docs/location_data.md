# location_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**location_estimate** | [**geographic_area_t**](geographic_area.md) \* |  | 
**accuracy_fulfilment_indicator** | **accuracy_fulfilment_indicator_t \*** |  | [optional] 
**age_of_location_estimate** | **int** | Indicates value of the age of the location estimate. | [optional] 
**timestamp_of_location_estimate** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**velocity_estimate** | [**velocity_estimate_t**](velocity_estimate.md) \* |  | [optional] 
**civic_address** | [**civic_address_t**](civic_address.md) \* |  | [optional] 
**local_location_estimate** | [**local_area_t**](local_area.md) \* |  | [optional] 
**positioning_data_list** | [**list_t**](positioning_method_and_usage.md) \* |  | [optional] 
**gnss_positioning_data_list** | [**list_t**](gnss_positioning_method_and_usage.md) \* |  | [optional] 
**ecgi** | [**ecgi_t**](ecgi.md) \* |  | [optional] 
**ncgi** | [**ncgi_t**](ncgi.md) \* |  | [optional] 
**altitude** | **double** | Indicates value of altitude. | [optional] 
**barometric_pressure** | **int** | Specifies the measured uncompensated atmospheric pressure. | [optional] 
**serving_lmf_identification** | **char \*** | LMF identification. | [optional] 
**ue_positioning_cap** | **char \*** | Positioning capabilities supported by the UE. A string encoding the \&quot;ProvideCapabilities-r9-IEs\&quot; IE as specified in clause 6.3 of 3GPP TS 37.355 (start from octet 1). | [optional] 
**ue_area_ind** | [**ue_area_indication_t**](ue_area_indication.md) \* |  | [optional] 
**supported_features** | **char \*** | A string used to indicate the features supported by an API that is used as defined in clause  6.6 in 3GPP TS 29.500. The string shall contain a bitmask indicating supported features in  hexadecimal representation Each character in the string shall take a value of \&quot;0\&quot; to \&quot;9\&quot;,  \&quot;a\&quot; to \&quot;f\&quot; or \&quot;A\&quot; to \&quot;F\&quot; and shall represent the support of 4 features as described in  table 5.2.2-3. The most significant character representing the highest-numbered features shall  appear first in the string, and the character representing features 1 to 4 shall appear last  in the string. The list of features and their numbering (starting with 1) are defined  separately for each API. If the string contains a lower number of characters than there are  defined features for an API, all features that would be represented by characters that are not  present in the string are not supported.  | [optional] 
**achieved_qos** | [**minor_location_qo_s_t**](minor_location_qo_s.md) \* |  | [optional] 
**direct_report_ind** | **int** |  | [optional] [default to false]
**indoor_outdoor_ind** | **indoor_outdoor_ind_t \*** |  | [optional] 
**accepted_periodic_event_info** | [**periodic_event_info_t**](periodic_event_info.md) \* |  | [optional] 
**ha_gnss_metrics** | [**high_accuracy_gnss_metrics_t**](high_accuracy_gnss_metrics.md) \* |  | [optional] 
**los_nlos_measure_ind** | **los_nlos_measure_ind_t \*** |  | [optional] 
**related_applicationlayer_id** | **char \*** | String identifying an UE with application layer ID. The format of the application  layer ID parameter is same as the Application layer ID defined in clause 11.3.4 of  3GPP TS 24.554.  | [optional] 
**distance_direction** | [**range_direction_t**](range_direction.md) \* |  | [optional] 
**_2d_relative_location** | [**model_2_d_relative_location_t**](model_2_d_relative_location.md) \* |  | [optional] 
**_3d_relative_location** | [**model_3_d_relative_location_t**](model_3_d_relative_location.md) \* |  | [optional] 
**relative_velocity** | [**velocity_estimate_t**](velocity_estimate.md) \* |  | [optional] 
**ranging_sl_capability** | **char \*** | Ranging/Sidelink Positioning Positioning capabilities supported by the UE. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


