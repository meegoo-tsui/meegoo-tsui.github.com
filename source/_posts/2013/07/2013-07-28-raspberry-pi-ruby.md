---
layout: post
title: "4. Raspberry pi ruby"
date: 2013-07-28 08:50
comments: true
categories: RaspberryPi
---

## [Installing Ruby on Rails on Raspberry Pi](http://elinux.org/RPi_Ruby_on_Rails) ##

This is a guide to install [Ruby on Rails](http://rubyonrails.org) on the Raspberry Pi computer running Debian "squeeze". It will also be useful to people who just require a [Ruby](http://www.ruby-lang.org) installation. The guide can be followed by anyone if it all goes right, but when things go wrong, it is often difficult to see what the problem is. It will take several hours to complete and requires an internet connection.

The guide has been developed/tested using debian6-19-04-2012. There is not enough room on a standard 2Gb image. I tested with an 8Gb image, but you may get away with 4Gb.

The installation was all done from the basic (pre startx) command prompt. We will use Ruby Version Manager [RVM](http://beginrescueend.com), so first we must install all its prerequisites:

	# Install prerequisites
	sudo apt-get install -y git curl zlib1g-dev subversion

You might come across the error '404 not found', then try update your APT package index:
	# Update APT package index
	sudo apt-get update

The above is enough to proceed, but we will also need the following later, so whilst we're in the mood for apt-getting:
	# Additional Ruby dependencies
	sudo apt-get install -y openssl libreadline6-dev git-core zlib1g libssl-dev
	sudo apt-get install -y libyaml-dev libsqlite3-dev sqlite3
	sudo apt-get install -y libxml2-dev libxslt-dev
	sudo apt-get install -y autoconf automake libtool bison

Note: Not installing openssl before RVM will cause you [grief](https://rvm.io/packages/openssl/) later!

Now we can use RVM straight from github using:
	curl -L get.rvm.io | bash -s stable --rails

Note: With my default Debian image and keyboard map, it was very hard to get a | (pipe) character. I got it by pressing AltGr+|

When run, you will get some messages about requirements for Ruby. You need to press 'q'. Note the computer may not react straight away as it is 'thinking'. After a few seconds, the script will download and compile ruby 1.9 and Rails. This takes a long time! (3 Hrs) Have a sleep and check in the morning.

At the end of the installation, RVM suggests that you have to run a script in order to enable Ruby. (I think I only had to do this once?)
	pi@raspberrypi:~$ source ~/.rvm/scripts/rvm

Now you should have ruby:
	pi@raspberrypi:~$ ruby -v
	ruby 1.9.3p194 (2012-04-20 revision 35410) [armv61-linux-eabi]

And you should have a rails command:

	pi@raspberrypi:~$ rails -v
	Rails 3.2.3

## JavaScript ##
Rails requires a JavaScript runtime. Any of the following listed [here](https://github.com/sstephenson/execjs) will do.
I installed node.js using this [blog](http://blog.tomg.co/post/21322413373/how-to-install-node-js-on-your-raspberry-pi) by Tom Gallacher. (Note I had to use sudo when doing make install)

## Testing Installation ##
In order to test the installation, let's create a simple project.
In this example the name for our new project is school.

	pi@raspberrypi:~$ rails new school
	pi@raspberrypi:~$ cd school
	pi@raspberrypi:~$ rails g scaffold Pupil name:string form:string
	pi@raspberrypi:~$ rake db:migrate
	pi@raspberrypi:~$ rails s

All being well you will now have a running server with database back end, which you can point a browser at.

Note: You can't use 'class' as a field name, so I chose 'form'.

If you do the above in an X-windows terminal, then point the Raspberry-Pi browser to:
	http://0.0.0.0:3000/pupils
You should then be able to Create, Read, Update & Delete (Often called CRUD) pupil records in your database.

Alternatively, if you have another computer on the same network, you can point its browser at the RPi substituting the 0.0.0.0 in the above address for the real RPi one. If you don't know the address of your RPi, then use the following command in a terminal:
	hostname -I

## Conclusion ##
We have a working installation of Ruby on Rails. It is very slow but just about usable. If this is your introduction to Ruby on Rails please don't let the speed put you off. If you follow this fantastic [tutorial](http://ruby.railstutorial.org/ruby-on-rails-tutorial-book) it will show you how to deploy to [Heroku](http://www.heroku.com/) (for free), then your website will be as fast as those with proper computers.
