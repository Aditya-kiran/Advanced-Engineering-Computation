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
include rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/depend.make

# Include the progress variables for this target.
include rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/progress.make

# Include the compile flags for this target's objects.
include rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/flags.make

rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/main.cpp.o: rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/flags.make
rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/main.cpp.o: /home/aditya/24783/src/rchavali/ps3/flythrough/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/main.cpp.o"
	cd /home/aditya/24783/build/rchavali/ps3/flythrough && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flythrough.dir/main.cpp.o -c /home/aditya/24783/src/rchavali/ps3/flythrough/main.cpp

rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flythrough.dir/main.cpp.i"
	cd /home/aditya/24783/build/rchavali/ps3/flythrough && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/rchavali/ps3/flythrough/main.cpp > CMakeFiles/flythrough.dir/main.cpp.i

rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flythrough.dir/main.cpp.s"
	cd /home/aditya/24783/build/rchavali/ps3/flythrough && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/rchavali/ps3/flythrough/main.cpp -o CMakeFiles/flythrough.dir/main.cpp.s

# Object files for target flythrough
flythrough_OBJECTS = \
"CMakeFiles/flythrough.dir/main.cpp.o"

# External object files for target flythrough
flythrough_EXTERNAL_OBJECTS =

rchavali/ps3/flythrough/flythrough: rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/main.cpp.o
rchavali/ps3/flythrough/flythrough: rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/build.make
rchavali/ps3/flythrough/flythrough: public/src/fslazywindow/src/libfslazywindow.a
rchavali/ps3/flythrough/flythrough: public/src/fssimplewindow/src/libfssimplewindow.a
rchavali/ps3/flythrough/flythrough: rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable flythrough"
	cd /home/aditya/24783/build/rchavali/ps3/flythrough && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flythrough.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/build: rchavali/ps3/flythrough/flythrough

.PHONY : rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/build

rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/clean:
	cd /home/aditya/24783/build/rchavali/ps3/flythrough && $(CMAKE_COMMAND) -P CMakeFiles/flythrough.dir/cmake_clean.cmake
.PHONY : rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/clean

rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/rchavali/ps3/flythrough /home/aditya/24783/build /home/aditya/24783/build/rchavali/ps3/flythrough /home/aditya/24783/build/rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : rchavali/ps3/flythrough/CMakeFiles/flythrough.dir/depend

