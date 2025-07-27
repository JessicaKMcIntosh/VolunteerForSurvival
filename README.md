# Volunteer For Survival (VTS) - A survival horror text adventure game

It’s been five years since the aliens invaded earth. We got an early warning of their approach so we were prepared. Shelters were built to house people during the conflict. Unfortunately, due to hubris, the world governments expected to defeat the aliens quickly. As a result the shelters were only intended to last for a decade. Thanks to overcrowding, the supplies have nearly run out. For the past year volunteers have been sent out to collect supplies. You are only the latest.

Welcome to Vololtol city.

Can you survive the alien wasteland and make it back to the shelter?

VTS is a survival horror text adventure game. You are tasked with finding supplies to keep the shelter going.

![Map of Vololtol city](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Map/vts_map.png?raw=true)

See the map file [Map/vts_map.png](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Map/vts_map.png).

## Playing Volunteer For Survival

Currently the best way to play VTS is from [Borogove.io](https://3srgd2vv.play.borogove.io/).

For Unix and Windows the game must be compiled first.

### Playing VTS Online

Volunteer For Survival has been uploaded to <https://borogove.io/>.
It is currently private, but will be made public when the game is playable.\
<https://3srgd2vv.play.borogove.io/>

See the Wiki on GitHub for useful information.\
<https://github.com/JessicaKMcIntosh/VolunteerForSurvival/wiki>

### Playing VTS on Unix

* It is likely your Linux/Unix distribution already has a Z-Machine interpreter available.
* See the following URL for Unix Z-Machine interpreters.\
  <https://www.inform-fiction.org/zmachine/unix.html>

### Playing VTS on Windows

* See the following URL for Windows Z-Machine interpreters.\
  <https://www.inform-fiction.org/zmachine/windows.html>
* Frotz is a very good interpreter.\
  <https://ifarchive.org/if-archive/infocom/interpreters/frotz/WindowsFrotzInstaller.exe>

### First Steps

VTS is a text adventure game written using the Inform 6 language. While the parser is powerful, it does not understand normal English.

Each line can have only one action. TAKE ALL, PLAY, NORTH, EAST, EXAMINE. You can navigate and play the game using two word commands, occasionally three words. Extra words like THE are not required.

Type `HELP WORDS` to get a list of words this game uses. Help is available on each word.

## Development

VTS is written in the Inform 6 language created by Graham Nelson.

The inspiration for VTS came from a video about PSX/PS1 era horror games.\
<https://youtu.be/z4vtcXVPhbQ?si=ldy6Ie5yHbjiqfTm>

VTS is being developed with [Visual Studio Code](https://code.visualstudio.com/) on Windows and Linux.

Docker is required to run the tests and to generate the file `Source/city.h`. This is due to inconsistent output of the Windows dfrotz binary.

### Debug Build

Building with the command `debug` will generate a DEBUG build.
This build will output extra messages useful for debugging parts of the game.
Search through the source for `#Ifdef DEBUG;` to find these messages.

### Coding style

The Coding style follows that of the Inform 6 Library source.

The following deviations are made:

* Two spaces for indention.
* Routine variables on a separate line. Or separate lines as required.
* I prefer readability over brevity. We have large displays now. This results in lots of comments along with longer variable and subroutine names.

### Source Files

These are all of the Inform files that make up the game.

* [vts.inf](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/vts.inf) - The Inform game file. This is the main source file for the VTS game.
* [Source/city.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/city.h) - The main city map. Generated from `Utilities/gencity.inf`.
* [Source/classes.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/classes.h) - Several classes that don't really fit anywhere else.
* [Source/help.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/help.h) - A simple help interface for people new to interactive fiction.
* [Source/lamp.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/lamp.h) - Implementation of a camping lantern to provide light in dark rooms.
* [Source/loot.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/loot.h) - Implementation of loot and loot containing containers.
* [Source/notebook.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/notebook.h) - Implementation of a notebook.
* [Source/pills.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/pills.h) - Implementation of the pills the player takes to stay sane.
* [Source/starting.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/starting.h) - The starting room and items. Also the alley which links it to the map.
* [Source/storm.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/storm.h) - Storm drain junctions.
* [Source/stuff.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/stuff.h) - Random stuff that doesn't really fit anywhere else.
* [Source/subway.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/subway.h) - The subway stations and junctions.
* [Source/tape.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/tape.h) - Implementation of the microcassette player the player carries. This library can easily be used in other games.
* [Source/xyzzy.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Source/xyzzy.h) - Implementation of the XYZZY easter egg. This is just for fun.
* [Utilities/gencity.inf](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Utilities/gencity.inf) - Generates the file `Source/city.h` file. Must be built with Docker or on Unix.

These files are still written in Inform, but are involved in testing.

* [Tests/testlamp.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Tests/testlamp.h) - Unit tests for the lamp library.
* [Tests/testnotebook.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Tests/testnotebook.h) - Unit tests for the notebook library.
* [Tests/testpills.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Tests/testpills.h) - Unit tests for the pills library.
* [Tests/testtape.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Tests/testtape.h) - Unit tests for the tape library.
* [Tests/unit.h](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Tests/xyzunitzy.h) - A unit testing library.
* [Tests/unit.inf](https://github.com/JessicaKMcIntosh/VolunteerForSurvival/blob/main/Tests/unit.inf) - The Inform game file for the unit tests.

There are several `*.rec` and `*.txt` files in the `Tests` subdirectory.
These files are used for integration tests.
The `*.rec` files are used as transcripts for Frotz.
The `.rec` files also contain comments describing the test.
The output is then compared to the corresponding `.txt` file.
See the `build.sh` file for details on how this works.

### Development Resources

* VS Code Extension 'Inform 6' for syntax highlighting.\
  <https://marketplace.visualstudio.com/items?itemName=natrium729.inform-6>

* The home of Inform 6.\
  <https://inform-fiction.org/>

* The Inform Designer's Manual, Fourth Edition, web version\
  The guide to using the Inform 6 language. Often referred to as the 'DM4'.\
  <https://inform-fiction.org/manual/html/contents.html>

* A remix of the Inform Designer's Manual to make it nicer to use.\
  <https://radiogoddess.github.io/inform6-dm4-remix/index.html>

* Documentation at [The Interactive Fiction Archive](https://www.ifarchive.org/).\
  <https://www.ifarchive.org/indexes/if-archive/infocom/compilers/inform6/manuals/>

  * The DM4 is also available from the archive.
  * HTML - <https://www.ifarchive.org/if-archive/infocom/compilers/inform6/manuals/designers_manual_4.zip>
  * PDF - <https://www.ifarchive.org/if-archive/infocom/compilers/inform6/manuals/designers_manual_4.pdf>

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

### Fast and easy

Using VSCode and Docker this project can be opened in a VSCode Dev Container with everything already setup.

[![Open in Dev Containers](https://img.shields.io/static/v1?label=Dev%20Containers&message=Open&color=blue)](https://vscode.dev/redirect?url=vscode://ms-vscode-remote.remote-containers/cloneInVolume?url=https://github.com/JessicaKMcIntosh/VolunteerForSurvival)

The following extensions are installed:

* [Better Comments](https://marketplace.visualstudio.com/items?itemName=aaron-bond.better-comments)
* [Markdown Preview Github Styling](https://marketplace.visualstudio.com/items?itemName=bierner.markdown-preview-github-styles)
* [markdownlint](https://marketplace.visualstudio.com/items?itemName=DavidAnson.vscode-markdownlint)
* [Draw.io Integration](https://marketplace.visualstudio.com/items?itemName=hediet.vscode-drawio) - For working with the map source files.
* [Git Indicators](https://marketplace.visualstudio.com/items?itemName=lamartire.git-indicators)
* [Git Graph](https://marketplace.visualstudio.com/items?itemName=mhutchie.git-graph)
* [IF Player](https://marketplace.visualstudio.com/items?itemName=natrium729.if-player) - Play the compiled game file.
* [Inform 6](https://marketplace.visualstudio.com/items?itemName=natrium729.inform-6) - Syntax highlighting and more.
* [indent-rainbow](https://marketplace.visualstudio.com/items?itemName=oderwat.indent-rainbow)
* [Indenticator](https://marketplace.visualstudio.com/items?itemName=SirTori.indenticator)
* [Code Spell Checker](https://marketplace.visualstudio.com/items?itemName=streetsidesoftware.code-spell-checker)
* [Error Lens](https://marketplace.visualstudio.com/items?itemName=usernamehw.errorlens)

### Compiling with Docker

The build process will attempt to use [Docker](https://www.docker.com/) if installed.
The build script will create a new image `vts:0.0`.
This image uses Debian stable and installs the packages `frotz` and `inform6-compiler`.
Using Docker greatly simplifies the process and is the recommended method.

### Compiling under Windows

The files required are included in the subdirectory `inform6`.

* Run the script `build.bat`.\
  `build.bat`
* The build script has builtin help.\
  `build.bat help`
* Unit tests can be run using the `test` command.\
  `build.bat tests`

### Compiling under Unix

Linux generally has the inform6 package available for install.
It is recommended to install the package.

* WARNING: Do not use the old Inform 6.31 version under Linux.
  If this is the only version available for your version of Linux then
  download the latest version and compile from source.

To build VTS:

* Run the build.sh file \
  `bash ./build.sh`
* The build script has builtin help.\
  `bash ./build.sh help`
* Tests can be run using the `test` parameter.\
  `bash ./build.sh tests`

There is a version of the inform compiler for Linux included.
To use this version edit the file `build.sh` and see the variable `INFORM_COMPILER`.

To install the latest version of the compiler from source:

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

### Compiling using Visual Studio Code

Using the included build shell or batch files:

* Run the task `Build VTS Game`. This is the default build task.
* The task `Run VTS Tests` will build and run the tests. This is the default test task.
* Run the task `Build VTS Game DEBUG` to compile VTS with DEBUG enabled.

Using the 'Inform 6' extension:

* Install the Extension 'Inform 6' for syntax highlighting.\
  <https://marketplace.visualstudio.com/items?itemName=natrium729.inform-6>
* Optionally install the Extension 'IF Player' to play the game in VS code.\
  <https://marketplace.visualstudio.com/items?itemName=natrium729.if-player>
* Follow the steps for 'Compiling under Windows' to download the compiler and Library.
* If you are on Linux/Unix update the file `.vscode/settings.json` and remove `.exe` from the setting `inform6.inform6Path`.

## Credits

* Inform 6 Compiler and Library by Graham Nelson and David Griffith.
* [betatest.h](https://www.ifarchive.org/if-archive/infocom/compilers/inform6/library/contributions/betatest.h) - A Betatesting Aid. by Marnie Parker aka Doe
* [infunit.h](https://www.ifarchive.org/if-archive/infocom/compilers/inform6/library/contributions/infunit.h) - An outline test harness for Inform, based on jUnit. by Matt Albrecht
* [istring.h](https://www.ifarchive.org/if-archive/infocom/compilers/inform6/library/contributions/istring.h) - The Inform String Library: A reconstruction of the ansi C string functions. By L. Ross Raszewski
* [zorkh.zip](https://www.ifarchive.org/if-archive/infocom/compilers/inform6/library/contributions/zorkh.zip) - A collection of Zork-related library extensions, Release 2, by Joe Merical. Inspiration for the camping lantern.

## Copyright and License

Volunteer For Survival was created by Jessica McIntosh\
JessicaKMcIntosh AT gmail DOT com\
<https://github.com/JessicaKMcIntosh/VolunteerForSurvival>

This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
See the file LICENSE for details.

---

The Inform 6 Library is Copyright Graham Nelson 1993-2004 and David Griffith 2012-2022
See the file inform6/COPYING for details.

---

Files in directory Extensions were downloaded from The Interactive Fiction Archive
from the Inform 6 Library contributions directory. I do not claim ownership on
any files in this directory. All files belong to their creator. See the files
for details.\
<https://ifarchive.org/indexes/if-archive/infocom/compilers/inform6/library/contributions/>
