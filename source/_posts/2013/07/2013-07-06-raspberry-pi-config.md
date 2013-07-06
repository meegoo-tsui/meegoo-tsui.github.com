---
layout: post
title: "3. Raspberry pi config"
date: 2013-07-06 00:50
comments: true
categories: RaspberryPi
---

*	安装基本命令

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

SD卡兼容表： [http://elinux.org/RPi_SD_cards](http://elinux.org/RPi_SD_cards)
