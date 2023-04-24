# ROS2 Hexapod Temperature Regulator
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

import RPi.GPIO as GPIO


class Temperature_regulator():

    # Fan Configuration
    FAN_PIN = 18  # BCM pin
    PWM_FREQ = 100  # [Hz] Change this value if fan has strange behavior

    LOWER_LIMIT = 30
    UPPER_LIMIT = 70

    MIN_SPEED = 20

    def __init__(self):

        # Fan control
        # Setup GPIO pin
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(self.FAN_PIN, GPIO.OUT, initial=GPIO.LOW)
        self.fan = GPIO.PWM(self.FAN_PIN, self.PWM_FREQ)
        self.fan.start(0)

        self.status = False
        self.history = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    def temperature_timer_callback(self):
        # Get CPU Temp
        with open("/sys/class/thermal/thermal_zone0/temp", "r") as sensor:
            temp = int(float(sensor.read()) / 1000)

        # Reset the fan speed
        speed = 0

        # Should the fan be turned off?
        if temp <= self.LOWER_LIMIT:
            # Turn off the fan
            self.status = False

        # Is the fan on or should it be?
        elif self.status or temp >= self.LOWER_LIMIT:
            # Clamp the temperature to the fan curve
            if temp <= self.LOWER_LIMIT:
                index = 0
            elif temp > self.UPPER_LIMIT:
                index = self.UPPER_LIMIT - self.LOWER_LIMIT
            else:
                index = temp - self.LOWER_LIMIT

            # Check if it's an upward trend
            if ((sum(self.history) / 10) < temp) or temp < self.LOWER_LIMIT:
                # Try to stabilize the temperature
                # TODO: Need to test this further
                if index < 100:
                    index += 1

            # Remove the first entry
            self.history.pop(0)

            # Add temperature to the list
            self.history.append(temp)

            # Load fan speed from curve
            speed = self.MIN_SPEED + \
                (100 - self.MIN_SPEED) * index / (self.UPPER_LIMIT - self.LOWER_LIMIT)

            # Keep the fan on
            self.status = True

        # Update fan speed
        self.fan.ChangeDutyCycle(speed)
