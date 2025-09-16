// src/armor_parameters_publisher_streaming.cpp
#include "armor_interface/msg/armor_points.hpp"
#include "rclcpp/rclcpp.hpp"
#include <memory>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <optional>
#include <stdexcept>  // 用于捕获stoi异常
#include <filesystem> // 用于检查文件是否存在（C++17及以上）

class ArmorParametersPublisher : public rclcpp::Node
{
public:
    ArmorParametersPublisher()
    : Node("armor_parameters_publisher"), current_idx_(0), loop_count_(0)
    {
        // 1. 声明并获取CSV文件路径参数
        armor_parameters_path_ = this->declare_parameter<std::string>(
            "armor_parameters_path",
            ""
        );

        // 2. 检查文件是否存在（提前规避路径错误）
        if (!std::filesystem::exists(armor_parameters_path_)) {
            RCLCPP_FATAL(this->get_logger(), "CSV文件不存在！路径：%s", armor_parameters_path_.c_str());
            rclcpp::shutdown(); // 文件不存在，直接退出节点
            return;
        }

        // 3. 声明循环发布参数和发布间隔
        loop_ = this->declare_parameter<bool>("loop", true);
        publish_interval_ms_ = this->declare_parameter<int>("publish_interval_ms", 10);

        // 4. 创建发布者（QoS深度1000）
        armor_pub_ = this->create_publisher<armor_interface::msg::ArmorPoints>(
            "armor_parameters",
            rclcpp::QoS(1000)
        );

        // 5. 加载CSV文件（检查加载结果）
        bool load_success = load_file();
        if (!load_success) {
            RCLCPP_FATAL(this->get_logger(), "CSV数据加载失败，节点即将退出");
            rclcpp::shutdown();
            return;
        }

        // 6. 创建定时器（按间隔发布数据）
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(publish_interval_ms_),
            [this]() { this->onTimer(); }
        );

        // 7. 启动日志（buffer_已有效）
        RCLCPP_INFO(this->get_logger(), "节点启动成功！话题：armor_parameters，数据总量：%zu，循环：%s，发布间隔：%dms",
                    buffer_.size(), loop_ ? "开启" : "关闭", publish_interval_ms_);
    }

private:
    // 参数与成员变量
    std::string armor_parameters_path_;
    rclcpp::Publisher<armor_interface::msg::ArmorPoints>::SharedPtr armor_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::vector<armor_interface::msg::ArmorPoints> buffer_;
    size_t current_idx_;
    bool loop_;
    int publish_interval_ms_;
    size_t loop_count_;  // 控制循环日志频率

    // 读取并解析CSV文件到buffer_（返回是否加载成功）
    bool load_file()
    {
        RCLCPP_INFO(this->get_logger(), "开始读取CSV文件：%s", armor_parameters_path_.c_str());
        
        // 打开文件（检查是否成功）
        std::ifstream file(armor_parameters_path_);
        if (!file.is_open()) {
            RCLCPP_ERROR(this->get_logger(), "文件打开失败！可能原因：路径错误、权限不足");
            return false;
        }

        std::string line;
        // 跳过表头行（假设第一行为表头）
        if (!std::getline(file, line)) {
            RCLCPP_ERROR(this->get_logger(), "CSV文件为空，无任何数据");
            file.close();
            return false;
        }
        RCLCPP_INFO(this->get_logger(), "已跳过表头行：%s", line.c_str());

        size_t total_line = 0;    // 总行数（不含表头）- size_t类型
        size_t valid_line = 0;    // 有效行数 - size_t类型
        size_t invalid_line = 0;  // 无效行数 - size_t类型

        // 逐行解析数据
        while (std::getline(file, line)) {
            total_line++;
            auto maybe_msg = parse_line(line);

            if (maybe_msg.has_value()) {
                buffer_.push_back(std::move(maybe_msg.value()));
                valid_line++;
            } else {
                invalid_line++;
                // 修复：%d → %zu（匹配size_t类型）
                RCLCPP_WARN(this->get_logger(), "第%zu行解析失败，跳过（内容：%s）", total_line, line.c_str());
            }
        }

        file.close();

        // 检查有效数据是否为空
        if (buffer_.empty()) {
            RCLCPP_ERROR(this->get_logger(), "CSV文件解析完成，但无有效数据！总行数：%zu，无效行数：%zu",
                        total_line, invalid_line);
            return false;
        }

        // 加载成功日志
        RCLCPP_INFO(this->get_logger(), "CSV文件加载完成！总行数：%zu，有效行数：%zu，无效行数：%zu",
                    total_line, valid_line, invalid_line);
        return true;
    }

    // 定时器回调：发布数据（删除header相关代码）
    void onTimer()
    {
        if (buffer_.empty()) return;

        // 发布当前数据
        if (current_idx_ < buffer_.size()) {
            auto msg = buffer_[current_idx_++];
            // 【关键修复】删除header赋值（ArmorPoints.msg无header字段）
            armor_pub_->publish(msg);

            // 每100条打印一次进度（修复：%d → %zu）
            if (current_idx_ % 100 == 0) {
                RCLCPP_INFO(this->get_logger(), "已发布%zu条数据，当前索引：%zu", current_idx_, current_idx_);
            }
            return;
        }

        // 数据发布完毕，处理循环
        if (loop_) {
            loop_count_++;
            // 每5次循环打印一次日志（修复：%d → %zu）
            if (loop_count_ % 5 == 1) {
                RCLCPP_INFO(this->get_logger(), "已完成第%zu次循环，重新开始发布（共%zu条数据）",
                            loop_count_, buffer_.size());
            }
            current_idx_ = 0;
        } else {
            RCLCPP_INFO(this->get_logger(), "所有数据发布完毕（共%zu条），停止定时器", buffer_.size());
            timer_->cancel();
        }
    }

    // 解析单行CSV数据（返回optional）
    std::optional<armor_interface::msg::ArmorPoints> parse_line(const std::string& line)
    {
        std::stringstream ss(line);
        std::string value;
        std::vector<int> points;

        try {
            // 按逗号分割，转换为int（跳过空字段）
            while (std::getline(ss, value, ',')) {
                // 去除字段前后空格
                value.erase(0, value.find_first_not_of(" \t\n\r"));
                value.erase(value.find_last_not_of(" \t\n\r") + 1);
                
                if (value.empty()) {
                    RCLCPP_WARN(this->get_logger(), "解析到空字段，跳过");
                    continue;
                }

                points.push_back(std::stoi(value));
            }
        } catch (const std::invalid_argument& e) {
            RCLCPP_WARN(this->get_logger(), "字段转换失败（非整数）：%s，错误信息：%s", value.c_str(), e.what());
            return std::nullopt;
        } catch (const std::out_of_range& e) {
            RCLCPP_WARN(this->get_logger(), "字段数值超出范围：%s，错误信息：%s", value.c_str(), e.what());
            return std::nullopt;
        }

        // 检查字段数是否为8（装甲板8个坐标）
        if (points.size() != 8) {
            RCLCPP_WARN(this->get_logger(), "字段数异常：%zu个（预期8个）", points.size());
            return std::nullopt;
        }

        // 填充消息（与ArmorPoints.msg字段匹配）
        armor_interface::msg::ArmorPoints msg;
        msg.left_top_x     = points[0];
        msg.left_top_y     = points[1];
        msg.left_bottom_x  = points[2];
        msg.left_bottom_y  = points[3];
        msg.right_bottom_x = points[4];
        msg.right_bottom_y = points[5];
        msg.right_top_x    = points[6];
        msg.right_top_y    = points[7];

        return msg;
    }

}; // class

int main(int argc, char* argv[])
{
    // 检查C++版本是否支持filesystem（C++17及以上）
    #if __cplusplus < 201703L
        RCLCPP_FATAL(rclcpp::get_logger("armor_parameters_publisher"), 
                    "编译时C++版本过低（需C++17及以上），无法检查文件是否存在！");
        return 1;
    #endif

    rclcpp::init(argc, argv);
    auto node = std::make_shared<ArmorParametersPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}