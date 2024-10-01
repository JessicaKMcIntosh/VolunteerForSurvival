! ------------------------------------------------------------------------------
! Extensions to the infunit.h library.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! Modified from the original 'infunit.h' file in the Extensions folder.
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Adding Inform Unit Test library extensions.";

! ------------------------------------------------------------------------------
! Test Code
! ------------------------------------------------------------------------------

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! At the end of the Main, you should call this routine.
! Modified to print the report without asking for a key press.
[ reportCustom;

    print
     "*************************************^
      * infUnit test results:^
      *    number of tests run: ",infunit__testCount,"^
      *    number of successful tests: ",(infunit__testCount - infunit__errorCount),"^
      *    number of errors: ",infunit__errorCount,"^
      *************************************^";
    "";
];

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Asserts that the first parameter is of the second parameter class.
[ assertOfClass
    first second optErrorText   ! parameters
    doContinue ! optional parameter
    ;

    if (infunit__assertTrue( first ofclass second, optErrorText, true ))
    {
        print "[ expected ",(name) first,", but found ",(name) second,"]^";
        infunit__throw( doContinue );
        rtrue;
    }
    ! else
    rfalse;
];

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Asserts that the first two parameters are equal using the StrmCmp routine.
[ assertStrCmp
    first second optErrorText   ! parameters
    doContinue ! optional parameter
    ;

    if (infunit__assertTrue( (StrCmp(CheckString, PrintedString) == 0), optErrorText, true ))
    {
        print "^[ expected the string:^";
        PrintString(first);
        print "^but captured the string:^";
        PrintString(second);
        print "^]^";
        infunit__throw( doContinue );
        rtrue;
    }
    ! else
    rfalse;
];
