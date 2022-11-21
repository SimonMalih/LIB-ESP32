#ifndef PAD_H
#define PAD_H

#define ROW_NUM 4    // four rows
#define COLUMN_NUM 4 // four columns

#include <Arduino.h>
#include <Keypad.h>
#include <string>

class PAD {

private:
    String buffer = "";
    char keys[ROW_NUM][COLUMN_NUM] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}};

    byte pin_rows[ROW_NUM] = {19, 18, 5, 17};    // GIOP19, GIOP18, GIOP5, GIOP17 connect to the row pins
    byte pin_column[COLUMN_NUM] = {16, 4, 0, 2}; // GIOP16, GIOP4, GIOP0, GIOP2 connect to the column pins
    Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

public:
    void getKey()
    {
        char key = keypad.getKey();
        if (key)
        {
            switch (key)
            {
            case 'D':
                enterCode();
                break;
            case 'C':
                buffer = "";
                break;
            default:
                buffer += key;
                break;
            }
            Serial.println(buffer);
        }
    }

    void enterCode()
    {
        Serial.println("Enter pressed");
        if (buffer.equals("1234"))
            Serial.println("Correct password");
        else
            Serial.println("Incorrect password");
        buffer = "";
    }
};

#endif