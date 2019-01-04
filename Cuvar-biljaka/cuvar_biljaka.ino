#include "DHT.h"
#define DHTPIN A0
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);
int Svjetlo = 2;
int Ventilator = 3;
int Grijac = 4;
int Pumpa = 5;
int SenzorVlage = A1;
int Vlaznost;

void setup() {
  pinMode(Grijac, OUTPUT);
  pinMode(Ventilator, OUTPUT);
  pinMode(SenzorVlage, INPUT);
  pinMode(Svjetlo, OUTPUT);
  pinMode(Pumpa, OUTPUT);
  dht.begin();
}
 
void loop() {

  Vlaznost = analogRead(SenzorVlage); //0-1023
  double h = dht.readHumidity();
  double t = dht.readTemperature();
   
  digitalWrite(Svjetlo, HIGH);

  if(t < 22){ 
    digitalWrite(Grijac, HIGH);
  }
  else digitalWrite(Grijac, LOW); 
  
  if(t > 25){
    digitalWrite(Ventilator, HIGH);
  }
  else digitalWrite(Ventilator, LOW);

  if(h > 70){
    digitalWrite(Ventilator, HIGH);
  }
  else digitalWrite(Ventilator, LOW);

  if(Vlaznost < 500){
    digitalWrite(Pumpa, HIGH);
  }
  else digitalWrite(Pumpa, LOW);
  
  delay(3000);
}
