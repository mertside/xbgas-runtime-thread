# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/meside/xbgas-runtime-thread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/meside/xbgas-runtime-thread/build

# Include any dependencies generated for this target.
include src/xbgas-runtime/CMakeFiles/xbrtime.dir/depend.make

# Include the progress variables for this target.
include src/xbgas-runtime/CMakeFiles/xbrtime.dir/progress.make

# Include the compile flags for this target's objects.
include src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_init.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_init.c.o: ../src/xbgas-runtime/xbrtime_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_init.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_init.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_init.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_init.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_init.c > CMakeFiles/xbrtime.dir/xbrtime_init.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_init.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_init.c -o CMakeFiles/xbrtime.dir/xbrtime_init.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_ctor.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_ctor.c.o: ../src/xbgas-runtime/xbrtime_ctor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_ctor.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_ctor.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_ctor.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_ctor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_ctor.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_ctor.c > CMakeFiles/xbrtime.dir/xbrtime_ctor.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_ctor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_ctor.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_ctor.c -o CMakeFiles/xbrtime.dir/xbrtime_ctor.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_util.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_util.c.o: ../src/xbgas-runtime/xbrtime_util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_util.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_util.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_util.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_util.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_util.c > CMakeFiles/xbrtime.dir/xbrtime_util.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_util.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_util.c -o CMakeFiles/xbrtime.dir/xbrtime_util.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_api.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_api.c.o: ../src/xbgas-runtime/xbrtime_api.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_api.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_api.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_api.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_api.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_api.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_api.c > CMakeFiles/xbrtime.dir/xbrtime_api.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_api.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_api.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_api.c -o CMakeFiles/xbrtime.dir/xbrtime_api.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_alloc.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_alloc.c.o: ../src/xbgas-runtime/xbrtime_alloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_alloc.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_alloc.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_alloc.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_alloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_alloc.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_alloc.c > CMakeFiles/xbrtime.dir/xbrtime_alloc.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_alloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_alloc.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_alloc.c -o CMakeFiles/xbrtime.dir/xbrtime_alloc.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_barrier.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_barrier.c.o: ../src/xbgas-runtime/xbrtime_barrier.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_barrier.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_barrier.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_barrier.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_barrier.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_barrier.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_barrier.c > CMakeFiles/xbrtime.dir/xbrtime_barrier.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_barrier.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_barrier.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_barrier.c -o CMakeFiles/xbrtime.dir/xbrtime_barrier.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_atomics.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_atomics.c.o: ../src/xbgas-runtime/xbrtime_atomics.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_atomics.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_atomics.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_atomics.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_atomics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_atomics.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_atomics.c > CMakeFiles/xbrtime.dir/xbrtime_atomics.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_atomics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_atomics.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_atomics.c -o CMakeFiles/xbrtime.dir/xbrtime_atomics.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_alltoall.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_alltoall.c.o: ../src/xbgas-runtime/xbrtime_alltoall.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_alltoall.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_alltoall.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_alltoall.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_alltoall.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_alltoall.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_alltoall.c > CMakeFiles/xbrtime.dir/xbrtime_alltoall.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_alltoall.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_alltoall.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_alltoall.c -o CMakeFiles/xbrtime.dir/xbrtime_alltoall.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_broadcast.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_broadcast.c.o: ../src/xbgas-runtime/xbrtime_broadcast.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_broadcast.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_broadcast.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_broadcast.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_broadcast.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_broadcast.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_broadcast.c > CMakeFiles/xbrtime.dir/xbrtime_broadcast.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_broadcast.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_broadcast.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_broadcast.c -o CMakeFiles/xbrtime.dir/xbrtime_broadcast.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_gather.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_gather.c.o: ../src/xbgas-runtime/xbrtime_gather.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_gather.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_gather.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_gather.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_gather.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_gather.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_gather.c > CMakeFiles/xbrtime.dir/xbrtime_gather.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_gather.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_gather.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_gather.c -o CMakeFiles/xbrtime.dir/xbrtime_gather.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_gather_all.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_gather_all.c.o: ../src/xbgas-runtime/xbrtime_gather_all.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_gather_all.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_gather_all.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_gather_all.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_gather_all.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_gather_all.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_gather_all.c > CMakeFiles/xbrtime.dir/xbrtime_gather_all.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_gather_all.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_gather_all.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_gather_all.c -o CMakeFiles/xbrtime.dir/xbrtime_gather_all.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_reduce.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_reduce.c.o: ../src/xbgas-runtime/xbrtime_reduce.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_reduce.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_reduce.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_reduce.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_reduce.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_reduce.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_reduce.c > CMakeFiles/xbrtime.dir/xbrtime_reduce.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_reduce.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_reduce.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_reduce.c -o CMakeFiles/xbrtime.dir/xbrtime_reduce.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_reduce_all.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_reduce_all.c.o: ../src/xbgas-runtime/xbrtime_reduce_all.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_reduce_all.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_reduce_all.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_reduce_all.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_reduce_all.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_reduce_all.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_reduce_all.c > CMakeFiles/xbrtime.dir/xbrtime_reduce_all.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_reduce_all.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_reduce_all.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_reduce_all.c -o CMakeFiles/xbrtime.dir/xbrtime_reduce_all.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_scatter.c.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_scatter.c.o: ../src/xbgas-runtime/xbrtime_scatter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_scatter.c.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_scatter.c.o   -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_scatter.c

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_scatter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xbrtime.dir/xbrtime_scatter.c.i"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_scatter.c > CMakeFiles/xbrtime.dir/xbrtime_scatter.c.i

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_scatter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xbrtime.dir/xbrtime_scatter.c.s"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_scatter.c -o CMakeFiles/xbrtime.dir/xbrtime_scatter.c.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_ctor_asm.s.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_ctor_asm.s.o: ../src/xbgas-runtime/xbrtime_ctor_asm.s
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building ASM object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_ctor_asm.s.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_ctor_asm.s.o -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_ctor_asm.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_util_asm.s.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_util_asm.s.o: ../src/xbgas-runtime/xbrtime_util_asm.s
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building ASM object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_util_asm.s.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_util_asm.s.o -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_util_asm.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_api_asm.s.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_api_asm.s.o: ../src/xbgas-runtime/xbrtime_api_asm.s
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building ASM object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_api_asm.s.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_api_asm.s.o -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_api_asm.s

src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_atomics_asm.s.o: src/xbgas-runtime/CMakeFiles/xbrtime.dir/flags.make
src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_atomics_asm.s.o: ../src/xbgas-runtime/xbrtime_atomics_asm.s
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building ASM object src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_atomics_asm.s.o"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && /usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/xbrtime.dir/xbrtime_atomics_asm.s.o -c /home/meside/xbgas-runtime-thread/src/xbgas-runtime/xbrtime_atomics_asm.s

# Object files for target xbrtime
xbrtime_OBJECTS = \
"CMakeFiles/xbrtime.dir/xbrtime_init.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_ctor.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_util.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_api.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_alloc.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_barrier.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_atomics.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_alltoall.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_broadcast.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_gather.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_gather_all.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_reduce.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_reduce_all.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_scatter.c.o" \
"CMakeFiles/xbrtime.dir/xbrtime_ctor_asm.s.o" \
"CMakeFiles/xbrtime.dir/xbrtime_util_asm.s.o" \
"CMakeFiles/xbrtime.dir/xbrtime_api_asm.s.o" \
"CMakeFiles/xbrtime.dir/xbrtime_atomics_asm.s.o"

# External object files for target xbrtime
xbrtime_EXTERNAL_OBJECTS =

src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_init.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_ctor.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_util.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_api.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_alloc.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_barrier.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_atomics.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_alltoall.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_broadcast.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_gather.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_gather_all.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_reduce.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_reduce_all.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_scatter.c.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_ctor_asm.s.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_util_asm.s.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_api_asm.s.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/xbrtime_atomics_asm.s.o
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/build.make
src/xbgas-runtime/libxbrtime.a: src/xbgas-runtime/CMakeFiles/xbrtime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/meside/xbgas-runtime-thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking C static library libxbrtime.a"
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && $(CMAKE_COMMAND) -P CMakeFiles/xbrtime.dir/cmake_clean_target.cmake
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xbrtime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/xbgas-runtime/CMakeFiles/xbrtime.dir/build: src/xbgas-runtime/libxbrtime.a

.PHONY : src/xbgas-runtime/CMakeFiles/xbrtime.dir/build

src/xbgas-runtime/CMakeFiles/xbrtime.dir/clean:
	cd /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime && $(CMAKE_COMMAND) -P CMakeFiles/xbrtime.dir/cmake_clean.cmake
.PHONY : src/xbgas-runtime/CMakeFiles/xbrtime.dir/clean

src/xbgas-runtime/CMakeFiles/xbrtime.dir/depend:
	cd /home/meside/xbgas-runtime-thread/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/meside/xbgas-runtime-thread /home/meside/xbgas-runtime-thread/src/xbgas-runtime /home/meside/xbgas-runtime-thread/build /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime /home/meside/xbgas-runtime-thread/build/src/xbgas-runtime/CMakeFiles/xbrtime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/xbgas-runtime/CMakeFiles/xbrtime.dir/depend
