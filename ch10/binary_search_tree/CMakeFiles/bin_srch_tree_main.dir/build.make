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
CMAKE_SOURCE_DIR = /home/bilal/DataStructures/ch10/binary_search_tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bilal/DataStructures/ch10/binary_search_tree

# Include any dependencies generated for this target.
include CMakeFiles/bin_srch_tree_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bin_srch_tree_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bin_srch_tree_main.dir/flags.make

CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o: CMakeFiles/bin_srch_tree_main.dir/flags.make
CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o: src/main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bilal/DataStructures/ch10/binary_search_tree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o -c /home/bilal/DataStructures/ch10/binary_search_tree/src/main.cxx

CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bilal/DataStructures/ch10/binary_search_tree/src/main.cxx > CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.i

CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bilal/DataStructures/ch10/binary_search_tree/src/main.cxx -o CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.s

CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o.requires:

.PHONY : CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o.requires

CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o.provides: CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o.requires
	$(MAKE) -f CMakeFiles/bin_srch_tree_main.dir/build.make CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o.provides.build
.PHONY : CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o.provides

CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o.provides.build: CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o


# Object files for target bin_srch_tree_main
bin_srch_tree_main_OBJECTS = \
"CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o"

# External object files for target bin_srch_tree_main
bin_srch_tree_main_EXTERNAL_OBJECTS =

bin_srch_tree_main: CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o
bin_srch_tree_main: CMakeFiles/bin_srch_tree_main.dir/build.make
bin_srch_tree_main: CMakeFiles/bin_srch_tree_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bilal/DataStructures/ch10/binary_search_tree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin_srch_tree_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bin_srch_tree_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bin_srch_tree_main.dir/build: bin_srch_tree_main

.PHONY : CMakeFiles/bin_srch_tree_main.dir/build

CMakeFiles/bin_srch_tree_main.dir/requires: CMakeFiles/bin_srch_tree_main.dir/src/main.cxx.o.requires

.PHONY : CMakeFiles/bin_srch_tree_main.dir/requires

CMakeFiles/bin_srch_tree_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bin_srch_tree_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bin_srch_tree_main.dir/clean

CMakeFiles/bin_srch_tree_main.dir/depend:
	cd /home/bilal/DataStructures/ch10/binary_search_tree && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bilal/DataStructures/ch10/binary_search_tree /home/bilal/DataStructures/ch10/binary_search_tree /home/bilal/DataStructures/ch10/binary_search_tree /home/bilal/DataStructures/ch10/binary_search_tree /home/bilal/DataStructures/ch10/binary_search_tree/CMakeFiles/bin_srch_tree_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bin_srch_tree_main.dir/depend

