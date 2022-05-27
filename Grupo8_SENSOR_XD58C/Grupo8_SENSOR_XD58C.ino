 /*
  * UNIVERSIDAD TÉCNICA DEL NORTE
  * FACULTAD DE INGENIERÍA EN CIENCIAS APLICADAS
  * CITEL
  * 
  * PROYECTO 1ER BIMESTRE
  * INTEGRANTES:  
  * Almachi Darwin
  * Benavides Joseth 
  * Fuertes Steven
  * TEMA: SUAVIZADO DE SEÑALES - SENSOR XD - 58C
  */

int PulseSignal;               
int umbral = 550;            

void setup() {
   Serial.begin(9600);        
}

void loop() {

  
  PulseSignal = (float)analogRead(A0);  // La conversión int - float le da otorga mayor amplificación a la señal
  Serial.println(100*PulseSignal);      // Mayor amplificación de la señal
  delay(10);
  //Encendido de led en caso de exceder el umbral de pulso
   if(PulseSignal > umbral){                          
     digitalWrite(13,HIGH);
   } else {
     digitalWrite(13,LOW);                
   }
  delay(10);
}
