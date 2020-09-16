# Dactyl with Arduino Pro Micro

See https://github.com/adereth/dactyl-keyboard for the original Version.

This Dactyl uses the Arduino Pro Mirco (2x).
Wiring is a 6x6 Matrix like the [Dactyl Manuform](https://github.com/qmk/qmk_firmware/tree/master/keyboards/handwired/dactyl_manuform)


## Build the Firmware:

  - Build the firmware with `make handwired/qform:<keymapname>`, for example `make handwired/dactyl:default`
  - This will result in a hex file called `handwired_qform_<keymapname>.hex`, e.g.
    `handwired_qform_default.hex`

How to setup your build enviroment can be found here: [Installing Build Tools](https://docs.qmk.fm/#/getting_started_build_tools)

## Required Hardware

TODO

## Wiring

TODO

## Flashing

To flash your firmware take a look at: [Flashing Instructions and Bootloader Information](https://docs.qmk.fm/#/flashing).

Under Windows the most convenient way is installing the [QMK Drivers](https://github.com/qmk/qmk_driver_installer/releases) and use the [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases).

Notes on Using Pro Micro 3.3V
-----------------------------

Do update the `F_CPU` parameter in `rules.mk` to `8000000` which reflects
the frequency on the 3.3V board.

Also, if the slave board is producing weird characters in certain columns,
update the following line in `matrix.c` to the following:

```
// _delay_us(30);  // without this wait read unstable value.
_delay_us(300);  // without this wait read unstable value.
```
