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
include public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/depend.make

# Include the progress variables for this target.
include public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/progress.make

# Include the compile flags for this target's objects.
include public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/flags.make

public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/ystexturemanager_null.cpp.o: public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/flags.make
public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/ystexturemanager_null.cpp.o: /home/aditya/24783/src/public/src/ystexturemanager/src/null/ystexturemanager_null.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/ystexturemanager_null.cpp.o"
	cd /home/aditya/24783/build/public/src/ystexturemanager/src/null && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ystexturemanager_nownd.dir/ystexturemanager_null.cpp.o -c /home/aditya/24783/src/public/src/ystexturemanager/src/null/ystexturemanager_null.cpp

public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/ystexturemanager_null.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ystexturemanager_nownd.dir/ystexturemanager_null.cpp.i"
	cd /home/aditya/24783/build/public/src/ystexturemanager/src/null && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/ystexturemanager/src/null/ystexturemanager_null.cpp > CMakeFiles/ystexturemanager_nownd.dir/ystexturemanager_null.cpp.i

public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/ystexturemanager_null.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ystexturemanager_nownd.dir/ystexturemanager_null.cpp.s"
	cd /home/aditya/24783/build/public/src/ystexturemanager/src/null && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/ystexturemanager/src/null/ystexturemanager_null.cpp -o CMakeFiles/ystexturemanager_nownd.dir/ystexturemanager_null.cpp.s

# Object files for target ystexturemanager_nownd
ystexturemanager_nownd_OBJECTS = \
"CMakeFiles/ystexturemanager_nownd.dir/ystexturemanager_null.cpp.o"

# External object files for target ystexturemanager_nownd
ystexturemanager_nownd_EXTERNAL_OBJECTS =

public/src/ystexturemanager/src/null/libystexturemanager_nownd.a: public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/ystexturemanager_null.cpp.o
public/src/ystexturemanager/src/null/libystexturemanager_nownd.a: public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/build.make
public/src/ystexturemanager/src/null/libystexturemanager_nownd.a: public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libystexturemanager_nownd.a"
	cd /home/aditya/24783/build/public/src/ystexturemanager/src/null && $(CMAKE_COMMAND) -P CMakeFiles/ystexturemanager_nownd.dir/cmake_clean_target.cmake
	cd /home/aditya/24783/build/public/src/ystexturemanager/src/null && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ystexturemanager_nownd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/build: public/src/ystexturemanager/src/null/libystexturemanager_nownd.a

.PHONY : public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/build

public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/clean:
	cd /home/aditya/24783/build/public/src/ystexturemanager/src/null && $(CMAKE_COMMAND) -P CMakeFiles/ystexturemanager_nownd.dir/cmake_clean.cmake
.PHONY : public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/clean

public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/public/src/ystexturemanager/src/null /home/aditya/24783/build /home/aditya/24783/build/public/src/ystexturemanager/src/null /home/aditya/24783/build/public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/src/ystexturemanager/src/null/CMakeFiles/ystexturemanager_nownd.dir/depend

