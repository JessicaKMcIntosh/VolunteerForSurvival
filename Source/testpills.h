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
Constant Pills_MSG_Daemon_Critical "^You feel terrible.";
Constant Pills_MSG_Daemon_Dead
 "You stumble as your vision blurrs.^
  Pain consumes your mind as reality grows numb.^
  Laughing echos in your head as you fall to the ground.";
Constant Pills_MSG_Daemon_Extra "^You feel great!";
Constant Pills_MSG_Daemon_Warning "^You do not feel so well.";
Constant Pills_MSG_Eat_Empty "The pill bottle is empty.";
Constant Pills_MSG_Eat_Full "You take a pill. You have 24 pills left.";
Constant Pills_MSG_Eat_One "You take a pill. You have no more pills left.";
Constant Pills_MSG_Number_Empty "Empty";
Constant Pills_MSG_Number_One "1 pill";
Constant Pills_MSG_Number_More "25 pills";

! ------------------------------------------------------------------------------
! Test Objects
! ------------------------------------------------------------------------------


Pills_Class Pill_Bottle "pill bottle"
;

! ------------------------------------------------------------------------------
! Test Code
! ------------------------------------------------------------------------------

[ TestPillRun;
  ! Prepare test objects.
  move Pill_Bottle to player;

  ! Run the tests.
  print "Testing the Pills library.^^";
  StartTest(_TestPill_PillsCreated);
  StartTest(_TestPill_Daemon);
  StartTest(_TestPill_EatPill);
  StartTest(_TestPill_PrintNumber);
];

! Test Routines.

[ _TestPill_PillsCreated;
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

[ _TestPill_Daemon;
  print "Verify the pills daemon works corectly.^";

  ! Message for extra time.
  Pill_Bottle.time_left = (PILLS_DURATION * 2);
  WriteString(CheckString, Pills_MSG_Daemon_Extra);
  CaptureOutput(_TestPill_HelperDaemon);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message for extra time is incorrect."
  );

  ! Carning for not enough time..
  Pill_Bottle.time_left = PILLS_WARNING;
  WriteString(CheckString, Pills_MSG_Daemon_Warning);
  CaptureOutput(_TestPill_HelperDaemon);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message for time warning is incorrect."
  );

  ! Critical for almost out of time.
  Pill_Bottle.time_left = PILLS_CRITICAL;
  WriteString(CheckString, Pills_MSG_Daemon_Critical);
  CaptureOutput(_TestPill_HelperDaemon);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message for extra time is incorrect."
  );

  ! Dead from running out of time.
  Pill_Bottle.time_left = 1;
  WriteString(CheckString, Pills_MSG_Daemon_Dead);
  CaptureOutput(_TestPill_HelperDaemon);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message for dying is incorrect."
  );

  assertEquals(
    1,
    deadflag,
    "Deadflag should be set when the player dies."
  );

  print "Success...^^";
];

[ _TestPill_EatPill;
  print "Verify eating pills works corectly.^";

  ! Eat a pill from a full bottle.
  noun = Pill_Bottle;
  action = ##Eat;
  Pill_Bottle.number = PILLS_DEFAULT_COUNT;
  Pill_Bottle.time_left = 0;
  WriteString(CheckString, Pills_MSG_Eat_Full);
  CaptureOutput(_TestPill_HelperEatPill);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message eating a pill is incorrect."
  );

  assertEquals(
    (PILLS_DEFAULT_COUNT - 1),
    Pill_Bottle.number,
    "Pills should decrement after one is eaten."
  );

  assertEquals(
    PILLS_DURATION,
    Pill_Bottle.time_left,
    "Pills should increment the amount of time left."
  );

  ! Eat a pill from a bottle with one pill.
  noun = Pill_Bottle;
  action = ##Eat;
  Pill_Bottle.number = 1;
  Pill_Bottle.time_left = 0;
  WriteString(CheckString, Pills_MSG_Eat_One);
  CaptureOutput(_TestPill_HelperEatPill);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message eating a pill is incorrect, one pill."
  );

  assertEquals(
    0,
    Pill_Bottle.number,
    "Pills should decrement after one is eaten, one pill."
  );

  assertEquals(
    PILLS_DURATION,
    Pill_Bottle.time_left,
    "Pills should increment the amount of time left, one pill."
  );

  ! Eat a pill from an empty bottle.
  noun = Pill_Bottle;
  action = ##Eat;
  Pill_Bottle.number = 0;
  Pill_Bottle.time_left = 0;
  WriteString(CheckString, Pills_MSG_Eat_Empty);
  CaptureOutput(_TestPill_HelperEatPill);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message eating a pill is incorrect."
  );

  assertEquals(
    0,
    Pill_Bottle.number,
    "Pills should change after eating from an empty bottle."
  );

  assertEquals(
    0,
    Pill_Bottle.time_left,
    "Time left should not change after eating from an empty bottle."
  );

  Pill_Bottle.number = PILLS_DEFAULT_COUNT;
  Pill_Bottle.time_left = PILLS_DURATION;

  print "Success...^^";
];

[ _TestPill_PrintNumber;
  print "Verify the number of pills is printed corectly.^";

  ! The numer of pills in an empty bottle.
  Pill_Bottle.number = 0;
  WriteString(CheckString, Pills_MSG_Number_Empty);
  CaptureOutput(_TestPill_HelperPrintNumber);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message from empty pill bottle is incorrect."
  );

  ! The numer of pills in a bottle with one pill.
  Pill_Bottle.number = 1;
  WriteString(CheckString, Pills_MSG_Number_One);
  CaptureOutput(_TestPill_HelperPrintNumber);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message from empty pill bottle is incorrect."
  );

  ! The numer of pills in a bottle with the default number of pills.
  Pill_Bottle.number = PILLS_DEFAULT_COUNT;
  WriteString(CheckString, Pills_MSG_Number_More);
  CaptureOutput(_TestPill_HelperPrintNumber);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message from empty pill bottle is incorrect."
  );

  print "Success...^^";
];

! Test Helpers.

[ _TestPill_HelperDaemon;
  Pill_Bottle.daemon();
];

[ _TestPill_HelperEatPill;
  Pill_Bottle.before();
];

[ _TestPill_HelperPrintNumber;
  Pills_Print_Number(Pill_Bottle);
];
