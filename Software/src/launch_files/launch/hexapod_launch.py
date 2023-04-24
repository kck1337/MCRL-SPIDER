# Copyright (c) 2020 Pascal Voser
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Author: Pascal Voser

import os

from ament_index_python.packages import get_package_share_directory
from launch.substitutions import Command, LaunchConfiguration

import launch
import launch_ros.actions


def generate_launch_description():
    # Check if device is a Raspberry pi
    try:
        f = open("/proc/device-tree/model", "r")   # File does not exist on "regular" Ubuntu PCs
        line = f.readline()
        if line.find("Raspberry") != -1:
            print("This is a Raspberry Pi")
            is_raspberry = True
        f.close()
    except IOError:
        print("This is not a Raspberry Pi")
        is_raspberry = False

    if is_raspberry:
        input_device = '/dev/input/event0'
        arguments1 = ['-RPi']
    else:
        input_device = '/dev/input/js1'
        arguments1 = ['']

    joy_dev = launch.substitutions.LaunchConfiguration('joy_dev')
    pkg_share = launch_ros.substitutions.FindPackageShare(
        package='hexapod_description_mk2').find('hexapod_description_mk2')
    default_model_path = os.path.join(pkg_share, 'urdf/hexapod.urdf.xacro')
    default_rviz_config_path = os.path.join(pkg_share, 'rviz/urdf.rviz')

    config = os.path.join(
        get_package_share_directory('hexapod_control'),
        'params',
        'hexapod.yaml'
    )

    robot_state_publisher_node = launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[
            LaunchConfiguration('use_sim_time'),
            {'robot_description': Command(['xacro ', LaunchConfiguration('model')])}]
    )

    rviz_node = launch_ros.actions.Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', LaunchConfiguration('rvizconfig')],
    )

    joy_node = launch_ros.actions.Node(
        package='joy',
        executable='joy_node',
        name='joy_node',
        parameters=[{
          'dev': joy_dev,
          'deadzone': 0.3,
          'autorepeat_rate': 20.0,
          }]
    )

    hexa_node = launch_ros.actions.Node(
        package='hexapod_control',
        executable='hexapod_control_exe',
        name='hexapod_controller',
        arguments=arguments1,
        parameters=[config]
    )

    # print("ran hexa_node", config)

    return_list = [
        launch.actions.DeclareLaunchArgument('joy_dev', default_value=input_device),

        launch.actions.DeclareLaunchArgument(
          'use_sim_time',
          default_value='false',
          description='Use simulation (Gazebo) clock if true'),

        launch.actions.DeclareLaunchArgument(
            name='model',
            default_value=default_model_path,
            description='Absolute path to robot urdf file'),

        launch.actions.DeclareLaunchArgument(
            name='rvizconfig',
            default_value=default_rviz_config_path,
            description='Absolute path to rviz config file'),

        # nodes
        joy_node,
        hexa_node]

    # RVIZ visualization nodes
    if not is_raspberry:
        return_list.append(robot_state_publisher_node)
        return_list.append(rviz_node)

    return launch.LaunchDescription(return_list)
