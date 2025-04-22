#!/bin/sh

# (1) Mount pseudo filesystems
mount -t proc none /proc
mount -t sysfs none /sys
#mount -t devpts none /dev/pts

# (2) Initialize network interfaces
ifconfig eth0 192.168.3.1
ifconfig eth0 netmask 255.255.255.0
ifconfig lo 127.0.0.1

# (3) Load required kernel modules
modprobe sctp
modprobe pwm_fan
insmod /lib/modules/ecid-params.ko
