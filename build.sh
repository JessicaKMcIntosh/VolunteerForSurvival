#!/usr/bin/env bash
# Build te Volunteer For Survival game.
# See the README file for details.

# Compiler setting:
INFORM_COMPILER="./inform6/inform" # Use this line for the included compiler.
#INFORM_COMPILER="inform" # Use this line for the system compiler.

# If using the local compiler make sure it is executable.
if [[ "$INFORM_COMPILER" = "./inform6/inform" &&  ! -x "$INFORM_COMPILER" ]] ; then
    chmod +x $INFORM_COMPILER
fi

# Set the dfrotz intepreter command for running the tests.
INTERPRETER="dfrotz"

# Application name for output.
APPNAME="Volunteer For Survival"

# The output file for the integration test results.
INTEGOUT="integ_results.txt"

# Counts for running the integration tests.
ERRORCOUNT=0
TESTCOUNT=0

# Build the game and tests.
function RunAll {
    RunBuild
    echo ""
    RunBuildtest
}

# Build the game.
function RunBuild {
    echo "Building ${APPNAME}..."
    DeleteFile "vts.z5"
    CompileFile "vts.inf"
}

# Built the tests.
function RunBuildtest {
    echo "Building ${APPNAME} unit tests..."
    DeleteFile "unit.z5"
    CompileFile "unit.inf"
}

# Cleanup build artifacts.
function RunClean {
    echo "Cleaning ${APPNAME}..."
    DeleteFile "vts.z5"
    DeleteFile "unit.z5"
    DeleteFile "${INTEGOUT}"
}

# Build the game with debug enabled.
function RunDebug {
    echo "Building ${APPNAME}..."
    DeleteFile "vts.z5"
    CompileFile "vts.inf" "-D"
}

# Run the integration tests.
function RunInteg {
    RunBuild
    echo ""
    echo "Running ${APPNAME} Integration tests..."
    DeleteFile "${INTEGOUT}"
    echo "${APPNAME} Integration Test Results" >> ${INTEGOUT}
    echo "" >> ${INTEGOUT}

    # Loop over the tests and run each one.
    for file in $(ls Tests/*.rec); do
        RunIntegTest $(basename $file)
    done

    # Check if there were errors.
    echo ""
    if [[ ${ERRORCOUNT} -eq "0" ]] ; then
        echo "All tests were successful!"
    else
        echo "Tests have failed: ${ERRORCOUNT} out of ${TESTCOUNT} tests"
        echo "See the file '${INTEGOUT}' for more information."
    fi
}

# Run an integration test.
function RunIntegTest {
    TEST_FILE="${1%.rec}"
    WriteStringNoEOL "${INTEGOUT}" "Running Integ Test: ${TEST_FILE}..."
    TESTCOUNT=$((TESTCOUNT + 1))
    cat "Tests/${TEST_FILE}.rec" | ${INTERPRETER} -q vts.z5 > Tests/temp.txt 2>&1
    diff -w "Tests/${TEST_FILE}.rec" Tests/temp.txt > /dev/null
    if [[ "$?" -eq "0" ]] ; then
        WriteString "${INTEGOUT}" "Succeeded."
    else
        WriteString "${INTEGOUT}" "Failed!"
        ERRORCOUNT=$((ERRORCOUNT + 1))
    fi
    rm -f Tests/temp.txt
}

# Run the unit tests.
function RunUnit {
    RunBuildtest
    echo ""
    echo "Running ${APPNAME} unit tests..."
    echo "" | ${INTERPRETER} -h 100 -p -Z 2 unit.z5
    echo ""
}

# Run the tests.
function RunTests {
    echo "Running ${APPNAME} tests..."
    RunUnit
    RunInteg
}

# Show some help text.
function ShowHelp {
    echo "${APPNAME} Windows Build Script"
    echo "Performs build tasks for ${APPNAME}."
    echo ""
    echo "Commands:"
    echo "all   - Build the game and the unit tests."
    echo "build - Builds the ${APPNAME} game. (Default)"
    echo "clean - Delete all built files."
    echo "integ - Run the integration tests."
    echo "debug - Build the game with debug enabled."
    echo "help  - Display this help text."
    echo "tests - Build and run all tests for ${APPNAME}."
    echo "unit  - Build then run the ${APPNAME} unit tests."
    exit;
}

#       -----===== Helper functions. ======------

# Compile a file.
# %1 - The file to compile.
# %2 - Any extra compile options.
function CompileFile {
    ${INFORM_COMPILER} +inform6 ++Extensions ++Source -S $2 $1
}

# Delete a file if it exists.
# %1 - The file to delete.
function DeleteFile {
    if [[ -f $1 ]] ; then
        rm -f $1
    fi
}

# Write a string to STDOUT and the log file.
# %1 - The file to write the string to.
# %2 - The string to write.
function WriteString {
    echo "$2"
    echo "$2" >> $1
}

# Write a string to STDOUT and the log file. Special case.
# No newline is output to STDOUT and a space is added to the end.
# %1 - The file to write the string to.
# %2 - The string to write.
function WriteStringNoEOL {
    echo -n "$2"
    echo -n "$2" >> $1
}

# Default to build if no options given.
if [[ "$#" -eq "0" ]] ; then
    echo "No option provided, defaulting to 'build'."
    echo "See '$0 help' for more information."
    echo ""
    RunBuild
fi

# Figure out what we were given on the command line.
while [[ "$#" -gt "0" ]] ; do
    if  [[ "$1" = "all"   ]] then RunAll   ; fi
    if  [[ "$1" = "build" ]] then RunBuild ; fi
    if  [[ "$1" = "clean" ]] then RunClean ; fi
    if  [[ "$1" = "debug" ]] then RunDebug ; fi
    if  [[ "$1" = "integ" ]] then RunInteg ; fi
    if  [[ "$1" = "unit"  ]] then RunUnit  ; fi
    if  [[ "$1" = "test"  ]] then RunTests ; fi
    if  [[ "$1" = "tests" ]] then RunTests ; fi
    if  [[ "$1" = "help"  ]] then ShowHelp ; fi
    if  [[ "$1" = "/?"    ]] then ShowHelp ; fi
    if  [[ "$1" = "/h"    ]] then ShowHelp ; fi
    if  [[ "$1" = "-h"    ]] then ShowHelp ; fi
    shift
done
exit
