# location_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**gpsi** | **char \*** | String identifying a Gpsi shall contain either an External Id or an MSISDN.  It shall be formatted as follows -External Identifier&#x3D; \&quot;extid-&#39;extid&#39;, where &#39;extid&#39;  shall be formatted according to clause 19.7.2 of 3GPP TS 23.003 that describes an  External Identifier.   | [optional] 
**supi** | **char \*** | String identifying a Supi that shall contain either an IMSI, a network specific identifier, a Global Cable Identifier (GCI) or a Global Line Identifier (GLI) as specified in clause  2.2A of 3GPP TS 23.003. It shall be formatted as follows  - for an IMSI \&quot;imsi-&lt;imsi&gt;\&quot;, where &lt;imsi&gt; shall be formatted according to clause 2.2    of 3GPP TS 23.003 that describes an IMSI.  - for a network specific identifier \&quot;nai-&lt;nai&gt;, where &lt;nai&gt; shall be formatted    according to clause 28.7.2 of 3GPP TS 23.003 that describes an NAI.  - for a GCI \&quot;gci-&lt;gci&gt;\&quot;, where &lt;gci&gt; shall be formatted according to clause 28.15.2    of 3GPP TS 23.003.  - for a GLI \&quot;gli-&lt;gli&gt;\&quot;, where &lt;gli&gt; shall be formatted according to clause 28.16.2 of    3GPP TS 23.003.To enable that the value is used as part of an URI, the string shall    only contain characters allowed according to the \&quot;lower-with-hyphen\&quot; naming convention    defined in 3GPP TS 29.501.  | [optional] 
**location_estimate** | [**geographic_area_t**](geographic_area.md) \* |  | [optional] 
**civic_address** | [**civic_address_t**](civic_address.md) \* |  | [optional] 
**local_location_estimate** | [**local_area_t**](local_area.md) \* |  | [optional] 
**age_of_location_estimate** | **int** | Indicates value of the age of the location estimate. | [optional] 
**timestamp_of_location_estimate** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**positioning_data_list** | [**list_t**](positioning_method_and_usage.md) \* |  | [optional] 
**gnss_positioning_data_list** | [**list_t**](gnss_positioning_method_and_usage.md) \* |  | [optional] 
**accuracy_fulfilment_indicator** | **accuracy_fulfilment_indicator_t \*** |  | [optional] 
**ue_velocity** | [**velocity_estimate_t**](velocity_estimate.md) \* |  | [optional] 
**ldr_reference** | **char \*** | LDR Reference. | [optional] 
**altitude** | **double** | Indicates value of altitude. | [optional] 
**serving_lmf_identification** | **char \*** | LMF identification. | [optional] 
**location_privacy_ver_result** | [**location_privacy_ver_result_t**](location_privacy_ver_result.md) \* |  | [optional] 
**success_type** | **success_type_t \*** |  | [optional] 
**achieved_qos** | [**minor_location_qo_s_t**](minor_location_qo_s.md) \* |  | [optional] 
**direct_report_ind** | **int** |  | [optional] [default to false]
**accepted_periodic_event_info** | [**periodic_event_info_t**](periodic_event_info.md) \* |  | [optional] 
**ha_gnss_metrics** | [**high_accuracy_gnss_metrics_t**](high_accuracy_gnss_metrics.md) \* |  | [optional] 
**los_nlos_measure_ind** | **los_nlos_measure_ind_t \*** |  | [optional] 
**indoor_outdoor_ind** | **indoor_outdoor_ind_t \*** |  | [optional] 
**related_applicationlayer_id** | **char \*** | String identifying an UE with application layer ID. The format of the application  layer ID parameter is same as the Application layer ID defined in clause 11.3.4 of  3GPP TS 24.554.  | [optional] 
**distance_direction** | [**range_direction_t**](range_direction.md) \* |  | [optional] 
**_2d_relative_location** | [**model_2_d_relative_location_t**](model_2_d_relative_location.md) \* |  | [optional] 
**_3d_relative_location** | [**model_3_d_relative_location_t**](model_3_d_relative_location.md) \* |  | [optional] 
**relative_velocity** | [**velocity_estimate_t**](velocity_estimate.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


