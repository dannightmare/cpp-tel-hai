# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cpp_ex1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cpp_ex1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cpp_ex1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp_ex1.dir/flags.make

CMakeFiles/cpp_ex1.dir/main.cpp.o: CMakeFiles/cpp_ex1.dir/flags.make
CMakeFiles/cpp_ex1.dir/main.cpp.o: ../main.cpp
CMakeFiles/cpp_ex1.dir/main.cpp.o: CMakeFiles/cpp_ex1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpp_ex1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpp_ex1.dir/main.cpp.o -MF CMakeFiles/cpp_ex1.dir/main.cpp.o.d -o CMakeFiles/cpp_ex1.dir/main.cpp.o -c /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/main.cpp

CMakeFiles/cpp_ex1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_ex1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/main.cpp > CMakeFiles/cpp_ex1.dir/main.cpp.i

CMakeFiles/cpp_ex1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_ex1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/main.cpp -o CMakeFiles/cpp_ex1.dir/main.cpp.s

CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.o: CMakeFiles/cpp_ex1.dir/flags.make
CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.o: ../ObservationCLI.cpp
CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.o: CMakeFiles/cpp_ex1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.o -MF CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.o.d -o CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.o -c /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/ObservationCLI.cpp

CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/ObservationCLI.cpp > CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.i

CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/ObservationCLI.cpp -o CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.s

CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.o: CMakeFiles/cpp_ex1.dir/flags.make
CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.o: ../ObservationNode.cpp
CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.o: CMakeFiles/cpp_ex1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.o -MF CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.o.d -o CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.o -c /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/ObservationNode.cpp

CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/ObservationNode.cpp > CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.i

CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/ObservationNode.cpp -o CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.s

# Object files for target cpp_ex1
cpp_ex1_OBJECTS = \
"CMakeFiles/cpp_ex1.dir/main.cpp.o" \
"CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.o" \
"CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.o"

# External object files for target cpp_ex1
cpp_ex1_EXTERNAL_OBJECTS =

cpp_ex1: CMakeFiles/cpp_ex1.dir/main.cpp.o
cpp_ex1: CMakeFiles/cpp_ex1.dir/ObservationCLI.cpp.o
cpp_ex1: CMakeFiles/cpp_ex1.dir/ObservationNode.cpp.o
cpp_ex1: CMakeFiles/cpp_ex1.dir/build.make
cpp_ex1: CMakeFiles/cpp_ex1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable cpp_ex1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpp_ex1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp_ex1.dir/build: cpp_ex1
.PHONY : CMakeFiles/cpp_ex1.dir/build

CMakeFiles/cpp_ex1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpp_ex1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpp_ex1.dir/clean

CMakeFiles/cpp_ex1.dir/depend:
	cd /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1 /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1 /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/cmake-build-debug /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/cmake-build-debug /Users/dannightmare/Programming/CLionProjects/CPP/cpp-ex1/cmake-build-debug/CMakeFiles/cpp_ex1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpp_ex1.dir/depend
