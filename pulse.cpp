#include "pulse.h"

Pulse::Pulse(byte connected_pin, bool reverse_output) {
        pin = connected_pin;
        nPulses = 0;
        onTime = 0;
        offTime = 0;
        reverse = reverse_output;
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
        else if ((state == true) && (millis() > (switchTime + onTime))) {
                switchTime = millis();
                powerOff();
        }
        else if ((state == false) && (millis() > (switchTime + offTime))) {
                switchTime = millis();
                nPulses--;
                powerOn();
        }
}

bool Pulse::isOn() {
    return state;
}

bool Pulse::isOff() {
    return !state;
}

bool Pulse::isDone() {
    return (nPulses == 0);
}

void Pulse::reset() {
    nPulses = 0;
}

unsigned long Pulse::getTimeToEnd() {
    if(!nPulses)
        return 0;

    unsigned long allTime = ((nPulses * onTime) + (nPulses * offTime));

    if(state == true)
        return allTime - (millis() - switchTime);

    return allTime - ((millis() - switchTime) + onTime);
}

unsigned int Pulse::pulsesToEnd() {
    return nPulses;
}

void Pulse::powerOff() {
        digitalWrite(pin, reverse);
        state = false;
}

void Pulse::powerOn() {
        if((onTime == 0) || (nPulses == 0)) return;
        digitalWrite(pin, !reverse);
        state = true;
}
