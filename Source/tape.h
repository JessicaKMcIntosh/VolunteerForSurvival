! ------------------------------------------------------------------------------
! Casette Tape - A library for creating a cassette player and playable tapes.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
! ------------------------------------------------------------------------------
! USAGE
! ------------------------------------------------------------------------------
! Include after Grammar.
!
! Create a tape player and tape objects.
! The tape player object must be named 'Tape_Player'.
!
! The tape contents are stored in the property inside_description.
! Alternately uses description if inside_description is not provided.
!
! Customize messages by changing the constants TAPE_PLAYER_NAME and
! TAPE_CASETTE_NAME.
!
! After a tape is played it is given the attribute 'general'.
! ------------------------------------------------------------------------------
! Classes:
! ------------------------------------------------------------------------------
! Tape_Player_Class - The tape player class.
!   Will play objects of the class 'Cassette_Tape_Class'.
!   It is a container, but is not openable by default.
!   If the tape player contains a tape then the tape name is printed when
!   inventory is listed.
!
! Cassette_Tape_Class - The Cassette tape class.
! ------------------------------------------------------------------------------
! Verbs:
! ------------------------------------------------------------------------------
! Play [noun]
!   With no noun plays the tape currently in the player.
!   With a noun will insert the tape into the player.
!
! Eject [noun]
!   Ignores the noun.
!   If there is a tape in the tape player the tape is given to the 'player'.
!
! ------------------------------------------------------------------------------
! Example:
! ------------------------------------------------------------------------------
! Include "Tape";
!
! Tape_Player_Class Tape_Player "Tape Player"
! ;
!
! Cassette_Tape_Class Tape_1 "Cassette Tape"
!   with
!     name 'cassette' 'tape',
!     description "A cassette tape containing a message.",
!     inside_description
!      "Static plays.^
!       A voice asks for help from Obiwan.^
!       Blaster fire is heard before the static returns.";
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the Tape library.";

! ------------------------------------------------------------------------------
! Constants
! ------------------------------------------------------------------------------

! Name of the tape player used in messages.
Constant TAPE_PLAYER_NAME "tape player";

! Name of a cassette tape used in messages.
Constant TAPE_CASETTE_NAME "cassette tape";

! ------------------------------------------------------------------------------
! Classes
! ------------------------------------------------------------------------------

! The Cassette tape player.
Class Tape_Player_Class
  with
    name 'tape' 'player',
    description
     "A cassette tape player.^
      To play a tape use the command: PLAY TAPE NAME",
    capacity 1,
    invent [;
      print (a) self;
      ! Print the tape name if the tape player contains a tape.
      if (children(self) ~= 0) {
        print " containing ", (the) child(self);
      }
      rtrue;
    ],
    before [
      tape;
      ! Handle putting a tape in the player.
      Receive:
        if (children(self) ~= 0) {
          move child(self) to player;
          print "(first ejecting ", (name) noun, ")^";
        }
        move noun to self;
        print "You put ", (name) noun, " into the ",
        (string) TAPE_PLAYER_NAME, ".^";
        rtrue;
      ! Handle removing a tape from the tape player.
      Empty, Remove:
        if (children(self) ~= 0) {
          tape = child(self);
          move tape to player;
          "Removed ", (name) tape, " from the ",
          (string) TAPE_PLAYER_NAME, ".";
        }
      ! When turned or switched on play the tape.
      SwitchOn, Turn:
        give self ~on;
        PlayTapeSub();
        rtrue;
    ]
  has container switchable
;

! Individual cassette tapes.
! This is class is what determins an object is a tape that can be played.
Class Tape_Cassette_Class
;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

! Play a tape.
! If playing an object insert the object into the tape player first.
! Finally play the tape in the tape player.
[ PlaySub;
  if (Tape_Player notin player)
    "You do not have a ", (string) TAPE_PLAYER_NAME, ".";
  if (noun ~= nothing && noun ~= Tape_Player) {
    ! Make sure the noun is a cassette tape.
    if (~~(noun ofclass Tape_Cassette_Class)) {
      "Can not play '", (name) noun, "'. ",
      "It is not a ", (string) TAPE_CASETTE_NAME, ".";
    }
    ! Empty the tape player if it already contains a tape.
    if (children(Tape_Player) ~= 0) {
      move child(Tape_Player) to player;
    }
    ! Move the noun into the tape player.
    print "(first putting ", (name) noun, " into the ",
    (string) TAPE_PLAYER_NAME, ")^";
    move noun to Tape_Player;
  }
  PlayTapeSub();
];

! Play tape in the tape player.
! Called to display the cassette tapes message.
! Will also execute before and after actions on the tape played.
[PlayTapeSub
  tape;
    if (children(Tape_Player) == 0) {
      "The ", (name) Tape_Player, " is empty.";
    } else {
      tape = child(Tape_Player);
      action = ##Play;
      if (tape provides before) tape.before();
      if (tape provides inside_description) {
        tape.inside_description();
      } else {
        tape.description();
      }
      if (tape hasnt general) give tape general;
      if (tape provides after) tape.after();
    }
];

! Eject the current tape from the tape player.
[EjectSub
tape;
  if (Tape_Player notin player)
    "You are not carrying a ", (string) TAPE_PLAYER_NAME, ".";
  if (children(Tape_Player) ~= 0) {
    tape = child(Tape_Player);
    print
      "Removed ", (name) tape, " from the ",
      (string) TAPE_PLAYER_NAME, ".^";
    move tape to player;
  } else {
      "There is no ", (string) TAPE_CASETTE_NAME,
      " in the ", (name) Tape_Player, ".";
  }
];

! ------------------------------------------------------------------------------
! Grammar
! ------------------------------------------------------------------------------

! Play a tape.
Verb 'play'
  *       -> Play
  * noun  -> Play;

! Eject a tape.
Verb 'eject'
  *       -> Eject
  * noun  -> Eject;
