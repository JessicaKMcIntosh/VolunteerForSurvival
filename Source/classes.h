! ------------------------------------------------------------------------------
! classes - All of the classes used by the world that are not part of a libary.
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

! A dark room.
Class Dark_Room_Class
;

! City streets.
! Print descriptions for the directions here so the city.h file doesn't have to
! contain the full description and we can dynamically change the location.
Class City_Class
  with
    describe [;
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
        print "East to ",  (name) self.e_to, ".^";
      }

      if (self provides w_to) {
        print "West to ",  (name) self.w_to, ".^";
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
          print "Down to ",  (name) self.d_to, ".^";
        }
      }

      if (self provides in_to) {
        print "In to ",  (name) self.in_to, ".^";
      }
    ],
  has light
;

! Subways.
Class Subway_Class
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
