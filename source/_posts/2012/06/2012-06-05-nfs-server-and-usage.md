---
layout: post
title: "nfs服务器安装及用法"
date: 2012-06-05 13:56
comments: true
categories: server
---

系统环境： ubuntu10.04

*    [nfs服务器安装](#install)
*    [nfs服务器使用](#usage)

<!---
################################################################################
-->
<hr />
<h3 id="install">nfs服务器安装</h3>
### 1. 安装软件包 ####
	sudo apt-get install nfs-kernel-server
### 2. 修改配置文件 ###
	sudo vim /etc/exports
添加内容如下：    
	/home/meegoo/work/out/filesys *(rw,sync,no_root_squash,no_subtree_check)
配置文件生效：   
	sudo /usr/sbin/exportfs -va

<!---
################################################################################
-->
<hr />
<h3 id="usage">nfs服务器使用</h3>
### 1. 显示 ###
	meegoo@lenovo:~$ showmount -e 192.168.0.238
	Export list for 192.168.0.238:
	/home/meegoo/work/out/filesys *
### 2. 挂载 ###
	$ sudo mkdir /mnt/nfs
	$ sudo mount -o soft,intr,rsize=8192,wsize=8192 192.168.0.238:/home/meegoo/work/out/filesys /mnt/nfs

