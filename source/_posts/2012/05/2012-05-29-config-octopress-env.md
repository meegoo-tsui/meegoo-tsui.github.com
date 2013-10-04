---
layout: post
title: "配置Octopress环境"
date: 2012-05-29 13:11
comments: true
categories: octopress
---

[Octopress](http://octopress.org)的官方网站上有详细文档，可先参考此网站上的相关文档。
配置完后，已安装jekyll。

<hr />

<!---
################################################################################
-->
*    [Windows7 环境](#windows7)
*    [Linux 环境](#linux)
<hr />

<!---
################################################################################
-->
<h2 id="windows7">配置Octopress - windows7 环境</h2>

### 1. 安装msysgit ###
下载[msysgit](http://code.google.com/p/msysgit/downloads/list)，当前版本为`Git-1.7.8-preview20111206.exe`,
安装在D:\Git-1.7.8，默认安装即可，其他路径也可以，但是路径中不要包含中文和空格，免得自找麻烦。

### 2. 安装[yari](https://github.com/scottmuc/yari) ###
使用刚才的工具下载，输入命令如下：    
	$ git clone git://github.com/scottmuc/yari.git /d/yari
完成后添加`D:\yari\bin`到windoes环境变量`PATH`，打开dos，运行命令如下：    
	D:\yari>yari 1.9.2

### 3. 安装[python2.7.3 - Python 2.7.3 Windows Installer ](http://www.python.org/getit/) ###
安装路径：`D:\Python27`

### 4. 添加git环境变量PATH ###
修改文件`D:\Git-1.7.8\etc\profile`:    
	export PATH="/d/Python27:/d/yari/ruby-1.9.2-p290-i386-mingw32/bin:$PATH"

### 5. 安装gem包 ###
	git clone git@github.com:meegoo-tsui/meegoo-tsui.github.com.git
	git chehckout source
	gem install bundler
	bundle install

### 6. 解决rake generate的错误 ###
错误内容如下：    
	...
	ruby-1.9.2-p290-i386-mingw32/lib/ruby/gems/1.9.1/gems/jekyll-0.11.2/lib
	/jekyll/convertible.rb:29:in `read_yaml': invalid byte sequence in GB2312 (ArgumentError)
	...

修改`D:\yari\ruby-1.9.2-p290-i386-mingw32\lib\ruby\gems\1.9.1\gems\jekyll-0.11.2\lib\jekyll\tags\include.rb`    
	source = File.read(@file)
替换为    
	source = File.read(@file, :encoding => "utf-8")
修改`D:\yari\ruby-1.9.2-p290-i386-mingw32\lib\ruby\gems\1.9.1\gems\jekyll-0.11.2\lib\jekyll\convertible.rb`     
	self.content = File.read(File.join(base, name))
替换为    
	self.content = File.read(File.join(base, name), :encoding => "utf-8")	
	
### 7. 测试 ###
	git generate
	git preview

查看：http://127.0.0.1:4000/
<hr />

<!---
################################################################################
-->
<h2 id="linux">配置Octopress - linux 环境</h2>
### ubuntu10.04安装rvm ###

### 1. 安装ruby依靠包、curl、ruby ###
	sudo apt-get install build-essential openssl libreadline6 libreadline6-dev curl git zlib1g zlib1g-dev libssl-dev libyaml-dev libsqlite3-dev sqlite3 libxml2-dev libxslt-dev autoconf libc6-dev ncurses-dev automake libtool bison subversion
	sudo apt-get install ruby

### 2. 通过下面指令安装rvm ###
	bash -s stable < <(curl -s https://raw.github.com/wayneeseguin/rvm/master/binscripts/rvm-installer )

### 3. 查询安装结果 ###
添加如下内容到`~/.bashrc`，删除`~/.bash_profile`：    
	[[ -s "$HOME/.rvm/scripts/rvm" ]] && source "$HOME/.rvm/scripts/rvm"
重新进入终端使环境变量生效，然后运行如下命令：    
	rvm list known
	[ruby-]1.9.3-[xxx]
如上所示，显示出可安装的ruby版本，至此rvm的安装完成。

### ubuntu10.04安装ruby及依靠包 ###

### 1. 安装ruby ###
`Octopress`当前使用的`ruby`版本为`1.9.3`，因此使用如下命令安装`ruby`，按提示安装相关软件包：    
	rvm install 1.9.3
需要重装时：   
	rvm reinstall 1.9.3
设置环境：    
	. ~/.rvm/scripts/rvm
	rvm use 1.9.3

### 2. 克隆`Octopress`的版本库 ###
`Octopress`的版本库托管在`github`，使用如下命令`checkout`：    
	git clone git://github.com/imathis/octopress.git octopress
	cd octopress    # 当使用rvm时，提示是否信任.rvmrc文件，输入yes
	ruby --version  # 显示 Ruby 1.9.3

### 3. 安装依靠包 ###
Windows环境安装了[RailsInstaller](http://railsinstaller.org/)，可直接安装下面内容，
以下命令需要在`octopress`路径下执行，版本的锁定需要此路径下的`Gemfile`文件：   
	gem install bundler
	bundle install

到此已完成`Octopress`环境的配置，可以使用`Octopress`的相关命令：    
	rake install
	rake generate
	rake preview
查看：http://127.0.0.1:4000/
<hr />
