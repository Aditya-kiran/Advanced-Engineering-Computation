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
include public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/depend.make

# Include the progress variables for this target.
include public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/progress.make

# Include the compile flags for this target's objects.
include public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/flags.make

public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/yssimplesound.cpp.o: public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/flags.make
public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/yssimplesound.cpp.o: /home/aditya/24783/src/public/src/yssimplesound/src/yssimplesound.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/yssimplesound.cpp.o"
	cd /home/aditya/24783/build/public/src/yssimplesound/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yssimplesound.dir/yssimplesound.cpp.o -c /home/aditya/24783/src/public/src/yssimplesound/src/yssimplesound.cpp

public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/yssimplesound.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yssimplesound.dir/yssimplesound.cpp.i"
	cd /home/aditya/24783/build/public/src/yssimplesound/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/yssimplesound/src/yssimplesound.cpp > CMakeFiles/yssimplesound.dir/yssimplesound.cpp.i

public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/yssimplesound.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yssimplesound.dir/yssimplesound.cpp.s"
	cd /home/aditya/24783/build/public/src/yssimplesound/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/yssimplesound/src/yssimplesound.cpp -o CMakeFiles/yssimplesound.dir/yssimplesound.cpp.s

# Object files for target yssimplesound
yssimplesound_OBJECTS = \
"CMakeFiles/yssimplesound.dir/yssimplesound.cpp.o"

# External object files for target yssimplesound
yssimplesound_EXTERNAL_OBJECTS =

public/src/yssimplesound/src/libyssimplesound.a: public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/yssimplesound.cpp.o
public/src/yssimplesound/src/libyssimplesound.a: public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/build.make
public/src/yssimplesound/src/libyssimplesound.a: public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libyssimplesound.a"
	cd /home/aditya/24783/build/public/src/yssimplesound/src && $(CMAKE_COMMAND) -P CMakeFiles/yssimplesound.dir/cmake_clean_target.cmake
	cd /home/aditya/24783/build/public/src/yssimplesound/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yssimplesound.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/build: public/src/yssimplesound/src/libyssimplesound.a

.PHONY : public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/build

public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/clean:
	cd /home/aditya/24783/build/public/src/yssimplesound/src && $(CMAKE_COMMAND) -P CMakeFiles/yssimplesound.dir/cmake_clean.cmake
.PHONY : public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/clean

public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/public/src/yssimplesound/src /home/aditya/24783/build /home/aditya/24783/build/public/src/yssimplesound/src /home/aditya/24783/build/public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/src/yssimplesound/src/CMakeFiles/yssimplesound.dir/depend
