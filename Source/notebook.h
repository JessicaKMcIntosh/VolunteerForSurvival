! ------------------------------------------------------------------------------
! Notebook - A notebook to keep track of things learned in-game.
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
!
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the Notebook library.";

! ------------------------------------------------------------------------------
! Globals
! ------------------------------------------------------------------------------

! The page number given to the previous page added to the notebook.
! Pages get numbers as they are added.
Global Notebook_Recent_Page_Num = 0;

! ------------------------------------------------------------------------------
! Classes
! ------------------------------------------------------------------------------

! The notebook.
Class Notebook_Class
  with
    name 'book' 'note' 'notebook',
    description "A book of knowledge.^",
    before [;
      Examine, Read:
        Notebook_List_Contents();
        rtrue;
    ],
    invent [;
      print (a) self;
      print " (";
      if (children(self) == 0) {
        print "Empty";
      } else {
        print children(self), " page";
        if (children(self) > 1) {
          print "s";
        }
      }
      print ")";
      rtrue;
    ],
  has container
;

! Pages in the notebook.
Class Notebook_Page_Class(10)
  with
    number 0,
;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

! List the contents of the notebook.
[ Notebook_List_Contents
  page_obj;
  print "Notebook Contents:^";
  objectloop (page_obj in Notebook) {
    ! Make sure each page has a number.
    if (page_obj.number == 0) {
      page_obj.number = ++Notebook_Recent_Page_Num;
    }
    print "Page ", page_obj.number, " - ", (name) page_obj, "^";
  }
];

! Notebook interface.
[ NotebookSub;
  "Not yet implemented.";
];

! ------------------------------------------------------------------------------
! Grammar
! ------------------------------------------------------------------------------

! Notebook verbs.
Verb 'book'
  *       -> Notebook
  * noun  -> Notebook;

Verb 'note'
  *       -> Notebook
  * noun  -> Notebook;

Verb 'notebook'
  *       -> Notebook
  * noun  -> Notebook;
