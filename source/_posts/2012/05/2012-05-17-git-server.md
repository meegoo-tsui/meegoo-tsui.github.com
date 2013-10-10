---
layout: post
title: "git服务器配置"
date: 2012-05-17 13:11
comments: true
categories: server
---

安装平台： ubuntu 10.04    
搭建git服务器，需要如下软件：    
	$ sudo apt-get install openssh-server openssh-client
	$ sudo apt-get install git
	$ sudo apt-get install python-setuptools

## 源码删除gitosis ##
使用git下载源码：    
	$ git clone https://github.com/meegoo-tsui/gitosis.git gitosis.git
	$ cd gitosis.git
	$ sudo python setup.py install --record uninstall.txt
	$ cat uninstall.txt | xargs sudo rm -rf

## 源码安装gitolite ##
使用git下载源码：    
	$ git clone git://github.com/sitaramc/gitolite gitolite.git
	$ cd gitolite.git
	$ sudo mkdir /usr/local/gitolite
	$ sudo ./install -to /usr/local/gitolite

## 账户相关信息 ##
创建用户git    
	$ sudo adduser --system --shell /bin/bash --disabled-password --group git
	$ sudo usermod -G git -a www-data

初始化全局设置
{% include_code config_git.sh %}

## 初始化gitolite ##
生成 SSH key：    
	$ sudo su - git
	$ ssh-keygen -t rsa -C "meegoo.tsui@gmail.com"
	$ /usr/local/gitolite/gitolite setup -pk ~/.ssh/id_rsa.pub
文件内容如下：
{% include_code id_rsa.pub lang:sh %}
修改文件`sudo gedit /home/git/.gitolite.rc`:    
	UMASK                           =>  0022,
	GIT_CONFIG_KEYS                 =>  '.*',
	GITWEB_PROJECTS_LIST            => '/home/git/projects.list',

clone gitolite管理平台：    
	$ git clone git@127.0.0.1:gitolite-admin.git gitolite-admin.git

创建版本项目：    
	$ mkdir test.git;cd test.git
	$ git init
	$ git commit --allow-empty -m "create the repos."
	$ git remote add origin git@127.0.0.1:test.git
	$ git push -u origin master

## gitweb安装及配置 ##
安装gitweb：     
	$ sudo apt-get install highlight gitweb
配置apache服务器:
	$ sudo gedit /etc/apache2/mods-available/dav_svn.conf
添加内容如下：      
	Alias /gitweb /usr/share/gitweb
	<Directory /usr/share/gitweb>
		Options FollowSymLinks +ExecCGI
		AddHandler cgi-script .cgi
		DirectoryIndex index.cgi gitweb.cgi
		order Allow,Deny
		Allow from all
	</Directory>
或：    
	<VirtualHost *:80>
		ServerName localhost
		ScriptAlias /cgi-bin/ /usr/lib/cgi-bin/
		<Directory /usr/lib/cgi-bin/>
			Options ExecCGI +FollowSymLinks +SymLinksIfOwnerMatch
			AllowOverride All
			order allow,deny
			Allow from all
			AddHandler cgi-script cgi .pl .py
			DirectoryIndex gitweb.cgi
		</Directory>
	</VirtualHost>

修改gitweb配置文件：   
	$ sudo vim /etc/gitweb.conf
	$ sudo /etc/init.d/apache2 restart
	# 修改内容如下：
	$projectroot = "/home/git/repositories";
	$home_text = "/home/git/indextext.html";
	$projects_list = "/home/git/projects.list";
	# Add Highlighting at the end
	$feature{'highlight'}{'default'} = [1];

访问： http://127.0.0.1/gitweb

<hr />
