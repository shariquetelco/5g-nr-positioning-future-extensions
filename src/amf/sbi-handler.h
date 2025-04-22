#ifndef _SBI_AMF_HANDLER_
#define _SBI_AMF_HANDLER_

#include "amfd.h"

/*
 * Forward declaration
 *
 * implemented in: amf-callbacks.c
 */
int send_response(nghttp2_session *session, int32_t stream_id, nghttp2_nv *nva, size_t nvlen, nghttp2_data_provider2 *data_prd);
int error_response(nghttp2_session *session, http2_stream_data *stream_data, int err, char *cause);

/*
 * Callback function to send JSON data
 */
nghttp2_ssize json_read_callback(nghttp2_session *session, int32_t stream_id, uint8_t *buf, size_t length, uint32_t *data_flags, nghttp2_data_source *source, void *user_data);

/*
 * SBI handler functions
 *
 * Working principle: parsing and interpretation of request payload data, generation and sending of HTTP response
 * ... in error cases: return -1 if an INTERNAL SERVER ERROR occurs (e.g. not enough memory available), 0 otherwise (because sending response is realized in SBI handler itself!)
 */
int namf_comm_n1n2msgtransfer(nghttp2_session *session, http2_stream_data *stream_data, rentry_t *entry);
int namf_comm_n1n2msgsubscribe(nghttp2_session *session, http2_stream_data *stream_data, rentry_t *entry);
int namf_comm_n1n2msgunsubscribe(nghttp2_session *session, http2_stream_data *stream_data, rentry_t *entry, char *subid);

#endif
