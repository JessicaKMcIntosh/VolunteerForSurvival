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
    ],
  has container
;

! Pages in the notebook.
Class Notebook_Page_Class
;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

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
