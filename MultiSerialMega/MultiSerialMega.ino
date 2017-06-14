/*
 Arduino Mega i Leonardo serial test

 Prima s glavnog seriskog porta, te šalje na druge (poput Blutooth modula).
 Prima s seriskog porta (Serial1), te šalje na primarni (Serial 0).

 Ovaj kod radi s Arduino Mega i Leonardo 

 Shema:
 * Bluetooth modul HC-05 ili HC-06 te druge serijske uređaje spojiti s digitlnim pinovima (Serial port 1) 0 i 1 (Tx i Rx)
 * Serial monitor prikazuje podatke poslane na Serial port 0 (Arduino USB konekcija):

 created 30 Dec. 2008
 modified 20 May 2012
 by Tom Igoe & Jed Roach

 This example code is in the public domain.

 */


void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // read from port 1, send to port 0:
  if (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.write(inByte);
  }

  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }
}
