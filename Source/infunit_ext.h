! ------------------------------------------------------------------------------
! Extensions to the infunit.h library.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
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