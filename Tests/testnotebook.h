! ------------------------------------------------------------------------------
! Tests for the notebook library.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
! ------------------------------------------------------------------------------

Message "Loading the Notebook Test library.";

! ------------------------------------------------------------------------------
! Libraries
! ------------------------------------------------------------------------------

Include "notebook";

! ------------------------------------------------------------------------------
! Constants
! ------------------------------------------------------------------------------

! Messages for testing.
Constant Notebook_MSG_Contents_1
 "Notebook Contents:^
  Page 1 - Notebook Page 1";
Constant Notebook_MSG_Contents_2
 "Notebook Contents:^
  Page 1 - Notebook Page 1^
  Page 2 - notebook page other";
Constant Notebook_MSG_Page_1
 "Page 1 - Notebook Page 1^
  This is the contents of the notebook page.";

! ------------------------------------------------------------------------------
! Test Objects
! ------------------------------------------------------------------------------

! Notebook object to test.
Notebook_Class Notebook "Notebook"
;

! A page to test the notebook with.
Notebook_Page_Class -> Page_1 "Notebook Page 1"
  with
    name 'page' '#1',
    description "A notebook page containing a message.",
    inside_description "This is the contents of the notebook page."
;

! A different page to test the notebook with.
Notebook_Page_Class Page_2 "notebook page other"
  with
    name '#2',
    description "A Notebook page containing NO message.",
  has scored
;

! An object that is not a tape.
Object Notebook_Not_Note "Not a Note"
;

! Object to run the tests.
Unit_Test_Class Note_Tests "Notebook library"
  with
    RunTest [;
      ! Prepare test objects.
      move Notebook to player;
      NotebookUpdateNumbers();

      ! Run the tests.
      Unit_RunTest(_TestNotebook_Created);
      Unit_RunTest(_TestNotebook_AddPage);
      Unit_RunTest(_TestNotebook_Read);
    ],
;

! ------------------------------------------------------------------------------
! Test Routines
! ------------------------------------------------------------------------------

[ _TestNotebook_Created;
  print "Verify the notebook was created successfully.^";

  Unit_AssertNotNothing(
    Notebook,
    "The notebook was not created."
  );

  Unit_AssertOfClass(
    Notebook,
    Notebook_Class,
    "Notebook not created with the notebook class."
  );

  Unit_AssertEquals(
    1,
    Page_1.number,
    "Notebook Page 1 not correctly numbered."
  );

  Unit_AssertCapture(
    NotebookListContents,
    Notebook_MSG_Contents_1,
    "Contents of the notebook with only Page 1 are not correct."
  );

  print "Success...^^";
];

[ _TestNotebook_AddPage;
  print "Verify a new page can be added to the notebook.^";

  Notebook.add(Page_2);

  Unit_AssertTrue(
    (Page_2 in Notebook),
    "Page 2 should be in the notebook after being added."
  );

  Unit_AssertCapture(
    NotebookListContents,
    Notebook_MSG_Contents_2,
    "Contents of the notebook with Pages 1 & 2 are not correct."
  );

  print "Success...^^";
];

[ _TestNotebook_Read;
  print "Verify a page can be read.^";

  Unit_AssertCapture(
    _TestNotebook_ReadPage,
    Notebook_MSG_Page_1,
    "Contents of Page 1 are incorrect."
  );

  print "Success...^^";
];

! ------------------------------------------------------------------------------
! Test Helpers
! ------------------------------------------------------------------------------

[ _TestNotebook_ReadPage;
  NotebookReadPage(Page_1);
];
