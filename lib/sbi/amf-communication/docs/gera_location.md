# gera_location_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**location_number** | **char \*** | Location number within the PLMN. See 3GPP TS 23.003, clause 4.5. | [optional] 
**cgi** | [**cell_global_id_t**](cell_global_id.md) \* |  | [optional] 
**sai** | [**service_area_id_t**](service_area_id.md) \* |  | [optional] 
**lai** | [**location_area_id_t**](location_area_id.md) \* |  | [optional] 
**rai** | [**routing_area_id_t**](routing_area_id.md) \* |  | [optional] 
**vlr_number** | **char \*** | VLR number. See 3GPP TS 23.003 clause 5.1. | [optional] 
**msc_number** | **char \*** | MSC number. See 3GPP TS 23.003 clause 5.1. | [optional] 
**age_of_location_information** | **int** | The value represents the elapsed time in minutes since the last network contact of the mobile station. Value \&quot;0\&quot; indicates that the location information was obtained after a successful paging procedure for  Active Location Retrieval when the UE is in idle mode or after a successful location reporting procedure the UE is in connected mode. Any other value than \&quot;0\&quot; indicates that the location information is the last known one. See 3GPP TS 29.002 clause 17.7.8.  | [optional] 
**ue_location_timestamp** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**geographical_information** | **char \*** | Refer to geographical Information.See 3GPP TS 23.032 clause 7.3.2. Only the description of an ellipsoid point with uncertainty circle is allowed to be used.  | [optional] 
**geodetic_information** | **char \*** | Refers to Calling Geodetic Location.See ITU-T Recommendation Q.763 (1999) clause 3.88.2.  Only the description of an ellipsoid point with uncertainty circle is allowed to be used.  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


