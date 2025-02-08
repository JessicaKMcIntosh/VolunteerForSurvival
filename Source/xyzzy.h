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
    ]
  has scored
;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

[ XYZZYSub;
  print
   "You say 'XYZZY'.^
    You wait expectantly...^^
    Nothing happens.^";
    if (XYZZY_Token in nothing) {
      move XYZZY_Token to player;
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