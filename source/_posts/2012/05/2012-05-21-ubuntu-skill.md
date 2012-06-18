---
layout: post
title: "ubuntu常见问题集锦"
date: 2012-05-21 13:11
comments: true
categories: linux
---

<!---
################################################################################
-->
<hr />
*    [ubuntu 源](#ubuntu_sources)
*    [静态IP](#static_ip)
*    [grub启动项](#grub_boot)

<!---
################################################################################
-->
<hr />
<h3 id="ubuntu_sources">ubuntu 源</h3>
先备份原始文件：    
	$ sudo cp /etc/apt/sources.list /etc/apt/sources.list.backup

以下面文件替换：    

*    ubuntu 10.04 - <a href='/downloads/config/ubuntu_10.04.sources.list' id='blog-link' title='Tar'>sources.list</a>	
*    ubuntu 12.04 - <a href='/downloads/config/ubuntu_12.04.sources.list' id='blog-link' title='Tar'>sources.list</a>	

消除ID警告：    
	sudo apt-key adv --keyserver keyserver.ubuntu.com --recv ID_xxxxxxxxx

运行命令更新：    
	$ sudo apt-get update
	$ sudo spt-get upgrade

### 修改更新错误 ###
### error 1 ###
E: Could not get lock /var/lib/apt/lists/lock - open (11: Resource temporarily unavailable)     
E: Unable to lock the list directory    
解决方法：     
	$ ps -e | grep apt
删除相关进程：    
	$ sudo kill xxxx

<!---
################################################################################
-->
<hr />
<h3 id="static_ip">静态IP - ubuntu 12.04 server</h3>
执行命令如下：

	sudo vi /etc/network/interfaces

替换：

	auto eth0
	iface eth0 inet dhcp

为：

	auto eth0
	iface eth0 inet static
		address 192.168.0.2
		netmask 255.255.255.0
		network 192.168.0.0
		broadcast 192.168.0.255
		gateway 192.168.0.1
		dns-nameservers 192.168.0.1

重启服务：

	sudo /etc/init.d/networking restart

<!---
################################################################################
-->
<hr />
<h3 id="grub_boot">grub启动项</h3>
执行命令如下：

	sudo vi /etc/default/grub

替换：

	GRUB_DEFAULT=0

为：

	GRUB_DEFAULT=4

使设置生效：

	sudo update-grub 

<hr />
