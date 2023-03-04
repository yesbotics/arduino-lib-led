#include <Led.h>

const int PIN_LED = 33;

// Create instance
Led led()

void setup() {
	Serial.begin(57600);
	led.init(PIN_LED, 200);

    // Start blinking
    led.startBlinking();
}

void loop() {
    // Call loop function to allow the blinking
    led.loop();
}
