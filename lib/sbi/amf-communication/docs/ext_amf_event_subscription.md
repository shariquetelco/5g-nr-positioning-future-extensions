# ext_amf_event_subscription_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**event_list** | [**list_t**](amf_event.md) \* |  | 
**event_notify_uri** | **char \*** | String providing an URI formatted according to RFC 3986. | 
**notify_correlation_id** | **char \*** |  | 
**nf_id** | **char \*** | String uniquely identifying a NF instance. The format of the NF Instance ID shall be a  Universally Unique Identifier (UUID) version 4, as described in IETF RFC 4122.   | 
**subs_change_notify_uri** | **char \*** | String providing an URI formatted according to RFC 3986. | [optional] 
**subs_change_notify_correlation_id** | **char \*** |  | [optional] 
**supi** | **char \*** | String identifying a Supi that shall contain either an IMSI, a network specific identifier, a Global Cable Identifier (GCI) or a Global Line Identifier (GLI) as specified in clause  2.2A of 3GPP TS 23.003. It shall be formatted as follows  - for an IMSI \&quot;imsi-&lt;imsi&gt;\&quot;, where &lt;imsi&gt; shall be formatted according to clause 2.2    of 3GPP TS 23.003 that describes an IMSI.  - for a network specific identifier \&quot;nai-&lt;nai&gt;, where &lt;nai&gt; shall be formatted    according to clause 28.7.2 of 3GPP TS 23.003 that describes an NAI.  - for a GCI \&quot;gci-&lt;gci&gt;\&quot;, where &lt;gci&gt; shall be formatted according to clause 28.15.2    of 3GPP TS 23.003.  - for a GLI \&quot;gli-&lt;gli&gt;\&quot;, where &lt;gli&gt; shall be formatted according to clause 28.16.2 of    3GPP TS 23.003.To enable that the value is used as part of an URI, the string shall    only contain characters allowed according to the \&quot;lower-with-hyphen\&quot; naming convention    defined in 3GPP TS 29.501.  | [optional] 
**group_id** | **char \*** | String identifying a group of devices network internal globally unique ID which identifies a set of IMSIs, as specified in clause 19.9 of 3GPP TS 23.003.   | [optional] 
**exclude_supi_list** | **list_t \*** |  | [optional] 
**exclude_gpsi_list** | **list_t \*** |  | [optional] 
**include_supi_list** | **list_t \*** |  | [optional] 
**include_gpsi_list** | **list_t \*** |  | [optional] 
**gpsi** | **char \*** | String identifying a Gpsi shall contain either an External Id or an MSISDN.  It shall be formatted as follows -External Identifier&#x3D; \&quot;extid-&#39;extid&#39;, where &#39;extid&#39;  shall be formatted according to clause 19.7.2 of 3GPP TS 23.003 that describes an  External Identifier.   | [optional] 
**pei** | **char \*** | String representing a Permanent Equipment Identifier that may contain - an IMEI or IMEISV, as  specified in clause 6.2 of 3GPP TS 23.003; a MAC address for a 5G-RG or FN-RG via  wireline  access, with an indication that this address cannot be trusted for regulatory purpose if this  address cannot be used as an Equipment Identifier of the FN-RG, as specified in clause 4.7.7  of 3GPP TS23.316. Examples are imei-012345678901234 or imeisv-0123456789012345.   | [optional] 
**any_ue** | **int** |  | [optional] 
**options** | [**amf_event_mode_t**](amf_event_mode.md) \* |  | [optional] 
**source_nf_type** | [**nf_type_t**](nf_type.md) \* |  | [optional] 
**term_notify_ind** | **int** |  | [optional] 
**binding_info** | **list_t \*** |  | [optional] 
**subscribing_nf_type** | [**nf_type_t**](nf_type.md) \* |  | [optional] 
**event_sync_ind** | **int** |  | [optional] 
**nf_consumer_info** | **list_t \*** |  | [optional] 
**aoi_state_list** | **list_t*** | Map of subscribed Area of Interest (AoI) Event State in the old AMF. The JSON pointer to an AmfEventArea element in the areaList IE (or a PresenceInfo element in  presenceInfoList IE) of the AmfEvent data type shall be the key of the map.  | [optional] 
**access_token** | **char \*** | JWS Compact Serialized representation of JWS signed JSON object (AccessTokenClaims  defined in 3GPP TS 29.510)  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


