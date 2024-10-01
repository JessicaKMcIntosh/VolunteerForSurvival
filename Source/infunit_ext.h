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