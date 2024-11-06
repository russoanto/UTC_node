cmake_minimum_required(VERSION 3.5)
project(utc_time_example)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(builtin_interfaces REQUIRED)

add_executable(utc_time_publisher src/utc_time_publisher.cpp)
ament_target_dependencies(utc_time_publisher rclcpp builtin_interfaces)


install(TARGETS
  utc_time_publisher
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

