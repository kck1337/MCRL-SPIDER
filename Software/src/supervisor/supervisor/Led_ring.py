# ROS2 Hexapod Led Ring
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
import neopixel_spi as neopixel
import board


class Led_ring():

    # Configuration
    # LED Ring
    PIXEL_ORDER = neopixel.GRB
    NUM_PIXELS = 24

    bt_connected = False
    charge = 0
    green = (0, 50, 0)
    orange = (50, 30, 0)
    red = (50, 0, 0)
    blue = (0, 0, 50)
    front_r = 50
    front_g = 0
    front_b = 0

    offset = 7
    time_const = 0.4
    charge_leds = [
        11,
        0,
        10,
        1,
        9,
        2,
        8,
        3,
        7,
        4,
        5,
        6]

    def __init__(self):
        spi = board.SPI()

        self.pixels = neopixel.NeoPixel_SPI(spi,
                                            self.NUM_PIXELS,
                                            pixel_order=self.PIXEL_ORDER,
                                            auto_write=False)
        # Variables
        self.pulse_count = 0
        self.pulse_color = self.red
        self.up = True
        self.blink = False

    def bt_connect(self, enable):
        if enable:
            self.front_r = 0
            self.front_b = 50
        else:
            self.front_r = 50
            self.front_b = 0
        self.bt_connected = enable

    def node_running(self, enable):
        if enable:
            self.front_g = 50
        else:
            self.front_g = 0

    def set_charge(self, charge):
        self.charge = charge

    def led_timer_callback(self):
        self.pixels.fill((0, 0, 0))

        if self.up:
            self.pulse_count = self.pulse_count + self.time_const % 6
        else:
            self.pulse_count = self.pulse_count - self.time_const

        if self.pulse_count >= 6:
            self.up = False
        if self.pulse_count <= 1:
            self.up = True

        self.pixels[self.offset % self.NUM_PIXELS] = (self.front_r, self.front_g, self.front_b)
        self.pixels[(self.offset - 1) % self.NUM_PIXELS] = \
            (self.front_r, self.front_g, self.front_b)

        for index in range(1, 6):
            if index < self.pulse_count:
                self.pixels[index + self.offset % self.NUM_PIXELS] = self.pulse_color
                self.pixels[-index - 1 + self.offset % self.NUM_PIXELS] = self.pulse_color
            elif index == self.pulse_count:
                self.pixels[index + self.offset % self.NUM_PIXELS] = \
                    tuple(ti/4 for ti in self.pulse_color)
                self.pixels[-index - 1 + self.offset % self.NUM_PIXELS] = \
                    tuple(ti/4 for ti in self.pulse_color)

        if self.charge > 95:
            for led_nr in self.charge_leds:
                self.pixels[int((led_nr + 1 + self.NUM_PIXELS / 2) % self.NUM_PIXELS)] = self.green
        elif self.charge > 90:
            for led_nr in self.charge_leds[1:]:
                self.pixels[int((led_nr + 1 + self.NUM_PIXELS / 2) % self.NUM_PIXELS)] = self.green
        elif self.charge > 80:
            for led_nr in self.charge_leds[2:]:
                self.pixels[int((led_nr + 1 + self.NUM_PIXELS / 2) % self.NUM_PIXELS)] = self.green
        elif self.charge > 70:
            for led_nr in self.charge_leds[3:]:
                self.pixels[int((led_nr + 1 + self.NUM_PIXELS / 2) % self.NUM_PIXELS)] = self.green
        elif self.charge > 60:
            for led_nr in self.charge_leds[4:]:
                self.pixels[int((led_nr + 1 + self.NUM_PIXELS / 2) % self.NUM_PIXELS)] = self.green
        elif self.charge > 50:
            for led_nr in self.charge_leds[5:]:
                self.pixels[int((led_nr + 1 + self.NUM_PIXELS / 2) % self.NUM_PIXELS)] = self.green
        elif self.charge > 40:
            for led_nr in self.charge_leds[6:]:
                self.pixels[int((led_nr + 1 + self.NUM_PIXELS / 2) % self.NUM_PIXELS)] = self.green
        elif self.charge > 30:
            for led_nr in self.charge_leds[7:]:
                self.pixels[int((led_nr + 1 + self.NUM_PIXELS / 2) % self.NUM_PIXELS)] = \
                    self.orange
        elif self.charge > 20:
            for led_nr in self.charge_leds[8:]:
                self.pixels[int((led_nr + 1 + self.NUM_PIXELS / 2) % self.NUM_PIXELS)] = \
                    self.orange
        elif self.charge > 10:
            for led_nr in self.charge_leds[9:]:
                if self.blink:
                    self.pixels[int((led_nr + 1 + self.NUM_PIXELS / 2) % self.NUM_PIXELS)] = \
                        self.red
        else:
            for led_nr in self.charge_leds[10:]:
                if self.blink:
                    self.pixels[int((led_nr + 1 + self.NUM_PIXELS / 2) % self.NUM_PIXELS)] = \
                        self.red
        self.blink = not(self.blink)

        self.pixels.show()
