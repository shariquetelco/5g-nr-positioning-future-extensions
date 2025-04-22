#!/bin/sh

# (1) Mount pseudo filesystems
mount -t proc proc /proc
mount -t sysfs sysfs /sys
mount -o rw,remount /

# (2) Initialize network interface
ifconfig eth0 192.168.3.2
ifconfig eth0 netmask 255.255.255.0

# (3) Load required kernel modules
modprobe sctp
insmod /lib/modules/ecid-params.ko

# (4) Set date and time of the system
date -s "2024-08-09 10:00:00"

# (5) Network tuning within the Linux kernel
echo 4096 > /proc/sys/net/core/somaxconn
echo 65536 > /proc/sys/net/core/netdev_max_backlog
echo 0 > /proc/sys/net/ipv4/tcp_slow_start_after_idle
echo 65536 > /proc/sys/net/ipv4/tcp_max_syn_backlog
echo 0 > /proc/sys/net/ipv4/tcp_syncookies
echo 16777216 > /proc/sys/net/core/rmem_max
echo 16777216 > /proc/sys/net/core/wmem_max
echo 16777216 > /proc/sys/net/core/rmem_default
echo 16777216 > /proc/sys/net/core/wmem_default
echo 40960 > /proc/sys/net/core/optmem_max

# (6) CPU frequency scaling
echo performance > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
echo performance > /sys/devices/system/cpu/cpu1/cpufreq/scaling_governor
echo performance > /sys/devices/system/cpu/cpu2/cpufreq/scaling_governor
echo performance > /sys/devices/system/cpu/cpu3/cpufreq/scaling_governor

# (7) Disable RT throttling feature
echo -1 > /proc/sys/kernel/sched_rt_runtime_us
