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
include public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/depend.make

# Include the progress variables for this target.
include public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/progress.make

# Include the compile flags for this target's objects.
include public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/flags.make

public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/main.cpp.o: public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/flags.make
public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/main.cpp.o: /home/aditya/24783/src/public/src/FM7/util/RS232CDiskBios/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/main.cpp.o"
	cd /home/aditya/24783/build/public/src/FM7/util/RS232CDiskBios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RS232CDiskBios.dir/main.cpp.o -c /home/aditya/24783/src/public/src/FM7/util/RS232CDiskBios/main.cpp

public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RS232CDiskBios.dir/main.cpp.i"
	cd /home/aditya/24783/build/public/src/FM7/util/RS232CDiskBios && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/FM7/util/RS232CDiskBios/main.cpp > CMakeFiles/RS232CDiskBios.dir/main.cpp.i

public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RS232CDiskBios.dir/main.cpp.s"
	cd /home/aditya/24783/build/public/src/FM7/util/RS232CDiskBios && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/FM7/util/RS232CDiskBios/main.cpp -o CMakeFiles/RS232CDiskBios.dir/main.cpp.s

public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/disk_bios_hook_client.cpp.o: public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/flags.make
public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/disk_bios_hook_client.cpp.o: /home/aditya/24783/src/public/src/FM7/util/RS232CDiskBios/disk_bios_hook_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/disk_bios_hook_client.cpp.o"
	cd /home/aditya/24783/build/public/src/FM7/util/RS232CDiskBios && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RS232CDiskBios.dir/disk_bios_hook_client.cpp.o -c /home/aditya/24783/src/public/src/FM7/util/RS232CDiskBios/disk_bios_hook_client.cpp

public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/disk_bios_hook_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RS232CDiskBios.dir/disk_bios_hook_client.cpp.i"
	cd /home/aditya/24783/build/public/src/FM7/util/RS232CDiskBios && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/FM7/util/RS232CDiskBios/disk_bios_hook_client.cpp > CMakeFiles/RS232CDiskBios.dir/disk_bios_hook_client.cpp.i

public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/disk_bios_hook_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RS232CDiskBios.dir/disk_bios_hook_client.cpp.s"
	cd /home/aditya/24783/build/public/src/FM7/util/RS232CDiskBios && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/FM7/util/RS232CDiskBios/disk_bios_hook_client.cpp -o CMakeFiles/RS232CDiskBios.dir/disk_bios_hook_client.cpp.s

# Object files for target RS232CDiskBios
RS232CDiskBios_OBJECTS = \
"CMakeFiles/RS232CDiskBios.dir/main.cpp.o" \
"CMakeFiles/RS232CDiskBios.dir/disk_bios_hook_client.cpp.o"

# External object files for target RS232CDiskBios
RS232CDiskBios_EXTERNAL_OBJECTS =

exe/RS232CDiskBios: public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/main.cpp.o
exe/RS232CDiskBios: public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/disk_bios_hook_client.cpp.o
exe/RS232CDiskBios: public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/build.make
exe/RS232CDiskBios: public/src/FM7/util/lib/libfm7lib.a
exe/RS232CDiskBios: public/src/FM7/util/d77/libd77lib.a
exe/RS232CDiskBios: public/src/FM7/util/lib/yscomport/libcomportlib.a
exe/RS232CDiskBios: public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../../../exe/RS232CDiskBios"
	cd /home/aditya/24783/build/public/src/FM7/util/RS232CDiskBios && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RS232CDiskBios.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/build: exe/RS232CDiskBios

.PHONY : public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/build

public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/clean:
	cd /home/aditya/24783/build/public/src/FM7/util/RS232CDiskBios && $(CMAKE_COMMAND) -P CMakeFiles/RS232CDiskBios.dir/cmake_clean.cmake
.PHONY : public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/clean

public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/public/src/FM7/util/RS232CDiskBios /home/aditya/24783/build /home/aditya/24783/build/public/src/FM7/util/RS232CDiskBios /home/aditya/24783/build/public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/src/FM7/util/RS232CDiskBios/CMakeFiles/RS232CDiskBios.dir/depend
