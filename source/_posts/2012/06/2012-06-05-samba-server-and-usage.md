---
layout: post
title: "samba服务器安装及用法"
date: 2012-06-05 13:56
comments: true
categories: server
---

系统环境： ubuntu10.04

*    [samba服务器安装](#install)
*    [samba服务器使用](#usage)

<!---
################################################################################
-->
<hr />
<h3 id="install">samba服务器安装</h3>
### 1. 安装软件包 ####
	sudo apt-get install samba samba-common samba-common-bin system-config-samba
### 2. 运行 ###
	sudo smbd start
### 3. 图形界面配置 ###
	sudo system-config-samba
### 4. 命令行配置 ###
修改配置文件：    
	sudo gedit /etc/samba/smb.conf
修改内容如下：   
	####### Authentication #######
	
	# “security = user” is always a good idea. This will require a Unix account
	# in this server for every user accessing the server. See
	# /usr/share/doc/samba-doc/htmldocs/Samba-HOWTO-Collection/ServerType.html
	# in the samba-doc package for details.
	;  security = user
修改为：    
	security = user
	username map = /etc/samba/smbusers
添加samba用户：    
	sudo smbpasswd -a meegoo
添加到samba用户文件，格式为`<ubuntuusername> = “<samba username>”`    
	sudo gedit /etc/samba/smbusers

### 5. 添加samba共享路径 ###
修改配置文件：    
	sudo gedit /etc/samba/smb.conf
文件尾添加内容如下：    
	[meegoo]
		path = /home/meegoo
		writeable = yes
	;	browseable = yes
		valid users = meegoo 
开始或重启samba服务：    
	sudo smbd start
	sudo smbd restart

<!---
################################################################################
-->
<hr />
<h3 id="usage">samba服务器使用</h3>
### 1. 安装smbfs ###
	sudo apt-get install smbfs

### 2. 挂载samba ###
	sudo mkdir /mnt/samba
	sudo mount -t smbfs -o username=meegoo //192.168.0.238/meegoo /mnt/samba

