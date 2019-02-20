#include "SFE_BMP180.h"
#include "Wire.h"

SFE_BMP180 tlak;

double tlakZraka, tempZraka; 
const int Svjetlo = A0;
const int Hladnjak = A1;
const int Vrata = A2;
const int IR1=2;
const int IR2=3;
const int IR3=4;
const int IR4=5;
const int IR5=6;
const int IR6=7;
int broj;
int rucno=0;
byte serialA;

void setup(){
  Serial.begin(9600);
  pinMode(Svjetlo,OUTPUT);
  pinMode(Hladnjak,OUTPUT);
  pinMode(Vrata,INPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(IR4,INPUT);
  pinMode(IR5,INPUT);
  pinMode(IR6,INPUT);

  tlak.begin();
  delay(1);
}

void loop() {
if (Serial.available()>0) {serialA =Serial.read(); Serial.println(serialA);}
  switch(serialA){
    case 49: //Broj 1 u Ascii
    digitalWrite(Svjetlo, !digitalRead(Svjetlo));
    delay(5);
    break;
    
    case 50: //Broj 2 u Ascii
    digitalWrite(Hladnjak, !digitalRead(Hladnjak));
    delay(5);
    break;

    case 51: //Broj 3 u Ascii
    rucno = 1;
    delay(5);
    break;

    case 52: //Broj 4 u Ascii
    rucno = 0;
    delay(5);
    break;
    
  } broj = 0;
    if(digitalRead(IR1)){
      broj = broj+1;
    }
    if(digitalRead(IR2)){
      broj = broj+1;
    }
    if(digitalRead(IR3)){
      broj = broj+1;
    }
    if(digitalRead(IR4)){
      broj = broj+1;
    }
    if(digitalRead(IR5)){
      broj = broj+1;
    }
    if(digitalRead(IR6)){
      broj = broj+1;
    }
    
    Serial.println(",Broj limenki: " + String(broj)+ ",");
    delay(5);

    if(digitalRead(Vrata)){
      digitalWrite(Svjetlo, HIGH);
      Serial.println("Vrata otvorena,");
    } else digitalWrite(Svjetlo, LOW);
      Serial.println("Vrata zatvorena,");

    tlakZraka = ocitajTlak();
    Serial.println("Tlak zraka: " + String(tlakZraka) + "hPa,");
  
    tempZraka = ocitajTemperaturu();
    Serial.println("Temp zraka: " + String(tempZraka) + "C,");

    if(tempZraka >= 20){
      if(rucno = 0){
      digitalWrite(Hladnjak, HIGH);     
      }
    }
    if(tempZraka <= 7){
      if(rucno = 0){
      digitalWrite(Hladnjak, LOW);
      }
    }
    delay(300);
    Serial.println();  

}

// FUNKCIJA ZA RAČUNANJE TLAKA I TEMPERATURE ZRAKA BMP SENZOR
double ocitajTlak()
{
  char status;

  double temp, Tlak, tlak0, nadVisina;
  
  status = tlak.startTemperature();
  if(status != 0)
  {
    delay(status);
    status = tlak.getTemperature(temp);
    if(status != 0)
    {
      status = tlak.startPressure(3);
      if(status != 0)
      {
        delay(status);
        status = tlak.getPressure(Tlak,temp);
        if(status != 0)
        {
          return(Tlak);
        }
      }
    }
  }
}

double ocitajTemperaturu()
{
  char status;
  double temp;
  
  status = tlak.startTemperature();
  if(status != 0)
  {
    delay(status);
    status = tlak.getTemperature(temp);
    if(status != 0)
    {
      return(temp);
    }
  }
}

