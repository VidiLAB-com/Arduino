#define sensorIn A0
#define sensitivity 100    //sensitivity modula koji se koristi [mV/A]
 
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  Voltage = getVPP();
  VRMS = (Voltage / 2.0) * 0.70710678;
  AmpsRMS = (VRMS * 1000) / sensitivity;
  Serial.print(AmpsRMS);
  Serial.println(" Amps RMS");
}
 
float getVPP() {
  float result;
 
  unsigned int readValue;             // vrijednost pročitana sa senzora
  unsigned int maxValue = 0;          // max vrijednost
  unsigned int minValue = 1023;       // min vrijednost
 
  unsigned long start_time = millis();
  //radi mjerenja jednu sekundu
  while ((millis() - start_time) !=  maxValue) {
    readValue = analogRead(sensorIn);
    //ako je pročitana vrijednost veća od prijašnje max vrijednosti
    if(readValue > maxValue){
      // postavi tu vrijednost kao maksimalnu
      maxValue = readValue;
    }
 
    // ako je pročitana vrijednost manja od prijašnje min vrijednosti
    if (readValue < minValue) {
      // postavi tu vrijednost kao minimalnu
      minValue = readValue;
    }
  }
 
  // pronađi Vpp
  result = ((maxValue - minValue) * 5.0) / 1024.0;
 
  return result;
}
