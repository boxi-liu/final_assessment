#include "rclcpp/rclcpp.hpp"
#include "camera_info_manager/camera_info_manager.hpp"
#include "sensor_msgs/msg/camera_info.hpp"
#include <string>

class CameraParametersPublisher : public rclcpp::Node
{
public:
    CameraParametersPublisher()
    : Node("camera_parameters_publisher"),
      camera_info_manager_(this, "mv_camera", "")
    {
        camera_parameters_path_ = this->declare_parameter<std::string>(
            "camera_parameters_path",
            ""
        );

        std::string file_url = "file://" + camera_parameters_path_;
        if (!camera_info_manager_.loadCameraInfo(file_url)) {
            RCLCPP_ERROR(this->get_logger(), "无法加载相机文件：%s", file_url.c_str());
        } else {
            RCLCPP_INFO(this->get_logger(), "相机参数加载成功：%s", file_url.c_str());
        }

        publisher_ = this->create_publisher<sensor_msgs::msg::CameraInfo>("camera_parameters", 10);

        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(1000),
            std::bind(&CameraParametersPublisher::publish_camera_parameters, this)
        );
    }

private:
    void publish_camera_parameters() {
        auto msg = camera_info_manager_.getCameraInfo(); // 拷贝一份
        msg.header.stamp = this->now();
        msg.header.frame_id = "camera_link";
        publisher_->publish(msg);
    }

private:
    std::string camera_parameters_path_;
    camera_info_manager::CameraInfoManager camera_info_manager_;
    rclcpp::Publisher<sensor_msgs::msg::CameraInfo>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CameraParametersPublisher>());
    rclcpp::shutdown();
    return 0;
}
