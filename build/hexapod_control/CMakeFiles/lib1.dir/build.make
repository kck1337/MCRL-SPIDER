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
CMAKE_SOURCE_DIR = /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mustafa/Documents/GitHub/MCRL-SPIDER/build/hexapod_control

# Include any dependencies generated for this target.
include CMakeFiles/lib1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lib1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lib1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lib1.dir/flags.make

CMakeFiles/lib1.dir/src/ik.cpp.o: CMakeFiles/lib1.dir/flags.make
CMakeFiles/lib1.dir/src/ik.cpp.o: /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/ik.cpp
CMakeFiles/lib1.dir/src/ik.cpp.o: CMakeFiles/lib1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mustafa/Documents/GitHub/MCRL-SPIDER/build/hexapod_control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lib1.dir/src/ik.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lib1.dir/src/ik.cpp.o -MF CMakeFiles/lib1.dir/src/ik.cpp.o.d -o CMakeFiles/lib1.dir/src/ik.cpp.o -c /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/ik.cpp

CMakeFiles/lib1.dir/src/ik.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib1.dir/src/ik.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/ik.cpp > CMakeFiles/lib1.dir/src/ik.cpp.i

CMakeFiles/lib1.dir/src/ik.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib1.dir/src/ik.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/ik.cpp -o CMakeFiles/lib1.dir/src/ik.cpp.s

CMakeFiles/lib1.dir/src/gait.cpp.o: CMakeFiles/lib1.dir/flags.make
CMakeFiles/lib1.dir/src/gait.cpp.o: /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/gait.cpp
CMakeFiles/lib1.dir/src/gait.cpp.o: CMakeFiles/lib1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mustafa/Documents/GitHub/MCRL-SPIDER/build/hexapod_control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lib1.dir/src/gait.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lib1.dir/src/gait.cpp.o -MF CMakeFiles/lib1.dir/src/gait.cpp.o.d -o CMakeFiles/lib1.dir/src/gait.cpp.o -c /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/gait.cpp

CMakeFiles/lib1.dir/src/gait.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib1.dir/src/gait.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/gait.cpp > CMakeFiles/lib1.dir/src/gait.cpp.i

CMakeFiles/lib1.dir/src/gait.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib1.dir/src/gait.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/gait.cpp -o CMakeFiles/lib1.dir/src/gait.cpp.s

CMakeFiles/lib1.dir/src/servo_driver.cpp.o: CMakeFiles/lib1.dir/flags.make
CMakeFiles/lib1.dir/src/servo_driver.cpp.o: /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/servo_driver.cpp
CMakeFiles/lib1.dir/src/servo_driver.cpp.o: CMakeFiles/lib1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mustafa/Documents/GitHub/MCRL-SPIDER/build/hexapod_control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lib1.dir/src/servo_driver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lib1.dir/src/servo_driver.cpp.o -MF CMakeFiles/lib1.dir/src/servo_driver.cpp.o.d -o CMakeFiles/lib1.dir/src/servo_driver.cpp.o -c /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/servo_driver.cpp

CMakeFiles/lib1.dir/src/servo_driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib1.dir/src/servo_driver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/servo_driver.cpp > CMakeFiles/lib1.dir/src/servo_driver.cpp.i

CMakeFiles/lib1.dir/src/servo_driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib1.dir/src/servo_driver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/servo_driver.cpp -o CMakeFiles/lib1.dir/src/servo_driver.cpp.s

CMakeFiles/lib1.dir/src/motion_control.cpp.o: CMakeFiles/lib1.dir/flags.make
CMakeFiles/lib1.dir/src/motion_control.cpp.o: /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/motion_control.cpp
CMakeFiles/lib1.dir/src/motion_control.cpp.o: CMakeFiles/lib1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mustafa/Documents/GitHub/MCRL-SPIDER/build/hexapod_control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lib1.dir/src/motion_control.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lib1.dir/src/motion_control.cpp.o -MF CMakeFiles/lib1.dir/src/motion_control.cpp.o.d -o CMakeFiles/lib1.dir/src/motion_control.cpp.o -c /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/motion_control.cpp

CMakeFiles/lib1.dir/src/motion_control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib1.dir/src/motion_control.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/motion_control.cpp > CMakeFiles/lib1.dir/src/motion_control.cpp.i

CMakeFiles/lib1.dir/src/motion_control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib1.dir/src/motion_control.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control/src/motion_control.cpp -o CMakeFiles/lib1.dir/src/motion_control.cpp.s

# Object files for target lib1
lib1_OBJECTS = \
"CMakeFiles/lib1.dir/src/ik.cpp.o" \
"CMakeFiles/lib1.dir/src/gait.cpp.o" \
"CMakeFiles/lib1.dir/src/servo_driver.cpp.o" \
"CMakeFiles/lib1.dir/src/motion_control.cpp.o"

# External object files for target lib1
lib1_EXTERNAL_OBJECTS =

liblib1.so: CMakeFiles/lib1.dir/src/ik.cpp.o
liblib1.so: CMakeFiles/lib1.dir/src/gait.cpp.o
liblib1.so: CMakeFiles/lib1.dir/src/servo_driver.cpp.o
liblib1.so: CMakeFiles/lib1.dir/src/motion_control.cpp.o
liblib1.so: CMakeFiles/lib1.dir/build.make
liblib1.so: /home/mustafa/Documents/GitHub/MCRL-SPIDER/install/hexapod_msgs/lib/libhexapod_msgs__rosidl_typesupport_fastrtps_c.so
liblib1.so: /home/mustafa/Documents/GitHub/MCRL-SPIDER/install/hexapod_msgs/lib/libhexapod_msgs__rosidl_typesupport_fastrtps_cpp.so
liblib1.so: /home/mustafa/Documents/GitHub/MCRL-SPIDER/install/hexapod_msgs/lib/libhexapod_msgs__rosidl_typesupport_introspection_c.so
liblib1.so: /home/mustafa/Documents/GitHub/MCRL-SPIDER/install/hexapod_msgs/lib/libhexapod_msgs__rosidl_typesupport_introspection_cpp.so
liblib1.so: /home/mustafa/Documents/GitHub/MCRL-SPIDER/install/hexapod_msgs/lib/libhexapod_msgs__rosidl_typesupport_cpp.so
liblib1.so: /home/mustafa/Documents/GitHub/MCRL-SPIDER/install/hexapod_msgs/lib/libhexapod_msgs__rosidl_generator_py.so
liblib1.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_fastrtps_c.so
liblib1.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_fastrtps_cpp.so
liblib1.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_introspection_c.so
liblib1.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_introspection_cpp.so
liblib1.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_generator_py.so
liblib1.so: /opt/ros/humble/lib/librclcpp.so
liblib1.so: /home/mustafa/Documents/GitHub/MCRL-SPIDER/install/dynamixel_sdk/lib/libdynamixel_sdk.so
liblib1.so: /home/mustafa/Documents/GitHub/MCRL-SPIDER/install/hexapod_msgs/lib/libhexapod_msgs__rosidl_typesupport_c.so
liblib1.so: /home/mustafa/Documents/GitHub/MCRL-SPIDER/install/hexapod_msgs/lib/libhexapod_msgs__rosidl_generator_c.so
liblib1.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_fastrtps_c.so
liblib1.so: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_fastrtps_c.so
liblib1.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_fastrtps_cpp.so
liblib1.so: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_fastrtps_cpp.so
liblib1.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_introspection_c.so
liblib1.so: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
liblib1.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_introspection_cpp.so
liblib1.so: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
liblib1.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_generator_py.so
liblib1.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_c.so
liblib1.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_c.so
liblib1.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_generator_c.so
liblib1.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_generator_c.so
liblib1.so: /opt/ros/humble/lib/libstd_msgs__rosidl_generator_py.so
liblib1.so: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_c.so
liblib1.so: /opt/ros/humble/lib/libstd_msgs__rosidl_generator_c.so
liblib1.so: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_cpp.so
liblib1.so: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_cpp.so
liblib1.so: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_cpp.so
liblib1.so: /opt/ros/humble/lib/liblibstatistics_collector.so
liblib1.so: /opt/ros/humble/lib/librcl.so
liblib1.so: /opt/ros/humble/lib/librmw_implementation.so
liblib1.so: /opt/ros/humble/lib/libament_index_cpp.so
liblib1.so: /opt/ros/humble/lib/librcl_logging_spdlog.so
liblib1.so: /opt/ros/humble/lib/librcl_logging_interface.so
liblib1.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_fastrtps_c.so
liblib1.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_introspection_c.so
liblib1.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_fastrtps_cpp.so
liblib1.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_introspection_cpp.so
liblib1.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_cpp.so
liblib1.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_generator_py.so
liblib1.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_c.so
liblib1.so: /opt/ros/humble/lib/librcl_interfaces__rosidl_generator_c.so
liblib1.so: /opt/ros/humble/lib/librcl_yaml_param_parser.so
liblib1.so: /opt/ros/humble/lib/libyaml.so
liblib1.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_c.so
liblib1.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_cpp.so
liblib1.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so
liblib1.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so
liblib1.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_cpp.so
liblib1.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_generator_py.so
liblib1.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_c.so
liblib1.so: /opt/ros/humble/lib/librosgraph_msgs__rosidl_generator_c.so
liblib1.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_c.so
liblib1.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_c.so
liblib1.so: /opt/ros/humble/lib/librosidl_typesupport_fastrtps_c.so
liblib1.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_cpp.so
liblib1.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_cpp.so
liblib1.so: /opt/ros/humble/lib/librosidl_typesupport_fastrtps_cpp.so
liblib1.so: /opt/ros/humble/lib/libfastcdr.so.1.0.24
liblib1.so: /opt/ros/humble/lib/librmw.so
liblib1.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so
liblib1.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
liblib1.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so
liblib1.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
liblib1.so: /opt/ros/humble/lib/librosidl_typesupport_introspection_cpp.so
liblib1.so: /opt/ros/humble/lib/librosidl_typesupport_introspection_c.so
liblib1.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_cpp.so
liblib1.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
liblib1.so: /opt/ros/humble/lib/librosidl_typesupport_cpp.so
liblib1.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_generator_py.so
liblib1.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_generator_py.so
liblib1.so: /usr/lib/x86_64-linux-gnu/libpython3.10.so
liblib1.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_c.so
liblib1.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
liblib1.so: /opt/ros/humble/lib/libstatistics_msgs__rosidl_generator_c.so
liblib1.so: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_generator_c.so
liblib1.so: /opt/ros/humble/lib/librosidl_typesupport_c.so
liblib1.so: /opt/ros/humble/lib/librosidl_runtime_c.so
liblib1.so: /opt/ros/humble/lib/librcpputils.so
liblib1.so: /opt/ros/humble/lib/librcutils.so
liblib1.so: /opt/ros/humble/lib/libtracetools.so
liblib1.so: CMakeFiles/lib1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mustafa/Documents/GitHub/MCRL-SPIDER/build/hexapod_control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library liblib1.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lib1.dir/build: liblib1.so
.PHONY : CMakeFiles/lib1.dir/build

CMakeFiles/lib1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lib1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lib1.dir/clean

CMakeFiles/lib1.dir/depend:
	cd /home/mustafa/Documents/GitHub/MCRL-SPIDER/build/hexapod_control && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control /home/mustafa/Documents/GitHub/MCRL-SPIDER/Software/src/hexapod_control /home/mustafa/Documents/GitHub/MCRL-SPIDER/build/hexapod_control /home/mustafa/Documents/GitHub/MCRL-SPIDER/build/hexapod_control /home/mustafa/Documents/GitHub/MCRL-SPIDER/build/hexapod_control/CMakeFiles/lib1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lib1.dir/depend
