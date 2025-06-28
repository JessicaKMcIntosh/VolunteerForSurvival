! ------------------------------------------------------------------------------
! XYZZY - A silly easter egg.
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
! Saying "XYZZY" gives the player a token.
! Rubbing the token teleports the player back to the starting location.
! The token saves the location and can send them back.
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the XYZZY library.";

! ------------------------------------------------------------------------------
! Globals
! ------------------------------------------------------------------------------

Global XYZZY_Previous_Location = nothing;

! ------------------------------------------------------------------------------
! Objects
! ------------------------------------------------------------------------------

Object XYZZY_Token "XYZZY Token"
  with
    name 'xyzzy' 'token' 'xyzzy_token',
    description "A token given to those that say the magic word.",
    before [;
      Blow:
        "Even less happens.";
      Burn:
        "The token glows briefly.";
      Consult:
        XYZZY_Consult();
        rtrue;
      Drop:
        "The token bounces back into your pocket.";
      Eat:
        "You don't know where it has been!";
      Listen:
        "The token whispers secrets from beyond the land of Zork.";
      Read:
       "A special token for those that know the magic word.^
        This token may do something useful, it is magical after all.";
      Remove:
       "You remove the token from your pocket and ponder the meaning of^
        Life, the Universe and Everything.";
      Rub:
        if (player notin Start_Room) {
          XYZZY_Previous_Location = Location;
          print "A magical spell carries you back to the starting room.^";
          PlayerTo(Start_Room);
          rtrue;
        } else if (XYZZY_Previous_Location ~= nothing) {
          print "A magical spell carries you back to your previous location.^";
          PlayerTo(XYZZY_Previous_Location);
          XYZZY_Previous_Location = nothing;
          rtrue;
        }
      Taste:
        "It tastes like rainbows and magic.";
      Touch:
        "The token feels appreciated.";
      Kiss:
        "Ewww! That's disgusting.";
      Wear:
        "You attempt to wear the token as a hat. It is much too small.";
    ],
  life [;
    Tell:
        XYZZY_Consult();
        rtrue;
  ],
  has animate scored
;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

! Hidden debugging commands.
[ XYZZY_Consult
  word
  num
  room;

  ! Gather some details.
  wn = consult_from;
  consult_from = 0;
  num = TryNumber(wn);
  word = NextWord();

  ! Try to figure out what to do.
  if (num > 0) {
    ! Teleport the player to the given room number.
    ! This only applies to City rooms that have a number.
    room = Find_Room_Number(num);
    if (room == nothing) {
      print "That location doesn't exist.^";
      PlayerTo(thedark);
    } else {
      print "<Whooshing teleporting noises!>^";
      PlayerTo(room);
    }
  } else {
    print "What?^";
  }
];

[ XYZZYSub;
  print
   "You say 'XYZZY'.^
    You wait expectantly...^^
    Nothing happens.^";
    if (XYZZY_Token in nothing) {
      move XYZZY_Token to player;
      Notebook.add(Notebook_XYZZY_Token);
      print "^You have received a special token.";
    }
];

! ------------------------------------------------------------------------------
! Grammar
! ------------------------------------------------------------------------------

Verb "xyzzy"
  *           -> XYZZY;

Extend "say" first
  * "xyzzy"   -> XYZZY;