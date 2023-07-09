// ShiftReg.cpp
//
// Craig Cochrane, 2023
//
// Library to interface the Raspberry Pi Pico with a shift register
//

#include "ShiftReg.hpp"

#include <cmath>
#include <array>
#include <stdlib.h>
#include <cstdio>
#include "pico/stdlib.h"

// ---------- CONSTRUCTORS ----------

ShiftReg::ShiftReg(int data_pin, int clock_pin):
    _data_pin(data_pin), _clock_pin(clock_pin)
{
    init_pins();
}

ShiftReg::ShiftReg(int data_pin, int clock_pin, int latch_pin):
    _data_pin(data_pin), _clock_pin(clock_pin), _latch_pin(latch_pin)
{
    init_pins();
}

ShiftReg::ShiftReg(int data_pin, int clock_pin, int latch_pin, int clear_pin):
    _data_pin(data_pin), _clock_pin(clock_pin), _latch_pin(latch_pin), _clear_pin(clear_pin)
{
    init_pins();
}

void ShiftReg::init_pins()
{
    gpio_init(_data_pin);
    gpio_set_dir(_data_pin, GPIO_OUT);

    gpio_init(_clock_pin);
    gpio_set_dir(_clock_pin, GPIO_OUT);

    if (_latch_pin >= 0)
    {
        gpio_init(_latch_pin);
        gpio_set_dir(_latch_pin, GPIO_OUT);
    }

    if (_clear_pin >= 0)
    {
        gpio_init(_clear_pin);
        gpio_set_dir(_clear_pin, GPIO_OUT);
    }
}

// ---------- BASIC METHODS ----------

void ShiftReg::set_data(int value)
{
    gpio_put(_data_pin, value);
}

void ShiftReg::clock_pulse(void)
{
    gpio_put(_clock_pin, 1);
    sleep_ms(0.1);
    gpio_put(_clock_pin, 0);
}

void ShiftReg::latch(void)
{
    if (_latch_pin >= 0)
    {
        gpio_put(_latch_pin, 1);
        sleep_ms(0.1);
        gpio_put(_latch_pin, 0);
    }
}

void ShiftReg::clear(void)
{
    if (_clear_pin >= 0)
    {
        gpio_put(_clear_pin, 1);
        sleep_ms(0.1);
        gpio_put(_clear_pin, 0);
    }
}
// ---------- COMPOSITE METHODS ----------

void ShiftReg::send_bit(bool data)
{
    set_data(int(data));
    clock_pulse();
}

void ShiftReg::send_byte(int8_t data)
{
    std::array<bool, 8> bits;

    for (int i=0; i<8; i++)
    {
        // Split number into array of bits
        // array is in Little Endian format
        bits[i] = data % 2;
        data /= 2;
    }

    for (int j=0; j<8; j++)
    {
        // Send each bit of the number
        // work backwards through the array to send in Big Endian format
        int index = 7 - j;
        send_bit(bits[index]);
    }
    latch();
}

