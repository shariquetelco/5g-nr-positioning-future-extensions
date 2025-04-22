# access_token_req_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**grant_type** | **lmf_location_access_token_req_GRANTTYPE_e** |  | 
**nf_instance_id** | **char \*** | String uniquely identifying a NF instance. The format of the NF Instance ID shall be a  Universally Unique Identifier (UUID) version 4, as described in IETF RFC 4122.   | 
**nf_type** | [**nf_type_t**](nf_type.md) \* |  | [optional] 
**target_nf_type** | [**nf_type_t**](nf_type.md) \* |  | [optional] 
**scope** | **char \*** |  | 
**target_nf_instance_id** | **char \*** | String uniquely identifying a NF instance. The format of the NF Instance ID shall be a  Universally Unique Identifier (UUID) version 4, as described in IETF RFC 4122.   | [optional] 
**requester_plmn** | [**plmn_id_t**](plmn_id.md) \* |  | [optional] 
**requester_plmn_list** | [**list_t**](plmn_id.md) \* |  | [optional] 
**requester_snssai_list** | [**list_t**](snssai.md) \* |  | [optional] 
**requester_fqdn** | **char \*** | Fully Qualified Domain Name | [optional] 
**requester_snpn_list** | [**list_t**](plmn_id_nid.md) \* |  | [optional] 
**target_plmn** | [**plmn_id_t**](plmn_id.md) \* |  | [optional] 
**target_snpn** | [**plmn_id_nid_t**](plmn_id_nid.md) \* |  | [optional] 
**target_snssai_list** | [**list_t**](snssai.md) \* |  | [optional] 
**target_nsi_list** | **list_t \*** |  | [optional] 
**target_nf_set_id** | **char \*** | NF Set Identifier (see clause 28.12 of 3GPP TS 23.003), formatted as the following string \&quot;set&lt;Set ID&gt;.&lt;nftype&gt;set.5gc.mnc&lt;MNC&gt;.mcc&lt;MCC&gt;\&quot;, or  \&quot;set&lt;SetID&gt;.&lt;NFType&gt;set.5gc.nid&lt;NID&gt;.mnc&lt;MNC&gt;.mcc&lt;MCC&gt;\&quot; with  &lt;MCC&gt; encoded as defined in clause 5.4.2 (\&quot;Mcc\&quot; data type definition)  &lt;MNC&gt; encoding the Mobile Network Code part of the PLMN, comprising 3 digits.    If there are only 2 significant digits in the MNC, one \&quot;0\&quot; digit shall be inserted    at the left side to fill the 3 digits coding of MNC.  Pattern: &#39;^[0-9]{3}$&#39; &lt;NFType&gt; encoded as a value defined in Table 6.1.6.3.3-1 of 3GPP TS 29.510 but    with lower case characters &lt;Set ID&gt; encoded as a string of characters consisting of    alphabetic characters (A-Z and a-z), digits (0-9) and/or the hyphen (-) and that    shall end with either an alphabetic character or a digit.   | [optional] 
**target_nf_service_set_id** | **char \*** | NF Service Set Identifier (see clause 28.12 of 3GPP TS 23.003) formatted as the following  string \&quot;set&lt;Set ID&gt;.sn&lt;Service Name&gt;.nfi&lt;NF Instance ID&gt;.5gc.mnc&lt;MNC&gt;.mcc&lt;MCC&gt;\&quot;, or  \&quot;set&lt;SetID&gt;.sn&lt;ServiceName&gt;.nfi&lt;NFInstanceID&gt;.5gc.nid&lt;NID&gt;.mnc&lt;MNC&gt;.mcc&lt;MCC&gt;\&quot; with  &lt;MCC&gt; encoded as defined in clause 5.4.2 (\&quot;Mcc\&quot; data type definition)   &lt;MNC&gt; encoding the Mobile Network Code part of the PLMN, comprising 3 digits.    If there are only 2 significant digits in the MNC, one \&quot;0\&quot; digit shall be inserted    at the left side to fill the 3 digits coding of MNC.  Pattern: &#39;^[0-9]{3}$&#39; &lt;NID&gt; encoded as defined in clause 5.4.2 (\&quot;Nid\&quot; data type definition)  &lt;NFInstanceId&gt; encoded as defined in clause 5.3.2  &lt;ServiceName&gt; encoded as defined in 3GPP TS 29.510  &lt;Set ID&gt; encoded as a string of characters consisting of alphabetic    characters (A-Z and a-z), digits (0-9) and/or the hyphen (-) and that shall end    with either an alphabetic character or a digit.  | [optional] 
**hnrf_access_token_uri** | **char \*** | String providing an URI formatted according to RFC 3986. | [optional] 
**source_nf_instance_id** | **char \*** | String uniquely identifying a NF instance. The format of the NF Instance ID shall be a  Universally Unique Identifier (UUID) version 4, as described in IETF RFC 4122.   | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


