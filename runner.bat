@echo off
cls
set arg1=%1
set arg2=%2
shift
shift

echo Compiling %arg1%.c ...
gcc %arg1%.c -o %arg1%.exe
echo Compile finished
pause

echo Running %arg1%.exe ...
%arg1%.exe

cls