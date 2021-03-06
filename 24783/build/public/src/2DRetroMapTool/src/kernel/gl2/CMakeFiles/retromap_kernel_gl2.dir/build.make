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
include public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/depend.make

# Include the progress variables for this target.
include public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/progress.make

# Include the compile flags for this target's objects.
include public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/flags.make

public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/retromap_data_render.cpp.o: public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/flags.make
public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/retromap_data_render.cpp.o: /home/aditya/24783/src/public/src/2DRetroMapTool/src/kernel/gl2/retromap_data_render.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/retromap_data_render.cpp.o"
	cd /home/aditya/24783/build/public/src/2DRetroMapTool/src/kernel/gl2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/retromap_kernel_gl2.dir/retromap_data_render.cpp.o -c /home/aditya/24783/src/public/src/2DRetroMapTool/src/kernel/gl2/retromap_data_render.cpp

public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/retromap_data_render.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/retromap_kernel_gl2.dir/retromap_data_render.cpp.i"
	cd /home/aditya/24783/build/public/src/2DRetroMapTool/src/kernel/gl2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/2DRetroMapTool/src/kernel/gl2/retromap_data_render.cpp > CMakeFiles/retromap_kernel_gl2.dir/retromap_data_render.cpp.i

public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/retromap_data_render.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/retromap_kernel_gl2.dir/retromap_data_render.cpp.s"
	cd /home/aditya/24783/build/public/src/2DRetroMapTool/src/kernel/gl2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/2DRetroMapTool/src/kernel/gl2/retromap_data_render.cpp -o CMakeFiles/retromap_kernel_gl2.dir/retromap_data_render.cpp.s

# Object files for target retromap_kernel_gl2
retromap_kernel_gl2_OBJECTS = \
"CMakeFiles/retromap_kernel_gl2.dir/retromap_data_render.cpp.o"

# External object files for target retromap_kernel_gl2
retromap_kernel_gl2_EXTERNAL_OBJECTS =

public/src/2DRetroMapTool/src/kernel/gl2/libretromap_kernel_gl2.a: public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/retromap_data_render.cpp.o
public/src/2DRetroMapTool/src/kernel/gl2/libretromap_kernel_gl2.a: public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/build.make
public/src/2DRetroMapTool/src/kernel/gl2/libretromap_kernel_gl2.a: public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libretromap_kernel_gl2.a"
	cd /home/aditya/24783/build/public/src/2DRetroMapTool/src/kernel/gl2 && $(CMAKE_COMMAND) -P CMakeFiles/retromap_kernel_gl2.dir/cmake_clean_target.cmake
	cd /home/aditya/24783/build/public/src/2DRetroMapTool/src/kernel/gl2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/retromap_kernel_gl2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/build: public/src/2DRetroMapTool/src/kernel/gl2/libretromap_kernel_gl2.a

.PHONY : public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/build

public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/clean:
	cd /home/aditya/24783/build/public/src/2DRetroMapTool/src/kernel/gl2 && $(CMAKE_COMMAND) -P CMakeFiles/retromap_kernel_gl2.dir/cmake_clean.cmake
.PHONY : public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/clean

public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/public/src/2DRetroMapTool/src/kernel/gl2 /home/aditya/24783/build /home/aditya/24783/build/public/src/2DRetroMapTool/src/kernel/gl2 /home/aditya/24783/build/public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/src/2DRetroMapTool/src/kernel/gl2/CMakeFiles/retromap_kernel_gl2.dir/depend

