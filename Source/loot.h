! ------------------------------------------------------------------------------
! Loot - Classes and code for loot found in the wasteland.
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
! Types of Treasure:
! * Electronics
! * Toolbox
! * Rations
! * Scrap metal
! * Twinkies
!
! Types of Junk:
! * Spoiled canned food
! * Broken electronics
! * Junk
! * Rusty tools
! * Ruined office supplies
!
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the Loot library.";

! ------------------------------------------------------------------------------
! Constants
! ------------------------------------------------------------------------------


! ------------------------------------------------------------------------------
! Classes
! ------------------------------------------------------------------------------

! Treasure with a value.
Class Loot_Treasure
;

Class Loot_Treasure_Laptop
  class Loot_Treasure,
  with
    name 'laptop',
    short_name "laptop computer",
    description "A laptop computer with some life left in it.",
;

Class Loot_Treasure_Rations
  class Loot_Treasure,
  with
    name 'rations' 'ration',
    short_name "tasty rations",
    description "A box of rations, cardboard flavored.",
;

Class Loot_Treasure_Twinkies
  class Loot_Treasure,
  with
    name 'twinkies' 'twinkie',
    short_name "twinkies",
    description "Everlasting twinkies.",
;

Class Loot_Treasure_Scrap_Metal
  class Loot_Treasure,
  with
    name 'scrap' 'metal',
    short_name "scrap metal",
    description "Scrap metal waiting to be molded into scrap parts.",
;

Class Loot_Treasure_Scrap_Toobox
  class Loot_Treasure,
  with
    name 'toolbox' 'tools' 'box',
    short_name "toolbox",
    description "A toolbox filled with useful items.",
;

! Worthless junk.
Class Loot_Junk
;

Class Loot_Junk_Spoiled_Canned_Food
  class Loot_Junk,
  with
    name 'can' 'food' 'spoiled',
    short_name "spoiled canned food",
    description "A worthless spoiled can of food that does not smell good."
;

Class Loot_Junk_Broken_Electronics
  class Loot_Junk,
  with
    name 'broken' 'electronics',
    short_name "broken electronics",
    description "A piece of electronics so broken it is now uselesss."
;

Class Loot_Junk_Rusty_Tools
  class Loot_Junk,
  with
    name 'rusty' 'tools',
    short_name "rusty tools",
    description "Tools so rusty they are no longer usable."
;

Class Loot_Junk_Ruined_Office_Supplies
  class Loot_Junk,
  with
    name 'ruined' 'office' 'supplies',
    short_name "ruined office supplies",
    description "Damp disgusting office supplies smelling of mold."
;

Class Loot_Junk_Junk
  class Loot_Junk,
  with
    name 'junk',
    short_name "junk",
    description "It must have had a purpose at some point."
;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

