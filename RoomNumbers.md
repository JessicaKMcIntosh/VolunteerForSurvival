# Room numbers in Volunteer For Survival

Each room in VTS has a number associated with it for debugging purposes.
This might be removed later.

## Below 10000

Room numbers in the city.h file range from 1 to 283.
The highest possible number is `285`.
The number is the position in the table `Under_Table` in the file `gencity.inf`.
The number is created from the Avenue and Street combination.
Storm drains have the same number as the city room above them, plus 500.

```txt
Number = ((Avenue - 19) * 19) + (Street - 20);
```

## 1000 Serries

This serries is reserved for the starting area and any special locations.

* 1001 - `Start_Room` - The starting room.
* 1002 - `Shelter_Entrance` - The shelter entrance room behind the code locked door.
* 1003 - `Start_Alley` - The second alley in the starting area. This alley links the starting room to the city.

## 1100 Serries

This serries is reserved for the subway and storm drain systems.
Starting with the added city rooms that link the subway junctions to the city.

* 1100 - `City_20_19` - 20th Ave and 19th St
* 1101 - `City_34_37` - 34th Ave and 37th St
* 1105 - `Junction_20` - Subway junction at 20th Ave
* 1106 - `Junction_37` - Subway junction at 37th St
* 1120 - 1139 - Subway Blue line.
* 1140 - 1159 - Subway Green line.
* 1160 - 1179 - Subway Orange line.
* 1180 - 1189 - Storm drain junctions.
