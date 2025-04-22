# loc_update_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**gpsi** | **char \*** | String identifying a Gpsi shall contain either an External Id or an MSISDN.  It shall be formatted as follows -External Identifier&#x3D; \&quot;extid-&#39;extid&#39;, where &#39;extid&#39;  shall be formatted according to clause 19.7.2 of 3GPP TS 23.003 that describes an  External Identifier.   | [optional] 
**supi** | **char \*** | String identifying a Supi that shall contain either an IMSI, a network specific identifier, a Global Cable Identifier (GCI) or a Global Line Identifier (GLI) as specified in clause  2.2A of 3GPP TS 23.003. It shall be formatted as follows  - for an IMSI \&quot;imsi-&lt;imsi&gt;\&quot;, where &lt;imsi&gt; shall be formatted according to clause 2.2    of 3GPP TS 23.003 that describes an IMSI.  - for a network specific identifier \&quot;nai-&lt;nai&gt;, where &lt;nai&gt; shall be formatted    according to clause 28.7.2 of 3GPP TS 23.003 that describes an NAI.  - for a GCI \&quot;gci-&lt;gci&gt;\&quot;, where &lt;gci&gt; shall be formatted according to clause 28.15.2    of 3GPP TS 23.003.  - for a GLI \&quot;gli-&lt;gli&gt;\&quot;, where &lt;gli&gt; shall be formatted according to clause 28.16.2 of    3GPP TS 23.003.To enable that the value is used as part of an URI, the string shall    only contain characters allowed according to the \&quot;lower-with-hyphen\&quot; naming convention    defined in 3GPP TS 29.501.  | [optional] 
**pseudonym_indicator** | **pseudonym_indicator_t \*** |  | [optional] 
**location_request_type** | **location_request_type_t \*** |  | 
**location_estimate** | [**geographic_area_t**](geographic_area.md) \* |  | 
**age_of_location_estimate** | **int** | Indicates value of the age of the location estimate. | 
**timestamp_of_location_estimate** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**accuracy_fulfilment_indicator** | **accuracy_fulfilment_indicator_t \*** |  | 
**civic_address** | [**civic_address_t**](civic_address.md) \* |  | [optional] 
**lcs_qos_class** | **lcs_qos_class_t \*** |  | 
**external_client_identification** | **char \*** | Contains the external client identification | [optional] 
**af_id** | **char \*** |  | [optional] 
**gmlc_number** | **char \*** |  | [optional] 
**lcs_service_type** | **int** | LCS Service Type Id. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


