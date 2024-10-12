@ECHO OFF
REM Build the Volunteer For Survival game.
REM See the README file for details.
REM See the following for help in BAT scripts.
REM https://en.wikibooks.org/wiki/Windows_Batch_Scripting

REM Set the compiler.
REM This one is the included compiler for Windows.
SET COMPILER=inform6\inform6
REM This one expects the inform compiler to be included in the path.
REM SET COMPILER="inform6"

REM Set the dfrotz intepreter command for running the tests.
SET INTERPRETER=inform6\dfrotz

REM The name of this script for help text.
SET THISSCRIPT=%0

REM Application name for output.
SET APPNAME=Volunteer For Survival

REM The output file for the integration test results.
SET INTEGOUT=integ_results.txt

REM The name of the docker image.
SET DOCKERIMAGE=vts:0.0

REM Did the user disable Docker.
SET USEDOCKER=yes
IF /I -%1-==-/D- (
    SET USEDOCKER=no
    SHIFT
)

REM Check if Docker is installed.
IF %USEDOCKER% == yes CALL :DockerCheck

REM If using Docker then run the build there.
IF %USEDOCKER% == yes GOTO :DockerRun

REM       -----===== Process Command Line ======------

REM Check for a command line argument.
REM If none just run the build.
IF -%1-==-- (
    ECHO No option provided, defaulting to 'build'.
    ECHO See '%0 help' for more information.
    ECHO.
    GOTO RunBuild
)

REM Figure out what we were given on the command line.
:ProcessArgs
    IF /I "%1"=="all"   CALL :RunAll
    IF /I "%1"=="build" CALL :RunBuild
    IF /I "%1"=="clean" CALL :RunClean
    IF /I "%1"=="debug" CALL :RunDebug
    IF /I "%1"=="integ" CALL :RunInteg
    IF /I "%1"=="unit"  CALL :RunUnit
    IF /I "%1"=="test"  CALL :RunTests
    IF /I "%1"=="tests" CALL :RunTests
    IF /I "%1"=="help"  GOTO :ShowHelp
    IF /I "%1"=="/?"    GOTO :ShowHelp
    IF /I "%1"=="/h"    GOTO :ShowHelp
    IF /I "%1"=="-h"    GOTO :ShowHelp
    SHIFT
    IF NOT -%1-==-- GOTO ProcessArgs
    GOTO exitscript

REM       -----===== Build Functions ======------

REM Build the game and tests.
:RunAll
    CALL :RunBuild
    ECHO.
    CALL :RunBuildUnit
    EXIT /B

REM Build the game.
:RunBuild
    ECHO Building %APPNAME%...
    CALL :DeleteFile "vts.z5"
    CALL :CompileFile "vts.inf"
    EXIT /B

REM Built the tests.
:RunBuildUnit
    ECHO Building %APPNAME% unit tests...
    CALL :DeleteFile "Utilities\unit.z5"
    CALL :CompileFile "Utilities\unit.inf" "Utilities\unit.z5"
    EXIT /B

REM Cleanup build artifacts.
:RunClean
    ECHO Cleaning %APPNAME%...
    CALL :DeleteFile "vts.z5"
    CALL :DeleteFile "Utilities\unit.z5"
    CALL :DeleteFile "%INTEGOUT%"
    EXIT /B

REM Build the game with debug enabled.
:RunDebug
    ECHO Building %APPNAME%...
    CALL :DeleteFile "vts.z5"
    CALL :CompileFile "-D" "vts.inf"
    EXIT /B

REM Run the integration tests.
:RunInteg
    CALL :RunBuild
    ECHO.
    ECHO Running %APPNAME% Integration tests...
    SET ERRORCOUNT=0
    SET TESTCOUNT=0
    CALL :DeleteFile "%INTEGOUT%"
    ECHO %APPNAME% Integration Test Results>> %INTEGOUT%
    ECHO.>> %INTEGOUT%

    REM Loop over the tests and run each one.
    FOR %%I IN (Tests\*.rec) DO CALL :RunIntegTest %%~nI

    REM Check if there were errors.
    ECHO.
    if %ERRORCOUNT% EQU 0 (
        ECHO All tests were successful!
    ) else (
        ECHO Tests have failed: %ERRORCOUNT% out of %TESTCOUNT% tests
        ECHO See the file '%INTEGOUT%' for more information.
    )
    EXIT /B

REM Run an integration test.
:RunIntegTest
    SET TEST_FILE=%1
    CALL :WriteStringNoEOL "%INTEGOUT%" "Running Integ Test: %TEST_FILE%..."
    SET /A TESTCOUNT = %TESTCOUNT% + 1
    TYPE Tests\%TEST_FILE%.rec | %INTERPRETER% vts.z5 > Tests\temp.txt 2>&1
    FC /w Tests\%TEST_FILE%.txt Tests\temp.txt >> %INTEGOUT%
    IF %ERRORLEVEL% EQU 0 (
        CALL :WriteString "%INTEGOUT%" "Succeeded."
    ) else (
        CALL :WriteString "%INTEGOUT%" "Failed!"
        SET /A ERRORCOUNT = %ERRORCOUNT% + 1
    )
    DEL Tests\temp.txt
    EXIT /B

REM Run the unit tests.
:RunUnit
    CALL :RunBuildUnit
    ECHO.
    ECHO Running %APPNAME% unit tests...
    ECHO. | %INTERPRETER% -h 100 -p -Z 2 Utilities\unit.z5
    ECHO.
    EXIT /B

REM Run the tests.
:RunTests
    ECHO Running %APPNAME% tests...
    CALL :RunUnit
    CALL :RunInteg
    EXIT /B

REM       -----===== Help Text ======------

REM Show some help text.
:ShowHelp
    ECHO %APPNAME% Windows Build Script
    ECHO Performs build tasks for %APPNAME%.
    ECHO Usage %THISSCRIPT% [OPTIONS] COMMAND(s)
    ECHO.
    ECHO Commands:
    ECHO all   - Build the game and the unit tests.
    ECHO build - Builds the %APPNAME% game. (Default)
    ECHO clean - Delete all built files.
    ECHO integ - Run the integration tests.
    ECHO debug - Build the game with debug enabled.
    ECHO help  - Display this help text. Also /H or /?
    ECHO tests - Build and run all tests for %APPNAME%.
    ECHO unit  - Build then run the %APPNAME% unit tests.
    ECHO.
    ECHO Options:
    ECHO /D    - Do not use Docker, even if it is available.
    GOTO :exitscript

REM       -----===== Helper Functions ======------

REM Compile a file.
:CompileFile
    %COMPILER% +inform6 ++Extensions ++Source -S %~1 %~2  %~3  %~4
    EXIT /B

REM Delete a file if it exists.
REM %1 - The file to delete.
:DeleteFile
    IF EXIST %1 (
        DEL %1
    )
    EXIT /B

REM Write a string to STDOUT and the log file.
REM %1 - The file to write the string to.
REM %2 - The string to write.
:WriteString
    IF -%1-==-- (
        ECHO.
        ECHO.>> %1%
    ) else (
        ECHO %~2
        ECHO %~2>> %1%
    )
    EXIT /B

REM Write a string to STDOUT and the log file. Special case.
REM No newline is output to STDOUT and a space is added to the end.
REM %1 - The file to write the string to.
REM %2 - The string to write.
:WriteStringNoEOL
    IF -%1-==-- (
        ECHO.
        ECHO.>> %1%
    ) else (
        set <NUL /p="%~2 "
        ECHO %~2>> %1%
    )
    EXIT /B

REM       -----===== Docker Functions ======------

REM Build the Docker image if it does not already exist.

:DockerBuildImage
    SET HASIMAGE=no
    FOR /F %%F IN ('docker images -q %DOCKERIMAGE%') DO SET HASIMAGE=%%F

    if %HASIMAGE% == no (
        ECHO Building the Docker Image...
        docker buildx build --tag %DOCKERIMAGE% - < Dockerfile
        ECHO Complete.
    )
    EXIT /B

REM Check if Docker is installed.
:DockerCheck
    docker --help > NUL 2>&1
    IF %ERRORLEVEL% EQU 0 (
        ECHO Docker detected...
    ) else (
        SET USEDOCKER=no
    )
    EXIT /B

REM Run the build in Docker.
:DockerRun
    REM Check if Docker is running.
    docker stats --no-stream > NUL 2>&1
    IF %ERRORLEVEL% NEQ 0 (
        ECHO Docker is not running. Aborting!
        GOTO :exitscript
    )

    CALL :DockerBuildImage

    ECHO Running the build in Docker...
    docker run --rm -t -v "%CD%:/src" %DOCKERIMAGE% bash -c -e "cd /src; bash build.sh %1 %2 %3 %4 %5"
    GOTO :exitscript

REM Exit the script.
:exitscript