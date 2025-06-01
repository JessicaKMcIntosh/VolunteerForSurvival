! ------------------------------------------------------------------------------
! stuff - Random stuff that doesn't really fit anywhere else.
!         Also separated to make testing easier.
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

Message "Loading the Stuff library.";

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

! Silly Half Life reference.
[ CrowbarSub;
  if (Crowbar notin player) {
    "You do not currently possess a Crowbar.^";
  }

  if (noun == nothing) {
    "Use the Crowbar on what?";
  }

  if (noun has lockable) {
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
      print (The) noun, " is already unlocked.^";
    }
  } else {
    print "The Crowbar does nothing to ", (the) noun, ".^";
  }
];

! Test that City_Find_Room_Direction returns expected results.
[ Test_Find_City_Room;
  print "^Testing FindCityRoom()...^";
  Test_City_Find_Room_Check(City_20_23,    'north', City_18_20_23);
  Test_City_Find_Room_Check(City_22_23_25, 'north', City_20_23_25);
  Test_City_Find_Room_Check(City_20_23_25, 'north', nothing);
  print "^";

  Test_City_Find_Room_Check(City_32_23,    'south', City_32_34_23);
  Test_City_Find_Room_Check(City_30_23_25, 'south', City_32_23_25);
  Test_City_Find_Room_Check(City_32_23_25, 'south', nothing);
  print "^";

  Test_City_Find_Room_Check(City_22_37,    'east', City_22_37_39);
  Test_City_Find_Room_Check(City_22_24_35, 'east', City_22_24_37);
  Test_City_Find_Room_Check(City_22_24_37, 'east', nothing);
  print "^";

  Test_City_Find_Room_Check(City_22_21,    'west', City_22_19_21);
  Test_City_Find_Room_Check(City_22_24_23, 'west', City_22_24_21);
  Test_City_Find_Room_Check(City_22_24_21, 'west', nothing);
  print "Complete.^";
];

! Check Find_City_Room_Direction on a specific room has the desired results.
[ Test_City_Find_Room_Check
  room
  direction
  expected
  actual;

  print "Checking ", (address) direction, " from ", (name) room, "...^";
  actual = Find_City_Room_Direction(room, direction);
  print "Found: ";
  if (actual == nothing) {
    print "nothing...";
  } else {
    print(name) room;
  }
  if (actual == expected) {
    print " Success.^";
  } else {
    print " FAILED!^";
  }
];

! Find the matching city location given the room number.
[ Find_Room_Number
  num
  room;
  objectloop(room ofclass Room_Class) {
    if (room.number == num) {
      return room;
    }
  }
  return nothing;
];

! Find the matching city location given the room number.
[ Find_City_Room_Number
  position
  room;
  objectloop(room ofclass City_Class) {
    if (room.number == position) {
      return room;
    }
  }
  return nothing;
];

! Find the matching city location in the specified direction.
! Returns nothing if there is no room in the given direction.
! This is only for rooms on the map grid and excludes the two subway junctions.
[ Find_City_Room_Direction
  room      ! The room to start from.
  direction ! The direction to search in. 'north', 'south', 'east', 'west'
  avenue    ! Decoded then adjusted avenue.
  street    ! Decoded then adjusted street.
  position; ! Encoded location as a number.

  ! Decode the room number into the street and avenue.
  avenue = (room.number / 19) + 19;
  street = (room.number % 19) + 20;

  #Ifdef DEBUG;
  print "DEBUG: City_Find_Room_Direction:^";
  position = ((avenue - 19) * 19) + (street - 20);
  print "DEBUG >>", (address) direction, " => ", avenue, " Ave ", street, " St  = ", position, "^";
  #Endif;

  ! Figure out what to do based on the direction.
  switch (direction) {
    'north':
      if ((street % 2) == 1) {            ! On a street.
        if (avenue == 19) return nothing; ! Top of the map.
        avenue = avenue - 1;
      } else {                            ! On an Avenue between two streets.
        if (avenue == 20) return nothing; ! Top of the map.
        avenue = avenue - 2;
      }
    'south':
      if ((street % 2) == 1) {            ! On a street.
        if (avenue == 33) return nothing; ! Bottom of the map.
        avenue = avenue + 1;
      } else {                            ! On an Avenue between two streets.
        if (avenue == 32) return nothing; ! Bottom of the map.
        avenue = avenue + 2;
      }
    'east':
      if ((avenue % 2) == 0) {            ! On an avenue.
        if (street == 38) return nothing; ! Right edge of the map.
        street = street + 1;
      } else {                            ! On a street between two avenues.
        if (street == 37) return nothing; ! Right edge of the map.
        street = street + 2;
      }
    'west':
      if ((avenue % 2) == 0) {            ! On an avenue.
        if (street == 20) return nothing; ! Left edge of the map.
        street = street - 1;
      } else {                            ! On a street between two avenues.
        if (street == 21) return nothing; ! Left edge of the map.
        street = street - 2;
      }
    default:              return nothing; ! Not a valid direction.
  }

  ! Recreate the number for the corresponding city location.
  position = ((avenue - 19) * 19) + (street - 20);

  #Ifdef DEBUG;
  print "DEBUG <<", (address) direction, " => ", avenue, " Ave ", street, " St = ", position, "^";
  #Endif;

  ! Try to find the room with the matching number.
  ! This should return something if everything worked correctly.
  return Find_City_Room_Number(position);
];
