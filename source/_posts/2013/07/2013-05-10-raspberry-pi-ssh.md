---
layout: post
title: "Raspberry pi ssh"
date: 2013-07-05 21:23
comments: true
categories: RaspberryPi
---

{% img http://www.raspberrypi.org/wp-content/themes/raspite/img/PiOrg-Site-Sidebar-003.gif %}

[http://www.raspberrypi.org/](http://www.raspberrypi.org/)

*	使能路由器hdcp功能，查看raspberry pi的ip地址，且ping成功
*	ssh登录raspberry pi, Username: pi Password: raspberry

登录过程如下：    
	meegoo@mg:~$ ssh pi@192.168.1.60
	ssh_exchange_identification: read: Connection reset by peer

	meegoo@mg:~$ ssh pi@192.168.1.60

	Linux raspberrypi 3.6.11+ #456 PREEMPT Mon May 20 17:42:15 BST 2013 armv6l

	The programs included with the Debian GNU/Linux system are free software;
	the exact distribution terms for each program are described in the
	individual files in /usr/share/doc/*/copyright.

	Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
	permitted by applicable law.

	NOTICE: the software on this Raspberry Pi has not been fully configured. Please run 'sudo raspi-config'

	pi@raspberrypi ~ $ 

*	配置raspberry pi

结果如下：    
	pi@raspberrypi ~ $ sudo raspi-config
                                                                                                                     
	┌────────────────────────────┤ Raspberry Pi Software Configuration Tool (raspi-config) ├────────────────────────────┐
	│ Setup Options                                                                                                     │
	│                                                                                                                   │
	│        1 Expand Filesystem            Ensures that all of the SD card storage is available to the OS              │
	│        2 Change User Password         Change password for the default user (pi)                                   │
	│        3 Enable Boot to Desktop       Choose whether to boot into a desktop environment or the command-line       │
	│        4 Internationalisation Options Set up language and regional settings to match your location                │
	│        5 Enable Camera                Enable this Pi to work with the Raspberry Pi Camera                         │
	│        6 Add to Rastrack              Add this Pi to the online Raspberry Pi Map (Rastrack)                       │
	│        7 Overclock                    Configure overclocking for your Pi                                          │
	│        8 Advanced Options             Configure advanced settings                                                 │
	│        9 About raspi-config           Information about this configuration tool                                   │
	│                                                                                                                   │
	│                                                                                                                   │
	│                                 <Select>                                 <Finish>                                 │
	│                                                                                                                   │
	└───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

                                                                                                     
