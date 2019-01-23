#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 
const int trig = 11;
const int echo = 12;
 
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  u8g2.begin();
}
 
void loop() {
   
  long vrijeme, udaljenost;
 
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
   
  vrijeme = pulseIn(echo, HIGH);
  udaljenost = ((vrijeme/2)*(0.035));
     
   u8g2.clearBuffer();         // ocisti memoriju zaslona
   u8g2.setFont(u8g2_font_logisoso28_tr); //odabrani font, u našem slučaju visine 28
   u8g2.setCursor(0,31); //postavi pokazivač na nultu poziciju i 31 red, 31/32
   u8g2.print(udaljenost); //ispiši vrijednost udaljenosti
   u8g2.drawStr(75,31,"cm"); //dodaj mjernu jedinicu na poziciju 75, i red 32
   u8g2.sendBuffer();         // slanje poruke na zaslon

  delay(1000); 
}
//fontove je moguće odabrati na navedenoj stranici
//https://github.com/olikraus/u8g2/wiki/fntlistall#30-pixel-height fontovi
