! ------------------------------------------------------------------------------
! Tests for the camping lantern library.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
! ------------------------------------------------------------------------------

Message "Loading the Lamp Test library.";

! ------------------------------------------------------------------------------
! Libraries
! ------------------------------------------------------------------------------

Include "lamp";

! ------------------------------------------------------------------------------
! Constants
! ------------------------------------------------------------------------------

! Messages for testing.
Constant Lamp_MSG_Switch_On "The Lamp is now on.";
Constant Lamp_MSG_Switch_Off "The Lamp is now off.";
Constant Lamp_MSG_Description_On "^You see a Lamp here. (providing light)";
Constant Lamp_MSG_Description_Off "^You see a Lamp here.";

! ------------------------------------------------------------------------------
! Test Objects
! ------------------------------------------------------------------------------


Lamp_Class Lamp "Lamp"
;

! ------------------------------------------------------------------------------
! Test Code
! ------------------------------------------------------------------------------

[ TestLampRun;
  ! Prepare test objects.
  move Lamp to player;

  ! Run the tests.
  print "Testing the Lamp library.^^";
  StartTest(_TestLamp_LampCreated);
  StartTest(_TestLamp_LampSwitch);
];

! Test Routines.

[ _TestLamp_LampCreated;
  print "Verify the lamp was created successfully.^";

  assertNotNothing(
    Lamp,
    "The lamp was not created.");

  assertOfClass(
    Lamp,
    Lamp_Class,
    "Lamp not created with the lamp class."
  );

  print "Success...^^";
];

[ _TestLamp_LampSwitch;
  print "Verify the lamp can be switched successfully.^";

  AssertTrue(
    (Lamp hasnt light),
    "The Lamp should not have light before being switched on.^"
  );

  ! Switch the lamp on.
  noun = Lamp;
  action = ##SwitchOn;
  WriteString(CheckString, Lamp_MSG_Switch_On);
  CaptureOutput(_TestLamp_HelperBefore);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message for switching lamp on is incorrect."
  );

  AssertTrue(
    (Lamp has light),
    "The Lamp should have light after being switched on.^"
  );

  ! Check the description while switched on.
  WriteString(CheckString, Lamp_MSG_Description_On);
  CaptureOutput(_TestLamp_HelperDescribe);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message for lamp that is on is incorrect."
  );

  ! Switch the lamp off.
  noun = Lamp;
  action = ##SwitchOff;
  WriteString(CheckString, Lamp_MSG_Switch_Off);
  CaptureOutput(_TestLamp_HelperBefore);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message for switching lamp off is incorrect."
  );

  AssertTrue(
    (Lamp hasnt light),
    "The Lamp should not have light after being switched off.^"
  );

  ! Check the description while switched off.
  WriteString(CheckString, Lamp_MSG_Description_Off);
  CaptureOutput(_TestLamp_HelperDescribe);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message for lamp that is off is incorrect."
  );

  ! The Turn action should toggle the state of the lamp.
  noun = Lamp;
  action = ##Turn;
  WriteString(CheckString, Lamp_MSG_Switch_On);
  CaptureOutput(_TestLamp_HelperBefore);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message for turning lamp on is incorrect."
  );

  WriteString(CheckString, Lamp_MSG_Switch_Off);
  CaptureOutput(_TestLamp_HelperBefore);

  assertStrCmp(
    CheckString,
    PrintedString,
    "Output message for turning lamp off is incorrect."
  );

  print "Success...^^";
];

! Test Helpers.

[ _TestLamp_HelperBefore;
  Lamp.before();
];

[ _TestLamp_HelperDescribe;
  Lamp.describe();
];
