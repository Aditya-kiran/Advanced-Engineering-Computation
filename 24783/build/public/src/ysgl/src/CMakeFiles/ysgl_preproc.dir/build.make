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
include public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/depend.make

# Include the progress variables for this target.
include public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/progress.make

# Include the compile flags for this target's objects.
include public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/flags.make

public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/glsl_src/preproc.cpp.o: public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/flags.make
public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/glsl_src/preproc.cpp.o: /home/aditya/24783/src/public/src/ysgl/src/glsl_src/preproc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/glsl_src/preproc.cpp.o"
	cd /home/aditya/24783/build/public/src/ysgl/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ysgl_preproc.dir/glsl_src/preproc.cpp.o -c /home/aditya/24783/src/public/src/ysgl/src/glsl_src/preproc.cpp

public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/glsl_src/preproc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ysgl_preproc.dir/glsl_src/preproc.cpp.i"
	cd /home/aditya/24783/build/public/src/ysgl/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/ysgl/src/glsl_src/preproc.cpp > CMakeFiles/ysgl_preproc.dir/glsl_src/preproc.cpp.i

public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/glsl_src/preproc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ysgl_preproc.dir/glsl_src/preproc.cpp.s"
	cd /home/aditya/24783/build/public/src/ysgl/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/ysgl/src/glsl_src/preproc.cpp -o CMakeFiles/ysgl_preproc.dir/glsl_src/preproc.cpp.s

# Object files for target ysgl_preproc
ysgl_preproc_OBJECTS = \
"CMakeFiles/ysgl_preproc.dir/glsl_src/preproc.cpp.o"

# External object files for target ysgl_preproc
ysgl_preproc_EXTERNAL_OBJECTS =

exe/ysgl_preproc: public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/glsl_src/preproc.cpp.o
exe/ysgl_preproc: public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/build.make
exe/ysgl_preproc: public/src/ysclass/src/libysclass.a
exe/ysgl_preproc: public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../exe/ysgl_preproc"
	cd /home/aditya/24783/build/public/src/ysgl/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ysgl_preproc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/build: exe/ysgl_preproc

.PHONY : public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/build

public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/clean:
	cd /home/aditya/24783/build/public/src/ysgl/src && $(CMAKE_COMMAND) -P CMakeFiles/ysgl_preproc.dir/cmake_clean.cmake
.PHONY : public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/clean

public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/public/src/ysgl/src /home/aditya/24783/build /home/aditya/24783/build/public/src/ysgl/src /home/aditya/24783/build/public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/src/ysgl/src/CMakeFiles/ysgl_preproc.dir/depend

