#include "SFE_BMP180.h"
#include "Wire.h"

SFE_BMP180 tlak;

double tlakZraka, tempZraka; 
const int IR=6;
const int FOTO=7;
byte serialA;

void setup(){
  Serial.begin(9600);
  pinMode(IR,INPUT);
  pinMode(FOTO,INPUT);

    if(tlak.begin()) delay(1);
  else
  {
    delay(1);
    while(1);
  }

}

void loop() {
if (Serial.available()>0) {serialA =Serial.read(); Serial.println(serialA);}
  switch(serialA){
    case 49:
    digitalWrite(Relej1, !digitalRead(Relej1));
    delay(10);
    break;
    
  }
    int StanjeIR = digitalRead(IR);
    Serial.println(",Vrata = " + String(StanjeIR) + ",");
    delay(10);

    int StanjeFOTO = digitalRead(FOTO);
    Serial.println("Svjetlo = " + String(StanjeFOTO) + ",");
    delay(10);

    tlakZraka = ocitajTlak();
    Serial.println("Tlak zraka = " + String(tlakZraka) + "hPa,");
  
    tempZraka = ocitajTemperaturu();
    Serial.println("Temp zraka = " + String(tempZraka) + "C,");
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
