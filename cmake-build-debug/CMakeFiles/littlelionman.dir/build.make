# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "/Users/i848340/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.5728.100/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/i848340/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.5728.100/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/i848340/CLionProjects/littlelionman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/i848340/CLionProjects/littlelionman/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/littlelionman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/littlelionman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/littlelionman.dir/flags.make

CMakeFiles/littlelionman.dir/src/main.cpp.o: CMakeFiles/littlelionman.dir/flags.make
CMakeFiles/littlelionman.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/i848340/CLionProjects/littlelionman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/littlelionman.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/littlelionman.dir/src/main.cpp.o -c /Users/i848340/CLionProjects/littlelionman/src/main.cpp

CMakeFiles/littlelionman.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/littlelionman.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/i848340/CLionProjects/littlelionman/src/main.cpp > CMakeFiles/littlelionman.dir/src/main.cpp.i

CMakeFiles/littlelionman.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/littlelionman.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/i848340/CLionProjects/littlelionman/src/main.cpp -o CMakeFiles/littlelionman.dir/src/main.cpp.s

# Object files for target littlelionman
littlelionman_OBJECTS = \
"CMakeFiles/littlelionman.dir/src/main.cpp.o"

# External object files for target littlelionman
littlelionman_EXTERNAL_OBJECTS =

littlelionman: CMakeFiles/littlelionman.dir/src/main.cpp.o
littlelionman: CMakeFiles/littlelionman.dir/build.make
littlelionman: /usr/local/lib/libSOIL.a
littlelionman: /usr/local/lib/libGLEW.dylib
littlelionman: /usr/local/lib/libglfw.3.3.dylib
littlelionman: CMakeFiles/littlelionman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/i848340/CLionProjects/littlelionman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable littlelionman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/littlelionman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/littlelionman.dir/build: littlelionman

.PHONY : CMakeFiles/littlelionman.dir/build

CMakeFiles/littlelionman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/littlelionman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/littlelionman.dir/clean

CMakeFiles/littlelionman.dir/depend:
	cd /Users/i848340/CLionProjects/littlelionman/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/i848340/CLionProjects/littlelionman /Users/i848340/CLionProjects/littlelionman /Users/i848340/CLionProjects/littlelionman/cmake-build-debug /Users/i848340/CLionProjects/littlelionman/cmake-build-debug /Users/i848340/CLionProjects/littlelionman/cmake-build-debug/CMakeFiles/littlelionman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/littlelionman.dir/depend

