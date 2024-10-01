! ------------------------------------------------------------------------------
! Unit - Unit testing for Inform games.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
!
! This is a reimplementation of infunit.h by Matt Albrecht
! with some additions of my own to simplify unit testing.
! https://ifarchive.org/if-archive/infocom/compilers/inform6/library/contributions/infunit.h
! ------------------------------------------------------------------------------
! USAGE
! ------------------------------------------------------------------------------
! Include after Grammar.
!
! IF the istring.h library is included adds extra functionality.
!
! TODO: More details here.
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the Unit library.";

! ------------------------------------------------------------------------------
! Globals
! ------------------------------------------------------------------------------

Global Unit_TestCount = 0;
GLobal Unit_FailCount = 0;
Global _Unit_Exception;

! Only if the istring library is included.
#Ifdef ISTRING_LIBRARY;
Array _Unit_Captured->MAX_STR_LEN;
Array _Unit_Expected->MAX_STR_LEN;
#Endif;

! ------------------------------------------------------------------------------
! Interface Subroutines
! ------------------------------------------------------------------------------

! Execute the test routine.
[ Unit_RunTest
  TestRoutine;  ! The routine to test.

  ++Unit_TestCount;
  @catch -> _Unit_Exception;
  TestRoutine();
  rfalse;
];

! Print a summary report of test results.
[ Unit_Report;
  print "Test Results:^";
  print "  Tests run:    ", Unit_TestCount, "^";
  print "  Tests Passed: ", (Unit_TestCount - Unit_FailCount), "^";
  print "  Tests Failed: ", Unit_FailCount, "^";
];

! ------------------------------------------------------------------------------
! Assertion Subroutines
! ------------------------------------------------------------------------------

! Only if the istring library is included.
#Ifdef ISTRING_LIBRARY;
! Execute a routine and compare the captured output to the expected string.
[ Unit_AssertCapture
  Routine   ! The routine to capture output for.
  Expected  ! (Required) The expected string.
  ErrorText ! (Required) Error text to print on failure.
  Continue; ! (Optional) Continue execution after a failure.

  ! Execute the routine, capturing the output.
  _Unit_CaptureStart();
  Routine();
  _Unit_CaptureStop();

  ! Convert ErrorText to an array string.
  WriteString(_Unit_Expected, Expected);

  if (_Unit_Assert((StrCmp(_Unit_Expected, _Unit_Captured) == 0), ErrorText, "AssertCapture")) {
    print "[Expected (^";
    PrintString(_Unit_Expected);
    print "^) but recieved (^";
    PrintString(_Unit_Captured);
    print "^)]^^";
    _Unit_Throw(Continue);
  }
];
#Endif;

! Check if the expected value matches the actual value.
[ Unit_AssertEquals
  Expected  ! (Required) The expected value.
  Actual    ! (Required) The actual value.
  ErrorText ! (Required) Error text to print on failure.
  Continue; ! (Optional) Continue execution after a failure.

  if (_Unit_Assert((Expected == Actual), ErrorText, "AssertEquals")) {
    print "[Expected (", Expected, ") but recieved (", Actual, ")]^^";
    _Unit_Throw(Continue);
  }
];

! Check if the condition is false.
[ Unit_AssertFalse
  Condition ! (Required) Condition to test.
  ErrorText ! (Required) Error text to print on failure.
  Continue; ! (Optional) Continue execution after a failure.

  if (_Unit_Assert(~~(Condition), ErrorText, "AssertFalse")) {
    print "^";
    _Unit_Throw(Continue);
  }
];

! Check if the is value is of the expected class.
[ Unit_AssertOfClass
  Value ! (Required) The value to test.
  Actual    ! (Required) The actual value.
  ErrorText ! (Required) Error text to print on failure.
  Continue; ! (Optional) Continue execution after a failure.

  if (_Unit_Assert((Value ofclass Actual), ErrorText, "AssertOfClass")) {
    print "[The object (", (name) Value, ") is not of the class (", (name) Actual, ")]^^";
    _Unit_Throw(Continue);
  }
];

! Check if the value is not equal to nothing.
[ Unit_AssertNotNothing
  Value ! (Required) The value to test.
  ErrorText ! (Required) Error text to print on failure.
  Continue; ! (Optional) Continue execution after a failure.

  if (_Unit_Assert((Value ~= nothing), ErrorText, "AssertNotNothing")) {
    print "^";
    _Unit_Throw(Continue);
  }
];

! Only if the istring library is included.
#Ifdef ISTRING_LIBRARY;
! Check if the expected value matches the actual value using StrCmp.
[ Unit_AssertStrCmp
  Expected  ! (Required) The expected value.
  Actual    ! (Required) The actual value.
  ErrorText ! (Required) Error text to print on failure.
  Continue; ! (Optional) Continue execution after a failure.

  if (_Unit_Assert((StrCmp(Expected, Actual) == 0), ErrorText, "AssertStrCmp")) {
    print "[Expected (^";
    PrintString(Expected);
    print "^) but recieved (^";
    PrintString(Actual);
    print "^)]^^";
    _Unit_Throw(Continue);
  }
];
#Endif;

! Check if the condition is true.
[ Unit_AssertTrue
  Condition ! (Required) Condition to test.
  ErrorText ! (Required) Error text to print on failure.
  Continue; ! (Optional) Continue execution after a failure.

  if (_Unit_Assert(Condition, ErrorText, "AssertTrue")) {
    print "^";
    _Unit_Throw(Continue);
  }
];

! Always fails.
[ Unit_Fail
  ErrorText ! (Required) Error text to print on failure.
  Continue; ! (Optional) Continue execution after a failure.

  _Unit_Assert(false, ErrorText, "Fail");
  print "^";
  _Unit_Throw(Continue);
];

! ------------------------------------------------------------------------------
! Private Subroutines
! ------------------------------------------------------------------------------

! If the condition is false print an error then return true.
[ _Unit_Assert
  Condition   ! (Required) Condition to test.
  ErrorText   ! (Required) Error text to print on failure.
  Caller;     ! (Required) The assert routine.

  if (Condition == false) {
    ++Unit_FailCount;
    print "* ERROR: ", (string) Caller, " failed!^";
    if (ErrorText ~= nothing) {
      print (string) ErrorText, "^";
    }
    rtrue;
  }
  rfalse;
];

! Performs a throw if Continue is false.
[_Unit_Throw
  Continue; ! (Required) Continue execution after a failure.

  if (Continue ~= true) {
    @throw "Assertion failed!" _Unit_Exception;
  }
];

! Only if the istring library is included.
#Ifdef ISTRING_LIBRARY;
! Start capturing output to the array PrintedString.
[ _Unit_CaptureStart;
  @output_stream 3 _Unit_Captured;
];

! Stop capturing output.
[ _Unit_CaptureStop;
  @output_stream -3;
];
#Endif;
