---
layout: post
title: "ubuntu常见问题集锦"
date: 2012-05-21 13:11
comments: true
categories: ubuntu
---

<!---
################################################################################
-->
<hr />
*    [ubuntu 源](#ubuntu_sources)

<!---
################################################################################
-->
<hr />
<h3 id="ubuntu_sources">ubuntu 源</h3>
先备份原始文件：    
	$ sudo cp /etc/apt/sources.list /etc/apt/sources.list.backup

新文件`/etc/apt/sources.list`:

{% codeblock %}
# deb cdrom:[Ubuntu 10.04.3 LTS _Lucid Lynx_ - Release amd64 (20110720.1)]/ lucid main restricted
# See http://help.ubuntu.com/community/UpgradeNotes for how to upgrade to
# newer versions of the distribution.

deb http://mirrors.163.com/ubuntu/ lucid main restricted
deb-src http://mirrors.163.com/ubuntu/ lucid main restricted

## Major bug fix updates produced after the final release of the
## distribution.
deb http://mirrors.163.com/ubuntu/ lucid-updates main restricted
deb-src http://mirrors.163.com/ubuntu/ lucid-updates main restricted

## N.B. software from this repository is ENTIRELY UNSUPPORTED by the Ubuntu
## team. Also, please note that software in universe WILL NOT receive any
## review or updates from the Ubuntu security team.
deb http://mirrors.163.com/ubuntu/ lucid universe
deb-src http://mirrors.163.com/ubuntu/ lucid universe
deb http://mirrors.163.com/ubuntu/ lucid-updates universe
deb-src http://mirrors.163.com/ubuntu/ lucid-updates universe

## N.B. software from this repository is ENTIRELY UNSUPPORTED by the Ubuntu 
## team, and may not be under a free licence. Please satisfy yourself as to 
## your rights to use the software. Also, please note that software in 
## multiverse WILL NOT receive any review or updates from the Ubuntu
## security team.
deb http://mirrors.163.com/ubuntu/ lucid multiverse
deb-src http://mirrors.163.com/ubuntu/ lucid multiverse
deb http://mirrors.163.com/ubuntu/ lucid-updates multiverse
deb-src http://mirrors.163.com/ubuntu/ lucid-updates multiverse

## Uncomment the following two lines to add software from the 'backports'
## repository.
## N.B. software from this repository may not have been tested as
## extensively as that contained in the main release, although it includes
## newer versions of some applications which may provide useful features.
## Also, please note that software in backports WILL NOT receive any review
## or updates from the Ubuntu security team.
# deb http://cn.archive.ubuntu.com/ubuntu/ lucid-backports main restricted universe multiverse
# deb-src http://cn.archive.ubuntu.com/ubuntu/ lucid-backports main restricted universe multiverse

## Uncomment the following two lines to add software from Canonical's
## 'partner' repository.
## This software is not part of Ubuntu, but is offered by Canonical and the
## respective vendors as a service to Ubuntu users.
# deb http://archive.canonical.com/ubuntu lucid partner
# deb-src http://archive.canonical.com/ubuntu lucid partner

deb http://mirrors.163.com/ubuntu/ lucid-security main restricted
deb-src http://mirrors.163.com/ubuntu/ lucid-security main restricted
deb http://mirrors.163.com/ubuntu/ lucid-security universe
deb-src http://mirrors.163.com/ubuntu/ lucid-security universe
deb http://mirrors.163.com/ubuntu/ lucid-security multiverse
deb-src http://mirrors.163.com/ubuntu/ lucid-security multiverse
{% endcodeblock %}

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

<hr />