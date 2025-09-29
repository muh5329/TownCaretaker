## TownCareTaker


## Roadmap

## Change Log

001:

## Docs


## Prequisites



## Folder Structure 

```sh
    Root/
        /lib # Libraries
            /raylib.h
        /bin # Build folder
        /src # App Source
        /assets # Assets - images, sounds, 3D models etc.

```


## Raylib MACosx Mac setup abridged

[src](https://github.com/jalder89/raylib-macos-template-arm-cpp)

1. Clone https://github.com/raysan5/raylib
2. Run make from raylib/src
3. Create template folder with lib - bin - src - assets
4. Copy libraylib.a , raymath.h , raymath.h to lib
5. Base main.ccp
```c
#include <raylib.h>
#include <raymath.h>

int main()
{
	InitWindow(400, 224, "Template-4.0.0");
	
	while (!WindowShouldClose()) {
        	BeginDrawing();
            	ClearBackground(RAYWHITE);
    
        	EndDrawing();
    	}
   	 CloseWindow();
   	 return 0;
}
```
6. Base Make File
    IMPORTANT NOTE: build recipes (build_osx) must be spaced using a tab character, copy/pasting Markdown tends to convert tabs to spaces:
```Makefile
COMPILER = clang++
SOURCE_LIBS = -Ilib/
MACOS_OPT = -std=c++17 -Llib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a
MACOS_OUT = -o "bin/build_osx"
CFILES = src/*.cpp

build_osx:
    $(COMPILER) $(CFILES) $(SOURCE_LIBS) $(MACOS_OUT) $(MACOS_OPT)
```
7. In vscode main.cpp  press F5 switch to clang++, includes 
    .vscode
        /launch.json'
        /settings.json
        /tasks.json
8.  In tasks.json change:
```json
{
    "tasks": [
        {
            "type": "shell",
            "label": "Build OSX",
            "command": "make build_osx",
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "detail": "Raylib Debugger."
        }
    ],
    "version": "2.0.0"
}
```
9. In launch.json:
```sh
{
    "configurations": [
        {
            "name": "(lldb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/bin/build_osx",
            "cwd": "${workspaceFolder}",
            // This is to ensure VScode prints the program log in the debug console
            "internalConsoleOptions": "openOnSessionStart", 
            "MIMode": "lldb",
            "preLaunchTask": "Build OSX"
            }
    ],
    "version": "2.0.0"
}
```
10. In c_cpp_properties.json ( add if does not exist):
```json
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "macFrameworkPath": [
                "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks"
            ],
            "compilerPath": "/usr/bin/clang++",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "macos-clang-arm64"
        }
    ],
    "version": 4
}
```