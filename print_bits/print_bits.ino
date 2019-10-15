// read/print each bit of a numeric value. EX 0xA001:  1010 0000 0000 0001

#include <Arduino.h>

char compileDATE[] PROGMEM = __DATE__;

int value = 0xA050;
String binary_string = "";

// function prototypes
String buildBinaryString(int);


void setup() {
   Serial.begin(115200);
    while (!Serial && (millis() < 5000)) {
    }  // include timeout to continue program if print console isn't opened
    Serial.println("USB Serial Print initialized.");
    Serial.printf("%s \n\n", compileDATE);

    for (int i = 1; i <= 3; i++) {      // show three incrementing values
        binary_string = buildBinaryString(value);
        Serial.printf("%d  %X ", i, value);
        Serial.println(binary_string);
        value++;
    }
}


void loop() {

}


/// create a binary string from a number (ex: 1110 0101)
String buildBinaryString(int number) {
    String str = "";
    int wordLength = 16;
    for (int i = 0; i < wordLength; i++) {
        byte bit_val = bitRead(number, (wordLength - 1) - i);  // print MSB left to right
        if ((i % 4) == 0)
            str += " ";  // mark nibbles
        str += String(bit_val);
    }
    return str;
}
