! ------------------------------------------------------------------------------
! Unit - Unit testing for Inform games.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
!
! This is a re-implementation of infunit.h by Matt Albrecht
! with some additions of my own to simplify unit testing.
! https://ifarchive.org/if-archive/infocom/compilers/inform6/library/contributions/infunit.h
!
! String functions based on the IString library by L. Ross Raszewski
! https://ifarchive.org/if-archive/infocom/compilers/inform6/library/contributions/istring.h
! ------------------------------------------------------------------------------
! USAGE
! ------------------------------------------------------------------------------
! Include after Grammar, if using the standard library.
!
! ------------------------------------------------------------------------------
! Test functions:
!
! Run a test. Executes the provided routine.
! Unit_RunTest(RoutineName);
!
! After running at least one test the report will print the number of tests
! run, failed and succeeded.
! Unit_Report();
!
! [TestRoutine;
!   print "Really bad test.^";
!   Unit_AssertTrue(true, "True should always be true.");
! ];
!
! ------------------------------------------------------------------------------
! Assertions:
!
! For all assertions setting Continue to true will continue execution if the
! assertion fails. Otherwise an exception is thrown to Unit_RunTest(), which will
! then return false.
!
! If an assertion fails ErrorText is printed along with the test name.
! If applicable expected and actual values are printed.
!
! Executes a routine and captures any output that is printed.
! The output is compared to the string Expected.
! The Expected can be an ctual string or string array.
! Unit_AssertCapture(Routine, Expected, ErrorText, Continue);
!
! Checks that ActualValue matches Expected.
! Keep in mind strings are actually addresses, so this will not compare strings.
! Unit_AssertEquals(Expected, Actual, ErrorText, Continue);
!
! Checks if Condition is false.
! Unit_AssertFalse(Condition, ErrorText, Continue);
!
! Checks that Object belongs to the class Expected.
! Unit_AssertOfClass(Object, Expected, ErrorText, Continue);
!
! Checks that Value is not equal to nothing.
! Unit_AssertNotNothing(Value, ErrorText, Continue);
!
! Compares the strings Expected and Actual strings.
! The strings can be actual strings or string arrays.
! Unit_AssertStrCmp(Expected, Actual, ErrorText, Continue);
!
! Checks if Condition is true.
! Unit_AssertTrue(Condition, ErrorText, Continue);
!
! Always fails.
! Unit_Fail(ErrorText, Continue);
!
! ------------------------------------------------------------------------------
! Object Interface:
!
! An object interface is provided to make creating and running tests easier.
! All objects created from the class Unit_Test_Class will be run.
!
! If the Inform standard library is included various globals are set before
! each Unit_Test_Class object is run. Including creating a fake player object.
! See _Unit_Initialize_Globals() for details.
!
! Create a unit object to run the tests with.
! Unit_Class Unit "Unit testing object";
!
! Create unit test objects with the property describe created to run the tests.
! Unit_Test_Class Unit_Test "Unit Test"
!   with
!     describe [;
!       Unit_RunTest(TestRoutine);
!     ];
!
! Run the tests then generate a report.
! Unit.Run();
! Unit.Report();
!
! Tests can provide before() and after() methods that are executed before and
! and after describe() is executed, respectively.
! Why use before(), after() and describe()?
! Because they are already built into the standard library and are additive.
! And if you want to use inheritance on your tests you can.
!
! There is also a builtin self test for the internal functions.
! If the self tests fail the library will quit.
! Unit.SelfTest();
!
! Unit_Class methods:
! * Unit.Report(); - Generates the testing report. Calls Unit_Report().
! * Unit.Run(); - Runs all the tests created from Unit_Test_Class.
! * Unit.SelfTest(); - Enables builtin the test Unit_Self_Test.
! * Unit.Verbose(true|false); - Enables/Disables verbose output.
!
! Unit_Class Attributes:
! * general - If present verbose output is generated.
!
! Unit_Test_Class methods:
! * self.info() - Prints the passed variables if the test has general.
! * self.msg() - Prints the passed variables.
!
! Unit_Test_Class Attributes:
! * general - If present verbose output is generated.
! * on - If the test does not have on then it is skipped.
! * visited - Once a test is run it is given 'visited'.
!
! ------------------------------------------------------------------------------
! A note on strings:
!
! Internally arrays as strings are used for the assertions
! Unit_AssertCapture() and Unit_AssertStrCmp().
! If your test strings are longer than 200 characters then
! you will need to increase _Unit_Max_String_Length.
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the Unit library.";

! These are needed for testing if the standard library is not loaded.
#Ifndef  LIBRARY_VERSION;
  ! Taken from the file 'inform6/linklpa.h'.
  Attribute general;  ! Used to indicate verbose output is desired.
  Attribute on;       ! Enables the test.
  Attribute visited;  ! Given to the test after running it.
  #Ifdef TARGET_ZCODE;
    Constant NULL         = $ffff;
  #Ifnot; ! TARGET_GLULX
    Constant NULL         = $ffffffff;
  #Endif; ! TARGET_
  Property additive after    NULL;
  Property additive before   NULL;
  Property additive describe NULL;
  ! Taken from the file 'inform6/parser.h'.
  #Ifndef WORDSIZE;
    Constant WORDSIZE 2;
  #Endif;
Endif;

! ------------------------------------------------------------------------------
! Constants
! ------------------------------------------------------------------------------

! Maximum string length for string routines.
! Increase this number if your test strings get too long.
Constant _Unit_Max_String_Length 200;

! Strings for the self test.
Constant _Unit_Self_Test_String_Empty "";
Constant _Unit_Self_Test_String_A "A string of text for the self test.";
Constant _Unit_Self_Test_String_B "A different string of text for the self test.";
Constant _Unit_Self_Test_String_C "A different string of text for the self test.^^";

! ------------------------------------------------------------------------------
! Globals
! ------------------------------------------------------------------------------

! Test counts for the report.
Global Unit_TestCount = 0;
GLobal Unit_FailCount = 0;

! For throwing and catching.
Global _Unit_Exception;

! For string comparison. Used by Unit_AssertCapture and Unit_AssertStrCmp.
Array _Unit_Actual   buffer _Unit_Max_String_Length + WORDSIZE;
Array _Unit_Expected buffer _Unit_Max_String_Length + WORDSIZE;
Array _Unit_Scratch  buffer _Unit_Max_String_Length + WORDSIZE;

! ------------------------------------------------------------------------------
! Test Objects
! ------------------------------------------------------------------------------

! Player class to make the standard library happy.
#Ifdef LIBRARY_VERSION;
  Class Unit_Player(1)
    class SelfClass;
Endif;

! Class to run the unit tests.
Class Unit_Class
  with
    Run [
      Test;

      objectloop (Test ofclass Unit_Test_Class) {
        if (self has general) {
          give Test general;
        }

        if (Test hasnt on) {
          Test.msg("Skipping test disabled test '", Test, "'...^^");
          rfalse;
        }

        Test.info("Preparing for '", Test, "'...^");
        #Ifdef LIBRARY_VERSION;
          Test.info("Preparing Inform Library globals...^");
          _Unit_Initialize_Globals();
        #Endif;

        if (Test provides before) {
          Test.info("Running before() for '", Test, "'...^");
          Test.before();
        }

        Test.msg("Running tests for ", Test, "...^");
        Test.describe();

        if (Test provides after) {
          Test.info("Running after() for '", Test, "'...^");
          Test.after();
        }

        Test.msg("Completed testing for '", Test, "'...^^");
        give Test visited;
      }
    ],
    Report [;
      Unit_Report();
    ],
    SelfTest [;
      give Unit_Self_Test on;
    ],
    Verbose [
      Value;

      if (value) {
        give self general;
      } else {
        give self ~general;
      }
    ]
  has ~general
;

! Unit test class. Each test must inherit from this class;
Class Unit_Test_Class
  with
    ! Prints a message if the test has 'general'.
    info [a b c d e f g;
      if (self has general) _Unit_Print_Variables(a, b, c, d, e, f, g);
    ],
    ! Prints a message.
    msg [a b c d e f g;
      _Unit_Print_Variables(a, b, c, d, e, f, g);
    ],
  has ~general on ~visited
;

! Self test.
! This must run first.
Unit_Test_Class Unit_Self_Test "Unit Self Test"
  with
    describe [;
      if (_Unit_Self_Test()) {
        self.msg("Success!^");
      } else {
        self.msg("Self test failed!^Aborting!^");
        quit;
      }
    ],
    after [;
      ! Reset the counters before running the actual tests.
      Unit_TestCount = 0;
      Unit_FailCount = 0;
    ]
  has ~on
;

! ------------------------------------------------------------------------------
! Test Interface Subroutines
! ------------------------------------------------------------------------------

! Execute the test routine.
! Returns false if an exception is thrown.
[ Unit_RunTest
  TestRoutine;  ! The routine to test.

  ++Unit_TestCount;
  @catch -> _Unit_Exception;
  TestRoutine();
  rtrue;
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

! Execute a routine and compare the captured output to the expected string.
[ Unit_AssertCapture
  Routine   ! (Required) The routine to capture output for.
  Expected  ! (Required) The expected string.
  ErrorText ! (Required) Error text to print on failure.
  Continue; ! (Optional) Continue execution after a failure.

  ! Execute the routine, capturing the output.
  _Unit_Capture_Start();
  Routine();
  _Unit_Capture_Stop();

  ! Remove any stray carriage returns from the end of the captured string.
  _Unit_String_Chomp(_Unit_Actual);

  ! Convert Expected to an array string.
  if (Expected ofclass string) {
    Expected.print_to_array(_Unit_Expected);
  } else {
    _Unit_String_Copy(Expected, _Unit_Expected);
  }

  ! Compare the strings.
  if (_Unit_Assert(_Unit_String_Compare(), ErrorText, "AssertCapture")) {
    print "[Expected (^";
    _Unit_String_Print(_Unit_Expected);
    print "^) but received (^";
    _Unit_String_Print(_Unit_Actual);
    print "^)]^^";
    _Unit_Throw(Continue);
  }
];

! Check if the expected value matches the actual value.
[ Unit_AssertEquals
  Expected  ! (Required) The expected value.
  Actual    ! (Required) The actual value.
  ErrorText ! (Required) Error text to print on failure.
  Continue; ! (Optional) Continue execution after a failure.

  if (_Unit_Assert((Expected == Actual), ErrorText, "AssertEquals")) {
    print "[Expected (", Expected, ") but received (", Actual, ")]^^";
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

! Check if the expected value matches the actual value.
[ Unit_AssertStrCmp
  Expected  ! (Required) The expected value.
  Actual    ! (Required) The actual value.
  ErrorText ! (Required) Error text to print on failure.
  Continue; ! (Optional) Continue execution after a failure.

  ! Convert or copy the strings.
  if (Expected ofclass String) {
    Expected.print_to_array(_Unit_Expected);
  } else {
    _Unit_String_Copy(Expected, _Unit_Expected);
  }
  if (Actual ofclass string) {
    Actual.print_to_array(_Unit_Actual);
  } else {
    _Unit_String_Copy(Actual, _Unit_Actual);
  }

  if (_Unit_Assert(_Unit_String_Compare(), ErrorText, "AssertStrCmp")) {
    print "[Expected (^";
    _Unit_String_Print(_Unit_Expected);
    print "^) but received (^";
    _Unit_String_Print(_Unit_Actual);
    print "^)]^^";
    _Unit_Throw(Continue);
  }
];

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

! Start capturing output.
[ _Unit_Capture_Start;
  @output_stream 3 _Unit_Actual;
];

! Stop capturing output.
[ _Unit_Capture_Stop;
  @output_stream -3;
];

#Ifdef LIBRARY_VERSION;
  ! Initialize globals so tests run in a normal-ish environment.
  [_Unit_Initialize_Globals;
    ! Prepare the player.
    if (player ~= nothing) Unit_Player.destroy(player);
    player = Unit_Player.create();
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
#Endif;

! Prints something in the most appropriate way.
[ _Unit_Print
  Value;

    switch (metaclass(Value)) {
      Object:
        print (name) Value;
      String:
        print (string) Value;
      Routine:
        return Value();
      default:
        print Value;
    }
];

! Print a bunch of variables.
! Basically a replacement for the print statement.
[ _Unit_Print_Variables
  a b c d e f g;
  if (a) _Unit_Print(a);
  if (b) _Unit_Print(b);
  if (c) _Unit_Print(c);
  if (d) _Unit_Print(d);
  if (e) _Unit_Print(e);
  if (f) _Unit_Print(f);
  if (g) _Unit_Print(g);
];

! Chomp carriage returns from the end of a string.
! (I'm a Perl developer...)
[ _Unit_String_Chomp
  Value;

  while (Value->(Value-->0 + 1) == 13) {
    Value-->0 = Value-->0 - 1;
  }
];

! Compare the _Unit_Expected and _Unit_Actual strings.
! Check the length first, then compare the strings.
[_Unit_String_Compare
  Position
  Length;

  ! Check the length first.
  ! This caused issues with empty strings with the istring library.
  if (_Unit_Expected-->0 ~= _Unit_Actual-->0) {
    rfalse;
  }

  ! Then check the contents.
  Length = WORDSIZE + _Unit_Expected-->0;
  for (Position = WORDSIZE: Position < Length: Position++) {
    if (_Unit_Expected->(Position) ~= _Unit_Actual->(Position)) {
      rfalse;
    }
  }
  rtrue;
];

! Copy a string array.
[ _Unit_String_Copy
  Source
  Destination
  Position
  Length;

  Destination-->0 = Source-->0;
  Length = WORDSIZE + Source-->0;
  for (Position = WORDSIZE: Position < Length: Position++) {
    Destination->(Position) = Source->(Position);
  }
];

! Print a string.
[ _Unit_String_Print
  Value
  Position
  Length;

  Length = WORDSIZE + Value-->0;
  for (Position = WORDSIZE: Position < Length: Position++) {
    print (char) Value->(Position);
  }
];

! Performs a throw if Continue is false.
[_Unit_Throw
  Continue; ! (Required) Continue execution after a failure.

  if (Continue ~= true) {
    @throw false _Unit_Exception;
  }
];

! ------------------------------------------------------------------------------
! Self Test
! ------------------------------------------------------------------------------

! Run a self test of the Unit test internals.
[_Unit_Self_Test;
  ! The general tests should succeed.
  if (~~ Unit_RunTest(_Unit_Self_Test_General))
    rfalse;

  ! This test should fail.
  if (Unit_RunTest(_Unit_Self_Test_Throw))
    rfalse;

  rtrue;
];

! Test most of the library.
[ _Unit_Self_Test_General;
  ! Two strings that should match.
  Unit_AssertStrCmp(
    _Unit_Self_Test_String_A,
    _Unit_Self_Test_String_A,
    "Comparing the same string failed."
  );

  ! Two strings that should match, using an array as the expected.
  _Unit_Self_Test_String_A.print_to_array(_Unit_Scratch);
  Unit_AssertStrCmp(
    _Unit_Self_Test_String_A,
    _Unit_Scratch,
    "Comparing the same string failed, using an array as the expected."
  );

  ! Two strings that should match, using an array as the actual.
  _Unit_Self_Test_String_A.print_to_array(_Unit_Scratch);
  Unit_AssertStrCmp(
    _Unit_Scratch,
    _Unit_Self_Test_String_A,
    "Comparing the same string failed, using an array as the actual."
  );

  ! Copy a string.
  _Unit_Self_Test_String_A.print_to_array(_Unit_Expected);
  _Unit_String_Copy(_Unit_Expected, _Unit_Actual);
  Unit_AssertTrue(
    _Unit_String_Compare(),
    "Copying strings failed."
  );
  ! Two strings that should not match.
  _Unit_Self_Test_String_A.print_to_array(_Unit_Actual);
  _Unit_Self_Test_String_B.print_to_array(_Unit_Expected);
  Unit_AssertFalse(
    _Unit_String_Compare(),
    "Comparing different strings failed."
  );

  ! Compare a string to an empty string.
  ! This was a problem with an earlier version.
  _Unit_Self_Test_String_A.print_to_array(_Unit_Actual);
  _Unit_Self_Test_String_Empty.print_to_array(_Unit_Expected);
  Unit_AssertFalse(
    _Unit_String_Compare(),
    "Comparing a string to an empty string failed."
  );

  ! Chomp carriage returns from the end of a string.
  _Unit_Self_Test_String_B.print_to_array(_Unit_Actual);
  _Unit_Self_Test_String_C.print_to_array(_Unit_Expected);
  _Unit_String_Chomp(_Unit_Expected);
  Unit_AssertTrue(
    _Unit_String_Compare(),
    "Chomping carriage returns from the end of a string failed."
  );

  ! Chomp a string with no carriage returns at the end.
  _Unit_Self_Test_String_A.print_to_array(_Unit_Actual);
  _Unit_Self_Test_String_A.print_to_array(_Unit_Expected);
  _Unit_String_Chomp(_Unit_Expected);
  Unit_AssertTrue(
    _Unit_String_Compare(),
    "Chomping a string with no carriage returns failed."
  );

  ! Check capturing output.
  Unit_AssertCapture(
    _Unit_Self_Test_Helper_Capture,
    _Unit_Self_Test_String_A,
    "Capturing printed text failed."
  );

  ! Check capturing output, using an array as the expected.
  _Unit_Self_Test_String_A.print_to_array(_Unit_Scratch);
  Unit_AssertCapture(
    _Unit_Self_Test_Helper_Capture,
    _Unit_Scratch,
    "Capturing printed text failed, using an array as the expected."
  );

  ! Check that _Unit_String_Print accurately reproduces strings.
  Unit_AssertCapture(
    _Unit_Self_Test_Helper_Print,
    _Unit_Self_Test_String_A,
    "Printing a string failed."
  );

  ! Test Unit_AssertEquals using numbers.
  Unit_AssertEquals(
    42,
    42,
    "Unit_AssertEquals failed using numbers."
  );

  ! Test Unit_AssertEquals using string constants.
  Unit_AssertEquals(
    _Unit_Self_Test_String_A,
    _Unit_Self_Test_String_A,
    "Unit_AssertEquals failed using string constants."
  );

  ! Test Unit_AssertOfClass.
  Unit_AssertOfClass(
    "This is a string",
    String,
    "Unit_AssertOfClass failed."
  );

  ! Test Unit_AssertNotNothing.
  Unit_AssertNotNothing(
    "This is something.",
    "Unit_AssertNotNothing failed."
  );

  ! Make sure Unit_Fail increments the failed test counter.
  Unit_AssertTrue(
    _Unit_Self_Test_Helper_Fail(),
    "Unit_Fail did not increase the error count."
  );
  Unit_FailCount--;
];

! Make sure _Unit_Throw throws an exception.
[ _Unit_Self_Test_Throw;
  _Unit_Throw();
  print "* ERROR: _Unit_Throw failed to generate an exception.^";
];


! Prints String A for a capture test.
[ _Unit_Self_Test_Helper_Capture;
  print (string) _Unit_Self_Test_String_A;
];

! Test Unit_Fail.
[ _Unit_Self_Test_Helper_Fail
  Count;
  Count = Unit_FailCount;
  ! Don't display this failure since it is expected.
  _Unit_Capture_Start();
  ! The true is to continue and not throw an exception.
  Unit_Fail("This is a failure test.", true);
  _Unit_Capture_Stop();
  return ((Count + 1) == Unit_FailCount);
];

! Prints String A converted to an array for a capture test.
[ _Unit_Self_Test_Helper_Print;
  _Unit_Self_Test_String_A.print_to_array(_Unit_Scratch);
  _Unit_String_Print(_Unit_Scratch);
];
