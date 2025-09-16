from setuptools import setup
import os
from glob import glob

package_name = 'bringup'

data_files = [
    # 原有必要项：resource 和 package.xml
    ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
    ('share/' + package_name, ['package.xml']),

    # 安装 launch 文件到 share/<pkg>/launch
    (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),

    # 关键：安装 config 目录下的所有文件到 share/<pkg>/config
    (os.path.join('share', package_name, 'config'), glob('config/*')),
]

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=data_files,
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='liu',
    maintainer_email='xxx@xxx.com',
    description='bringup package',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [],
    },
)
