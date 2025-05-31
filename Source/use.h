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

[UseSub;
  if (noun == nothing)                  "Use what?";
  if (noun == XYZZY_Token)              <<Rub noun>>;
  if (noun ofclass Tape_Cassette_Class) <<Play noun>>;
  if (noun ofclass Notebook_Class)      <<Read noun>>;
  "You don't know how to use ", (the) noun, ".";
];

! ------------------------------------------------------------------------------
! Grammar
! ------------------------------------------------------------------------------

! General Use verb.
Verb 'use'
  *                                                         -> Use
  *                                             edible      -> Eat
  *                                             openable    -> Open
  *                                             switchable  -> Turn
  * 'crowbar'/'bar'/'crow'                      lockable    -> Crowbar
  * 'crowbar'/'bar'/'crow' 'open'/'on'/'with'   lockable    -> Crowbar
  * 'crowbar'/'bar'/'crow' 'to' 'open'          lockable    -> Crowbar
  * 'crowbar'/'bar'/'crow'                                  -> Crowbar
  * 'crowbar'/'bar'/'crow' 'open'/'on'/'with'   noun        -> Crowbar
  * 'crowbar'/'bar'/'crow' 'to' 'open'          noun        -> Crowbar
  * 'book'/'note'/'notebook'                    topic       -> Notebook
  * 'book'/'note'/'notebook' 'page'             topic       -> Notebook
  * 'note' 'book'                               topic       -> Notebook
  * 'note' 'book' 'page'                        topic       -> Notebook
  *                                             noun        -> Use;
