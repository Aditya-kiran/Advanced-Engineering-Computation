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
include public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/depend.make

# Include the progress variables for this target.
include public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/progress.make

# Include the compile flags for this target's objects.
include public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/flags.make

public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/fsguiapp.cpp.o: public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/flags.make
public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/fsguiapp.cpp.o: /home/aditya/24783/src/public/src/fsguilib/template/fsguiapp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/fsguiapp.cpp.o"
	cd /home/aditya/24783/build/public/src/fsguilib/template && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fsguilib_template.dir/fsguiapp.cpp.o -c /home/aditya/24783/src/public/src/fsguilib/template/fsguiapp.cpp

public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/fsguiapp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fsguilib_template.dir/fsguiapp.cpp.i"
	cd /home/aditya/24783/build/public/src/fsguilib/template && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/fsguilib/template/fsguiapp.cpp > CMakeFiles/fsguilib_template.dir/fsguiapp.cpp.i

public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/fsguiapp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fsguilib_template.dir/fsguiapp.cpp.s"
	cd /home/aditya/24783/build/public/src/fsguilib/template && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/fsguilib/template/fsguiapp.cpp -o CMakeFiles/fsguilib_template.dir/fsguiapp.cpp.s

public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/fsguimain.cpp.o: public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/flags.make
public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/fsguimain.cpp.o: /home/aditya/24783/src/public/src/fsguilib/template/fsguimain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/fsguimain.cpp.o"
	cd /home/aditya/24783/build/public/src/fsguilib/template && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fsguilib_template.dir/fsguimain.cpp.o -c /home/aditya/24783/src/public/src/fsguilib/template/fsguimain.cpp

public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/fsguimain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fsguilib_template.dir/fsguimain.cpp.i"
	cd /home/aditya/24783/build/public/src/fsguilib/template && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/fsguilib/template/fsguimain.cpp > CMakeFiles/fsguilib_template.dir/fsguimain.cpp.i

public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/fsguimain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fsguilib_template.dir/fsguimain.cpp.s"
	cd /home/aditya/24783/build/public/src/fsguilib/template && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/fsguilib/template/fsguimain.cpp -o CMakeFiles/fsguilib_template.dir/fsguimain.cpp.s

public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/singleton.cpp.o: public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/flags.make
public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/singleton.cpp.o: /home/aditya/24783/src/public/src/fsguilib/template/singleton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/singleton.cpp.o"
	cd /home/aditya/24783/build/public/src/fsguilib/template && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fsguilib_template.dir/singleton.cpp.o -c /home/aditya/24783/src/public/src/fsguilib/template/singleton.cpp

public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/singleton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fsguilib_template.dir/singleton.cpp.i"
	cd /home/aditya/24783/build/public/src/fsguilib/template && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aditya/24783/src/public/src/fsguilib/template/singleton.cpp > CMakeFiles/fsguilib_template.dir/singleton.cpp.i

public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/singleton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fsguilib_template.dir/singleton.cpp.s"
	cd /home/aditya/24783/build/public/src/fsguilib/template && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aditya/24783/src/public/src/fsguilib/template/singleton.cpp -o CMakeFiles/fsguilib_template.dir/singleton.cpp.s

# Object files for target fsguilib_template
fsguilib_template_OBJECTS = \
"CMakeFiles/fsguilib_template.dir/fsguiapp.cpp.o" \
"CMakeFiles/fsguilib_template.dir/fsguimain.cpp.o" \
"CMakeFiles/fsguilib_template.dir/singleton.cpp.o"

# External object files for target fsguilib_template
fsguilib_template_EXTERNAL_OBJECTS =

public/src/fsguilib/template/fsguilib_template: public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/fsguiapp.cpp.o
public/src/fsguilib/template/fsguilib_template: public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/fsguimain.cpp.o
public/src/fsguilib/template/fsguilib_template: public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/singleton.cpp.o
public/src/fsguilib/template/fsguilib_template: public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/build.make
public/src/fsguilib/template/fsguilib_template: public/src/fslazywindow/src/libfslazywindow.a
public/src/fsguilib/template/fsguilib_template: public/src/ysgl/src/libysgl.a
public/src/fsguilib/template/fsguilib_template: public/src/fsguilib/src/libfsguilib.a
public/src/fsguilib/template/fsguilib_template: public/src/fsguilib/src/gl2/libfsguilib_gl2.a
public/src/fsguilib/template/fsguilib_template: public/src/ysfontrenderer/src/libysfontrenderer.a
public/src/fsguilib/template/fsguilib_template: public/src/ysbitmapfont/src/libysbitmapfont.a
public/src/fsguilib/template/fsguilib_template: public/src/ysgl/src/libysgl.a
public/src/fsguilib/template/fsguilib_template: public/src/fssimplewindow/src/libfssimplewindow.a
public/src/fsguilib/template/fsguilib_template: public/src/ysclass/src/libysclass.a
public/src/fsguilib/template/fsguilib_template: public/src/ysbitmap/src/libysbitmap.a
public/src/fsguilib/template/fsguilib_template: public/src/yssystemfont/src/libyssystemfont.a
public/src/fsguilib/template/fsguilib_template: public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aditya/24783/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable fsguilib_template"
	cd /home/aditya/24783/build/public/src/fsguilib/template && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fsguilib_template.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/build: public/src/fsguilib/template/fsguilib_template

.PHONY : public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/build

public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/clean:
	cd /home/aditya/24783/build/public/src/fsguilib/template && $(CMAKE_COMMAND) -P CMakeFiles/fsguilib_template.dir/cmake_clean.cmake
.PHONY : public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/clean

public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/depend:
	cd /home/aditya/24783/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/24783/src /home/aditya/24783/src/public/src/fsguilib/template /home/aditya/24783/build /home/aditya/24783/build/public/src/fsguilib/template /home/aditya/24783/build/public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/src/fsguilib/template/CMakeFiles/fsguilib_template.dir/depend

