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
Class City_Class
  has light
;

! Subways.
Class Subway_Class
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
