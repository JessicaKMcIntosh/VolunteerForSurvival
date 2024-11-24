! ------------------------------------------------------------------------------
! help - Help text for how to play the game.
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

Message "Loading the Help library.";

! ------------------------------------------------------------------------------
! Constants
! ------------------------------------------------------------------------------

! General help text.
Constant Help_Text_General
 "This is a text adventure game along the lines of Adventure and Zork.^
  To interact with the game use one command per line.^
  Examples are LOOK, EXAMINE, OPEN, TAKE and so on.^
  ^
  To get help on a topic or object type 'HELP TOPIC'.^
  To get a list of words used in the game type 'HELP WORDS'.
  If you are completely lost type 'HELP FIRST'.^";
Constant Help_Text_First_Steps
 "There are the first steps to start your exploration.^
  ^
  PLAY^
  INVENTORY^
  OPEN BOX^
  TAKE ALL^
  NORTH^
  ^
  TAKE ALL^
  PLAY #1^
  NORTH^";
Constant Help_Text_Not_Word "That is not a valid word in this game.^";
Constant Help_Text_Unknown "Help is not available on this topic.^";
Constant Help_Text_Words
 "These are the words used in this game:^
  EAT EXAMINE GO INVENTORY OPEN LOOK PLAY SCORE TAKE TURN UNLOCK USE^
  Directions: NORTH SOUTH EAST WEST UP DOWN^";

! Help text for specific words.
Constant Help_Text_Word_Close "CLOSE a container.";
Constant Help_Text_Word_Eat "Use 'EAT PILL' to consume a pill from the bottle.^";
Constant Help_Text_Word_Examine "EXAMINE an object or direction to get detailed information.^";
Constant Help_Text_Word_Go "GO in a specific direction. NORTH, SOUTH, EAST, WEST, UP, DOWN^";
Constant Help_Text_Word_Inventory "INVENTORY shows what the player is currently carrying.^";
Constant Help_Text_Word_Open "OPEN a container to interact with the contents.^";
Constant Help_Text_Word_Look
 "LOOK will give information on the current room.^
  You can also LOOK AT and object or LOOK IN a container.^";
Constant Help_Text_Word_Play
 "PLAY the tape currently in the tape player.^
  PLAY TAPE to put a tape into the tape player and play it.^";
Constant Help_Text_Word_Take
 "TAKE takes an object from the ground.^
  TAKE ALL takes all available objects on ground or from open containers.^";
Constant Help_Text_Word_Turn "TURN an object on or off.^";
Constant Help_Text_Word_Score "SCORE shows your current score out of the maximum score.^";
Constant Help_Text_Word_Unlock "UNLOCK CONTAINER WITH ITEM to unlock a container with a key (crowbar).^";
Constant Help_Text_Word_Use "USE attempts to do the right thing for an item. Try it.^";

! ------------------------------------------------------------------------------
! Globals
! ------------------------------------------------------------------------------

Global Help_Topic = false;
Global Help_Topic_Word = nothing;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

! Set the global Help_Topic_Word to the word.
! This is an ugly hack, but it works.
[ HelpTopic
  word;
  word = NextWord();
  Help_Topic_word = word;
  Help_Topic = true;
];

! Print help text for the user.
[ HelpSub;
  ! Do we have a noun?
  if (noun == nothing) {
    ! No noun. Do we have a help topic?
    if (Help_Topic == true) {
      switch (Help_Topic_Word) {
        0:          print (string) Help_Text_Not_Word;
        'close':    print (string) Help_Text_Word_Close;
        'eat':      print (string) Help_Text_Word_Eat;
        'examine':  print (string) Help_Text_Word_Examine;
        'first':    print (string) Help_Text_First_Steps;
        'go':       print (string) Help_Text_Word_Go;
        'inventory':print (string) Help_Text_Word_Inventory;
        'look':     print (string) Help_Text_Word_Look;
        'open':     print (string) Help_Text_Word_Open;
        'play':     print (string) Help_Text_Word_Play;
        'take':     print (string) Help_Text_Word_Take;
        'turn':     print (string) Help_Text_Word_Turn;
        'score':    print (string) Help_Text_Word_Score;
        'score':    print (string) Help_Text_Word_Unlock;
        'use':      print (string) Help_Text_Word_Use;
        'words':    print (string) Help_Text_Words;
        default:    print (string) Help_Text_Unknown;
      }
      Help_Topic = false;
      Help_Topic_Word = nothing;
    } else {
      ! Print default help text.
      print "Welcome to ", (string) Story, "!^";
      print (string) Help_Text_General;
    }
  } else {
    ! Try to print something useful about the object.
    ! if (noun provides help_text) {
      ! print noun.help_text();
    ! } else {
      noun.description();
    ! }
    rtrue;
  }
];

! ------------------------------------------------------------------------------
! Grammar
! ------------------------------------------------------------------------------

Verb meta "help"
  *           -> Help
  * noun      -> Help
  * HelpTopic -> Help;
