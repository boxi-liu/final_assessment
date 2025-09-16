from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import TimerAction
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    # 假定把 config 放在 bringup 包下
    bringup_share = get_package_share_directory("bringup")
    camera_info = os.path.join(bringup_share, "config", "correct_camera_info.yaml")
    kalman_params = os.path.join(bringup_share, "config", "kalman.yaml")
    armor_csv = os.path.join(bringup_share, "config", "data.csv")

    # 相机发布节点
    camera_publisher = Node(
        package="publisher_camera",
        executable="publisher_camera",
        name="camera_publisher",
        output="screen",
        parameters=[{
            "camera_parameters_path": camera_info
        }]
    )

    # 装甲板发布节点（延迟启动），并把 csv 路径传给它
    armor_publisher = Node(
        package="publisher_armor",
        executable="publisher_armor",
        name="armor_publisher",
        output="screen",
        parameters=[{
            "armor_parameters_path": armor_csv
        }]
    )

    delayed_armor_publisher = TimerAction(
        period=1.0,   # 延迟 1s 启动
        actions=[armor_publisher],
    )

    # 姿态解算节点，加载 kalman 参数
    armor_pose_solver = Node(
        package="subscriber",
        executable="armor_pose_solver",
        name="armor_pose_solver",
        output="screen",
        parameters=[kalman_params]  # 加载 kalman 参数文件
    )

    return LaunchDescription([
        camera_publisher,
        armor_pose_solver,
        delayed_armor_publisher
    ])