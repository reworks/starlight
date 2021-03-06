# galaxy
[![Windows](https://ci.appveyor.com/api/projects/status/ww31j6b22u7bo1ua?svg=true)](https://ci.appveyor.com/project/reworks/galaxy)
[![Documentation Status](https://travis-ci.org/DomRe/galaxy.svg?branch=master)](https://domre.github.io/galaxy/)
[![Code Quality](https://api.codacy.com/project/badge/Grade/1cac439022e2417fa82b5dbc2c320030)](https://www.codacy.com/manual/DomRe/galaxy?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=DomRe/galaxy&amp;utm_campaign=Badge_Grade)
[![CII Best Practices](https://bestpractices.coreinfrastructure.org/projects/4377/badge)](https://bestpractices.coreinfrastructure.org/projects/4377)
[![Apache 2.0 Licensed](https://img.shields.io/badge/license-apache-blue.svg)](./LICENSE.txt)

Application Programming Library using C++20, with a Data driven design and Test driven development.

![galaxy](logo.png?raw=true "galaxy")

## Supercluster - Application Builder/Editor for Galaxy.

![supercluster](editor.png?raw=true "supercluster")

## Building
Only supports 64bit systems.

### Windows:
You will need to install ```Visual Studio 2019 16.10 Preview 1```, and set the ```Win-SDK``` version to ```10.0.19041.0``` (minimum).

Make sure C++ desktop development, cmake tools, linux development, and game development with C++ are enabled when installing.
```
git clone --recursive https://github.com/DomRe/galaxy.git galaxy_engine
git submodule update --init --recursive
cd galaxy_engine
cmake -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Release -DGALAXY_BUILD_TESTS=ON -DGALAXY_ENABLE_DOXYGEN=OFF -Bbuild -H.
cd build
msbuild galaxy_engine.sln
```
OR open ```galaxy_engine.sln``` and press F5 to build.

### Linux:
```
Coming soon.
```

## Documentation
See [online documentation](https://domre.github.io/galaxy/).

Or generate offline with Doxygen, with ```ENABLE_DOXYGEN``` set to ```ON```:
```
cmake -DGALAXY_ENABLE_DOXYGEN=ON -Bbuild -H.
cd build
make doxygen
```


## Features
- Uses Modern C++ design principles, built on C++20.
- Tiled map editor parsing.
- Modern Core OpenGL renderer.
- Platform abstraction.
- Audio streaming.
- Entity component System.
- Fast Logging.
- Physics Engine.
- Event Dispatcher.
- JSON support.
- Lua Scripting.
- GUI.
- Development Toolset.
- Resource Management.
- Filesystem Management.
- Application Management.


### Tiled Implementation.
* Supported:
	* Tiled 1.4.3 .json maps.
	* Loading maps from Tiled Worlds.
	* Base64 encoding.
	* zlib compression.
	* gzip compression.
* Limitations:
	* Only renders right-down maps.
	* Only renders topdown objects.
* Unsupported:
	* Tiled projects.
	* External Tiled assets.
	* Text objects.
	* Terrain.
	* Wang-Sets.
	* Tile Flipping.


## Contributing / Feedback / Issues
Feel free to open an issue for feedback, bug reports, ehancements, issues, etc,
and pull requests for contributions. (Don't forget to add yourself to the credits section below.)


### Credits
* [doxygen-dark-theme](https://github.com/MaJerle/doxygen-dark-theme).
* [sercode.ttf](http://www.dafont.com/secret-code.font).
	* Used in logo.png & logo_docs.png.
* [galaxy image](https://www.nasa.gov/image-feature/goddard/2020/hubble-probes-colorful-galaxy).
	* Image Credit: ESA/Hubble & NASA, A. Filippenko.
	* See [NASA media guidelines](https://www.nasa.gov/multimedia/guidelines/index.html).
	* Used for non-commerical purposes.
* [supercluster icon.png](https://images.nasa.gov/details-PIA17241).
    * Image Credit: NASA/JPL-Caltech/University of Wisconsin
    * See [NASA media guidelines](https://www.nasa.gov/multimedia/guidelines/index.html).
	* Used for non-commerical purposes.
* Any "dependency" i.e. "software library" will have an associated LICENSE.txt/COPYING.txt file included.
* Resources used in sandbox:
	* Various from [OpenGameArt](https://opengameart.org/). No copyright infringement intended.
* https://learnopengl.com/
* https://skypjack.github.io/2019-02-14-ecs-baf-part-1/.
* https://skypjack.github.io/2019-03-21-ecs-baf-part-2-insights/.
* https://skypjack.github.io/2019-09-25-ecs-baf-part-5/.
* https://www.computist.xyz/2018/06/sparse-sets.html.
* https://www.geeksforgeeks.org/sparse-set/.
* https://indiegamedev.net/2020/02/25/the-complete-guide-to-openal-with-c-part-2-streaming-audio/
* https://indiegamedev.net/2020/01/16/how-to-stream-ogg-files-with-openal-in-c/
* https://gist.github.com/tilkinsc/f91d2a74cff62cc3760a7c9291290b29
* https://github.com/zemasoft/clangformat-cmake
* https://github.com/ocornut/imgui/issues/707
* https://github.com/SSBMTonberry/tileson/
* https://github.com/RandyGaul/cute_headers/