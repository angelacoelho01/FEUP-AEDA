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
CMAKE_SOURCE_DIR = "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/aeda2021_p04.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aeda2021_p04.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aeda2021_p04.dir/flags.make

CMakeFiles/aeda2021_p04.dir/main.cpp.o: CMakeFiles/aeda2021_p04.dir/flags.make
CMakeFiles/aeda2021_p04.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aeda2021_p04.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda2021_p04.dir/main.cpp.o -c "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/main.cpp"

CMakeFiles/aeda2021_p04.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda2021_p04.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/main.cpp" > CMakeFiles/aeda2021_p04.dir/main.cpp.i

CMakeFiles/aeda2021_p04.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda2021_p04.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/main.cpp" -o CMakeFiles/aeda2021_p04.dir/main.cpp.s

CMakeFiles/aeda2021_p04.dir/Tests/tests.cpp.o: CMakeFiles/aeda2021_p04.dir/flags.make
CMakeFiles/aeda2021_p04.dir/Tests/tests.cpp.o: ../Tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/aeda2021_p04.dir/Tests/tests.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda2021_p04.dir/Tests/tests.cpp.o -c "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/Tests/tests.cpp"

CMakeFiles/aeda2021_p04.dir/Tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda2021_p04.dir/Tests/tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/Tests/tests.cpp" > CMakeFiles/aeda2021_p04.dir/Tests/tests.cpp.i

CMakeFiles/aeda2021_p04.dir/Tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda2021_p04.dir/Tests/tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/Tests/tests.cpp" -o CMakeFiles/aeda2021_p04.dir/Tests/tests.cpp.s

CMakeFiles/aeda2021_p04.dir/Tests/carPark.cpp.o: CMakeFiles/aeda2021_p04.dir/flags.make
CMakeFiles/aeda2021_p04.dir/Tests/carPark.cpp.o: ../Tests/carPark.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/aeda2021_p04.dir/Tests/carPark.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeda2021_p04.dir/Tests/carPark.cpp.o -c "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/Tests/carPark.cpp"

CMakeFiles/aeda2021_p04.dir/Tests/carPark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda2021_p04.dir/Tests/carPark.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/Tests/carPark.cpp" > CMakeFiles/aeda2021_p04.dir/Tests/carPark.cpp.i

CMakeFiles/aeda2021_p04.dir/Tests/carPark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda2021_p04.dir/Tests/carPark.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/Tests/carPark.cpp" -o CMakeFiles/aeda2021_p04.dir/Tests/carPark.cpp.s

# Object files for target aeda2021_p04
aeda2021_p04_OBJECTS = \
"CMakeFiles/aeda2021_p04.dir/main.cpp.o" \
"CMakeFiles/aeda2021_p04.dir/Tests/tests.cpp.o" \
"CMakeFiles/aeda2021_p04.dir/Tests/carPark.cpp.o"

# External object files for target aeda2021_p04
aeda2021_p04_EXTERNAL_OBJECTS =

aeda2021_p04: CMakeFiles/aeda2021_p04.dir/main.cpp.o
aeda2021_p04: CMakeFiles/aeda2021_p04.dir/Tests/tests.cpp.o
aeda2021_p04: CMakeFiles/aeda2021_p04.dir/Tests/carPark.cpp.o
aeda2021_p04: CMakeFiles/aeda2021_p04.dir/build.make
aeda2021_p04: lib/libgtestd.a
aeda2021_p04: lib/libgtest_maind.a
aeda2021_p04: lib/libgtestd.a
aeda2021_p04: CMakeFiles/aeda2021_p04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable aeda2021_p04"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aeda2021_p04.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aeda2021_p04.dir/build: aeda2021_p04

.PHONY : CMakeFiles/aeda2021_p04.dir/build

CMakeFiles/aeda2021_p04.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aeda2021_p04.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aeda2021_p04.dir/clean

CMakeFiles/aeda2021_p04.dir/depend:
	cd "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code" "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code" "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/cmake-build-debug" "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/cmake-build-debug" "/home/angela/Desktop/MIEIC/2nd Year/AEDA/FEUP-AEDA/TP04/Code/cmake-build-debug/CMakeFiles/aeda2021_p04.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/aeda2021_p04.dir/depend

