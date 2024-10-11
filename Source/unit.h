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
! Main testing interface:
!
! Run a test. Executes the provided routine.
! Unit_RunTest(RoutineName);
!
! After running at least one test the report will print the number of tests
! run, failed and successful.
! Unit_Report();
!
! Assertions:
! For all assertions setting Continue to true will continue execution if the
! assertion fails. By default the test stops at the first failed assertion.
!
! If an assertion fails ErrorText is printed along with the text name and
! the expected and actual values.
!
! Executes a routine and captures any output that is printed.
! The output is compared to a string.
! Requires the library istring.h to be loaded.
! Unit_AssertCapture(RoutineName, ExpectedOutput, ErrorText, Continue);
!
! Checks that ActualValue matches ExpectedValue.
! Unit_AssertEquals(ExpectedValue, ActualValue, ErrorText, Continue);
!
! Checks if Condition is false.
! Unit_AssertFalse(Condition, ErrorText, Continue);
!
! Checkes that Object belongs to the class Expected.
! Unit_AssertOfClass(Object, Expected, ErrorText, Continue);
!
! Checks that Value is not equal to nothing.
! Unit_AssertNotNothing(Value, ErrorText, Continue);
!
! Compares the strings Expected and Actual using the StrCmp routine.
! Requires the library istring.h to be loaded.
! Unit_AssertStrCmp(Expected, Actual, ErrorText, Continue);
!
! Checks if Condition is true.
! Unit_AssertTrue(Condition, ErrorText, Continue);
!
! Always fails.
! Unit_Fail(ErrorText, Continue);
! ------------------------------------------------------------------------------
! USAGE - Object
! ------------------------------------------------------------------------------
! An object interface is provided to make creating and running tests easier.
! All objects created from the class Unit_Test_Class will be run.
!
! Create a unit object to run the tests with.
! Unit_Class Unit "Unit testing object";
!
! Create a unit test object with the property RunTest created to run the tests.
! Unit_Test_Class Unit_Test "Unit Test"
!   with
!     RunTest [;
!       Unit_AssertTrue(true, "True should always be true.");
!     ];
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
! Test Objects
! ------------------------------------------------------------------------------

! Fake player class to make the standard library happy.
Class Fake_Player(1)
  class SelfClass;

! Class to run the unit tests.
Class Unit_Class
  with
    Run [
      Test;
      objectloop (Test ofclass Unit_Test_Class) {
        Test.Run();
      }
    ],
    Report [;
      Unit_Report();
    ];

! Class to create a unit test.
Class Unit_Test_Class
  with
    ! Run this test object.
    Run [;
      print "Running Tests for ", (name) self, "...^";
      self.Initialize();
      self.RunTest();
    ],
    ! Placeholder for the actual tests to be run.
    RunTest [; ],
    ! Initialize data so tests run in a normalish environment.
    Initialize [;
      ! Prepare the player.
      if (player ~= nothing) Fake_Player.destroy(player);
      player = Fake_Player.create();
      deadflag = 0;

      ! Prepare action processing.
      action = nothing;
      inp1 = nothing;
      inp2 = nothing;
      noun = nothing;
      second = nothing;

      ! Prepare the scoring variables.
      score = 0;
      last_score = 0;
      places_score = 0;
      things_score = 0;

      ! Other random variables.
      lookmode = 2;
      turns = 0;
    ];

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
  Routine   ! (Required) The routine to capture output for.
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

! Check if the object is of the expected class.
[ Unit_AssertOfClass
  Object    ! (Required) The object to test.
  Expected  ! (Required) The expected class.
  ErrorText ! (Required) Error text to print on failure.
  Continue; ! (Optional) Continue execution after a failure.

  if (_Unit_Assert((Object ofclass Expected), ErrorText, "AssertOfClass")) {
    print "[The object (", (name) Object, ") is not of the class (", (name) Expected, ")]^^";
    _Unit_Throw(Continue);
  }
];

! Check if the value is not equal to nothing.
[ Unit_AssertNotNothing
  Value     ! (Required) The value to test.
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
