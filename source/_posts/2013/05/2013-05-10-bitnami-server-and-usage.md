---
layout: post
title: "bitnami服务器安装及用法"
date: 2013-05-10 22:23
comments: true
categories: server
---

系统环境： ubuntu10.04

*    [bitnami服务器安装](#install)
*    [bitnami服务器使用](#usage)

<!---
################################################################################
-->
<hr />
<h3 id="install"> bitnama 服务器安装</h3>
### 安装软件包 [bitnama](http://bitnami.com/) ####
	sudo ./bitnami-redmine-2.3.1-0-linux-installer.run

<!---
################################################################################
-->
<hr />
<h3 id="usage">bitnami服务器使用</h3>
### [添加自动运行](http://bitnami.com/article/how-to-install-services-on-linux) ###
	cp ${installdir}/ctlscript.sh /etc/init.d/bitnami-drupal
	update-rc.d -f bitnami-drupal start 80 2 3 4 5 . stop 30 0 1 6 .

结果如下：    
	Adding system startup for /etc/init.d/bitnami-drupal ...
	/etc/rc0.d/K30bitnami-bitnami-drupal -> ../init.d/drupal
	/etc/rc1.d/K30bitnami-bitnami-drupal -> ../init.d/drupal
	/etc/rc6.d/K30bitnami-drupal -> ../init.d/bitnami-drupal
	/etc/rc2.d/S80bitnami-drupal -> ../init.d/bitnami-drupal
	/etc/rc3.d/S80bitnami-drupal -> ../init.d/bitnami-drupal
	/etc/rc4.d/S80bitnami-drupal -> ../init.d/bitnami-drupal
	/etc/rc5.d/S80bitnami-drupal -> ../init.d/bitnami-dru

浏览器输入： `http://192.168.1.10/redmine/`
