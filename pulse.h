
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
    Pulse(unsigned char connected_pin, bool reverse_output = false);
    ~Pulse();
    void startPulse(unsigned long on_time = 10, unsigned long off_time = 0, unsigned int n_pulses = 1);
    void update();
    void reset();
    bool isOn() const;
    bool isOff() const;
    bool isDone() const;
    unsigned long getTimeToEnd() const;
    unsigned int pulsesToEnd() const;


private:
    bool state;
    bool reverse;
    unsigned char pin;
    unsigned int nPulses;
    unsigned long switchTime;
    unsigned long onTime;
    unsigned long offTime;

    void powerOff();
    void powerOn();
};

#endif // PULSE_H
