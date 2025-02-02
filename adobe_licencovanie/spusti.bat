@echo off
setlocal
REM Získanie aktuálneho adresára bat súboru
set "currentDir=%~dp0"
echo Aktualny adresar bat suboru je: %currentDir%

REM Prompt the user for input
set /p userInput=vloz prikaz:
REM Check if the input is empty
if "%userInput%"=="" (
    echo No input provided
    exit /b 1
)
bash licencia.sh '%userInput%'
pause