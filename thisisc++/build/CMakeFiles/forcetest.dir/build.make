# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /workspaces/billbill/thisisc++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/billbill/thisisc++/build

# Utility rule file for forcetest.

# Include the progress variables for this target.
include CMakeFiles/forcetest.dir/progress.make

CMakeFiles/forcetest:
	cd /workspaces/billbill/thisisc++/test && ../node_modules/.bin/node-gyp rebuild
	cd /workspaces/billbill/thisisc++/test && npm test

forcetest: CMakeFiles/forcetest
forcetest: CMakeFiles/forcetest.dir/build.make

.PHONY : forcetest

# Rule to build all files generated by this target.
CMakeFiles/forcetest.dir/build: forcetest

.PHONY : CMakeFiles/forcetest.dir/build

CMakeFiles/forcetest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/forcetest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/forcetest.dir/clean

CMakeFiles/forcetest.dir/depend:
	cd /workspaces/billbill/thisisc++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/billbill/thisisc++ /workspaces/billbill/thisisc++ /workspaces/billbill/thisisc++/build /workspaces/billbill/thisisc++/build /workspaces/billbill/thisisc++/build/CMakeFiles/forcetest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/forcetest.dir/depend

