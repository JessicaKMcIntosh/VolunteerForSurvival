! ------------------------------------------------------------------------------
! lamp - A camping lantern to provide light in dark rooms.
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
!
! Create a camping lantern object.
! Lamp_Class -> -> Camping_Lantern "camping lantern";
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the Lamp library.";

! ------------------------------------------------------------------------------
! Classes
! ------------------------------------------------------------------------------

Class Lamp_Class
  with
    name 'camping' 'lantern' 'lamp' 'light',
    description "A fancy futuristic camping lantern.",
    describe [;
      print "^You see a ", (name) self, " here.";
      if (self has light) " (providing light)";
    ],
    before [;
      SwitchOn:
        if (self has light) {
          "The ", (name) self," is already switched on.";
        } else{
          give self light;
          give self on;
          "The ", (name) self," is now on.";
        }
      SwitchOff:
        if (self hasnt light) {
          "The ", (name) self," is already switched off.";
        } else{
          give self ~light;
          give self ~on;
          "The ", (name) self," is now off.";
        }
      Turn:
        if (self has light) {
          <<SwitchOff self>>;
        } else {
          <<SwitchOn self>>;
        }
    ],
  has switchable scored
;

! ------------------------------------------------------------------------------
! Grammar
! ------------------------------------------------------------------------------

! Turn the lantern on and off.
Extend only 'light' first
  * switchable  -> SwitchOn;
Verb 'extinguish'
  * switchable  -> SwitchOff;
