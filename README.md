# Volunteer For Survival (VTS) - A survival horror text adventure game

It’s been five years since the aliens invaded earth. We got an early warning of their approach so we were prepared. Shelters were built to house people during the conflict. Unfortunately, due to hubris, the world governments expected to defeat the aliens quickly. As a result the shelters were only intended to last for a decade. Thanks to overcrowding, the supplies have nearly run out. For the past year volunteers have been sent out to collect supplies. You are only the latest.

VTS is a survival horror text adventure game. You are tasked with finding supplies to keep the shelter going.

Can you survive the alien wasteland and make it back to the shelter?

## Playing Volunteer For Survival

Playing VTS Online:

Volunteer For Survival has been uploaded to <https://borogove.io/>.
It is currently private, but will be made public when the game is playable.\
<https://3srgd2vv.play.borogove.io/>

Playing VTS on Unix:

* It is likely your Linux/Unix distribution already has a Z-Machine interpreter available.
* See the following URL for Unix Z-Machine interpreters.\
  <https://www.inform-fiction.org/zmachine/unix.html>

Playing VTS on Windows:

* See the following URL for Windows Z-Machine interpreters.\
  <https://www.inform-fiction.org/zmachine/windows.html>
* Frotz is a very good interpreter.\
  <https://ifarchive.org/if-archive/infocom/interpreters/frotz/WindowsFrotzInstaller.exe>

## Development

VTS is written in the Inform 6 language created by Graham Nelson.

The inspiration for VTS came from a video about PSX/PS1 era horror games.\
<https://youtu.be/z4vtcXVPhbQ?si=ldy6Ie5yHbjiqfTm>

VTS is being developed with [Visual Studio Code](https://code.visualstudio.com/) on Windows.

### Source Files

* [vts.inf](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/vts.inf) -
  The Inform game file. This is the main source file for the VTS game.
* [test_vts.inf](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/test_vts.inf) -
  The Inform game file for the unit tests.
* [Source/infunit_ext.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/infunit_ext.h) -
  Extensions to the testing routines from `Extensions/infunit.h`. These extensions to make testing easier.
* [Source/pills.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/pills.h) -
  Implementation of the pills the player takes.
* [Source/tape.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/tape.h) - Implementation of the microcassette player the player carries. This library can easily be used in other games.
* [Source/testpills.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/testpills.h) - Unit tests for the pills library.
* [Source/testtape.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/testtape.h) - Unit tests for the tape library.
* [Source/xyzzy.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/xyzzy.h) - Implementation of the XYZZY easter egg. This is just for fun.
* [Extensions/betatest.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Extensions/betatest.h) - Adds commands for best testing to record the output of the game with comments.
* [Extensions/infunit.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Extensions/infunit.h) - The unit test library.
* [Extensions/istring.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Extensions/istring.h) - A strings library used for checking the printed output in unit tests.

### Development Resources

* VS Code Extension 'Inform 6' for syntax highlighting.\
  <https://marketplace.visualstudio.com/items?itemName=natrium729.inform-6>

* The home of Inform 6.\
  <https://inform-fiction.org/>

* The Inform Designer's Manual, Fourth Edition, web version\
  The guide to using the Inform 6 language. Often referred to as the 'DM4'.\
  <https://inform-fiction.org/manual/html/contents.html>

* Documentation at [The Interactive Fiction Archive](https://www.ifarchive.org/).\
  <https://www.ifarchive.org/indexes/if-archive/infocom/compilers/inform6/manuals/>

  * In addition to the DM4 I also recommend Roger Firth's Inform 6 Frequently Asked Questions document.\
  <https://www.ifarchive.org/if-archive/infocom/compilers/inform6/manuals/inform_faq.pdf>

  * I also recommend the quick reference cards. These are extremely useful and well designed.\
  <https://www.ifarchive.org/if-archive/infocom/compilers/inform6/manuals/inform_quick_ref.pdf>\
  <https://www.ifarchive.org/if-archive/infocom/compilers/inform6/manuals/inform_lib_quick_ref.pdf>

* Contributed Inform 6 code to extend your game. The files in the directory 'Extensions' came from here.\
  <https://www.ifarchive.org/indexes/if-archive/infocom/compilers/inform6/library/contributions/>

* Example games. These are great for understanding how Inform 6 works.\
  <https://www.ifarchive.org/indexes/if-archive/infocom/compilers/inform6/examples/>

## Compiling Volunteer For Survival

### Compiling under Windows

The files required are included in the subdirectory `inform6`.

* Run the script `build.bat`. \
  `build.bat`
* The build script has builtin help.\
  `build.bat help`
* Tests can be run using the `test` parameter.\
  `build.bat tests`

### Compiling under Unix

The files required are included in the subdirectory `inform6`.

* Run the build.sh file \
  `sh ./build.sh`

If the included files do not work:

* WARNING: Do not use the old Inform 6.31 version under Linux.
  Download the latest version and compile from source.
* Download the Inform 6 compiler source .tar.gz file from:
  <http://www.ifarchive.org/if-archive/infocom/compilers/inform6/source/>
  As of writing this the current file is: inform-6.41-r1.tar.gz
* Extract, build and install the Inform 6 compiler.
  tar -xzf inform-6.41-r1.tar.gz
  cd inform-6.41-r1
  make
  make install
* Change to the VTS folder and update the file `build.sh`.
  Change the comment for the variable `INFORM_COMPILER`.

* Run the build.sh file \
  `sh ./build.sh`

### Compiling using Visual Studio Code

Using the included build shell or batch files:

* Run the task `Build VTS Game`. This is the default build task.
* The task `Run VTS Tests` will build and run the tests. This is the default test task.

Using the 'Inform 6' extension:

* Install the Extension 'Inform 6' for syntax highlighting.\
  <https://marketplace.visualstudio.com/items?itemName=natrium729.inform-6>
* Optionally install the Extension 'IF Player' to play the game in VS code.\
  <https://marketplace.visualstudio.com/items?itemName=natrium729.if-player>
* Follow the steps for 'Compiling under Windows' to download the compiler and Library.
* If you are on Linux/Unix update the file `.vscode/settings.json` and remove `.exe` from the setting `inform6.inform6Path`.

## Copyright and License

Created by Jessica McIntosh\
JessicaKMcIntosh AT gmail DOT com

This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License. See the file LICENSE for details.
