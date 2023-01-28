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
    uint8_t numProducing = 0;
    for (uint8_t i = 0; i < Hoymiles.getNumInverters(); i++) {
        auto inv = Hoymiles.getInverterByPos(i);
        if(inv->isProducing()) {
            numProducing++;
        }        
    }

    digitalWrite(pinOn, numProducing > 0 ? HIGH : LOW);
    digitalWrite(pinOff, numProducing > 0 ? LOW : HIGH);
}

StatusLEDs StatusIndicator;