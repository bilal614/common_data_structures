# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bilal/DataStructures/ch5/queues

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bilal/DataStructures/ch5/queues

# Include any dependencies generated for this target.
include CMakeFiles/queues_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/queues_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/queues_main.dir/flags.make

CMakeFiles/queues_main.dir/main.cxx.o: CMakeFiles/queues_main.dir/flags.make
CMakeFiles/queues_main.dir/main.cxx.o: main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bilal/DataStructures/ch5/queues/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/queues_main.dir/main.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/queues_main.dir/main.cxx.o -c /home/bilal/DataStructures/ch5/queues/main.cxx

CMakeFiles/queues_main.dir/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queues_main.dir/main.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bilal/DataStructures/ch5/queues/main.cxx > CMakeFiles/queues_main.dir/main.cxx.i

CMakeFiles/queues_main.dir/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queues_main.dir/main.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bilal/DataStructures/ch5/queues/main.cxx -o CMakeFiles/queues_main.dir/main.cxx.s

CMakeFiles/queues_main.dir/main.cxx.o.requires:

.PHONY : CMakeFiles/queues_main.dir/main.cxx.o.requires

CMakeFiles/queues_main.dir/main.cxx.o.provides: CMakeFiles/queues_main.dir/main.cxx.o.requires
	$(MAKE) -f CMakeFiles/queues_main.dir/build.make CMakeFiles/queues_main.dir/main.cxx.o.provides.build
.PHONY : CMakeFiles/queues_main.dir/main.cxx.o.provides

CMakeFiles/queues_main.dir/main.cxx.o.provides.build: CMakeFiles/queues_main.dir/main.cxx.o


# Object files for target queues_main
queues_main_OBJECTS = \
"CMakeFiles/queues_main.dir/main.cxx.o"

# External object files for target queues_main
queues_main_EXTERNAL_OBJECTS =

queues_main: CMakeFiles/queues_main.dir/main.cxx.o
queues_main: CMakeFiles/queues_main.dir/build.make
queues_main: CMakeFiles/queues_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bilal/DataStructures/ch5/queues/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable queues_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/queues_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/queues_main.dir/build: queues_main

.PHONY : CMakeFiles/queues_main.dir/build

CMakeFiles/queues_main.dir/requires: CMakeFiles/queues_main.dir/main.cxx.o.requires

.PHONY : CMakeFiles/queues_main.dir/requires

CMakeFiles/queues_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/queues_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/queues_main.dir/clean

CMakeFiles/queues_main.dir/depend:
	cd /home/bilal/DataStructures/ch5/queues && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bilal/DataStructures/ch5/queues /home/bilal/DataStructures/ch5/queues /home/bilal/DataStructures/ch5/queues /home/bilal/DataStructures/ch5/queues /home/bilal/DataStructures/ch5/queues/CMakeFiles/queues_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/queues_main.dir/depend

