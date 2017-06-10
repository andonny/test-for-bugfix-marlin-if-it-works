/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2017 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * ANET 10 board pin assignments
 */

/**
 * Rev B    16 JUN 2017
 *
 * 1) no longer uses Sanguino files to define some of the pins
 * 2) added pointers to useable Arduino IDE extensions
 *
 */

/**
 * The standard Arduino IDE extension (board manager) for this board
 * is located at https://github.com/SkyNet3D/anet-board.
 *
 * Installation instructions are on that page.
 *
 * After copying the files to the appropriate location, restart Arduino and
 * you'll see "Anet V1.0" and "Anet V1.0 (Optiboot)" in the boards list.
 *
 * "Anet V1.0" uses the bootloader that was installed on the board when
 * it shipped from the factory.
 *
 * "Anet V1.0 (Optiboot)" frees up another 3K of FLASH.  You'll need to burn
 * a new bootloader to the board to be able to automatically download a
 * compiled image.
 *
 */

/**
 * Another useable Arduino IDE extension (board manager) can be found at
 * https://github.com/Lauszus/Sanguino
 *
 * This extension has been tested on Arduino 1.6.12 & 1.8.0
 *
 * Here's the JSON path:
 * https://raw.githubusercontent.com/Lauszus/Sanguino/master/package_lauszus_sanguino_index.json
 *
 * When installing select 1.0.2
 *
 * Installation instructions can be found at https://learn.sparkfun.com/pages/CustomBoardsArduino
 * Just use the above JSON URL instead of Sparkfun's JSON.
 *
 * Once installed select the Sanguino board and then select the CPU.
 *
 */

 /**
 *  To burn a new bootloader:
 *
 *   1. Connect your programmer to the board.
 *   2. In the Arduino IDE select the board and then select the programmer.
 *   3. In the Arduino IDE click on "burn bootloader". Don't worry about the "verify failed at 1F000" error message.
 *   4. The programmer is no longer needed. Remove it.
 */

#if !defined(__AVR_ATmega1284P__)
  #error "Oops!  Make sure you have 'Anet V1.0', 'Anet V1.0 (Optiboot)' or 'Sanguino' selected from the 'Tools -> Boards' menu."
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME "Anet"
#endif

#define LARGE_FLASH true

//
// Limit Switches
//
#define X_STOP_PIN         18
#define Y_STOP_PIN         19
#define Z_STOP_PIN         20

//
// Steppers
//
#define X_STEP_PIN         15
#define X_DIR_PIN          21
#define X_ENABLE_PIN       14

#define Y_STEP_PIN         22
#define Y_DIR_PIN          23
#define Y_ENABLE_PIN       14

#define Z_STEP_PIN          3
#define Z_DIR_PIN           2
#define Z_ENABLE_PIN       26

#define E0_STEP_PIN         1
#define E0_DIR_PIN          0
#define E0_ENABLE_PIN      14

//
// Temperature Sensors
//
#define TEMP_0_PIN          7  // Analog Input (pin 33 extruder)
#define TEMP_BED_PIN        6  // Analog Input (pin 34 bed)

//
// Heaters / Fans
//
#define HEATER_0_PIN       13  // (extruder)
#define HEATER_BED_PIN     12  // (bed)
#define FAN_PIN             4

//
// Misc. Functions
//
#define SDSS               31
#define LED_PIN            -1

/*
 * LCD / Controller
 *
 * Only the following displays are supported:
 *  ANET_KEYPAD_LCD
 *  ANET_FULL_GRAPHICS_LCD
 *  REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
 *    requires Anet Adapter http://www.thingiverse.com/thing:2103748)
 */

#if ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL)
  #define LCD_SDSS           28
  #if ENABLED(ADC_KEYPAD)
    #define SERVO0_PIN         27 // free for BLTouch/3D-Touch
    #define LCD_PINS_RS        28
    #define LCD_PINS_ENABLE    29
    #define LCD_PINS_D4        10
    #define LCD_PINS_D5        11
    #define LCD_PINS_D6        16
    #define LCD_PINS_D7        17
    #define BTN_EN1            -1
    #define BTN_EN2            -1
    #define BTN_ENC            -1
    #define ADC_KEYPAD_PIN      1
    #define ENCODER_FEEDRATE_DEADZONE 2
  #elif ENABLED(U8GLIB_ST7920)
    #if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
      // For RepRap Discount (with Anet Adapter wiring)
      #define SERVO0_PIN         27 // free for BLTouch/3D-Touch
      #define BEEPER_PIN         28
      #define LCD_PINS_RS        30
      #define LCD_PINS_ENABLE    29
      #define LCD_PINS_D4        17
      #define BTN_EN1            11
      #define BTN_EN2            10
      #define BTN_ENC            16
    #elif ENABLED(ANET_FULL_GRAPHICS_LCD)
      #define SERVO0_PIN         29 // free for BLTouch/3D-Touch
      #define BEEPER_PIN 17
      #define LCD_PINS_RS        27
      #define LCD_PINS_ENABLE    28
      #define LCD_PINS_D4        30
      #define BTN_EN1            11
      #define BTN_EN2            10
      #define BTN_ENC            16
    #else
      #error "You need to select ANET or RepRap Version"
    #endif
    #define ST7920_DELAY_1 DELAY_0_NOP
    #define ST7920_DELAY_2 DELAY_1_NOP
    #define ST7920_DELAY_3 DELAY_2_NOP
    #ifndef ENCODER_STEPS_PER_MENU_ITEM
      #define ENCODER_STEPS_PER_MENU_ITEM 1
    #endif
    #ifndef ENCODER_PULSES_PER_STEP
      #define ENCODER_PULSES_PER_STEP 4
    #endif
  #endif
#endif
