# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = I:\cubeclt\cube\STM32CubeCLT_1.16.0\CMake\bin\cmake.exe

# The command to remove a file.
RM = I:\cubeclt\cube\STM32CubeCLT_1.16.0\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = I:\learning\prj\hash_map

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = I:\learning\prj\hash_map\build

# Include any dependencies generated for this target.
include CMakeFiles/hashmap.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hashmap.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hashmap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hashmap.dir/flags.make

CMakeFiles/hashmap.dir/hashmap.c.obj: CMakeFiles/hashmap.dir/flags.make
CMakeFiles/hashmap.dir/hashmap.c.obj: CMakeFiles/hashmap.dir/includes_C.rsp
CMakeFiles/hashmap.dir/hashmap.c.obj: I:/learning/prj/hash_map/hashmap.c
CMakeFiles/hashmap.dir/hashmap.c.obj: CMakeFiles/hashmap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=I:\learning\prj\hash_map\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hashmap.dir/hashmap.c.obj"
	D:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/hashmap.dir/hashmap.c.obj -MF CMakeFiles\hashmap.dir\hashmap.c.obj.d -o CMakeFiles\hashmap.dir\hashmap.c.obj -c I:\learning\prj\hash_map\hashmap.c

CMakeFiles/hashmap.dir/hashmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/hashmap.dir/hashmap.c.i"
	D:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E I:\learning\prj\hash_map\hashmap.c > CMakeFiles\hashmap.dir\hashmap.c.i

CMakeFiles/hashmap.dir/hashmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/hashmap.dir/hashmap.c.s"
	D:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S I:\learning\prj\hash_map\hashmap.c -o CMakeFiles\hashmap.dir\hashmap.c.s

# Object files for target hashmap
hashmap_OBJECTS = \
"CMakeFiles/hashmap.dir/hashmap.c.obj"

# External object files for target hashmap
hashmap_EXTERNAL_OBJECTS =

hashmap.exe: CMakeFiles/hashmap.dir/hashmap.c.obj
hashmap.exe: CMakeFiles/hashmap.dir/build.make
hashmap.exe: CMakeFiles/hashmap.dir/linkLibs.rsp
hashmap.exe: CMakeFiles/hashmap.dir/objects1.rsp
hashmap.exe: CMakeFiles/hashmap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=I:\learning\prj\hash_map\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable hashmap.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hashmap.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hashmap.dir/build: hashmap.exe
.PHONY : CMakeFiles/hashmap.dir/build

CMakeFiles/hashmap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hashmap.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hashmap.dir/clean

CMakeFiles/hashmap.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" I:\learning\prj\hash_map I:\learning\prj\hash_map I:\learning\prj\hash_map\build I:\learning\prj\hash_map\build I:\learning\prj\hash_map\build\CMakeFiles\hashmap.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/hashmap.dir/depend

