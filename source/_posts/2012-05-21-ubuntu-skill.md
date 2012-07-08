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
*    [MTA延时解决](#mta_delay)
*    [firefox flash插件](#firefox_flash)
*    [远程桌面](#remote_desktop)
*    [ramdisk](#ramdisk)
*    [firefox cache](#firefox_cache)
*    [ibus 消失](#ibus_repaire)

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

<!---
################################################################################
-->
<hr />
<h3 id="mta_delay">MTA延时解决</h3>
修改文件：

	sudo vim /etc/hosts

修改内容如下：

	127.0.0.1       localhost.localdomain localhost
	127.0.1.1       server.localdomain server

<!---
################################################################################
-->
<hr />
<h3 id="firefox_flash">firefox flash插件</h3>
下载[ adobe flash player ](http://get.adobe.com/flashplayer/), 格式为*.tar.gz:

1.    解压：`tar -zxf xxx.tar.gz`
2.    拷贝：`sudo sudo cp -r usr/* /usr`
3.    插件：`sudo cp libflashplayer.so /usr/lib/mozilla/plugins`
4.    重启

已测试： ubuntu 12.04

<!---
################################################################################
-->
<hr />
<h3 id="remote_desktop">远程桌面</h3>
1.    `sudo apt-get install xrdp`
2.    `echo "gnome-session --session=ubuntu-2d" > ~/.xsession`
3.    `sudo apt-get install gnome-session-fallback`
4.    `sudo reboot`

已测试： windows xp

<!---
################################################################################
-->
<hr />
<h3 id="ramdisk">ramdisk</h3>
修改文件`/etc/rc.local`	
	mount -t tmpfs -o size=2048M tmpfs /mnt/ramdisk

创建挂载点：	
	sudo mkdir /mnt/ramdisk

已测试： ubuntu 12.04

<!---
################################################################################
-->
<hr />
<h3 id="firefox_cache">firefox cache</h3>
打开firefox输入：`about:config`	

*    设置字符串browser.cache.disk.parent_directory，值为路径
*    设置字符串browser.cache.offline.parent_directory，值为路径

<!---
################################################################################
-->
<hr />
<h3 id="ibus_repaire">ibus 消失</h3>
在终端输入如下内容：
	gconftool -- type boolean -s /desktop/ibus/panel/show_icon_on_systray true
	gconftool -- type boolean -s /desktop/ibus/panel/show true
	gsettings set com.canonical.Unity.Panel systray-whitelist "['all']"

<hr />

