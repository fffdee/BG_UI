# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/bango/BanGUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bango/BanGUI/build

# Include any dependencies generated for this target.
include CMakeFiles/BanGUI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BanGUI.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BanGUI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BanGUI.dir/flags.make

CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.o: CMakeFiles/BanGUI.dir/flags.make
CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.o: ../components/BG_List/bg_list.c
CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.o: CMakeFiles/BanGUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bango/BanGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.o -MF CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.o.d -o CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.o -c /home/bango/BanGUI/components/BG_List/bg_list.c

CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bango/BanGUI/components/BG_List/bg_list.c > CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.i

CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bango/BanGUI/components/BG_List/bg_list.c -o CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.s

CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.o: CMakeFiles/BanGUI.dir/flags.make
CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.o: ../components/base_func/gui_tool.c
CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.o: CMakeFiles/BanGUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bango/BanGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.o -MF CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.o.d -o CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.o -c /home/bango/BanGUI/components/base_func/gui_tool.c

CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bango/BanGUI/components/base_func/gui_tool.c > CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.i

CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bango/BanGUI/components/base_func/gui_tool.c -o CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.s

CMakeFiles/BanGUI.dir/emulator/lcd.c.o: CMakeFiles/BanGUI.dir/flags.make
CMakeFiles/BanGUI.dir/emulator/lcd.c.o: ../emulator/lcd.c
CMakeFiles/BanGUI.dir/emulator/lcd.c.o: CMakeFiles/BanGUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bango/BanGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/BanGUI.dir/emulator/lcd.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BanGUI.dir/emulator/lcd.c.o -MF CMakeFiles/BanGUI.dir/emulator/lcd.c.o.d -o CMakeFiles/BanGUI.dir/emulator/lcd.c.o -c /home/bango/BanGUI/emulator/lcd.c

CMakeFiles/BanGUI.dir/emulator/lcd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BanGUI.dir/emulator/lcd.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bango/BanGUI/emulator/lcd.c > CMakeFiles/BanGUI.dir/emulator/lcd.c.i

CMakeFiles/BanGUI.dir/emulator/lcd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BanGUI.dir/emulator/lcd.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bango/BanGUI/emulator/lcd.c -o CMakeFiles/BanGUI.dir/emulator/lcd.c.s

CMakeFiles/BanGUI.dir/keyinput/input_handle.c.o: CMakeFiles/BanGUI.dir/flags.make
CMakeFiles/BanGUI.dir/keyinput/input_handle.c.o: ../keyinput/input_handle.c
CMakeFiles/BanGUI.dir/keyinput/input_handle.c.o: CMakeFiles/BanGUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bango/BanGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/BanGUI.dir/keyinput/input_handle.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BanGUI.dir/keyinput/input_handle.c.o -MF CMakeFiles/BanGUI.dir/keyinput/input_handle.c.o.d -o CMakeFiles/BanGUI.dir/keyinput/input_handle.c.o -c /home/bango/BanGUI/keyinput/input_handle.c

CMakeFiles/BanGUI.dir/keyinput/input_handle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BanGUI.dir/keyinput/input_handle.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bango/BanGUI/keyinput/input_handle.c > CMakeFiles/BanGUI.dir/keyinput/input_handle.c.i

CMakeFiles/BanGUI.dir/keyinput/input_handle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BanGUI.dir/keyinput/input_handle.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bango/BanGUI/keyinput/input_handle.c -o CMakeFiles/BanGUI.dir/keyinput/input_handle.c.s

CMakeFiles/BanGUI.dir/src/main.c.o: CMakeFiles/BanGUI.dir/flags.make
CMakeFiles/BanGUI.dir/src/main.c.o: ../src/main.c
CMakeFiles/BanGUI.dir/src/main.c.o: CMakeFiles/BanGUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bango/BanGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/BanGUI.dir/src/main.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BanGUI.dir/src/main.c.o -MF CMakeFiles/BanGUI.dir/src/main.c.o.d -o CMakeFiles/BanGUI.dir/src/main.c.o -c /home/bango/BanGUI/src/main.c

CMakeFiles/BanGUI.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BanGUI.dir/src/main.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bango/BanGUI/src/main.c > CMakeFiles/BanGUI.dir/src/main.c.i

CMakeFiles/BanGUI.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BanGUI.dir/src/main.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bango/BanGUI/src/main.c -o CMakeFiles/BanGUI.dir/src/main.c.s

# Object files for target BanGUI
BanGUI_OBJECTS = \
"CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.o" \
"CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.o" \
"CMakeFiles/BanGUI.dir/emulator/lcd.c.o" \
"CMakeFiles/BanGUI.dir/keyinput/input_handle.c.o" \
"CMakeFiles/BanGUI.dir/src/main.c.o"

# External object files for target BanGUI
BanGUI_EXTERNAL_OBJECTS =

BanGUI: CMakeFiles/BanGUI.dir/components/BG_List/bg_list.c.o
BanGUI: CMakeFiles/BanGUI.dir/components/base_func/gui_tool.c.o
BanGUI: CMakeFiles/BanGUI.dir/emulator/lcd.c.o
BanGUI: CMakeFiles/BanGUI.dir/keyinput/input_handle.c.o
BanGUI: CMakeFiles/BanGUI.dir/src/main.c.o
BanGUI: CMakeFiles/BanGUI.dir/build.make
BanGUI: CMakeFiles/BanGUI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bango/BanGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable BanGUI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BanGUI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BanGUI.dir/build: BanGUI
.PHONY : CMakeFiles/BanGUI.dir/build

CMakeFiles/BanGUI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BanGUI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BanGUI.dir/clean

CMakeFiles/BanGUI.dir/depend:
	cd /home/bango/BanGUI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bango/BanGUI /home/bango/BanGUI /home/bango/BanGUI/build /home/bango/BanGUI/build /home/bango/BanGUI/build/CMakeFiles/BanGUI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BanGUI.dir/depend

