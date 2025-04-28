#######################
# Directory Structure #
#######################

|
|-- ecid-rprt/ => contains recorded time measurement values for NR-ECID Measurement Report (periodical time interval metric)
|	|
|	|-- rt/ => measurements that are recorded with real-time priority
|	|    |
|	|    |-- raw/ => recorded raw data
|	|    |    |-- ...
|	|    |
|	|    |-- analysis.m => MATLAB script to calculate the statistical parameters using the recorded raw data
|	|    |-- res_rprt_XX_YY_pZ.csv => interim results (after usage of analysis.m) for XX parallel procedures, with thread pool size YY, and period Z
|	|   
|	|-- normal/ => measurements that are recorded without real-time priority
|	     |
|	     |-- raw/
|	     | ... => similar structure and meaning as in /ecid-rprt/rt
|
|-- ecid-init/ => contains recorded time measurement values for NR-ECID Measurement Request/Response (round trip time metric)
|	|
|	|-- rt/ => same structure as in /ecid-rprt/rt; contents are similar, but without period value ;-)
|	|
|	|-- normal/ => same structure as in /ecid-rprt/normal; contents are similar, but without period value ;-)
|
|-- res_init_XX-ZZ.csv => final statistical results of NRPPa NR-ECID Measurement (on-demand) time measurements that are used in the corresponding journal article (XX-ZZ = number of parallel procedures).
|-- res_rprt_YYY.csv => final statistical results of NRPPa NR-ECID Measurement Report (periodically) time measurements that are used in the corresponding journal article (YYY = period in milliseconds).
