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
include public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/depend.make

# Include the progress variables for this target.
include public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/progress.make

# Include the compile flags for this target's objects.
include public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/flags.make

public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/linux/ysunixsystemfont.cpp.o: public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/flags.make
public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/linux/ysunixsystemfont.cpp.o: /home/aditya/24783/src/public/src/yssystemfont/src/linux/ysunixsystemfont.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/linux/ysunixsystemfont.cpp.o"
	cd /home/aditya/24783/build/public/src/yssystemfont/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yssystemfont.dir/linux/ysunixsystemfont.cpp.o -c /home/aditya/24783/src/public/src/yssystemfont/src/linux/ysunixsystemfont.cpp

public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/linux/ysunixsystemfont.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yssystemfont.dir/linux/ysunixsystemfont.cpp.i"
	cd /home/aditya/24783/build/public/src/yssystemfont/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/yssystemfont/src/linux/ysunixsystemfont.cpp > CMakeFiles/yssystemfont.dir/linux/ysunixsystemfont.cpp.i

public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/linux/ysunixsystemfont.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yssystemfont.dir/linux/ysunixsystemfont.cpp.s"
	cd /home/aditya/24783/build/public/src/yssystemfont/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/yssystemfont/src/linux/ysunixsystemfont.cpp -o CMakeFiles/yssystemfont.dir/linux/ysunixsystemfont.cpp.s

# Object files for target yssystemfont
yssystemfont_OBJECTS = \
"CMakeFiles/yssystemfont.dir/linux/ysunixsystemfont.cpp.o"

# External object files for target yssystemfont
yssystemfont_EXTERNAL_OBJECTS =

public/src/yssystemfont/src/libyssystemfont.a: public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/linux/ysunixsystemfont.cpp.o
public/src/yssystemfont/src/libyssystemfont.a: public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/build.make
public/src/yssystemfont/src/libyssystemfont.a: public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libyssystemfont.a"
	cd /home/aditya/24783/build/public/src/yssystemfont/src && $(CMAKE_COMMAND) -P CMakeFiles/yssystemfont.dir/cmake_clean_target.cmake
	cd /home/aditya/24783/build/public/src/yssystemfont/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yssystemfont.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/build: public/src/yssystemfont/src/libyssystemfont.a

.PHONY : public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/build

public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/clean:
	cd /home/aditya/24783/build/public/src/yssystemfont/src && $(CMAKE_COMMAND) -P CMakeFiles/yssystemfont.dir/cmake_clean.cmake
.PHONY : public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/clean

public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/public/src/yssystemfont/src /home/aditya/24783/build /home/aditya/24783/build/public/src/yssystemfont/src /home/aditya/24783/build/public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/src/yssystemfont/src/CMakeFiles/yssystemfont.dir/depend

