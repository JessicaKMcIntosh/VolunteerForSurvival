! ------------------------------------------------------------------------------
! storm - The storm drain junctions of the city.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
! ------------------------------------------------------------------------------

Storm_Class Storm_Junction_20_19 "Storm Drain Junction at 20th Ave and 19th Street"
  with
    description "
      East to the Storm Drain below 21st St between 20thAve and 22nd
      Up to Subway junction at 20th Ave.
    ",
    e_to Storm_20_22_21,
    u_to Junction_20,
;

Storm_Class Storm_Junction_34_37 "Storm Drain Junction at 34th Ave and 37th Street"
  with
    description "
      North to the Storm Drain below 32nd Ave between 37th St and 39th.
      Up to Subway junction at 37th St.
    ",
    n_to Storm_32_37_39,
    u_to Junction_37,
;

Storm_Class Storm_Junction_20_23 "Storm Drain Junction at 20th Ave and 23rd St"
  with
    description "
    South to the Storm Drain below 23rd St between 20thAve and 22nd St.
    East to the Storm Drain below 20th Ave between 23rd St and 25th St.
    ",
    e_to Storm_20_23_25,
    s_to Storm_20_22_23,
;

Storm_Class Storm_Junction_20_29 "Storm Drain Junction at 20th Ave and 29th St"
  with
    description "
    South to the Storm Drain below 29th St between 20thAve and 22nd Ave.
    East to the Storm Drain below 20th Ave between 29th St and 31st St.
    ",
    s_to Storm_20_22_29,
    e_to Storm_20_29_31,
;

Storm_Class Storm_Junction_20_37 "Storm Drain Junction at 20th Ave and 37th St"
  with
    description "
    South to the Storm Drain below 37th St between 20thAve and 22nd Ave.
    East to the Storm Drain below 20th Ave between 37th St and 39th St.
    ",
    s_to Storm_20_22_37,
    e_to Storm_20_37_39,
;

Storm_Class Storm_Junction_30_23 "Storm Drain Junction at 30th Ave and 23rd St"
  with
    description "
    South to the Storm Drain below 23rd St between 30thAve and 32nd St.
    East to the Storm Drain below 30th Ave between 23rd St and 25th St.
    ",
    s_to Storm_30_32_23,
    e_to Storm_30_23_25,
;

Storm_Class Storm_Junction_30_29 "Storm Drain Junction at 30th Ave and 29th St"
  with
    description "
    South to Stthe Stormorm Drain below 29th St between 30thAve and 32nd Ave.
    East to the Storm Drain below 30th Ave between 29th St and 31st St.
    ",
    s_to Storm_30_32_29,
    e_to Storm_30_29_31,
;

Storm_Class Storm_Junction_30_37 "Storm Drain Junction at "
  with
    description "
    South to the Storm Drain below 29th St between 30thAve and 32nd St.
    East to Storthe Stormm Drain below 30th Ave between 29th St and 31st St.
    ",
    s_to Storm_30_32_29,
    e_to Storm_30_29_31,
;