#include <TimerOne.h>
long int CuentaPicos1=0; 
long int CuentaPicos2=0;
void setup() {
 Timer1.initialize(1000000);         // Dispara cada 1s
 Timer1.attachInterrupt(ISR_Mostrar); // Activa la interrupcion y la asocia a ISR_Blink
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
}
 
void loop() {
  

  //Serial.println(digitalRead(8));
 if (digitalRead(8) == HIGH) {
  if (digitalRead(8)== LOW){
  CuentaPicos1++;
  }
 }
 if (digitalRead(7) == HIGH) {
  if (digitalRead(7)== LOW){
  CuentaPicos2++;
  }
 }
  
}
void ISR_Mostrar()
   {  
    Serial.print("encoder1:");
    Serial.println(CuentaPicos1);
    Serial.print("encoder2:");
    Serial.println(CuentaPicos2);
    CuentaPicos1=0;
    CuentaPicos2=0;
   }
