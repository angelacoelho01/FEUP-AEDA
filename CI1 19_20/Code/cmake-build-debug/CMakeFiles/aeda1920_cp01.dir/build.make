# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/aeda1920_cp01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aeda1920_cp01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aeda1920_cp01.dir/flags.make

CMakeFiles/aeda1920_cp01.dir/main.cpp.o: CMakeFiles/aeda1920_cp01.dir/flags.make
CMakeFiles/aeda1920_cp01.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aeda1920_cp01.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1920_cp01.dir/main.cpp.o -c "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/main.cpp"

CMakeFiles/aeda1920_cp01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1920_cp01.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/main.cpp" > CMakeFiles/aeda1920_cp01.dir/main.cpp.i

CMakeFiles/aeda1920_cp01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1920_cp01.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/main.cpp" -o CMakeFiles/aeda1920_cp01.dir/main.cpp.s

CMakeFiles/aeda1920_cp01.dir/Tests/tests.cpp.o: CMakeFiles/aeda1920_cp01.dir/flags.make
CMakeFiles/aeda1920_cp01.dir/Tests/tests.cpp.o: ../Tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/aeda1920_cp01.dir/Tests/tests.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1920_cp01.dir/Tests/tests.cpp.o -c "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/Tests/tests.cpp"

CMakeFiles/aeda1920_cp01.dir/Tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1920_cp01.dir/Tests/tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/Tests/tests.cpp" > CMakeFiles/aeda1920_cp01.dir/Tests/tests.cpp.i

CMakeFiles/aeda1920_cp01.dir/Tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1920_cp01.dir/Tests/tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/Tests/tests.cpp" -o CMakeFiles/aeda1920_cp01.dir/Tests/tests.cpp.s

CMakeFiles/aeda1920_cp01.dir/Tests/Room.cpp.o: CMakeFiles/aeda1920_cp01.dir/flags.make
CMakeFiles/aeda1920_cp01.dir/Tests/Room.cpp.o: ../Tests/Room.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/aeda1920_cp01.dir/Tests/Room.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda1920_cp01.dir/Tests/Room.cpp.o -c "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/Tests/Room.cpp"

CMakeFiles/aeda1920_cp01.dir/Tests/Room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda1920_cp01.dir/Tests/Room.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/Tests/Room.cpp" > CMakeFiles/aeda1920_cp01.dir/Tests/Room.cpp.i

CMakeFiles/aeda1920_cp01.dir/Tests/Room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda1920_cp01.dir/Tests/Room.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/Tests/Room.cpp" -o CMakeFiles/aeda1920_cp01.dir/Tests/Room.cpp.s

# Object files for target aeda1920_cp01
aeda1920_cp01_OBJECTS = \
"CMakeFiles/aeda1920_cp01.dir/main.cpp.o" \
"CMakeFiles/aeda1920_cp01.dir/Tests/tests.cpp.o" \
"CMakeFiles/aeda1920_cp01.dir/Tests/Room.cpp.o"

# External object files for target aeda1920_cp01
aeda1920_cp01_EXTERNAL_OBJECTS =

aeda1920_cp01: CMakeFiles/aeda1920_cp01.dir/main.cpp.o
aeda1920_cp01: CMakeFiles/aeda1920_cp01.dir/Tests/tests.cpp.o
aeda1920_cp01: CMakeFiles/aeda1920_cp01.dir/Tests/Room.cpp.o
aeda1920_cp01: CMakeFiles/aeda1920_cp01.dir/build.make
aeda1920_cp01: lib/libgtestd.a
aeda1920_cp01: lib/libgtest_maind.a
aeda1920_cp01: lib/libgtestd.a
aeda1920_cp01: CMakeFiles/aeda1920_cp01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable aeda1920_cp01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aeda1920_cp01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aeda1920_cp01.dir/build: aeda1920_cp01

.PHONY : CMakeFiles/aeda1920_cp01.dir/build

CMakeFiles/aeda1920_cp01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aeda1920_cp01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aeda1920_cp01.dir/clean

CMakeFiles/aeda1920_cp01.dir/depend:
	cd "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code" "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code" "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/cmake-build-debug" "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/cmake-build-debug" "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/Test 19_20/Code/cmake-build-debug/CMakeFiles/aeda1920_cp01.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/aeda1920_cp01.dir/depend

