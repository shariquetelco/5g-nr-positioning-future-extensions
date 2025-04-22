## libhttp2 notes
- tested with libnghttp2 v1.61.0 (if version > 1.61 it could be give problems with compilation if gcc 11 or 12 is used)
- ldconfig(1) should be executed so that the libhttp2 library can be found.
- libnghttp2 (v1.61.0) dependencies:
	- libssl
	- libcrypto
	- libxml2
	- libev
	- libcares
	- libevent_openssl
	- libevent
	- libjansson
	- libjemalloc
	- libz
	- libsystemd
	- + third-party http-parser

## basic principle
1. 5G NF (e.g. AMF) has to be dynamically linked with the libhttp2 library that provides the start_http2server() function.
2. The NF has to define two callback functions (examples in main_callbacks.c):
	- on_header_callback(): parsing HTTP/2 request HEADERS frame
	- on_frame_recv_callback(): processing HTTP/2 DATA frame content (e.g. sent data (HTTP body) from client) + sending response to client
3. Both callback functions are passed to start_http2_server() together with the server address (IPv4 and port), the NF RSA key file and the NF TLS certificate (both located in /src/tls) 
4. The NF consumer has to use the corresponding server TLS certifiacte to establish a HTTP/2 connection based on TLS/ALPN.

The source code of the libhttp2 library was adopted from the libnghttp2 source code example libevent-server.c (see https://nghttp2.org/documentation/tutorial-server.html) and was modified for this project.
