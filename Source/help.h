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
  To get a list of words used in the game type 'HELP WORDS'.^
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
  NORTH^
  NOTE^";
Constant Help_Text_Not_Word "That is not a valid word in this game.^";
Constant Help_Text_Unknown
 "Help is not available on this topic.^
  Type HELP WORDS for topics.^";
Constant Help_Text_Words
 "These are the words used in this game:^
  EAT EXAMINE GO INVENTORY OPEN LOOK NOTE PLAY SCORE SWITCH TAKE TURN UNLOCK USE^
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
Constant Help_Text_Word_Note
 "NOTE interfaces with the notebook.^
  Without a topic will list the contents of the notebook.^
  If given a page # or topic will lookup said page or topic.^
  ^
  NOTE PAGE 1^
  NOTE 1^
  NOTE LIST";
Constant Help_Text_Word_Play
 "PLAY the tape currently in the tape player.^
  PLAY TAPE to put a tape into the tape player and play it.^";
Constant Help_Text_Word_Take
 "TAKE takes an object from the ground.^
  TAKE ALL takes all available objects on ground or from open containers.^";
Constant Help_Text_Word_Turn "TURN an object on or off.^";
Constant Help_Text_Word_Score "SCORE shows your current score out of the maximum score.^";
Constant Help_Text_Word_Switch "SWITCH an object ON or OFF, toggling the state.^";
Constant Help_Text_Word_Unlock "UNLOCK CONTAINER WITH ITEM to unlock a container with a key (crowbar).^";
Constant Help_Text_Word_Use "USE attempts to do the right thing for an item. Try it.^";

! ------------------------------------------------------------------------------
! Globals
! ------------------------------------------------------------------------------

Global Help_Topic_Text = nothing;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

! Check for a help topic that we want to print help for.
[ HelpTopic
  word;

  ! See if the word is a help topic.
  word = NextWord();
  Help_Topic_Text = nothing;
  switch (word) {
    'book':       Help_Topic_Text = Help_Text_Word_Note;
    'close':      Help_Topic_Text = Help_Text_Word_Close;
    'eat':        Help_Topic_Text = Help_Text_Word_Eat;
    'examine':    Help_Topic_Text = Help_Text_Word_Examine;
    'first':      Help_Topic_Text = Help_Text_First_Steps;
    'go':         Help_Topic_Text = Help_Text_Word_Go;
    'inventory':  Help_Topic_Text = Help_Text_Word_Inventory;
    'look':       Help_Topic_Text = Help_Text_Word_Look;
    'note':       Help_Topic_Text = Help_Text_Word_Note;
    'notebook':   Help_Topic_Text = Help_Text_Word_Note;
    'open':       Help_Topic_Text = Help_Text_Word_Open;
    'play':       Help_Topic_Text = Help_Text_Word_Play;
    'take':       Help_Topic_Text = Help_Text_Word_Take;
    'turn':       Help_Topic_Text = Help_Text_Word_Turn;
    'score':      Help_Topic_Text = Help_Text_Word_Score;
    'switch':     Help_Topic_Text = Help_Text_Word_Switch;
    'unlock':     Help_Topic_Text = Help_Text_Word_Unlock;
    'use':        Help_Topic_Text = Help_Text_Word_Use;
    'words':      Help_Topic_Text = Help_Text_Words;
  }

  ! Was a help topic found?
  if (Help_Topic_Text ~= nothing) {
    return GPR_PREPOSITION;
  }

  ! Nothing found.
  return GPR_FAIL;
];

! Print help text for the user.
[ HelpSub;

  ! Is there help text to print already?
  if (Help_Topic_Text ~= nothing) {
    print (string) Help_Topic_Text;
    Help_Topic_Text = nothing;
  } else if (noun ~= nothing) {
    <<Examine noun>>;
  } else {
      ! Print default help text.
      print "Welcome to ", (string) Story, "!^";
      print (string) Help_Text_General;
  }
];

! ------------------------------------------------------------------------------
! Grammar
! ------------------------------------------------------------------------------

Verb meta "help"
  *                           -> Help
  * HelpTopic                 -> Help
  * noun                      -> Help;
