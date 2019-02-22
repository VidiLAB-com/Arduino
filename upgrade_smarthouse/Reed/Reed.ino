const int REED = 22;
                           
void setup() {
                               
Serial.begin(9600);         
pinMode(REED, INPUT);
digitalWrite(REED, HIGH);
}                                            
void loop() {
                     
if(digitalRead(REED) == HIGH){
Serial.print("Iskljuceno");         
}                                        
else{
Serial.print("Ukljuceno");
}                  
}

