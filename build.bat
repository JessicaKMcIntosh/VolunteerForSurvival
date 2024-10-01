@ECHO OFF
REM Build the Volunteer For Survival game.
REM See the README file for details.
REM See the following for help in BAT scripts.
REM https://en.wikibooks.org/wiki/Windows_Batch_Scripting

REM Set the compiler.
REM This one is the included compiler for Windows.
SET COMPILER="inform6\inform6"
REM This one expects the inform compiler to be included in the path.
REM SET COMPILER="inform6"

REM Set the dfrotz intepreter command for running the tests.
SET INTERPRETER="inform6\dfrotz"

REM Application name for output.
SET APPNAME="Volunteer For Survival"

REM Check for a command line argument.
REM If none just run the build.
IF -%1-==-- GOTO runbuild

REM Figure out what we were given on the command line.
:processargs
    if /i "%1"=="all"   CALL :runall
    if /i "%1"=="build" CALL :runbuild
    if /i "%1"=="clean" CALL :runclean
    if /i "%1"=="debug" CALL :rundebug
    if /i "%1"=="test"  CALL :runtests
    if /i "%1"=="tests" CALL :runtests
    if /i "%1"=="help"  CALL :showhelp
    if /i "%1"=="/?"    CALL :showhelp
    if /i "%1"=="-h"    CALL :showhelp
    shift
    if not -%1-==-- goto processargs
    GOTO exitscript

REM Build the game and tests.
:runall
    CALL :runbuild
    ECHO.
    CALL :runbuildtest
    EXIT /b

REM Build the game.
:runbuild
    ECHO Building %APPNAME%...
    IF EXIST "vts.z5" (
        DEL vts.z5
    )
    %COMPILER% +inform6 ++Extensions ++Source -S vts.inf
    EXIT /b

REM Built the tests.
:runbuildtest
    ECHO Building %APPNAME% tests...
    IF EXIST "test_vts.z5" (
        DEL test_vts.z5
    )
    %COMPILER% +inform6 ++Extensions ++Source -S test_vts.inf
    EXIT /b

REM Cleanup build artifacts.
:runclean
    ECHO Cleaning %APPNAME%...
    IF EXIST "vts.z5" (
        DEL vts.z5
    )
    IF EXIST "test_vts.z5" (
        DEL test_vts.z5
    )
    EXIT /b

REM Build the game with debug enabled.
:rundebug
    ECHO Building %APPNAME%...
    IF EXIST "vts.z5" (
        DEL vts.z5
    )
    %COMPILER% +inform6 ++Extensions ++Source -SD vts.inf
    EXIT /b

REM Run the tests.
:runtests
    CALL :runbuildtest
    ECHO.
    ECHO Running %APPNAME% Unit tests...
    ECHO. | %INTERPRETER% -p -Z 2 test_vts.z5
    ECHO.
    EXIT /b

REM Show some help text.
:showhelp
    ECHO %APPNAME% Windows Build Script
    ECHO Performs build tasks for %APPNAME%.
    ECHO.
    ECHO Commands:
    ECHO all   - Build the game and the tests.
    ECHO build - Builds the %APPNAME% game. (Default)
    ECHO clean - Delete all built files.
    ECHO debug - Build the game with debug enabled.
    ECHO help  - Display this help text.
    ECHO test  - Build then run the %APPNAME% tests.
    GOTO exitscript

REM Exit the script.
:exitscript