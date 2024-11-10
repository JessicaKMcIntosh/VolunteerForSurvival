! ------------------------------------------------------------------------------
! subway - The subways and junctions of the city.
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

Message "Loading the subways.";

! ------------------------------------------------------------------------------
! Subway Junctions
! ------------------------------------------------------------------------------

Subway_Class Junction_20 "Subway junction at 20th Ave"
  with
    description
     "East to the Orange line under 20th Ave between 19th St and 21st St.^
      South to the Green line under 22nd Ave between 19th St and 21st St.^
      Up to 20th Ave and 19th St.^
      Down to the storm drain.^
    ",
    e_to Subway_Orange_20_19_21,
    s_to Subway_Green_22_19_21,
    u_to City_20_19,
    d_to Storm_Junction_20_19,
;

City_Class City_20_19 "20th Ave and 19th St"
  with
    description
   "East to 20th Ave between 19th St and 21st St.^
    Down to Subway junction at 20th Ave.",
    e_to City_20_19_21,
    d_to Junction_20,
;

Subway_Class Junction_37 "Subway junction at 37th St"
  with
    description
     "East to the Orange line at 35th St between 32ndAve and 34th Ave.^
      North to the Blue line at 32nd Ave between 35th St and 37th St.^
      Up to 34th Ave and 37th St.^
      Down to the storm drain.",
    e_to Subway_Orange_32_34_35,
    n_to Subway_Blue_32_35_37,
    u_to City_34_37,
    d_to Storm_Junction_34_37,
;

City_Class City_34_37 "34nd Ave and 37th St"
  with
    description
   "North to 37th St between 32th Ave and 34nd Ave.^
    Down to the Subway junction at 37th St.",
    n_to City_32_34_37,
    d_to Junction_37,
;

! ------------------------------------------------------------------------------
! Blue Line
! ------------------------------------------------------------------------------

Subway_Class Subway_Blue_18_20_35 "Blue line at 35th St between 18th Ave and 20th Ave"
  with
    description
   "The way North is blocked by a collapsed tunnel.^
    South to the Blue line at 18th Ave and 35th St.^
    Up to 35th St between 18th Ave and 20th Ave.",
    s_to Subway_Blue_20_35,
    u_to City_18_20_35,
;

Subway_Class Subway_Blue_20_35 "Blue line at 20th Ave and 35th St"
  with
    description
   "North to the Blue line at 35th St between 18th Ave and 20th Ave.^
    South to the Blue line at 35th St between 20th Ave and 22nd Ave.^
    Up to 35th St between 18th Ave and 20th Ave.",
    n_to Subway_Blue_18_20_35,
    s_to Subway_Blue_20_22_35,
    u_to City_18_20_35,
;

Subway_Class Subway_Blue_20_22_35 "Blue line at 35th St between 20th Ave and 22nd Ave"
  with
    description
   "North to the Blue line at 18th Ave and 35th St.^
    South to the Blue line at 22nhAve and 35th St.^
    Up to 35th St between 20th Ave and 22nd Ave.^
    Down to the Storm Drain below 35th St between 20th Ave and 22nd Ave.",
    n_to Subway_Blue_20_35,
    s_to Subway_Blue_22_35,
    u_to City_20_22_35,
    d_to Storm_20_22_35,
;

Subway_Class Subway_Blue_22_35 "Blue line at 22nhAve and 35th St"
  with
    description
   "North to the Blue line at 35th St between 20th Ave and 22nd Ave.^
    South to the Blue line at 24th Ave between 35th St and 37th St.^
    Up to 35th St between 18th Ave and 20th Ave.",
    n_to Subway_Blue_20_22_35,
    s_to Subway_Blue_24_35_37,
    u_to City_18_20_35,
;

Subway_Class Subway_Blue_24_35_37 "Blue line at 24th Ave between 35th St and 37th St"
  with
    description
   "North to the Blue line at 22nhAve and 35th St.^
    South to the Blue line at 26th Ave between 35th St and 37th St.^
    Up to 24th Ave between 35th St and 37th St.",
    n_to Subway_Blue_22_35,
    s_to Subway_Blue_26_35_37,
    u_to City_24_35_37,
;

Subway_Class Subway_Blue_26_35_37 "Blue line at 26th Ave between 35th St and 37th St"
  with
    description
   "North to the Blue line at 24th Ave between 35th St and 37th St.^
    South to the Blue line at 28th Ave between 35th St and 37th St.^
    Up to 26th Ave between 35th St and 37th St.",
    n_to Subway_Blue_24_35_37,
    s_to Subway_Blue_28_35_37,
    u_to City_26_35_37,
;

Subway_Class Subway_Blue_28_35_37 "Blue line at 28th Ave between 35th St and 37th St"
  with
    description
   "North to the Blue line at 26th Ave between 35th St and 37th St.^
    South to the Blue line at 35th St between 30th Ave and 32nd Ave^
    Up to 28th Ave between 35th St and 37th St.",
    n_to Subway_Blue_26_35_37,
    s_to Subway_Blue_30_32_35,
    u_to City_28_35_37,
;

Subway_Class Subway_Blue_30_32_35 "Blue line at 35th St between 30th Ave and 32nd Ave"
  with
    description
   "North to the Blue line at 28th Ave between 35th St and 37th St.^
    South to the Blue line at 32nd Ave between 35th St and 37th St.^
    Up to 35th St between 30th Ave and 32nd Ave.^
    Down to the Storm Drain below 35th St between 30th Ave and 32nd Ave.",
    n_to Subway_Blue_28_35_37,
    s_to Subway_Blue_32_35_37,
    u_to City_30_32_35,
    d_to Storm_30_32_35,
;

Subway_Class Subway_Blue_32_35_37 "Blue line at 32nd Ave between 35th St and 37th St"
  with
    description
   "North to the Blue line at 35th St between 30th Ave and 32nd Ave.^
    South to the Subway junction at 37th St.^
    Up to 32nd Ave between 35th St and 37th St.",
    n_to Subway_Blue_30_32_35,
    s_to Junction_37,
    u_to City_32_35_37,
;

! ------------------------------------------------------------------------------
! Green Line
! ------------------------------------------------------------------------------

Subway_Class Subway_Green_22_19_21 "Green line at 22nd Ave between 19th St and 21st St"
  with
    description
   "North to the Subway junction at 20th Ave.^
    Up to 22nd Ave between 19th St and 21st St.",
    n_to Junction_20,
    u_to City_22_19_21,
;

Subway_Class Subway_Green_24_19_21 "Green line at 24th Ave between 19th St and 21st St"
  with
    description
   "North to the Green line at 22nd Ave between 19th St and 21st St.^
    South to the Green line at 21st St between 24th Ave and 26th Ave.^
    Up to 24th Ave between 19th St and 21st St.",
    n_to Subway_Green_22_19_21,
    s_to Subway_Green_24_26_21,
    u_to City_24_19_21,
;

Subway_Class Subway_Green_24_26_21 "Green line at 21st St between 24th Ave and 26th Ave"
  with
    description
   "North to the Green line at 24th Ave between 19th St and 21st St.^
    South to the Green line at 26th Ave between 21st St and 23rd St.^
    Up to 21st St between 24th Ave and 26th Ave.",
    n_to Subway_Green_24_19_21,
    s_to Subway_Green_26_21_23,
    u_to City_24_26_21,
;

Subway_Class Subway_Green_26_21_23 "Green line at 26th Ave between 21st St and 23rd St"
  with
    description
   "North to the Green line at 21st St between 24th Ave and 26th Ave.^
    South to teh Green line at 28th Ave between 21st St and 23rd St.^
    Up to 26th Ave between 21st St and 23rd St.",
    n_to Subway_Green_24_26_21,
    s_to Subway_Green_28_21_23,
    u_to City_26_21_23,
;

Subway_Class Subway_Green_28_21_23 "Green line at 28th Ave between 21st St and 23rd St"
  with
    description
   "North to the Green line at 26th Ave between 21st St and 23rd St.^
    South to the Green line at 30th Ave between 21st St and 23rd St.^
    Up to 28th Ave between 21st St and 23rd St.",
    n_to Subway_Green_26_21_23,
    s_to Subway_Green_30_21_23,
    u_to City_28_21_23,
;

Subway_Class Subway_Green_30_21_23 "Green line at 30th Ave between 21st St and 23rd St"
  with
    description
   "North to the Green line at 28th Ave between 21st St and 23rd St.^
    South to the Green line at 32nd Ave between 21st St and 23rd St.^
    Up to 30th Ave between 21st St and 23rd St.",
    n_to Subway_Green_28_21_23,
    s_to Subway_Green_32_21_23,
    u_to City_30_21_23,
;

Subway_Class Subway_Green_32_21_23 "Green line at 32nd Ave between 21st St and 23rd St"
  with
    description
   "North to the Green line at 30th Ave between 21st St and 23rd St.^
    South to the Green line at 23rd St between 32ndAve and 34th Ave.^
    Up to 32nd Ave between 21st St and 23rd St.",
    n_to Subway_Green_30_21_23,
    s_to Subway_Class Subway_Green_32_34_23 "Green line at 23rd St between 32ndAve and 34th Ave"
,
    u_to City_32_21_23,
;

Subway_Class Subway_Green_32_34_23 "Green line at 23rd St between 32ndAve and 34th Ave"
  with
    description
   "North to the Green line at 32nd Ave between 21st St and 23rd St.^
    The way South is blocked by a collapsed tunnel.^
    Up to 23rd St between 32ndAve and 34th Ave.",
    n_to Subway_Green_32_21_23,
    u_to City_32_34_23,
;

! ------------------------------------------------------------------------------
! Orange Line
! ------------------------------------------------------------------------------

Subway_Class Subway_Orange_20_19_21 "Orange line at 20th Ave between 19th St and 21st St"
  with
    description
   "East to the Orange line at 21st St between 20th Ave and 22nd Ave.^
    West to the Subway junction at 20th Ave.^
    Up to 20th Ave between 19th St and 21st St.",
    e_to Subway_Orange_20_22_21,
    w_to Junction_20,
    u_to City_20_19_21,
;

Subway_Class Subway_Orange_20_22_21 "Orange line at 21st St between 20th Ave and 22nd Ave"
  with
    description
   "East to the Orange line at 22nd Ave between 21st St and 23rd St.^
    West to the Orange line at 20th Ave between 19th St and 21st St.^
    Up to 21st St between 20th Ave and 22nd Ave.^
    Down to the Storm Drain below 21st St between 20th Ave and 22nd Ave.",
    e_to Subway_Orange_22_21_23,
    w_to Subway_Orange_20_19_21,
    u_to City_20_22_21,
    d_to Storm_20_22_21,
;

Subway_Class Subway_Orange_22_21_23 "Orange line at 22nd Ave between 21st St and 23rd St"
  with
    description
   "East to the Orange line at 23rd St between 22ndAve and 24th Ave.^
    West to the Orange line at 21st St between 20th Ave and 22nd Ave.^
    Up to 22nd Ave between 21st St and 23rd St.",
    e_to Subway_Orange_22_24_23,
    w_to Subway_Orange_20_22_21,
    u_to City_22_21_23,
;

Subway_Class Subway_Orange_22_24_23 "Orange line at 23rd St between 22ndAve and 24th Ave"
  with
    description
   "East to the Orange line at 25th St between 22ndAve and 24th Ave.^
    West to the Orange line at 22nd Ave between 21st St and 23rd St.^
    Up to 23rd St between 22ndAve and 24th Ave.",
    e_to Subway_Orange_22_24_25,
    w_to Subway_Orange_22_21_23,
    u_to City_22_24_23,
;

Subway_Class Subway_Orange_22_24_25 "Orange line at 25th St between 22ndAve and 24th Ave"
  with
    description
   "East to the Orange line at 27th St between 22ndAve and 24th Ave.^
    West to the Orange line at 23rd St between 22ndAve and 24th Ave.^
    Up to 25th St between 22ndAve and 24th Ave.",
    e_to Subway_Orange_22_24_27,
    w_to Subway_Orange_22_24_23,
    u_to City_22_24_25,
;

Subway_Class Subway_Orange_22_24_27 "Orange line at 27th St between 22ndAve and 24th Ave"
  with
    description
   "East to the Orange line at 29th St between 22ndAve and 24th Ave.^
    West to the Orange line at 25th St between 22ndAve and 24th Ave.^
    Up to 27th St between 22ndAve and 24th Ave.",
    e_to Subway_Orange_22_24_29,
    w_to Subway_Orange_22_24_25,
    u_to City_22_24_27,
;

Subway_Class Subway_Orange_22_24_29 "Orange line at 29th St between 22ndAve and 24th Ave"
  with
    description
   "East to the Orange line at 24th Ave between 29th St and 31st St.^
    West to the Orange line at 27th St between 22ndAve and 24th Ave.^
    Up to 29th St between 22ndAve and 24th Ave.",
    e_to Subway_Orange_24_29_31,
    w_to Subway_Orange_22_24_27,
    u_to City_22_24_29,
;

Subway_Class Subway_Orange_24_29_31 "Orange line at 24th Ave between 29th St and 31st St"
  with
    description
   "East to the Orange line at 31st St between 24th Ave and 26th Ave.^
    West to the Orange line at 29th St between 22ndAve and 24th Ave.^
    Up to 24th Ave between 29th St and 31st St.^
    Down to the Storm Drain below 24th Ave between 29th St and 31st St.",
    e_to Subway_Orange_24_26_31,
    w_to Subway_Orange_22_24_29,
    u_to City_24_29_31,
    d_to Storm_24_29_31,
;

Subway_Class Subway_Orange_24_26_31 "Orange line at 31st St between 24th Ave and 26th Ave"
  with
    description
   "East to the Orange line at 26th Ave between 31st St and 33rd St.^
    West to the Orange line at 24th Ave between 29th St and 31st St.^
    Up to 31st St between 24th Ave and 26th Ave.",
    e_to Subway_Orange_26_31_33,
    w_to Subway_Orange_24_29_31,
    u_to City_24_26_31,
;

Subway_Class Subway_Orange_26_31_33 "Orange line at 26th Ave between 31st St and 33rd St"
  with
    description
   "South to the Orange line at 33rd St between 26th Ave and 28th Ave.^
    West to the Orange line at 31st St between 24th Ave and 26th Ave.^
    Up to 26th Ave between 31st St and 33rd St.",
    s_to Subway_Orange_26_28_33,
    w_to Subway_Orange_24_26_31,
    u_to City_26_31_33,
;

Subway_Class Subway_Orange_26_28_33 "Orange line at 33rd St between 26th Ave and 28th Ave"
  with
    description
   "South to Orange line at 33rd St between 28th Ave and 30th Ave.^
    North to the Orange line at 26th Ave between 31st St and 33rd St.^
    Up to 33rd St between 26th Ave and 28th Ave.",
    s_to Subway_Orange_28_30_33,
    n_to Subway_Orange_26_31_33,
    u_to City_26_28_33,
;

Subway_Class Subway_Orange_28_30_33 "Orange line at 33rd St between 28th Ave and 30th Ave"
  with
    description
   "North to the Orange line at 33rd St between 26th Ave and 28th Ave.^
    South to the Orange line at 28th Ave and 33rd St.^
    Up to 33rd St between 28th Ave and 30th Ave.",
    n_to Subway_Orange_26_28_33,
    s_to Subway_Orange_28_33,
    u_to City_28_30_33,
;

Subway_Class Subway_Orange_28_33 "Orange line at 28th Ave and 33rd St"
  with
    description
   "North to the Orange line at 33rd St between 28th Ave and 30th Ave.^
    South to the Orange line at 33rd St between 30th Ave and 32nd Ave.^
    Up to 33rd St between 28th Ave and 30th Ave.",
    n_to Subway_Orange_28_30_33,
    s_to Subway_Orange_30_32_33,
    u_to City_28_30_33,
;

Subway_Class Subway_Orange_30_32_33 "Orange line at 33rd St between 30th Ave and 32nd Ave"
  with
    description
   "North to the Orange line at 28th Ave and 33rd St.^
    South to the Orange line at 30th Ave and 33rd St.^
    Up to 33rd St between 30th Ave and 32nd Ave.^
    Down to the Storm Drain below 33rd St between 30th Ave and 32nd Ave.",
    n_to Subway_Orange_28_33,
    s_to Subway_Orange_30_33,
    u_to City_30_32_33,
    d_to Storm_30_32_33,
;

Subway_Class Subway_Orange_30_33 "Orange line at 30th Ave and 33rd St"
  with
    description
   "North to the Orange line at 33rd St between 30th Ave and 32nd Ave.^
    South to the Orange line at 32nd Ave between 33rd St and 35th St.^
    Up to 33rd St between 28th Ave and 30th Ave.",
    n_to Subway_Orange_30_32_33,
    s_to Subway_Orange_32_33_35,
    u_to City_28_30_33,
;

Subway_Class Subway_Orange_32_33_35 "Orange line at 32nd Ave between 33rd St and 35th St"
  with
    description
   "East to the Orange line at 35th St between 32ndAve and 34th Ave.^
    West to the Orange line at 30th Ave and 33rd St.^
    Up to 32nd Ave between 33rd St and 35th St.",
    e_to Subway_Orange_32_33_35,
    w_to Subway_Orange_30_33,
    u_to City_32_33_35,
;

Subway_Class Subway_Orange_32_34_35 "Orange line at 35th St between 32ndAve and 34th Ave"
  with
    description
   "East to the Subway junction at 37th St.^
    West to the Orange line at 32nd Ave between 33rd St and 35th St.^
    Up to 35th St between 32ndAve and 34th Ave.",
    e_to Junction_37,
    w_to Subway_Orange_32_33_35,
    u_to City_32_34_35,
;
