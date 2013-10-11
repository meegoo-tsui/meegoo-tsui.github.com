---
layout: post
title: "1. Raspberry pi install"
date: 2013-07-05 20:23
comments: true
categories: RaspberryPi
---

{% img http://www.raspberrypi.org/wp-content/themes/raspite/img/PiOrg-Site-Sidebar-003.gif %}

[http://www.raspberrypi.org/](http://www.raspberrypi.org/)

*	安装版本[Raspbian “wheezy”](http://www.raspberrypi.org/downloads)

下载安装包，当前版本为2013-05-25-wheezy-raspbian.zip，然后解压得到文件2013-05-25-wheezy-raspbian.img。

*	插上SD卡，运行 `df -h` 查看挂在设备且移除

运行如下：    
	meegoo@mg:meegoo-tsui.github.com.git$ df -h
	Filesystem      Size  Used Avail Use% Mounted on
	/dev/sdb1       3.7G   19M  3.7G   1% /media/boot
	
	meegoo@mg:meegoo-tsui.github.com.git$ umount /dev/sdb1
	meegoo@mg:meegoo-tsui.github.com.git$ umount /dev/sdb2
	...

*	使用`dd`写镜像到SD卡

运行如下：    
	meegoo@mg:~$ sudo dd bs=1M if=./2013-05-25-wheezy-raspbian.img of=/dev/sdb
	1850+0 records in
	1850+0 records out
	1939865600 bytes (1.9 GB) copied, 300.62 s, 6.5 MB/s

	meegoo@mg:meegoo-tsui.github.com.git$ sudo sync

*	使用`dd`读取SD卡备份镜像

运行如下：    
	meegoo@mg:~$ sudo dd bs=1M if=/dev/sdb | gzip > ./`date +%Y-%m-%d`_wheezy-raspbian.gz

至此完成镜像的安装，拔出SD卡，插入raspberry pi。

{% img http://images.weiphone.com/attachments/Day_130504/0_3600269_a9f76102b632c5a.jpg %}

