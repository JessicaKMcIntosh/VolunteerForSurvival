! ------------------------------------------------------------------------------
! Use - The verb USE and support routines.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
! ------------------------------------------------------------------------------
! USAGE
! ------------------------------------------------------------------------------
! Include after Grammar but before loading world areas.
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the Use library.";

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

[ CrowbarSub;
  if (noun has locked) {
    if (noun.with_key == Crowbar) {
      give noun ~locked;
      give noun open;
      print "You use the Crowbar to pry open ", (the) noun, ", revealing ";
      if (WriteListFrom(child(noun), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT) == 0) "nothing.";
    } else {
      print "The Crowbar does not work on ", (the) noun, ".^";
    }
  } else {
    print "The Crowbar does nothing to ", (the) noun, ".^";
  }
];

! ------------------------------------------------------------------------------
! Grammar
! ------------------------------------------------------------------------------

! General Use verb.
Verb 'use'
  *             -> Help
  * edible      -> Eat
  * openable    -> Open
  * switchable  -> Turn
  * 'crowbar'/'bar'/'crow' noun    -> Crowbar
  * 'crowbar'/'bar'/'crow' locked  -> Crowbar
  * 'crowbar'/'bar'/'crow' 'open'/'on'/'with' noun    -> Crowbar
  * 'crowbar'/'bar'/'crow' 'open'/'on'/'with' locked  -> Crowbar
  * 'crowbar'/'bar'/'crow' 'to' 'open' noun    -> Crowbar
  * 'crowbar'/'bar'/'crow' 'to' 'open' locked  -> Crowbar;
