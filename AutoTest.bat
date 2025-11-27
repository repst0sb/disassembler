@echo off

set Program=as2.exe
set InputPath=%~dp0test\
set OutputPath=%~dp0test\
set InputExt=.bin
set OutputExt=.txt
set TempFile=%~dp0output.txt
set Col=20

for /f %%a in ('echo prompt $E^| cmd') do set "ESC=%%a"
set msgSuccess= %ESC%[32;1m%ESC%[%Col%G%ESC%[0KSuccess%ESC%[0m
set msgFailure= %ESC%[31;1m%ESC%[%Col%G%ESC%[0KFAILED!%ESC%[0m
setlocal EnableDelayedExpansion

echo Running tests...

for %%f in (%InputPath%*%InputExt%) do (
  echo|set /p dummy=%%~nf
  %Program% "%%~dpnxf" "%TempFile%"
  chcp 65001 | echo|set /p dummy=

  >nul fc /B "%TempFile%" "%OutputPath%%%~nf%OutputExt%"
  if !errorlevel! equ 0 (
    echo %msgSuccess%
  ) else (
    echo %msgFailure%
  )
  del %TempFile%
)

pause