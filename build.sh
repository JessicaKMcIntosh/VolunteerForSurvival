#!/usr/bin/env bash
# Build te Volunteer For Survival game.
# See the README file for details.
# This is a port of the build.bat file to Bash.

# Enforce some safety.
set -o errexit  # Abort on nonzero exitstatus.
set -o nounset  # Abort on unbound variable.
set -o pipefail # Don't hide errors within pipes.

# Compiler setting:
#readonly INFORM_COMPILER="./inform6/inform" # Use this line for the included compiler.
readonly INFORM_COMPILER="inform" # Use this line for the system compiler.

# Debian likes to put games like Frotz in '/usr/games/' and then not add this
# directory to the PATH.
if [[ -d "/usr/games" ]] ; then
    PATH="$PATH:/usr/games";
fi

# If using the local compiler make sure it is executable.
if [[ "$INFORM_COMPILER" = "./inform6/inform" &&  ! -x "$INFORM_COMPILER" ]] ; then
    chmod +x $INFORM_COMPILER
fi

# The name of this script for help text.
readonly THISSCRIPT="$0"

# Set the dfrotz interpreter command for running the tests.
readonly INTERPRETER="dfrotz"

# Application name for output.
readonly APPNAME="Volunteer For Survival"

# The output file for the integration test results.
readonly INTEGOUT="integ_results.txt"

# Counts for running the integration tests.
ERRORCOUNT=0
TESTCOUNT=0

# The name of the docker image.
readonly DOCKERIMAGE="vts:0.0"

# Is Docker being used?
USEDOCKER="YES"

# Verbose output?
VERBOSE="NO"

# Any compile options to add.
COMPILEOPTIONS=()

# Actions passed on the command line.
ACTIONS=()

#       -----===== Build Functions ======------

# Build the city.h file, the game and run the unit and integ tests.
function RunAll {
    RunCity
    echo ""
    RunBuild
    echo ""
    RunUnit
    echo ""
    RunInteg
}

# Build the game.
function RunBuild {
    CheckCompiler
    echo "Building ${APPNAME}..."
    DeleteFile "vts.z5"
    CompileFile "vts.inf"
}

# Build the city.h file.
function RunCity {
    CheckCompiler
    CheckInterpreter
    echo "Building ${APPNAME} Source/city.h..."
    echo "Compiling Utilities/gencity.inf..."
    DeleteFile "Utilities/gencity.z5"
    if ! CompileFile "Utilities/gencity.inf" "Utilities/gencity.z5" ; then
        echo "Error compiling. Aborting!"
        exit 1
    fi
    echo "Generating Source/city.h..."
    DeleteFile "Source/city.h"
    $INTERPRETER -h 100000 -m -p -q -w 100 Utilities/gencity.z5 > Source/city.h
    DeleteFile "Utilities/gencity.z5"
}

# Cleanup build artifacts.
function RunClean {
    echo "Cleaning ${APPNAME}..."
    DeleteFile "vts.z5" "YES"
    DeleteFile "Tests/unit.z5" "YES"
    DeleteFile "Tests/vts.z5" "YES"
    DeleteFile "${INTEGOUT}" "YES"
    for file in Tests/*.out; do
        DeleteFile "${file}" "YES"
    done
}

# Build the game with debug enabled.
function RunDebug {
    CheckCompiler
    echo "Building ${APPNAME}..."
    DeleteFile "vts.z5"
    CompileFile "-D" "vts.inf"
}

# Run the integration tests.
function RunInteg {
    local file
    CheckCompiler
    CheckInterpreter
    DeleteFile "Tests/vts.z5"
    echo "Building ${APPNAME} with the random number seeded to eliminate randomness..."
    if ! CompileFile '$#RANDOM_SEED=-1' "vts.inf" "Tests/vts.z5" ; then
        echo "Error compiling. Aborting!"
        exit 1
    fi
    echo ""
    echo "Running ${APPNAME} Integration tests..."
    DeleteFile "${INTEGOUT}"
    echo "${APPNAME} Integration Test Results" >> ${INTEGOUT}
    echo "" >> "${INTEGOUT}"

    # Loop over the tests and run each one.
    for file in Tests/*.rec; do
        RunIntegTest "${file}"
    done

    # Check if there were errors.
    echo ""
    if [[ ${ERRORCOUNT} -eq "0" ]] ; then
        echo "All tests were successful!"
        DeleteFile "${INTEGOUT}"
    else
        echo "Tests have failed: ${ERRORCOUNT} out of ${TESTCOUNT} tests"
        echo "See the file '${INTEGOUT}' for more information."
    fi
    DeleteFile "Tests/vts.z5"
}

# Run an integration test.
# $1 - The test recorded input file.
function RunIntegTest {
    local test_file="${1%.rec}"
    local rec_file="${test_file}.rec"
    local out_file="${test_file}.out"
    local txt_file="${test_file}.txt"
    WriteString "${INTEGOUT}" "Running Integ Test: ${test_file}..."
    TESTCOUNT=$((TESTCOUNT + 1))
    DeleteFile "${out_file}"
    (
        echo "transcript"
        echo "${out_file}"
        grep -v -e '^#' -e '^$' "${rec_file}"
        echo "quit"
        echo "yes"
    ) | ${INTERPRETER} -m -q Tests/vts.z5 > /dev/null 2>&1
    if diff -w "${txt_file}" "${out_file}" > /dev/null ; then
        WriteString "${INTEGOUT}" "Succeeded."
        DeleteFile "${out_file}"
    else
        WriteString "${INTEGOUT}" "Failed! See the file '${out_file}' for test output."
        diff -w "${txt_file}" "${out_file}" >> "${INTEGOUT}"
        ERRORCOUNT=$((ERRORCOUNT + 1))
    fi
}

# Run the unit tests.
function RunUnit {
    CheckCompiler
    CheckInterpreter
    echo "Building ${APPNAME} unit tests..."
    DeleteFile "Tests/unit.z5"
    # Verbose mode requested?
    if [[ "$VERBOSE" = "YES" ]]; then
        COMPILEOPTIONS+=('$#UNIT_VERBOSE=1')
    fi
    if ! CompileFile "++Tests" "Tests/unit.inf" "Tests/unit.z5" ; then
        echo "Error compiling. Aborting!"
        exit 1
    fi
    echo ""
    echo "Running ${APPNAME} unit tests..."
    echo "" | ${INTERPRETER} -h 100000 -m -p -q -w 100 -Z 2 "Tests/unit.z5"
    echo ""
    DeleteFile "Tests/unit.z5"
}

# Run the tests.
function RunTests {
    CheckCompiler
    CheckInterpreter
    echo "Running ${APPNAME} tests..."
    RunUnit
    RunInteg
}

#       -----===== Help Text ======------

# Show some help text.
function ShowHelp {
    echo "${APPNAME} Linux Build Script"
    echo "Performs build tasks for ${APPNAME}."
    echo "Usage: ${THISSCRIPT} [OPTIONS] COMMANDS(s)"
    echo ""
    echo "Commands:"
    echo "all    - Build the city.h file, the game and run the tests."
    echo "build  - Builds the ${APPNAME} game. (Default)"
    echo "city   - Build the city.h file."
    echo "clean  - Delete all built files."
    echo "docker - Starts an interactive Docker container."
    echo "integ  - Run the integration tests."
    echo "debug  - Build the game with debug enabled."
    echo "help   - Display this help text."
    echo "tests  - Build and run all tests for ${APPNAME}."
    echo "unit   - Build then run the ${APPNAME} unit tests."
    echo ""
    echo "Options:"
    echo "-D    - Do not use Docker, even if it is available."
    echo "-h    - Display this help text."
    echo "-v    - Verbos output. Only applies in a few places."
    echo ""
    echo "Other options are passed to the compiler."
    exit;
}

#       -----===== Helper Functions ======------

# Check if the compiler is installed.
function CheckCompiler {
    if ! which "$INFORM_COMPILER" > /dev/null ; then
        echo "The compiler '$INFORM_COMPILER' is not installed."
        echo "Aborting!!"
        exit 1
    fi
}

# Check if the interpreter is installed.
function CheckInterpreter {
    if ! which "$INTERPRETER" > /dev/null ; then
        echo "The interpreter '$INTERPRETER' is not installed."
        echo "Aborting!!"
        exit 1
    fi
}

# Compile a file.
function CompileFile {
    if ! ${INFORM_COMPILER} +inform6 ++Extensions ++Source -S "${COMPILEOPTIONS[@]}" "$@" ; then
        echo "Error compiling. Aborting!"
        exit 1
    fi
}

# Delete a file if it exists.
# $1 - The file to delete.
# $2 - If "YES" be verbose.
function DeleteFile {
    local file="${1}"
    local verbose="${2:-}"
    if [[ -f "${file}" ]] ; then
        if [[ "$verbose" == "YES" ]]; then
            echo "Deleting '${file}'..."
        fi
        rm -f "${file}"
    fi
}

# Write a string to STDOUT and append to a file.
# $1 - The file to write the string to.
# $2 - The string to write.
function WriteString {
    local file="${1}"
    local str="${2}"
    echo "${str}" | tee -a "${file}"
}

#       -----===== Docker Functions ======------

# Build the Docker image if it does not already exist.
function DockerBuildImage {
    if [[ -z "$(docker images -q ${DOCKERIMAGE})" ]]; then
        echo "Building the Docker Image..."
        docker buildx build --tag ${DOCKERIMAGE} - < Dockerfile
        echo "Complete."
    fi
}

# Starts an interactive Docker container.
function DockerInteractive {
    echo "Starting an interactive Docker container..."
    DockerBuildImage
    docker run  --rm \
                -t \
                -i \
                -v "${PWD}:/src" \
                -w "/src/" \
                -u "$(id -u):$(id -g)" \
                ${DOCKERIMAGE} \
                bash
    exit
}

# Check if Docker is installed.
function DockerCheck {
    if docker --version >> /dev/null 2>&1 ; then
        echo Docker detected...
    else
        USEDOCKER="NO"
    fi
}

# Run the build in Docker.
function DockerRun {
    # Check if Docker is running.
    if ! pgrep docker > /dev/null; then
        echo "Docker is not running. Aborting!"
        exit 1
    fi

    DockerBuildImage

    echo "Running the build in Docker..."
    docker run  --rm \
                -t \
                -v "${PWD}:/src" \
                -w "/src/" \
                -u "$(id -u):$(id -g)" \
                ${DOCKERIMAGE} \
                bash -c -e "bash build.sh $PARAMS"
    exit
}

#       -----===== Process Command Line ======------

# Check for standard type command line switches.
# Anything looking like an option is just passed on to the compiler.
# Everything else is saved as an action for later.
while [[ "$#" -gt "0" ]] ; do
    case "$1" in
        help)   ShowHelp;;
        -\?)    ShowHelp;;
        /\?)    ShowHelp;;
        /h)     ShowHelp;;
        -h)     ShowHelp;;
        -D)     USEDOCKER="NO";;
        /D)     USEDOCKER="NO";;
        -v)     VERBOSE="YES";;
        /v)     VERBOSE="YES";;
        --)     break;;
        -*)     COMPILEOPTIONS+=("$1");;
        *)      ACTIONS+=("$1");;
    esac
    shift
done

# Grab anything left over in case -- is given.
# This includes the -- since this might be going to Docker.
ACTIONS+=("${@}")

# Check if Docker is installed.
if [[ "$USEDOCKER" = "YES" ]]; then
    DockerCheck
fi

# Special case for running an interactive Docker container.
if [[ "$#" -gt "0" && "$1" = "docker" ]]; then
    DockerInteractive
fi

# If using Docker then run the build there.
if [[ "$USEDOCKER" = "YES" ]]; then
    PARAMS="${COMPILEOPTIONS[*]} ${ACTIONS[*]}"
    DockerRun
fi

# Default to build if no options given.
if [[ "${#ACTIONS[@]}" -eq "0" ]] ; then
    echo "No option provided, defaulting to 'build'."
    echo "See '$THISSCRIPT help' for more information."
    echo ""
    RunBuild
    echo "Complete."
    exit
fi

# Figure out what we were given on the command line.
set -- "${ACTIONS[@]}"
while [[ "$#" -gt "0" ]] ; do
    case "$1" in
        all)    RunAll    ;;
        city)   RunCity   ;;
        build)  RunBuild  ;;
        clean)  RunClean  ;;
        debug)  RunDebug  ;;
        integ)  RunInteg  ;;
        unit)   RunUnit   ;;
        test)   RunTests  ;;
        tests)  RunTests  ;;
    esac
    shift
done
echo "Complete."
