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
CMAKE_SOURCE_DIR = "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/gerador.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gerador.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gerador.dir/flags.make

CMakeFiles/gerador.dir/gerador.cpp.o: CMakeFiles/gerador.dir/flags.make
CMakeFiles/gerador.dir/gerador.cpp.o: ../gerador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gerador.dir/gerador.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gerador.dir/gerador.cpp.o -c "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3/gerador.cpp"

CMakeFiles/gerador.dir/gerador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gerador.dir/gerador.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3/gerador.cpp" > CMakeFiles/gerador.dir/gerador.cpp.i

CMakeFiles/gerador.dir/gerador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gerador.dir/gerador.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3/gerador.cpp" -o CMakeFiles/gerador.dir/gerador.cpp.s

CMakeFiles/gerador.dir/gerador.cpp.o.requires:

.PHONY : CMakeFiles/gerador.dir/gerador.cpp.o.requires

CMakeFiles/gerador.dir/gerador.cpp.o.provides: CMakeFiles/gerador.dir/gerador.cpp.o.requires
	$(MAKE) -f CMakeFiles/gerador.dir/build.make CMakeFiles/gerador.dir/gerador.cpp.o.provides.build
.PHONY : CMakeFiles/gerador.dir/gerador.cpp.o.provides

CMakeFiles/gerador.dir/gerador.cpp.o.provides.build: CMakeFiles/gerador.dir/gerador.cpp.o


# Object files for target gerador
gerador_OBJECTS = \
"CMakeFiles/gerador.dir/gerador.cpp.o"

# External object files for target gerador
gerador_EXTERNAL_OBJECTS =

gerador: CMakeFiles/gerador.dir/gerador.cpp.o
gerador: CMakeFiles/gerador.dir/build.make
gerador: CMakeFiles/gerador.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gerador"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gerador.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gerador.dir/build: gerador

.PHONY : CMakeFiles/gerador.dir/build

CMakeFiles/gerador.dir/requires: CMakeFiles/gerador.dir/gerador.cpp.o.requires

.PHONY : CMakeFiles/gerador.dir/requires

CMakeFiles/gerador.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gerador.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gerador.dir/clean

CMakeFiles/gerador.dir/depend:
	cd "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3" "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3" "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3/cmake-build-debug" "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3/cmake-build-debug" "/Users/JoGomes/Documents/LCC/3º ano/2º semestre/Computação Gráfica/Trabalho/Fase3/gerador3/cmake-build-debug/CMakeFiles/gerador.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/gerador.dir/depend

