! ------------------------------------------------------------------------------
! storm - The storm drain junctions of the city.
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
! NOTES
! ------------------------------------------------------------------------------
! This file contains rooms from the 11xx serries.
! Specifically 1180 - 1189 - Storm drain junctions.
! See the file `RoomNumbers.md` for details.
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the storm drains.";

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

Storm_Class Storm_Junction_20_19 "Storm Drain Junction at 20th Ave and 19th Street"
  with
    number 1180,
    e_to Storm_20_22_21,
    u_to Junction_20,
;

Storm_Class Storm_Junction_34_37 "Storm Drain Junction at 34th Ave and 37th Street"
  with
    number 1181,
    n_to Storm_32_37_39,
    u_to Junction_37,
;

Storm_Class Storm_Junction_20_23 "Storm Drain Junction at 20th Ave and 23rd St"
  with
    number 1182,
    e_to Storm_20_23_25,
    s_to Storm_20_22_23,
;

Storm_Class Storm_Junction_20_29 "Storm Drain Junction at 20th Ave and 29th St"
  with
    number 1183,
    s_to Storm_20_22_29,
    e_to Storm_20_29_31,
;

Storm_Class Storm_Junction_20_37 "Storm Drain Junction at 20th Ave and 37th St"
  with
    number 1184,
    s_to Storm_20_22_37,
    e_to Storm_20_37_39,
;

Storm_Class Storm_Junction_30_23 "Storm Drain Junction at 30th Ave and 23rd St"
  with
    number 1185,
    s_to Storm_30_32_23,
    e_to Storm_30_23_25,
;

Storm_Class Storm_Junction_30_29 "Storm Drain Junction at 30th Ave and 29th St"
  with
    number 1186,
    s_to Storm_30_32_29,
    e_to Storm_30_29_31,
;

Storm_Class Storm_Junction_30_37 "Storm Drain Junction at 30th Ave and 37th St"
  with
    number 1187,
    s_to Storm_30_32_29,
    e_to Storm_30_29_31,
;
