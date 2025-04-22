## NGAP-NRPPa Message Transfer according to 3GPP Release 18

## Installation: Required packages
If this 5G system is tested under Raspberry Pi OS (tested with Lite version that was released in July 5th, 2024), the following packages has to be installed:
- cmake
- git
- libsctp-dev
- uuid-dev
- libcurl4-openssl-dev

Furthermore, the C library libnghttp2 (tested with v1.62.1) also has to installed, e.g. building from source.

**Caution:** If libnghttp2 is build from source and installed under /usr/local then the older version has to be replaced. Please, check the build NFs dependencies, e.g. using ldd(1) to check, if the right version was linked.
