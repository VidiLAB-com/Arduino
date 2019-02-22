#define sredina 510
                                    
float struja;
                               
void setup() {          
  Serial.begin(9600);
}                                  
                          
void loop() {
  struja = (sredina - analogRead(A0)) * 5.0 / 1024.0 / 0.100;
  Serial.println(struja);
  delay(1000);
}                    

