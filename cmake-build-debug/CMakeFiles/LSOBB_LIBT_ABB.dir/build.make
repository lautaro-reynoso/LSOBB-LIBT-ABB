# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Usuario\Desktop\LSOBB-LIBT-ABB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Usuario\Desktop\LSOBB-LIBT-ABB\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LSOBB_LIBT_ABB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LSOBB_LIBT_ABB.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LSOBB_LIBT_ABB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LSOBB_LIBT_ABB.dir/flags.make

CMakeFiles/LSOBB_LIBT_ABB.dir/main.c.obj: CMakeFiles/LSOBB_LIBT_ABB.dir/flags.make
CMakeFiles/LSOBB_LIBT_ABB.dir/main.c.obj: CMakeFiles/LSOBB_LIBT_ABB.dir/includes_C.rsp
CMakeFiles/LSOBB_LIBT_ABB.dir/main.c.obj: C:/Users/Usuario/Desktop/LSOBB-LIBT-ABB/main.c
CMakeFiles/LSOBB_LIBT_ABB.dir/main.c.obj: CMakeFiles/LSOBB_LIBT_ABB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Usuario\Desktop\LSOBB-LIBT-ABB\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LSOBB_LIBT_ABB.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LSOBB_LIBT_ABB.dir/main.c.obj -MF CMakeFiles\LSOBB_LIBT_ABB.dir\main.c.obj.d -o CMakeFiles\LSOBB_LIBT_ABB.dir\main.c.obj -c C:\Users\Usuario\Desktop\LSOBB-LIBT-ABB\main.c

CMakeFiles/LSOBB_LIBT_ABB.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LSOBB_LIBT_ABB.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Usuario\Desktop\LSOBB-LIBT-ABB\main.c > CMakeFiles\LSOBB_LIBT_ABB.dir\main.c.i

CMakeFiles/LSOBB_LIBT_ABB.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LSOBB_LIBT_ABB.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Usuario\Desktop\LSOBB-LIBT-ABB\main.c -o CMakeFiles\LSOBB_LIBT_ABB.dir\main.c.s

# Object files for target LSOBB_LIBT_ABB
LSOBB_LIBT_ABB_OBJECTS = \
"CMakeFiles/LSOBB_LIBT_ABB.dir/main.c.obj"

# External object files for target LSOBB_LIBT_ABB
LSOBB_LIBT_ABB_EXTERNAL_OBJECTS =

LSOBB_LIBT_ABB.exe: CMakeFiles/LSOBB_LIBT_ABB.dir/main.c.obj
LSOBB_LIBT_ABB.exe: CMakeFiles/LSOBB_LIBT_ABB.dir/build.make
LSOBB_LIBT_ABB.exe: CMakeFiles/LSOBB_LIBT_ABB.dir/linkLibs.rsp
LSOBB_LIBT_ABB.exe: CMakeFiles/LSOBB_LIBT_ABB.dir/objects1.rsp
LSOBB_LIBT_ABB.exe: CMakeFiles/LSOBB_LIBT_ABB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Usuario\Desktop\LSOBB-LIBT-ABB\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LSOBB_LIBT_ABB.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LSOBB_LIBT_ABB.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LSOBB_LIBT_ABB.dir/build: LSOBB_LIBT_ABB.exe
.PHONY : CMakeFiles/LSOBB_LIBT_ABB.dir/build

CMakeFiles/LSOBB_LIBT_ABB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LSOBB_LIBT_ABB.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LSOBB_LIBT_ABB.dir/clean

CMakeFiles/LSOBB_LIBT_ABB.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Usuario\Desktop\LSOBB-LIBT-ABB C:\Users\Usuario\Desktop\LSOBB-LIBT-ABB C:\Users\Usuario\Desktop\LSOBB-LIBT-ABB\cmake-build-debug C:\Users\Usuario\Desktop\LSOBB-LIBT-ABB\cmake-build-debug C:\Users\Usuario\Desktop\LSOBB-LIBT-ABB\cmake-build-debug\CMakeFiles\LSOBB_LIBT_ABB.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LSOBB_LIBT_ABB.dir/depend

