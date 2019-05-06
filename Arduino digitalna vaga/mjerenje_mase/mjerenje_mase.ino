#include "HX711.h"

#define DOUT 5
#define CLK 6
 
long t;

HX711 scale(DOUT, CLK);

float calibration_factor = -877000.00; 
 
void setup() {
 Serial.begin(9600);
 
 
 Serial.println("Uklonite sve utege s vage");
 Serial.println("Pritisnite t za tariranje");
 scale.set_scale();
 scale.tare(); //postavlja vagu na 0
}
  
void loop() {
 scale.set_scale(calibration_factor); //postavlja faktor kalibracije koji smo deklarirali na početku
  
 (delay(1000);
 float masa=scale.get_units();//u varijablu masa spremamo masu koju očitavamo s vage
 Serial.print("Ocitavanje: ");
 Serial.print(masa, 3);// ispisujemo masu zaokruženu na 3 decimale
 Serial.println(" kg");
 t=millis();//u varijablu t spremamo novo vrijeme koje je prošlo od pokretanja Croduina
 }
 //ako je korisnik nešto unio putem Serial monitora onda se izvršava daljnji kod
 if(Serial.available())
 {
 char temp = Serial.read();
 //ako je poslano slovo t onda vagu postavimo na 0(tariramo)
 if(temp == 't')
 scale.tare();
 }
}
