! ------------------------------------------------------------------------------
! Tests for the cassette tape library.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
! ------------------------------------------------------------------------------
! USAGE
! ------------------------------------------------------------------------------
! Include after unit.h.
!
! Requires the following libraries:
! * unit.h by Jessica McIntosh
! * pills.h by Jessica McIntosh
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
 "You stumble as your vision blurs.^
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

! Pill bottle object to test.
Pills_Class Pill_Bottle "pill bottle"
;

! Object to run the tests.
Unit_Test_Class Pill_Tests "Pills library"
  with
    describe [;
      ! Run the tests.
      Unit_RunTest(_TestPill_PillsCreated);
      Unit_RunTest(_TestPill_Daemon);
      Unit_RunTest(_TestPill_EatPill);
      Unit_RunTest(_TestPill_PrintNumber);
    ],
;

! ------------------------------------------------------------------------------
! Test Routines
! ------------------------------------------------------------------------------

[ _TestPill_PillsCreated;
  self.msg("Verify the pill bottle was created successfully.^");

  Unit_AssertNotNothing(
    Pill_Bottle,
    "The pill bottle was not created.");

  Unit_AssertOfClass(
    Pill_Bottle,
    Pills_Class,
    "Pill bottle not created with the pills class."
  );

  self.msg("Success...^");
];

[ _TestPill_Daemon;
  self.msg("Verify the pills daemon works correctly.^");

  ! Message for extra time.
  Pill_Bottle.time_left = (PILLS_DURATION * 2);
  Unit_AssertCapture(
    _TestPill_HelperDaemon,
    Pills_MSG_Daemon_Extra,
    "Output message for extra time is incorrect."
  );

  ! Warning for not enough time..
  Pill_Bottle.time_left = PILLS_WARNING;
  Unit_AssertCapture(
    _TestPill_HelperDaemon,
    Pills_MSG_Daemon_Warning,
    "Output message for time warning is incorrect."
  );

  ! Critical for almost out of time.
  Pill_Bottle.time_left = PILLS_CRITICAL;
  Unit_AssertCapture(
    _TestPill_HelperDaemon,
    Pills_MSG_Daemon_Critical,
    "Output message for extra time is incorrect."
  );

  ! Dead from running out of time.
  Pill_Bottle.time_left = 1;
  Unit_AssertCapture(
    _TestPill_HelperDaemon,
    Pills_MSG_Daemon_Dead,
    "Output message for dying is incorrect."
  );

  Unit_AssertEquals(
    1,
    deadflag,
    "Deadflag should be set when the player dies."
  );

  self.msg("Success...^");
];

[ _TestPill_EatPill;
  self.msg("Verify eating pills works correctly.^");

  ! Eat a pill from a full bottle.
  noun = Pill_Bottle;
  action = ##Eat;
  Pill_Bottle.number = PILLS_DEFAULT_COUNT;
  Pill_Bottle.time_left = 0;
  Unit_AssertCapture(
    _TestPill_HelperBefore,
    Pills_MSG_Eat_Full,
    "Output message eating a pill is incorrect."
  );

  Unit_AssertEquals(
    (PILLS_DEFAULT_COUNT - 1),
    Pill_Bottle.number,
    "Pills should decrement after one is eaten."
  );

  Unit_AssertEquals(
    PILLS_DURATION,
    Pill_Bottle.time_left,
    "Pills should increment the amount of time left."
  );

  ! Eat a pill from a bottle with one pill.
  noun = Pill_Bottle;
  action = ##Eat;
  Pill_Bottle.number = 1;
  Pill_Bottle.time_left = 0;
  Unit_AssertCapture(
    _TestPill_HelperBefore,
    Pills_MSG_Eat_One,
    "Output message eating a pill is incorrect, one pill."
  );

  Unit_AssertEquals(
    0,
    Pill_Bottle.number,
    "Pills should decrement after one is eaten, one pill."
  );

  Unit_AssertEquals(
    PILLS_DURATION,
    Pill_Bottle.time_left,
    "Pills should increment the amount of time left, one pill."
  );

  ! Eat a pill from an empty bottle.
  noun = Pill_Bottle;
  action = ##Eat;
  Pill_Bottle.number = 0;
  Pill_Bottle.time_left = 0;
  Unit_AssertCapture(
    _TestPill_HelperBefore,
    Pills_MSG_Eat_Empty,
    "Output message eating a pill is incorrect."
  );

  Unit_AssertEquals(
    0,
    Pill_Bottle.number,
    "Pills should change after eating from an empty bottle."
  );

  Unit_AssertEquals(
    0,
    Pill_Bottle.time_left,
    "Time left should not change after eating from an empty bottle."
  );

  Pill_Bottle.number = PILLS_DEFAULT_COUNT;
  Pill_Bottle.time_left = PILLS_DURATION;

  self.msg("Success...^");
];

[ _TestPill_PrintNumber;
  self.msg("Verify the number of pills is printed correctly.^");

  ! The number of pills in an empty bottle.
  Pill_Bottle.number = 0;
  Unit_AssertCapture(
    _TestPill_HelperPrintNumber,
    Pills_MSG_Number_Empty,
    "Output message from empty pill bottle is incorrect."
  );

  ! The number of pills in a bottle with one pill.
  Pill_Bottle.number = 1;
  Unit_AssertCapture(
    _TestPill_HelperPrintNumber,
    Pills_MSG_Number_One,
    "Output message from empty pill bottle is incorrect."
  );

  ! The number of pills in a bottle with the default number of pills.
  Pill_Bottle.number = PILLS_DEFAULT_COUNT;
  Unit_AssertCapture(
    _TestPill_HelperPrintNumber,
    Pills_MSG_Number_More,
    "Output message from empty pill bottle is incorrect."
  );

  self.msg("Success...^");
];

! ------------------------------------------------------------------------------
! Test Helpers
! ------------------------------------------------------------------------------

[ _TestPill_HelperDaemon;
  Pill_Bottle.daemon();
];

[ _TestPill_HelperBefore;
  Pill_Bottle.before();
];

[ _TestPill_HelperPrintNumber;
  PillsPrintNumber(Pill_Bottle);
];
