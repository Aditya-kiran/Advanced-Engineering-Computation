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
include public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/depend.make

# Include the progress variables for this target.
include public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/progress.make

# Include the compile flags for this target's objects.
include public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/flags.make

public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/ys_bitmap_command_base.cpp.o: public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/flags.make
public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/ys_bitmap_command_base.cpp.o: /home/aditya/24783/src/public/src/ysbitmap/cmdtools/ys_bitmap_command_base.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/ys_bitmap_command_base.cpp.o"
	cd /home/aditya/24783/build/public/src/ysbitmap/cmdtools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ys_bitmap_command_base.dir/ys_bitmap_command_base.cpp.o -c /home/aditya/24783/src/public/src/ysbitmap/cmdtools/ys_bitmap_command_base.cpp

public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/ys_bitmap_command_base.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ys_bitmap_command_base.dir/ys_bitmap_command_base.cpp.i"
	cd /home/aditya/24783/build/public/src/ysbitmap/cmdtools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/ysbitmap/cmdtools/ys_bitmap_command_base.cpp > CMakeFiles/ys_bitmap_command_base.dir/ys_bitmap_command_base.cpp.i

public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/ys_bitmap_command_base.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ys_bitmap_command_base.dir/ys_bitmap_command_base.cpp.s"
	cd /home/aditya/24783/build/public/src/ysbitmap/cmdtools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/ysbitmap/cmdtools/ys_bitmap_command_base.cpp -o CMakeFiles/ys_bitmap_command_base.dir/ys_bitmap_command_base.cpp.s

# Object files for target ys_bitmap_command_base
ys_bitmap_command_base_OBJECTS = \
"CMakeFiles/ys_bitmap_command_base.dir/ys_bitmap_command_base.cpp.o"

# External object files for target ys_bitmap_command_base
ys_bitmap_command_base_EXTERNAL_OBJECTS =

exe/ys_bitmap_command_base: public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/ys_bitmap_command_base.cpp.o
exe/ys_bitmap_command_base: public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/build.make
exe/ys_bitmap_command_base: public/src/ysclass/src/libysclass.a
exe/ys_bitmap_command_base: public/src/ysbitmap/src/libysbitmap.a
exe/ys_bitmap_command_base: public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../exe/ys_bitmap_command_base"
	cd /home/aditya/24783/build/public/src/ysbitmap/cmdtools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ys_bitmap_command_base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/build: exe/ys_bitmap_command_base

.PHONY : public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/build

public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/clean:
	cd /home/aditya/24783/build/public/src/ysbitmap/cmdtools && $(CMAKE_COMMAND) -P CMakeFiles/ys_bitmap_command_base.dir/cmake_clean.cmake
.PHONY : public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/clean

public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/public/src/ysbitmap/cmdtools /home/aditya/24783/build /home/aditya/24783/build/public/src/ysbitmap/cmdtools /home/aditya/24783/build/public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/src/ysbitmap/cmdtools/CMakeFiles/ys_bitmap_command_base.dir/depend

