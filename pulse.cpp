#include "pulse.h"

Pulse::Pulse(unsigned char connected_pin, bool reverse_output) {
    pin = connected_pin;
    nPulses = 0;
    onTime = 0;
    offTime = 0;
    reverse = reverse_output;
    pinMode(pin, OUTPUT);
    powerOff();
}

Pulse::~Pulse() {}

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

void Pulse::reset() {
    nPulses = 0;
}

bool Pulse::isOn() const {
    return state;
}

bool Pulse::isOff() const {
    return !state;
}

bool Pulse::isDone() const {
    return (nPulses == 0);
}

unsigned long Pulse::getTimeToEnd() const {
    if(!nPulses)
        return 0;

    unsigned long allTime = ((nPulses * onTime) + (nPulses * offTime));

    if(state == true)
        return allTime - (millis() - switchTime);

    return allTime - ((millis() - switchTime) + onTime);
}

unsigned int Pulse::pulsesToEnd() const {
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
