## udev usage
- Get meta information of a certain device file: udevadm info -q all -a /dev/TARGET_FILE
- Create udev rule, e.g. in /etc/udev/rules.d/33-nrecid.rules to change access of the target device file:
	SUBSYSTEM=="nr_ecid", GROUP="dialout", MODE="0660"
- Set owner to root:root and change permissions to 0644.

- Insert the device driver module into the kernel using, e.g. insmod(1).	

- further reading: https://unix.stackexchange.com/questions/111593/allow-non-root-user-to-read-write-dev-files

## printk logging
- syslog is not used anymore. Instead, journalctl(1) can be used to see printk debug outputs:
	journalctl -f -n20
