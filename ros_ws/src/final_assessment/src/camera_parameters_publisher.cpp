#include "rclcpp/rclcpp.hpp"
#include <rclcpp/node.hpp>

class CameraParametersPublisher : public rclcpp::Node
{
public:
    CameraParametersPublisher() : Node("camera_paramaters_publisher")
    {
        std::string camera_parameters_path = this -> declare_parameter<std::string>(
            "camera_parameters_path",
            ""
        );
    }
}