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
    description "Bottle of Pills.",
    number PILLS_DEFAULT_COUNT,
    time_left PILLS_DURATION,
    invent [;
      if (inventory_stage==2) {
        print " (";
        Pills_Print_Number(self);
        print ")";
      }
    ],
    daemon [;
      self.time_left--;
#Ifdef DEBUG;
      print "^pill time left ", self.time_left, " turns.^";;
#Endif;
      if (self.time_left == 0) {
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

[Pills_Print_Number bottle;
  if (bottle.number == 0) {
    print "Empty";
  } else {
    print bottle.number, " pill";
    if (bottle.number > 1) {
      print "s";
    }
  }
];

! Special case for te pills. We want the pill bottle to stay in inventory.
[Pills_EatSub;
  ! Call the system eat routine if this is not our pills.
  if (~~(noun ofclass Pills_Class)) {
    EatSub();
  }

  ! No more pills left.
  if (noun.number == 0) {
    "The pill bottle is empty.";
  }

  ! Take a pill.
  noun.number--;
  print "You take a pill. You have ";
  Pills_Print_Number(noun);
  print " left.^";
  noun.time_left = noun.time_left + PILLS_DURATION;
];

! ------------------------------------------------------------------------------
! Grammar
! ------------------------------------------------------------------------------

Extend 'eat' first
  * held   -> Pills_Eat;
