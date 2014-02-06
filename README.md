SickleblowOne
=============

This was going to be a big game, but it ended up in just me learning. I did tell the artists to go 2D!

The graphics do not accurately match what's happening. This project isn't finished and probably won't
ever be. Unless I really get back into game development but it doesn't look like that's gonna happen.

Building
========

Standard CMake procedure. You'll need Ogre3D and Chipmunk Physics.

```bash
mkdir build
cd build
cmake-gui .. #now configure your variables
make && make install
```
You should set the installation directory to the dist/ subdirectory to have the game find the media
files.

It also compiles with MinGW on Windows, use the MSys shell and the same process. CMake is supposed to
build with MSVC++ too, and there's a MSVC++ Ogre3D version, but I haven't tested it.

Playing
=======

Arrows walk, space jumps.
