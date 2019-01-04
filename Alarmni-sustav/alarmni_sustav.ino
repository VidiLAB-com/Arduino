
int FOTOsenzor = 3;
int POKRETsenzor = 1;
int MAGNETsenzor = 4;
int VIBRACIJAsenzor = 2;
int TIPKA = 5;
int ALARM = 6;
int FOTOstanje;
int POKRETstanje;
int MAGNETstanje;
int VIBRACIJAstanje;
int TIPKAstanje;

void setup() {
  pinMode(FOTOsenzor, INPUT);
  pinMode(POKRETsenzor, INPUT);
  pinMode(MAGNETsenzor, INPUT);
  pinMode(VIBRACIJAsenzor, INPUT);
  pinMode(ALARM, OUTPUT);
  pinMode(TIPKA, INPUT);
}

void loop() {
  FOTOstanje = digitalRead(FOTOsenzor);
  POKRETstanje = digitalRead(POKRETsenzor);
  MAGNETstanje = digitalRead(MAGNETsenzor);
  VIBRACIJAstanje = digitalRead(VIBRACIJAsenzor);
  TIPKAstanje = digitalRead(TIPKA);
  
  if (FOTOstanje){
    digitalWrite(ALARM, HIGH);
    }
  delay(10);

  if (!POKRETstanje){
    digitalWrite(ALARM, HIGH);
    }
  delay(10);

  if (MAGNETstanje){
    digitalWrite(ALARM, HIGH);
    }
  delay(10);

  if (VIBRACIJAstanje){
    digitalWrite(ALARM, HIGH);
    }
  delay(10);

  if (TIPKAstanje){
    digitalWrite(ALARM, LOW);
    }
  delay(10);
}
