#include "kf_solve/kalman_filter.hpp"
#include <iostream>

KalmanFilter::KalmanFilter(double dt,
                           double P_init,  // 改为 P_init 避免命名冲突
                           double q_pos,
                           double q_vel,
                           double q_yaw,
                           double q_yawrate,
                           double r_x,
                           double r_y,
                           double r_z,
                           double r_yaw)
    : dt_(dt), is_first_measurement_(true)
{
    x_.setZero();
    
    // 初始化协方差矩阵
    P_.setIdentity();
    P_ = P_ * P_init;  // 使用传入的初始值

    Q_.setZero();
    R_.setZero();

    buildF_();
    buildH_();

    setProcessNoise(q_pos, q_vel, q_yaw, q_yawrate);
    setMeasNoise(r_x, r_y, r_z, r_yaw);
}

void KalmanFilter::setDt(double dt) {
    dt_ = dt;
    buildF_(); // 立刻更新F
}

void KalmanFilter::buildF_() {
    F_.setIdentity();
    // 状态向量: [x y z yaw vx vy vz yaw_rate]^T
    F_(0, 4) = dt_; // x += vx*dt
    F_(1, 5) = dt_; // y += vy*dt
    F_(2, 6) = dt_; // z += vz*dt
    F_(3, 7) = dt_; // yaw += yaw_rate*dt
}

void KalmanFilter::buildH_() {
    H_.setZero();
    // 量测为 [x y z yaw]，对应状态的前 4 项
    H_(0,0) = 1.0;
    H_(1,1) = 1.0;
    H_(2,2) = 1.0;
    H_(3,3) = 1.0;
}

void KalmanFilter::setProcessNoise(double q_pos, double q_vel, double q_yaw, double q_yawrate) {
    Q_.setZero();
    Q_(0,0) = q_pos;
    Q_(1,1) = q_pos;
    Q_(2,2) = q_pos;
    Q_(3,3) = q_yaw;
    Q_(4,4) = q_vel;
    Q_(5,5) = q_vel;
    Q_(6,6) = q_vel;
    Q_(7,7) = q_yawrate;
}

void KalmanFilter::setMeasNoise(double rx, double ry, double rz, double ryaw) {
    R_.setZero();
    R_(0,0) = rx;
    R_(1,1) = ry;
    R_(2,2) = rz;
    R_(3,3) = ryaw;
}

std::array<double,4> KalmanFilter::update(const std::array<double,4>& z_in) {
    if (is_first_measurement_) {
        x_(0) = z_in[0];
        x_(1) = z_in[1];
        x_(2) = z_in[2];
        x_(3) = z_in[3];
        x_(4) = 0.0;
        x_(5) = 0.0;
        x_(6) = 0.0;
        x_(7) = 0.0;

        is_first_measurement_ = false;
        return {x_(0), x_(1), x_(2), x_(3)};
    }

    // Predict
    buildF_();
    x_ = F_ * x_;
    P_ = F_ * P_ * F_.transpose() + Q_;

    // Update
    z_ << z_in[0], z_in[1], z_in[2], z_in[3];
    Eigen::Matrix<double,4,1> y = z_ - H_ * x_;
    Eigen::Matrix<double,4,4> S = H_ * P_ * H_.transpose() + R_;
    Eigen::Matrix<double,8,4> K = P_ * H_.transpose() * S.inverse();

    x_ = x_ + K * y;

    // 更稳定的 P 更新（Joseph 形式）
    Eigen::Matrix<double,8,8> I = Eigen::Matrix<double,8,8>::Identity();
    Eigen::Matrix<double,8,8> KH = K * H_;
    P_ = (I - KH) * P_ * (I - KH).transpose() + K * R_ * K.transpose();

    return {x_(0), x_(1), x_(2), x_(3)};
}

std::array<double,4> KalmanFilter::predictOnly() {
    buildF_();
    Eigen::Matrix<double,8,1> x_pred = F_ * x_;
    return { x_pred(0), x_pred(1), x_pred(2), x_pred(3) };
}
