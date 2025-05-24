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

! The room the player spawns into.
Room_Class Start_Room "Empty Alley Dead End"
  with
    description
       "To the east is a large metal door leading back to the shelter.^
        Next to the door, built into the wall, is a drop box.^
        To the north is more of the empty alley.",
    initial [;
      if (self hasnt visited) {
        print "^";
        print "You are laying in a small empty alley.^";
        print "You feel a hard object in your pocket.";
        print "^";
      }
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
  has lockable locked
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
    name 'bar' 'crow' 'crowbar' 'orange',
    description "An oddly familiar orange crowbar.",
  has scored
;

Item_Class -> -> Radio "old radio"
  with
    name 'radio',
    description "An old radio that should pickup messages from the shelter.",
  has scored
;

Notebook_Class -> -> Notebook "small notebook"
  has scored
;

Notebook_Page_Class -> -> -> Notebook_Items_To_Get "List of items to find"
  with
    name 'list' 'find' 'items' 'item',
    description "A list of items to find for the shelter.",
    inside_description
     "We need food above all.^
      Canned food, sealed rations, anything preserved and edible.^
      Working electronics like laptops, tablets, phones and similar.^
      Tools are in short supply as well.^
      Anything else useful you might find go ahead and bring back.^
      ^
      Place items in the box where you woke up for rewards.^
      Being back enough stuff and you will be allowed to return to the shelter.",
;

Notebook_Page_Class -> -> -> Notebook_Agalsirodine_Pamphlet "Agalsirodine Pamphlet"
  with
    name 'agalsirodine' 'pills',
    description "Agalsirodine Pamphlet",
    inside_description
     "NEW! From the makers of AdderFocusAll comes...^
      Agalsirodine!^
      Keep your mind in order with Agalsirodine!^
      ^
      Warning:^
      Will cause memory loss and hallucinations.^
      May cause brain damage.^
      Not certified, or recommended, for human consumption.^
      Do not take Agalsirodine if you are still breathing.^
      Consult a psychiatrist for delusions and psychosis.^
      ^
      The little green men really are out to get YOU!^
      Keep them at bay with Agalsirodine.",
;

! More will be done with this later.
Dark_Room_Class Shelter_Entrance "Entrance to the government shelter."
;

! Second room of the starting area.
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
  after [;
    ! Move the notebook page representing this tape into the notebook.
    Notebook.add(Notebook_Tape_1);
  ],
  has scored
;

! Put a mailbox on the first city street.
Loot_Container_Mail First_Mailbox City_28_25_27
  with
    description "A worn mail drop box with an odd inscription on the back.",
    short_name "worn mail drop box",
    before [;
      Read:
        <<Examine XYZZY_Inscription>>;
    ],
  has lockable locked
;

Tape_Cassette_Class Tape_2 "tape #2" First_Mailbox
  with
    name 'cassette' 'tape' '#2' 'tape_2' 'tape_#2',
    description "A microcassette tape containing a message from another volunteer.",
    inside_description
     "Jones, make sure you leave some food for me.^
      I found those things you wanted so you better pay me back.^
      Some day you need to tell me what the hell a Zork even is.^
      Ungrateful piece of ...",
  has scored
;

! Just a bit of fun.
Object XYZZY_Inscription "Inscription" City_28_25_27
  with
    name 'inscription' 'odd',
    description "The magic word is XYZZY."
  has concealed static
;
