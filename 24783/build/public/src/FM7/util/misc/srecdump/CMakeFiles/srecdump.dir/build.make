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
include public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/depend.make

# Include the progress variables for this target.
include public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/progress.make

# Include the compile flags for this target's objects.
include public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/flags.make

public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/main.cpp.o: public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/flags.make
public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/main.cpp.o: /home/aditya/24783/src/public/src/FM7/util/misc/srecdump/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/main.cpp.o"
	cd /home/aditya/24783/build/public/src/FM7/util/misc/srecdump && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/srecdump.dir/main.cpp.o -c /home/aditya/24783/src/public/src/FM7/util/misc/srecdump/main.cpp

public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srecdump.dir/main.cpp.i"
	cd /home/aditya/24783/build/public/src/FM7/util/misc/srecdump && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/FM7/util/misc/srecdump/main.cpp > CMakeFiles/srecdump.dir/main.cpp.i

public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srecdump.dir/main.cpp.s"
	cd /home/aditya/24783/build/public/src/FM7/util/misc/srecdump && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/FM7/util/misc/srecdump/main.cpp -o CMakeFiles/srecdump.dir/main.cpp.s

# Object files for target srecdump
srecdump_OBJECTS = \
"CMakeFiles/srecdump.dir/main.cpp.o"

# External object files for target srecdump
srecdump_EXTERNAL_OBJECTS =

exe/srecdump: public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/main.cpp.o
exe/srecdump: public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/build.make
exe/srecdump: public/src/FM7/util/lib/libfm7lib.a
exe/srecdump: public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../../../exe/srecdump"
	cd /home/aditya/24783/build/public/src/FM7/util/misc/srecdump && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/srecdump.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/build: exe/srecdump

.PHONY : public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/build

public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/clean:
	cd /home/aditya/24783/build/public/src/FM7/util/misc/srecdump && $(CMAKE_COMMAND) -P CMakeFiles/srecdump.dir/cmake_clean.cmake
.PHONY : public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/clean

public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/public/src/FM7/util/misc/srecdump /home/aditya/24783/build /home/aditya/24783/build/public/src/FM7/util/misc/srecdump /home/aditya/24783/build/public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/src/FM7/util/misc/srecdump/CMakeFiles/srecdump.dir/depend

