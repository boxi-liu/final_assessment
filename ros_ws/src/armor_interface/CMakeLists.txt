cmake_minimum_required(VERSION 3.5)
project(armor_interface)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/ArmorPose.msg"
  "msg/ArmorPoints.msg"
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
