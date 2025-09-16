cmake_minimum_required(VERSION 3.8)
project(subscriber)

# 依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(armor_interface REQUIRED)

# 自己写的功能包
find_package(pnp_solve REQUIRED)

find_package(kf_solve REQUIRED)



# 可执行文件
add_executable(armor_pose_solver src/subscriber.cpp)

target_include_directories(armor_pose_solver PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# 链接依赖
ament_target_dependencies(armor_pose_solver
  rclcpp
  sensor_msgs
  armor_interface
  pnp_solve
  kf_solve
)

# 安装
install(TARGETS armor_pose_solver
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
