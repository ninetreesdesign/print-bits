// read/print each bit of a numeric value
//

void setup() {
  Serial.begin(57600);
  Serial.println();

}
int datamsg = 0xA050;
static int i;
static byte bitval;

void loop() {
  for ( int i = 0; i < 16; i++) {
    bitval = bitRead(datamsg, 15 - i); // print MSB left to right
    if ((i % 4) == 0) Serial.print(" "); // mark nibbles
    Serial.print(bitval);
     delayMicroseconds(2000);
   // delay(90);  // see each bit output
  }
  Serial.println();
  delay(1500);
}
