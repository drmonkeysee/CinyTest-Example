@ECHO OFF
SETLOCAL

SET build_dir=build

SET cc=clang
SET cflags=-Wall -Wextra -Werror -pedantic -Wno-deprecated-declarations ^
	-Wno-unused-parameter -Wno-gnu-zero-variadic-macro-arguments -std=c17 ^
	-Os -iquote. -v

RMDIR /S /Q %build_dir%

MKDIR %build_dir%
%cc% %cflags% src\*.c -L. -lcinytest -o %build_dir%\recttests.exe

ENDLOCAL
EXIT /B %ERRORLEVEL%
