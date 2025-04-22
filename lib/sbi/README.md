## Note for building of SBI HTTPS Client API libraries

- required programs:
	- curl v7.58.0+
	- uncrustify v0.67+
	- default-jdk
	- nodejs
	- openapi-generator-cli v6.4.0
	=> installation guide adopted from Open5GS is placed in sbi-openapi-building/README.md

- It seems that the OpenAPI 3GPP specifications (or the generator) has problems with the "anyOf" instruction. Therefore, these instructions were commented out in context with enumerations in every used OpenAPI 3GPP specification. See e.g. sbi-openapi-building/sbi-standard/TS29518_Namf_Communication.yaml!
- BUT: Possible workaround tested in ngmlc_location: model/reporting_ind.h -> insert corresponding enumeration in structure -> the string convertion can be done by the enum method :-)

- The generator templates were adopted from the Open5GS source code (https://github.com/open5gs/open5gs) and modified for this project.

- For building: $ ./sbi-openapi-building/generator.sh
