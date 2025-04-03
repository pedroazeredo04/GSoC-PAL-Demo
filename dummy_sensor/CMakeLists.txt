cmake_minimum_required(VERSION 3.8)
project(dummy_sensor)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(GZ_PLUGIN_VER 2)
set(GZ_COMMON_VER 5)
set(GZ_SIM_VER 8)

find_package(ament_cmake REQUIRED)
find_package(gz-transport13 REQUIRED)
find_package(gz-common${GZ_COMMON_VER} REQUIRED)
find_package(gz-plugin${GZ_PLUGIN_VER} REQUIRED COMPONENTS register)
find_package(gz-sim${GZ_SIM_VER} REQUIRED)  # <--- MISSING DEPENDENCY

add_library(dummy_sensor SHARED 
  src/dummy_sensor.cpp
)

include_directories()

add_compile_options(-Wno-unused-parameter)

target_link_libraries(dummy_sensor PUBLIC
  gz-transport13::gz-transport13
  gz-sim${GZ_SIM_VER}::gz-sim${GZ_SIM_VER}
  gz-common${GZ_COMMON_VER}::gz-common${GZ_COMMON_VER}
  gz-plugin${GZ_PLUGIN_VER}::gz-plugin${GZ_PLUGIN_VER}
)

install(
  TARGETS dummy_sensor
  LIBRARY DESTINATION lib
)

install(
  PROGRAMS
    scripts/wait_for_message.py
  DESTINATION lib/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
