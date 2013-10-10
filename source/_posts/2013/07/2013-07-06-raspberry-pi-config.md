---
layout: post
title: "3. Raspberry pi config"
date: 2013-07-06 00:50
comments: true
categories: RaspberryPi
---

*	安装基本命令

To config apt-get software    
	pi@raspberrypi ~ $ cat  /etc/apt/sources.list
	deb http://mirrors.tuna.tsinghua.edu.cn/raspbian/raspbian/ wheezy main contrib non-free rpi
	
To install a package where you already know the name    
	sudo apt-get install <name of software>

To search for software by name    
	sudo apt-cache search <key word for search>

To update the repository database on your Rpi    
	sudo apt-get update

To uninstall a previously installed package    
	sudo apt-get remove <name of software to remove>

To update all current packages with the latest version    
	sudo apt-get upgrade

执行：    
	sudo apt-get update
	sudo apt-get upgrade

*	local配置

执行：    
	sudo apt-get install locales
	export LANGUAGE='en_US'
	export LC_ALL="en_US.UTF-8"
	sudo dpkg-reconfigure locales

*	IP配置

修改文件：    
	pi@raspberrypi ~ $ cat /etc/network/interfaces
	auto lo
	iface lo inet loopback
	auto eth0
	iface eth0 inet static
	address 192.168.55.111  
	gateway 192.168.55.1
	netmask 255.255.255.0
	allow-hotplug wlan0
	iface wlan0 inet manual
	wpa-roam /etc/wpa_supplicant/wpa_supplicant.conf
	iface default inet dhcp

*	备份 - buildsys.git/shell/rpi-clone

运行：    
	$ git clone https://github.com/billw2/rpi-clone.git 
	$ cd rpi-clone
	$ cp rpi-clone /usr/local/sbin

修改文件：    


SD卡兼容表： [http://elinux.org/RPi_SD_cards](http://elinux.org/RPi_SD_cards)
