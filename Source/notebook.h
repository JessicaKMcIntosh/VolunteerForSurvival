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
! Constants
! ------------------------------------------------------------------------------



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
Class Notebook_Page_Class
;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

! List the contents of the notebook.
[ Notebook_List_Contents
  page_obj
  page_number;
  page_number = 1;
  print "Notebook Contents:^";
  objectloop (page_obj in Notebook) {
    print "Page ", page_number, " - ", (name) page_obj, "^";
    page_number++;
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
