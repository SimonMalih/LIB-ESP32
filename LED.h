#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED {
    private:
        byte led;
    
    public:
        LED(byte pin);
        void on();
        void off();
};

#endif