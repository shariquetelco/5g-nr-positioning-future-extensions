# trace_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**trace_ref** | **char \*** | Trace Reference (see 3GPP TS 32.422).It shall be encoded as the concatenation of MCC, MNC and Trace ID as follows: &lt;MCC&gt;&lt;MNC&gt;-&lt;Trace ID&gt; The Trace ID shall be encoded as a 3 octet string in hexadecimal representation. Each character in the Trace ID string shall take a value of \&quot;0\&quot; to \&quot;9\&quot;, \&quot;a\&quot; to \&quot;f\&quot; or \&quot;A\&quot; to \&quot;F\&quot; and shall represent 4 bits. The most significant character representing the 4 most significant bits of the Trace ID shall appear first in the string, and the character representing the 4 least significant bit of the Trace ID shall appear last in the string.  | 
**trace_depth** | [**trace_depth_t**](trace_depth.md) \* |  | 
**ne_type_list** | **char \*** | List of NE Types (see 3GPP TS 32.422). It shall be encoded as an octet string in hexadecimal representation. Each character in the string shall take a value of \&quot;0\&quot; to \&quot;9\&quot;, \&quot;a\&quot; to \&quot;f\&quot; or \&quot;A\&quot; to \&quot;F\&quot; and shall represent 4 bits. The most significant character representing the 4 most significant bits shall appear first in the string, and the character representing the 4 least significant bit shall appear last in the string. Octets shall be coded according to 3GPP TS 32.422.  | 
**event_list** | **char \*** | Triggering events (see 3GPP TS 32.422). It shall be encoded as an octet string in hexadecimal representation. Each character in the string shall take a value of \&quot;0\&quot; to \&quot;9\&quot;, \&quot;a\&quot; to \&quot;f\&quot; or \&quot;A\&quot; to \&quot;F\&quot; and shall represent 4 bits. The most significant character representing the 4 most significant bits shall appear first in the string, and the character representing the 4 least significant bit shall appear last in the string. Octets shall be coded according to 3GPP TS 32.422.  | 
**collection_entity_ipv4_addr** | **char \*** | String identifying a IPv4 address formatted in the &#39;dotted decimal&#39; notation as defined in RFC 1166.  | [optional] 
**collection_entity_ipv6_addr** | [**ipv6_addr_t**](ipv6_addr.md) \* |  | [optional] 
**trace_reporting_consumer_uri** | **char \*** | String providing an URI formatted according to RFC 3986. | [optional] 
**interface_list** | **char \*** | List of Interfaces (see 3GPP TS 32.422). It shall be encoded as an octet string in hexadecimal representation. Each character in the string shall take a value of \&quot;0\&quot; to \&quot;9\&quot;, \&quot;a\&quot; to \&quot;f\&quot; or \&quot;A\&quot; to \&quot;F\&quot; and shall represent 4 bits. The most significant character representing the 4 most significant bits shall appear first in the string, and the character representing the  4 least significant bit shall appear last in the string. Octets shall be coded according to 3GPP TS 32.422. If this attribute is not present, all the interfaces applicable to the list of NE types indicated in the neTypeList attribute should be traced.  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


