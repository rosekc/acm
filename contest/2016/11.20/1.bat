@echo off
:again
test1003 > input.txt ;生成随机输入
1003 < input.txt > outputa.txt
1003_1 < input.txt > outputb.txt
fc outputa.txt outputb.txt > nul ;比较文件
if not errorlevel 1 goto again ;相同时继续循环
pause