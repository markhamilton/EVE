Eve Flight Simulator
====================

Test planes and spacecraft in a fully simulated physical environment. This project is in its early stages and is not usable at present.

Eve is meant to run on any desktop platform to provide visual or fully-automated simulations of spacecraft flight. Batch test simulations monte-carlo style faster than realtime, or take your vessel out for a test run.

## Roadmap

The current plans with the software are to:

1. Visualize ground-level and outerspace scenery nearly photorealistically.
2. Provide a simulated physics sandbox for you to test space flight in.
3. Import and export parametric testing data.
4. Take part in first-person test flights or perform batch simulations.
5. Graphical interface using OpenGL and command-line interface using ncurses.
6. Send simulated sensor output interface to an 8086 emulator running your flight control software.
7. Plug in live flight hardware to test hardware logic.
8. Use physical switches and VR head mounted displays (HMD) to get a realistic test drive.
9. Realistic planetary and atmospheric simulations using publicly available data.
10. Multiple visualization modes for satellites, planes, spacecraft, and more.
11. ✓Premake script to compile for a variety of platforms and work with most IDEs. (Visual Studio/Windows builds not tested.)
12. Extension via Lua scripting.
13. Provide pre-built binaries to make EveFS available for everyone.

## Dependencies

* OpenGL support
* GLFW (Included under `external/`)
* [Premake4](http://industriousone.com/premake/download)

## How to Build

This guide is heavily geared towards building on Linux. If you have any improvements to the premake script or procedures for building on Windows, I will gladly accept pull requests to fix this process.

That said, make sure you have the dependencies listed above. 

### RUNNING PREMAKE

There is a `premake4.lua` script in the `support` folder. This can generate project files for most major IDEs. Type `premake4 --help` from the command line to see output options.

To generate project files for Visual Studio 2010, type:

	premake4 vs2010

There will be a new folder called `vs2010` and the `.sln` and `.cproj` files will be in there for you. Open and hit F5 to build.

I usually keep the code::blocks projects and GNU make build files all up to date; those are in their respective folders under `support`. Open the `support/codeblocks/EVE.workspace` file in order to open the project in codeblocks, or `cd` to the `gmake` folder to build from a Makefile.
