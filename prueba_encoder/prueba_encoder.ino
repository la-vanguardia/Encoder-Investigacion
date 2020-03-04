#define PCINT_PIN1 A5
#define PCINT_PIN2 A4
long int CuentaPicos1=0;
long int CuentaPicos2=0;
#include <YetAnotherPcInt.h>
#include <TimerOne.h>
 
void pinChanged1(const char* message, bool pinstate) {
  CuentaPicos1++;
}
 void pinChanged2(const char* message, bool pinstate) {
  CuentaPicos2++;
}
 
void setup() {
  Timer1.initialize(1000000);         // Dispara cada 1s
 Timer1.attachInterrupt(ISR_Mostrar); // Activa la interrupcion
  Serial.begin(115200);
  pinMode(PCINT_PIN1, INPUT_PULLUP);
  pinMode(PCINT_PIN2, INPUT_PULLUP);
  PcInt::attachInterrupt(PCINT_PIN1, pinChanged1, "Pin A5 has changed to ", CHANGE);
  PcInt::attachInterrupt(PCINT_PIN2, pinChanged2, "Pin A5 has changed to ", CHANGE);
}
 
void loop() {}
void ISR_Mostrar()
   {  
    Serial.print("encoder1:");
    Serial.println(CuentaPicos1);
    Serial.print("encoder2:");
    Serial.println(CuentaPicos2);
    CuentaPicos1=0;
    CuentaPicos2=0;
   }
