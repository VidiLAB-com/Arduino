const int FIRE = 24;
                                     
void setup() {
                         
Serial.begin(9600);
pinMode(FIRE, INPUT);
}                                         
void loop() {
                       
if(digitalRead(FIRE) == HIGH){
Serial.print("Pozar!");            
}                                  
} 

