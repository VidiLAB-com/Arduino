#include "Wire.h"
#include "Arduino.h"
#include "U8g2lib.h"
#include "SPI.h"
 
float Pom = 1.05;
float ocitano, X, napon;
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 

void setup() {
  u8g2.begin();                   
}
 
void loop() {

   u8g2.clearBuffer(); 
   u8g2.setFont(u8g2_font_profont22_tr); // u8g2_font_6x10_tr
   u8g2.drawStr(2,15,"Napon"); 
   
    ocitano = analogRead(A0);
    X = ocitano/1023;
    napon = X*Pom*4;
    u8g2.setCursor(73,15);
    u8g2.print(napon);
   if(napon > 0 && napon < 1){
      u8g2.drawStr(4,30,"1/4");
   }else if(napon > 1 && napon < 2.7){
     u8g2.drawStr(4,30,"2/4");
   }else if(napon > 2.7 && napon < 3.7){
      u8g2.drawStr(4,30,"3/4");
   }else{
      u8g2.drawStr(4,30,"4/4");
   }
   u8g2.sendBuffer();
   delay(1000);
}
