---
layout: post
title: "ssh服务器安装及用法"
date: 2012-06-05 13:56
comments: true
categories: server
---

系统环境： ubuntu10.04

*    [ssh服务器安装](#install)
*    [ssh服务器使用](#usage)

<!---
################################################################################
-->
<hr />
<h3 id="install">ssh服务器安装</h3>
### 1. 安装软件包 ####
	sudo apt-get install openssh-server
### 2. 重启ssh服务 ###
	sudo /etc/init.d/ssh restart
### 3. 查看 ###
	netstat -tlp | grep ssh

<!---
################################################################################
-->
<hr />
<h3 id="usage">ssh服务器使用</h3>
### 1. 用法 ###
	SYNOPSIS

	ssh [-l login_name ] hostname | user@hostname [command ]
	ssh [-afgknqstvxACNTX1246 ] [-b bind_address ] [-c cipher_spec ] 
	[-e escape_char ] [-i identity_file ] [-l login_name ] [-m mac_spec ] 
	[-o option ] [-p port ] [-F configfile ] [-L port host hostport ] 
	[-R port host hostport ] [-D port ] hostname | user@hostname [command ] 

### 2. 热键 ###
	~.
	    Disconnect 
	~^Z
	    Background ssh 
	~#
	    List forwarded connections 
	~&
	    Background ssh at logout when waiting for forwarded connection / X11 sessions to terminate 
	~?
	    Display a list of escape characters 
	~C
	    Open command line (only useful for adding port forwardings using the -L and -R options) 
	~R
	    Request rekeying of the connection (only useful for SSH protocol version 2 and if the peer supports it)

