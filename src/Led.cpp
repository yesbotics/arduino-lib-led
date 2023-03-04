#include <Arduino.h>
#include "Led.h"

Led::Led() {
}

void Led::init(const int pin, unsigned long _blinkDelay) {
    this->_pin = pin;
    this->_blinkDelay = _blinkDelay;
    pinMode(pin, OUTPUT);
    this->_setLight(false);
}

// Call this in Arduino loop() function
void Led::loop() {
    if (this->_isBlinking) {
        unsigned long currentMillis = millis();
        if ((currentMillis - this->_lastMillis) >= this->_blinkDelay) {
            this->_lastMillis = currentMillis;
            this->_setLight(!this->_isOn);
        }
    }
}

void Led::startBlinking() {
    this->_setLight(false);
    this->_lastMillis = millis();
    this->_isBlinking = true;
}

void Led::stopBlinking() {
    this->_isBlinking = false;
}

void Led::setLightOn() {
    this->stopBlinking();
    _setLight(true);
}

void Led::setLightOff() {
    this->stopBlinking();
    this->_setLight(false);
}

bool Led::isLightOn() {
    return this->_isOn;
}

bool Led::isLightOff() {
    return !this->_isOn;
}

bool Led::isBlinking() {
    return this->_isBlinking;
}

void Led::setLight(bool on) {
    this->stopBlinking();
    this->_setLight(on);
}

void Led::_setLight(bool on) {
    this->_isOn = on;
    digitalWrite(this->_pin, on);
}


