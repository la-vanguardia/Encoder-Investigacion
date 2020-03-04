void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
}
 
void loop() {
  volatile long contPotenciaInit; // LEER MANDO RC --> POTENCIA
volatile int PulsoPotencia;
  //Serial.println(digitalRead(8));
 if (digitalRead(8) == HIGH) {
  contPotenciaInit = micros();
  if (digitalRead(8) == LOW){
    PulsoPotencia = micros() - contPotenciaInit;
    Serial.println(PulsoPotencia);
  }
 }
  
}
