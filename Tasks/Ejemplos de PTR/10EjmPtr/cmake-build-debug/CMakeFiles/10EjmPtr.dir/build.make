# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\rbara\CLionProjects\10EjmPtr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\rbara\CLionProjects\10EjmPtr\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/10EjmPtr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/10EjmPtr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/10EjmPtr.dir/flags.make

CMakeFiles/10EjmPtr.dir/main.cpp.obj: CMakeFiles/10EjmPtr.dir/flags.make
CMakeFiles/10EjmPtr.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\rbara\CLionProjects\10EjmPtr\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/10EjmPtr.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\10EjmPtr.dir\main.cpp.obj -c C:\Users\rbara\CLionProjects\10EjmPtr\main.cpp

CMakeFiles/10EjmPtr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/10EjmPtr.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rbara\CLionProjects\10EjmPtr\main.cpp > CMakeFiles\10EjmPtr.dir\main.cpp.i

CMakeFiles/10EjmPtr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/10EjmPtr.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rbara\CLionProjects\10EjmPtr\main.cpp -o CMakeFiles\10EjmPtr.dir\main.cpp.s

CMakeFiles/10EjmPtr.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/10EjmPtr.dir/main.cpp.obj.requires

CMakeFiles/10EjmPtr.dir/main.cpp.obj.provides: CMakeFiles/10EjmPtr.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\10EjmPtr.dir\build.make CMakeFiles/10EjmPtr.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/10EjmPtr.dir/main.cpp.obj.provides

CMakeFiles/10EjmPtr.dir/main.cpp.obj.provides.build: CMakeFiles/10EjmPtr.dir/main.cpp.obj


# Object files for target 10EjmPtr
10EjmPtr_OBJECTS = \
"CMakeFiles/10EjmPtr.dir/main.cpp.obj"

# External object files for target 10EjmPtr
10EjmPtr_EXTERNAL_OBJECTS =

10EjmPtr.exe: CMakeFiles/10EjmPtr.dir/main.cpp.obj
10EjmPtr.exe: CMakeFiles/10EjmPtr.dir/build.make
10EjmPtr.exe: CMakeFiles/10EjmPtr.dir/linklibs.rsp
10EjmPtr.exe: CMakeFiles/10EjmPtr.dir/objects1.rsp
10EjmPtr.exe: CMakeFiles/10EjmPtr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\rbara\CLionProjects\10EjmPtr\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 10EjmPtr.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\10EjmPtr.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/10EjmPtr.dir/build: 10EjmPtr.exe

.PHONY : CMakeFiles/10EjmPtr.dir/build

CMakeFiles/10EjmPtr.dir/requires: CMakeFiles/10EjmPtr.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/10EjmPtr.dir/requires

CMakeFiles/10EjmPtr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\10EjmPtr.dir\cmake_clean.cmake
.PHONY : CMakeFiles/10EjmPtr.dir/clean

CMakeFiles/10EjmPtr.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\rbara\CLionProjects\10EjmPtr C:\Users\rbara\CLionProjects\10EjmPtr C:\Users\rbara\CLionProjects\10EjmPtr\cmake-build-debug C:\Users\rbara\CLionProjects\10EjmPtr\cmake-build-debug C:\Users\rbara\CLionProjects\10EjmPtr\cmake-build-debug\CMakeFiles\10EjmPtr.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/10EjmPtr.dir/depend

