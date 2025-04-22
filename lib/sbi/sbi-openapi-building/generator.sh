#!/bin/bash

export C_POST_PROCESS_FILE="/usr/bin/uncrustify --no-backup"
export UNCRUSTIFY_CONFIG="./configs/uncrustify-rules.cfg"

openapi_generator_cli="openapi-generator-cli"

#$openapi_generator_cli generate -i ./standard-sbi/TS29518_Namf_Communication.yaml -c ./configs/config.yaml -g c -o ./amf-communication || exit 1
#$openapi_generator_cli generate -i ./standard-sbi/TS29572_Nlmf_Location.yaml -c ./configs/config.yaml -g c -o ./lmf-location || exit 1
#$openapi_generator_cli generate -i ./standard-sbi/TS29572_Nlmf_Broadcast.yaml -c ./configs/config.yaml -g c -o ./lmf-broadcast || exit 1
$openapi_generator_cli generate -i ./standard-sbi/TS29515_Ngmlc_Location.yaml -c ./configs/config.yaml -g c -o ./gmlc-location || exit 1
