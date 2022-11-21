#include "LED.h"

LED::LED(byte pin) {
    led = pin;
    pinMode(pin, OUTPUT);
}

void LED::on() {
    digitalWrite(led, HIGH);
}

void LED::off() {
    digitalWrite(led, LOW);
}