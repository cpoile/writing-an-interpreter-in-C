@echo off

pushd C:\Users\Chris\git\c\writing_an_interpreter

if not exist build (
	mkdir build
)

pushd build

rem clang-cl.exe  /nologo -Wall /Ob0 /Od /RTC1 -MDd -Zi /Feinterpreter.exe /FdTARGET_COMPILE_PDB ..\\all.c /link
cl.exe -nologo -Zi -FC -Wall -I..\\base -I..\\token -I..\\lexer ..\\all.c -Feinterpreter.exe /link

popd
popd
