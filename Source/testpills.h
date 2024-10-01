! ------------------------------------------------------------------------------
! Tests for the cassette tape library.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
! ------------------------------------------------------------------------------

Message "Loading the Pills Test library.";

! ------------------------------------------------------------------------------
! Libraries
! ------------------------------------------------------------------------------

Include "pills";

! ------------------------------------------------------------------------------
! Constants
! ------------------------------------------------------------------------------

! Messages for testing.
Constant Pills_MSG_Number_Empty "Empty";
Constant Pills_MSG_Number_One "1 pill";
Constant Pills_MSG_Number_More "25 pills";


! ------------------------------------------------------------------------------
! Test Objects
! ------------------------------------------------------------------------------


Pills_Class Pill_Bottle "pill bottle"
;

Object Pills_Not_Pills "Not Pills"
;

Object Pills_Food "Food"
  has edible
;

! ------------------------------------------------------------------------------
! Test Code
! ------------------------------------------------------------------------------

[ TestPillRun;
  ! Prepare test objects.
  move Pill_Bottle to player;

  ! Run the tests.
  StartTest(_TestPill_PillsCreated);
  StartTest(_TestPill_PrintNumber);
  StartTest(_TestPill_EatPill);
];

! Test Routines.

[_TestPill_PillsCreated;
  print "Verify the pill bottle was created successfully.^";

  assertNotNothing(
    Pill_Bottle,
    "The pill bottle was not created.");

    assertOfClass(
      Pill_Bottle,
      Pills_Class,
      "Pill bottle not created with the pills class."
    );

  print "Success...^^";
];

[_TestPill_EatPill;
  print "Verify eating pills works corectly.^";

  noun = Fake_Object;
  ! Pills_EatSub();

  print "Success...^^";
];


[_TestPill_PrintNumber;
  print "Verify the number of pills is printed corectly.^";

  ! The numer of pills in an empty bottle.
  Pill_Bottle.number = 0;
  WriteString(CheckString, Pills_MSG_Number_Empty);
  CaptureOutput(_TestPill_HelperPrintNumber);

  assertTrue(
    (StrCmp(CheckString, PrintedString) == 0),
    "Output message from empty pill bottle is incorrect."
  );

  ! The numer of pills in a bottle with one pill.
  Pill_Bottle.number = 1;
  WriteString(CheckString, Pills_MSG_Number_One);
  CaptureOutput(_TestPill_HelperPrintNumber);

  assertTrue(
    (StrCmp(CheckString, PrintedString) == 0),
    "Output message from empty pill bottle is incorrect."
  );

  ! The numer of pills in a bottle with the default number of pills.
  Pill_Bottle.number = PILLS_DEFAULT_COUNT;
  WriteString(CheckString, Pills_MSG_Number_More);
  CaptureOutput(_TestPill_HelperPrintNumber);

  assertTrue(
    (StrCmp(CheckString, PrintedString) == 0),
    "Output message from empty pill bottle is incorrect."
  );

  print "Success...^^";
];

! Test Helpers.

[_TestPill_HelperPrintNumber;
  Pills_Print_Number(Pill_Bottle);
];
