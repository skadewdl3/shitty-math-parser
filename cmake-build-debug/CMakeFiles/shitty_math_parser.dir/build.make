# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/skadewdl3/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/skadewdl3/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/skadewdl3/Projects/shitty-math-parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/skadewdl3/Projects/shitty-math-parser/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/shitty_math_parser.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/shitty_math_parser.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/shitty_math_parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shitty_math_parser.dir/flags.make

CMakeFiles/shitty_math_parser.dir/main.c.o: CMakeFiles/shitty_math_parser.dir/flags.make
CMakeFiles/shitty_math_parser.dir/main.c.o: /home/skadewdl3/Projects/shitty-math-parser/main.c
CMakeFiles/shitty_math_parser.dir/main.c.o: CMakeFiles/shitty_math_parser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/skadewdl3/Projects/shitty-math-parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/shitty_math_parser.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/shitty_math_parser.dir/main.c.o -MF CMakeFiles/shitty_math_parser.dir/main.c.o.d -o CMakeFiles/shitty_math_parser.dir/main.c.o -c /home/skadewdl3/Projects/shitty-math-parser/main.c

CMakeFiles/shitty_math_parser.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/shitty_math_parser.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/skadewdl3/Projects/shitty-math-parser/main.c > CMakeFiles/shitty_math_parser.dir/main.c.i

CMakeFiles/shitty_math_parser.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/shitty_math_parser.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/skadewdl3/Projects/shitty-math-parser/main.c -o CMakeFiles/shitty_math_parser.dir/main.c.s

CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.o: CMakeFiles/shitty_math_parser.dir/flags.make
CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.o: /home/skadewdl3/Projects/shitty-math-parser/include/shitty-math-parser.c
CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.o: CMakeFiles/shitty_math_parser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/skadewdl3/Projects/shitty-math-parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.o -MF CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.o.d -o CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.o -c /home/skadewdl3/Projects/shitty-math-parser/include/shitty-math-parser.c

CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/skadewdl3/Projects/shitty-math-parser/include/shitty-math-parser.c > CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.i

CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/skadewdl3/Projects/shitty-math-parser/include/shitty-math-parser.c -o CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.s

# Object files for target shitty_math_parser
shitty_math_parser_OBJECTS = \
"CMakeFiles/shitty_math_parser.dir/main.c.o" \
"CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.o"

# External object files for target shitty_math_parser
shitty_math_parser_EXTERNAL_OBJECTS =

shitty_math_parser: CMakeFiles/shitty_math_parser.dir/main.c.o
shitty_math_parser: CMakeFiles/shitty_math_parser.dir/include/shitty-math-parser.c.o
shitty_math_parser: CMakeFiles/shitty_math_parser.dir/build.make
shitty_math_parser: CMakeFiles/shitty_math_parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/skadewdl3/Projects/shitty-math-parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable shitty_math_parser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shitty_math_parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shitty_math_parser.dir/build: shitty_math_parser
.PHONY : CMakeFiles/shitty_math_parser.dir/build

CMakeFiles/shitty_math_parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shitty_math_parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shitty_math_parser.dir/clean

CMakeFiles/shitty_math_parser.dir/depend:
	cd /home/skadewdl3/Projects/shitty-math-parser/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/skadewdl3/Projects/shitty-math-parser /home/skadewdl3/Projects/shitty-math-parser /home/skadewdl3/Projects/shitty-math-parser/cmake-build-debug /home/skadewdl3/Projects/shitty-math-parser/cmake-build-debug /home/skadewdl3/Projects/shitty-math-parser/cmake-build-debug/CMakeFiles/shitty_math_parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/shitty_math_parser.dir/depend

