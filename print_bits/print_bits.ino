// read/print each bit of a numeric value. EX 0xA001:    1010 0000 0000 0001
// update: add print to HW serial port in addition

#include <Arduino.h>
#define HWSERIAL Serial1

char compileDATE[] PROGMEM = __DATE__;

int value = 0xB050;
String binary_string = "";

// function prototypes
String buildBinaryString(int);


void setup() {
    // initialize serial ports
    HWSERIAL.begin(115200, SERIAL_8N1);    // optional: configure Teensy HW UART serial port Rx/Tx
    HWSERIAL.println("\x1b[2J \x1b[H");        // clear screen, cursor to home
    HWSERIAL.println("HW Serial Print initialized.");
    delay(99);

    Serial.begin(115200);
        while (!Serial && (millis() < 5000)) {
    }    // include timeout to continue program if print console isn't opened
    Serial.println("USB Serial Print initialized.");

    Serial.printf    ("Compiled: %s\n\n", compileDATE);
    HWSERIAL.printf("Compiled: %s\r\n\n", compileDATE);
    Serial.println();
    for (int i = 1; i <= 8; i++) {            // show a few incrementing values
        binary_string = buildBinaryString(value + i);
        Serial.printf    ("%4d    %X ", i, value + i);
        HWSERIAL.printf("%4d    %X ", i, value + i);
        Serial.println(binary_string);
        HWSERIAL.println(binary_string);
        delay(111);
    }
}


void loop() {
    ;
}


/// create a binary string from a number (ex:    0x03E5        1110 0101)
String buildBinaryString(int number) {
    String str = "";
    int wordLength = 16;                            // rightmost N bits: 8|12|16|32
    for (int i = 0; i < wordLength; i++) {
        byte bit_val = bitRead(number, (wordLength - 1) - i);    // print MSB left to right
        if ((i % 4) == 0)
            str += " ";    // mark nibbles
        str += String(bit_val);
    }
    return str;
}
