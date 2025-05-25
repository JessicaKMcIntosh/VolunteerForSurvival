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
! Create a Notebook and Notebook Page objects.
! The tape Notebook object must be named 'Notebook'.
!
! To update the page number for all notebook pages call:
! Notebook.update();
! This is useful when putting pages in the notebook before the game starts.
!
! To add new pages to the notebook call:
! Notebook.add(NEW_PAGE);
! This automatically gives the page the next number in line.
! ------------------------------------------------------------------------------

! ------------------------------------------------------------------------------
! Meta Data
! ------------------------------------------------------------------------------

System_file;

Message "Loading the Notebook library.";

! ------------------------------------------------------------------------------
! Classes
! ------------------------------------------------------------------------------

! The notebook.
Class Notebook_Class
  with
    name 'book' 'note' 'notebook',
    description "A book of knowledge.^",
    number 0, ! The page number given to the previous page added to the notebook.
    before [;
      Examine, Read:
        NotebookListContents();
        rtrue;
      Consult:
        NotebookConsult();
        rtrue;
    ],
    invent [
      number_children;
      print (a) self;
      print " (";
      number_children = children(self);
      if (number_children == 0) {
        print "Empty";
      } else {
        print number_children, " page";
        if (number_children > 1) {
          print "s";
        }
      }
      print ")";
      rtrue;
    ],
    contents [;
      NotebookListContents();
    ],
    update [;
      NotebookUpdateNumbers();
    ],
    add [ page;
      NotebookAddPage(page);
    ]
  has container
;

! Pages in the notebook.
Class Notebook_Page_Class
  with
    number 0,         ! The page number.
    found_in nothing, ! The object that actually contains the text to print.
;

! ------------------------------------------------------------------------------
! Subroutines
! ------------------------------------------------------------------------------

! Add a new page to the notebook.
[NotebookAddPage
  page
  temp_page;

  ! Add the page to the notebook and give it a number.
  move page to Notebook;
  page.number = ++Notebook.number;

  ! Move the page to the end of the list.
  ! (Make it the newest object.)
  while(sibling(page)) {
    temp_page = sibling(page);
    while(sibling(temp_page)) {
      temp_page = sibling(temp_page);
    }
    move temp_page to Notebook;
  }
];

! Consult the notebook for a page or topic.
[ NotebookConsult
  page
  num
  word;

  ! Get the word to lookup, and check if the word is really a number.
  wn = consult_from;
  consult_from = 0;
  num = TryNumber(wn);
  word = NextWord();

  ! If the word is 'page' then get the next word.
  if (word == 'page') {
    num = TryNumber(wn);
    word = NextWord();
  }

  if (num > 0) {
    ! Find the page by number.
    objectloop (page in Notebook) {
      if (page.number == num) {
        NotebookReadPage(page);
        rtrue;
      }
    }
    print "Unable to find page ", num, " in ", (the) Notebook, ".";
  } else if (word == nothing) {
    ! Not a valid dictionary word.
    print "That topic is not listed in ", (the) Notebook, ".";
  } else {
    ! Find the page by word/name.
    objectloop (page in Notebook) {
      for (num = 0: num < (page.#name / 2): num++) {
        if (page.&name-->num == word) {
          NotebookReadPage(page);
          rtrue;
        }
      }
    }
    print "Unable to find the topic '", (address) word, "' in ", (the) Notebook, ".";
  }
];

! List the contents of the notebook.
[ NotebookListContents
  page;
  print "Notebook Contents:^";
  objectloop (page in Notebook) {
    print "Page ", page.number, " - ", (name) page, "^";
  }
];

! Read a page from the notebook.
! Pass the actual page object.
[ NotebookReadPage
  page;
  print "Page ", page.number, " - ", (name) page, "^";
  if (page.found_in ~= nothing) {
    page = page.found_in;
  }
  if (page provides inside_description) {
    print (string) page.inside_description;
  } else {
    print (string) page.description;
  }
];

! Make sure each page has a number.
[ NotebookUpdateNumbers
  page;
  objectloop (page in Notebook) {
    if (page.number == 0) {
      page.number = ++Notebook.number;
    }
  }
];

! Notebook interface.
[ NotebookSub;
  if (Notebook notin player) {
    print "You are not currently carrying a notebook.";
  } else if (consult_from == 0) {
    NotebookListContents();
  } else {
    NotebookConsult();
  }
];

! By default Read just does Examine.
[ReadSub;
  <<Examine noun>>;
];

! ------------------------------------------------------------------------------
! Grammar
! ------------------------------------------------------------------------------

! Notebook verbs.
Verb 'book' 'note' 'notebook'
  *       -> Notebook
  * topic -> Notebook
  * 'page' topic -> Notebook;

Extend 'read'
  * 'book'/'note'/'notebook' topic -> Notebook
  * 'book'/'note'/'notebook' 'page' topic -> Notebook
  * 'note' 'book' topic -> Notebook
  * 'note' 'book' 'page' topic -> Notebook;
