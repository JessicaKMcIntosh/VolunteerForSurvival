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

! The maximum number of an individual loot item that can exist.
Constant Loot_Max_Items = 10;

! The number of treasure and junk classes.
Constant Loot_Number_Treasure = 5;
Constant Loot_Number_Junk = 5;
Constant Loot_Number = (Loot_Number_Treasure + Loot_Number_Junk);
Constant Loot_Number_Subway = 4;

! The number of loot containers of each type to create.
Constant Loot_Containers = 20;

! ------------------------------------------------------------------------------
! Loot Table
! ------------------------------------------------------------------------------

! The table of all loot available.
Array Loot_Table --> (Loot_Number + 1);

! The subway loot table.
Array Loot_Table_Subway --> (Loot_Number_Subway + 1);

! ------------------------------------------------------------------------------
! Treasure with a value
! ------------------------------------------------------------------------------

Class Loot_Treasure
;

Class Loot_Treasure_Laptop(Loot_Max_Items)
  class Loot_Treasure,
  with
    name 'laptop',
    short_name "laptop computer",
    description "A laptop computer with some life left in it.",
    plural "laptop computers",
;

Class Loot_Treasure_Rations(Loot_Max_Items)
  class Loot_Treasure,
  with
    name 'rations' 'ration',
    short_name "tasty rations",
    description "A box of rations, cardboard flavored.",
    plural "boxes of tasty rations",
  has pluralname
;

Class Loot_Treasure_Twinkies(Loot_Max_Items)
  class Loot_Treasure,
  with
    name 'twinkies' 'twinkie',
    short_name "pack of twinkies",
    description "Everlasting twinkies.",
    plural "packs of twinkies",
;

Class Loot_Treasure_Scrap_Metal(Loot_Max_Items)
  class Loot_Treasure,
  with
    name 'scrap' 'metal',
    short_name "scrap metal",
    description "Scrap metal waiting to be molded into scrap parts.",
    plural "pieces of scrap metal",
  has pluralname
;

Class Loot_Treasure_Scrap_Toobox(Loot_Max_Items)
  class Loot_Treasure,
  with
    name 'toolbox' 'tools' 'box',
    short_name "toolbox",
    description "A toolbox filled with useful items.",
    plural "toolboxes",
;

! ------------------------------------------------------------------------------
! Worthless junk
! ------------------------------------------------------------------------------

Class Loot_Junk
;

Class Loot_Junk_Spoiled_Canned_Food(Loot_Max_Items)
  class Loot_Junk,
  with
    name 'can' 'food' 'spoiled',
    short_name "spoiled can of food",
    description "A worthless spoiled can of food that does not smell good.",
    plural "spoiled cans of food",
;

Class Loot_Junk_Broken_Electronics(Loot_Max_Items)
  class Loot_Junk,
  with
    name 'broken' 'electronics',
    short_name "broken electronics",
    description "A piece of electronics so broken it is now uselesss.",
    plural "crates of broken electronics",
  has pluralname
;

Class Loot_Junk_Rusty_Tools(Loot_Max_Items)
  class Loot_Junk,
  with
    name 'rusty' 'tools',
    short_name "rusty tools",
    description "Tools so rusty they are no longer usable.",
    plural "sets of rusty tools",
  has pluralname
;

Class Loot_Junk_Ruined_Office_Supplies(Loot_Max_Items)
  class Loot_Junk,
  with
    name 'ruined' 'office' 'supplies',
    short_name "ruined office supplies",
    description "Damp disgusting office supplies smelling of mold.",
    plural "legal boxes of ruined office supplies",
  has pluralname
;

Class Loot_Junk_Junk(Loot_Max_Items)
  class Loot_Junk,
  with
    name 'junk',
    short_name "junk",
    description "It must have had a purpose at some point.",
    plural "piles of junk",
  has pluralname
;

! ------------------------------------------------------------------------------
! Loot containers
! ------------------------------------------------------------------------------

! Mail drop box that contains treasure.
Class Loot_Container_Mail(Loot_Containers)
  with
    name 'box' 'drop' 'mail' 'mailbox',
    description "A mail drop box.",
    short_name "mail drop box",
    with_key Crowbar,
    create [;
      ! Create loot in the mailbox.
      CreateRandomLoot(self);

      ! Randomly decide if the box is locked or not.
      if (random(2) == 1) {
        give self lockable;
        give self locked;
      }
    ],
  has container static openable
;

! Trash can that contains treasure.
Class Loot_Container_Trash(Loot_Containers)
  with
    name 'can' 'trash' 'refuse',
    description "A trash can.",
    short_name "trash can",
    create [;
      ! Create loot in the trash cah.
      CreateRandomLoot(self);
    ],
  has container static openable
;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

! Create a random loot object then move to the given container.
[ CreateRandomLoot
  Container     ! The container to move the loot to.
  RandomNumber  ! Random number for determining the loot.
  RandomClass   ! The random loot class;
  RandomLoot;   ! The random loot object.

  ! Pick a random number.
  ! If the number is higher than Loot_Number then no loot.
  RandomNumber = random(Loot_Number + 1);
  if (RandomNumber > Loot_Number) {
    #Ifdef DEBUG;
        print "DEBUG: NO LOOT FOR YOU!^";
    #Endif;
    rfalse;
  }

  ! Create the loot. Specal case for the Subway.
  if (Container ofclass Subway_Class) {
    RandomNumber = random(Loot_Number_Subway);
    RandomClass = Loot_Table_Subway-->RandomNumber;
  } else {
    RandomClass = Loot_Table-->RandomNumber;
  }
  RandomLoot = RandomClass.Create();

  ! Move the loot to the container.
  if (RandomLoot ~= nothing) {
    move RandomLoot to Container;
  } else {
    #Ifdef DEBUG;
        print "DEBUG: Loot did not create: ", (name) RandomClass, "^";
    #Endif;
    rfalse;
  }
  rtrue;
];

! Setup the loot.
[ SetupLoot
  RandomNumber  ! Randomize where mailboxes appear.
  Mailboxes     ! The number of mailboxes created.
  TrashCans     ! The number of trash cans to create.
  Container     ! The loot container to place.
  LootLocation; ! The location to place the loot.

  #Ifdef DEBUG;
    print "DEBUG: Generating loot...^";
  #Endif;

  ! Create the loot table.
  Loot_Table-->1  = Loot_Treasure_Laptop;
  Loot_Table-->2  = Loot_Treasure_Rations;
  Loot_Table-->3  = Loot_Treasure_Twinkies;
  Loot_Table-->4  = Loot_Treasure_Scrap_Metal;
  Loot_Table-->5  = Loot_Treasure_Scrap_Toobox;
  Loot_Table-->6  = Loot_Junk_Spoiled_Canned_Food;
  Loot_Table-->7  = Loot_Junk_Broken_Electronics;
  Loot_Table-->8  = Loot_Junk_Rusty_Tools;
  Loot_Table-->9  = Loot_Junk_Ruined_Office_Supplies;
  Loot_Table-->10 = Loot_Junk_Junk;

  ! Create the Subway loot table.
  Loot_Table_Subway-->1  = Loot_Treasure_Scrap_Metal;
  Loot_Table_Subway-->2  = Loot_Treasure_Scrap_Toobox;
  Loot_Table_Subway-->3  = Loot_Junk_Rusty_Tools;
  Loot_Table_Subway-->4  = Loot_Junk_Junk;

  #Ifdef DEBUG;
    print "DEBUG: Generating mailboxes and trash cans...^";
  #Endif;

  ! Generate loot containers.
  Mailboxes = 1;
  TrashCans = 1;
  objectloop (LootLocation ofclass City_Class) {
    RandomNumber = random(5);

    ! Create a mail drop box.
    if (RandomNumber == 1 && Mailboxes <= Loot_Containers) {
      Mailboxes++;
      Container = Loot_Container_Mail.create();
      #Ifdef DEBUG;
        print
          "DEBUG: Creating a ", (Container has locked),
          " mailbox containing ", (name) child(Container),
          " at ", (name) LootLocation, "^";
      #Endif;
      if (Container ~= nothing) move Container to LootLocation;
    }

    ! Create a trash can.
    if (RandomNumber == 5 && TrashCans <= Loot_Containers) {
      TrashCans++;
      Container = Loot_Container_Trash.create();
      #Ifdef DEBUG;
        print
          "DEBUG: Creating a trash can containing ", (name) child(Container),
          " at ", (name) LootLocation, "^";
      #Endif;
      if (Container ~= nothing) move Container to LootLocation;
    }
  }

  #Ifdef DEBUG;
    print "DEBUG: Generating loot in the subway...^";
  #Endif;

  ! Drop some random loot in the subway tunnels.
  objectloop (LootLocation ofclass Subway_Class) {
    if (random(5) == 1) {
      CreateRandomLoot(LootLocation);
      #Ifdef DEBUG;
        print
          "DEBUG: Creating loot ", (name) child(LootLocation),
          " at ", (name) LootLocation, "^";
      #Endif;
    }
  }

  #Ifdef DEBUG;
    print "DEBUG: Loot generation complete.^";

    ! The number of objects that can be created for each loot class.
    for (RandomNumber = 1: RandomNumber <= Loot_Number: RandomNumber++){
      Container = Loot_Table-->RandomNumber;
      print (name) Container, " has remaining ", Container.remaining(),"^";
    }
  #Endif;
];
