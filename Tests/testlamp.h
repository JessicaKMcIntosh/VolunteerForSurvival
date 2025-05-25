! ------------------------------------------------------------------------------
! Tests for the camping lantern library.
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
! * lamp.h by Jessica McIntosh
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

! A lamp object to test.
Lamp_Class Lamp "Lamp"
;

! Object to run the tests.
Unit_Test_Class Lamp_Tests "Lamp library"
  with
    RunTest [;
      ! Prepare test objects.
      move Lamp to player;

      ! Run the tests.
      Unit_RunTest(_TestLamp_LampCreated);
      Unit_RunTest(_TestLamp_LampSwitch);
    ],
;

! ------------------------------------------------------------------------------
! Test Routines
! ------------------------------------------------------------------------------

[ _TestLamp_LampCreated;
  print "Verify the lamp was created successfully.^";

  Unit_AssertNotNothing(
    Lamp,
    "The lamp was not created.");

  Unit_AssertOfClass(
    Lamp,
    Lamp_Class,
    "Lamp not created with the lamp class."
  );

  print "Success...^^";
];

[ _TestLamp_LampSwitch;
  print "Verify the lamp can be switched successfully.^";

  Unit_AssertTrue(
    (Lamp hasnt light),
    "The Lamp should not have light before being switched on.^"
  );

  ! Switch the lamp on.
  noun = Lamp;
  action = ##SwitchOn;
  Unit_AssertCapture(
    _TestLamp_HelperBefore,
    Lamp_MSG_Switch_On,
    "Output message for switching lamp on is incorrect."
  );

  Unit_AssertTrue(
    (Lamp has light),
    "The Lamp should have light after being switched on.^"
  );

  ! Check the description while switched on.
  Unit_AssertCapture(
    _TestLamp_HelperDescribe,
    Lamp_MSG_Description_On,
    "Output message for lamp that is on is incorrect."
  );

  ! Switch the lamp off.
  noun = Lamp;
  action = ##SwitchOff;
  Unit_AssertCapture(
    _TestLamp_HelperBefore,
    Lamp_MSG_Switch_Off,
    "Output message for switching lamp off is incorrect."
  );

  Unit_AssertTrue(
    (Lamp hasnt light),
    "The Lamp should not have light after being switched off.^"
  );

  ! Check the description while switched off.
  Unit_AssertCapture(
    _TestLamp_HelperDescribe,
    Lamp_MSG_Description_Off,
    "Output message for lamp that is off is incorrect."
  );

  ! The Turn action should toggle the state of the lamp.
  noun = Lamp;
  action = ##Turn;
  Unit_AssertCapture(
    _TestLamp_HelperBefore,
    Lamp_MSG_Switch_On,
    "Output message for turning lamp on is incorrect."
  );

  Unit_AssertCapture(
    _TestLamp_HelperBefore,
    Lamp_MSG_Switch_Off,
    "Output message for turning lamp off is incorrect."
  );

  print "Success...^^";
];

! ------------------------------------------------------------------------------
! Test Helpers
! ------------------------------------------------------------------------------

[ _TestLamp_HelperBefore;
  Lamp.before();
];

[ _TestLamp_HelperDescribe;
  Lamp.describe();
];
