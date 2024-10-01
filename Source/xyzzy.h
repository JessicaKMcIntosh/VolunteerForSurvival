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
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the XYZZY library.";

! ------------------------------------------------------------------------------
! Objects
! ------------------------------------------------------------------------------

Object XYZZY_Token "XYZZY Token"
  with
    name 'xyzzy' 'token' 'xyzzy_token',
    description "A token given to those that say the magic word.",
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
      print "^You have recieved a special token.";
    }
];

! ------------------------------------------------------------------------------
! Grammar
! ------------------------------------------------------------------------------

Verb "xyzzy"
  *           -> XYZZY;

Extend "say" first
  * "xyzzy"   -> XYZZY;