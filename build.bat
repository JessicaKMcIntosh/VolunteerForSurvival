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

REM Application name for output.
SET APPNAME=Volunteer For Survival

REM The output file for the integration test results.
SET INTEGOUT=integ_results.txt

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
    if /i "%1"=="all"   CALL :RunAll
    if /i "%1"=="build" CALL :RunBuild
    if /i "%1"=="clean" CALL :RunClean
    if /i "%1"=="debug" CALL :RunDebug
    if /i "%1"=="integ" CALL :RunInteg
    if /i "%1"=="unit"  CALL :RunUnit
    if /i "%1"=="test"  CALL :RunTests
    if /i "%1"=="tests" CALL :RunTests
    if /i "%1"=="help"  CALL :ShowHelp
    if /i "%1"=="/?"    CALL :ShowHelp
    if /i "%1"=="/h"    CALL :ShowHelp
    if /i "%1"=="-h"    CALL :ShowHelp
    shift
    if not -%1-==-- goto ProcessArgs
    GOTO exitscript

REM Build the game and tests.
:RunAll
    CALL :RunBuild
    ECHO.
    CALL :RunBuildtest
    EXIT /b

REM Build the game.
:RunBuild
    ECHO Building %APPNAME%...
    CALL :DeleteFile "vts.z5"
    CALL :CompileFile "vts.inf"
    EXIT /b

REM Built the tests.
:RunBuildtest
    ECHO Building %APPNAME% unit tests...
    CALL :DeleteFile "unit.z5"
    CALL :CompileFile "unit.inf"
    EXIT /b

REM Cleanup build artifacts.
:RunClean
    ECHO Cleaning %APPNAME%...
    CALL :DeleteFile "vts.z5"
    CALL :DeleteFile "unit.z5"
    CALL :DeleteFile "%INTEGOUT%"
    EXIT /b

REM Build the game with debug enabled.
:RunDebug
    ECHO Building %APPNAME%...
    CALL :DeleteFile "vts.z5"
    CALL :CompileFile "vts.inf" "-D"
    EXIT /b

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
    FOR %%I IN (Tests/*.rec) DO CALL :RunIntegTest %%~nI

    REM Check if there were errors.
    ECHO.
    if %ERRORCOUNT% EQU 0 (
        ECHO All tests were successful!
    ) else (
        ECHO Tests have failed: %ERRORCOUNT% out of %TESTCOUNT% tests
        ECHO See the file '%INTEGOUT%' for more information.
    )
    EXIT /b

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
    EXIT /b

REM Run the unit tests.
:RunUnit
    CALL :RunBuildtest
    ECHO.
    ECHO Running %APPNAME% unit tests...
    ECHO. | %INTERPRETER% -h 100 -p -Z 2 unit.z5
    ECHO.
    EXIT /b

REM Run the tests.
:RunTests
    ECHO Running %APPNAME% tests...
    CALL :RunUnit
    CALL :RunInteg
    EXIT /b

REM Show some help text.
:ShowHelp
    ECHO %APPNAME% Windows Build Script
    ECHO Performs build tasks for %APPNAME%.
    ECHO.
    ECHO Commands:
    ECHO all   - Build the game and the unit tests.
    ECHO build - Builds the %APPNAME% game. (Default)
    ECHO clean - Delete all built files.
    ECHO integ - Run the integration tests.
    ECHO debug - Build the game with debug enabled.
    ECHO help  - Display this help text.
    ECHO tests - Build and run all tests for %APPNAME%.
    ECHO unit  - Build then run the %APPNAME% unit tests.
    GOTO exitscript

REM       -----===== Helper functions. ======------

REM Compile a file.
REM %1 - The file to compile.
REM %2 - Any extra compile options.
:CompileFile
    %COMPILER% +inform6 ++Extensions ++Source -S %~2 %~1
    EXIT /b

REM Delete a file if it exists.
REM %1 - The file to delete.
:DeleteFile
    IF EXIST %1 (
        DEL %1
    )
    EXIT /b

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
    EXIT /b

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
    EXIT /b

REM Exit the script.
:exitscript