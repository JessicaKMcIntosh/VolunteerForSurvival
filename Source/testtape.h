! ------------------------------------------------------------------------------
! Tests for the cassette tape library.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
! ------------------------------------------------------------------------------

Message "Loading the Tape Test library.";

! ------------------------------------------------------------------------------
! Libraries
! ------------------------------------------------------------------------------

Include "tape";

! ------------------------------------------------------------------------------
! Constants
! ------------------------------------------------------------------------------

! Messages for testing.
Constant Tape_MSG_Contents_1 "This is the contents of the cassette tape first.";
Constant Tape_MSG_Contents_2 "A cassette tape containing NO message.";
Constant Tape_MSG_Eject_Empty "There is no cassette tape in the Tape Player.";
Constant Tape_MSG_Eject_Tape "Removed cassette tape first from tape player.";
Constant Tape_MSG_Empty "The Tape Player is empty.";
Constant Tape_MSG_Inventory_Empty "a Tape Player";
Constant Tape_MSG_Inventory_Tape "a Tape Player containing the cassette tape first";
Constant Tape_MSG_Play_Wrong "Can not play 'Not a Tape'. It is not a cassette tape.";

! ------------------------------------------------------------------------------
! Test Objects
! ------------------------------------------------------------------------------

Tape_Player_Class Tape_Player "Tape Player"
;

Tape_Cassette_Class Tape_1 "cassette tape first"
  with
    name 'cassette' 'tape',
    description "A cassette tape containing a message.",
    inside_description Tape_MSG_Contents_1
;

Tape_Cassette_Class Tape_2 "cassette tape other"
  with
    name 'cassette' 'tape',
    description "A cassette tape containing NO message."
;

! An object that is not a tape.
Object Tape_Not_Tape "Not a Tape"
;

! ------------------------------------------------------------------------------
! Test Code
! ------------------------------------------------------------------------------

[ TestTapeRun;
  ! Prepare test objects.
  move Tape_Player to player;

  ! Run the tests.
  print "Testing the Tape library.^^";
  StartTest(_TestTape_PlayerCreated);
  StartTest(_TestTape_CassetteCreated);
  StartTest(_TestTape_CassetteEject);
  StartTest(_TestTape_CassetteInventory);
  StartTest(_TestTape_CassettePlayed);
];

! Test Routines.

[_TestTape_PlayerCreated;
  print "Verify the tape player was created successfully.^";

  assertNotNothing(
    Tape_Player,
    "The tape player was not created.");

    assertOfClass(
      Tape_Player,
      Tape_Player_Class,
      "Tape player not created with the tape player class."
    );

  print "Success...^^";
];

[_TestTape_CassetteCreated;
  print "Verify the tape cassette was created successfully.^";

  assertNotNothing(
    Tape_1,
    "The cassette tape was not created.");

    assertOfClass(
      Tape_1,
      Tape_Cassette_Class,
      "Cassette tape not created with the tape cassette class."
    );

  print "Success...^^";
];

[_TestTape_CassetteEject;
  print "Verify ejecting a cassette tape works.^";

  ! Eject an empty tape player.
  WriteString(CheckString, Tape_MSG_Eject_Empty);
  CaptureOutput(EjectSub);

  assertTrue(
    (StrCmp(CheckString, PrintedString) == 0),
    "Output message from ejecting an empty tape player is incorrect."
  );

  ! Eject a tape from the tape player.
  move Tape_1 to Tape_Player;
  WriteString(CheckString, Tape_MSG_Eject_Tape);
  CaptureOutput(EjectSub);

  assertTrue(
    (Tape_1 in player),
    "Cassette tape should be in the player inventory after being ejected."
  );

  assertTrue(
    (StrCmp(CheckString, PrintedString) == 0),
    "Output message from ejecting a tape from the tape player is incorrect."
  );

  ! Empty the tape player.
  move Tape_1 to Tape_Player;
  action = ##Empty;
  WriteString(CheckString, Tape_MSG_Eject_Tape);
  CaptureOutput(_TestTape_HelperPlayerBefore);

  assertTrue(
    (Tape_1 in player),
    "Cassette tape should be in the player inventory after being emptied."
  );

  assertTrue(
    (StrCmp(CheckString, PrintedString) == 0),
    "Output message from emptying the tape player is incorrect."
  );

  print "Success...^^";
];

[_TestTape_CassetteInventory;
  print "Verify tape player inventory works.^";

  ! Inventory of an empty tape player.
  WriteString(CheckString, Tape_MSG_Inventory_Empty);
  CaptureOutput(_TestTape_HelperPlayerInvent);

  assertTrue(
    (StrCmp(CheckString, PrintedString) == 0),
    "Output message from inventory of empty tape player is incorrect."
  );

  ! Inventory of a tape player containing a cassette tape.
  move Tape_1 to Tape_Player;
  WriteString(CheckString, Tape_MSG_Inventory_Tape);
  CaptureOutput(_TestTape_HelperPlayerInvent);
  move Tape_1 to player;

  assertTrue(
    (StrCmp(CheckString, PrintedString) == 0),
    "Output message from inventory of tape player is incorrect."
  );

  print "Success...^^";
];

[_TestTape_CassettePlayed;
  print "Verify playing a tape works.^";

  ! Play with the tape player empty.
  WriteString(CheckString, Tape_MSG_Empty);
  CaptureOutput(PlaySub);

  assertTrue(
    (StrCmp(CheckString, PrintedString) == 0),
    "Output message from playing no tape is incorrect."
  );

  ! Play an object that is not a cassette tape.
  noun = Tape_Not_Tape;
  WriteString(CheckString, Tape_MSG_Play_Wrong);
  CaptureOutput(PlaySub);

  assertTrue(
    (StrCmp(CheckString, PrintedString) == 0),
    "Output message from playing not a tape is incorrect."
  );

  assertTrue(
    (Tape_1 hasnt general),
    "Cassette tape should not have 'general' before being played."
  );

  ! Play the first tape.
  WriteString(CheckString, Tape_MSG_Contents_1);
  noun = Tape_1;
  CaptureOutput(PlaySub);

  assertTrue(
    (Tape_1 has general),
    "Cassette tape should have 'general' after being played."
  );

  assertTrue(
    (Tape_1 in Tape_Player),
    "Cassette tape should be in the tape player after being played."
  );

  assertTrue(
    (StrCmp(CheckString, PrintedString) == 0),
    "Output message from playing the first tape is incorrect."
  );

  ! Play the other tape.
  WriteString(CheckString, Tape_MSG_Contents_2);
  noun = Tape_2;
  CaptureOutput(PlaySub);

  assertTrue(
    (Tape_1 in player),
    "Cassette should be moved to player inventory when playing a different tape."
  );

  assertTrue(
    (StrCmp(CheckString, PrintedString) == 0),
    "Output message from playing the other tape is incorrect."
  );

  ! Put the tape back in the player inventory.
  move Tape_2 to player;

  print "Success...^^";
];

! Test Helpers.

[_TestTape_HelperPlayerBefore;
  Tape_Player.before();
];

[_TestTape_HelperPlayerInvent;
  Tape_Player.invent();
];