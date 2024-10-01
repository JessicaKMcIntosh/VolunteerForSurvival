! infunit.h - An outline test harness for Inform, based on jUnit.
!   Version 1.0 (19-Sep-2001)
!
! by Matt Albrecht - groboclown@users.sourceforge.net
!
! (If you need to edit this file, note that indentations are 4 spaces
! and tabs are not used.)
!
! This has been donated to the Public Domain.  Use, abuse, and don't blame me.
!


System_file;


Message "Adding Inform Unit Test library";

! You must provide your own Main method to execute each of your tests.

Global infunit__errorCount = 0;
Global infunit__testCount = 0;
Global infunit__exception;


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! At the end of the Main, you should call this routine.
[ report
    k; ! locals

    print "*************************^
     * infUnit test results:^
     *    number of tests run: ",infunit__testCount,"^
     *    number of successful tests: ",
        (infunit__testCount - infunit__errorCount),"^
     *    number of errors: ",infunit__errorCount,"^
     *************************^";
    print "Press any key to continue.";
    @read_char 1 -> k;
    "";
];


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! At the start of each test method, this should be called.
[ StartTest
    testRoutine;    ! parameter
    ++infunit__testCount;
    @catch -> infunit__exception;

    testRoutine();

    rfalse;
];


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Ensure that the 1st parameter is true.  If not, report the error with the
! optional text in the second parameter.
!
! Returns true if the assertion failed (indicating the test should exit), or
! false if the assertion is good.
[ assertTrue
    isTrue optErrorText   !  parameters
    doContinue ! optional parameter
    ;

    if (infunit__assertTrue( isTrue, optErrorText, false ))
    {
        infunit__throw( doContinue );
        rtrue;
    }
    ! else
    rfalse;
];


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Asserts that the first two parameters are equal.
[ assertEquals
    first second optErrorText   ! parameters
    doContinue ! optional parameter
    ;

!print "[[ first = ",first,", second = ",second,"; first == second = ",(first == second),"]]^";
    if (infunit__assertTrue( first == second, optErrorText, true ))
    {
        print "[ expected ",first,", but found ",second,"]^";
        infunit__throw( doContinue );
        rtrue;
    }
    ! else
    rfalse;
];




!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Asserts that the first parameter is not equal to nothing
[ assertNotNothing
    first optErrorText   ! parameters
    doContinue ! optional parameter
    ;

    if (infunit__assertTrue( first ~= nothing, optErrorText, true ))
    {
        print "[value is nothing]^";
        infunit__throw( doContinue );
        rtrue;
    }
    ! else
    rfalse;
];


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Sends a failure signal.
[ fail
    optErrorText   ! parameters
    doContinue ! optional parameter
    ;

    infunit__assertTrue( false, optErrorText, true );
    print "[failure]^";
    infunit__throw( doContinue );
    rtrue;
];


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Internal method to handle basic assertions.
[ infunit__assertTrue
    isTrue optErrorText   !  parameters
    dontPrintEOL   ! hidden parameter
    ;

    if (isTrue == false)
    {
        ++infunit__errorCount;
        print "** Error: an assertion failed!";
        if (optErrorText ~= nothing)
        {
            print " ",(string)optErrorText;
        }
        if (dontPrintEOL == false)
            print "^";
        else
            print " ";
        rtrue;
    }
    ! else
    rfalse;
];


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Internal method to throw exceptions.
[ infunit__throw
    doContinue; ! parameters

    if (doContinue == false)
    {
        @throw "Assert failed" infunit__exception;
    }
];

