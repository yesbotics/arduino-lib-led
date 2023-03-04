#include <Led.h>

const int PIN_LED = 33;

// Create instance
Led led()

void setup() {
	Serial.begin(57600);
	led.init(PIN_LED)
}

void loop() {
    Serial.print("Set the light on...");
    led.setLightOn();
    delay(3000);

    Serial.print("and off again.");
    led.setLightOff();
    delay(3000);
}
