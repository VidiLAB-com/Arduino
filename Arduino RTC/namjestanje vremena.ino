#include "DS3231.h"
DS3231 rtc(SDA, SCL);
void setup() {               
rtc.begin();   
rtc.setDOW(MONDAY);     // dan u tjednu
rtc.setTime(12, 00, 0);       // vrijeme u 24h formatu
rtc.setDate(10, 9, 2019);   // datum                            
}                                                            
void loop(){
}                  
