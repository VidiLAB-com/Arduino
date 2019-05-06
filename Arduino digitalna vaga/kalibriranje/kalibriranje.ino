#include "HX711.h" //HX711 biblioteka
#define DOUT 4
#define CLK 5
  
HX711 scale(DOUT, CLK); //Pinovi na koje se spaja HX711
  
float faktor_kalibr = -877000.00;
  
void setup() {
 Serial.begin(9600);
 scale.set_scale();
 scale.tare(); //Vaga na 0
}
  
void loop() {
 scale.set_scale(faktor_kalibr); //Postavlja faktor kalibracije
 Serial.print("Ocitavanje: ");
 Serial.print(scale.get_units(), 3);
 Serial.print(" kg");
 Serial.print(" Faktor kalibracije: ");
 Serial.print(faktor_kalibr);//ispisujemo faktor kalibracije
 Serial.println();
  
 if(Serial.available())
 {
 char temp = Serial.read();
 if(temp == 'f')
    faktor_kalibr += 10;
 else if(temp == 'v')
    faktor_kalibr -= 10;
 else if(temp == 'g')
    faktor_kalibr += 100; 
 else if(temp == 'b')
    faktor_kalibr -= 100; 
 else if(temp == 'h')
    faktor_kalibr += 1000; 
 else if(temp == 'n')
  faktor_kalibr -= 1000;
 else if(temp == 't')
 scale.tare(); //Vaga na 0
 }
}
