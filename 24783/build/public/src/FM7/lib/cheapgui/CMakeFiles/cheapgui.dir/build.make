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
include public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/depend.make

# Include the progress variables for this target.
include public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/progress.make

# Include the compile flags for this target's objects.
include public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/flags.make

public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/gui.cpp.o: public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/flags.make
public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/gui.cpp.o: /home/aditya/24783/src/public/src/FM7/lib/cheapgui/gui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/gui.cpp.o"
	cd /home/aditya/24783/build/public/src/FM7/lib/cheapgui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cheapgui.dir/gui.cpp.o -c /home/aditya/24783/src/public/src/FM7/lib/cheapgui/gui.cpp

public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cheapgui.dir/gui.cpp.i"
	cd /home/aditya/24783/build/public/src/FM7/lib/cheapgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/FM7/lib/cheapgui/gui.cpp > CMakeFiles/cheapgui.dir/gui.cpp.i

public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cheapgui.dir/gui.cpp.s"
	cd /home/aditya/24783/build/public/src/FM7/lib/cheapgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/FM7/lib/cheapgui/gui.cpp -o CMakeFiles/cheapgui.dir/gui.cpp.s

public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/gui_gl2.cpp.o: public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/flags.make
public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/gui_gl2.cpp.o: /home/aditya/24783/src/public/src/FM7/lib/cheapgui/gui_gl2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/gui_gl2.cpp.o"
	cd /home/aditya/24783/build/public/src/FM7/lib/cheapgui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cheapgui.dir/gui_gl2.cpp.o -c /home/aditya/24783/src/public/src/FM7/lib/cheapgui/gui_gl2.cpp

public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/gui_gl2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cheapgui.dir/gui_gl2.cpp.i"
	cd /home/aditya/24783/build/public/src/FM7/lib/cheapgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/FM7/lib/cheapgui/gui_gl2.cpp > CMakeFiles/cheapgui.dir/gui_gl2.cpp.i

public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/gui_gl2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cheapgui.dir/gui_gl2.cpp.s"
	cd /home/aditya/24783/build/public/src/FM7/lib/cheapgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/FM7/lib/cheapgui/gui_gl2.cpp -o CMakeFiles/cheapgui.dir/gui_gl2.cpp.s

# Object files for target cheapgui
cheapgui_OBJECTS = \
"CMakeFiles/cheapgui.dir/gui.cpp.o" \
"CMakeFiles/cheapgui.dir/gui_gl2.cpp.o"

# External object files for target cheapgui
cheapgui_EXTERNAL_OBJECTS =

public/src/FM7/lib/cheapgui/libcheapgui.a: public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/gui.cpp.o
public/src/FM7/lib/cheapgui/libcheapgui.a: public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/gui_gl2.cpp.o
public/src/FM7/lib/cheapgui/libcheapgui.a: public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/build.make
public/src/FM7/lib/cheapgui/libcheapgui.a: public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libcheapgui.a"
	cd /home/aditya/24783/build/public/src/FM7/lib/cheapgui && $(CMAKE_COMMAND) -P CMakeFiles/cheapgui.dir/cmake_clean_target.cmake
	cd /home/aditya/24783/build/public/src/FM7/lib/cheapgui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cheapgui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/build: public/src/FM7/lib/cheapgui/libcheapgui.a

.PHONY : public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/build

public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/clean:
	cd /home/aditya/24783/build/public/src/FM7/lib/cheapgui && $(CMAKE_COMMAND) -P CMakeFiles/cheapgui.dir/cmake_clean.cmake
.PHONY : public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/clean

public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/public/src/FM7/lib/cheapgui /home/aditya/24783/build /home/aditya/24783/build/public/src/FM7/lib/cheapgui /home/aditya/24783/build/public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/src/FM7/lib/cheapgui/CMakeFiles/cheapgui.dir/depend

