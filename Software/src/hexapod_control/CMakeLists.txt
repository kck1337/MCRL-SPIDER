cmake_minimum_required(VERSION 3.5)
project(hexapod_control)

# use C++17 standard in order to use inline
set(CMAKE_CXX_STANDARD 17)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(hexapod_msgs REQUIRED)
find_package(dynamixel_sdk REQUIRED)

include_directories(include)

add_library( lib1 SHARED
src/ik.cpp
src/gait.cpp
src/servo_driver.cpp
src/motion_control.cpp )

ament_target_dependencies( lib1
"hexapod_msgs"
"geometry_msgs"
"sensor_msgs"
"dynamixel_sdk"
"rclcpp"
)

set(HEXAPOD_CONTROL_EXE_SRC
  src/hexapod_controller.cpp
)

# generate stand-alone executable
add_executable(${PROJECT_NAME}_exe
  ${HEXAPOD_CONTROL_EXE_SRC}
)

target_link_libraries(${PROJECT_NAME}_exe
  lib1
)

ament_target_dependencies( ${PROJECT_NAME}_exe
"hexapod_msgs"
"sensor_msgs"
"rclcpp"
)

# ros2 run only looks in the “libexec” folder (actually lib/pkg)
# https://discourse.ros.org/t/ros2-cmakelist-command-line-publish-metapackages-revised-heading/2640
install(TARGETS
  lib1
  ${PROJECT_NAME}_exe
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  params
  DESTINATION share/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  find_package(ament_cmake_gtest)
  set(TEST_SOURCES
    test/gtest_main.cpp
    test/test_ik.cpp
    test/test_gait.cpp
    test/test_gait_turning.cpp
    test/test_motion.cpp
  )
  set(TEST_HEXAPOD_CONTROL_EXE
    test_hexa
  )
  ament_add_gtest(${TEST_HEXAPOD_CONTROL_EXE} ${TEST_SOURCES})
  target_link_libraries(${TEST_HEXAPOD_CONTROL_EXE}
    lib1
  )
endif()

ament_package()
