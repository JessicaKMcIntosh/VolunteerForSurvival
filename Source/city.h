City_Class City_20_21 "20th Ave and 21st St"
  with
    description "
    North to 21st St between 18thAve and 20th Ave.^
    South to 21st St between 20thAve and 22nd Ave.^
    West to 20th Ave between 19th St and 21st St.^
    East to 20th Ave between 21st St and 23rd St.^
    ",
    n_to City_18_20_21,
    s_to City_20_22_21,
    w_to City_20_19_21,
    e_to City_20_21_23,
;

City_Class City_20_19_21 "20th Ave between 19th St and 21st St"
  with
    description "
    East to 20th Ave and 21st St.^
    ",
    e_to City_20_21,
;

City_Class City_18_20_21 "21st St between 18thAve and 20th Ave"

  with
    description "
    South to 20th Ave and 21st St.^
    ",
    s_to City_20_21,
;

City_Class City_20_23 "20th Ave and 23rd St"
  with
    description "
    North to 23rd St between 18thAve and 20th Ave.^
    South to 23rd St between 20thAve and 22nd Ave.^
    West to 20th Ave between 21st St and 23rd St.^
    East to 20th Ave between 23rd St and 25th St.^
    ",
    n_to City_18_20_23,
    s_to City_20_22_23,
    w_to City_20_21_23,
    e_to City_20_23_25,
;

City_Class City_20_21_23 "20th Ave between 21st St and 23rd St"
  with

    description "
    West to 20th Ave and 21st St.^
    East to 20th Ave and 23rd St.^
    ",
    w_to City_20_21,
    e_to City_20_23,
;

City_Class City_18_20_23 "23rd St between 18thAve and 20th Ave"
  with
    description "
    South to 20th Ave and 23rd St.^
    ",
    s_to City_20_23,
;

City_Class City_20_25 "20th Ave and 25th St"
  with
    description "
    North to 25th St between 18thAve and 20th Ave.^
    South to 25th St between 20thAve and 22nd Ave.^
    West to 20th Ave between 23rd St and 25th St.^
    East to 20th Ave between 25th St and 27th St.^

    ",
    n_to City_18_20_25,
    s_to City_20_22_25,
    w_to City_20_23_25,
    e_to City_20_25_27,
;

City_Class City_20_23_25 "20th Ave between 23rd St and 25th St"
  with
    description "
    West to 20th Ave and 23rd St.^
    East to 20th Ave and 25th St.^
    ",
    w_to City_20_23,
    e_to City_20_25,
;

City_Class City_18_20_25 "25th St between 18thAve and 20th Ave"
  with
    description "
    South to 20th Ave and 25th St.^
    ",
    s_to City_20_25,

;

City_Class City_20_27 "20th Ave and 27th St"
  with
    description "
    North to 27th St between 18thAve and 20th Ave.^
    South to 27th St between 20thAve and 22nd Ave.^
    West to 20th Ave between 25th St and 27th St.^
    East to 20th Ave between 27th St and 29th St.^
    ",
    n_to City_18_20_27,
    s_to City_20_22_27,
    w_to City_20_25_27,
    e_to City_20_27_29,
;

City_Class City_20_25_27 "20th Ave between 25th St and 27th St"
  with
    description "
    West to 20th Ave and 25th St.^
    East to 20th Ave and 27th St.^
    ",
    w_to City_20_25,

    e_to City_20_27,
;

City_Class City_18_20_27 "27th St between 18thAve and 20th Ave"
  with
    description "
    South to 20th Ave and 27th St.^
    ",
    s_to City_20_27,
;

City_Class City_20_29 "20th Ave and 29th St"
  with
    description "
    North to 29th St between 18thAve and 20th Ave.^
    South to 29th St between 20thAve and 22nd Ave.^
    West to 20th Ave between 27th St and 29th St.^
    East to 20th Ave between 29th St and 31st St.^
    ",
    n_to City_18_20_29,
    s_to City_20_22_29,
    w_to City_20_27_29,
    e_to City_20_29_31,

;

City_Class City_20_27_29 "20th Ave between 27th St and 29th St"
  with
    description "
    West to 20th Ave and 27th St.^
    East to 20th Ave and 29th St.^
    ",
    w_to City_20_27,
    e_to City_20_29,
;

City_Class City_18_20_29 "29th St between 18thAve and 20th Ave"
  with
    description "
    South to 20th Ave and 29th St.^
    ",
    s_to City_20_29,
;

City_Class City_20_31 "20th Ave and 31st St"
  with
    description "

    North to 31st St between 18thAve and 20th Ave.^
    South to 31st St between 20thAve and 22nd Ave.^
    West to 20th Ave between 29th St and 31st St.^
    East to 20th Ave between 31st St and 33rd St.^
    ",
    n_to City_18_20_31,
    s_to City_20_22_31,
    w_to City_20_29_31,
    e_to City_20_31_33,
;

City_Class City_20_29_31 "20th Ave between 29th St and 31st St"
  with
    description "
    West to 20th Ave and 29th St.^
    East to 20th Ave and 31st St.^
    ",
    w_to City_20_29,
    e_to City_20_31,
;

City_Class City_18_20_31 "31st St between 18thAve and 20th Ave"
  with

    description "
    South to 20th Ave and 31st St.^
    ",
    s_to City_20_31,
;

City_Class City_20_33 "20th Ave and 33rd St"
  with
    description "
    North to 33rd St between 18thAve and 20th Ave.^
    South to 33rd St between 20thAve and 22nd Ave.^
    West to 20th Ave between 31st St and 33rd St.^
    East to 20th Ave between 33rd St and 35th St.^
    ",
    n_to City_18_20_33,
    s_to City_20_22_33,
    w_to City_20_31_33,
    e_to City_20_33_35,
;

City_Class City_20_31_33 "20th Ave between 31st St and 33rd St"
  with
    description "

    West to 20th Ave and 31st St.^
    East to 20th Ave and 33rd St.^
    ",
    w_to City_20_31,
    e_to City_20_33,
;

City_Class City_18_20_33 "33rd St between 18thAve and 20th Ave"
  with
    description "
    South to 20th Ave and 33rd St.^
    ",
    s_to City_20_33,
;

City_Class City_20_35 "20th Ave and 35th St"
  with
    description "
    North to 35th St between 18thAve and 20th Ave.^
    South to 35th St between 20thAve and 22nd Ave.^
    West to 20th Ave between 33rd St and 35th St.^
    East to 20th Ave between 35th St and 37th St.^
    ",

    n_to City_18_20_35,
    s_to City_20_22_35,
    w_to City_20_33_35,
    e_to City_20_35_37,
;

City_Class City_20_33_35 "20th Ave between 33rd St and 35th St"
  with
    description "
    West to 20th Ave and 33rd St.^
    East to 20th Ave and 35th St.^
    ",
    w_to City_20_33,
    e_to City_20_35,
;

City_Class City_18_20_35 "35th St between 18thAve and 20th Ave"
  with
    description "
    South to 20th Ave and 35th St.^
    ",
    s_to City_20_35,
;

City_Class City_20_37 "20th Ave and 37th St"
  with
    description "
    North to 37th St between 18thAve and 20th Ave.^
    South to 37th St between 20thAve and 22nd Ave.^
    West to 20th Ave between 35th St and 37th St.^
    East to 20th Ave between 37th St and 39th St.^
    ",
    n_to City_18_20_37,
    s_to City_20_22_37,
    w_to City_20_35_37,
    e_to City_20_37_39,
;

City_Class City_20_35_37 "20th Ave between 35th St and 37th St"
  with
    description "
    West to 20th Ave and 35th St.^
    East to 20th Ave and 37th St.^
    ",
    w_to City_20_35,
    e_to City_20_37,

;

City_Class City_18_20_37 "37th St between 18thAve and 20th Ave"
  with
    description "
    South to 20th Ave and 37th St.^
    ",
    s_to City_20_37,
;

City_Class City_20_37_39 "20th Ave between 37th St and 39th St"
  with
    description "
    West to 20th Ave and 37th St.^
    ",
    w_to City_20_37,
;

City_Class City_22_21 "22nd Ave and 21st St"
  with
    description "
    North to 21st St between 20thAve and 22nd Ave.^
    South to 21st St between 22ndAve and 24th Ave.^

    West to 22nd Ave between 19th St and 21st St.^
    East to 22nd Ave between 21st St and 23rd St.^
    ",
    n_to City_20_22_21,
    s_to City_22_24_21,
    w_to City_22_19_21,
    e_to City_22_21_23,
;

City_Class City_22_19_21 "22nd Ave between 19th St and 21st St"
  with
    description "
    East to 22nd Ave and 21st St.^
    ",
    e_to City_22_21,
;

City_Class City_20_22_21 "21st St between 20thAve and 22nd Ave"
  with
    description "
    North to 20th Ave and 21st St.^
    South to 22nd Ave and 21st St.^
    ",

    n_to City_20_21,
    s_to City_22_21,
;

City_Class City_22_23 "22nd Ave and 23rd St"
  with
    description "
    North to 23rd St between 20thAve and 22nd Ave.^
    South to 23rd St between 22ndAve and 24th Ave.^
    West to 22nd Ave between 21st St and 23rd St.^
    East to 22nd Ave between 23rd St and 25th St.^
    ",
    n_to City_20_22_23,
    s_to City_22_24_23,
    w_to City_22_21_23,
    e_to City_22_23_25,
;

City_Class City_22_21_23 "22nd Ave between 21st St and 23rd St"
  with
    description "
    West to 22nd Ave and 21st St.^
    East to 22nd Ave and 23rd St.^

    ",
    w_to City_22_21,
    e_to City_22_23,
;

City_Class City_20_22_23 "23rd St between 20thAve and 22nd Ave"
  with
    description "
    North to 20th Ave and 23rd St.^
    South to 22nd Ave and 23rd St.^
    ",
    n_to City_20_23,
    s_to City_22_23,
;

City_Class City_22_25 "22nd Ave and 25th St"
  with
    description "
    North to 25th St between 20thAve and 22nd Ave.^
    South to 25th St between 22ndAve and 24th Ave.^
    West to 22nd Ave between 23rd St and 25th St.^
    East to 22nd Ave between 25th St and 27th St.^
    ",

    n_to City_20_22_25,
    s_to City_22_24_25,
    w_to City_22_23_25,
    e_to City_22_25_27,
;

City_Class City_22_23_25 "22nd Ave between 23rd St and 25th St"
  with
    description "
    West to 22nd Ave and 23rd St.^
    East to 22nd Ave and 25th St.^
    ",
    w_to City_22_23,
    e_to City_22_25,
;

City_Class City_20_22_25 "25th St between 20thAve and 22nd Ave"
  with
    description "
    North to 20th Ave and 25th St.^
    South to 22nd Ave and 25th St.^
    ",
    n_to City_20_25,

    s_to City_22_25,
;

City_Class City_22_27 "22nd Ave and 27th St"
  with
    description "
    North to 27th St between 20thAve and 22nd Ave.^
    South to 27th St between 22ndAve and 24th Ave.^
    West to 22nd Ave between 25th St and 27th St.^
    East to 22nd Ave between 27th St and 29th St.^
    ",
    n_to City_20_22_27,
    s_to City_22_24_27,
    w_to City_22_25_27,
    e_to City_22_27_29,
;

City_Class City_22_25_27 "22nd Ave between 25th St and 27th St"
  with
    description "
    West to 22nd Ave and 25th St.^
    East to 22nd Ave and 27th St.^
    ",

    w_to City_22_25,
    e_to City_22_27,
;

City_Class City_20_22_27 "27th St between 20thAve and 22nd Ave"
  with
    description "
    North to 20th Ave and 27th St.^
    South to 22nd Ave and 27th St.^
    ",
    n_to City_20_27,
    s_to City_22_27,
;

City_Class City_22_29 "22nd Ave and 29th St"
  with
    description "
    North to 29th St between 20thAve and 22nd Ave.^
    South to 29th St between 22ndAve and 24th Ave.^
    West to 22nd Ave between 27th St and 29th St.^
    East to 22nd Ave between 29th St and 31st St.^
    ",
    n_to City_20_22_29,

    s_to City_22_24_29,
    w_to City_22_27_29,
    e_to City_22_29_31,
;

City_Class City_22_27_29 "22nd Ave between 27th St and 29th St"
  with
    description "
    West to 22nd Ave and 27th St.^
    East to 22nd Ave and 29th St.^
    ",
    w_to City_22_27,
    e_to City_22_29,
;

City_Class City_20_22_29 "29th St between 20thAve and 22nd Ave"
  with
    description "
    North to 20th Ave and 29th St.^
    South to 22nd Ave and 29th St.^
    ",
    n_to City_20_29,
    s_to City_22_29,

;

City_Class City_22_31 "22nd Ave and 31st St"
  with
    description "
    North to 31st St between 20thAve and 22nd Ave.^
    South to 31st St between 22ndAve and 24th Ave.^
    West to 22nd Ave between 29th St and 31st St.^
    East to 22nd Ave between 31st St and 33rd St.^
    ",
    n_to City_20_22_31,
    s_to City_22_24_31,
    w_to City_22_29_31,
    e_to City_22_31_33,
;

City_Class City_22_29_31 "22nd Ave between 29th St and 31st St"
  with
    description "
    West to 22nd Ave and 29th St.^
    East to 22nd Ave and 31st St.^
    ",
    w_to City_22_29,

    e_to City_22_31,
;

City_Class City_20_22_31 "31st St between 20thAve and 22nd Ave"
  with
    description "
    North to 20th Ave and 31st St.^
    South to 22nd Ave and 31st St.^
    ",
    n_to City_20_31,
    s_to City_22_31,
;

City_Class City_22_33 "22nd Ave and 33rd St"
  with
    description "
    North to 33rd St between 20thAve and 22nd Ave.^
    South to 33rd St between 22ndAve and 24th Ave.^
    West to 22nd Ave between 31st St and 33rd St.^
    East to 22nd Ave between 33rd St and 35th St.^
    ",
    n_to City_20_22_33,
    s_to City_22_24_33,

    w_to City_22_31_33,
    e_to City_22_33_35,
;

City_Class City_22_31_33 "22nd Ave between 31st St and 33rd St"
  with
    description "
    West to 22nd Ave and 31st St.^
    East to 22nd Ave and 33rd St.^
    ",
    w_to City_22_31,
    e_to City_22_33,
;

City_Class City_20_22_33 "33rd St between 20thAve and 22nd Ave"
  with
    description "
    North to 20th Ave and 33rd St.^
    South to 22nd Ave and 33rd St.^
    ",
    n_to City_20_33,
    s_to City_22_33,
;

City_Class City_22_35 "22nd Ave and 35th St"
  with
    description "
    North to 35th St between 20thAve and 22nd Ave.^
    South to 35th St between 22ndAve and 24th Ave.^
    West to 22nd Ave between 33rd St and 35th St.^
    East to 22nd Ave between 35th St and 37th St.^
    ",
    n_to City_20_22_35,
    s_to City_22_24_35,
    w_to City_22_33_35,
    e_to City_22_35_37,
;

City_Class City_22_33_35 "22nd Ave between 33rd St and 35th St"
  with
    description "
    West to 22nd Ave and 33rd St.^
    East to 22nd Ave and 35th St.^
    ",
    w_to City_22_33,
    e_to City_22_35,

;

City_Class City_20_22_35 "35th St between 20thAve and 22nd Ave"
  with
    description "
    North to 20th Ave and 35th St.^
    South to 22nd Ave and 35th St.^
    ",
    n_to City_20_35,
    s_to City_22_35,
;

City_Class City_22_37 "22nd Ave and 37th St"
  with
    description "
    North to 37th St between 20thAve and 22nd Ave.^
    South to 37th St between 22ndAve and 24th Ave.^
    West to 22nd Ave between 35th St and 37th St.^
    East to 22nd Ave between 37th St and 39th St.^
    ",
    n_to City_20_22_37,
    s_to City_22_24_37,
    w_to City_22_35_37,

    e_to City_22_37_39,
;

City_Class City_22_35_37 "22nd Ave between 35th St and 37th St"
  with
    description "
    West to 22nd Ave and 35th St.^
    East to 22nd Ave and 37th St.^
    ",
    w_to City_22_35,
    e_to City_22_37,
;

City_Class City_20_22_37 "37th St between 20thAve and 22nd Ave"
  with
    description "
    North to 20th Ave and 37th St.^
    South to 22nd Ave and 37th St.^
    ",
    n_to City_20_37,
    s_to City_22_37,
;

City_Class City_22_37_39 "22nd Ave between 37th St and 39th St"
  with
    description "
    West to 22nd Ave and 37th St.^
    ",
    w_to City_22_37,
;

City_Class City_24_21 "24th Ave and 21st St"
  with
    description "
    North to 21st St between 22ndAve and 24th Ave.^
    South to 21st St between 24thAve and 26th Ave.^
    West to 24th Ave between 19th St and 21st St.^
    East to 24th Ave between 21st St and 23rd St.^
    ",
    n_to City_22_24_21,
    s_to City_24_26_21,
    w_to City_24_19_21,
    e_to City_24_21_23,
;

City_Class City_24_19_21 "24th Ave between 19th St and 21st St"

  with
    description "
    East to 24th Ave and 21st St.^
    ",
    e_to City_24_21,
;

City_Class City_22_24_21 "21st St between 22ndAve and 24th Ave"
  with
    description "
    North to 22nd Ave and 21st St.^
    South to 24th Ave and 21st St.^
    ",
    n_to City_22_21,
    s_to City_24_21,
;

City_Class City_24_23 "24th Ave and 23rd St"
  with
    description "
    North to 23rd St between 22ndAve and 24th Ave.^
    South to 23rd St between 24thAve and 26th Ave.^
    West to 24th Ave between 21st St and 23rd St.^

    East to 24th Ave between 23rd St and 25th St.^
    ",
    n_to City_22_24_23,
    s_to City_24_26_23,
    w_to City_24_21_23,
    e_to City_24_23_25,
;

City_Class City_24_21_23 "24th Ave between 21st St and 23rd St"
  with
    description "
    West to 24th Ave and 21st St.^
    East to 24th Ave and 23rd St.^
    ",
    w_to City_24_21,
    e_to City_24_23,
;

City_Class City_22_24_23 "23rd St between 22ndAve and 24th Ave"
  with
    description "
    North to 22nd Ave and 23rd St.^
    South to 24th Ave and 23rd St.^

    ",
    n_to City_22_23,
    s_to City_24_23,
;

City_Class City_24_25 "24th Ave and 25th St"
  with
    description "
    North to 25th St between 22ndAve and 24th Ave.^
    South to 25th St between 24thAve and 26th Ave.^
    West to 24th Ave between 23rd St and 25th St.^
    East to 24th Ave between 25th St and 27th St.^
    ",
    n_to City_22_24_25,
    s_to City_24_26_25,
    w_to City_24_23_25,
    e_to City_24_25_27,
;

City_Class City_24_23_25 "24th Ave between 23rd St and 25th St"
  with
    description "
    West to 24th Ave and 23rd St.^

    East to 24th Ave and 25th St.^
    ",
    w_to City_24_23,
    e_to City_24_25,
;

City_Class City_22_24_25 "25th St between 22ndAve and 24th Ave"
  with
    description "
    North to 22nd Ave and 25th St.^
    South to 24th Ave and 25th St.^
    ",
    n_to City_22_25,
    s_to City_24_25,
;

City_Class City_24_27 "24th Ave and 27th St"
  with
    description "
    North to 27th St between 22ndAve and 24th Ave.^
    South to 27th St between 24thAve and 26th Ave.^
    West to 24th Ave between 25th St and 27th St.^
    East to 24th Ave between 27th St and 29th St.^

    ",
    n_to City_22_24_27,
    s_to City_24_26_27,
    w_to City_24_25_27,
    e_to City_24_27_29,
;

City_Class City_24_25_27 "24th Ave between 25th St and 27th St"
  with
    description "
    West to 24th Ave and 25th St.^
    East to 24th Ave and 27th St.^
    ",
    w_to City_24_25,
    e_to City_24_27,
;

City_Class City_22_24_27 "27th St between 22ndAve and 24th Ave"
  with
    description "
    North to 22nd Ave and 27th St.^
    South to 24th Ave and 27th St.^
    ",

    n_to City_22_27,
    s_to City_24_27,
;

City_Class City_24_29 "24th Ave and 29th St"
  with
    description "
    North to 29th St between 22ndAve and 24th Ave.^
    South to 29th St between 24thAve and 26th Ave.^
    West to 24th Ave between 27th St and 29th St.^
    East to 24th Ave between 29th St and 31st St.^
    ",
    n_to City_22_24_29,
    s_to City_24_26_29,
    w_to City_24_27_29,
    e_to City_24_29_31,
;

City_Class City_24_27_29 "24th Ave between 27th St and 29th St"
  with
    description "
    West to 24th Ave and 27th St.^
    East to 24th Ave and 29th St.^

    ",
    w_to City_24_27,
    e_to City_24_29,
;

City_Class City_22_24_29 "29th St between 22ndAve and 24th Ave"
  with
    description "
    North to 22nd Ave and 29th St.^
    South to 24th Ave and 29th St.^
    ",
    n_to City_22_29,
    s_to City_24_29,
;

City_Class City_24_31 "24th Ave and 31st St"
  with
    description "
    North to 31st St between 22ndAve and 24th Ave.^
    South to 31st St between 24thAve and 26th Ave.^
    West to 24th Ave between 29th St and 31st St.^
    East to 24th Ave between 31st St and 33rd St.^
    ",

    n_to City_22_24_31,
    s_to City_24_26_31,
    w_to City_24_29_31,
    e_to City_24_31_33,
;

City_Class City_24_29_31 "24th Ave between 29th St and 31st St"
  with
    description "
    West to 24th Ave and 29th St.^
    East to 24th Ave and 31st St.^
    ",
    w_to City_24_29,
    e_to City_24_31,
;

City_Class City_22_24_31 "31st St between 22ndAve and 24th Ave"
  with
    description "
    North to 22nd Ave and 31st St.^
    South to 24th Ave and 31st St.^
    ",
    n_to City_22_31,

    s_to City_24_31,
;

City_Class City_24_33 "24th Ave and 33rd St"
  with
    description "
    North to 33rd St between 22ndAve and 24th Ave.^
    South to 33rd St between 24thAve and 26th Ave.^
    West to 24th Ave between 31st St and 33rd St.^
    East to 24th Ave between 33rd St and 35th St.^
    ",
    n_to City_22_24_33,
    s_to City_24_26_33,
    w_to City_24_31_33,
    e_to City_24_33_35,
;

City_Class City_24_31_33 "24th Ave between 31st St and 33rd St"
  with
    description "
    West to 24th Ave and 31st St.^
    East to 24th Ave and 33rd St.^
    ",

    w_to City_24_31,
    e_to City_24_33,
;

City_Class City_22_24_33 "33rd St between 22ndAve and 24th Ave"
  with
    description "
    North to 22nd Ave and 33rd St.^
    South to 24th Ave and 33rd St.^
    ",
    n_to City_22_33,
    s_to City_24_33,
;

City_Class City_24_35 "24th Ave and 35th St"
  with
    description "
    North to 35th St between 22ndAve and 24th Ave.^
    South to 35th St between 24thAve and 26th Ave.^
    West to 24th Ave between 33rd St and 35th St.^
    East to 24th Ave between 35th St and 37th St.^
    ",
    n_to City_22_24_35,

    s_to City_24_26_35,
    w_to City_24_33_35,
    e_to City_24_35_37,
;

City_Class City_24_33_35 "24th Ave between 33rd St and 35th St"
  with
    description "
    West to 24th Ave and 33rd St.^
    East to 24th Ave and 35th St.^
    ",
    w_to City_24_33,
    e_to City_24_35,
;

City_Class City_22_24_35 "35th St between 22ndAve and 24th Ave"
  with
    description "
    North to 22nd Ave and 35th St.^
    South to 24th Ave and 35th St.^
    ",
    n_to City_22_35,
    s_to City_24_35,

;

City_Class City_24_37 "24th Ave and 37th St"
  with
    description "
    North to 37th St between 22ndAve and 24th Ave.^
    South to 37th St between 24thAve and 26th Ave.^
    West to 24th Ave between 35th St and 37th St.^
    East to 24th Ave between 37th St and 39th St.^
    ",
    n_to City_22_24_37,
    s_to City_24_26_37,
    w_to City_24_35_37,
    e_to City_24_37_39,
;

City_Class City_24_35_37 "24th Ave between 35th St and 37th St"
  with
    description "
    West to 24th Ave and 35th St.^
    East to 24th Ave and 37th St.^
    ",
    w_to City_24_35,

    e_to City_24_37,
;

City_Class City_22_24_37 "37th St between 22ndAve and 24th Ave"
  with
    description "
    North to 22nd Ave and 37th St.^
    South to 24th Ave and 37th St.^
    ",
    n_to City_22_37,
    s_to City_24_37,
;

City_Class City_24_37_39 "24th Ave between 37th St and 39th St"
  with
    description "
    West to 24th Ave and 37th St.^
    ",
    w_to City_24_37,
;

City_Class City_26_21 "26th Ave and 21st St"
  with

    description "
    North to 21st St between 24thAve and 26th Ave.^
    South to 21st St between 26thAve and 28th Ave.^
    West to 26th Ave between 19th St and 21st St.^
    East to 26th Ave between 21st St and 23rd St.^
    ",
    n_to City_24_26_21,
    s_to City_26_28_21,
    w_to City_26_19_21,
    e_to City_26_21_23,
;

City_Class City_26_19_21 "26th Ave between 19th St and 21st St"
  with
    description "
    East to 26th Ave and 21st St.^
    ",
    e_to City_26_21,
;

City_Class City_24_26_21 "21st St between 24thAve and 26th Ave"
  with
    description "

    North to 24th Ave and 21st St.^
    South to 26th Ave and 21st St.^
    ",
    n_to City_24_21,
    s_to City_26_21,
;

City_Class City_26_23 "26th Ave and 23rd St"
  with
    description "
    North to 23rd St between 24thAve and 26th Ave.^
    South to 23rd St between 26thAve and 28th Ave.^
    West to 26th Ave between 21st St and 23rd St.^
    East to 26th Ave between 23rd St and 25th St.^
    ",
    n_to City_24_26_23,
    s_to City_26_28_23,
    w_to City_26_21_23,
    e_to City_26_23_25,
;

City_Class City_26_21_23 "26th Ave between 21st St and 23rd St"
  with

    description "
    West to 26th Ave and 21st St.^
    East to 26th Ave and 23rd St.^
    ",
    w_to City_26_21,
    e_to City_26_23,
;

City_Class City_24_26_23 "23rd St between 24thAve and 26th Ave"
  with
    description "
    North to 24th Ave and 23rd St.^
    South to 26th Ave and 23rd St.^
    ",
    n_to City_24_23,
    s_to City_26_23,
;

City_Class City_26_25 "26th Ave and 25th St"
  with
    description "
    North to 25th St between 24thAve and 26th Ave.^
    South to 25th St between 26thAve and 28th Ave.^

    West to 26th Ave between 23rd St and 25th St.^
    East to 26th Ave between 25th St and 27th St.^
    ",
    n_to City_24_26_25,
    s_to City_26_28_25,
    w_to City_26_23_25,
    e_to City_26_25_27,
;

City_Class City_26_23_25 "26th Ave between 23rd St and 25th St"
  with
    description "
    West to 26th Ave and 23rd St.^
    East to 26th Ave and 25th St.^
    ",
    w_to City_26_23,
    e_to City_26_25,
;

City_Class City_24_26_25 "25th St between 24thAve and 26th Ave"
  with
    description "
    North to 24th Ave and 25th St.^

    South to 26th Ave and 25th St.^
    ",
    n_to City_24_25,
    s_to City_26_25,
;

City_Class City_26_27 "26th Ave and 27th St"
  with
    description "
    North to 27th St between 24thAve and 26th Ave.^
    South to 27th St between 26thAve and 28th Ave.^
    West to 26th Ave between 25th St and 27th St.^
    East to 26th Ave between 27th St and 29th St.^
    ",
    n_to City_24_26_27,
    s_to City_26_28_27,
    w_to City_26_25_27,
    e_to City_26_27_29,
;

City_Class City_26_25_27 "26th Ave between 25th St and 27th St"
  with
    description "

    West to 26th Ave and 25th St.^
    East to 26th Ave and 27th St.^
    ",
    w_to City_26_25,
    e_to City_26_27,
;

City_Class City_24_26_27 "27th St between 24thAve and 26th Ave"
  with
    description "
    North to 24th Ave and 27th St.^
    South to 26th Ave and 27th St.^
    ",
    n_to City_24_27,
    s_to City_26_27,
;

City_Class City_26_29 "26th Ave and 29th St"
  with
    description "
    North to 29th St between 24thAve and 26th Ave.^
    South to 29th St between 26thAve and 28th Ave.^
    West to 26th Ave between 27th St and 29th St.^

    East to 26th Ave between 29th St and 31st St.^
    ",
    n_to City_24_26_29,
    s_to City_26_28_29,
    w_to City_26_27_29,
    e_to City_26_29_31,
;

City_Class City_26_27_29 "26th Ave between 27th St and 29th St"
  with
    description "
    West to 26th Ave and 27th St.^
    East to 26th Ave and 29th St.^
    ",
    w_to City_26_27,
    e_to City_26_29,
;

City_Class City_24_26_29 "29th St between 24thAve and 26th Ave"
  with
    description "
    North to 24th Ave and 29th St.^
    South to 26th Ave and 29th St.^

    ",
    n_to City_24_29,
    s_to City_26_29,
;

City_Class City_26_31 "26th Ave and 31st St"
  with
    description "
    North to 31st St between 24thAve and 26th Ave.^
    South to 31st St between 26thAve and 28th Ave.^
    West to 26th Ave between 29th St and 31st St.^
    East to 26th Ave between 31st St and 33rd St.^
    ",
    n_to City_24_26_31,
    s_to City_26_28_31,
    w_to City_26_29_31,
    e_to City_26_31_33,
;

City_Class City_26_29_31 "26th Ave between 29th St and 31st St"
  with
    description "
    West to 26th Ave and 29th St.^

    East to 26th Ave and 31st St.^
    ",
    w_to City_26_29,
    e_to City_26_31,
;

City_Class City_24_26_31 "31st St between 24thAve and 26th Ave"
  with
    description "
    North to 24th Ave and 31st St.^
    South to 26th Ave and 31st St.^
    ",
    n_to City_24_31,
    s_to City_26_31,
;

City_Class City_26_33 "26th Ave and 33rd St"
  with
    description "
    North to 33rd St between 24thAve and 26th Ave.^
    South to 33rd St between 26thAve and 28th Ave.^
    West to 26th Ave between 31st St and 33rd St.^
    East to 26th Ave between 33rd St and 35th St.^

    ",
    n_to City_24_26_33,
    s_to City_26_28_33,
    w_to City_26_31_33,
    e_to City_26_33_35,
;

City_Class City_26_31_33 "26th Ave between 31st St and 33rd St"
  with
    description "
    West to 26th Ave and 31st St.^
    East to 26th Ave and 33rd St.^
    ",
    w_to City_26_31,
    e_to City_26_33,
;

City_Class City_24_26_33 "33rd St between 24thAve and 26th Ave"
  with
    description "
    North to 24th Ave and 33rd St.^
    South to 26th Ave and 33rd St.^
    ",

    n_to City_24_33,
    s_to City_26_33,
;

City_Class City_26_35 "26th Ave and 35th St"
  with
    description "
    North to 35th St between 24thAve and 26th Ave.^
    South to 35th St between 26thAve and 28th Ave.^
    West to 26th Ave between 33rd St and 35th St.^
    East to 26th Ave between 35th St and 37th St.^
    ",
    n_to City_24_26_35,
    s_to City_26_28_35,
    w_to City_26_33_35,
    e_to City_26_35_37,
;

City_Class City_26_33_35 "26th Ave between 33rd St and 35th St"
  with
    description "
    West to 26th Ave and 33rd St.^
    East to 26th Ave and 35th St.^

    ",
    w_to City_26_33,
    e_to City_26_35,
;

City_Class City_24_26_35 "35th St between 24thAve and 26th Ave"
  with
    description "
    North to 24th Ave and 35th St.^
    South to 26th Ave and 35th St.^
    ",
    n_to City_24_35,
    s_to City_26_35,
;

City_Class City_26_37 "26th Ave and 37th St"
  with
    description "
    North to 37th St between 24thAve and 26th Ave.^
    South to 37th St between 26thAve and 28th Ave.^
    West to 26th Ave between 35th St and 37th St.^
    East to 26th Ave between 37th St and 39th St.^
    ",

    n_to City_24_26_37,
    s_to City_26_28_37,
    w_to City_26_35_37,
    e_to City_26_37_39,
;

City_Class City_26_35_37 "26th Ave between 35th St and 37th St"
  with
    description "
    West to 26th Ave and 35th St.^
    East to 26th Ave and 37th St.^
    ",
    w_to City_26_35,
    e_to City_26_37,
;

City_Class City_24_26_37 "37th St between 24thAve and 26th Ave"
  with
    description "
    North to 24th Ave and 37th St.^
    South to 26th Ave and 37th St.^
    ",
    n_to City_24_37,

    s_to City_26_37,
;

City_Class City_26_37_39 "26th Ave between 37th St and 39th St"
  with
    description "
    West to 26th Ave and 37th St.^
    ",
    w_to City_26_37,
;

City_Class City_28_21 "28th Ave and 21st St"
  with
    description "
    North to 21st St between 26thAve and 28th Ave.^
    South to 21st St between 28thAve and 30th Ave.^
    West to 28th Ave between 19th St and 21st St.^
    East to 28th Ave between 21st St and 23rd St.^
    ",
    n_to City_26_28_21,
    s_to City_28_30_21,
    w_to City_28_19_21,
    e_to City_28_21_23,

;

City_Class City_28_19_21 "28th Ave between 19th St and 21st St"
  with
    description "
    East to 28th Ave and 21st St.^
    ",
    e_to City_28_21,
;

City_Class City_26_28_21 "21st St between 26thAve and 28th Ave"
  with
    description "
    North to 26th Ave and 21st St.^
    South to 28th Ave and 21st St.^
    ",
    n_to City_26_21,
    s_to City_28_21,
;

City_Class City_28_23 "28th Ave and 23rd St"
  with
    description "

    North to 23rd St between 26thAve and 28th Ave.^
    South to 23rd St between 28thAve and 30th Ave.^
    West to 28th Ave between 21st St and 23rd St.^
    East to 28th Ave between 23rd St and 25th St.^
    ",
    n_to City_26_28_23,
    s_to City_28_30_23,
    w_to City_28_21_23,
    e_to City_28_23_25,
;

City_Class City_28_21_23 "28th Ave between 21st St and 23rd St"
  with
    description "
    West to 28th Ave and 21st St.^
    East to 28th Ave and 23rd St.^
    ",
    w_to City_28_21,
    e_to City_28_23,
;

City_Class City_26_28_23 "23rd St between 26thAve and 28th Ave"
  with

    description "
    North to 26th Ave and 23rd St.^
    South to 28th Ave and 23rd St.^
    ",
    n_to City_26_23,
    s_to City_28_23,
;

City_Class City_28_25 "28th Ave and 25th St"
  with
    description "
    North to 25th St between 26thAve and 28th Ave.^
    South to 25th St between 28thAve and 30th Ave.^
    West to 28th Ave between 23rd St and 25th St.^
    East to 28th Ave between 25th St and 27th St.^
    ",
    n_to City_26_28_25,
    s_to City_28_30_25,
    w_to City_28_23_25,
    e_to City_28_25_27,
;

City_Class City_28_23_25 "28th Ave between 23rd St and 25th St"

  with
    description "
    West to 28th Ave and 23rd St.^
    East to 28th Ave and 25th St.^
    ",
    w_to City_28_23,
    e_to City_28_25,
;

City_Class City_26_28_25 "25th St between 26thAve and 28th Ave"
  with
    description "
    North to 26th Ave and 25th St.^
    South to 28th Ave and 25th St.^
    ",
    n_to City_26_25,
    s_to City_28_25,
;

City_Class City_28_27 "28th Ave and 27th St"
  with
    description "
    North to 27th St between 26thAve and 28th Ave.^

    South to 27th St between 28thAve and 30th Ave.^
    West to 28th Ave between 25th St and 27th St.^
    East to 28th Ave between 27th St and 29th St.^
    ",
    n_to City_26_28_27,
    s_to City_28_30_27,
    w_to City_28_25_27,
    e_to City_28_27_29,
;

City_Class City_28_25_27 "28th Ave between 25th St and 27th St"
  with
    description "
    West to 28th Ave and 25th St.^
    East to 28th Ave and 27th St.^
    ",
    w_to City_28_25,
    e_to City_28_27,
;

City_Class City_26_28_27 "27th St between 26thAve and 28th Ave"
  with
    description "

    North to 26th Ave and 27th St.^
    South to 28th Ave and 27th St.^
    ",
    n_to City_26_27,
    s_to City_28_27,
;

City_Class City_28_29 "28th Ave and 29th St"
  with
    description "
    North to 29th St between 26thAve and 28th Ave.^
    South to 29th St between 28thAve and 30th Ave.^
    West to 28th Ave between 27th St and 29th St.^
    East to 28th Ave between 29th St and 31st St.^
    ",
    n_to City_26_28_29,
    s_to City_28_30_29,
    w_to City_28_27_29,
    e_to City_28_29_31,
;

City_Class City_28_27_29 "28th Ave between 27th St and 29th St"
  with

    description "
    West to 28th Ave and 27th St.^
    East to 28th Ave and 29th St.^
    ",
    w_to City_28_27,
    e_to City_28_29,
;

City_Class City_26_28_29 "29th St between 26thAve and 28th Ave"
  with
    description "
    North to 26th Ave and 29th St.^
    South to 28th Ave and 29th St.^
    ",
    n_to City_26_29,
    s_to City_28_29,
;

City_Class City_28_31 "28th Ave and 31st St"
  with
    description "
    North to 31st St between 26thAve and 28th Ave.^
    South to 31st St between 28thAve and 30th Ave.^

    West to 28th Ave between 29th St and 31st St.^
    East to 28th Ave between 31st St and 33rd St.^
    ",
    n_to City_26_28_31,
    s_to City_28_30_31,
    w_to City_28_29_31,
    e_to City_28_31_33,
;

City_Class City_28_29_31 "28th Ave between 29th St and 31st St"
  with
    description "
    West to 28th Ave and 29th St.^
    East to 28th Ave and 31st St.^
    ",
    w_to City_28_29,
    e_to City_28_31,
;

City_Class City_26_28_31 "31st St between 26thAve and 28th Ave"
  with
    description "
    North to 26th Ave and 31st St.^

    South to 28th Ave and 31st St.^
    ",
    n_to City_26_31,
    s_to City_28_31,
;

City_Class City_28_33 "28th Ave and 33rd St"
  with
    description "
    North to 33rd St between 26thAve and 28th Ave.^
    South to 33rd St between 28thAve and 30th Ave.^
    West to 28th Ave between 31st St and 33rd St.^
    East to 28th Ave between 33rd St and 35th St.^
    ",
    n_to City_26_28_33,
    s_to City_28_30_33,
    w_to City_28_31_33,
    e_to City_28_33_35,
;

City_Class City_28_31_33 "28th Ave between 31st St and 33rd St"
  with
    description "

    West to 28th Ave and 31st St.^
    East to 28th Ave and 33rd St.^
    ",
    w_to City_28_31,
    e_to City_28_33,
;

City_Class City_26_28_33 "33rd St between 26thAve and 28th Ave"
  with
    description "
    North to 26th Ave and 33rd St.^
    South to 28th Ave and 33rd St.^
    ",
    n_to City_26_33,
    s_to City_28_33,
;

City_Class City_28_35 "28th Ave and 35th St"
  with
    description "
    North to 35th St between 26thAve and 28th Ave.^
    South to 35th St between 28thAve and 30th Ave.^
    West to 28th Ave between 33rd St and 35th St.^

    East to 28th Ave between 35th St and 37th St.^
    ",
    n_to City_26_28_35,
    s_to City_28_30_35,
    w_to City_28_33_35,
    e_to City_28_35_37,
;

City_Class City_28_33_35 "28th Ave between 33rd St and 35th St"
  with
    description "
    West to 28th Ave and 33rd St.^
    East to 28th Ave and 35th St.^
    ",
    w_to City_28_33,
    e_to City_28_35,
;

City_Class City_26_28_35 "35th St between 26thAve and 28th Ave"
  with
    description "
    North to 26th Ave and 35th St.^
    South to 28th Ave and 35th St.^

    ",
    n_to City_26_35,
    s_to City_28_35,
;

City_Class City_28_37 "28th Ave and 37th St"
  with
    description "
    North to 37th St between 26thAve and 28th Ave.^
    South to 37th St between 28thAve and 30th Ave.^
    West to 28th Ave between 35th St and 37th St.^
    East to 28th Ave between 37th St and 39th St.^
    ",
    n_to City_26_28_37,
    s_to City_28_30_37,
    w_to City_28_35_37,
    e_to City_28_37_39,
;

City_Class City_28_35_37 "28th Ave between 35th St and 37th St"
  with
    description "
    West to 28th Ave and 35th St.^

    East to 28th Ave and 37th St.^
    ",
    w_to City_28_35,
    e_to City_28_37,
;

City_Class City_26_28_37 "37th St between 26thAve and 28th Ave"
  with
    description "
    North to 26th Ave and 37th St.^
    South to 28th Ave and 37th St.^
    ",
    n_to City_26_37,
    s_to City_28_37,
;

City_Class City_28_37_39 "28th Ave between 37th St and 39th St"
  with
    description "
    West to 28th Ave and 37th St.^
    ",
    w_to City_28_37,
;

City_Class City_30_21 "30th Ave and 21st St"
  with
    description "
    North to 21st St between 28thAve and 30th Ave.^
    South to 21st St between 30thAve and 32nd Ave.^
    West to 30th Ave between 19th St and 21st St.^
    East to 30th Ave between 21st St and 23rd St.^
    ",
    n_to City_28_30_21,
    s_to City_30_32_21,
    w_to City_30_19_21,
    e_to City_30_21_23,
;

City_Class City_30_19_21 "30th Ave between 19th St and 21st St"
  with
    description "
    East to 30th Ave and 21st St.^
    ",
    e_to City_30_21,
;

City_Class City_28_30_21 "21st St between 28thAve and 30th Ave"
  with
    description "
    North to 28th Ave and 21st St.^
    South to 30th Ave and 21st St.^
    ",
    n_to City_28_21,
    s_to City_30_21,
;

City_Class City_30_23 "30th Ave and 23rd St"
  with
    description "
    North to 23rd St between 28thAve and 30th Ave.^
    South to 23rd St between 30thAve and 32nd Ave.^
    West to 30th Ave between 21st St and 23rd St.^
    East to 30th Ave between 23rd St and 25th St.^
    ",
    n_to City_28_30_23,
    s_to City_30_32_23,
    w_to City_30_21_23,
    e_to City_30_23_25,
;

City_Class City_30_21_23 "30th Ave between 21st St and 23rd St"
  with
    description "
    West to 30th Ave and 21st St.^
    East to 30th Ave and 23rd St.^
    ",
    w_to City_30_21,
    e_to City_30_23,
;

City_Class City_28_30_23 "23rd St between 28thAve and 30th Ave"
  with
    description "
    North to 28th Ave and 23rd St.^
    South to 30th Ave and 23rd St.^
    ",
    n_to City_28_23,
    s_to City_30_23,
;

City_Class City_30_25 "30th Ave and 25th St"
  with

    description "
    North to 25th St between 28thAve and 30th Ave.^
    South to 25th St between 30thAve and 32nd Ave.^
    West to 30th Ave between 23rd St and 25th St.^
    East to 30th Ave between 25th St and 27th St.^
    ",
    n_to City_28_30_25,
    s_to City_30_32_25,
    w_to City_30_23_25,
    e_to City_30_25_27,
;

City_Class City_30_23_25 "30th Ave between 23rd St and 25th St"
  with
    description "
    West to 30th Ave and 23rd St.^
    East to 30th Ave and 25th St.^
    ",
    w_to City_30_23,
    e_to City_30_25,
;

City_Class City_28_30_25 "25th St between 28thAve and 30th Ave"

  with
    description "
    North to 28th Ave and 25th St.^
    South to 30th Ave and 25th St.^
    ",
    n_to City_28_25,
    s_to City_30_25,
;

City_Class City_30_27 "30th Ave and 27th St"
  with
    description "
    North to 27th St between 28thAve and 30th Ave.^
    South to 27th St between 30thAve and 32nd Ave.^
    West to 30th Ave between 25th St and 27th St.^
    East to 30th Ave between 27th St and 29th St.^
    ",
    n_to City_28_30_27,
    s_to City_30_32_27,
    w_to City_30_25_27,
    e_to City_30_27_29,
;

City_Class City_30_25_27 "30th Ave between 25th St and 27th St"
  with
    description "
    West to 30th Ave and 25th St.^
    East to 30th Ave and 27th St.^
    ",
    w_to City_30_25,
    e_to City_30_27,
;

City_Class City_28_30_27 "27th St between 28thAve and 30th Ave"
  with
    description "
    North to 28th Ave and 27th St.^
    South to 30th Ave and 27th St.^
    ",
    n_to City_28_27,
    s_to City_30_27,
;

City_Class City_30_29 "30th Ave and 29th St"
  with
    description "

    North to 29th St between 28thAve and 30th Ave.^
    South to 29th St between 30thAve and 32nd Ave.^
    West to 30th Ave between 27th St and 29th St.^
    East to 30th Ave between 29th St and 31st St.^
    ",
    n_to City_28_30_29,
    s_to City_30_32_29,
    w_to City_30_27_29,
    e_to City_30_29_31,
;

City_Class City_30_27_29 "30th Ave between 27th St and 29th St"
  with
    description "
    West to 30th Ave and 27th St.^
    East to 30th Ave and 29th St.^
    ",
    w_to City_30_27,
    e_to City_30_29,
;

City_Class City_28_30_29 "29th St between 28thAve and 30th Ave"
  with

    description "
    North to 28th Ave and 29th St.^
    South to 30th Ave and 29th St.^
    ",
    n_to City_28_29,
    s_to City_30_29,
;

City_Class City_30_31 "30th Ave and 31st St"
  with
    description "
    North to 31st St between 28thAve and 30th Ave.^
    South to 31st St between 30thAve and 32nd Ave.^
    West to 30th Ave between 29th St and 31st St.^
    East to 30th Ave between 31st St and 33rd St.^
    ",
    n_to City_28_30_31,
    s_to City_30_32_31,
    w_to City_30_29_31,
    e_to City_30_31_33,
;

City_Class City_30_29_31 "30th Ave between 29th St and 31st St"

  with
    description "
    West to 30th Ave and 29th St.^
    East to 30th Ave and 31st St.^
    ",
    w_to City_30_29,
    e_to City_30_31,
;

City_Class City_28_30_31 "31st St between 28thAve and 30th Ave"
  with
    description "
    North to 28th Ave and 31st St.^
    South to 30th Ave and 31st St.^
    ",
    n_to City_28_31,
    s_to City_30_31,
;

City_Class City_30_33 "30th Ave and 33rd St"
  with
    description "
    North to 33rd St between 28thAve and 30th Ave.^

    South to 33rd St between 30thAve and 32nd Ave.^
    West to 30th Ave between 31st St and 33rd St.^
    East to 30th Ave between 33rd St and 35th St.^
    ",
    n_to City_28_30_33,
    s_to City_30_32_33,
    w_to City_30_31_33,
    e_to City_30_33_35,
;

City_Class City_30_31_33 "30th Ave between 31st St and 33rd St"
  with
    description "
    West to 30th Ave and 31st St.^
    East to 30th Ave and 33rd St.^
    ",
    w_to City_30_31,
    e_to City_30_33,
;

City_Class City_28_30_33 "33rd St between 28thAve and 30th Ave"
  with
    description "

    North to 28th Ave and 33rd St.^
    South to 30th Ave and 33rd St.^
    ",
    n_to City_28_33,
    s_to City_30_33,
;

City_Class City_30_35 "30th Ave and 35th St"
  with
    description "
    North to 35th St between 28thAve and 30th Ave.^
    South to 35th St between 30thAve and 32nd Ave.^
    West to 30th Ave between 33rd St and 35th St.^
    East to 30th Ave between 35th St and 37th St.^
    ",
    n_to City_28_30_35,
    s_to City_30_32_35,
    w_to City_30_33_35,
    e_to City_30_35_37,
;

City_Class City_30_33_35 "30th Ave between 33rd St and 35th St"
  with

    description "
    West to 30th Ave and 33rd St.^
    East to 30th Ave and 35th St.^
    ",
    w_to City_30_33,
    e_to City_30_35,
;

City_Class City_28_30_35 "35th St between 28thAve and 30th Ave"
  with
    description "
    North to 28th Ave and 35th St.^
    South to 30th Ave and 35th St.^
    ",
    n_to City_28_35,
    s_to City_30_35,
;

City_Class City_30_37 "30th Ave and 37th St"
  with
    description "
    North to 37th St between 28thAve and 30th Ave.^
    South to 37th St between 30thAve and 32nd Ave.^

    West to 30th Ave between 35th St and 37th St.^
    East to 30th Ave between 37th St and 39th St.^
    ",
    n_to City_28_30_37,
    s_to City_30_32_37,
    w_to City_30_35_37,
    e_to City_30_37_39,
;

City_Class City_30_35_37 "30th Ave between 35th St and 37th St"
  with
    description "
    West to 30th Ave and 35th St.^
    East to 30th Ave and 37th St.^
    ",
    w_to City_30_35,
    e_to City_30_37,
;

City_Class City_28_30_37 "37th St between 28thAve and 30th Ave"
  with
    description "
    North to 28th Ave and 37th St.^

    South to 30th Ave and 37th St.^
    ",
    n_to City_28_37,
    s_to City_30_37,
;

City_Class City_30_37_39 "30th Ave between 37th St and 39th St"
  with
    description "
    West to 30th Ave and 37th St.^
    ",
    w_to City_30_37,
;

City_Class City_32_21 "32nd Ave and 21st St"
  with
    description "
    North to 21st St between 30thAve and 32nd Ave.^
    South to 21st St between 32ndAve and 34th Ave.^
    West to 32nd Ave between 19th St and 21st St.^
    East to 32nd Ave between 21st St and 23rd St.^
    ",
    n_to City_30_32_21,

    s_to City_32_34_21,
    w_to City_32_19_21,
    e_to City_32_21_23,
;

City_Class City_32_19_21 "32nd Ave between 19th St and 21st St"
  with
    description "
    East to 32nd Ave and 21st St.^
    ",
    e_to City_32_21,
;

City_Class City_30_32_21 "21st St between 30thAve and 32nd Ave"
  with
    description "
    North to 30th Ave and 21st St.^
    South to 32nd Ave and 21st St.^
    ",
    n_to City_30_21,
    s_to City_32_21,
;

City_Class City_32_34_21 "21st St between 32ndAve and 34th Ave"
  with
    description "
    North to 32nd Ave and 21st St.^
    ",
    n_to City_32_21,
;

City_Class City_32_23 "32nd Ave and 23rd St"
  with
    description "
    North to 23rd St between 30thAve and 32nd Ave.^
    South to 23rd St between 32ndAve and 34th Ave.^
    West to 32nd Ave between 21st St and 23rd St.^
    East to 32nd Ave between 23rd St and 25th St.^
    ",
    n_to City_30_32_23,
    s_to City_32_34_23,
    w_to City_32_21_23,
    e_to City_32_23_25,
;

City_Class City_32_21_23 "32nd Ave between 21st St and 23rd St"

  with
    description "
    West to 32nd Ave and 21st St.^
    East to 32nd Ave and 23rd St.^
    ",
    w_to City_32_21,
    e_to City_32_23,
;

City_Class City_30_32_23 "23rd St between 30thAve and 32nd Ave"
  with
    description "
    North to 30th Ave and 23rd St.^
    South to 32nd Ave and 23rd St.^
    ",
    n_to City_30_23,
    s_to City_32_23,
;

City_Class City_32_34_23 "23rd St between 32ndAve and 34th Ave"
  with
    description "
    North to 32nd Ave and 23rd St.^

    ",
    n_to City_32_23,
;

City_Class City_32_25 "32nd Ave and 25th St"
  with
    description "
    North to 25th St between 30thAve and 32nd Ave.^
    South to 25th St between 32ndAve and 34th Ave.^
    West to 32nd Ave between 23rd St and 25th St.^
    East to 32nd Ave between 25th St and 27th St.^
    ",
    n_to City_30_32_25,
    s_to City_32_34_25,
    w_to City_32_23_25,
    e_to City_32_25_27,
;

City_Class City_32_23_25 "32nd Ave between 23rd St and 25th St"
  with
    description "
    West to 32nd Ave and 23rd St.^
    East to 32nd Ave and 25th St.^

    ",
    w_to City_32_23,
    e_to City_32_25,
;

City_Class City_30_32_25 "25th St between 30thAve and 32nd Ave"
  with
    description "
    North to 30th Ave and 25th St.^
    South to 32nd Ave and 25th St.^
    ",
    n_to City_30_25,
    s_to City_32_25,
;

City_Class City_32_34_25 "25th St between 32ndAve and 34th Ave"
  with
    description "
    North to 32nd Ave and 25th St.^
    ",
    n_to City_32_25,
;

City_Class City_32_27 "32nd Ave and 27th St"
  with
    description "
    North to 27th St between 30thAve and 32nd Ave.^
    South to 27th St between 32ndAve and 34th Ave.^
    West to 32nd Ave between 25th St and 27th St.^
    East to 32nd Ave between 27th St and 29th St.^
    ",
    n_to City_30_32_27,
    s_to City_32_34_27,
    w_to City_32_25_27,
    e_to City_32_27_29,
;

City_Class City_32_25_27 "32nd Ave between 25th St and 27th St"
  with
    description "
    West to 32nd Ave and 25th St.^
    East to 32nd Ave and 27th St.^
    ",
    w_to City_32_25,
    e_to City_32_27,
;

City_Class City_30_32_27 "27th St between 30thAve and 32nd Ave"
  with
    description "
    North to 30th Ave and 27th St.^
    South to 32nd Ave and 27th St.^
    ",
    n_to City_30_27,
    s_to City_32_27,
;

City_Class City_32_34_27 "27th St between 32ndAve and 34th Ave"
  with
    description "
    North to 32nd Ave and 27th St.^
    ",
    n_to City_32_27,
;

City_Class City_32_29 "32nd Ave and 29th St"
  with
    description "
    North to 29th St between 30thAve and 32nd Ave.^

    South to 29th St between 32ndAve and 34th Ave.^
    West to 32nd Ave between 27th St and 29th St.^
    East to 32nd Ave between 29th St and 31st St.^
    ",
    n_to City_30_32_29,
    s_to City_32_34_29,
    w_to City_32_27_29,
    e_to City_32_29_31,
;

City_Class City_32_27_29 "32nd Ave between 27th St and 29th St"
  with
    description "
    West to 32nd Ave and 27th St.^
    East to 32nd Ave and 29th St.^
    ",
    w_to City_32_27,
    e_to City_32_29,
;

City_Class City_30_32_29 "29th St between 30thAve and 32nd Ave"
  with
    description "

    North to 30th Ave and 29th St.^
    South to 32nd Ave and 29th St.^
    ",
    n_to City_30_29,
    s_to City_32_29,
;

City_Class City_32_34_29 "29th St between 32ndAve and 34th Ave"
  with
    description "
    North to 32nd Ave and 29th St.^
    ",
    n_to City_32_29,
;

City_Class City_32_31 "32nd Ave and 31st St"
  with
    description "
    North to 31st St between 30thAve and 32nd Ave.^
    South to 31st St between 32ndAve and 34th Ave.^
    West to 32nd Ave between 29th St and 31st St.^
    East to 32nd Ave between 31st St and 33rd St.^
    ",

    n_to City_30_32_31,
    s_to City_32_34_31,
    w_to City_32_29_31,
    e_to City_32_31_33,
;

City_Class City_32_29_31 "32nd Ave between 29th St and 31st St"
  with
    description "
    West to 32nd Ave and 29th St.^
    East to 32nd Ave and 31st St.^
    ",
    w_to City_32_29,
    e_to City_32_31,
;

City_Class City_30_32_31 "31st St between 30thAve and 32nd Ave"
  with
    description "
    North to 30th Ave and 31st St.^
    South to 32nd Ave and 31st St.^
    ",
    n_to City_30_31,

    s_to City_32_31,
;

City_Class City_32_34_31 "31st St between 32ndAve and 34th Ave"
  with
    description "
    North to 32nd Ave and 31st St.^
    ",
    n_to City_32_31,
;

City_Class City_32_33 "32nd Ave and 33rd St"
  with
    description "
    North to 33rd St between 30thAve and 32nd Ave.^
    South to 33rd St between 32ndAve and 34th Ave.^
    West to 32nd Ave between 31st St and 33rd St.^
    East to 32nd Ave between 33rd St and 35th St.^
    ",
    n_to City_30_32_33,
    s_to City_32_34_33,
    w_to City_32_31_33,
    e_to City_32_33_35,

;

City_Class City_32_31_33 "32nd Ave between 31st St and 33rd St"
  with
    description "
    West to 32nd Ave and 31st St.^
    East to 32nd Ave and 33rd St.^
    ",
    w_to City_32_31,
    e_to City_32_33,
;

City_Class City_30_32_33 "33rd St between 30thAve and 32nd Ave"
  with
    description "
    North to 30th Ave and 33rd St.^
    South to 32nd Ave and 33rd St.^
    ",
    n_to City_30_33,
    s_to City_32_33,
;

City_Class City_32_34_33 "33rd St between 32ndAve and 34th Ave"

  with
    description "
    North to 32nd Ave and 33rd St.^
    ",
    n_to City_32_33,
;

City_Class City_32_35 "32nd Ave and 35th St"
  with
    description "
    North to 35th St between 30thAve and 32nd Ave.^
    South to 35th St between 32ndAve and 34th Ave.^
    West to 32nd Ave between 33rd St and 35th St.^
    East to 32nd Ave between 35th St and 37th St.^
    ",
    n_to City_30_32_35,
    s_to City_32_34_35,
    w_to City_32_33_35,
    e_to City_32_35_37,
;

City_Class City_32_33_35 "32nd Ave between 33rd St and 35th St"
  with

    description "
    West to 32nd Ave and 33rd St.^
    East to 32nd Ave and 35th St.^
    ",
    w_to City_32_33,
    e_to City_32_35,
;

City_Class City_30_32_35 "35th St between 30thAve and 32nd Ave"
  with
    description "
    North to 30th Ave and 35th St.^
    South to 32nd Ave and 35th St.^
    ",
    n_to City_30_35,
    s_to City_32_35,
;

City_Class City_32_34_35 "35th St between 32ndAve and 34th Ave"
  with
    description "
    North to 32nd Ave and 35th St.^
    ",

    n_to City_32_35,
;

City_Class City_32_37 "32nd Ave and 37th St"
  with
    description "
    North to 37th St between 30thAve and 32nd Ave.^
    South to 37th St between 32ndAve and 34th Ave.^
    West to 32nd Ave between 35th St and 37th St.^
    East to 32nd Ave between 37th St and 39th St.^
    ",
    n_to City_30_32_37,
    s_to City_32_34_37,
    w_to City_32_35_37,
    e_to City_32_37_39,
;

City_Class City_32_35_37 "32nd Ave between 35th St and 37th St"
  with
    description "
    West to 32nd Ave and 35th St.^
    East to 32nd Ave and 37th St.^
    ",

    w_to City_32_35,
    e_to City_32_37,
;

City_Class City_30_32_37 "37th St between 30thAve and 32nd Ave"
  with
    description "
    North to 30th Ave and 37th St.^
    South to 32nd Ave and 37th St.^
    ",
    n_to City_30_37,
    s_to City_32_37,
;

City_Class City_32_37_39 "32nd Ave between 37th St and 39th St"
  with
    description "
    West to 32nd Ave and 37th St.^
    ",
    w_to City_32_37,
;

City_Class City_32_34_37 "37th St between 32ndAve and 34th Ave"

  with
    description "
    North to 32nd Ave and 37th St.^
    ",
    n_to City_32_37,
;
