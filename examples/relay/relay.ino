#include <pulse.h>

const unsigned char BUTTON_PIN = 2;
const unsigned char RELAY_PIN = 13;
const unsigned long ON_TIME = 3000; // ms
const bool LOW_LEVEL_TRIGGER = true;

Pulse relay(RELAY_PIN, LOW_LEVEL_TRIGGER);

void setup()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Connect button between pin and GDN
}

void loop()
{
    if(digitalRead(BUTTON_PIN) == LOW && relay.isDone())
        relay.startPulse(ON_TIME);

    relay.update();
}
