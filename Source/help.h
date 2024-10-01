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

! GEneral help text.
Constant Help_Text_General
 "This is a text adventure game along the lines of Adventure and Zork.^
  To interact with the game use one command per line.^
  Examples are LOOK, EXAMINE, OPEN, TAKE and so on.^
  ^
  To get help on a topic or object type 'HELP TOPIC'.^
  To get a list of words used in the game type 'HELP WORDS'.^";
Constant Help_Text_Notword "That is not a valid word in this game.^";
Constant Help_Text_Unknown "Help is not available on this topic.^";
Constant Help_Text_Words
 "These are the words used in this game:^
  EAT EXAMINE OPEN LOOK PLAY TAKE USE^";

! Help test for specific words.
Constant Help_Text_Word_Close "CLOSE a container.";
Constant Help_Text_Word_Eat "Use 'EAT PILL' to consume a pill from the bottle.^";
Constant Help_Text_Word_Examine "Give detailed information on any object or direction.^";
Constant Help_Text_Word_Open "OPEN a container to interact with the contents.";
Constant Help_Text_Word_Look
 "LOOK will give information on the current room.^
  You can also LOOK AT and object or LOOK IN a container.^";
Constant Help_Text_Word_Play
 "PLAY the tape currently in the tape player.^
  PLAY TAPE to put a tape into the tape player and play it.^";
Constant Help_Text_Word_Take
 "TAKE takes an object from the ground.^
  TAKE ALL takes all available objects on ground or from open containers.^";
Constant Help_Text_Word_Use "USE attempts to do the right thing for an item. Try it.^";

! Constant Help_Text_ "";

! ------------------------------------------------------------------------------
! Globals
! ------------------------------------------------------------------------------

Global Help_Topic = false;
Global Help_Topic_Word = nothing;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

! Set the global Help_Topic to the word.
[HelpTopic word;
  word = NextWord();
  Help_Topic_word = word;
  Help_Topic = true;
];

! Print general help for playing the game.
[HelpGeneral;
  print
   "Welcome to ", (string) Story, "!^
    This is a text adventure game along the lines of Adventure and Zork.^
    To interact with the game use one command per line.^
    Examples are LOOK, EXAMINE, OPEN, TAKE and so on.^
    ^
    To get help on a topic or object type 'HELP TOPIC'.^
    To get a list of words used in the game type 'HELP WORDS'.^";
];

! Print help text for the user.
[HelpSub;
  ! Do we have a noun?
  if (noun == nothing) {
    ! No noun. Do we have a help topic?
    if (Help_Topic == true) {
      switch (Help_Topic_Word) {
        0:          print (string) Help_Text_Notword;
        'close':    print (string) Help_Text_Word_Close;
        'eat':      print (string) Help_Text_Word_Eat;
        'examine':  print (string) Help_Text_Word_Examine;
        'look':     print (string) Help_Text_Word_Look;
        'open':     print (string) Help_Text_Word_Open;
        'play':     print (string) Help_Text_Word_Play;
        'take':     print (string) Help_Text_Word_Take;
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
