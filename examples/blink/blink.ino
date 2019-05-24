#include "pulse.h"

const byte LED_PIN = 13;
const unsigned long ON_TIME = 50;
const unsigned long OFF_TIME = 950;
const byte PULSES = 10;

Pulse LED(LED_PIN);

void setup()
{
}

void loop()
{
    if(LED.isDone())
        LED.startPulse(ON_TIME, OFF_TIME, PULSES);

    LED.update();
}
