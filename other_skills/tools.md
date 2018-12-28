# Tools

### 正则表达式

##### 其他

面试题。。。。 。。。

### Docker


### git、github、git_server

- Git 属于分布式版本控制系统，而 SVN 属于集中式
![](git_img/git.png)
- 图形化
  - `gitk`  内建的图形化 git
  - `git config color.ui true`  彩色的 git 输出
  - `git config format.pretty oneline`  显示历史记录时，只显示一行注释信息
  - `git add -i`  交互地添加文件至缓存区
- 远程
  - `git remote add origin <url>`  添加远程地址
  - `git remote remove <name>`  删除关联的远程版本库
  - `git push -u origin master`  将master分支推送到origin远程仓库
  - `git push -u origin master -f`  强制将master分支推送到远程仓库origin  慎用
- 图解
- git结构
![](git_img/trees.png)
- 工作区：就是你在电脑里能看到的目录
- 暂存区：英文叫stage, 或index。一般存放在 ".git目录下" 下的index文件（.git/index）中，所以我们把暂存区有时也叫作索引（index）
- 版本库：工作区有一个隐藏目录.git，这个不算工作区，而是Git的版本库
- 分支
![](git_img/branches.png)
- error
  - `error: src refspec master does not match any.`
      - 空目录不能提交；至少有一次commit



### Nginx、Apache

### Ajax



### Interview Problem
