# CMake tool for creating project files from source code (C++)

A great number of projects written in C++ are being written so they could execute on multiple platforms. To ensure that the source code for these projects is successfully compiled for the appropriate platform, developers need to define special set of commands for each of those platforms. For example, to compile code on Unix systems, one could use the [Makefile system](https://en.wikipedia.org/wiki/Makefile) or [Visual Studio development toolset](https://visualstudio.microsoft.com/) on Windows operating systems. 

However, the problem that we are encounting is that for each of these compilation systems (and sometimes even between the versions), we need to create a specific set of files, so that we can use one set to compile project on Unix, and another set to compile it on Windows. For the first mentioned system, we need to create files called `Makefile` in the project folder, and for the second one, we need to generate different `.sln` and `.vcproj` files, among others. As you can imagine, this is a cumbersome job that no one wants to do. However, there is another problem and that is the polution of the version control system with "unnecessary" files. [CMake](https://cmake.org/) tool that I will be describing in this article works in a way which solves all of the mentioned problems, and at the same time generate the files for the appropriate compilation system, on a certain platform.

## Description of the C++ project

We are going to create an application which loads a JPEG colored image, and constructs a black and white image from it. To do this, we will use some modules from [stb library](https://github.com/nothings/stb/), mainly `stb_image` and `stb_image_write`. Our application will simply use the functions provided by this library since the point of this article is learning how to connect third-party libraries with our application, and not image processing :) The structure of our project folder looks like this:

```
cmake-tutorial/                 # Root of a project directory
    bin/                        # Executable code
    build/                      # Compilation system files
    resources/                  # Resources for testing the application
        leaves.jpeg
        CMakeLists.txt          # A recipe for installing the resources
    src/                        # Application source code
        app.cpp
    thirdparty/                 # Third-party library's source code
        include/
            stb_image.h
            stb_image_write.h
        source/
            stb_image.cpp
            stb_image_write.cpp
        CMakeLists.txt          # A recipe for creating a third-party library
    CMakeLists.txt              # A recipe for creating an app
    build.sh                    # A script for automating the process for Unix
```
