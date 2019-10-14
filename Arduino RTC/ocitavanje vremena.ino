#include "DS3231.h"
DS3231 rtc(SDA, SCL);
void setup() {                
Serial.begin(115200); 
rtc.begin();                   
}                                     
void loop() {             
Serial.print(String(rtc.getDOWStr()));   // Dan u tjednu
Serial.print(rtc.getDateStr());   //Datum                         
Serial.println(rtc.getTimeStr());   //Vrijeme
delay (1000);                                                   
}
