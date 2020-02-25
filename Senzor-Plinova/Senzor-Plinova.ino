#include <Wire.h>               
                                    
#define calibr 50				   //konstanta za kalibraciju
const int A_ulaz = A0;     //Dodjela imena pinovima
const int D_trig = 2; 
const int LED = 9;
                               
void setup() {
                            
	pinMode(A_ulaz,INPUT);  //Analogni pin ulaz
pinMode(D_trig,INPUT);    //Digitalni pin ulaz
	pinMode(LED,OUTPUT);    //LEDica izlaz
	Serial.begin(9600);           
}                                             
                        
void loop() {
	                         
	int Sr_vr = 0;          //Srednja vrijednost
	int Q = 0;              //Kalibrirana vrijednost
	int suma = 0;           //Suma mjerenih vrijednosti
	int i;		              //Brojac za for petlju
	int x;                  //Pomocna varijabla
                                                                                                  
	for (i = 0; i < 10; ++i){  //Izmjeri svake pola sekunde vrijednost, 10x
		x = analogRead(A0);
		suma += x;             
		delay(500);                   
	}                                            
                                                     
	Sr_vr = suma/10;       //Srednja vrijednost očitavanja
	Q = Sr_vr - calibr;    //Korekcija za preciznost
                                                             
	Serial.print(Q);            
	Serial.println(" PPM");
                                                                                        
	if(Q>750){             //Paljenje alarma ako razina prijeđe dopustenu
		digitalWrite(LED,HIGH); 
	}                                                        
	else{                                                 
		digitalWrite(LED,LOW);   
	}                                                           
}         
