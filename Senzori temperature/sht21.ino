#include "SHT21.h"
SHT21 sht;
float Temperatura, Vlaznost; 
void setup() {
	Wire.begin();
	Serial.begin(9600);
}
void loop() {
	Temperatura = sht.getTemperature();
	Vlaznost = sht.getHumidity();
	Serial.print("Temperatura: ");
	Serial.print(Temperatura);
	Serial.print(" C; ");
	Serial.print(" Vlaznost: ");
	Serial.print(Vlaznost);
	Serial.println(" % ");
	delay(85);
}