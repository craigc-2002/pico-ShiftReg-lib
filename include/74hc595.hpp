// 74hc595.hpp
//
// Craig Cochrane, 2023
//
// Library to interface the Raspberry Pi Pico with a 74HC595 shift register
//

#ifndef _74HC595_H
#define _74HC595_H

#include <cstdint>

class ShiftReg74HC595
{
    public:
        ShiftReg74HC595(int data_pin, int clock_pin);
        ShiftReg74HC595(int data_pin, int clock_pin, int latch_pin);
        ShiftReg74HC595(int data_pin, int clock_pin, int latch_pin, int clear_pin);

        void set_data(int value);
        void clock_pulse(void);
        void latch(void);
        void clear(void);

        void send_bit(bool data); // send 1 bit of data
        void send_byte(int8_t data); // send 8 bits of data
        void send_data(int data, int num_bits); // send any number of bits of data

    private:
        void init_pins();

    private:
        int _data_pin {-1};
        int _clock_pin {-1};
        int _latch_pin {-1};
        int _clear_pin {-1};
};

#endif

