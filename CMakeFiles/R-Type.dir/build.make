# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leonard/code/tek3/R-Type

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leonard/code/tek3/R-Type

# Include any dependencies generated for this target.
include CMakeFiles/R-Type.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/R-Type.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/R-Type.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/R-Type.dir/flags.make

CMakeFiles/R-Type.dir/src/main.cpp.o: CMakeFiles/R-Type.dir/flags.make
CMakeFiles/R-Type.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/R-Type.dir/src/main.cpp.o: CMakeFiles/R-Type.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonard/code/tek3/R-Type/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/R-Type.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/R-Type.dir/src/main.cpp.o -MF CMakeFiles/R-Type.dir/src/main.cpp.o.d -o CMakeFiles/R-Type.dir/src/main.cpp.o -c /home/leonard/code/tek3/R-Type/src/main.cpp

CMakeFiles/R-Type.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/R-Type.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leonard/code/tek3/R-Type/src/main.cpp > CMakeFiles/R-Type.dir/src/main.cpp.i

CMakeFiles/R-Type.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/R-Type.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leonard/code/tek3/R-Type/src/main.cpp -o CMakeFiles/R-Type.dir/src/main.cpp.s

# Object files for target R-Type
R__Type_OBJECTS = \
"CMakeFiles/R-Type.dir/src/main.cpp.o"

# External object files for target R-Type
R__Type_EXTERNAL_OBJECTS =

R-Type: CMakeFiles/R-Type.dir/src/main.cpp.o
R-Type: CMakeFiles/R-Type.dir/build.make
R-Type: CMakeFiles/R-Type.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leonard/code/tek3/R-Type/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable R-Type"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/R-Type.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/R-Type.dir/build: R-Type
.PHONY : CMakeFiles/R-Type.dir/build

CMakeFiles/R-Type.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/R-Type.dir/cmake_clean.cmake
.PHONY : CMakeFiles/R-Type.dir/clean

CMakeFiles/R-Type.dir/depend:
	cd /home/leonard/code/tek3/R-Type && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leonard/code/tek3/R-Type /home/leonard/code/tek3/R-Type /home/leonard/code/tek3/R-Type /home/leonard/code/tek3/R-Type /home/leonard/code/tek3/R-Type/CMakeFiles/R-Type.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/R-Type.dir/depend

