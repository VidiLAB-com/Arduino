#include "Wire.h"

const int REED=A0;
float radius = 70;
int reedVal;
long timer = 0;
float mph = 0.00;
float circumference;
boolean backlight;

int maxReedCounter = 100;
int reedCounter;


byte serialA;

void setup(){
	
	reedCounter = maxReedCounter;
  circumference = 2*3.14*radius;
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(reed, INPUT);
  
  checkBacklight();
  
  Serial.write(12);
  

  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 1999;
  TCCR1B |= (1 << WGM12);

  TCCR1B |= (1 << CS11);   

  TIMSK1 |= (1 << OCIE1A);
  
  sei();
  
  Serial.begin(9600);
}

void loop() {
if (Serial.available()>0) {serialA =Serial.read(); Serial.println(serialA);}
  displayMPH();
  delay(1000);
  checkBacklight();
}

