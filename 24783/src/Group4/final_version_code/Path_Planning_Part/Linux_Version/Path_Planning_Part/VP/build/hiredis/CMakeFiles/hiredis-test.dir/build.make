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
CMAKE_SOURCE_DIR = /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/build

# Include any dependencies generated for this target.
include hiredis/CMakeFiles/hiredis-test.dir/depend.make

# Include the progress variables for this target.
include hiredis/CMakeFiles/hiredis-test.dir/progress.make

# Include the compile flags for this target's objects.
include hiredis/CMakeFiles/hiredis-test.dir/flags.make

hiredis/CMakeFiles/hiredis-test.dir/test.c.o: hiredis/CMakeFiles/hiredis-test.dir/flags.make
hiredis/CMakeFiles/hiredis-test.dir/test.c.o: ../hiredis/test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object hiredis/CMakeFiles/hiredis-test.dir/test.c.o"
	cd /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/build/hiredis && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hiredis-test.dir/test.c.o   -c /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/hiredis/test.c

hiredis/CMakeFiles/hiredis-test.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hiredis-test.dir/test.c.i"
	cd /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/build/hiredis && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/hiredis/test.c > CMakeFiles/hiredis-test.dir/test.c.i

hiredis/CMakeFiles/hiredis-test.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hiredis-test.dir/test.c.s"
	cd /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/build/hiredis && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/hiredis/test.c -o CMakeFiles/hiredis-test.dir/test.c.s

# Object files for target hiredis-test
hiredis__test_OBJECTS = \
"CMakeFiles/hiredis-test.dir/test.c.o"

# External object files for target hiredis-test
hiredis__test_EXTERNAL_OBJECTS =

hiredis/hiredis-test: hiredis/CMakeFiles/hiredis-test.dir/test.c.o
hiredis/hiredis-test: hiredis/CMakeFiles/hiredis-test.dir/build.make
hiredis/hiredis-test: hiredis/libhiredis.so.0.14
hiredis/hiredis-test: hiredis/CMakeFiles/hiredis-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable hiredis-test"
	cd /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/build/hiredis && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hiredis-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hiredis/CMakeFiles/hiredis-test.dir/build: hiredis/hiredis-test

.PHONY : hiredis/CMakeFiles/hiredis-test.dir/build

hiredis/CMakeFiles/hiredis-test.dir/clean:
	cd /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/build/hiredis && $(CMAKE_COMMAND) -P CMakeFiles/hiredis-test.dir/cmake_clean.cmake
.PHONY : hiredis/CMakeFiles/hiredis-test.dir/clean

hiredis/CMakeFiles/hiredis-test.dir/depend:
	cd /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/hiredis /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/build /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/build/hiredis /home/aditya/24783/src/Group4/final_version_code/Path_Planning_Part/Linux_Version/Path_Planning_Part/VP/build/hiredis/CMakeFiles/hiredis-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : hiredis/CMakeFiles/hiredis-test.dir/depend
