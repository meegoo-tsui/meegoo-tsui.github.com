---
layout: post
title: "eclipse安装及配置"
date: 2012-06-09 21:13
comments: true
categories: editor
---

官网下载：

*    [oracle JDK](http://www.oracle.com/technetwork/java/javase/downloads/index.html)
*    [eclipse](http://www.eclipse.org/downloads/)

<!---
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-->
<hr />
#### 1. 下载 [java sdk - 7u4](http://www.oracle.com/technetwork/java/javase/downloads/jdk-7u4-downloads-1591156.html) ####
linux平台:

*    x86-32: [jdk-7u4-linux-i586.tar.gz](http://www.oracle.com/technetwork/java/javase/downloads/jdk-7u4-downloads-1591156.html)
*    x64-64: [jdk-7u4-linux-x64.tar.gz](http://www.oracle.com/technetwork/java/javase/downloads/jdk-7u4-downloads-1591156.html)

windows平台:

*    x86-32: [jdk-7u4-windows-i586.exe](http://www.oracle.com/technetwork/java/javase/downloads/jdk-7u4-downloads-1591156.html)
*    x64-64: [jdk-7u4-windows-x64.exe](http://www.oracle.com/technetwork/java/javase/downloads/jdk-7u4-downloads-1591156.html)

<!---
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-->
<hr />
#### 2. 下载 [eslipse](http://www.eclipse.org/downloads) ####
linux平台:

*    x86-32: [eclipse-SDK-3.7.2-linux-gtk.tar.gz](http://www.eclipse.org/downloads/download.php?file=/eclipse/downloads/drops/R-3.7.2-201202080800/eclipse-SDK-3.7.2-linux-gtk.tar.gz)
*    x64-64: [eclipse-SDK-3.7.2-linux-gtk-x86_64.tar.gz](http://www.eclipse.org/downloads/download.php?file=/eclipse/downloads/drops/R-3.7.2-201202080800/eclipse-SDK-3.7.2-linux-gtk-x86_64.tar.gz)

windows平台:

*    x86-32: [eclipse-SDK-3.7.2-win32.zip](http://www.eclipse.org/downloads/download.php?file=/eclipse/downloads/drops/R-3.7.2-201202080800/eclipse-SDK-3.7.2-win32.zip)
*    x64-64: [eclipse-SDK-3.7.2-win32-x86_64.zip](http://www.eclipse.org/downloads/download.php?file=/eclipse/downloads/drops/R-3.7.2-201202080800/eclipse-SDK-3.7.2-win32-x86_64.zip)

<!---
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-->
<hr />
#### 3. 安装 ####
ubuntu 12.04 - 64bit	

1. 解压安装包到/opt路径下；
2. 修改/opt/eclipse/eclipse.ini，在文件开头添加二行：	

eclipse.ini:	
	-vm
	/opt/jdk1.7.0_0x/bin/java

<!---
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-->
<hr />
#### 4. plugin - pydev ####
python的开发插件 - [pydev](http://pydev.org/)，下载[http://sourceforge.net/projects/pydev/files/pydev/](http://sourceforge.net/projects/pydev/files/pydev/)
的zip文件，解压后，对应复制features、plugins到eclipse，修改eclipse文件夹权限，否则仅root用户插件才起作用。

<!---
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-->
<hr />

