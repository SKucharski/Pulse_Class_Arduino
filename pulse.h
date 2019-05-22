
/*
 * Pulse.h
 *
 * Arduino library for LED's control, etc.
 *
 * This code is released ito the public domain
 *
 */

#ifndef PULSE_H
#define PULSE_H

#include <Arduino.h>

class Pulse {
public:
        Pulse(byte connectPin);
        bool isStateHigh();
        bool isStateLow();
        bool isDone();
        void reset();
        void startPulse(unsigned long on_time = 10, unsigned long off_time = 0, unsigned int n_pulses = 1);
        void update();
        unsigned long getTimeToEnd();
        unsigned int pulsesToEnd();


private:
        byte pin;
        bool state;
        unsigned int nPulses;
        unsigned long switchTime;
        unsigned long onTime;
        unsigned long offTime;

        void powerOff();
        void powerOn();
};

#endif // PULSE_H
