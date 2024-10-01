# Volunteer For Survival (VTS) - A survival horror text adventure game

It’s been five years since the aliens invaded earth. We got an early warning of their approach so we were prepared. Shelters were built to house people during the conflict. Unfortunately, due to hubris, the world governments expected to defeat the aliens quickly. As a result the shelters were only intended to last for a decade. Thanks to overcrowding, the supplies have nearly run out. For the past year volunteers have been sent out to collect supplies. You are only the latest.

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

* Install the Extension 'Inform 6' for syntax highlighting.
  <https://marketplace.visualstudio.com/items?itemName=natrium729.inform-6>
* Optionally install the Extension 'IF Player' to play the game in VS code.
  <https://marketplace.visualstudio.com/items?itemName=natrium729.if-player>
* Follow the steps for 'Compiling under Windows' to download the compiler and Library.
* If you are on Linux/Unix update the file `.vscode/settings.json` and remove `.exe` from the setting `inform6.inform6Path`.

## Copyright and License

Created by Jessica McIntosh\
JessicaKMcIntosh AT gmail DOT com

This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License. See the file LICENSE for details.
