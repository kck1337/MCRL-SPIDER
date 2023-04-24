# ROS2 Hexapod Supervisor
#
# Copyright (c) 2021 Pascal Voser
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

import evdev
import rclpy
import threading
import subprocess
import time
import RPi.GPIO as GPIO
from rclpy.node import Node
from sensor_msgs.msg import Joy
from sensor_msgs.msg import JointState

import supervisor.temperature_regulator as Temp_reg
import supervisor.Led_ring as Led_ring
import supervisor.Voltage_monitor as Volt_mon


class Supervisor(Node):
    temp_timer_period = 0.5  # seconds --> 25 Hz
    led_timer_period = 0.04  # seconds --> 25 Hz
    voltage_timer_period = 1  # seconds --> 1 Hz

    def __init__(self):
        super().__init__('supervisor_node')

        GPIO.setmode(GPIO.BCM)
        GPIO.setup(17, GPIO.OUT)
        GPIO.output(17, GPIO.LOW)

        # Init functions
        self.led = Led_ring.Led_ring()
        self.volt_mon = Volt_mon.Voltage_monitor()
        temp_reg = Temp_reg.Temperature_regulator()
        self.started = False

        # Subscriber to topics
        self.joy_subscription = self.create_subscription(
            Joy,
            '/joy',
            self.listener_callback,
            1)
        self.joy_subscription  # prevent unused variable warning

        self.jointstate_subscription = self.create_subscription(
            JointState,
            '/joint_states',
            self.nodecheck_callback,
            1)
        self.jointstate_subscription  # prevent unused variable warning

        # Temperature Montior setup
        try:
            self.temp_timer = self.create_timer(
                self.temp_timer_period,
                temp_reg.temperature_timer_callback)
        except Exception:
            print("Temperature Regulator problem!")

        # Led Ring setup
        try:
            self.led_timer = self.create_timer(self.led_timer_period, self.led.led_timer_callback)
        except Exception:
            print("LED problem! ")

        # setup hexa thread
        self.hexa_thread = threading.Thread(target=self.hexapod_thread)

        # Battery monitoring setup
        if self.volt_mon.init():
            self.voltage_timer = self.create_timer(
                self.voltage_timer_period,
                self.voltage_callback)
        else:
            print("INA260 not connected")

        self.check_timer = self.create_timer(1, self.check_callback)

    turnoff_timer = 0

    def listener_callback(self, msg):
        if msg.buttons[6] == 1:
            if self.turnoff_timer == 0:
                self.turnoff_timer = time.time()
            else:
                if time.time() - self.turnoff_timer > 3:
                    GPIO.output(17, GPIO.LOW)  # Turn off the servos
                    subprocess.run(["shutdown", "now", "-h"])
        elif self.turnoff_timer != 0:
            self.turnoff_timer = 0

    def nodecheck_callback(self, msg):
        self.node_alive = True

    node_alive = False

    def check_callback(self):
        # check for the Bluetooth controller
        devices = [evdev.InputDevice(path) for path in evdev.list_devices()]
        bt_connected = False
        for device in devices:
            if device.name.find("Xbox Wireless Controller") != -1:
                bt_connected = True
                if not self.started:
                    self.started = True
                    GPIO.output(17, GPIO.HIGH)  # Power the servos
                    self.hexa_thread.start()

        self.led.bt_connect(bt_connected)
        if self.node_alive:
            self.led.node_running(True)
        else:
            self.led.node_running(False)
        self.node_alive = False

        # check for the hexapod controller nodes

    def voltage_callback(self):
        self.volt_mon.print_voltage()
        self.led.set_charge(self.volt_mon.get_charge_state())

    def hexapod_thread(self):
        print("start hexapod")
        # Start the main ROS2 node
        subprocess.Popen(["ros2", "launch", "launch_files", "hexapod_launch.py"])


def main(args=None):
    rclpy.init(args=args)
    print('Hi from supervisor.')

    supervisor_node = Supervisor()

    rclpy.spin(supervisor_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    supervisor_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
