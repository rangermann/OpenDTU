#pragma once

#include <inttypes.h>

class StatusLEDs {

public:
    void setup(uint8_t pinOn, uint8_t pinOff);
    void loop();

private:
    uint8_t pinOn;
    uint8_t pinOff;
};

extern StatusLEDs StatusIndicator;