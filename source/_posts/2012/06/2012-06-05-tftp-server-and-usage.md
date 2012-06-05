---
layout: post
title: "tftp服务器安装及用法"
date: 2012-06-05 13:56
comments: true
categories: server
---

系统环境： ubuntu10.04

*    [tftp服务器安装](#install)
*    [tftp服务器使用](#usage)

<!---
################################################################################
-->
<hr />
<h3 id="install">tftp服务器安装</h3>
### 1. 安装软件包 ####
	sudo apt-get install tftpd tftp xinetd
### 2. 修改配置文件 ###
	sudo vim /etc/xinetd.d/tftp
添加内容如下：    
	service tftp
	{
		socket_type = dgram
		protocol = udp
		wait = yes
		user = root
		server = /usr/sbin/in.tftpd
		server_args = -s /tftpboot
		disable = no
		per_source = 11
		cps = 100 2
		flags = IPv4
	} 
配置文件生效：   
	sudo chmod ugo+rwx /tftpboot
	sudo /etc/init.d/xinetd restart 

<!---
################################################################################
-->
<hr />
<h3 id="usage">tftp服务器使用</h3>
### 1. 显示帮助信息 ###
	meegoo@lenovo:~$ tftp
	tftp> ?
	Commands may be abbreviated.  Commands are:
	
	connect 	connect to remote tftp
	mode    	set file transfer mode
	put     	send file
	get     	receive file
	quit    	exit tftp
	verbose 	toggle verbose mode
	trace   	toggle packet tracing
	status  	show current status
	binary  	set mode to octet
	ascii   	set mode to netascii
	rexmt   	set per-packet retransmission timeout
	timeout 	set total retransmission timeout
	?       	print help information
	tftp>

### 2. 常见用法 ###
	tftp> connect 192.168.0.238
	tftp> binary    
	tftp> get uImage
	Received 2144888 bytes in 0.1 seconds
	tftp>

