# Requirements:

## WS2812 LEDs
`sudo pip3 install adafruit-circuitpython-neopixel-spi`
Pin GPIO 10 which is SPI 0 MOSI

### SPI
[Source SPI](https://forum.up-community.org/discussion/2141/solved-tutorial-gpio-i2c-spi-access-without-root-permissions)
[Source Neopoixel](https://learn.adafruit.com/circuitpython-neopixels-using-spi)
For SPI-bus access create the file /etc/udev/rules.d/50-spi.rules with the following contents:

`SUBSYSTEM=="spidev", GROUP="spiuser", MODE="0660"`

Next, copy and paste or type these lines into the terminal as the user you want to give access to the bus:

`sudo groupadd spiuser`
`sudo adduser "$USER" spiuser`

## ADS1115

`pip3 install ads1115`
`sudo adduser "$USER" i2c` as the I2C is in the I2C group by default

## INA260

`pip3 install adafruit-circuitpython-ina260`
`sudo adduser "$USER" i2c` as the I2C is in the I2C group by default

## Temperature

`pip3 install gpiozero`

## Enable shutdown
`sudo chmod u+s /sbin/shutdown`
