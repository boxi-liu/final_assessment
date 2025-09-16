#include "pnp_solve/pnp_solve.hpp"
#include <cmath>

using sensor_msgs::msg::CameraInfo;
using armor_interface::msg::ArmorPoints;

static inline cv::Mat eulerFromR(const cv::Mat& R){
  // 采用 ZYX 欧拉角（roll around X, pitch around Y, yaw around Z）
  double sy = std::sqrt(R.at<double>(0,0)*R.at<double>(0,0) + R.at<double>(1,0)*R.at<double>(1,0));
  bool singular = sy < 1e-6;
  double x, y, z; // roll, pitch, yaw
  if(!singular){
    x = std::atan2(R.at<double>(2,1), R.at<double>(2,2));
    y = std::atan2(-R.at<double>(2,0), sy);
    z = std::atan2(R.at<double>(1,0), R.at<double>(0,0));
  }else{
    x = std::atan2(-R.at<double>(1,2), R.at<double>(1,1));
    y = std::atan2(-R.at<double>(2,0), sy);
    z = 0;
  }
  cv::Mat e = (cv::Mat_<double>(3,1) << x, y, z); // roll, pitch, yaw
  return e;
}

void PnpSolver::cameraInfoToCv(const CameraInfo& cam, cv::Mat& K, cv::Mat& D){
  K = (cv::Mat_<double>(3,3) <<
       cam.k[0], cam.k[1], cam.k[2],
       cam.k[3], cam.k[4], cam.k[5],
       cam.k[6], cam.k[7], cam.k[8]);
  // 假定使用前 5 个畸变参数（k1,k2,t1,t2,k3），不足则补 0
  D = cv::Mat::zeros(1, (int)cam.d.size(), CV_64F);
  for(size_t i=0;i<cam.d.size();++i) D.at<double>(0,(int)i) = cam.d[i];
  if(D.cols==0){ D = cv::Mat::zeros(1,5,CV_64F); }
}

std::array<double,6> PnpSolver::solve(const ArmorPoints& pts, const CameraInfo& cam){
  // 1) 构建物体坐标系下 3D 角点（以装甲板中心为原点，Z 朝外）
  double w = width_/2.0, h = height_/2.0;
  std::vector<cv::Point3d> obj{
    {-w,  h, 0}, // left_top
    {-w, -h, 0}, // left_bottom
    { w, -h, 0}, // right_bottom
    { w,  h, 0}  // right_top
  };

  // 2) 像素坐标按同一顺序组织
  std::vector<cv::Point2d> img{
    { (double)pts.left_top_x,     (double)pts.left_top_y },
    { (double)pts.left_bottom_x,  (double)pts.left_bottom_y },
    { (double)pts.right_bottom_x, (double)pts.right_bottom_y },
    { (double)pts.right_top_x,    (double)pts.right_top_y }
  };

  // 3) 相机内参、畸变
  cv::Mat K, D;
  cameraInfoToCv(cam, K, D);

  // 4) PnP
  cv::Mat rvec, tvec;
  bool ok = cv::solvePnP(obj, img, K, D, rvec, tvec, false, cv::SOLVEPNP_IPPE_SQUARE);
  if(!ok){
    // 失败时返回 NaN
    return {NAN, NAN, NAN, NAN, NAN, NAN};
  }

  // 5) rvec->R, R->欧拉角（roll,pitch,yaw）
  cv::Mat R;
  cv::Rodrigues(rvec, R);
  R.convertTo(R, CV_64F);
  cv::Mat e = eulerFromR(R); // x=roll, y=pitch, z=yaw

  // 6) 返回 [x, y, z, pitch, yaw, roll]
  double x = tvec.at<double>(0), y = tvec.at<double>(1), z = tvec.at<double>(2);
  double roll  = e.at<double>(0);
  double pitch = e.at<double>(1);
  double yaw   = e.at<double>(2);
  return {x, y, z, pitch, yaw, roll};
}
