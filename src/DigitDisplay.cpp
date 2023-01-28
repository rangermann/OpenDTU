#include "DigitDisplay.h"
#include <Hoymiles.h>

DigitDisplay::~DigitDisplay()
{
    if (display) {
        delete display;
    }
}

void DigitDisplay::setup(uint8_t pinClk, uint8_t pinDIO, bool showTotalYieldDayIfOff)
{
    this->showTotalYieldDayIfOff = showTotalYieldDayIfOff;
    display = new TM1637Display(pinClk, pinDIO);
    display->setBrightness(7, true); // Turn on
    display->clear();
}

void DigitDisplay::loop()
{
    float totalPower = 0;
    float totalYieldDay = 0;
    float totalYieldTotal = 0;
    uint8_t numProducing = 0;
    for (uint8_t i = 0; i < Hoymiles.getNumInverters(); i++) {
        auto inv = Hoymiles.getInverterByPos(i);
        if (inv->isProducing()) {
            numProducing++;
        }

        totalPower += inv->Statistics()->getChannelFieldValue(CH0, FLD_PAC);
        totalYieldDay += inv->Statistics()->getChannelFieldValue(CH0, FLD_YD);
        totalYieldTotal += inv->Statistics()->getChannelFieldValue(CH0, FLD_YT);
    }
    if (numProducing > 0) {
        display->showNumberDec(totalPower);
    } else {
        if (showTotalYieldDayIfOff) {
            display->showNumberDec(totalYieldDay);
        } else {
            display->setSegments(SEG_OFF);
        }
    }
}

void DigitDisplay::clear()
{
    display->clear();
}

void DigitDisplay::showNumber(int number)
{
    display->showNumberDec(number);
}

DigitDisplay FourDigitDisplay;