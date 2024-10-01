#!/usr/bin/env sh
# Build te Volunteer For Survival game.
# See the README file for details.

# Compiler setting:
export INFORM_COMPILER='./inform6/inform' # Use this line for the included compiler.
#export INFORM_COMPILER='inform' # Use this line for the system compiler.

echo "Building Volunteer For Survival..."
echo "If this fails see the file README."
echo ""

$INFORM_COMPILER +inform6 ++Extensions ++Source -S vts.inf