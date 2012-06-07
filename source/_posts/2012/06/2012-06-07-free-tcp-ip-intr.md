---
layout: post
title: "开源tcp-ip协议栈简介"
date: 2012-06-07 14:58
comments: true
categories: 
---

#### 1. [BSD TCP/IP](http://svnweb.freebsd.org/base/release/9.0.0/sys/netinet/) ####
BSD栈历史上是其他商业栈的起点，大多数专业TCP/IP栈（VxWorks内嵌的TCP/IP栈）是BSD栈派生的。
这是因为BSD栈在BSD许可协议下提供了这些专业栈的雏形，BSD许用证允许BSD栈以修改或未修改的形式结合这些专业栈的代码而无须向创建者付版税。
同时，BSD也是许多TCP/IP协议中的创新（如广域网中饿拥塞控制和避免）的开始点。

#### 2. [uC/IP](http://ucip.sourceforge.net/) ####
uC/IP是由Guy Lancaster编写的一套基于uC/OS且开放源码的TCP/IP协议栈，亦可移植到其它操作系统，
是一套完全免费的、可供研究的TCP/IP协议栈，uC/IP大部分源码是从公开源码BSD发布站点和KA9Q（一个基于DOS单任务环境运行的TCP/IP协议栈）移植过来。
uC/IP具有如下一些特点：带身份验证和报头压缩支持的PPP协议，优化的单一请求/回复交互过程，支持IP/TCP/UDP协议，
可实现的网络功能较为强大，并可裁减。UCIP协议栈被设计为一个带最小化用户接口及可应用串行链路网络模块。
根据采用CPU、编译器和系统所需实现协议的多少，协议栈需要的代码容量空间在30-60KB之间。

#### 3. [LwIP](http://savannah.nongnu.org/projects/lwip/) ####
LwIP是瑞士计算机科学院（Swedish Institute of Computer Science）的Adam Dunkels等开发的一套用于嵌入式系统的开放源代码TCP/IP协议栈。
LwIP的含义是Light Weight(轻型)IP协议，相对于uip。LwIP可以移植到操作系统上，也可以在无操作系统的情况下独立运行。
LwIP TCP/IP实现的重点是在保持TCP协议主要功能的基础上减少对RAM的占用，一般它只需要几十K的RAM和40K左右的ROM就可以运行，
这使LwIP协议栈适合在低端嵌入式系统中使用。LwIP的特性如下：支持多网络接口下的IP转发，支持ICMP协议 ，
包括实验性扩展的的UDP（用户数据报协议），包括阻塞控制，RTT估算和快速恢复和快速转发的TCP（传输控制协议），
提供专门的内部回调接口（Raw API）用于提高应用程序性能，并提供了可选择的Berkeley接口API。

#### [4. uIP](http://dunkels.com/adam/)####
专门为8位和16位控制器设计的一个非常小的TCP/IP栈。完全用C编写，因此可移植到各种不同的结构和操作系统上，
一个编译过的栈可以在几KB ROM或几百字节RAM中运行。uIP中还包括一个HTTP服务器作为服务内容。
