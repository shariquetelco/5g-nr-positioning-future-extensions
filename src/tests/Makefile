CC=gcc
CFLAGS= -Wall -L ../../lib/
LDFLAGS= -lNRPPa -lnamf_communication -lcurl -lNGAP

httpCli:
	$(CC) -o cli $(CFLAGS) -I ../../include/asn1/ -I ../../include/nrppa/ -I ../../include/ngap/ -I ../../lib/ -I ../../lib/sbi/amf-communication/ httpCurl.c $(LDFLAGS)
