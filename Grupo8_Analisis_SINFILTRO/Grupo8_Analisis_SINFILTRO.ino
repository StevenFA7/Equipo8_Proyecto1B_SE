 /* UNIVERSIDAD TECNICA DEL NORTE
  * FACULTAD DE INGENIERIA EN CIENCIAS APLICADAS
  * CITEL
  *
  * PROYECTO PRIMER BIMESTRE
  * 
  * INTEGRANTES:  
  * Almachi Darwin
  * Benavides Joseth
  * Fuertes Steven
  * DOCENTE ASIGNATURA: Msc. Pamela Godoy Trujillo
  * TECNICO DOCENTE: Msc. Alejandra Pinto Erazo
  * TEMA: SUAVIZADO DE SEÑALES - SENSOR XD-58C - SIN FILTRO
  */

//  Variables
#define tam_sig 100                             //Tamaño de muestra
extern int ecg_100Hz [tam_sig];                 //Declaración para la señal externa
float S;                                        //Variable asociada a la Media Movil Exponencial
float alpha=0.2;                                //Factor de suavizado
int umbral = 550;                               //Umbral de frecuencia cardiaca

void setup() {
   Serial.begin(9600);                          
}

void loop() {
 
  for(int i=0;i<tam_sig;i++){                   //Inicialización del ciclo for (i no es necesario inicializar en las variables)
    //S[-1]=0;
    S=(alpha*ecg_100Hz[i])+((1-alpha)*S);       //Aplicación del algoritmo
    Serial.println(ecg_100Hz[i]);               //Impresión para la señal Original
    Serial.print(",");
    Serial.println(S);                          //Señal tratada sin Filtro
    delay(10);                                  //Detiene el microcontrolador un tiempo estimado
  
    if(ecg_100Hz[i] > umbral){                  //Inicialización del ciclo if para la frecuencia establecida
      digitalWrite(13,HIGH);                    //Envía 5V al pin13 (enciende el led si excede esa frecuencia)
    } else {                                    //Condición contraria al ciclo if
       digitalWrite(13,LOW);                    //Envía 0V al pin13 (el led permanece apagado si no excede la frecuencia)
    }
  
    
  }
  
  
delay(10);

}
