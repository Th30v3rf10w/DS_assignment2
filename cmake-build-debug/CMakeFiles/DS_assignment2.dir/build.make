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
CMAKE_COMMAND = "C:\Users\youss\AppData\Local\Programs\CLion Nova\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\youss\AppData\Local\Programs\CLion Nova\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\C++\DS_assignment2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\C++\DS_assignment2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DS_assignment2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DS_assignment2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DS_assignment2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DS_assignment2.dir/flags.make

CMakeFiles/DS_assignment2.dir/main.cpp.obj: CMakeFiles/DS_assignment2.dir/flags.make
CMakeFiles/DS_assignment2.dir/main.cpp.obj: CMakeFiles/DS_assignment2.dir/includes_CXX.rsp
CMakeFiles/DS_assignment2.dir/main.cpp.obj: D:/Projects/C++/DS_assignment2/main.cpp
CMakeFiles/DS_assignment2.dir/main.cpp.obj: CMakeFiles/DS_assignment2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Projects\C++\DS_assignment2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DS_assignment2.dir/main.cpp.obj"
	C:\Users\youss\AppData\Local\Programs\CLIONN~1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DS_assignment2.dir/main.cpp.obj -MF CMakeFiles\DS_assignment2.dir\main.cpp.obj.d -o CMakeFiles\DS_assignment2.dir\main.cpp.obj -c D:\Projects\C++\DS_assignment2\main.cpp

CMakeFiles/DS_assignment2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DS_assignment2.dir/main.cpp.i"
	C:\Users\youss\AppData\Local\Programs\CLIONN~1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\C++\DS_assignment2\main.cpp > CMakeFiles\DS_assignment2.dir\main.cpp.i

CMakeFiles/DS_assignment2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DS_assignment2.dir/main.cpp.s"
	C:\Users\youss\AppData\Local\Programs\CLIONN~1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\C++\DS_assignment2\main.cpp -o CMakeFiles\DS_assignment2.dir\main.cpp.s

# Object files for target DS_assignment2
DS_assignment2_OBJECTS = \
"CMakeFiles/DS_assignment2.dir/main.cpp.obj"

# External object files for target DS_assignment2
DS_assignment2_EXTERNAL_OBJECTS =

DS_assignment2.exe: CMakeFiles/DS_assignment2.dir/main.cpp.obj
DS_assignment2.exe: CMakeFiles/DS_assignment2.dir/build.make
DS_assignment2.exe: CMakeFiles/DS_assignment2.dir/linkLibs.rsp
DS_assignment2.exe: CMakeFiles/DS_assignment2.dir/objects1.rsp
DS_assignment2.exe: CMakeFiles/DS_assignment2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Projects\C++\DS_assignment2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DS_assignment2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DS_assignment2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DS_assignment2.dir/build: DS_assignment2.exe
.PHONY : CMakeFiles/DS_assignment2.dir/build

CMakeFiles/DS_assignment2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DS_assignment2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DS_assignment2.dir/clean

CMakeFiles/DS_assignment2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\C++\DS_assignment2 D:\Projects\C++\DS_assignment2 D:\Projects\C++\DS_assignment2\cmake-build-debug D:\Projects\C++\DS_assignment2\cmake-build-debug D:\Projects\C++\DS_assignment2\cmake-build-debug\CMakeFiles\DS_assignment2.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/DS_assignment2.dir/depend
