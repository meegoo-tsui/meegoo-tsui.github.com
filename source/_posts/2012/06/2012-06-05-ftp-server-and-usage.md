---
layout: post
title: "ftp服务器安装及用法"
date: 2012-06-05 13:56
comments: true
categories: server
---

系统环境： ubuntu10.04

*    [ftp服务器安装](#install)
*    [ftp服务器使用](#usage)

<!---
################################################################################
-->
<hr />
<h3 id="install">ftp服务器安装</h3>
### 1. 安装软件包 ####
	sudo apt-get install vsftpd
### 2. 创建ftp文件夹 ###
	sudo mkdir /home/ftp
	sudo usermod -d /home/ftp ftp
### 3. ftp操作 ###
	sudo /etc/init.d/vsftpd start
	sudo /etc/init.d/vsftpd restart
	sudo /etc/init.d/vsftpd stop
### 4. 修改配置文件 ###
	sudo gedit /etc/vsftpd.conf
内容如下：    
	local_umask=022
	anon_umask=000
	anonymous_enable=YES
	write_enable=YES
	anon_world_readable_only=NO
	anon_other_write_enable=YES
	anon_upload_enable=YES
	anon_mkdir_write_enable=YES 

<!---
################################################################################
-->
<hr />
<h3 id="usage">ftp服务器使用</h3>
### 1. 连接 ###
	meegoo@lenovo:~$ ftp 192.168.0.238
	Connected to 192.168.0.238.
	220 (vsFTPd 2.2.2)
	Name (192.168.0.238:meegoo): anonymous
	331 Please specify the password.
	Password:
	230 Login successful.
	Remote system type is UNIX.
	Using binary mode to transfer files.

### 2. 帮助信息 ###
	ftp> ?
	Commands may be abbreviated.  Commands are:
	
	!		    debug		mdir		qc		    send
	$		    dir		    mget		sendport	site
	account		disconnect	mkdir		put		    size
	append		exit		mls		    pwd		    status
	ascii		form		mode		quit		struct
	bell		get		    modtime		quote		system
	binary		glob		mput		recv		sunique
	bye		    hash		newer		reget		tenex
	case		help		nmap		rstatus		tick
	cd		    idle		nlist		rhelp		trace
	cdup		image		ntrans		rename		type
	chmod		lcd		    open		reset		user
	close		ls		    prompt		restart		umask
	cr		    macdef		passive		rmdir		verbose
	delete		mdelete		proxy		runique		?

