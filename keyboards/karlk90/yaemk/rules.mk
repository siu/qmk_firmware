# Choose to use RISC-V or ARM MCU
RISC-V = yes

ifeq ($(strip $(RISC-V)), yes)
    MCU                =   GD32VF103
    BOARD              =   SIPEED_LONGAN_NANO
    LTO_ENABLE         =   yes
    EXTRAFLAGS         += -Ofast
    USE_PROCESS_STACKSIZE = 2048
    # Default clock is 96MHz, 120MHz is out of spec but possible.
    OPT_DEFS           += -DOVERCLOCK_120MHZ
else
    MCU        =   STM32F303
    BOARD      =   GENERIC_STM32_F303XC
    LTO_ENABLE =   yes
    EXTRAFLAGS += -Ofast
endif

# YAEMK source files
SRC     = led_config.c custom_color.c

# Debugging
#EXTRAFLAGS     += -gdwarf-4 -Wextra -Wconversion
ALLOW_WARNINGS =   yes

# QMK features
CONSOLE_ENABLE                     = no
DEBOUNCE_TYPE                      = asym_eager_defer_pk
EEPROM_DRIVER                      = i2c
ENCODER_ENABLE                     = yes
EXTRAKEY_ENABLE                    = yes
# Set KEYBOARD_SHARED_EP = yes if you run out of usb endpoints.
# This setting is mandatory with VIA on GD32VF103/RISC-V,
# because the MCU has a limited amount of USB endpoints.
KEYBOARD_SHARED_EP                 = no
MOUSEKEY_ENABLE                    = yes
NKRO_ENABLE                        = yes
OLED_ENABLE                        = yes
OLED_DRIVER                        = SSD1306
REGISTER_MULTIPLE_KEYEVENTS_ENABLE = yes
RGB_MATRIX_ENABLE                  = yes
RGB_MATRIX_DRIVER                  = WS2812
SERIAL_DRIVER                      = usart
SPLIT_KEYBOARD                     = yes
VIA_ENABLE                         = no
WPM_ENABLE                         = no
WS2812_DRIVER                      = pwm