cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

project(shift_reg 
    VERSION 0.1
    DESCRIPTION "Library to interface the Rasberry Pi Pico with the 74HC595 Shift Register"
    LANGUAGES CXX C ASM
)

# rest of your project

add_subdirectory(./src)
add_subdirectory(./examples)

