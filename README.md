## NGAP-NRPPa Message Transfer (3GPP Release 18)
This repository contains a from-scratch implementation approach of a 5G positioning system exploring the New Radio Positioning Protocol Annex (NRPPa) and its performance in terms of time depending on the number of parallel NRPPa procedures, and the number of threads.
For this purpose, four different programs are provided:
1. ```lmfd```: Representing the Location Management Function (LMF) of the 5G core network. This program is responsible for handling location information using the NRPPa.
2. ```amfd```: Representing the Access and Mobility Management Function (AMF) of the 5G core network. This program is responsible to forward data from the core network, e.g. the LMF, to the radio access network, and vise versa.
3. ```gnb```: Representing the software component of a 5g Node B (gNB) that is part of the radio access network in a 5G standalone network.
4. ```init5g```: Representing the initialization system that is responsible for bringing up the previously mentioned programs. These programs are only neccesary if using the embedded Linux (see ```/embedded```).

## Required packages
In order to build the above mentioned programs (tested under Raspberry Pi OS Lite version that was released in July 5th, 2024), the following packages have to be installed:
- ```cmake```
- ```make```
- ```git```
- ```libsctp-dev```
- ```uuid-dev```
- ```libcurl4-openssl-dev```
- ```libssl-dev```
- ```build-essential```


Furthermore, the C library ```libnghttp2``` (tested with v1.62.1) also has to installed, e.g. building from source.

**Note:** If ```libnghttp2``` is build from source and installed under ```/usr/local``` then the older version has to be replaced. Please, check the target program dependencies, e.g. using ```ldd(1)``` to check, if the right version has been linked.

## Building programs
For the generation of the target programs, ```make``` is used directly. However, the self-developed libraries, e.g. NRPPa and NGAP handling, located in ```lib``` must be built first. Therefore, the following steps should be performed:
1. Switch to library directory: ```$ cd lib/```
2. Building of NGAP library: ```$ make libNGAP```
3. Building of NRPPa library: ```$ make libNRPPA```
4. Building of HTTP2 library: ```$ make libhttp2```
5. Building the Service-Based Interface (SBI) libraries for AMF and LMF: ```$ make libnamf_communication && make liblmf_location```

Afterwards, the built libraries should be moved to a destination where the linker will find them, e.g. ```/usr/local/lib``` and update the search path: ```$ cp ./*.so /usr/local/lib/ && sudo ldconfig``` .

Finally, the programs of the 5G positioning system can be built from source. To do this, please, perform the following steps:
1. Switch from the library to the source directory: ```$ cd ../src```
2. Build the target program, e.g. ```amfd``` by executing ```make```: ```$ make amfd```

**NOTE:** When a target program is built, different versions are usually generated. While for ```amfd```, ```lmfd```, and ```gnb``` also a real-time version is built (```-rt```), the initialization system ```init5g``` has four different versions depending on the target system (gNB or core network role) and the investigated NRPPa NR E-CID procedures (on-demand ```-init``` or periodical ```-rprt``` report messages).

## Setup of network interfaces
To be able to execute the ```amfd``` and ```lmfd``` implementations without errors, the hostnames (for SBI interfaces) have to be added to the system by editing ```/etc/hosts```. Depending on the used TLS certificates, e.g. the provided ones in the ```/src/tls``` directory of this repository, the following lines should be added:
```
127.0.2.1 amfd.5gc
127.0.3.1 lmfd.5gc
```
Then, the used TLS certificates have to be copied to th expected path:
```
$ sudo mkdir -p /etc/init5g/tls
$ sudo cp ./tls/* /etc/init5g/tls/
```
Due to the fact that the AMF is listing on two interfaces (SBI, N2), the IPv4 address of the N2 interface (macro ```N2_ADDR```) has to be modified manually in ```src/amf/amfd.h```.

## Installing Linux kernel module
Because the ```gNB``` program uses a Linux kernel driver for generating dummy NRPPa NR-ECID data, the driver that is located in ```src/kernel/ecid_params``` must be loaded. Therefore, the following steps should be performed:
1. Change the current directory: ```$ cd src/kernel/ecid_params```
2. Built kernel module from source (**tested with Linux v6.6.42**): ```$ make```
3. Loading kernel module to system: ```$ sudo insmod ecid-params.ko```

In order to allow programs to open the corresponding virtual device files after loading the driver (see: ```/dev/5g/...```) and ```udev(1)``` is installed, then a corresponding udev rule has to be set. Further instructions can be found [here](https://gitlab.uni-rostock.de/ed2328/5g-positioning-from-scratch-nrppa-over-ngap/-/blob/main/src/kernel/ecid_params/README.md).

## Execution on command line
The initialization system ```init5g``` can be used. Otherwise, the provided programs can also be executed manually on command line. For this purpose, three different terminals should be opened.