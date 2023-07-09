// ShiftReg.hpp
//
// Craig Cochrane, 2023
//
// Library to interface the Raspberry Pi Pico with a shift register
//

#ifndef _ShiftReg_H
#define _ShiftReg_H

#include <cstdint>

class ShiftReg
{
    public:
        ShiftReg(int data_pin, int clock_pin);
        ShiftReg(int data_pin, int clock_pin, int latch_pin);
        ShiftReg(int data_pin, int clock_pin, int latch_pin, int clear_pin);

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

