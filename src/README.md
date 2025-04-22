## TLS Key + CERT generation (10 years)
openssl req -x509 -newkey rsa:4096 -keyout key.pem -out cert.pem -sha256 -days 3650

- PEM passphrase: password for using key and cert files
- common name: domain for the server -> add to /etc/hosts for IP mapping

## Decoding of HTTPS traffic with Wireshark
1. Create SSL log file: touch ~/.ssl-key.log
2. Set environment variable SSLKEYLOGFILE: export SSLKEYLOGFILE=~/.ssl-key.log
3. Start client in the same shell (because environment variable is only temporarily set...) NOTE: log file is only written when libcurl or a suitable browser is used! (tested with libcurl)
4. Edit preferences in Wireshark: Preferences -> Protocols -> TLS -> Secret Log File <= add path to created log file .ssl-key.log 

## Current RSA keys and certificates
- AMF: amf.key, amf.crt (PEM pass phrase: 123456789, domain: amfd.5gc)
- LMF: lmf.key, lmf.crt (PEM pass phrase: 123456789, domain: lmfd.5gc)
