#include "SETUP.H"

SETUP::SETUP() {
    Serial.begin(115200);
}

SETUP::print(string s) {
    Serial.println(s);
}

SETUP::printNoLine(string s) {
    Serial.print(s);
}