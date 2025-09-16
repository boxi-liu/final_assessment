#pragma once
#include <array>
#include <Eigen/Dense>

class KalmanFilter {
public:
    // 构造：传入所有可调参数（也可由 node 读取后传入）
    // 构造：传入所有可调参数（也可由 node 读取后传入）
    KalmanFilter(double dt = 0.01,
             double P_init = 5.0,  // 改为 P_init
             double q_pos = 0.01,
             double q_vel = 0.1,
             double q_yaw = 0.001,
             double q_yawrate = 0.01,
             double r_x = 0.05,
             double r_y = 0.05,
             double r_z = 0.05,
             double r_yaw = 0.01);
    // 设噪声
    void setProcessNoise(double q_pos, double q_vel, double q_yaw, double q_yawrate);
    void setMeasNoise(double rx, double ry, double rz, double ryaw);

    // 核心接口
    std::array<double, 4> update(const std::array<double, 4>& z_in);
    std::array<double, 4> predictOnly();

    // 可选：更新 dt 并重构 F
    void setDt(double dt);

private:
    void buildF_();
    void buildH_();

private:
    double dt_;
    bool is_first_measurement_;

    Eigen::Matrix<double, 8, 1> x_;
    Eigen::Matrix<double, 8, 8> P_;
    Eigen::Matrix<double, 8, 8> F_;
    Eigen::Matrix<double, 8, 8> Q_;
    Eigen::Matrix<double, 4, 8> H_;
    Eigen::Matrix<double, 4, 4> R_;
    Eigen::Matrix<double, 4, 1> z_;
};
