// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include <TM1637Display.h>

const uint8_t SEG_OFF[] = {
	SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
	SEG_A | SEG_E | SEG_F | SEG_G,                  // F
	SEG_A | SEG_E | SEG_F | SEG_G,                  // F
	0            // 
	};


class DigitDisplay {

public:
    ~DigitDisplay();

    void setup(uint8_t pinClk, uint8_t pinDIO, bool showTotalYieldDayIfOff);
    void loop();
    
    void clear();
    void showNumber(int number);

private:
    TM1637Display* display;
    bool showTotalYieldDayIfOff;
};

extern DigitDisplay FourDigitDisplay;