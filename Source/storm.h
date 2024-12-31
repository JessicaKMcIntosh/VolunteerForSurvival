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
    e_to Storm_20_22_21,
    u_to Junction_20,
;

Storm_Class Storm_Junction_34_37 "Storm Drain Junction at 34th Ave and 37th Street"
  with
    n_to Storm_32_37_39,
    u_to Junction_37,
;

Storm_Class Storm_Junction_20_23 "Storm Drain Junction at 20th Ave and 23rd St"
  with
    e_to Storm_20_23_25,
    s_to Storm_20_22_23,
;

Storm_Class Storm_Junction_20_29 "Storm Drain Junction at 20th Ave and 29th St"
  with
    s_to Storm_20_22_29,
    e_to Storm_20_29_31,
;

Storm_Class Storm_Junction_20_37 "Storm Drain Junction at 20th Ave and 37th St"
  with
    s_to Storm_20_22_37,
    e_to Storm_20_37_39,
;

Storm_Class Storm_Junction_30_23 "Storm Drain Junction at 30th Ave and 23rd St"
  with
    s_to Storm_30_32_23,
    e_to Storm_30_23_25,
;

Storm_Class Storm_Junction_30_29 "Storm Drain Junction at 30th Ave and 29th St"
  with
    s_to Storm_30_32_29,
    e_to Storm_30_29_31,
;

Storm_Class Storm_Junction_30_37 "Storm Drain Junction at "
  with
    s_to Storm_30_32_29,
    e_to Storm_30_29_31,
;
