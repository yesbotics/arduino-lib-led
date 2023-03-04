#include <Arduino.h>

#ifndef LED_H
#define LED_H

class Led {
public:
    Led();

    void init(const int pin, unsigned long blinkDelay = 300);
    void startBlinking();
    void stopBlinking();
    void loop();
    void setLightOn();
    void setLightOff();
    void setLight(bool on);
    void isBlinking();
    void isLightOn();
    void isLightOff();

private:
    void _setLight(bool on);
    unsigned long _blinkDelay;
    unsigned long _lastMillis;
    boolean _isBlinking = false;
    boolean _isOn = false;
    int _pin;
};

#endif
