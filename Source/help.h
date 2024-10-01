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

Constant Help_Unknown "Help is not available on this topic.^";
Constant Help_Topic_Eat "Use 'EAT PILL' to consume a pill from the bottle.^";

! ------------------------------------------------------------------------------
! Globals
! ------------------------------------------------------------------------------

Global Help_Topic = nothing;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

! Set the global Help_Topic to the word.
[HelpTopic word;
  word = NextWord();
  Help_Topic = word;
];

! Print general help for playing the game.
[HelpGeneral;
  print "
    Welcome to ", (string) Story, "!^
    This is a text adventure game along the lines of Adventure and Zork.^
    To interact with the game use one command per line.^
    Examples are LOOK, EXAMINE, OPEN, TAKE and so on.^
    ^
    To get help on a topic or object type 'HELP TOPIC'.^
  ";
];

! Print help text for the user.
[HelpSub;
  ! Do we have a noun?
  if (noun == nothing) {
    ! No noun. Do we have a help topic?
    if (Help_Topic ~= nothing) {
      switch (Help_Topic) {
        'eat':    print (string) Help_Topic_Eat;
        default:  print (string) Help_Unknown;
      }
      Help_Topic = nothing;
      rtrue;
    }

    ! Print default help text.
    HelpGeneral();
  } else {
    ! Try to print something useful about the object.
    if (metaclass(noun) == Object) {
      ! if (noun provides help_text) {
        ! print noun.help_text();
      ! } else {
        noun.description();
      ! }
      rtrue;
    }
  }
];

! ------------------------------------------------------------------------------
! Grammar
! ------------------------------------------------------------------------------

Verb meta "help"
  *           -> Help
  * noun      -> Help
  * HelpTopic -> Help;
