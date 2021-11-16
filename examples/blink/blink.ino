#include <pulse.h>

const unsigned char LED_PIN = 13;
const unsigned long ON_TIME = 50;
const unsigned long OFF_TIME = 950;
const unsigned char PULSES = 10;

Pulse LED(LED_PIN);

void setup()
{
    LED.startPulse(ON_TIME, OFF_TIME, PULSES);
}

void loop()
{
    LED.update();
}
