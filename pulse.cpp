#include "pulse.h"

Pulse::Pulse(byte connectPin) {
        pin = connectPin;
        nPulses = 0;
        onTime = 0;
        offTime = 0;
        pinMode(pin, OUTPUT);
        powerOff();
}

void Pulse::startPulse(unsigned long on_time, unsigned long off_time, unsigned int n_pulses) {
        onTime = on_time;
        offTime = off_time;
        nPulses = n_pulses;
        switchTime = millis();
        powerOn();
}

void Pulse::update() {
        if (switchTime > millis()) switchTime = millis();
        if (nPulses == 0) powerOff();
        else if ((state == 1) && (millis() > (switchTime + onTime))) {
                switchTime = millis();
                powerOff();
        }
        else if ((state == 0) && (millis() > (switchTime + offTime))) {
                switchTime = millis();
                nPulses--;
                powerOn();
        }
}

bool Pulse::isStateHigh() {
    return state;
}

bool Pulse::isStateLow() {
    return !state;
}

bool Pulse::isDone() {
    return (nPulses == 0);
}

void Pulse::reset() {
    nPulses = 0;
}

unsigned long Pulse::getTimeToEnd() {
    unsigned long allTime = ((nPulses * onTime) + (nPulses * offTime));
    if(state == 1) return allTime - (millis() - switchTime);
    return allTime - ((millis() - switchTime) + onTime);
}

unsigned int Pulse::pulsesToEnd() {
    return nPulses;
}

void Pulse::powerOff() {
        digitalWrite(pin, 0);
        state = 0;
}

void Pulse::powerOn() {
        if((onTime == 0) || (nPulses == 0)) return;
        digitalWrite(pin, 1);
        state = 1;
}
