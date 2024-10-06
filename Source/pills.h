! ------------------------------------------------------------------------------
! pills - Medication that makes is possible to explore the wasteland.
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
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the Pills library.";

! ------------------------------------------------------------------------------
! Constants
! ------------------------------------------------------------------------------

! The number of pills in a bottle by default.
Constant PILLS_DEFAULT_COUNT 25;

! How many turns each pill lasts.
Constant PILLS_DURATION 100;

! Print a warning message at this remaining duration.
Constant PILLS_WARNING (PILLS_DURATION / 4);

! Print a critical message at this remaining duration.
Constant PILLS_CRITICAL 5;

! ------------------------------------------------------------------------------
! Classes
! ------------------------------------------------------------------------------

Class Pills_Class
  with
    name 'pills' 'pill' 'bottle',
    description
     "Bottle of Agalsirodine pills.^
      Warning, not for human consumption.^
      Will cause memory loss, hallucinations and brain damage.^
      ^
      The label says to take one pill regularly to avoid mind control.",
    number PILLS_DEFAULT_COUNT,
    time_left PILLS_DURATION,
    invent [;
      if (inventory_stage==2) {
        print " (";
        Pills_Print_Number(self);
        print ")";
      }
    ],
    before [;
      Eat:
        ! No more pills left.
        if (self.number == 0) {
          "The pill bottle is empty.";
        }

        ! Take a pill.
        self.number--;
        self.time_left = self.time_left + PILLS_DURATION;
        print "You take a pill. You have ";
        if (noun.number == 0) {
          print "no more pills";
        } else {
          Pills_Print_Number(self);
        }
        print " left.^";
        rtrue;
    ],
    daemon [;
      self.time_left--;
#Ifdef DEBUG;
      print "^pill time left ", self.time_left, " turns.^";;
#Endif;
      if (self.time_left <= 0) {
        deadflag = 1;
       "You stumble as your vision blurrs.^
        Pain consumes your mind as reality grows numb.^
        Laughing echos in your head as you fall to the ground.";
      }
      if (self.time_left < PILLS_CRITICAL) "^You feel terrible.";
      if (self.time_left < PILLS_WARNING)  "^You do not feel so well.";
      if (self.time_left > PILLS_DURATION) "^You feel great!";
    ]
  has edible
;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

! Pring the number of pills in the bottle.
[ Pills_Print_Number
  bottle;
  if (bottle.number == 0) {
    print "Empty";
  } else {
    print bottle.number, " pill";
    if (bottle.number > 1) {
      print "s";
    }
  }
];
