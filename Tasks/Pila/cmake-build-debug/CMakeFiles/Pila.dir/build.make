# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = C:\Users\xblao\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.4548.31\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\xblao\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.4548.31\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Pila.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pila.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pila.dir/flags.make

CMakeFiles/Pila.dir/main.cpp.obj: CMakeFiles/Pila.dir/flags.make
CMakeFiles/Pila.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pila.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Pila.dir\main.cpp.obj -c C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\main.cpp

CMakeFiles/Pila.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pila.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\main.cpp > CMakeFiles\Pila.dir\main.cpp.i

CMakeFiles/Pila.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pila.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\main.cpp -o CMakeFiles\Pila.dir\main.cpp.s

CMakeFiles/Pila.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Pila.dir/main.cpp.obj.requires

CMakeFiles/Pila.dir/main.cpp.obj.provides: CMakeFiles/Pila.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Pila.dir\build.make CMakeFiles/Pila.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Pila.dir/main.cpp.obj.provides

CMakeFiles/Pila.dir/main.cpp.obj.provides.build: CMakeFiles/Pila.dir/main.cpp.obj


CMakeFiles/Pila.dir/Pila.cpp.obj: CMakeFiles/Pila.dir/flags.make
CMakeFiles/Pila.dir/Pila.cpp.obj: ../Pila.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Pila.dir/Pila.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Pila.dir\Pila.cpp.obj -c C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\Pila.cpp

CMakeFiles/Pila.dir/Pila.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pila.dir/Pila.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\Pila.cpp > CMakeFiles\Pila.dir\Pila.cpp.i

CMakeFiles/Pila.dir/Pila.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pila.dir/Pila.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\Pila.cpp -o CMakeFiles\Pila.dir\Pila.cpp.s

CMakeFiles/Pila.dir/Pila.cpp.obj.requires:

.PHONY : CMakeFiles/Pila.dir/Pila.cpp.obj.requires

CMakeFiles/Pila.dir/Pila.cpp.obj.provides: CMakeFiles/Pila.dir/Pila.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Pila.dir\build.make CMakeFiles/Pila.dir/Pila.cpp.obj.provides.build
.PHONY : CMakeFiles/Pila.dir/Pila.cpp.obj.provides

CMakeFiles/Pila.dir/Pila.cpp.obj.provides.build: CMakeFiles/Pila.dir/Pila.cpp.obj


CMakeFiles/Pila.dir/Nodo.cpp.obj: CMakeFiles/Pila.dir/flags.make
CMakeFiles/Pila.dir/Nodo.cpp.obj: ../Nodo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Pila.dir/Nodo.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Pila.dir\Nodo.cpp.obj -c C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\Nodo.cpp

CMakeFiles/Pila.dir/Nodo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pila.dir/Nodo.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\Nodo.cpp > CMakeFiles\Pila.dir\Nodo.cpp.i

CMakeFiles/Pila.dir/Nodo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pila.dir/Nodo.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\Nodo.cpp -o CMakeFiles\Pila.dir\Nodo.cpp.s

CMakeFiles/Pila.dir/Nodo.cpp.obj.requires:

.PHONY : CMakeFiles/Pila.dir/Nodo.cpp.obj.requires

CMakeFiles/Pila.dir/Nodo.cpp.obj.provides: CMakeFiles/Pila.dir/Nodo.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Pila.dir\build.make CMakeFiles/Pila.dir/Nodo.cpp.obj.provides.build
.PHONY : CMakeFiles/Pila.dir/Nodo.cpp.obj.provides

CMakeFiles/Pila.dir/Nodo.cpp.obj.provides.build: CMakeFiles/Pila.dir/Nodo.cpp.obj


# Object files for target Pila
Pila_OBJECTS = \
"CMakeFiles/Pila.dir/main.cpp.obj" \
"CMakeFiles/Pila.dir/Pila.cpp.obj" \
"CMakeFiles/Pila.dir/Nodo.cpp.obj"

# External object files for target Pila
Pila_EXTERNAL_OBJECTS =

Pila.exe: CMakeFiles/Pila.dir/main.cpp.obj
Pila.exe: CMakeFiles/Pila.dir/Pila.cpp.obj
Pila.exe: CMakeFiles/Pila.dir/Nodo.cpp.obj
Pila.exe: CMakeFiles/Pila.dir/build.make
Pila.exe: CMakeFiles/Pila.dir/linklibs.rsp
Pila.exe: CMakeFiles/Pila.dir/objects1.rsp
Pila.exe: CMakeFiles/Pila.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Pila.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Pila.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pila.dir/build: Pila.exe

.PHONY : CMakeFiles/Pila.dir/build

CMakeFiles/Pila.dir/requires: CMakeFiles/Pila.dir/main.cpp.obj.requires
CMakeFiles/Pila.dir/requires: CMakeFiles/Pila.dir/Pila.cpp.obj.requires
CMakeFiles/Pila.dir/requires: CMakeFiles/Pila.dir/Nodo.cpp.obj.requires

.PHONY : CMakeFiles/Pila.dir/requires

CMakeFiles/Pila.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Pila.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Pila.dir/clean

CMakeFiles/Pila.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\cmake-build-debug C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\cmake-build-debug C:\Users\xblao\Documents\GitHub\Pankratios_Colbert\Tasks\Pila\cmake-build-debug\CMakeFiles\Pila.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pila.dir/depend

