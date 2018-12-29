# Linux

### Overview



### man page

安装命令

### 指令

##### 文件管理

- `cat`用于连接文件并打印到标准输出设备上
  - `cat [-AbeEnstTuv] [--help] [--version] fileName`
  - `-n`：由1开始对所有输出的行数编号
  - `-b`：对于空白行不编号
- `chattr`用于改变文件属性
  - `chattr [-RV][-v<版本编号>][+/-/=<属性>][文件或目录...]`
  - `-R` 递归处理，将指定目录下的所有文件及子目录一并处理
  - `+<属性>` 开启文件或目录的该项属性
  - `-<属性>` 关闭文件或目录的该项属性
  - `=<属性>` 指定文件或目录的该项属性
- `chgrp`用于变更文件或目录的所属群组
  - `chgrp [-cfhRv][--help][--version][所属群组][文件或目录...] 或 chgrp [-cfhRv][--help][--reference=<参考文件或目录>][--version][文件或目录...]`
  - `-R`　递归处理，将指定目录下的所有文件及子目录一并处理
- `chmod`设置文件调用权限
  - r 表示可读取，w 表示可写入，x 表示可执行
  - User、Group、及Other：r=4，w=2，x=1

- `chown`
- cksum
- cmp
- diff
- diffstat
- file
- find
- git
- gitview
- indent
- cut
- ln
- less
- locate
- lsattr
- mattrib
- mc
- mdel
- mdir
- mktemp
- more
- mmove
- mread
- mren
- mtools
- mtoolstest
- mv
- od
- paste
- patch
- rcp
- rm
- slocate
- split
- tee
- tmpwatch
- touch
- umask
- which
- cp
- whereis
- mcopy
- mshowfat
- rhmask
- scp
- awk
- read
- updatedb

##### 文档编辑

- col
- colrm
- comm
- csplit
- ed
- egrep
- ex
- fgrep
- fmt
- fold
- grep
- ispell
- jed
- joe
- join
- look
- mtype
- pico
- rgrep
- sed
- sort
- spell
- tr
- expr
- uniq
- wc
- let

##### 文件传输

- lprm
- lpr
- lpq
- lpd
- bye
- ftp
- uuto
- uupick
- uucp
- uucico
- tftp
- ncftp
- ftpshut
- ftpwho
- ftpcount

##### 磁盘管理

- cd
- df
- dirs
- du
- edquota
- eject
- mcd
- mdeltree
- mdu
- mkdir
- mlabel
- mmd
- mrd
- mzip
- pwd
- quota
- mount
- mmount
- rmdir
- rmt
- stat
- tree
- umount
- ls
- quotacheck
- quotaoff
- lndir
- repquota
- quotaon

##### 磁盘维护

- badblocks
- cfdisk
- dd
- e2fsck
- ext2ed
- fsck
- fsck.minix
- fsconf
- fdformat
- hdparm
- mformat
- mkbootdisk
- mkdosfs
- mke2fs
- mkfs.ext2
- mkfs.msdos
- mkinitrd
- mkisofs
- mkswap
- mpartition
- swapon
- symlinks
- sync
- mbadblocks
- mkfs.minix
- fsck.ext2
- fdisk
- losetup
- mkfs
- sfdisk
- swapoff

##### 网络通讯

- apachectl
- arpwatch
- dip
- getty
- mingetty
- uux
- telnet
- uulog
- uustat
- ppp-off
- netconfig
- nc
- httpd
- ifconfig
- minicom
- mesg
- dnsconf
- wall
- netstat
- ping
- pppstats
- samba
- setserial
- talk
- traceroute
- tty
- newaliases
- uuname
- netconf
- write
- statserial
- efax
- pppsetup
- tcpdump
- ytalk
- cu
- smbd
- testparm
- smbclient
- shapecfg


##### 系统管理

- adduser
- chfn
- useradd
- date
- exit
- finger
- fwhios
- sleep
- suspend
- groupdel
- groupmod
- halt
- kill
- last
- lastb
- login
- logname
- logout
- ps
- nice
- procinfo
- top
- pstree
- reboot
rlogin
- rsh
- sliplogin
- screen
shutdown
- rwho
- sudo
- gitps
swatch
- tload
- logrotate
- uname
chsh
- userconf
- userdel
- usermod
vlock
- who
- whoami
- whois
newgrp
- renice
- su
- skill
w
- id
- free
-  


##### 系统设置

reset
- clear
- alias
- dircolors
aumix
- bind
- chroot
- clock
crontab
- declare
- depmod
- dmesg
enable
- eval
- export
- pwunconv
grpconv
- rpm
- insmod
- kbdconfig
lilo
- liloconfig
- lsmod
- minfo
set
- modprobe
- ntsysv
- mouseconfig
passwd
- pwconv
- rdate
- resize
rmmod
- grpunconv
- modinfo
- time
setup
- sndconfig
- setenv
- setconsole
timeconfig
- ulimit
- unset
- chkconfig
apmd
- hwclock
- mkkickstart
- fbset
unalias
- SVGATextMode
-  
-  


##### 备份压缩

ar
- bunzip2
- bzip2
- bzip2recover
gunzip
- unarj
- compress
- cpio
dump
- uuencode
- gzexe
- gzip
lha
- restore
- tar
- uudecode
unzip
- zip
- zipinfo
-  


##### 设备管理


setleds
- loadkeys
- rdev
- dumpkeys
MAKEDEV
-  
-  
-  


##### 其他


- 快捷键
  - Tab：命令和文件名补全；
  - Ctrl+C：中断正在运行的程序；
  - Ctrl+D：结束键盘输入（End Of File，EOF）
- --help指令的基本用法与选项介绍。
- 包管理
- vim
- 为了使不同 Linux 发行版本的目录结构保持一致性，Filesystem Hierarchy Standard (FHS) 规定了 Linux 的目录结构。最基础的三个目录如下：
  - / (root, 根目录)
  - /usr (unix software resource)：所有系统默认软件都会安装到这个目录；
  - /var (variable)：存放系统或程序运行过程中的数据文件。

### Shell Script

.sh

### Interview Problem


### Reference Link

- [RUNOOB Linux 命令大全](http://www.runoob.com/linux/linux-command-manual.html)
