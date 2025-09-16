#include "sensor_msgs/msg/camera_info.hpp"
#include "armor_interface/msg/armor_points.hpp"
#include "armor_interface/msg/armor_pose.hpp"

#include <rclcpp/rclcpp.hpp>

#include "pnp_solve/pnp_solve.hpp"
#include "kf_solve/kalman_filter.hpp"

#include <memory>
#include <array>

using namespace std::chrono_literals;

class ArmorPoseSolver : public rclcpp::Node
{
private:
    sensor_msgs::msg::CameraInfo::SharedPtr camera_parameters_;
    rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr camera_sub_;
    rclcpp::Subscription<armor_interface::msg::ArmorPoints>::SharedPtr armor_sub_;
    rclcpp::Publisher<armor_interface::msg::ArmorPose>::SharedPtr raw_pose_pub_;
    rclcpp::Publisher<armor_interface::msg::ArmorPose>::SharedPtr filtered_pose_pub_;
    std::shared_ptr<PnpSolver> pnp_solver_;
    std::shared_ptr<KalmanFilter> kf_;
    bool kf_initialized_;

public:
    ArmorPoseSolver() : Node("armor_pose_solver"), kf_initialized_(false)
    {
        RCLCPP_INFO(this->get_logger(), "ArmorPoseSolver 节点正在初始化...");

        // 1. 初始化订阅者
        camera_sub_ = this->create_subscription<sensor_msgs::msg::CameraInfo>(
            "camera_parameters", 10,
            std::bind(&ArmorPoseSolver::cameraCallback, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "已订阅 camera_parameters 话题");

        armor_sub_ = this->create_subscription<armor_interface::msg::ArmorPoints>(
            "armor_parameters", 10,
            std::bind(&ArmorPoseSolver::armorCallback, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "已订阅 armor_parameters 话题");

        // 2. 初始化发布者
        raw_pose_pub_ = this->create_publisher<armor_interface::msg::ArmorPose>("armor/raw_pose", 10);
        RCLCPP_INFO(this->get_logger(), "已创建 raw_pose 发布者");

        filtered_pose_pub_ = this->create_publisher<armor_interface::msg::ArmorPose>("armor/filtered_pose", 10);
        RCLCPP_INFO(this->get_logger(), "已创建 filtered_pose 发布者");

        // 3. 初始化 PnP 解算器
        pnp_solver_ = std::make_shared<PnpSolver>();
        RCLCPP_INFO(this->get_logger(), "PnP 解算器已初始化");

        // 4. 声明参数
        this->declare_parameter<double>("dt", 0.01);
        this->declare_parameter<double>("P_", 5.0);
        this->declare_parameter<double>("q_pos", 0.01);
        this->declare_parameter<double>("q_vel", 0.1);
        this->declare_parameter<double>("q_yaw", 0.001);
        this->declare_parameter<double>("q_yawrate", 0.01);
        this->declare_parameter<double>("r_x", 0.05);
        this->declare_parameter<double>("r_y", 0.05);
        this->declare_parameter<double>("r_z", 0.05);
        this->declare_parameter<double>("r_yaw", 0.01);

        // 5. 获取参数值
        double dt = this->get_parameter("dt").as_double();
        double P_ = this->get_parameter("P_").as_double();
        double q_pos = this->get_parameter("q_pos").as_double();
        double q_vel = this->get_parameter("q_vel").as_double();
        double q_yaw = this->get_parameter("q_yaw").as_double();
        double q_yawrate = this->get_parameter("q_yawrate").as_double();
        double r_x = this->get_parameter("r_x").as_double();
        double r_y = this->get_parameter("r_y").as_double();
        double r_z = this->get_parameter("r_z").as_double();
        double r_yaw = this->get_parameter("r_yaw").as_double();

        // 6. 初始化 Kalman 滤波器
        kf_ = std::make_shared<KalmanFilter>(
            dt, P_, q_pos, q_vel, q_yaw, q_yawrate,
            r_x, r_y, r_z, r_yaw
        );
        kf_initialized_ = true;

        RCLCPP_INFO(this->get_logger(), "KalmanFilter 初始化完成");
        RCLCPP_INFO(this->get_logger(), "参数: dt=%.3f, P_=%.3f, q_pos=%.3f, q_vel=%.3f, q_yaw=%.3f, q_yawrate=%.3f, r_x=%.3f, r_y=%.3f, r_z=%.3f, r_yaw=%.3f", 
                   dt, P_, q_pos, q_vel, q_yaw, q_yawrate, r_x, r_y, r_z, r_yaw);
    }

private:
    void cameraCallback(const sensor_msgs::msg::CameraInfo::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "收到相机参数");
        camera_parameters_ = msg;
    }

    void armorCallback(const armor_interface::msg::ArmorPoints::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "收到装甲板数据");
        
        if (!camera_parameters_) {
            RCLCPP_WARN(this->get_logger(), "尚未收到相机参数，跳过处理");
            return;
        }
        
        if (!kf_initialized_) {
            RCLCPP_WARN(this->get_logger(), "Kalman滤波器未初始化，跳过处理");
            return;
        }

        try {
            // PnP 解算
            auto raw_pose_data = pnp_solver_->solve(*msg, *camera_parameters_);
            RCLCPP_INFO(this->get_logger(), "PnP解算结果: x=%.2f, y=%.2f, z=%.2f, yaw=%.2f", 
                       raw_pose_data[0], raw_pose_data[1], raw_pose_data[2], raw_pose_data[4]);

            // 发布原始位姿
            armor_interface::msg::ArmorPose raw_pose_msg;
            raw_pose_msg.x = raw_pose_data[0];
            raw_pose_msg.y = raw_pose_data[1];
            raw_pose_msg.z = raw_pose_data[2];
            raw_pose_msg.pitch = raw_pose_data[3];
            raw_pose_msg.yaw = raw_pose_data[4];
            raw_pose_msg.roll = raw_pose_data[5];
            raw_pose_pub_->publish(raw_pose_msg);
            RCLCPP_INFO(this->get_logger(), "已发布原始位姿");

            // KF 滤波
            auto filtered_data = kf_->update({raw_pose_data[0], raw_pose_data[1], raw_pose_data[2], raw_pose_data[4]});
            RCLCPP_INFO(this->get_logger(), "KF滤波结果: x=%.2f, y=%.2f, z=%.2f, yaw=%.2f", 
                       filtered_data[0], filtered_data[1], filtered_data[2], filtered_data[3]);

            // 发布滤波后位姿
            armor_interface::msg::ArmorPose filtered_pose_msg;
            filtered_pose_msg.x = filtered_data[0];
            filtered_pose_msg.y = filtered_data[1];
            filtered_pose_msg.z = filtered_data[2];
            filtered_pose_msg.pitch = raw_pose_data[3];
            filtered_pose_msg.yaw = filtered_data[3];
            filtered_pose_msg.roll = raw_pose_data[5];
            filtered_pose_pub_->publish(filtered_pose_msg);
            RCLCPP_INFO(this->get_logger(), "已发布滤波后位姿");
        } catch (const std::exception& e) {
            RCLCPP_ERROR(this->get_logger(), "处理装甲板数据时出错: %s", e.what());
        }
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    RCLCPP_INFO(rclcpp::get_logger("main"), "启动 ArmorPoseSolver 节点");
    auto node = std::make_shared<ArmorPoseSolver>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}