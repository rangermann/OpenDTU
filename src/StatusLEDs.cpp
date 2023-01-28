#include "StatusLEDs.h"
#include <Hoymiles.h>

void StatusLEDs::setup(uint8_t pinOn, uint8_t pinOff)
{
    this->pinOn = pinOn;
    this->pinOff = pinOff;

    pinMode(pinOn, OUTPUT);
    pinMode(pinOff, OUTPUT);
}
void StatusLEDs::loop()
{
    bool isProducing = false;
    for (uint8_t i = 0; i < Hoymiles.getNumInverters(); i++) {
        auto inv = Hoymiles.getInverterByPos(i);
        isProducing = inv->isProducing();
    }

    digitalWrite(pinOn, isProducing ? HIGH : LOW);
    digitalWrite(pinOff, isProducing ? LOW : HIGH);
}

StatusLEDs StatusIndicator;