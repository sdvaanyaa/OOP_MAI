# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.9/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.9/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ivan/OOP_MAI/lab_6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ivan/OOP_MAI/lab_6/build

# Include any dependencies generated for this target.
include CMakeFiles/lab6_tests_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab6_tests_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab6_tests_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab6_tests_exe.dir/flags.make

CMakeFiles/lab6_tests_exe.dir/test/test.cpp.o: CMakeFiles/lab6_tests_exe.dir/flags.make
CMakeFiles/lab6_tests_exe.dir/test/test.cpp.o: /Users/ivan/OOP_MAI/lab_6/test/test.cpp
CMakeFiles/lab6_tests_exe.dir/test/test.cpp.o: CMakeFiles/lab6_tests_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivan/OOP_MAI/lab_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab6_tests_exe.dir/test/test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_tests_exe.dir/test/test.cpp.o -MF CMakeFiles/lab6_tests_exe.dir/test/test.cpp.o.d -o CMakeFiles/lab6_tests_exe.dir/test/test.cpp.o -c /Users/ivan/OOP_MAI/lab_6/test/test.cpp

CMakeFiles/lab6_tests_exe.dir/test/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab6_tests_exe.dir/test/test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivan/OOP_MAI/lab_6/test/test.cpp > CMakeFiles/lab6_tests_exe.dir/test/test.cpp.i

CMakeFiles/lab6_tests_exe.dir/test/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab6_tests_exe.dir/test/test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivan/OOP_MAI/lab_6/test/test.cpp -o CMakeFiles/lab6_tests_exe.dir/test/test.cpp.s

# Object files for target lab6_tests_exe
lab6_tests_exe_OBJECTS = \
"CMakeFiles/lab6_tests_exe.dir/test/test.cpp.o"

# External object files for target lab6_tests_exe
lab6_tests_exe_EXTERNAL_OBJECTS =

lab6_tests_exe: CMakeFiles/lab6_tests_exe.dir/test/test.cpp.o
lab6_tests_exe: CMakeFiles/lab6_tests_exe.dir/build.make
lab6_tests_exe: liblab6_lib.a
lab6_tests_exe: /opt/homebrew/lib/libgtest_main.a
lab6_tests_exe: /opt/homebrew/lib/libgtest.a
lab6_tests_exe: CMakeFiles/lab6_tests_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ivan/OOP_MAI/lab_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab6_tests_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab6_tests_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab6_tests_exe.dir/build: lab6_tests_exe
.PHONY : CMakeFiles/lab6_tests_exe.dir/build

CMakeFiles/lab6_tests_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab6_tests_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab6_tests_exe.dir/clean

CMakeFiles/lab6_tests_exe.dir/depend:
	cd /Users/ivan/OOP_MAI/lab_6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ivan/OOP_MAI/lab_6 /Users/ivan/OOP_MAI/lab_6 /Users/ivan/OOP_MAI/lab_6/build /Users/ivan/OOP_MAI/lab_6/build /Users/ivan/OOP_MAI/lab_6/build/CMakeFiles/lab6_tests_exe.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab6_tests_exe.dir/depend
