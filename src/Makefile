CC=gcc
CFLAGS= -g -L ../lib/ -O2 -DRESEARCH
LFLAGS= -lNGAP -lNRPPa

.PHONY: gnb
gnb:
	$(CC) -o gnb $(CFLAGS) -I ../include/asn1/ -I ../include/ngap/ -I ../include/nrppa/ -I ../lib/ -I ./kernel/ecid_params -I ./misc/ gNB/*.c misc/*.c -lasn1 -lprotoNGAP $(LFLAGS) -lpthread -lsctp
	$(CC) -o gnb-rt $(CFLAGS) -DRT -I ../include/asn1/ -I ../include/ngap/ -I ../include/nrppa/ -I ../lib/ -I ./kernel/ecid_params -I ./misc/ gNB/*.c misc/*.c -lasn1 -lprotoNGAP $(LFLAGS) -lpthread -lsctp


.PHONY: amfd
amfd:
	$(CC) -o amfd $(CFLAGS) -I ../include/asn1/ -I ../include/ngap/ -I ../include/nrppa/ -I ../lib/ -I ../lib/sbi/amf-communication/ -I ../lib/sbi/lmf-location/ -I ./misc/ -L ../lib/ amf/*.c misc/*.c -lhttp2 -lnghttp2 -lnamf_communication -llmf_location -lNGAP -lNRPPa -luuid -lpthread -lsctp -lcurl
	$(CC) -o amfd-rt $(CFLAGS) -DRT -I ../include/asn1/ -I ../include/ngap/ -I ../include/nrppa/ -I ../lib/ -I ../lib/sbi/amf-communication/ -I ../lib/sbi/lmf-location/ -I ./misc/ -L ../lib/ amf/*.c misc/*.c -lhttp2 -lnghttp2 -lnamf_communication -llmf_location -lNGAP -lNRPPa -luuid -lpthread -lsctp -lcurl

.PHONY: lmfd
lmfd:
	$(CC) -o lmfd $(CFLAGS) -I ../include/asn1/ -I ../include/ngap/ -I ../include/nrppa/ -I ../lib/ -I ../lib/sbi/amf-communication/ -I ../lib/sbi/lmf-location/ -I ./misc/ -L ../lib/ lmf/*.c misc/pthpool.c $(LFLAGS) -lhttp2 -lnghttp2 -lnamf_communication -llmf_location -luuid -lpthread -lcurl -luuid
	$(CC) -o lmfd-rt $(CFLAGS) -DRT -I ../include/asn1/ -I ../include/ngap/ -I ../include/nrppa/ -I ../lib/ -I ../lib/sbi/amf-communication/ -I ../lib/sbi/lmf-location/ -I ./misc/ -L ../lib/ lmf/*.c misc/pthpool.c $(LFLAGS) -lhttp2 -lnghttp2 -lnamf_communication -llmf_location -luuid -lpthread -lcurl -luuid

.PHONY: init5g
init5g:
	$(CC) -static -o init5g-core-init -Wall -DCORE -I ../include/ -I ../include/asn1/ -O2 init5g/*.c
	$(CC) -static -o init5g-core-rprt -Wall -DCORE -DREPORT -I ../include/ -I ../include/asn1/ -O2 init5g/*.c
	$(CC) -static -o init5g-gnb-init -Wall -O2 init5g/*.c
	$(CC) -static -o init5g-gnb-rprt -Wall -DREPORT -I ../include/ -I ../include/asn1/ -O2 init5g/*.c

test:
	$(CC) -o cli $(CFLAGS) -I ../include/asn1/ -I ../include/nrppa/ -I ../include/ngap/ -I ../lib/ -I ../lib/sbi/amf-communication/ httpCurl.c -lNRPPa -lnamf_communication -lcurl -lNGAP
