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
include public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/depend.make

# Include the progress variables for this target.
include public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/progress.make

# Include the compile flags for this target's objects.
include public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/flags.make

public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/main.cpp.o: public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/flags.make
public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/main.cpp.o: /home/aditya/24783/src/public/src/fssimplewindow/template/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/main.cpp.o"
	cd /home/aditya/24783/build/public/src/fssimplewindow/template && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fssimplewindow_template.dir/main.cpp.o -c /home/aditya/24783/src/public/src/fssimplewindow/template/main.cpp

public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fssimplewindow_template.dir/main.cpp.i"
	cd /home/aditya/24783/build/public/src/fssimplewindow/template && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/fssimplewindow/template/main.cpp > CMakeFiles/fssimplewindow_template.dir/main.cpp.i

public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fssimplewindow_template.dir/main.cpp.s"
	cd /home/aditya/24783/build/public/src/fssimplewindow/template && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/fssimplewindow/template/main.cpp -o CMakeFiles/fssimplewindow_template.dir/main.cpp.s

# Object files for target fssimplewindow_template
fssimplewindow_template_OBJECTS = \
"CMakeFiles/fssimplewindow_template.dir/main.cpp.o"

# External object files for target fssimplewindow_template
fssimplewindow_template_EXTERNAL_OBJECTS =

public/src/fssimplewindow/template/fssimplewindow_template: public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/main.cpp.o
public/src/fssimplewindow/template/fssimplewindow_template: public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/build.make
public/src/fssimplewindow/template/fssimplewindow_template: public/src/fssimplewindow/src/libfssimplewindow.a
public/src/fssimplewindow/template/fssimplewindow_template: public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fssimplewindow_template"
	cd /home/aditya/24783/build/public/src/fssimplewindow/template && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fssimplewindow_template.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/build: public/src/fssimplewindow/template/fssimplewindow_template

.PHONY : public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/build

public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/clean:
	cd /home/aditya/24783/build/public/src/fssimplewindow/template && $(CMAKE_COMMAND) -P CMakeFiles/fssimplewindow_template.dir/cmake_clean.cmake
.PHONY : public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/clean

public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/public/src/fssimplewindow/template /home/aditya/24783/build /home/aditya/24783/build/public/src/fssimplewindow/template /home/aditya/24783/build/public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/src/fssimplewindow/template/CMakeFiles/fssimplewindow_template.dir/depend

