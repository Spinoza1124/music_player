# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liuyang/code/vscode_project/music_player

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liuyang/code/vscode_project/music_player/build

# Utility rule file for music_player_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/music_player_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/music_player_autogen.dir/progress.make

CMakeFiles/music_player_autogen: music_player_autogen/timestamp

music_player_autogen/timestamp: /usr/lib/qt6/libexec/moc
music_player_autogen/timestamp: /usr/lib/qt6/libexec/uic
music_player_autogen/timestamp: CMakeFiles/music_player_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/liuyang/code/vscode_project/music_player/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target music_player"
	/usr/bin/cmake -E cmake_autogen /home/liuyang/code/vscode_project/music_player/build/CMakeFiles/music_player_autogen.dir/AutogenInfo.json Debug
	/usr/bin/cmake -E touch /home/liuyang/code/vscode_project/music_player/build/music_player_autogen/timestamp

music_player_autogen: CMakeFiles/music_player_autogen
music_player_autogen: music_player_autogen/timestamp
music_player_autogen: CMakeFiles/music_player_autogen.dir/build.make
.PHONY : music_player_autogen

# Rule to build all files generated by this target.
CMakeFiles/music_player_autogen.dir/build: music_player_autogen
.PHONY : CMakeFiles/music_player_autogen.dir/build

CMakeFiles/music_player_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/music_player_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/music_player_autogen.dir/clean

CMakeFiles/music_player_autogen.dir/depend:
	cd /home/liuyang/code/vscode_project/music_player/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuyang/code/vscode_project/music_player /home/liuyang/code/vscode_project/music_player /home/liuyang/code/vscode_project/music_player/build /home/liuyang/code/vscode_project/music_player/build /home/liuyang/code/vscode_project/music_player/build/CMakeFiles/music_player_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/music_player_autogen.dir/depend

