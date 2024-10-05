! ------------------------------------------------------------------------------
! subway - The subways and junctions of the city.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Subway Junctions
! ------------------------------------------------------------------------------

Subway_Class Junction_20 "Subway junction at 20th Ave"
  with
    description "
      East to the Orange line under 20th Ave between 19th St and 21st St^
      South to the Green line under 22nd Ave between 19th St and 21st St^
      Up to 20th Ave and 19th St^
      Down to the storm drain.^
    ",
    e_to Subway_Orange_20_19_21,
    s_to Subway_Green_22_19_21,
    u_to City_20_19,
    d_to Storm_Junction_20_19,
;

City_Class City_20_19 "20th Ave and 19th St"
  with
    description "
    East to 20th Ave between 19th St and 21st St.^
    Down to Subway junction^
    ",
    e_to City_20_19_21,
    d_to Junction_20,
;

Subway_Class Junction_37 "Subway junction at 37th St"
  with
    description "
      East to the Orange line under 20th Ave between 19th St and 21st St^
      South East to the Green line under 22nd Ave between 19th St and 21st St^
      Up to 34th Ave and 37th St^
      Down to the storm drain.^
    ",
    e_to Subway_Orange_20_19_21,
    se_to Subway_Green_22_19_21,
    u_to City_34_37,
    d_to Storm_Junction_34_37,
;

City_Class City_34_37 "34nd Ave and 37th St"
  with
    description "
    North to 37th St between 32thAve and 34nd Ave.^
    ",
    n_to City_32_34_37,
    d_to Junction_37,
;

! ------------------------------------------------------------------------------
! Blue Line
! ------------------------------------------------------------------------------



! ------------------------------------------------------------------------------
! Green Line
! ------------------------------------------------------------------------------



! ------------------------------------------------------------------------------
! Orange Line
! ------------------------------------------------------------------------------


