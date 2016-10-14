Set DELCMD=/Y
del obj\*.* /p
del obj /p
make
pause
copy xyj2_v104cn.u7 e:\s2\roms\orleg2
cd ..
cd s2
mametiny.20161009.exe orleg2 -w
