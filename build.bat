@echo off
echo FUCK, windows is a piece of shit

setlocal

set "SCRIPT_DIR=%~dp0"
set "INPUT=%~1"
set "OUTPUT=%~n1"

if "%INPUT%"=="" (
    echo Usage: %0 source_file.c
    exit /b 1
)

if not exist "%SCRIPT_DIR%bin" (
    mkdir "%SCRIPT_DIR%bin"
)

gcc .\lib\et21conio.c "%INPUT%" -o "%SCRIPT_DIR%bin\%OUTPUT%"

if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
)

"%SCRIPT_DIR%bin\%OUTPUT%"

endlocal