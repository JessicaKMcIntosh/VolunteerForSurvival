! ------------------------------------------------------------------------------
! starting - The starting area.
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
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the starting area.";

! ------------------------------------------------------------------------------
! Starting Area
! ------------------------------------------------------------------------------

Room_Class Start_Room "Empty Alley Dead End"
  with
    description
       "To the east is a large metal door leading back to the shelter.^
        Next to the door, built into the wall, is a drop box.^
        To the north is more of the empty alley.",
    initial [;
      print "^";
      print "You are laying in a small empty alley.^";
      print "You feel a hard object in your pocket.";
      print "^";
    ],
    e_to Start_Metal_Door,
    n_to Start_Alley,
    in_to Start_Metal_Door
;

Door_Class -> Start_Metal_Door "Metal Door"
  with
    name 'large' 'meta' 'door',
    description "A large metal door leading to the shelter entrance.",
    when_closed "The large metal door is closed and locked tight.",
    door_to Shelter_Entrance,
    door_dir e_to,
    describe [;
      rtrue;
    ],
    before [;
      Open:
        if (self has locked) "^The large metal door is locked with a keypad.";
        rtrue;
      Unlock:
        "The door is locked with a keypad.";
    ],
  has locked lockable
;

Scenery_Class -> Start_Drop_Box "Drop Box"
  with name 'drop' 'box',
    description "A drop box used to exchange items with the Shelter.",
    describe [;
      rtrue;
    ],
  has container openable
;

Lamp_Class -> -> Camping_Lantern "camping lantern"
;

Item_Class -> -> Crowbar "orange crowbar"
  with
    name 'crowbar' 'orange',
    description "An odly familiar orange crowbar.",
  has scored
;

Item_Class -> -> Radio "old radio"
  with
    name 'radio',
    description "An old radio that should pickup messages from the shelter.",
  has scored
;

Item_Class -> -> Notebook "small notebook"
  with
    name 'notebook' 'note' 'book',
    description "Not yet implemented."
  has scored
;

Dark_Room_Class Shelter_Entrance "Entrance to the government shelter."
;

Room_Class Start_Alley "Empty Alley"
  with
    description
     "An empty alley.^
      To the north is an intersection.^
      To the south is a dead end.",
    s_to Start_Room,
    n_to City_28_25_27,
;

Tape_Cassette_Class -> Tape_1 "tape #1"
  with
    name 'cassette' 'tape' '#1' 'tape_1' 'tape_#1',
    description "A microcassette tape containing a message from another volunteer.",
    inside_description "Send help. There are aliens out here who can read.... <STATIC>",
  has scored
;
