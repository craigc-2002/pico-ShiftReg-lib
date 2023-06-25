# pico-74hc595-lib

Library to interface the Raspberry Pi Pico with a 74HC595 shift register.

## Shift Register Class

The library provides the ShiftReg74HC595 class in the header ```74hc595.h```. This class contains the following methods:

Constructors:

* ```ShiftReg74HC595(int data_pin, int clock_pin)``` - only using the data and shift register clock pins
* ```ShiftReg74HC595(int data_pin, int clock_pin, int latch_pin)``` - using the data, shift register clock and latch pin.
* ```ShiftReg74HC595(int data_pin, int clock_pin, int latch_pin, int clear_pin)``` - using the data, clock, latch and clear pins. If the clear pin is needed without the latch pin, the latch_pin parameter can be set to -1.

Basic methods:

* ```void set_data(int value)``` - set the output value on the data pin. Passing in 0 sets the line low, a number > 0 sets the pin high.
* ```void clock_pulse(void)``` - pulse the shift register clock pin high for 100 us.
* ```void latch(void)``` - pulse the latch pin high for 100 us.
* ```void clear(void)``` - pulse the clear pin high for 100 us.

Composite methods:

* ```void send_bit(bool data)``` - send 1 bit of data
* ```void send_byte(int8_t data)``` - send 8 bits of data

## Usage

* Add git submodule to Raspberry Pi Pico project
* Add the line ```add_subirectory(pico-74hc595-lib)``` to the project's CMakeLists.txt
* Link the library shift_register library to the executable as necessary
