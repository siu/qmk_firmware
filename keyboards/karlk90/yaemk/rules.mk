# Shared configs
OPT = 2

# YAEMK source files
SRC = led_config.c custom_color.c

# QMK features
EEPROM_DRIVER                      = i2c
EXTRAKEY_ENABLE                    = yes
OLED_ENABLE                        = yes
OLED_DRIVER                        = SSD1306
WS2812_DRIVER                      = pwm
SERIAL_DRIVER                      = usart
