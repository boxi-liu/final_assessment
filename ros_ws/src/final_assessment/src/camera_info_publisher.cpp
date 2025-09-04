#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/camera_info.hpp"
#include "yaml-cpp/yaml.h"
#include <fstream>
#include <vector>

class CameraInfoPublisher : public rclcpp::Node
{
public:
    CameraInfoPublisher() : Node("camera_info_publisher")
    {
        
        std::string yaml_path = this->declare_parameter<std::string>(
            "camera_info_path",  
            "~/final_assessment/算法组——最终考核/correct_camera_info.yaml"  // 默认路径，建议使用绝对路径或相对工作空间的路径
        );

        // 解析YAML文件
        if (!parse_camera_info(yaml_path)) {
            RCLCPP_ERROR(this->get_logger(), "解析相机参数失败，节点退出");
            rclcpp::shutdown();
            return;
        }

        // 创建CameraInfo发布者
        publisher_ = this->create_publisher<sensor_msgs::msg::CameraInfo>(
            "camera_info", 10
        );

        // 设置发布频率（10Hz）
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&CameraInfoPublisher::publish_camera_info, this)
        );

        RCLCPP_INFO(this->get_logger(), "相机参数发布节点已启动: %s", camera_name_.c_str());
    }

private:
    bool parse_camera_info(const std::string& yaml_path)
    {
        // 打开YAML文件
        std::ifstream file(yaml_path);
        if (!file.is_open()) {
            RCLCPP_ERROR(this->get_logger(), "无法打开文件: %s", yaml_path.c_str());
            return false;
        }

        // 解析YAML内容
        YAML::Node root = YAML::Load(file);
        
        // 读取基本信息
        image_width_ = root["image_width"].as<int>();
        image_height_ = root["image_height"].as<int>();
        camera_name_ = root["camera_name"].as<std::string>();
        distortion_model_ = root["distortion_model"].as<std::string>();

        // 读取相机矩阵 (3x3) - 检查大小是否正确
        camera_matrix_ = root["camera_matrix"]["data"].as<std::vector<double>>();
        if (camera_matrix_.size() != 9) {
            RCLCPP_ERROR(this->get_logger(), "相机矩阵大小错误，应为9个元素");
            return false;
        }
        
        // 读取畸变系数 (1x5)
        distortion_coefficients_ = root["distortion_coefficients"]["data"].as<std::vector<double>>();
        if (distortion_coefficients_.size() != 5) {
            RCLCPP_ERROR(this->get_logger(), "畸变系数大小错误，应为5个元素");
            return false;
        }
        
        // 读取校正矩阵 (3x3)
        rectification_matrix_ = root["rectification_matrix"]["data"].as<std::vector<double>>();
        if (rectification_matrix_.size() != 9) {
            RCLCPP_ERROR(this->get_logger(), "校正矩阵大小错误，应为9个元素");
            return false;
        }
        
        // 读取投影矩阵 (3x4)
        projection_matrix_ = root["projection_matrix"]["data"].as<std::vector<double>>();
        if (projection_matrix_.size() != 12) {
            RCLCPP_ERROR(this->get_logger(), "投影矩阵大小错误，应为12个元素");
            return false;
        }

        return true;
    }

    void publish_camera_info()
    {
        auto msg = sensor_msgs::msg::CameraInfo();
        
        // 填充消息头
        msg.header.stamp = this->get_clock()->now();
        msg.header.frame_id = "camera_link";  // 相机坐标系，需与URDF匹配
        
        // 图像尺寸
        msg.width = image_width_;
        msg.height = image_height_;
        
        // 相机名称和畸变模型
        msg.distortion_model = distortion_model_;
        
        // 畸变系数（vector可以直接赋值，因为msg.d也是vector）
        msg.d = distortion_coefficients_;
        
        // 相机矩阵 (3x3) - 将vector复制到array
        for (size_t i = 0; i < 9; ++i) {
            msg.k[i] = camera_matrix_[i];
        }
        
        // 校正矩阵 (3x3) - 将vector复制到array
        for (size_t i = 0; i < 9; ++i) {
            msg.r[i] = rectification_matrix_[i];
        }
        
        // 投影矩阵 (3x4) - 将vector复制到array
        for (size_t i = 0; i < 12; ++i) {
            msg.p[i] = projection_matrix_[i];
        }

        // 发布消息
        publisher_->publish(msg);
        // RCLCPP_INFO(this->get_logger(), "发布相机内参信息");
    }

    // 成员变量
    rclcpp::Publisher<sensor_msgs::msg::CameraInfo>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int image_width_, image_height_;
    std::string camera_name_, distortion_model_;
    std::vector<double> camera_matrix_;         // 存储从YAML读取的9元素矩阵
    std::vector<double> distortion_coefficients_; // 存储5元素畸变系数
    std::vector<double> rectification_matrix_;  // 存储9元素校正矩阵
    std::vector<double> projection_matrix_;     // 存储12元素投影矩阵
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CameraInfoPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
    