# ROS2 Hexapod Voltage Monitor
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

from ina260.controller import Controller


class Voltage_monitor():
    # Charge table for a 3S LiPo
    # sourece: https://blog.ampow.com/lipo-voltage-chart/
    charge_voltage = [
        12.6,   # 100% Charge
        12.45,
        12.33,
        12.25,
        12.07,
        11.95,
        11.86,
        11.74,
        11.62,
        11.56,
        11.51,
        11.45,
        11.39,
        11.36,
        11.3,
        11.24,
        11.18,
        11.12,
        11.06,
        10.83,
        9.82]   # 0% Charge

    def init(self):
        # Battery monitoring setup
        try:
            # I2C on channel 4, beacuse channel 1 is used for the localization
            self.ina260 = Controller(address=0x40, channel=4)
            return True
        except Exception:
            try:
                # check channel 1 as well
                self.ina260 = Controller(address=0x40, channel=1)
                return True
            except Exception:
                return False

    def print_voltage(self):
        print("Current: %.2fA Voltage: %.2fV Power:%.2fW"
              % (self.ina260.current(), self.ina260.voltage(), self.ina260.power()))

    def get_charge_state(self):
        for i in self.charge_voltage:
            if i < self.ina260.voltage():
                return (len(self.charge_voltage) - self.charge_voltage.index(i) - 1) * 100 /\
                            (len(self.charge_voltage) - 1)
