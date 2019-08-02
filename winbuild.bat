@ECHO OFF
SETLOCAL

SET build_dir=build

SET cc=clang
SET cflags=-Wall -Wextra -Werror -pedantic -Wno-deprecated-declarations ^
	-Wno-unused-parameter -Wno-gnu-zero-variadic-macro-arguments -std=c11 -Os ^
	-iquoteCinyTest -v

RMDIR /S /Q %build_dir%

MKDIR %build_dir%
%cc% %cflags% src\*.c -LCinyTest -lcinytest -o %build_dir%\recttests.exe

ENDLOCAL
EXIT /B %ERRORLEVEL%
