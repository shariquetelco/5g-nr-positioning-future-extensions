CC=gcc
CFLAGS= -shared -fPIC -Wall -g
LFLAGS= -lasn1

# ASN.1 and Protocol Libraries
libasn1:
	$(CC) $(CFLAGS) -o libasn1.so -I ../include/asn1/ ../include/asn1/*.c

libprotoNGAP: libasn1
	$(CC) $(CFLAGS) -o libprotoNGAP.so -I ../include/asn1/ -I ../include/ngap/ -L ./ ../include/ngap/*.c $(LFLAGS)

libprotoNRPPa: libasn1
	$(CC) $(CFLAGS) -o libprotoNRPPa.so -I ../include/asn1/ -I ../include/nrppa/ -L ./ ../include/nrppa/*.c $(LFLAGS)

libNGAP: libasn1 libprotoNGAP
	$(CC) $(CFLAGS) -o libNGAP.so -I ../include/asn1/ -I ../include/ngap/ -I ngap/ -L ./ ngap/*.c $(LFLAGS) -lprotoNGAP

libNRPPA: libasn1 libprotoNRPPa
	$(CC) $(CFLAGS) -o libNRPPa.so -I ../include/asn1/ -I ../include/nrppa/ -I nrppa/ -L ./ nrppa/*.c $(LFLAGS) -lprotoNRPPa

# OpenAPI HTTPS SBI Client Libraries
libnamf_communication:
	make -C ./sbi/amf-communication install
	chmod +x ./libnamf_communication.so

liblmf_location:
	make -C ./sbi/lmf-location install
	chmod +x ./liblmf_location.so

liblmf_broadcast:
	make -C ./sbi/lmf-broadcast install
	chmod +x ./liblmf_broadcast.so

libngmlc_location:
	make -C ./sbi/gmlc-location install
	chmod +x ./libngmlc_location.so

# HTTP/2 Library
libhttp2:
	make -C ./http2 libhttp2


# clean up everything
clean:
	-rm *.so
	-make -C ./sbi/amf-communication clean
	-make -C ./sbi/lmf-location clean
	-make -C ./sbi/lmf-broadcast clean
	-make -C ./sbi/gmlc-location clean
