---
layout: post
title: "slickedit基本操作"
date: 2013-10-04 15:00
comments: true
categories: editor
---

<!---
################################################################################
-->

1.	[下载安装](#install)
2.	[系统设置](#system)
3.	[显示设置](#display)
4.	[编辑设置](#edit)
5.	[快捷使用](#hotkey)

<!---
################################################################################
-->
<hr />
<h3 id="install">下载安装</h3>

*	下载地址 - [http://www.slickedit.com/trial/slickedit](http://www.slickedit.com/trial/slickedit)    

*	ubuntu 12.04 桌面快捷键 SlickEdit-18.0.1.2.desktop 内容：    
<pre><code>	
	[Desktop Entry]
	Version=1.0
	Name=SlickEdit 2013
	Comment=SlickEdit 2013 version 18.0.1.2
	Exec=/usr/local/slickedit/bin/vs -sc "/home/meegoo/.slickedit/" %F +new
	Icon=/usr/local/slickedit/bitmaps/vse32.xpm
	Type=Application
	Categories=Application;Development;IDE;
</code></pre>

*	清除配置文件, ubuntu - `rm -rf /home/meegoo/.slickedit`, windows - `meegoo/Documents/My SlickEdit Config`    

<!---
################################################################################
-->
<hr />
<h3 id="system">系统设置</h3>

*	设置本身的设置 - Tool -> Option -> Application Option -> Exit -> Save Configuration 选择"***immediately"
*	启动多个SE实例 - 修改启动命令行，加多一个+new作为参数传进去

<!---
################################################################################
-->
<hr />
<h3 id="display">显示设置</h3>

*	设置Tab宽度 - Tools -> Options -> Languages -> All Languages -> Formatting -> Indent, 选择Indent，Syntax 4, Tabs:4,C++ -> formatting 修改My default
*	显示行数 - Tool -> Option -> Languages -> All Language -> View
*	折叠功能 - 在主窗口的工具栏上面右击，然后选择 Toolbars -> Selective Display
*	编辑器风格 - Tool -> Option -> Keyboard and mouse -> Emulation -> Vim
*	编码设置 - Tools -> Options -> File Options -> Load -> encoding, UTF-8
*	字体设置 - Tools -> Options -> Appearance -> Fonts -> Unicode Source Windows，SBCS/DBCS Source Windows
*	单行显示 - Tools -> Options -> Languages -> All Languages -> Word Wrap, 全部不选
*	特殊符号 - Tool -> Option -> Languages -> All Language -> View -> Special Characters
*	显示竖线 - Tools->Options->Appearance->General, Vertical line column设成80，下面可以设置一个颜色。字体设置时，三个选项全选。
*	颜色方案 - Tools -> Options -> Appearance -> Colors, Black
*	修改颜色 - Tool -> Option -> Languages -> All Language -> View， 全选

<!---
################################################################################
-->
<hr />
<h3 id="edit">编辑设置</h3>

*	if格式风格 - Tools -> Options -> Languages -> All Languages -> Formatting -> Begin/end style
*	注释与反注释 - Document->Comment Lines和Document->Uncomment Lines, 注释命令行为:comment, 反注释命令行为:comment-erase

<!---
################################################################################
-->
<hr />
<h3 id="hotkey">快捷使用</h3>

*	高亮显示 - 

<!---
################################################################################
-->
<hr />

