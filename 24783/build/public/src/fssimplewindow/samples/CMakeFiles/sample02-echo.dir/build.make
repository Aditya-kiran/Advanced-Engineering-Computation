# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aditya/24783/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aditya/24783/build

# Include any dependencies generated for this target.
include public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/depend.make

# Include the progress variables for this target.
include public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/progress.make

# Include the compile flags for this target's objects.
include public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/flags.make

public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/sample02-echo/sample02-echo.cpp.o: public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/flags.make
public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/sample02-echo/sample02-echo.cpp.o: /home/aditya/24783/src/public/src/fssimplewindow/samples/sample02-echo/sample02-echo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/sample02-echo/sample02-echo.cpp.o"
	cd /home/aditya/24783/build/public/src/fssimplewindow/samples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample02-echo.dir/sample02-echo/sample02-echo.cpp.o -c /home/aditya/24783/src/public/src/fssimplewindow/samples/sample02-echo/sample02-echo.cpp

public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/sample02-echo/sample02-echo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample02-echo.dir/sample02-echo/sample02-echo.cpp.i"
	cd /home/aditya/24783/build/public/src/fssimplewindow/samples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/fssimplewindow/samples/sample02-echo/sample02-echo.cpp > CMakeFiles/sample02-echo.dir/sample02-echo/sample02-echo.cpp.i

public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/sample02-echo/sample02-echo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample02-echo.dir/sample02-echo/sample02-echo.cpp.s"
	cd /home/aditya/24783/build/public/src/fssimplewindow/samples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/fssimplewindow/samples/sample02-echo/sample02-echo.cpp -o CMakeFiles/sample02-echo.dir/sample02-echo/sample02-echo.cpp.s

# Object files for target sample02-echo
sample02__echo_OBJECTS = \
"CMakeFiles/sample02-echo.dir/sample02-echo/sample02-echo.cpp.o"

# External object files for target sample02-echo
sample02__echo_EXTERNAL_OBJECTS =

public/src/fssimplewindow/samples/sample02-echo: public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/sample02-echo/sample02-echo.cpp.o
public/src/fssimplewindow/samples/sample02-echo: public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/build.make
public/src/fssimplewindow/samples/sample02-echo: public/src/fssimplewindow/src/libfssimplewindow.a
public/src/fssimplewindow/samples/sample02-echo: public/src/ysbitmapfont/src/libysbitmapfont.a
public/src/fssimplewindow/samples/sample02-echo: public/src/ysgl/src/libysgl.a
public/src/fssimplewindow/samples/sample02-echo: public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sample02-echo"
	cd /home/aditya/24783/build/public/src/fssimplewindow/samples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sample02-echo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/build: public/src/fssimplewindow/samples/sample02-echo

.PHONY : public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/build

public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/clean:
	cd /home/aditya/24783/build/public/src/fssimplewindow/samples && $(CMAKE_COMMAND) -P CMakeFiles/sample02-echo.dir/cmake_clean.cmake
.PHONY : public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/clean

public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/public/src/fssimplewindow/samples /home/aditya/24783/build /home/aditya/24783/build/public/src/fssimplewindow/samples /home/aditya/24783/build/public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/src/fssimplewindow/samples/CMakeFiles/sample02-echo.dir/depend
