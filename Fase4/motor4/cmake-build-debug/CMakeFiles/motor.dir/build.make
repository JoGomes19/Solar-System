# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/motor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/motor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/motor.dir/flags.make

CMakeFiles/motor.dir/motor.cpp.o: CMakeFiles/motor.dir/flags.make
CMakeFiles/motor.dir/motor.cpp.o: ../motor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/motor.dir/motor.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motor.dir/motor.cpp.o -c "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/motor.cpp"

CMakeFiles/motor.dir/motor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motor.dir/motor.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/motor.cpp" > CMakeFiles/motor.dir/motor.cpp.i

CMakeFiles/motor.dir/motor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motor.dir/motor.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/motor.cpp" -o CMakeFiles/motor.dir/motor.cpp.s

CMakeFiles/motor.dir/motor.cpp.o.requires:

.PHONY : CMakeFiles/motor.dir/motor.cpp.o.requires

CMakeFiles/motor.dir/motor.cpp.o.provides: CMakeFiles/motor.dir/motor.cpp.o.requires
	$(MAKE) -f CMakeFiles/motor.dir/build.make CMakeFiles/motor.dir/motor.cpp.o.provides.build
.PHONY : CMakeFiles/motor.dir/motor.cpp.o.provides

CMakeFiles/motor.dir/motor.cpp.o.provides.build: CMakeFiles/motor.dir/motor.cpp.o


CMakeFiles/motor.dir/tinystr.cpp.o: CMakeFiles/motor.dir/flags.make
CMakeFiles/motor.dir/tinystr.cpp.o: ../tinystr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/motor.dir/tinystr.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motor.dir/tinystr.cpp.o -c "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/tinystr.cpp"

CMakeFiles/motor.dir/tinystr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motor.dir/tinystr.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/tinystr.cpp" > CMakeFiles/motor.dir/tinystr.cpp.i

CMakeFiles/motor.dir/tinystr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motor.dir/tinystr.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/tinystr.cpp" -o CMakeFiles/motor.dir/tinystr.cpp.s

CMakeFiles/motor.dir/tinystr.cpp.o.requires:

.PHONY : CMakeFiles/motor.dir/tinystr.cpp.o.requires

CMakeFiles/motor.dir/tinystr.cpp.o.provides: CMakeFiles/motor.dir/tinystr.cpp.o.requires
	$(MAKE) -f CMakeFiles/motor.dir/build.make CMakeFiles/motor.dir/tinystr.cpp.o.provides.build
.PHONY : CMakeFiles/motor.dir/tinystr.cpp.o.provides

CMakeFiles/motor.dir/tinystr.cpp.o.provides.build: CMakeFiles/motor.dir/tinystr.cpp.o


CMakeFiles/motor.dir/tinyxml2.cpp.o: CMakeFiles/motor.dir/flags.make
CMakeFiles/motor.dir/tinyxml2.cpp.o: ../tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/motor.dir/tinyxml2.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motor.dir/tinyxml2.cpp.o -c "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/tinyxml2.cpp"

CMakeFiles/motor.dir/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motor.dir/tinyxml2.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/tinyxml2.cpp" > CMakeFiles/motor.dir/tinyxml2.cpp.i

CMakeFiles/motor.dir/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motor.dir/tinyxml2.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/tinyxml2.cpp" -o CMakeFiles/motor.dir/tinyxml2.cpp.s

CMakeFiles/motor.dir/tinyxml2.cpp.o.requires:

.PHONY : CMakeFiles/motor.dir/tinyxml2.cpp.o.requires

CMakeFiles/motor.dir/tinyxml2.cpp.o.provides: CMakeFiles/motor.dir/tinyxml2.cpp.o.requires
	$(MAKE) -f CMakeFiles/motor.dir/build.make CMakeFiles/motor.dir/tinyxml2.cpp.o.provides.build
.PHONY : CMakeFiles/motor.dir/tinyxml2.cpp.o.provides

CMakeFiles/motor.dir/tinyxml2.cpp.o.provides.build: CMakeFiles/motor.dir/tinyxml2.cpp.o


# Object files for target motor
motor_OBJECTS = \
"CMakeFiles/motor.dir/motor.cpp.o" \
"CMakeFiles/motor.dir/tinystr.cpp.o" \
"CMakeFiles/motor.dir/tinyxml2.cpp.o"

# External object files for target motor
motor_EXTERNAL_OBJECTS =

motor: CMakeFiles/motor.dir/motor.cpp.o
motor: CMakeFiles/motor.dir/tinystr.cpp.o
motor: CMakeFiles/motor.dir/tinyxml2.cpp.o
motor: CMakeFiles/motor.dir/build.make
motor: /usr/local/lib/libIL.dylib
motor: CMakeFiles/motor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable motor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/motor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/motor.dir/build: motor

.PHONY : CMakeFiles/motor.dir/build

CMakeFiles/motor.dir/requires: CMakeFiles/motor.dir/motor.cpp.o.requires
CMakeFiles/motor.dir/requires: CMakeFiles/motor.dir/tinystr.cpp.o.requires
CMakeFiles/motor.dir/requires: CMakeFiles/motor.dir/tinyxml2.cpp.o.requires

.PHONY : CMakeFiles/motor.dir/requires

CMakeFiles/motor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/motor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/motor.dir/clean

CMakeFiles/motor.dir/depend:
	cd "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4" "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4" "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/cmake-build-debug" "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/cmake-build-debug" "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase4/motor4/cmake-build-debug/CMakeFiles/motor.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/motor.dir/depend

