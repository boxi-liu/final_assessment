#pragma once
#include <array>
#include <vector>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <armor_interface/msg/armor_points.hpp>

class PnpSolver {
public:
  // 返回 [x, y, z, pitch, yaw, roll]
  std::array<double, 6> solve(const armor_interface::msg::ArmorPoints& pts,
                              const sensor_msgs::msg::CameraInfo& cam);

  // 允许手动设定装甲板实际 3D 大小（单位：米）
  void setArmorSize(double width_m, double height_m) {
    width_ = width_m; height_ = height_m;
  }

private:
  // 将 CameraInfo 转成 cv::Mat
  static void cameraInfoToCv(const sensor_msgs::msg::CameraInfo& cam,
                             cv::Mat& K, cv::Mat& D);

  // 默认小装甲板尺寸（示例：宽 0.135m，高 0.055m，可按比赛标准改）
  double width_  = 0.135;
  double height_ = 0.125;
};
