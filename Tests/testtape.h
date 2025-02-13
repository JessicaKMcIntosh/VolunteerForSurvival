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
Constant Tape_MSG_Contents_1
 "(first putting cassette tape first into the tape player)^
  This is the contents of the cassette tape first.";
Constant Tape_MSG_Contents_2 "A cassette tape containing NO message.";
Constant Tape_MSG_Eject_Empty "There is no cassette tape in the Tape Player.";
Constant Tape_MSG_Eject_Tape "Removed cassette tape first from the tape player.";
Constant Tape_MSG_Empty "The Tape Player is empty.";
Constant Tape_MSG_Inventory_Empty "a Tape Player";
Constant Tape_MSG_Inventory_Tape "a Tape Player containing the cassette tape first";
Constant Tape_MSG_Play_Wrong "Can not play 'Not a Tape'. It is not a cassette tape.";
Constant Tape_MSG_Receive
 "(first ejecting cassette tape other)^
You put cassette tape other into the tape player.";

! ------------------------------------------------------------------------------
! Test Objects
! ------------------------------------------------------------------------------

! Tape player object to test.
Tape_Player_Class Tape_Player "Tape Player"
;

! A tape to test the tape player with.
Tape_Cassette_Class Tape_1 "cassette tape first"
  with
    name 'cassette' 'tape',
    description "A cassette tape containing a message.",
    inside_description "This is the contents of the cassette tape first."
;

! A different tape to test te tape player with.
Tape_Cassette_Class Tape_2 "cassette tape other"
  with
    name 'cassette' 'tape',
    description "A cassette tape containing NO message.",
  has scored
;

! An object that is not a tape.
Object Tape_Not_Tape "Not a Tape"
;

! Object to run the tests.
Unit_Test_Class Tape_Tests "Tape library"
  with
    RunTest [;
      ! Prepare test objects.
      move Tape_Player to player;

      ! Run the tests.
      Unit_RunTest(_TestTape_PlayerCreated);
      Unit_RunTest(_TestTape_CassetteCreated);
      Unit_RunTest(_TestTape_CassetteEject);
      Unit_RunTest(_TestTape_CassetteInventory);
      Unit_RunTest(_TestTape_CassettePlayed);
    ],
;

! ------------------------------------------------------------------------------
! Test Routines
! ------------------------------------------------------------------------------

[ _TestTape_PlayerCreated;
  print "Verify the tape player was created successfully.^";

  Unit_AssertNotNothing(
    Tape_Player,
    "The tape player was not created.");

    Unit_AssertOfClass(
      Tape_Player,
      Tape_Player_Class,
      "Tape player not created with the tape player class."
    );

  print "Success...^^";
];

[ _TestTape_CassetteCreated;
  print "Verify the tape cassette was created successfully.^";

  Unit_AssertNotNothing(
    Tape_1,
    "The cassette tape was not created.");

    Unit_AssertOfClass(
      Tape_1,
      Tape_Cassette_Class,
      "Cassette tape not created with the tape cassette class."
    );

  print "Success...^^";
];

[ _TestTape_CassetteEject;
  print "Verify ejecting a cassette tape works.^";

  ! Eject an empty tape player.
  Unit_AssertCapture(
    EjectSub,
    Tape_MSG_Eject_Empty,
    "Output message from ejecting an empty tape player is incorrect."
  );

  ! Eject a tape from the tape player.
  move Tape_1 to Tape_Player;
  Unit_AssertCapture(
    EjectSub,
    Tape_MSG_Eject_Tape,
    "Output message from ejecting a tape from the tape player is incorrect."
  );

  Unit_AssertTrue(
    (Tape_1 in player),
    "Cassette tape should be in the player inventory after being ejected."
  );

  ! Empty the tape player.
  move Tape_1 to Tape_Player;
  action = ##Empty;
  Unit_AssertCapture(
    _TestTape_HelperPlayerBefore,
    Tape_MSG_Eject_Tape,
    "Output message from emptying the tape player is incorrect."
  );

  Unit_AssertTrue(
    (Tape_1 in player),
    "Cassette tape should be in the player inventory after being emptied."
  );

  print "Success...^^";
];

[ _TestTape_CassetteInventory;
  print "Verify tape player inventory works.^";

  ! Inventory of an empty tape player.
  Unit_AssertCapture(
    _TestTape_HelperPlayerInvent,
    Tape_MSG_Inventory_Empty,
    "Output message from inventory of empty tape player is incorrect."
  );

  ! Inventory of a tape player containing a cassette tape.
  move Tape_1 to Tape_Player;
  Unit_AssertCapture(
    _TestTape_HelperPlayerInvent,
    Tape_MSG_Inventory_Tape,
    "Output message from inventory of tape player is incorrect."
  );
  move Tape_1 to player;

  print "Success...^^";
];

[ _TestTape_CassettePlayed;
  print "Verify playing a tape works.^";

  ! Play with the tape player empty.
  Unit_AssertCapture(
    PlaySub,
    Tape_MSG_Empty,
    "Output message from playing no tape is incorrect."
  );

  ! Play an object that is not a cassette tape.
  noun = Tape_Not_Tape;
  Unit_AssertCapture(
    PlaySub,
    Tape_MSG_Play_Wrong,
    "Output message from playing not a tape is incorrect."
  );

  Unit_AssertTrue(
    (Tape_1 hasnt general),
    "Cassette tape should not have 'general' before being played."
  );

  ! Play the first tape.
  noun = Tape_1;
  Unit_AssertCapture(
    PlaySub,
    Tape_MSG_Contents_1,
    "Output message from playing the first tape is incorrect."
  );

  Unit_AssertTrue(
    (Tape_1 has general),
    "Cassette tape should have 'general' after being played."
  );

  Unit_AssertTrue(
    (Tape_1 in Tape_Player),
    "Cassette tape should be in the tape player after being played."
  );

  ! Put the other tape in the player.
  noun = Tape_2;
  action = ##Receive;
  Unit_AssertCapture(
    _TestTape_HelperPlayerBefore,
    Tape_MSG_Receive,
    "Output message from putting the other tape in the tape player is incorrect."
  );

  Unit_AssertTrue(
    (Tape_2 in Tape_Player),
    "Cassette should be moved to the tape player when Received."
  );

  ! Play the other tape.
  Unit_AssertCapture(
    PlaySub,
    Tape_MSG_Contents_2,
    "Output message from playing the other tape is incorrect."
  );

  Unit_AssertTrue(
    (Tape_1 in player),
    "Cassette should be moved to player inventory when playing a different tape."
  );

  Unit_AssertTrue(
    (Tape_2 has moved),
    "Cassette should be scored after being played."
  );

  Unit_AssertEquals(
    4,
    score,
    "Score should increment for a scored cassette."
  );

  ! Put the tape back in the player inventory.
  move Tape_2 to player;

  print "Success...^^";
];

! ------------------------------------------------------------------------------
! Test Helpers
! ------------------------------------------------------------------------------

[ _TestTape_HelperPlayerBefore;
  Tape_Player.before();
];

[ _TestTape_HelperPlayerInvent;
  Tape_Player.invent();
];