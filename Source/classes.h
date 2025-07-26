! ------------------------------------------------------------------------------
! classes - All of the classes used by the world that are not part of a library.
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

Message "Loading the Classes library.";

! ------------------------------------------------------------------------------
! Classes
! ------------------------------------------------------------------------------

! Just a basic room.
Class Room_Class
  has light
;

! Self describing room class.
! Print descriptions for the directions here so the city.h file doesn't have to
! contain the full description and we can dynamically change the location.
Class Self_Describe_Room
  class Room_Class,
  with
    describe [;
      #Ifdef DEBUG;
        print "DEBUG: Room number: ", self.number;
        if (self ofclass City_Class) {
          print ", City: ", ((self.number / 19) + 19), " Ave ", ((self.number % 19) + 20), " St";
        }
        print "^";
      #Endif;
      if (self provides n_to) {
        print "North to ", (name) self.n_to, ".^";
      }

      if (self provides s_to) {
        if (self.s_to == Start_Alley) {
          print "South to a suspiciously empty alley.^";
        } else {
          print "South to ", (name) self.s_to, ".^";
        }
      }

      if (self provides e_to) {
        print "East to ", (name) self.e_to, ".^";
      }

      if (self provides w_to) {
        print "West to ", (name) self.w_to, ".^";
      }

      if (self provides u_to) {
        if (self.u_to ofclass Storm_Class) {
          print "Up to the storm drain.^";
        } else if (self.u_to ofclass Subway_Blue_Class) {
          print "Up to the Blue subway line.^";
        } else if (self.u_to ofclass Subway_Green_Class) {
          print "Up to the Green subway line.^";
        } else if (self.u_to ofclass Subway_Orange_Class) {
          print "Up to the Orange subway line.^";
        } else {
          print "Up to ", (name) self.u_to, ".^";
        }
      }

      if (self provides d_to) {
        if (self.d_to ofclass Storm_Class) {
          print "Down to the storm drain.^";
        } else if (self.d_to ofclass Subway_Blue_Class) {
          print "Down to the Blue subway line.^";
        } else if (self.d_to ofclass Subway_Green_Class) {
          print "Down to the Green subway line.^";
        } else if (self.d_to ofclass Subway_Orange_Class) {
          print "Down to the Orange subway line.^";
        } else {
          print "Down to ", (name) self.d_to, ".^";
        }
      }

      if (self provides in_to) {
        print "In to ", (name) self.in_to, ".^";
      }

      if (self provides out_to) {
        print "Out to ", (name) self.out_to, ".^";
      }
    ],
;

! City streets.
Class City_Class
  class Self_Describe_Room
;

! Subways.
Class Subway_Class
  class Room_Class,
  has ~light
;

Class Subway_Blue_Class
  class Subway_Class
;

Class Subway_Green_Class
  class Subway_Class
;

Class Subway_Orange_Class
  class Subway_Class
;

! Storm drains.
Class Storm_Class
  class Self_Describe_Room,
  has ~light
;

! Object the player can possess.
Class Item_Class
;

! Scenery.
Class Scenery_Class
  has static
;

! A door.
Class Door_Class
  has static door openable
;
