@echo off
setlocal

REM Rozhodnutie na základe architektúry procesoru
if "%PROCESSOR_ARCHITECTURE%"=="AMD64" (
    set "path_to_licence_kit=%cd%/adobe-licensing-toolkit/win64"
) else (
    set "path_to_licence_kit=%cd%/adobe-licensing-toolkit/win32"
)
echo Cesta k licencnemu toolkitu: %path_to_licence_kit%

:loop
REM Prompt uživatele o vstup
set userInput=
set /p userInput=Vlozte prikaz:

REM Ošetření prázdného vstupu
if "%userInput%"=="" (
    echo "Nebol zadany ziadny vstup.""
    echo "Napiste -help pre zobrazenie spravnych vstupov."
    exit /b 1
)

REM Rozhodování na základě vstupu
if "%userInput%"=="-licencia-detail" (
    "%path_to_licence_kit%/adobe-licensing-toolkit.exe" -l
    goto loop
)
if "%userInput%"=="-package-detail" (
    "%path_to_licence_kit%/adobe-licensing-toolkit.exe" -d

    goto loop
)
if "%userInput%"=="-deactivate-all" (
    echo "Skutocne chcete deaktivovat vsetky licencie? (Stlacte libovolnu klavesu pro potvrdenie, inak zatvorte skript alebo straclte ctrl+c)"
    pause
    "%path_to_licence_kit%/adobe-licensing-toolkit.exe" -t
 
    goto loop
)
if "%userInput%"=="-aktivacia-licencie" (
    "%path_to_licence_kit%/adobe-licensing-toolkit.exe" --activate

    goto loop

)
if "%userInput%"=="-help" (
    echo "-licencia-detail  zobrazi informacie o licenciach"
    echo "-package-detail zobrazi informacie o nainstalovanom packagi"
    echo "-deactivate-all deaktivuje vsetky licencie packagu"
    echo "-exit|-e vypne skript"
    echo "-clear vycisti vypis obrazovky"

    goto loop
) else (
    echo Napiste -help pre zobrazenie spravnych vstupov.

    goto loop
)
if "%userInput%"=="-exit" || "%userInput%"=="-e"(
   
    exit /b 0
)
if "%userInput%"=="clear"(
  
    cls
    goto loop
)