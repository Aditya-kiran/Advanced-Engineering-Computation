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
include ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/depend.make

# Include the progress variables for this target.
include ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/progress.make

# Include the compile flags for this target's objects.
include ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/flags.make

ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/bintree.cpp.o: ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/flags.make
ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/bintree.cpp.o: /home/aditya/24783/src/ruofanz/bintreeutil/bintree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/bintree.cpp.o"
	cd /home/aditya/24783/build/ruofanz/bintreeutil && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bintreeutil.dir/bintree.cpp.o -c /home/aditya/24783/src/ruofanz/bintreeutil/bintree.cpp

ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/bintree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bintreeutil.dir/bintree.cpp.i"
	cd /home/aditya/24783/build/ruofanz/bintreeutil && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/ruofanz/bintreeutil/bintree.cpp > CMakeFiles/bintreeutil.dir/bintree.cpp.i

ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/bintree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bintreeutil.dir/bintree.cpp.s"
	cd /home/aditya/24783/build/ruofanz/bintreeutil && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/ruofanz/bintreeutil/bintree.cpp -o CMakeFiles/bintreeutil.dir/bintree.cpp.s

# Object files for target bintreeutil
bintreeutil_OBJECTS = \
"CMakeFiles/bintreeutil.dir/bintree.cpp.o"

# External object files for target bintreeutil
bintreeutil_EXTERNAL_OBJECTS =

ruofanz/bintreeutil/libbintreeutil.a: ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/bintree.cpp.o
ruofanz/bintreeutil/libbintreeutil.a: ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/build.make
ruofanz/bintreeutil/libbintreeutil.a: ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libbintreeutil.a"
	cd /home/aditya/24783/build/ruofanz/bintreeutil && $(CMAKE_COMMAND) -P CMakeFiles/bintreeutil.dir/cmake_clean_target.cmake
	cd /home/aditya/24783/build/ruofanz/bintreeutil && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bintreeutil.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/build: ruofanz/bintreeutil/libbintreeutil.a

.PHONY : ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/build

ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/clean:
	cd /home/aditya/24783/build/ruofanz/bintreeutil && $(CMAKE_COMMAND) -P CMakeFiles/bintreeutil.dir/cmake_clean.cmake
.PHONY : ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/clean

ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/ruofanz/bintreeutil /home/aditya/24783/build /home/aditya/24783/build/ruofanz/bintreeutil /home/aditya/24783/build/ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ruofanz/bintreeutil/CMakeFiles/bintreeutil.dir/depend
