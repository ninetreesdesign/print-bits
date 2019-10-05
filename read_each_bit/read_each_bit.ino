// read/print each bit of a numeric value

#include <Arduino.h>

int value1 = 0xA050;

void setup() {
    Serial.begin(115200);
    Serial.println();

    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 16; i++) {               // each bit of word
            byte bit_val = bitRead(value1, 15 - i);  // print MSB left to right
            if ((i % 4) == 0) Serial.print(" ");     // mark nibbles
            Serial.print(bit_val);
            delay(20);
        }
        Serial.println();
        delay(500);
        value1++;
    }
}

void loop() {
}