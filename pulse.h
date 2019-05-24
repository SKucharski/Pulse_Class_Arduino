
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
        Pulse(byte connected_pin, bool reverse_output = false);
        bool isOn();
        bool isOff();
        bool isDone();
        void reset();
        void startPulse(unsigned long on_time = 10, unsigned long off_time = 0, unsigned int n_pulses = 1);
        void update();
        unsigned long getTimeToEnd();
        unsigned int pulsesToEnd();


private:
        byte pin;
        bool state;
        bool reverse;
        unsigned int nPulses;
        unsigned long switchTime;
        unsigned long onTime;
        unsigned long offTime;

        void powerOff();
        void powerOn();
};

#endif // PULSE_H
