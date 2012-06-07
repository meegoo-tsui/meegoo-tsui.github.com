---
layout: post
title: "输入时间戳"
date: 2012-06-07 09:38
comments: true
categories: 
---

#### 目的 ####
记录输入时间戳，主要测试uboot的各启动项所花费时间，源码如下：    
{% include_code c/tstamp.c %}

#### 使用 ####
1.    测试uboot启动，先启动`minicom`，然后执行`tstamp.exe < /dev/ttyS0`；
2.    测试命令输出，使用管道`<commands> | tstamp.exe`；

