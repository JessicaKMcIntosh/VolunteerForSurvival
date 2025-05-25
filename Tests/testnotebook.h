! ------------------------------------------------------------------------------
! Tests for the notebook library.
!
! Created by Jessica McIntosh
! JessicaKMcIntosh AT gmail DOT com
!
! This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
! International License. See the file LICENSE for details.
! ------------------------------------------------------------------------------
! USAGE
! ------------------------------------------------------------------------------
! Include after unit.h.
!
! Requires the following libraries:
! * unit.h by Jessica McIntosh
! * notebook.h by Jessica McIntosh
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
  Page 2 - Notebook page other";
Constant Notebook_MSG_Page_1
 "Page 1 - Notebook Page 1^
  This is the contents of the notebook page.";
Constant Notebook_MSG_Page_2
 "Page 2 - Notebook page other^
  A Notebook page containing NO message.";
Constant Notebook_MSG_Page_3
 "Page 3 - Notebook page pointer^
  This is the real object for Page 3.";

! ------------------------------------------------------------------------------
! Test Objects
! ------------------------------------------------------------------------------

! Notebook object to test.
Notebook_Class Notebook "Notebook"
;

! A page to test the notebook with.
Notebook_Page_Class -> Notebook_Page_1 "Notebook Page 1"
  with
    name 'page' '#1',
    description "A notebook page containing a message.",
    inside_description "This is the contents of the notebook page."
;

! A different page to test the notebook with.
Notebook_Page_Class Notebook_Page_2 "Notebook page other"
  with
    name '#2',
    description "A Notebook page containing NO message.",
;

! A  page that points to a different object.
Notebook_Page_Class Notebook_Page_3 "Notebook page pointer"
  with
    name '#3',
    description "A Notebook page pointing to a different object.",
    real_page Notebook_Page_3_Real,
;

Object Notebook_Page_3_Real
  with
    name 'real',
    description "The real object for Page 3.",
    inside_description "This is the real object for Page 3."
;

! An object that is not a notebook.
Object Notebook_Not_Note "Not a Note"
;

! Object to run the tests.
Unit_Test_Class Notebook_Tests "Notebook library"
  with
    RunTest [;
      ! Prepare test objects.
      move Notebook to player;
      Notebook.update();

      ! Run the tests.
      Unit_RunTest(_TestNotebook_Created);
      Unit_RunTest(_TestNotebook_AddPage);
      Unit_RunTest(_TestNotebook_Read);
      Unit_RunTest(_TestNotebook_RealPage);
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
    Notebook_Page_1.number,
    "Notebook Page 1 not correctly numbered."
  );

  Unit_AssertCapture(
    _TestNotebook_Helper_Contents,
    Notebook_MSG_Contents_1,
    "Contents of the notebook with only Page 1 are not correct."
  );

  print "Success...^^";
];

[ _TestNotebook_AddPage;
  print "Verify a new page can be added to the notebook.^";

  Notebook.add(Notebook_Page_2);

  Unit_AssertTrue(
    (Notebook_Page_2 in Notebook),
    "Page 2 should be in the notebook after being added."
  );

  action = ##Examine;
  Unit_AssertCapture(
    _TestNotebook_Helper_Before,
    Notebook_MSG_Contents_2,
    "Contents of the notebook with Pages 1 & 2 are not correct."
  );

  print "Success...^^";
];

[ _TestNotebook_Read;
  print "Verify a page can be read.^";

  Unit_AssertCapture(
    _TestNotebook_Helper_ReadPage_1,
    Notebook_MSG_Page_1,
    "Contents of Page 1 are incorrect."
  );

  Unit_AssertCapture(
    _TestNotebook_Helper_ReadPage_2,
    Notebook_MSG_Page_2,
    "Contents of Page 2 are incorrect."
  );

  print "Success...^^";
];

[ _TestNotebook_RealPage;
  print "Verify a 'Real' page can be read.^";

  Notebook.add(Notebook_Page_3);

  Unit_AssertCapture(
    _TestNotebook_Helper_ReadPage_3,
    Notebook_MSG_Page_3,
    "Contents of Page 1 are incorrect."
  );

  print "Success...^^";
];

! ------------------------------------------------------------------------------
! Test Helpers
! ------------------------------------------------------------------------------

[ _TestNotebook_Helper_Before;
  Notebook.before();
];

[ _TestNotebook_Helper_Contents;
  Notebook.contents();
];

[ _TestNotebook_Helper_ReadPage_1;
  NotebookReadPage(Notebook_Page_1);
];

[ _TestNotebook_Helper_ReadPage_2;
  NotebookReadPage(Notebook_Page_2);
];

[ _TestNotebook_Helper_ReadPage_3;
  NotebookReadPage(Notebook_Page_3);
];
