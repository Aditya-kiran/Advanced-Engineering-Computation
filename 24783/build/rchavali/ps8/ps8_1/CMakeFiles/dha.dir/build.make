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
include rchavali/ps8/ps8_1/CMakeFiles/dha.dir/depend.make

# Include the progress variables for this target.
include rchavali/ps8/ps8_1/CMakeFiles/dha.dir/progress.make

# Include the compile flags for this target's objects.
include rchavali/ps8/ps8_1/CMakeFiles/dha.dir/flags.make

rchavali/ps8/ps8_1/CMakeFiles/dha.dir/dha.cpp.o: rchavali/ps8/ps8_1/CMakeFiles/dha.dir/flags.make
rchavali/ps8/ps8_1/CMakeFiles/dha.dir/dha.cpp.o: /home/aditya/24783/src/rchavali/ps8/ps8_1/dha.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object rchavali/ps8/ps8_1/CMakeFiles/dha.dir/dha.cpp.o"
	cd /home/aditya/24783/build/rchavali/ps8/ps8_1 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dha.dir/dha.cpp.o -c /home/aditya/24783/src/rchavali/ps8/ps8_1/dha.cpp

rchavali/ps8/ps8_1/CMakeFiles/dha.dir/dha.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dha.dir/dha.cpp.i"
	cd /home/aditya/24783/build/rchavali/ps8/ps8_1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/rchavali/ps8/ps8_1/dha.cpp > CMakeFiles/dha.dir/dha.cpp.i

rchavali/ps8/ps8_1/CMakeFiles/dha.dir/dha.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dha.dir/dha.cpp.s"
	cd /home/aditya/24783/build/rchavali/ps8/ps8_1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/rchavali/ps8/ps8_1/dha.cpp -o CMakeFiles/dha.dir/dha.cpp.s

# Object files for target dha
dha_OBJECTS = \
"CMakeFiles/dha.dir/dha.cpp.o"

# External object files for target dha
dha_EXTERNAL_OBJECTS =

rchavali/ps8/ps8_1/libdha.a: rchavali/ps8/ps8_1/CMakeFiles/dha.dir/dha.cpp.o
rchavali/ps8/ps8_1/libdha.a: rchavali/ps8/ps8_1/CMakeFiles/dha.dir/build.make
rchavali/ps8/ps8_1/libdha.a: rchavali/ps8/ps8_1/CMakeFiles/dha.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libdha.a"
	cd /home/aditya/24783/build/rchavali/ps8/ps8_1 && $(CMAKE_COMMAND) -P CMakeFiles/dha.dir/cmake_clean_target.cmake
	cd /home/aditya/24783/build/rchavali/ps8/ps8_1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dha.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rchavali/ps8/ps8_1/CMakeFiles/dha.dir/build: rchavali/ps8/ps8_1/libdha.a

.PHONY : rchavali/ps8/ps8_1/CMakeFiles/dha.dir/build

rchavali/ps8/ps8_1/CMakeFiles/dha.dir/clean:
	cd /home/aditya/24783/build/rchavali/ps8/ps8_1 && $(CMAKE_COMMAND) -P CMakeFiles/dha.dir/cmake_clean.cmake
.PHONY : rchavali/ps8/ps8_1/CMakeFiles/dha.dir/clean

rchavali/ps8/ps8_1/CMakeFiles/dha.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/rchavali/ps8/ps8_1 /home/aditya/24783/build /home/aditya/24783/build/rchavali/ps8/ps8_1 /home/aditya/24783/build/rchavali/ps8/ps8_1/CMakeFiles/dha.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : rchavali/ps8/ps8_1/CMakeFiles/dha.dir/depend

